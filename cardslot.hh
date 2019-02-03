// Ohjelmoinnin peruskurssin harjoitustyö
// 26.4.2018
// Eetu Pulkkinen, opiskelijanumero: 275184
// eetu.pulkkinen@student.tut.fi

#ifndef CARDSLOT_HH
#define CARDSLOT_HH

#include "gamerules.hh"
#include "card.hh"

#include <list>
#include <string>
#include <QFrame>

QT_BEGIN_NAMESPACE
class QDragEnterEvent;
class QDropEvent;
QT_END_NAMESPACE

using CheckFunction = bool(*)(std::string, std::string);

class CardSlot: public QFrame
{
public:
    // Rakentaja ja metodi, jolla slotiin voidaan lisätä kortti.
    CardSlot(CheckFunction function, QWidget* parent = 0);
    void addCard(Card* card);

    // Itse toteutetut Qt:n widgetin raahaukseen liittyvät metodit.
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
    void mousePressEvent(QMouseEvent *event);

private:
    // Apumetodeita dropEventin käyttöön.
    void parseNewCards(std::list<Card*>& newCards, QStringList& newCardsData);
    void setupNewCards(std::list<Card*>& newCards);

    // tarkastaa onko pinossa kortit 1-13 jolloin pino häviää
    void isRowComplete();

    // poistaa pinon kortteja
    void removeStack();

    // merkkijonojen käsittelyyn
    std::vector<std::string> split(std::string& s, const char delimiter, bool ignore_empty = false);

    // Päällimmäisenä oleva kortti on talletettu attribuutiksi, koska se vaikuttaa
    // siihen, mitä tähän slotiin saa raahata. Muut kortit ovat vain tämän widgetin
    // lapsia, ja niihin päästään tarvittaessa käsiksi Qt:n parent-mekanismin avulla.
    Card* topCard_;

    // Pelisääntöfunktio, joka määrittelee, mitä kortteja tähän widgettiin saa raahata.
    CheckFunction checkFunction_;
};

#endif // CARDSLOT_HH
