#include "Autobus.h"
#include <iostream>
using namespace std;

Autobus::Autobus(const string &marca, int putere, int anFabricatie, int nrLocuri) : Automobil(marca, putere,anFabricatie),nr_locuri(nrLocuri) {}
Autobus::Autobus(){}
Autobus::Autobus(const Autobus &bus) : Automobil(bus.marca, bus.putere, bus.an_fabricatie), nr_locuri(bus.nr_locuri) {
}

Autobus &Autobus::operator=(const Autobus &bus) {
    Automobil::operator=(bus);
    nr_locuri=bus.nr_locuri;
    return *this;
}

int Autobus::getNrLocuri() const {
    return nr_locuri;
}

void Autobus::setNrLocuri(int nrLocuri) {
    nr_locuri = nrLocuri;
}

void Autobus::Print(ostream &os) const {
    Automobil::Print(os);
    os << " numar locuri: " << nr_locuri;
}

//void Autobus::Read(istream &is) {
//    Automobil::Read(is);
//    cout<<"Introduceti numar locuri:";
//    is >> nr_locuri;
//}

class ExceptieLocuri : public std::exception {
public:
    ExceptieLocuri() = default;

    const char* what() const noexcept override  {
        return "Autobusul acesta nu mai are locuri disponibile.";
    }
};

void Autobus::RezervaLoc() {
    if ( nr_locuri == 0)
        throw ExceptieLocuri();
    else
        nr_locuri --;
}

void Autobus::CeEste() const {
    cout<<"Ati selectat un autobus " << marca << "!\n";
}

void Autobus::Read(){
    Automobil::Read();
    cout<<"Introduceti nr locuri: "; cin>>nr_locuri;
}