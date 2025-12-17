/* Citation and Sources...
Final Project Milestone 5:
Module: Drink
Filename: Drink.cpp
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
#include "Drink.h"

using namespace std;

namespace seneca
{
    Drink::Drink() : Billable()
    {
        m_size = '\0';
    }

    ostream &Drink::print(ostream &ostr) const
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
            if (m_size == 'S')
            {
                ostr << "SML..";
            }
            else if (m_size == 'M')
            {
                ostr << "MID..";
            }
            else if (m_size == 'L')
            {
                ostr << "LRG..";
            }
            else if (m_size == 'X')
            {
                ostr << "XLR..";
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

        return ostr;
    }

    bool Drink::order()
    {
        cout << "         Drink Size Selection" << endl;
        cout << "          1- Small" << endl;
        cout << "          2- Medium" << endl;
        cout << "          3- Larg" << endl;
        cout << "          4- Extra Large" << endl;
        cout << "          0- Back" << endl;
        cout << "         > ";

        int selection = getInt(0, 4);

        bool out = false;
        if (selection == 1)
        {
            m_size = 'S';
            out = true;
        }
        else if (selection == 2)
        {
            m_size = 'M';
            out = true;
        }
        else if (selection == 3)
        {
            m_size = 'L';
            out = true;
        }
        else if (selection == 4)
        {
            m_size = 'X';
            out = true;
        }
        else
        {
            m_size = '\0';
        }
        return out;
    }

    bool Drink::ordered() const
    {
        return m_size != '\0';
    }

    ifstream &Drink::read(ifstream &file)
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
            m_size = '\0';
        }

        return file;
    }

    double Drink::price() const
    {
        double largePrice = Billable::price();
        double out = largePrice;

        if (!ordered() || m_size == 'L')
        {
            out = largePrice;
        }
        else if (m_size == 'S')
        {
            out = largePrice / 2.0;
        }
        else if (m_size == 'M')
        {
            out = largePrice * 3.0 / 4.0;
        }
        else if (m_size == 'X')
        {
            out = largePrice * 1.5;
        }

        return out;
    }
}
