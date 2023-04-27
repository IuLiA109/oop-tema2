#ifndef _DEPOZIT_H_
#define _DEPOZIT_H_

#include "Automobil.h"
#include <string>
#include <ostream>
#include <memory>
#include <vector>

class Depozit {
    static std::vector<std::shared_ptr<Automobil>> automobile;
private:
    std::string name;
    std::string judet;
    std::string oras;
    int capacitate;
    Depozit();
public:
    Depozit(const std::string name, const std::string judet, const std::string oras, int capacitate);

    const std::string &getName() const;
    void setName(const std::string &name);

    const std::string &getJudet() const;
    void setJudet(const std::string &judet);

    const std::string &getOras() const;
    void setOras(const std::string &oras);

    int getCapacitate() const;
    void setCapacitate(int capacitate);

    static void AdaugaAuto(std::shared_ptr<Automobil>);
    static void ArataAuto();
    static void ScoateAuto(std::shared_ptr<Automobil>);

//    virtual void Print(std::ostream &os) const;
//
//    friend std::ostream &operator<<(std::ostream &os, const Depozit &depozit);

    virtual ~Depozit();
};

#endif
