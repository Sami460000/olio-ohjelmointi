#pragma once
#include "Pankkitili.h"

class Luottotili : public Pankkitili {
protected:
    double luottoRaja;

public:
    Luottotili(const std::string& owner, double limit);

    double getBalance() const override;
    bool deposit(double amount) override;
    bool withdraw(double amount) override;
};
