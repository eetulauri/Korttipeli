// Ohjelmoinnin peruskurssin harjoitustyö
// 26.4.2018
// Eetu Pulkkinen, opiskelijanumero: 275184
// eetu.pulkkinen@student.tut.fi

#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include "deck.hh"
#include "opendeck.hh"
#include "gamerules.hh"
#include "cardslot.hh"
#include "timer.hh"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

    void addCardsToSlots(std::vector<Card*> addedCards);


private:
    void setupLayout();

    // Talletetaan attribuuteiksi ne widgetit, joita saattaa tarvita käsitellä pelin aikana.
    // Ohjelmakoodipohjassa näitä ei käytetä mihinkään.
    Deck* deck_;
    OpenDeck* pickedCards_;
    Timer* kello_;
    std::vector<CardSlot*> cardSlots_;
};

#endif // MAINWINDOW_HH
