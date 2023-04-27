#include <iostream>
#include <vector>
#include "Automobil.h"
#include "Autobus.h"
#include "Depozit.h"
#include "Sedan.h"

using namespace std;

class ExceptieLocuri : public std::exception {
public:
    ExceptieLocuri() = default;

    const char* what() const noexcept override  {
        return "Autobusul acesta nu mai are locuri disponibile.";
    }
};

class ExceptieAuto : public std::exception {
public:
    ExceptieAuto() = default;

    const char* what() const noexcept override  {
        return "Masina nu exista in acest depozit.";
    }
};

void citire_n(){
    cout<<"Intorduceti cate automobile doriti sa introduceti in depozit"<<'\n';
    int n;
    cin>>n;
    vector<Automobil*> v;
    int x;
    for(int i=0; i<n; i++){
        cout<<'\n'<<"Pentru a introduce un autobus, apasati 1!"<<'\n';
        cout<<"Pentru a introduce un sedan, apasati 2!"<<'\n';
        cin>>x;
        if (x==2) {
            v.push_back(new Sedan());
            Sedan *aux=dynamic_cast<Sedan*>(v.back());
            (v.back())->Read();
            Depozit::AdaugaAuto(shared_ptr<Automobil>(aux));
            aux->CeEste();
        }
        if (x==1) {
            v.push_back(new Autobus());
            Autobus *aux=dynamic_cast<Autobus*>(v.back());
            (v.back())->Read();
            Depozit::AdaugaAuto(shared_ptr<Automobil>(aux));
            aux->CeEste();
        }
    }

}

void try_catch_autobus(){
    auto b=std::make_shared<Autobus>("Mercedes", 150, 2009,1);
    try {
        b->RezervaLoc();
        b->RezervaLoc();
        cout<<b->getNrLocuri();
    }
    catch (const ExceptieLocuri &l) {
        std::cout << l.what() << '\n';
    }
}

void try_catch_depozit(){
    auto a=std::make_shared<Sedan>("BMW", 300, 2023,"manuala");
    auto b=std::make_shared<Autobus>("Mercedes", 150, 2009,30);
    auto c=std::make_shared<Sedan>("Toyota", 150, 2014,"automata");

    Depozit::AdaugaAuto(c);
    Depozit::AdaugaAuto(b);
    try {
        Depozit::ScoateAuto(a);
    }
    catch (const ExceptieAuto &au) {
        std::cout << au.what() << '\n';
    }
    cout<<'\n'<<"In depozit se afla urmatoarele automobile:"<<'\n';
    Depozit::ArataAuto();
}

int main() {
    citire_n();
    cout<<'\n';
    Depozit::ArataAuto();
//    try_catch_autobus();
//    try_catch_depozit();
    return 0;

}
