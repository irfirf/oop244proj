/* Citation and Sources...
Final Project Milestone 5:
Module: Ordering
Filename: Ordering.cpp
Version 1.0
Author: Irfan Farid, StNo: 126930247, Email: ifarid2@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2025/11/25  Milestone 5 working submisison
-----------------------------------------------------------
https://www.w3schools.com/cpp/ref_fstream_ofstream.asp used in resetBill() to find out how to use ofstream
All other work is original work that references course textbook and lecture slides. Formated using Prettier v11.0.0
-----------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <cstring>
#include "Ordering.h"
#include "Menu.h"
#include "Utils.h"
#include "Constants.h"

using namespace std;

namespace seneca
{
    void Ordering::printBillTitle(ostream &ostr) const
    {
        ostr << "Bill # ";
        ostr.width(3);
        ostr.setf(ios::right);
        ostr.fill('0');
        ostr << m_billNumber;
        ostr.fill(' ');
        ostr.unsetf(ios::right);
        ostr << " =============================" << endl;
    }

    void Ordering::printTotals(ostream &ostr, double total) const
    {
        ostr << "                     Total:";
        ostr.width(13);
        ostr.setf(ios::right);
        ostr.setf(ios::fixed);
        ostr.precision(2);
        ostr << total << endl;
        ostr << "                     Tax:";
        ostr.width(15);
        ostr << (total * Tax) << endl;
        ostr << "                     Total+Tax:";
        ostr.width(9);
        ostr << (total + (total * Tax)) << endl;
        ostr << "========================================" << endl;
        ostr.unsetf(ios::right);
        ostr.unsetf(ios::fixed);
    }

    size_t Ordering::countRecords(const char *file) const
    {
        size_t newlineCounter = 0;
        ifstream input(file);
        char buffer;
        while (input)
        {
            input.get(buffer);
            if (input && buffer == '\n')
            {
                newlineCounter++;
            }
        }
        return newlineCounter;
    }

    Ordering::Ordering(const char *drinksFile, const char *foodsFile)
    {
        m_foodCounter = 0;
        m_drinkCounter = 0;
        m_billableCounter = 0;
        m_billNumber = 1;
        m_foods = nullptr;
        m_drinks = nullptr;
        for (unsigned int i = 0; i < MaximumNumberOfBillItems; i++)
        {
            m_billItems[i] = nullptr;
        }

        size_t numberOfFoods = countRecords(foodsFile);
        size_t numberOfDrinks = countRecords(drinksFile);

        if (numberOfFoods > 0 && numberOfDrinks > 0)
        {
            m_foods = new Food[numberOfFoods];
            m_drinks = new Drink[numberOfDrinks];

            ifstream drinkFile(drinksFile);
            ifstream foodFile(foodsFile);
            if (drinkFile)
            {
                while (m_drinkCounter < numberOfDrinks && m_drinks[m_drinkCounter].read(drinkFile))
                {
                    m_drinkCounter++;
                }
                drinkFile.close();

                while (m_foodCounter < numberOfFoods && m_foods[m_foodCounter].read(foodFile))
                {
                    m_foodCounter++;
                }
                foodFile.close();
            }

            if (m_foodCounter != numberOfFoods || m_drinkCounter != numberOfDrinks)
            {
                delete[] m_foods;
                delete[] m_drinks;
                m_foods = nullptr;
                m_drinks = nullptr;
                m_foodCounter = 0;
                m_drinkCounter = 0;
            }
        }
    }

    Ordering::~Ordering()
    {
        delete[] m_foods;
        delete[] m_drinks;
        for (unsigned int i = 0; i < m_billableCounter; i++)
        {
            delete m_billItems[i];
        }
    }

    Ordering::operator bool() const
    {
        return (m_foods != nullptr && m_drinks != nullptr);
    }

    int Ordering::noOfBillItems() const
    {
        return m_billableCounter;
    }

    bool Ordering::hasUnsavedBill() const
    {
        return m_billableCounter > 0;
    }

    void Ordering::listFoods() const
    {
        cout << "List Of Avaiable Meals" << endl;
        cout << "========================================" << endl;
        for (unsigned int i = 0; i < m_foodCounter; i++)
        {
            m_foods[i].print(cout);
            cout << endl;
        }
        cout << "========================================" << endl;
    }

    void Ordering::listDrinks() const
    {
        cout << "List Of Avaiable Drinks" << endl;
        cout << "========================================" << endl;
        for (unsigned int i = 0; i < m_drinkCounter; i++)
        {
            m_drinks[i].print(cout);
            cout << endl;
        }
        cout << "========================================" << endl;
    }

    void Ordering::orderFood()
    {
        Menu foodMenu("Food Menu", "Back to Order", 2);
        for (unsigned int i = 0; i < m_foodCounter; i++)
        {
            foodMenu << (const char *)m_foods[i];
        }

        size_t selection = foodMenu.select();
        if (selection != 0)
        {
            m_billItems[m_billableCounter] = new Food(m_foods[selection - 1]);

            if (m_billItems[m_billableCounter]->order())
            {
                m_billableCounter++;
            }
            else
            {
                delete m_billItems[m_billableCounter];
                m_billItems[m_billableCounter] = nullptr;
            }
        }
    }

    void Ordering::orderDrink()
    {
        Menu drinkMenu("Drink Menu", "Back to Order", 2);
        for (unsigned int i = 0; i < m_drinkCounter; i++)
        {
            drinkMenu << (const char *)m_drinks[i];
        }

        size_t selection = drinkMenu.select();
        if (selection != 0)
        {
            m_billItems[m_billableCounter] = new Drink(m_drinks[selection - 1]);

            if (m_billItems[m_billableCounter]->order())
            {
                m_billableCounter++;
            }
            else
            {
                delete m_billItems[m_billableCounter];
                m_billItems[m_billableCounter] = nullptr;
            }
        }
    }

    void Ordering::printBill(ostream &ostr) const
    {
        double total = 0.0;
        printBillTitle(ostr);
        for (unsigned int i = 0; i < m_billableCounter; i++)
        {
            m_billItems[i]->print(ostr) << endl;
            total += m_billItems[i]->price();
        }
        printTotals(ostr, total);
    }

    void Ordering::resetBill()
    {
        char filename[100];
        makeBillFileName(filename, m_billNumber);
        ofstream billFile(filename); // w3schools
        printBill(billFile);
        cout << "Saved bill number " << m_billNumber << endl;
        cout << "Starting bill number " << (m_billNumber + 1) << endl;

        for (unsigned int i = 0; i < m_billableCounter; i++)
        {
            delete m_billItems[i];
            m_billItems[i] = nullptr;
        }
        m_billNumber++;
        m_billableCounter = 0;
    }
}
