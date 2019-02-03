// Ohjelmoinnin peruskurssin harjoitustyö
// 26.4.2018
// Eetu Pulkkinen, opiskelijanumero: 275184
// eetu.pulkkinen@student.tut.fi

#ifndef OPENDECK_HH
#define OPENDECK_HH
#include <QFrame>

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

#include <QStackedLayout>
#include "card.hh"

///////// OPEN DECK EI KÄYTÖSSÄ TÄSSÄ PELISSÄ JA SE ON ASETETTU HIDDENIKSI/////
///////// koodia ei kuitenkaan poisteta sillä siitä saattaa olla hyötyä
///////// myöhemmin jos peliä haluaa muuttaa

class OpenDeck : public QFrame
{
public:
    OpenDeck(QWidget* parent = 0);
public slots:
    void addCard(Card* card);
protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent* event);
    void mousePressEvent(QMouseEvent *event);
private:
    QStackedLayout* layout_;  // Sisältää ne kortti-widgetit, jotka avopakassa on.
};

#endif // OPENDECK_HH
