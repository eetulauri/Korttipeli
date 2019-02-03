#include <QFrame>
#include <QHBoxLayout>

#include "mainwindow.hh"
#include "cardslot.hh"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    setupLayout();
    // yhdistetään deckin painallus ja korttien jako cardSlotteihin
    connect(deck_, &Deck::deckOnClick, this, &MainWindow::addCardsToSlots);

}

MainWindow::~MainWindow()
{
}

// lisää kuhunkin cardslottiin yhden avoinaisen kortin pakkaa klikattaessa
void MainWindow::addCardsToSlots(std::vector<Card *> addedCards)
{
    for (unsigned int i = 0; i < addedCards.size(); i++) {
        CardSlot* slot = cardSlots_.at(i);
        Card* card = addedCards.at(i);
        slot->addCard(card);
        card->show();
        card->turn();
    }
}

void MainWindow::setupLayout()
{
    // Pääikkunan isoimpana rakenteena on frame, joka sisältää...
    QFrame* frame = new QFrame;
    QVBoxLayout* frameLayout = new QVBoxLayout(frame);

    // asetetaan taustakuva
    QPixmap bkgnd(":/cards/background4.png");
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);

    // vaihdetaan ikkunan otsikko
    this->setWindowTitle("Spiderette");

    // ... alarivin ja ylärivin.
    QHBoxLayout* bottomRowLayout = new QHBoxLayout();
    QHBoxLayout* topRowLayout = new QHBoxLayout();
    frameLayout->addLayout(topRowLayout);
    frameLayout->addLayout(bottomRowLayout);

    // Luodaan pakkaoliot.
    deck_ = new Deck(this);
    pickedCards_ = new OpenDeck(this);

    // luodaan kello
    kello_ = new Timer(this);

    // Lisätään yläriville suljettu ja avoin pakka sekä kello
    topRowLayout->addWidget(deck_);
    topRowLayout->addWidget(pickedCards_);
    topRowLayout->addWidget(kello_);


    // alariville lisätään 7 paikkaa jossa eri määrä kortteja
    for (int i = 0; i < 7; i++) {
        CardSlot* new_slot = new CardSlot(&GameRules::checkIfOneLower, this);
        cardSlots_.push_back(new_slot);
        Card* top = nullptr;

        for (int j = 0; j <= i; j++) {
            if (j == 0 ) {
                top = deck_->pickCard();
                new_slot->addCard(top);
            } else {
                Card* newCard = deck_->pickCard();
                new_slot->addCard(newCard);
                top = newCard;
            }
        }
        if (top != nullptr) {
            top->turn();
        }
        bottomRowLayout->addWidget(new_slot);
    }
    setCentralWidget(frame);
}
