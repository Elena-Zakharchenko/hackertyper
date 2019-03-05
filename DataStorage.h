#ifndef DATASTORAGE_H
#define DATASTORAGE_H


#include <iostream>
#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
//#include "DataStorage.h"

struct Object
{
    int x;
    int y;
};

struct Texture : public Object
{
    sf::Texture texture;
    sf::Sprite sprite = sf::Sprite(texture);
};

struct Text : public Object
{
    std::string filename;
    std::string s;
    sf::Font font;
    void readFromFile();

};

struct DataStorage
{
    Object* object;
    Texture* texture;
    Text* text;
    sf::RenderWindow window;
};



#endif // DATASTORAGE_H
