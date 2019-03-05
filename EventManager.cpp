//#include "EventManager.h"
#include "DataStorage.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


struct EventMeneger
{
    DataStorage* DS;
    std::string text;
    std::string s;
    int i = 0;
    sf::Event event;

    void KeyPressed()
    {
        for (int k = 1; k < 4; k++)
        {
            s = s + text[i];
            i++;
        }
    }

    void EventCatcher()
    {
        while((DS->window).pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed){
                KeyPressed();
                };
            if (event.type == sf::Event::Closed)
            {
                (DS->window).close();
            };
        };
    }
};
