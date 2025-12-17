/* Citation and Sources...
Final Project Milestone 5:
Module: Billable
Filename: Billable.cpp
Version 1.0
Author: Irfan Farid, StNo: 126930247, Email: ifarid2@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2025/11/25  Milestone 5 working submisison
-----------------------------------------------------------
All work is original work that references course textbook and lecture slides. Formated using Prettier v11.0.0
-----------------------------------------------------------*/
#include <cstring>
#include "Utils.h"
#include "Billable.h"

using namespace std;

namespace seneca
{
    Billable::Billable()
    {
        m_name = nullptr;
        m_price = 0.0;
    }
    Billable::Billable(const Billable &original)
    {
        m_name = nullptr;
        *this = original;
    }
    Billable &Billable::operator=(const Billable &original)
    {
        if (this != &original)
        {
            delete[] m_name;
            m_name = nullptr;
            if (original.m_name != nullptr)
            {
                m_name = new char[strlen(original.m_name) + 1];
                strcpy(m_name, original.m_name);
            }
            m_price = original.m_price;
        }
        return *this;
    }
    Billable::~Billable()
    {
        delete[] m_name;
    }
    void Billable::price(double value)
    {
        m_price = value;
    }
    void Billable::name(const char *name)
    {
        delete[] m_name;
        m_name = nullptr;
        if (name != nullptr && name[0] != '\0')
        {
            m_name = new char[strlen(name) + 1];
            strcpy(m_name, name);
        }
    }
    double Billable::price() const
    {
        return m_price;
    }
    Billable::operator const char *() const
    {
        return m_name;
    }
    double operator+(double money, const Billable &B)
    {
        return money + B.price();
    }
    double &operator+=(double &money, const Billable &B)
    {
        money = money + B.price();
        return money;
    }
}
