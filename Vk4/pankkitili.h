#pragma once
#include <string>

class Pankkitili {
protected:
    std::string omistaja;
    double saldo;

public:
    explicit Pankkitili(const std::string& owner);
    virtual ~Pankkitili() = default;

    virtual double getBalance() const;
    virtual bool deposit(double amount);
    virtual bool withdraw(double amount);
};
