#ifndef _AUTOBUS_H_
#define _AUTOBUS_H_

#include "Automobil.h"
#include <string>
#include <ostream>
//class MyOutOfBoundsException{};
class Autobus: public Automobil{
    int nr_locuri;
public:
    Autobus(const std::string &marca, int putere, int anFabricatie, int nrLocuri);
    Autobus();
    Autobus(const Autobus& bus);

    Autobus& operator=(const Autobus& bus);

    void Print(std::ostream &os) const override;
    void Read();

    int getNrLocuri() const;

    void setNrLocuri(int nrLocuri);

    void CeEste() const override;

    void RezervaLoc();

};


#endif
