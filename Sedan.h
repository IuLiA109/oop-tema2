#ifndef _SEDAN_H_
#define _SEDAN_H_

#include "Automobil.h"
#include <string>
#include <ostream>

class Sedan: public Automobil{
    std::string transmisie;
public:
    Sedan(const std::string &marca, int putere, int anFabricatie, const std::string &transmisie);
    Sedan();
    Sedan(const Sedan& sed);

    Sedan& operator=(const Sedan& sed);

    void Print(std::ostream &os) const override;
    void Read();

    const std::string &getTransmisie() const;

    void setTransmisie(const std::string &Transmisie);

    void CeEste() const override;
};


#endif
