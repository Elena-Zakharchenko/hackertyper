#include <cstring>
#include <iostream>
#include <fstream>
#include <unistd.h>
#include "DataStorage.cpp"
#include "DrawManager.h"
#include "EventManager.cpp"


int main() {

    EventMeneger EM;
    DataStorage DS;
    DS.text->filename = "hackcode.txt";
    DS.text->readFromFile();
    int i = 0;
    sf::Event event;

    DrawManager DM;

    DM.init();

    while((DS.window).isOpen())
    {
        std::string s = EM.s;
        while((DS.window).pollEvent(event))
        {
            EM.event = event;
            EM.EventCatcher();
        }

        DM.SetText(s);
        DM.draw();
        usleep(50000);
    }
    return 0;
}
