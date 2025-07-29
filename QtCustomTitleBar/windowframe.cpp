#include "windowframe.h"
#include "ui_windowframe.h"

#include <windows.h>
#include <windowsx.h>

#include <QScreen>
#include <QDesktopWidget>
#include <QMouseEvent>

const QString DefaultTitle = "Custom Title Bar";

const QString headerDefaultStyle = QStringLiteral(
    "#header {"
    "    background-color: rgb(20, 20, 20);"
    "    border: 1px solid rgb(20, 20, 20);"
    "    border-top-left-radius: 10px;"
    "    border-top-right-radius: 10px;"
    "}"
);

const QString headerCollapseStyle = QStringLiteral(
    "#header {"
    "    background-color: rgb(20, 20, 20);"
    "    border: 2px solid rgb(20, 20, 20);"
    "    border-top-left-radius: 10px;"
    "    border-top-right-radius: 10px;"
    "    border-bottom-left-radius: 10px;"
    "    border-bottom-right-radius: 10px;"
    "}"
);

const QString headerMaximizeStyle = QStringLiteral(
    "#header {"
    "    background-color: rgb(20, 20, 20);"
    "    border: 1px solid rgb(20, 20, 20);"
    "    border-top-left-radius: 0px;"
    "    border-top-right-radius: 0px;"
    "}"
);

const QString appIcon           = ":/recources/icons/icon.png";
const QString closeIcon         = ":/recources/icons/close.png";
const QString collapseHideIcon  = ":/recources/icons/collapse_hide.png";
const QString collapseShowIcon  = ":/recources/icons/collapse_show.png";
const QString maximizeIcon      = ":/recources/icons/maximize.png";
const QString minimizeIcon      = ":/recources/icons/minimize.png";
const QString defaultSizeIcon   = ":/recources/icons/default_size.png";


WindowFrame::WindowFrame(QWidget *parent, QWidget *child)
    : QFrame(parent)
    , ui(new Ui::WindowFrame)
    , mBorderSize(5)
    , mIsCollapse(false)
    , mTitle(DefaultTitle)
{
    ui->setupUi(this);
    mBorderSize = 5;

    initIcons();

    ui->title->setText(mTitle);

    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    setAttribute(Qt::WA_TranslucentBackground);
    if(child != nullptr) {
        ui->body->layout()->addWidget(child);
        mMainBody = child;
        mMainBody->installEventFilter(this);
        resize(child->size());
    }
    mIsCollapse = false;
}

WindowFrame::~WindowFrame(){
    delete ui;
}

void WindowFrame::initIcons(){
    this->setIcon(appIcon);

    ui->collapse->setIcon(QIcon(collapseHideIcon));
    ui->close->setIcon(QIcon(closeIcon));
    ui->maximum->setIcon(QIcon(maximizeIcon));
    ui->minimum->setIcon(QIcon(minimizeIcon));
}


void WindowFrame::showHeaderContextMenu(const QPoint &pos){
    QMenu contextMenu(this);

    QAction *exitAction = contextMenu.addAction(tr("&Exit"));
    connect(exitAction, &QAction::triggered, this, &WindowFrame::close);

    contextMenu.addAction(exitAction);
    contextMenu.exec(mapToGlobal(pos));
}


void WindowFrame::on_close_clicked(){
    close();
}


void WindowFrame::on_maximum_clicked(){
    if(isMaximized()) {
        ui->maximum->setIcon(QIcon(maximizeIcon));
        mIsCollapse ? ui->header->setStyleSheet(headerCollapseStyle) : ui->header->setStyleSheet(headerDefaultStyle);
        showNormal();
    } else {
        ui->maximum->setIcon(QIcon(defaultSizeIcon));
        ui->header->setStyleSheet(headerMaximizeStyle);
        showMaximized();
    }
}


void WindowFrame::on_minimum_clicked(){
    showMinimized();
}


void WindowFrame::on_collapse_clicked() {
    if (mIsCollapse) {
        ui->body->setVisible(true);
        mIsCollapse = false;
        ui->collapse->setIcon(QIcon(collapseHideIcon));
        isMaximized() ? ui->header->setStyleSheet(headerMaximizeStyle) : ui->header->setStyleSheet(headerDefaultStyle);
    } else {
        ui->body->setVisible(false);
        mIsCollapse = true;
        ui->collapse->setIcon(QIcon(collapseShowIcon));
        isMaximized() ? ui->header->setStyleSheet(headerMaximizeStyle) : ui->header->setStyleSheet(headerCollapseStyle);
    }
}


void WindowFrame::mousePressEvent(QMouseEvent *event) {
#if QT_VERSION_MAJOR < 6
    if (event->buttons() == Qt::LeftButton) {
        QWidget* widget = childAt(event->x(), event->y());
        if (widget == ui->LHeader || widget == ui->title || widget == ui->icon) {
            if (isMaximized()) {
                QPoint globalClickPos = event->globalPos();
                showNormal();
                ui->maximum->setIcon(QIcon(maximizeIcon));
                mIsCollapse ? ui->header->setStyleSheet(headerCollapseStyle) : ui->header->setStyleSheet(headerDefaultStyle);
                int newX = globalClickPos.x() - width() / 2;
                int newY = globalClickPos.y() - ui->header->height() / 2;
                move(newX, newY);
                mPosition = QPoint(width() / 2, ui->header->height() / 2);
            } else {
                mPosition = event->pos();
            }
        }
    }

    if (event->button() == Qt::RightButton) {
        QWidget* widget = childAt(event->x(), event->y());
        if (widget == ui->LHeader || widget == ui->title || widget == ui->icon) {
            showHeaderContextMenu(event->pos());
        }
    }
#else
    if (event->buttons() == Qt::LeftButton) {
        QWidget* widget = childAt(event->position().x(), event->position().y());
        if(widget == ui->LHeader || widget == ui->title || widget == ui->icon) {
            mPosition.setX(event->position().x());
            mPosition.setY(event->position().y());
        }
    }
    if (event->button() == Qt::RightButton ) {
        QWidget* widget = childAt(event->position().x(), event->position().y());
        if (widget == ui->LHeader || widget == ui->title || widget == ui->icon){
            showHeaderContextMenu(event->pos());
        }
    }

#endif
}

/// @brief Handler for the mouse move event within the window.
/// @param event Pointer to the mouse move event object (QMouseEvent).
/// @return No return value.
void WindowFrame::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() == Qt::LeftButton) {
#if QT_VERSION_MAJOR < 6
        if (mPosition.x() != 0 || mPosition.y() != 0) {
            move(event->globalX() - mPosition.x(), event->globalY() - mPosition.y());
        }
#else
        if (mPosition.x() != 0 || mPosition.y() != 0) {
            move(event->globalPosition().x() - mPosition.x(), event->globalPosition().x() - mPosition.y());
        }
#endif
    }
}


void WindowFrame::mouseReleaseEvent(QMouseEvent *event) {
    Q_UNUSED(event);
    mPosition.setX(0);
    mPosition.setY(0);
}


void WindowFrame::mouseDoubleClickEvent(QMouseEvent *event) {
    if (event->buttons() == Qt::LeftButton) {
#if QT_VERSION_MAJOR < 6
        QWidget* widget = childAt(event->x(), event->y());
#else
        QWidget* widget = childAt(event->position().x(), event->position().x());
#endif
        if(widget == ui->LHeader) {
            if(isMaximized()) {
                ui->maximum->setIcon(QIcon(maximizeIcon));
                ui->header->setStyleSheet(headerDefaultStyle);
                showNormal();
            } else {
                ui->maximum->setIcon(QIcon(defaultSizeIcon));
                ui->header->setStyleSheet(headerMaximizeStyle);
                showMaximized();
            }
        }
    }
}


#if QT_VERSION_MAJOR < 6
    bool WindowFrame::nativeEvent(const QByteArray &eventType, void *message, long *result)
#else
    bool WindowFrame::nativeEvent(const QByteArray &eventType, void *message, qint64 *result)
#endif
{
    Q_UNUSED(eventType)
    MSG *param = static_cast<MSG *>(message);

    if (param->message == WM_NCHITTEST) {

        if (isMaximized()) {
            *result = HTCLIENT;
            return true;
        }

        QPoint globalPos(GET_X_LPARAM(param->lParam), GET_Y_LPARAM(param->lParam));
        QPoint localPos = mapFromGlobal(globalPos);

        int nX = localPos.x();
        int nY = localPos.y();

        if (nX >= 0 && nX < mBorderSize) {
            if (nY >= 0 && nY < mBorderSize) {
                *result = HTTOPLEFT;
            } else if (nY >= height() - mBorderSize) {
                *result = HTBOTTOMLEFT;
            } else {
                *result = HTLEFT;
            }
        } else if (nX >= width() - mBorderSize) {
            if (nY >= 0 && nY < mBorderSize) {
                *result = HTTOPRIGHT;
            } else if (nY >= height() - mBorderSize) {
                *result = HTBOTTOMRIGHT;
            } else {
                *result = HTRIGHT;
            }
        } else if (nY >= 0 && nY < mBorderSize) {
            *result = HTTOP;
        } else if (nY >= height() - mBorderSize) {
            *result = HTBOTTOM;
        } else {
            return QWidget::nativeEvent(eventType, message, result);
        }

        return true;
    }

    return QWidget::nativeEvent(eventType, message, result);
}


void WindowFrame::enableMinimum(bool enable) {
    !enable ? ui->minimum->hide() : ui->minimum->show();
}


void WindowFrame::enableMaximum(bool enable) {
    !enable ? ui->maximum->hide() : ui->maximum->show();
}


void WindowFrame::enableClose(bool enable) {
    !enable ? ui->close->hide() : ui->close->show();
}


void WindowFrame::setIcon(const QString &iconPath) {
    QPixmap pixmap(iconPath);
    ui->icon->setPixmap(pixmap);
    ui->icon->setScaledContents(true);
    ui->icon->setAlignment(Qt::AlignCenter);
    ui->icon->resize(24, 24);
}


void WindowFrame::setTitle(const QString &title) {
    mTitle = title;
    ui->title->setText(mTitle);
}


bool WindowFrame::eventFilter(QObject *obj, QEvent *event) {
    if(obj == mMainBody) {
        if(event->type() == QEvent::HideToParent) {
            hide();
            return true;
        }
        if(event->type() == QEvent::ShowToParent) {
            show();
            return true;
        }
        return QObject::eventFilter(obj, event);
    } else {
        return QFrame::eventFilter(obj, event);
    }
    return false;
}


