#ifndef WINDOWFRAME_H
#define WINDOWFRAME_H

#include <QFrame>

namespace Ui {
class WindowFrame;
}

class WindowFrame : public QFrame{
    Q_OBJECT

public:
    explicit WindowFrame(QWidget *parent = nullptr, QWidget *child=nullptr);
    ~WindowFrame();

private slots:
    /// Обработчик сигнала клика на кнопке "Закрыть".
    void on_close_clicked();
    /// Обработчик сигнала клика на кнопке "Максимизировать/Восстановить".
    void on_maximum_clicked();
    /// Обработчик сигнала клика на кнопке "Максимизировать/Восстановить".
    void on_minimum_clicked();
private:
    /// Указатель на объект пользовательского интерфейса.
    Ui::WindowFrame *ui;
    /// Указатель на главный виджет (дочерний виджет).
    QWidget *mainBody;
    /// Позиция окна на экране.
    QPoint position;
    /// Размер границ окна.
    int borderSize;
protected:
    /// Обработчик события нажатия кнопки мыши.
    void mousePressEvent(QMouseEvent *event) override;
    /// Обработчик события перемещения мыши в окне.
    void mouseMoveEvent(QMouseEvent* event) override;
    /// Обработчик события отпускания кнопки мыши в окне.
    void mouseReleaseEvent(QMouseEvent* event) override;
    /// Обработчик события двойного щелчка мыши в окне.
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    /// Обработчик нативного события окна.
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);
public:
    /// Показать или скрыть кнопку минимизации окна.
    void enableMinimum(bool enable);
    /// Показать или скрыть кнопку максимизации окна.
    void enableMaximum(bool enable);
    /// Показать или скрыть кнопку закрытия окна.
    void enableClose(bool enable);
protected:
    /// Переопределение функции фильтрации событий для класса WindowFrame.
    bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif // WINDOWFRAME_H
