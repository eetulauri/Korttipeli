// Ohjelmoinnin peruskurssin harjoitustyö
// 26.4.2018
// Eetu Pulkkinen, opiskelijanumero: 275184
// eetu.pulkkinen@student.tut.fi

#ifndef DECK_HH
#define DECK_HH

#include <vector>
#include <QFrame>
#include "card.hh"

class Deck : public QFrame
{
    Q_OBJECT

public:
    Deck(QWidget *parent = 0);

    // Korttipakasta voi nostaa päällimmäisen kortin.
    Card* pickCard();

    // sekoittaa pakan
    void shuffle_deck();

signals:
    // signaali, joka lähetetään kun pakkaa klikataan
    void deckOnClick(std::vector<Card*>);

protected:
    // Itse toteutettu Qt:n widgetin klikkaamiseen liittyvä metodi.
    void mousePressEvent(QMouseEvent *event);

private:
    // Korttipakan sisältämät kortit.
    std::vector<Card*> cards_;
};

#endif // DECK_HH
