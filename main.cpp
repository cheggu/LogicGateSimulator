#pragma once
#include <SFML/Graphics.hpp>
#include "includes.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(720, 480), "SFML works!");

    Button btn0;
    Button btn1;

    PrimativeGate andGate = PrimativeGate(PrimativeGateType::AND);

    std::cout << "btn0 name: " << btn0.getName() << std::endl;
    std::cout << "btn1 name: " << btn1.getName() << std::endl;

    btn0.connect(andGate, A);
    btn1.connect(andGate, B);
    
    btn0.printAllChildren();
    andGate.printAllParents();

    btn0.press();
    btn1.press();

  

    std::cout << "btn0 state: " << btn0.getState() << "\nbtn1 state: " << btn1.getState() << std::endl;

    andGate.emulate();

    

    std::cout << "and gate state: " << andGate.getState() << std::endl;
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    return 0;
                }

            }
        }

        window.clear();
        window.display();
    }

    return 0;
}