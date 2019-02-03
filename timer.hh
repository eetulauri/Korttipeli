// Ohjelmoinnin peruskurssin harjoitustyö
// 26.4.2018
// Eetu Pulkkinen, opiskelijanumero: 275184
// eetu.pulkkinen@student.tut.fi

#ifndef TIMER_HH
#define TIMER_HH

#include <QFrame>
#include <QLCDNumber>
#include <QtWidgets>

// yksinkertainen kello joka on helppo muuttaa
// möyhemmin sekuntikelloksi
class Timer : public QLCDNumber
{
    Q_OBJECT

public:
    Timer(QWidget *parent = 0);

private slots:
    void showTime();

private:

    QTime startTime_;

};

#endif // TIMER_HH
