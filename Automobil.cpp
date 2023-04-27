#include "Automobil.h"
#include <iostream>
using namespace std;

Automobil::Automobil(const std::string &marca, int putere, int anFabricatie) : marca(marca),putere(putere),an_fabricatie(anFabricatie) {}
Automobil::Automobil() {}

const std::string &Automobil::getMarca() const {
    return marca;
}
void Automobil::setMarca(const std::string &marca) {
    Automobil::marca = marca;
}

int Automobil::getPutere() const {
    return putere;
}
void Automobil::setPutere(int putere) {
    Automobil::putere = putere;
}

int Automobil::getAnFabricatie() const {
    return an_fabricatie;
}
void Automobil::setAnFabricatie(int anFabricatie) {
    an_fabricatie = anFabricatie;
}

ostream &operator<<(ostream &os, const Automobil &autom) {
    autom.Print(os);
    return os;
}

void Automobil::Print(std::ostream &os) const{
    os<<"marca: "<<marca<<" putere: "<<putere<<" an fabricatie: "<<an_fabricatie;
}

void Automobil::Read() {
    cout<<"Introduceti marca:";
    cin >> marca;
    cout<<"Introduceti putere:";
    cin>>putere;
//    autom.setPutere(b);
    cout<<"Introduceti an fabricatie:";
    cin >> an_fabricatie;
}

Automobil::~Automobil()=default;
