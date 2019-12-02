#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <SFML/Graphics.hpp>
extern std::map<sf::String, sf::Keyboard::Key> sfKeys;


/****************************************************************************//**
*   @brief  Convert a sf::Keyboard::Key to a sf::String.
********************************************************************************/
sf::String keyToString(const int key);


/****************************************************************************//**
*   @brief  Convert a sf::String to sf::Keyboard::Key.
********************************************************************************/
sf::Keyboard::Key stringToKey(sf::String &temp);


/****************************************************************************//**
*   @brief  convert sf::String to integer.
********************************************************************************/
int toInt(const sf::String &text);


/****************************************************************************//**
*   @brief  Convert integer to sf::String.
********************************************************************************/
sf::String toString(const int &num);


/****************************************************************************//**
*   @brief  Convert float to sf::String.
********************************************************************************/
sf::String toString(const float &num);


/****************************************************************************//**
*   @brief  Convert sf::String to float.
********************************************************************************/
float toFloat(const sf::String &text);
#endif // FUNCTIONS_H
