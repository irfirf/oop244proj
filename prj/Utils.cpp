/* Citation and Sources...
Final Project Milestone 5:
Module: Utils
Filename: Utils.cpp
Version 1.0
Author: Irfan Farid, StNo: 126930247, Email: ifarid2@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2025/11/25  Milestone 5 working submisison
-----------------------------------------------------------
I have refered the the following two links to help create the logic in getInt():
https://www.educative.io/answers/how-to-convert-a-string-to-an-int-in-cpp
https://www.youtube.com/watch?v=gf3Dqm-EOFQ
-----------------------------------------------------------
*/
#include <iostream>
#include <sstream>
#include <string>
#include "Utils.h"

using namespace std;
namespace seneca
{

    int getInt()
    {
        int value{};
        bool isValid = false;

        while (!isValid)
        {
            char buffer[100];
            cin.getline(buffer, 100);
            string input(buffer); // from youtube video

            if (input.length() == 0)
            {
                cout << "You must enter a value: ";
                continue;
            }
            stringstream ss(input); // from educative.io
            if (!(ss >> value))
            {
                cout << "Invalid integer: ";
                continue;
            }
            char leftover;
            if (ss >> leftover)
            {
                cout << "Only an integer please: ";
                continue;
            }
            isValid = true;
        }
        return value;
    }

    int getInt(int min, int max)
    {
        int value;
        do
        {
            value = getInt();
            if (value < min || value > max)
                cout << "Invalid value: [" << min << " <= value <= " << max << "], try again: ";
        } while (value < min || value > max);
        return value;
    }

    char *makeBillFileName(char *filename, size_t billNo)
    {
        char billFileName[21] = "bill_";
        size_t temp = billNo;
        int cnt = 5;
        int length;
        // Calculate the number of digits
        do
        {
            cnt++;
            temp /= 10;
        } while (temp > 0);
        length = cnt;
        // Convert each digit to character from the end
        while (billNo > 0)
        {
            billFileName[--cnt] = (billNo % 10) + '0';
            billNo /= 10;
        }
        // Handle the case when billNo is 0
        if (billFileName[cnt - 1] == '\0')
        {
            billFileName[--cnt] = '0';
        }
        // Attach .txt to the end of the file name
        for (int i = 0; ".txt"[i]; i++)
        {
            billFileName[length++] = ".txt"[i];
        }
        billFileName[length] = '\0';
        strcpy(filename, billFileName);
        return filename;
    }

}