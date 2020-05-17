#include <QWidget>

class AnalogClock : public QWidget
{
    Q_OBJECT
public:
    AnalogClock(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *event);
    virtual void enterEvent(QEvent *event)
    {
        setStyleSheet("background-color: white");
    }
    virtual void leaveEvent(QEvent *event)
    {
        setStyleSheet("background-color: gray");
    }
};