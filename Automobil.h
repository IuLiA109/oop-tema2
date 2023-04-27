#ifndef _AUTOMOBIL_H_
#define _AUTOMOBIL_H_
#include <string>
#include <ostream>

class Automobil {
protected:
    std::string marca;
    int putere;
    int an_fabricatie;
public:
    Automobil(const std::string &marca,  int putere, int anFabricatie);

    Automobil();

    const std::string &getMarca() const;
    void setMarca(const std::string &marca);

    int getPutere() const;
    void setPutere(int putere);

    int getAnFabricatie() const;
    void setAnFabricatie(int anFabricatie);

    virtual void Print(std::ostream &os) const;
    virtual void Read() = 0;
//    virtual void citire() =0;

    virtual void CeEste() const = 0; //metoda virtuala pura

    friend std::ostream &operator<<(std::ostream &os, const Automobil &automobil);
//    friend std::istream &operator>>(std::istream &is, Automobil &automobil);

    virtual ~Automobil();
};

#endif
