/* Citation and Sources...
Final Project Milestone 5:
Module: Ordering
Filename: Ordering.h
Version 1.0
Author: Irfan Farid, StNo: 126930247, Email: ifarid2@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2025/11/25  Milestone 5 working submisison
-----------------------------------------------------------
All work is original work that references course textbook and lecture slides. Formated using Prettier v11.0.0
-----------------------------------------------------------*/

#ifndef SENECA_ORDERING_H
#define SENECA_ORDERING_H
#include <iostream>
#include "Billable.h"
#include "Food.h"
#include "Drink.h"
#include "Constants.h"

namespace seneca
{
    class Ordering
    {
        unsigned int m_foodCounter;
        unsigned int m_drinkCounter;
        unsigned int m_billableCounter;
        unsigned int m_billNumber;

        Food *m_foods;
        Drink *m_drinks;
        Billable *m_billItems[MaximumNumberOfBillItems];

        void printBillTitle(std::ostream &ostr) const;
        void printTotals(std::ostream &ostr, double total) const;
        size_t countRecords(const char *file) const;

    public:
        Ordering(const char *drinksFile, const char *foodsFile);
        Ordering(const Ordering &original) = delete;
        Ordering &operator=(const Ordering &original) = delete;
        ~Ordering();

        operator bool() const;
        int noOfBillItems() const;
        bool hasUnsavedBill() const;

        void listFoods() const;
        void listDrinks() const;
        void orderFood();
        void orderDrink();
        void printBill(std::ostream &ostr) const;
        void resetBill();
    };
}

#endif