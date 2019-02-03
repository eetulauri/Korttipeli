// Ohjelmoinnin peruskurssin harjoitustyö
// 26.4.2018
// Eetu Pulkkinen, opiskelijanumero: 275184
// eetu.pulkkinen@student.tut.fi

#ifndef GAMERULES_HH
#define GAMERULES_HH
#include <string>
#include <cardslot.hh>

namespace GameRules {

    // Tarkastusfunktio, joka varmistaa, että päälle laitetaan vain yhtä
    // pienempiä kortteja
    bool checkIfOneLower(std::string bottom, std::string top);

}

#endif // GAMERULES_HH
