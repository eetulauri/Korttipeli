#include "gamerules.hh"
#include "card.hh"


// Funktio saa parametrinaan alla olevan kortin ja päälle tulevan kortin
// tiedot merkkijonomuodossa.

bool GameRules::checkIfOneLower(std::string bottom, std::string top)
{
    unsigned int higherValue = 0;
    unsigned int lowerValue = stoi(top.substr(0, top.find_first_of(",")));

    if (bottom != "") {
        higherValue = stoi(bottom.substr(0, bottom.find_first_of(",")));
    }
    // tarkastetaan onko pudetettava kortti yhdellä pienempi
    // ja jos on niin hyväksytään pudotus
    if (lowerValue == higherValue -1 or higherValue == 0) {
        return true;
    } else {
        return false;
    }
}



