// Ohjelmoinnin peruskurssin harjoitustyö
// 26.4.2018
// Eetu Pulkkinen, opiskelijanumero: 275184
// eetu.pulkkinen@student.tut.fi
// Spiderette pasianssi. Kortteja on tarkoitus pinota suurimmasta
// pienimpään (1-13) niitä siirtelemällä. Pakkaa klikattaessa, jokaiseen
// korttipaikkaan jaetaan uusi kortti. Pelin voittaa kun kaikki 4 pinoa
// on kasattu ja häviää, kun ei voi suorittaa enään yhtäkään siirtoa

#include "mainwindow.hh"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
