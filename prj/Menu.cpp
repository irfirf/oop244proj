/* Citation and Sources...
Final Project Milestone 5:
Module: Menu
Filename: Menu.cpp
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
#include "Menu.h"

using namespace std;
namespace seneca
{
    void MenuItem::setEmptyState()
    {
        delete[] m_menuContent;
        m_menuContent = nullptr;
        m_countIndent = 0;
        m_sizeIndent = 0;
        m_rowNum = 0;
    }

    MenuItem::MenuItem(const char *menuContent, unsigned countIndent, unsigned sizeIndent, int rowNum)
    {
        m_menuContent = nullptr;
        m_countIndent = 0;
        m_sizeIndent = 0;
        m_rowNum = 0;

        if (menuContent && countIndent <= 4 && sizeIndent <= 4 && rowNum <= (int)MaximumNumberOfMenuItems)
        {

            m_menuContent = new char[strlen(menuContent) + 1];
            strcpy(m_menuContent, menuContent);
            m_countIndent = countIndent;
            m_sizeIndent = sizeIndent;
            m_rowNum = rowNum;
        }
    }

    MenuItem::~MenuItem()
    {
        delete[] m_menuContent;
    }

    MenuItem::operator bool() const
    {
        return (m_menuContent != nullptr);
    }

    std::ostream &MenuItem::display() const
    {
        return display(std::cout);
    }

    std::ostream &MenuItem::display(std::ostream &ostr) const
    {
        if (m_menuContent && m_menuContent[0] != '\0')
        {
            unsigned int totalIndent = m_countIndent * m_sizeIndent;
            for (unsigned int i = 0; i < totalIndent; i++)
                ostr << ' ';

            if (m_rowNum >= 0)
            {
                ostr.width(2);
                ostr.setf(ios::right);
                ostr << m_rowNum << "- ";
                ostr.unsetf(ios::right);
            }
            const char *text = m_menuContent;
            while (*text == ' ' || *text == '\t' || *text == '\v' || *text == '\r' || *text == '\f' || *text == '\n')
            {
                ++text;
            }

            ostr << text;
        }
        else
        {
            ostr << "??????????";
        }

        return ostr;
    }

    // ms2--------------------------------------------------------------------------------------------------
    Menu::Menu(const char *title, const char *exitOption, unsigned int countIndentMenu, unsigned int sizeIndentMenu)
        : m_countIndentMenu(countIndentMenu),
          m_sizeIndentMenu(sizeIndentMenu),
          m_numOfMenuItems(0),
          m_title(title, countIndentMenu, sizeIndentMenu, -1),
          m_exitOption(exitOption, countIndentMenu, sizeIndentMenu, 0),
          m_selectionPrompt("> ", countIndentMenu, sizeIndentMenu, -1)
    {
        for (unsigned int i = 0; i < MaximumNumberOfMenuItems; i++)
        {
            m_menuItem[i] = nullptr;
        }
    }

    Menu::~Menu()
    {
        for (unsigned int i = 0; i < MaximumNumberOfMenuItems; i++)
        {
            if (m_menuItem[i] != nullptr)
            {
                delete m_menuItem[i];
                m_menuItem[i] = nullptr;
            }
        }
    }

    Menu &Menu::operator<<(const char *menuContent)
    {
        if (m_numOfMenuItems < MaximumNumberOfMenuItems)
        {
            m_menuItem[m_numOfMenuItems] = new MenuItem(menuContent, m_countIndentMenu, m_sizeIndentMenu, m_numOfMenuItems + 1);
            m_numOfMenuItems++;
        }
        return *this;
    }

    size_t Menu::select() const
    {
        if (m_title)
        {
            m_title.display(cout) << endl;
        }
        for (unsigned int i = 0; i < m_numOfMenuItems; ++i)
        {
            if (m_menuItem[i])
            {
                m_menuItem[i]->display(cout) << endl;
            }
        }
        m_exitOption.display(cout) << endl;
        m_selectionPrompt.display(cout);
        int selection = getInt(0, m_numOfMenuItems);
        return selection;
    }

    size_t operator<<(std::ostream &ostr, const Menu &m)
    {
        if (&ostr == &cout)
        {
            return m.select();
        }
        return 0;
    }

};