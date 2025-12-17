/* Citation and Sources...
Final Project Milestone 5:
Module: Utils
Filename: Utils.h
Version 1.0
Author: Irfan Farid, StNo: 126930247, Email: ifarid2@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2025/11/25  Milestone 5 working submisison
-----------------------------------------------------------
All work is original work that references course textbook and lecture slides. Formated using Prettier v11.0.0
-----------------------------------------------------------*/
#ifndef UTILS_H
#define UTILS_H

namespace seneca
{

    int getInt();
    int getInt(int min, int max);
    char *makeBillFileName(char *filename, size_t billNo);

}

#endif
