#ifndef WINDOWFRAME_H
#define WINDOWFRAME_H

#include <QFrame>

namespace Ui {
class WindowFrame;
}

class WindowFrame : public QFrame {
    Q_OBJECT

public:
    explicit WindowFrame(QWidget *parent = nullptr, QWidget *child = nullptr);
    ~WindowFrame();

public:
    /// Show or hide the window minimization button.
    void enableMinimum(bool enable);
    /// Show or hide the window maximization button.
    void enableMaximum(bool enable);
    /// Show or hide the window close button.
    void enableClose(bool enable);

protected:
    /// Handler for the mouse press event.
    void mousePressEvent(QMouseEvent *event) override;
    /// Handler for the mouse move event within the window.
    void mouseMoveEvent(QMouseEvent *event) override;
    /// Handler for the mouse release event within the window.
    void mouseReleaseEvent(QMouseEvent *event) override;
    /// Handler for the mouse double-click event within the window.
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    /// Handler for the native window event.
    bool nativeEvent(const QByteArray &eventType, void *message, long *result) override;
    /// Override event filtering function for the WindowFrame class.
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    /// Handler for the "Close" button click signal.
    void on_close_clicked();
    /// Handler for the "Maximize/Restore" button click signal.
    void on_maximum_clicked();
    /// Handler for the "Minimize" button click signal.
    void on_minimum_clicked();

private:
    /// Pointer to the user interface object.
    Ui::WindowFrame *ui;
    /// Pointer to the main widget (child widget).
    QWidget *mMainBody;
    /// Window mPosition on the screen.
    QPoint mPosition;
    /// Size of the window borders.
    int mBorderSize;
};

#endif // WINDOWFRAME_H
