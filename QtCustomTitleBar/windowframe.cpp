#include "windowframe.h"
#include "ui_windowframe.h"

#include <QMouseEvent>
#include <windows.h>
#include <windowsx.h>
#include <QDebug>

/// @brief Constructor for the WindowFrame class.
/// @param parent The parent widget.
/// @param child The child widget to be added to the window (optional).
WindowFrame::WindowFrame(QWidget *parent, QWidget *child)
    : QFrame(parent), ui(new Ui::WindowFrame){

    ui->setupUi(this);

    QPixmap pixmap(":/recources/icons/icon.png");
    ui->icon->setPixmap(pixmap);
    ui->icon->setScaledContents(true);
    ui->icon->setAlignment(Qt::AlignCenter);
    ui->icon->resize(24, 24);

    ui->collapse->setIcon(QIcon(":/recources/icons/collapse_hide.png"));
    ui->close->setIcon(QIcon(":/recources/icons/close.png"));
    ui->maximum->setIcon(QIcon(":/recources/icons/maximize.png"));
    ui->minimum->setIcon(QIcon(":/recources/icons/minimize.png"));

    setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint);
    setAttribute(Qt::WA_TranslucentBackground);
    if(child != nullptr) {
        ui->body->layout()->addWidget(child);
        mMainBody = child;
        mMainBody->installEventFilter(this);
        resize(child->size());
    }
    isCollapse = false;
}

/// @brief Destructor for the WindowFrame class.
WindowFrame::~WindowFrame(){
    int subBodies = ui->body->layout()->count();
    if(subBodies > 0) {
        for(int i = 0; i < subBodies; i++) {
            QWidget *subBody = ui->body->layout()->itemAt(i)->widget();
            delete subBody;
        }
    }
    delete ui;
}

/// @brief Handler for the "Close" button click signal.
void WindowFrame::on_close_clicked(){
    close();
}

/// @brief Handler for the "Maximize/Restore" button click signal.
void WindowFrame::on_maximum_clicked(){
    if(isMaximized()) {
        ui->maximum->setIcon(QIcon(":/recources/icons/maximize.png"));
        showNormal();
    } else {
        ui->maximum->setIcon(QIcon(":/recources/icons/default_size.png"));
        showMaximized();
    }
}

/// @brief Handler for the "Minimize" button click signal.
void WindowFrame::on_minimum_clicked(){
    showMinimized();
}

void WindowFrame::on_collapse_clicked() {
    if (isCollapse) {
        ui->body->setVisible(true);
        isCollapse = false;
        ui->collapse->setIcon(QIcon(":/recources/icons/collapse_hide.png"));
    } else {
        ui->body->setVisible(false);
        isCollapse = true;
        ui->collapse->setIcon(QIcon(":/recources/icons/collapse_show.png"));
    }
}


/// @brief Handler for the mouse press event.
/// @param event Pointer to the QMouseEvent object containing event information.
void WindowFrame::mousePressEvent(QMouseEvent *event) {
    if (event->buttons() == Qt::LeftButton) {
        QWidget* widget = childAt(event->x(), event->y());
        if(widget == ui->buttons) {
            mPosition.setX(event->x());
            mPosition.setY(event->y());
        }
    }
}

/// @brief Handler for the mouse move event within the window.
/// @param event Pointer to the mouse move event object (QMouseEvent).
/// @return No return value.
void WindowFrame::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() == Qt::LeftButton) {
        if (mPosition.x() != 0 || mPosition.y() != 0) {
            move(event->globalX() - mPosition.x(), event->globalY() - mPosition.y());
        }
    }
}

/// @brief Handler for the mouse release event within the window.
/// @param event Pointer to the mouse release event object (QMouseEvent).
void WindowFrame::mouseReleaseEvent(QMouseEvent *event) {
    Q_UNUSED(event);
    mPosition.setX(0);
    mPosition.setY(0);
}

/// @brief Handler for the mouse double-click event within the window.
/// @param event Pointer to the mouse double-click event object (QMouseEvent).
void WindowFrame::mouseDoubleClickEvent(QMouseEvent *event) {
    if (event->buttons() == Qt::LeftButton) {
        QWidget* widget = childAt(event->x(), event->y());
        if(widget == ui->buttons) {
            isMaximized() ? showNormal() : showMaximized();
        }
    }
}

/// @brief Handler for the native window event.
/// @param eventType The type of event, as a byte array (QByteArray).
/// @param message Pointer to a structure containing event information (void*).
/// @param result Pointer to a variable for returning the result (long*).
/// @return The return value, true if the event was handled, otherwise false.
bool WindowFrame::nativeEvent(const QByteArray &eventType, void *message, long *result) {
    Q_UNUSED(eventType)
    MSG *param = static_cast<MSG *>(message);
    switch (param->message){
        case WM_NCHITTEST:{
            int nX = GET_X_LPARAM(param->lParam) - geometry().x();
            int nY = GET_Y_LPARAM(param->lParam) - geometry().y();

            if (childAt(nX, nY) != ui->header && childAt(nX, nY) != ui->body){
                return QWidget::nativeEvent(eventType, message, result);
            }

            *result = HTCAPTION;

            if ((nX > 0) && (nX < mBorderSize)){
                *result = HTLEFT;
            }

            if ((nX > width() - mBorderSize) && (nX < width())){
                *result = HTRIGHT;
            }

            if ((nY > 0) && (nY < mBorderSize)){
                *result = HTTOP;
            }

            if ((nY > height() - mBorderSize) && (nY < height())){
                *result = HTBOTTOM;
            }

            if ((nX > 0) && (nX < mBorderSize) && (nY > 0) && (nY < mBorderSize)){
                *result = HTTOPLEFT;
            }

            if ((nX > width() - mBorderSize) && (nX < width()) && (nY > 0) && (nY < mBorderSize)){
                *result = HTTOPRIGHT;
            }

            if ((nX > 0) && (nX < mBorderSize) && (nY > height() - mBorderSize) && (nY < height())){
                *result = HTBOTTOMLEFT;
            }

            if ((nX > width() - mBorderSize) && (nX < width()) && (nY > height() - mBorderSize) && (nY < height())){
                *result = HTBOTTOMRIGHT;
            }

            return true;
        }
    }

    return QWidget::nativeEvent(eventType, message, result);
}

/// @brief Show or hide the window minimization button.
/// @param enable If true, the button will be shown; if false, it will be hidden.
void WindowFrame::enableMinimum(bool enable) {
    !enable ? ui->minimum->hide() : ui->minimum->show();
}

/// @brief Show or hide the window maximization button.
/// @param enable If true, the button will be shown; if false, it will be hidden.
void WindowFrame::enableMaximum(bool enable) {
    !enable ? ui->maximum->hide() : ui->maximum->show();
}

/// @brief Show or hide the window close button.
/// @param enable If true, the button will be shown; if false, it will be hidden.
void WindowFrame::enableClose(bool enable) {
    !enable ? ui->close->hide() : ui->close->show();
}

/// @brief Override event filtering function for the WindowFrame class.
/// @param obj Pointer to the object for which the event was generated.
/// @param event Pointer to the QEvent object representing the event.
/// @return `true` if the event was handled, otherwise `false`.
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


