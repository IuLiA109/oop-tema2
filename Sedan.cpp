#include "Sedan.h"
#include <iostream>
using namespace std;

Sedan::Sedan(const string &marca, int putere, int anFabricatie, const string &transmisie) : Automobil(marca, putere,anFabricatie),transmisie(transmisie) {}
Sedan::Sedan() {}
Sedan::Sedan(const Sedan &sed) : Automobil(sed.marca, sed.putere, sed.an_fabricatie), transmisie(sed.transmisie) {
}

Sedan &Sedan::operator=(const Sedan &sed) {
    Automobil::operator=(sed);
    transmisie=sed.transmisie;
    return *this;
}

const std::string &Sedan::getTransmisie() const {
    return transmisie;
}

void Sedan::setTransmisie(const string &Transmisie) {
    transmisie = Transmisie;
}

void Sedan::Print(ostream &os) const {
    Automobil::Print(os);
    os << " transmisie: " << transmisie;
}

void Sedan::Read(){
    Automobil::Read();
    cout<<"Introduceti transmisie: "; cin>>transmisie;
}

//void Sedan::Read(istream &is) {
//    Sedan::Read(is);
//    cout<<"Introduceti transmisie:";
//    is >> transmisie;
//}

void Sedan::CeEste() const {
    cout<<"Ati selectat un sedan " << marca << "!\n";
}