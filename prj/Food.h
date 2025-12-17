/* Citation and Sources...
Final Project Milestone 5:
Module: Food
Filename: Food.h
Version 1.0
Author: Irfan Farid, StNo: 126930247, Email: ifarid2@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2025/11/25  Milestone 5 working submisison
-----------------------------------------------------------
All work is original work that references course textbook and lecture slides. Formated using Prettier v11.0.0
-----------------------------------------------------------*/
#ifndef SENECA_FOOD_H
#define SENECA_FOOD_H

#include "Billable.h"

namespace seneca
{
    class Food : public Billable
    {
        bool m_ordered;
        bool m_child;
        char *m_customize;

    public:
        Food();
        Food(const Food &original);
        Food &operator=(const Food &original);
        ~Food();

        std::ostream &print(std::ostream &ostr = std::cout) const;
        bool order();
        bool ordered() const;
        std::ifstream &read(std::ifstream &file);

        double price() const;
    };
}

#endif
