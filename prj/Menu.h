/* Citation and Sources...
Final Project Milestone 5:
Module: Menu
Filename: Menu.h
Version 1.0
Author: Irfan Farid, StNo: 126930247, Email: ifarid2@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2025/11/25  Milestone 5 working submisison
-----------------------------------------------------------
All work is original work that references course textbook and lecture slides. Formated using Prettier v11.0.0
-----------------------------------------------------------*/

#ifndef MENU_H
#define MENU_H
#include <iostream>
#include "Utils.h"
#include "Constants.h"

namespace seneca
{
    class Menu;

    class MenuItem
    {
        char *m_menuContent;
        unsigned int m_countIndent;
        unsigned int m_sizeIndent;
        int m_rowNum;

        void setEmptyState();

        MenuItem(const char *menuContent, unsigned int countIndent, unsigned int sizeIndent, int rowNum);
        MenuItem(const MenuItem &original) = delete;
        MenuItem &operator=(const MenuItem &original) = delete;
        ~MenuItem();
        operator bool() const;
        std::ostream &display() const;
        std::ostream &display(std::ostream &ostr) const;
        friend class Menu;
    };

    class Menu
    {
        unsigned int m_countIndentMenu;
        unsigned int m_sizeIndentMenu;
        unsigned int m_numOfMenuItems;

        MenuItem m_title;
        MenuItem m_exitOption;
        MenuItem m_selectionPrompt;

        MenuItem *m_menuItem[MaximumNumberOfMenuItems]{};

    public:
        Menu(const char *title, const char *exitOption = "Exit", unsigned int countIndentMenu = 0, unsigned int sizeIndentMenu = 3);
        Menu(const Menu &original) = delete;
        Menu &operator=(const Menu &original) = delete;
        ~Menu();
        Menu &operator<<(const char *menuContent);
        size_t select() const;
    };
    size_t operator<<(std::ostream &ostr, const Menu &m);
};
#endif