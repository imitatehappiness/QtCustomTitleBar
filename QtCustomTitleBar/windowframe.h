#pragma once

#include <QFrame>
#include <QMenuBar>
#include <QMenu>

#include <QPropertyAnimation>

namespace Ui {
class WindowFrame;
}

/**
 * @brief Custom window frame with draggable title bar and control buttons.
 */
class WindowFrame : public QFrame {
    Q_OBJECT

public:
    /**
     * @brief Constructor for the WindowFrame class.
     * @param parent The parent widget.
     * @param child The child widget to be added to the window (optional).
     */
    explicit WindowFrame(QWidget *parent = nullptr, QWidget *child = nullptr);

    /**
     * @brief Destructor for the WindowFrame class.
     */
    ~WindowFrame();

    /**
     * @brief Initializes window control icons.
     */
    void initIcons();

    /**
     * @brief Displays the context menu in the header.
     * @param pos Position of the mouse click.
     */
    void showHeaderContextMenu(const QPoint &pos);

    /**
     * @brief Show or hide the window minimization button.
     * @param enable If true, the button is shown; otherwise, it is hidden.
     */
    void enableMinimum(bool enable);

    /**
     * @brief Show or hide the window maximization button.
     * @param enable If true, the button is shown; otherwise, it is hidden.
     */
    void enableMaximum(bool enable);

    /**
     * @brief Show or hide the window close button.
     * @param enable If true, the button is shown; otherwise, it is hidden.
     */
    void enableClose(bool enable);

    /**
     * @brief Sets the window icon.
     * @param iconPath Path to the icon file.
     */
    void setIcon(const QString& iconPath);

    /**
     * @brief Sets the window title.
     * @param title The title to be displayed.
     */
    void setTitle(const QString& title);

protected:
    /**
     * @brief Handles the mouse press event.
     * @param event Pointer to the QMouseEvent object.
     */
    void mousePressEvent(QMouseEvent *event) override;

    /**
     * @brief Handles the mouse move event for window dragging.
     * @param event Pointer to the QMouseEvent object.
     */
    void mouseMoveEvent(QMouseEvent *event) override;

    /**
     * @brief Handles the mouse release event.
     * @param event Pointer to the QMouseEvent object.
     */
    void mouseReleaseEvent(QMouseEvent *event) override;

    /**
     * @brief Handles the mouse double-click event on the header.
     * @param event Pointer to the QMouseEvent object.
     */
    void mouseDoubleClickEvent(QMouseEvent *event) override;

    /**
     * @brief Handles native OS window events (used for resizing).
     * @param eventType Type of the event.
     * @param message Native message pointer.
     * @param result Result pointer.
     * @return True if the event was handled.
     */
#if QT_VERSION_MAJOR < 6
    bool nativeEvent(const QByteArray &eventType, void *message, long *result) override;
#else
    bool nativeEvent(const QByteArray &eventType, void *message, qint64 *result) override;
#endif
    /**
     * @brief Event filter for child widgets.
     * @param obj The object that received the event.
     * @param event The event to filter.
     * @return True if the event was handled.
     */
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
    /**
     * @brief Slot for handling the close button click.
     */
    void on_close_clicked();

    /**
     * @brief Slot for handling the maximize/restore button click.
     */
    void on_maximum_clicked();

    /**
     * @brief Slot for handling the minimize button click.
     */
    void on_minimum_clicked();

    /**
     * @brief Slot for handling the collapse button click.
     */
    void on_collapse_clicked();

private:
    // Pointer to the UI elements.
    Ui::WindowFrame *ui;

    //  Pointer to the embedded main widget.
    QWidget *mMainBody;

    //  Position used for window dragging.
    QPoint mPosition;

    //  Border width for resizing.
    int mBorderSize;

    //  Collapse state flag.
    bool mIsCollapse;

    //  Window title string.
    QString mTitle;
};
