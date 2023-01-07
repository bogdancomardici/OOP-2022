#include <string>
#include <utility>
#include "IOstream.h"
#include "Bilet.h"

template<class T>
class Abonament : public IOstream{

    std::string mijlocTransport;
    float pret;
    int valabilitate;
    std::string nume;
    T t;

public:
    const std::string &getMijlocTransport() const {
        return mijlocTransport;
    }

    void setMijlocTransport(const std::string &mijlocTransport_) {
        Abonament::mijlocTransport = mijlocTransport_;
    }

    float getPret() const {
        return pret;
    }

    void setPret(float pret_) {
        Abonament::pret = pret_;
    }

    int getValabilitate() const {
        return valabilitate;
    }

    void setValabilitate(int valabilitate_) {
        Abonament::valabilitate = valabilitate_;
    }

    explicit Abonament(std::string nume = "") : valabilitate(30), nume(std::move(nume)) {

        mijlocTransport = t.getMijlocTransport();
        pret = t.getPret() * 30;
    }

    const std::string &getNume() const {
        return nume;
    }

    void setNume(const std::string &nume_) {
        Abonament::nume = nume_;
    }

    virtual ~Abonament() = default;

    void print(std::ostream &os) const override{

        os << "Mijloc Transport: " << this->mijlocTransport << std::endl;
        os << "Pret: " << pret << std::endl;
        os << "Valabilitate: " << valabilitate << std::endl;
        os << "Nume: " << nume << std::endl << std::endl;

    }
};

// in cazul in care template-ul este folosit cu un bilet gol care este clasa abstracta, toate campurile trebuie initializate
// manual
template<>
class Abonament<Bilet>: public IOstream{
    std::string mijlocTransport;
    float pret;
    int valabilitate;
    std::string nume;


public:
    const std::string &getMijlocTransport() const {
        return mijlocTransport;
    }

    void setMijlocTransport(const std::string &mijlocTransport_) {
        Abonament::mijlocTransport = mijlocTransport_;
    }

    float getPret() const {
        return pret;
    }

    void setPret(float pret_) {
        Abonament::pret = pret_;
    }

    int getValabilitate() const {
        return valabilitate;
    }

    void setValabilitate(int valabilitate_) {
        Abonament::valabilitate = valabilitate_;
    }

    explicit Abonament(std::string nume = "") : valabilitate(30), nume(std::move(nume)) {
    }

    const std::string &getNume() const {
        return nume;
    }

    void setNume(const std::string &nume_) {
        Abonament::nume = nume_;
    }

    virtual ~Abonament() = default;

    void print(std::ostream &os) const override{

        os << "Mijloc Transport: " << this->mijlocTransport << std::endl;
        os << "Pret: " << pret << std::endl;
        os << "Valabilitate: " << valabilitate << std::endl;
        os << "Nume: " << nume << std::endl << std::endl;

    }
};

template<class T>
void reducere(T *a){
    a -> setPret(a -> getPret() / 2);
}

template<>
inline void reducere(Bilet *a){
    a->setPret(a->getPret() * 0.7);

}