/* Citation and Sources...
Final Project Milestone 5:
Module: Billable
Filename: Billable.h
Version 1.0
Author: Irfan Farid, StNo: 126930247, Email: ifarid2@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2025/11/25  Milestone 5 working submisison
-----------------------------------------------------------
All work is original work that references course textbook and lecture slides. Formated using Prettier v11.0.0
-----------------------------------------------------------*/
#ifndef SENECA_BILLABLE_H
#define SENECA_BILLABLE_H
#include <iostream>
#include <fstream>

namespace seneca
{
    class Billable
    {
        char *m_name;
        double m_price;

    protected:
        void price(double value);
        void name(const char *name);

    public:
        Billable();
        Billable(const Billable &original);
        Billable &operator=(const Billable &original);

        virtual ~Billable();
        virtual double price() const;
        virtual std::ostream &print(std::ostream &ostr = std::cout) const = 0;
        virtual bool order() = 0;
        virtual bool ordered() const = 0;
        virtual std::ifstream &read(std::ifstream &file) = 0;

        operator const char *() const;
    };
    double operator+(double money, const Billable &B);
    double &operator+=(double &money, const Billable &B);
}

#endif
