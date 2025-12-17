/* Citation and Sources...
Final Project Milestone 5:
Module: main
Filename: main.cpp
Version 1.0
Author: Irfan Farid, StNo: 126930247, Email: ifarid2@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2025/11/25  Milestone 5 working submisison
-----------------------------------------------------------
All work is original work that references course textbook and lecture slides. Formated using Prettier v11.0.0
-----------------------------------------------------------*/
/*#include <iostream>
#include "Menu.h"
#include "Ordering.h"

using namespace std;
using namespace seneca;

int main()
{
    Ordering ordering("drinks.csv", "foods.csv");

    if (!ordering)
    {
        cout << "Failed to open data files or the data files are corrupted!" << endl;
        return 1;
    }

    Menu mainMenu("Seneca Restaurant", "End Program");
    mainMenu << "Order" << "Print Bill" << "Start a New Bill" << "List Foods" << "List Drinks";

    Menu subMenu("Order Menu", "Back to main menu", 1);
    subMenu << "Food" << "Drink";

    Menu confirmMenu("You have bills that are not saved. Are you sue you want to exit?", "No", 0);
    confirmMenu << "Yes";

    bool done = false;
    while (!done)
    {
        size_t mainSelection = mainMenu.select();
        if (mainSelection == 1)
        {
            bool backToMain = false;
            while (!backToMain)
            {
                size_t orderSelection = subMenu.select();
                if (orderSelection == 1)
                {
                    ordering.orderFood();
                }
                else if (orderSelection == 2)
                {
                    ordering.orderDrink();
                }
                else if (orderSelection == 0)
                {
                    backToMain = true;
                }
            }
        }
        else if (mainSelection == 2)
        {
            ordering.printBill(cout);
        }
        else if (mainSelection == 3)
        {
            ordering.resetBill();
        }
        else if (mainSelection == 4)
        {
            ordering.listFoods();
        }
        else if (mainSelection == 5)
        {
            ordering.listDrinks();
        }
        else if (mainSelection == 0)
        {
            if (ordering.hasUnsavedBill())
            {
                size_t confirmSelection = confirmMenu.select();
                if (confirmSelection == 1)
                {
                    done = true;
                }
            }
            else
            {
                done = true;
            }
        }
    }
    return 0;
}*/