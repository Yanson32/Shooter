#include "Editor/Functions.h"
#include <map>
#include <sstream>

/****************************************************************************//**
*   @brief  Convert a sf::Keyboard::Key to a sf::String.
********************************************************************************/
sf::String keyToString(const int key)
{
    if(key >= sf::Keyboard::A && key <= sf::Keyboard::Z)
    {
        char temp = 'A' + key;
        return temp;
    }
    else if(key == sf::Keyboard::Space)
    {
        return "Space";
    }
    else if(key == sf::Keyboard::Left)
    {
        return "Left";
    }
    else if(key == sf::Keyboard::Right)
    {
        return "Right";
    }
    else if(key == sf::Keyboard::Up)
    {
        return "Up";
    }
    else if(key == sf::Keyboard::Down)
    {
        return "Down";
    }
    else if(key == sf::Keyboard::Escape)
    {
        return "Escape";
    }
    return "";
}


/****************************************************************************//**
*   @brief  Convert a sf::String to sf::Keyboard::Key.
********************************************************************************/
sf::Keyboard::Key stringToKey(sf::String &temp)
{
    if(temp.getSize() == 1)
    {
        temp[0] = toupper(temp[0]);
    }
    else if(temp.getSize() > 1)
    {
        //Set the string to lowercase letters
        for(std::size_t i = 0; i < temp.getSize(); ++i)
        {
            temp[i] = tolower(temp[i]);
        }

        //set the first letter to uppercase
        temp[0] = toupper(temp[0]);
    }

    return sfKeys[temp];
}


/****************************************************************************//**
*   @brief  convert sf::String to integer.
********************************************************************************/
int toInt(const sf::String &text)
{
    int temp;
    std::stringstream ss;
    ss << text.toAnsiString();
    ss >> temp;
    return temp;
}


/****************************************************************************//**
*   @brief  Convert integer to sf::String.
********************************************************************************/
sf::String toString(const int &num)
{
    std::stringstream ss;
    ss << num;
    return ss.str();
}


/****************************************************************************//**
*   @brief  Convert sf::String to float.
********************************************************************************/
float toFloat(const sf::String &text)
{
    float temp;
    std::stringstream ss;
    ss << text.toAnsiString();
    ss >> temp;
    return temp;
}




std::map<sf::String, sf::Keyboard::Key> sfKeys =    {   {"A",       sf::Keyboard::A},
                                                        {"B",       sf::Keyboard::B},
                                                        {"C",       sf::Keyboard::C},
                                                        {"D",       sf::Keyboard::D},
                                                        {"E",       sf::Keyboard::E},
                                                        {"F",       sf::Keyboard::F},
                                                        {"G",       sf::Keyboard::G},
                                                        {"H",       sf::Keyboard::H},
                                                        {"I",       sf::Keyboard::I},
                                                        {"J",       sf::Keyboard::J},
                                                        {"K",       sf::Keyboard::L},
                                                        {"M",       sf::Keyboard::M},
                                                        {"N",       sf::Keyboard::N},
                                                        {"O",       sf::Keyboard::O},
                                                        {"P",       sf::Keyboard::P},
                                                        {"Q",       sf::Keyboard::Q},
                                                        {"R",       sf::Keyboard::R},
                                                        {"S",       sf::Keyboard::S},
                                                        {"T",       sf::Keyboard::T},
                                                        {"U",       sf::Keyboard::U},
                                                        {"V",       sf::Keyboard::V},
                                                        {"W",       sf::Keyboard::W},
                                                        {"X",       sf::Keyboard::X},
                                                        {"Y",       sf::Keyboard::Y},
                                                        {"Z",       sf::Keyboard::Z},
                                                        {"Space",   sf::Keyboard::Space},
                                                        {"Left",    sf::Keyboard::Left},
                                                        {"Right",   sf::Keyboard::Right},
                                                        {"Up",      sf::Keyboard::Up},
                                                        {"Down",    sf::Keyboard::Down},
                                                        {"Escape",  sf::Keyboard::Escape}
                                                    };

