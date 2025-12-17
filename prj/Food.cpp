/* Citation and Sources...
Final Project Milestone 5:
Module: Food
Filename: Food.cpp
Version 1.0
Author: Irfan Farid, StNo: 126930247, Email: ifarid2@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2025/11/25  Milestone 5 working submisison
-----------------------------------------------------------
All work is original work that references course textbook and lecture slides. Formated using Prettier v11.0.0
-----------------------------------------------------------*/
#include <iostream>
#include <cstring>
#include "Utils.h"
#include "Food.h"

using namespace std;

namespace seneca
{
    Food::Food() : Billable()
    {
        m_ordered = false;
        m_child = false;
        m_customize = nullptr;
    }

    Food::Food(const Food &original) : Billable(original)
    {
        m_customize = nullptr;
        *this = original;
    }

    Food &Food::operator=(const Food &original)
    {
        if (this != &original)
        {
            Billable::operator=(original);
            delete[] m_customize;
            m_customize = nullptr;
            m_ordered = original.m_ordered;
            m_child = original.m_child;

            if (original.m_customize != nullptr)
            {
                m_customize = new char[strlen(original.m_customize) + 1];
                strcpy(m_customize, original.m_customize);
            }
        }
        return *this;
    }

    Food::~Food()
    {
        delete[] m_customize;
    }

    ostream &Food::print(ostream &ostr) const
    {
        const char *itemName = (const char *)(*this);
        if (itemName != nullptr)
        {
            int nameLength = strlen(itemName);
            int displayLength;
            if (nameLength > 25)
            {
                displayLength = 25;
            }
            else
            {
                displayLength = nameLength;
            }
            ostr.setf(ios::left);
            for (int i = 0; i < displayLength; i++)
            {
                ostr << itemName[i];
            }
            for (int i = displayLength; i < 28; i++)
            {
                ostr << '.';
            }
        }
        else
        {
            for (int i = 0; i < 28; i++)
            {
                ostr << '.';
            }
        }

        if (ordered())
        {
            if (m_child)
            {
                ostr << "Child";
            }
            else
            {
                ostr << "Adult";
            }
        }
        else
        {
            ostr << ".....";
        }
        ostr.setf(ios::right);
        ostr.setf(ios::fixed);
        ostr.precision(2);
        ostr.width(7);
        ostr << price();
        ostr.unsetf(ios::right);
        ostr.unsetf(ios::fixed);

        if (&ostr == &cout && m_customize != nullptr)
        {
            ostr << " >> ";
            int customLength = strlen(m_customize);
            int displayLength;
            if (customLength > 30)
            {
                displayLength = 30;
            }
            else
            {
                displayLength = customLength;
            }
            for (int i = 0; i < displayLength; i++)
            {
                ostr << m_customize[i];
            }
        }
        return ostr;
    }

    bool Food::order()
    {
        cout << "         Food Size Selection" << endl;
        cout << "          1- Adult" << endl;
        cout << "          2- Child" << endl;
        cout << "          0- Back" << endl;
        cout << "         > ";

        int selection = getInt(0, 2);

        if (selection == 0)
        {
            m_ordered = false;
            delete[] m_customize;
            m_customize = nullptr;
            return false;
        }
        m_ordered = true;
        if (selection == 1)
        {
            m_child = false;
        }
        else if (selection == 2)
        {
            m_child = true;
        }

        cout << "Special instructions" << endl;
        cout << "> ";

        char buffer[1000];
        cin.getline(buffer, 1000);

        delete[] m_customize;
        m_customize = nullptr;

        if (buffer[0] != '\0')
        {
            m_customize = new char[strlen(buffer) + 1];
            strcpy(m_customize, buffer);
        }
        return true;
    }

    bool Food::ordered() const
    {
        return m_ordered;
    }

    ifstream &Food::read(ifstream &file)
    {
        char nameBuffer[256];
        double priceBuffer;

        file.getline(nameBuffer, 256, ',');
        file >> priceBuffer;
        file.ignore(1000, '\n');

        if (file)
        {
            name(nameBuffer);
            Billable::price(priceBuffer);
            m_child = false;
            m_ordered = false;
            delete[] m_customize;
            m_customize = nullptr;
        }
        return file;
    }

    double Food::price() const
    {
        double adultPrice = Billable::price();
        double out = adultPrice;

        if (ordered() && m_child)
        {
            out = adultPrice / 2.0;
        }
        else
        {
            out = adultPrice;
        }
        return out;
    }
}
