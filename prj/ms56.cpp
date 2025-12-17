/***********************************************************************
// OOP244 Project, milestone 56 : tester program
//
// File  ms56.cpp
// Version 1.0
// Author Fardad
// Description
//
// Revision History
// -----------------------------------------------------------
// Name            Date            Reason
// Irfan Farid      2025/11/25    changed line 33: "proofing" to "proofint" to match expected output
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include <iostream>
#include "Menu.h"
#include "Ordering.h"
using namespace std;
using namespace seneca;
int main()
{
   cout << "Testing Invalid Ordering if bad data is in data file!" << endl;
   Ordering badord("drink.csv", "badfood.csv");
   if (badord)
   {
      cout << "The ordering should have been invalid" << endl;
   }
   else
   {
      cout << "Passed!" << endl;
   }
   Ordering ord("drinks.csv", "foods.csv");
   cout << "Testing fool proofint..............................." << endl; // this line was modified from the original
   ord.orderDrink();
   return 0;
}
