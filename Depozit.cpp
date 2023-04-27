#include "Depozit.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;


Depozit::Depozit(const string name, const string judet, const string oras, int capacitate) : name(name), judet(judet), oras(oras), capacitate(capacitate) {
}

const string &Depozit::getName() const {
    return name;
}

void Depozit::setName(const string &name) {
    Depozit::name = name;
}

const string &Depozit::getJudet() const {
    return judet;
}

void Depozit::setJudet(const string &judet) {
    Depozit::judet = judet;
}

const string &Depozit::getOras() const {
    return oras;
}

void Depozit::setOras(const string &oras) {
    Depozit::oras = oras;
}

int Depozit::getCapacitate() const {
    return capacitate;
}

void Depozit::setCapacitate(int capacitate) {
    Depozit::capacitate = capacitate;
}

//ostream &operator<<(ostream &os, const Depozit &depozit) {
//    depozit.Print(os);
//    return os;
//}
//
//void Depozit::Print(ostream &os) const {
//    os << "nume: " << name << " judet: " << judet << " oras: " << oras << " capacitate: "<< capacitate;
//}

std::vector<std::shared_ptr<Automobil>> Depozit::automobile;

Depozit::Depozit() =default;

class ExceptieAuto : public std::exception {
public:
    ExceptieAuto() = default;

    const char* what() const noexcept override  {
        return "Masina nu exista in acest depozit.";
    }
};

void Depozit::AdaugaAuto(std::shared_ptr<Automobil> automobil) {
    automobile.push_back(automobil);
}

void Depozit::ScoateAuto(std::shared_ptr<Automobil> automobil) {
    auto it = find(automobile.begin(), automobile.end(), automobil);
    if (it != automobile.end()) {
        automobile.erase(it);
    }
    else{
        throw ExceptieAuto();
    }
}

void Depozit::ArataAuto() {
    for (auto &automobil : Depozit::automobile) {
        std::cout << *automobil << '\n';
    }
}

Depozit::~Depozit()=default;