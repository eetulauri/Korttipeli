#include "deck.hh"

#include <QDrag>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QPainter>
#include <QLabel>
#include <algorithm>
#include <random>
#include <ctime>

Deck::Deck(QWidget *parent) : QFrame(parent)
{
    setMinimumSize(180, 260);
    setMaximumSize(180, 260);
    setFrameStyle(QFrame::NoFrame);
    // tämä pidetään sellaisenaan vaikka pelissä käytetään vain yhtä
    // maata, sillä maata voi halutessaa vaihtaa tai ottaa
    // kaikki neljä maata taas käyttöön helposti
    for (int suit = SPADE; suit != SUIT_COUNT; ++suit){

        for (unsigned value = 1; value <= 13; ++value){
            auto card = new Card(static_cast<CardSuit>(3), value, this);
            int xOffset = (this->width() - card->width()) / 2;
            int yOffset = (this->height() - card->height()) / 2;
            card->move(xOffset, yOffset);
            cards_.push_back(card);
        }
    }
    // sekoitetaan pakka
    shuffle_deck();
}

Card* Deck::pickCard()
{
    if (cards_.empty()){
        return nullptr;
    } else {
        Card* card = cards_.back();
        cards_.pop_back();
        return card;
    }
}

// sekoitetaan pakka pelin alussa
void Deck::shuffle_deck()
{
    std::shuffle(cards_.begin(), cards_.end(), std::default_random_engine(time(0)));
}

// Suoritetaan, kun pakkaa klikataan.
void Deck::mousePressEvent(QMouseEvent *event)
{
    // Ohjelma ei saa kaatua tyhjän pakan klikkaukseen.
    if (cards_.empty()){
        return;
    }

    std::vector<Card*> newCards;

    // nostetaan 7 korttia pakasta ja sijoitetaan
    // ne vectoriin
    for (int i = 0; i < 7; i++) {
        Card* card = cards_.back();
        cards_.pop_back();

        newCards.push_back(card);
        if (cards_.empty()) {
            break;
        }
    }
    if (newCards.size() < 1) {
        return;
    }

    // lähetetään nostetut 7 korttia mainwindowille
    // jossa ne lisätään cardSlotteihin
    emit deckOnClick(newCards);

    event->accept();
}
