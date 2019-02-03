#include <QtWidgets>
#include "timer.hh"

// kellon voi myöhemmässä vaiheessa muuttaa tämän hetkisen ajan sijasta
// näyttämään sekunteja pelin alkamisesta
Timer::Timer(QWidget *parent)
    : QLCDNumber(parent), startTime_(QTime::fromString("00.00.00", "h.m.s"))
{
    setSegmentStyle(Filled);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start();

    setMinimumSize(180, 260);
    setMaximumSize(180, 260);
    setFrameStyle(QFrame::NoFrame);
}

void Timer::showTime()
{
    startTime_.addMSecs(1000);
    QTime time = startTime_;
    time.start();

    QString text = time.toString("hh:mm");

    if ((time.second() % 2) == 0)
        text[2] = ' ';
    display(text);
}
