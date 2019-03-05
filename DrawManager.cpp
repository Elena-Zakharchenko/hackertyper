#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "DrawManager.h"


void DrawManager::draw() {
    DS->window.clear();
    DS->window.draw(this->DS->texture->sprite);
    DS->window.draw(this->DS->text->s);
    DS->window.display();
}

void DrawManager::destroy(){
    DS->window.close();
}

DrawManager::~DrawManager(){
    free(this->DS->window);
    free(this->DS->texture->sprite);
    free(this->DS->text->s);
}

void DrawManager::SetText(std::string s){

    if(this->DS->text->s != NULL) {
        free(this->DS->text->s);
    }
    this->DS->text->s = new sf::Text(s, this->DS->text->font, 15);
    sf::FloatRect textBounds = this->DS->text->s->getGlobalBounds();
    if(textBounds.height > 600) {
        this->DS->text->s->setPosition(0, 600 - textBounds.height);
    }
    DS->text->s->setFillColor(sf::Color::Green);
}
