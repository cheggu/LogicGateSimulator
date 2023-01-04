#pragma once
#include <SFML/Graphics.hpp>
#include "includes.h"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(720, 480), "SFML works!");

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cout << "could not find font!" << std::endl;
    }

    sf::Text state;
    state.setFont(font);
    state.setCharacterSize(16);
    state.setFillColor(sf::Color::White);
    state.setPosition(0, 0);

    Button btn0;
    btn0.setPosition(300, 300);
    uiTools::addGate(btn0);
    Button btn1;
    btn1.setPosition(400, 300);
    uiTools::addGate(btn1);

    PrimativeGate andGate = PrimativeGate(PrimativeGateType::AND);
    uiTools::addGate(andGate);

    btn0.connect(andGate, A);
    btn1.connect(andGate, B);

    //btn0.press();
    //btn1.press();

    //btn0.printState();
    //btn1.printState();

    //andGate.emulate();

    //creating a new button
    UIButton newButton = UIButton(100, 100, 16, 100, 33);
    newButton.setClickFunc([]() { std::cout << "click function" << std::endl;  });
    uiTools::addButton(newButton);

    std::cout << "and gate state: " << andGate.getState() << std::endl;

    bool clickingAndHolding = false;

    while (window.isOpen())
    {
        window.clear(sf::Color(0xf2f2f2ff));

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    return 0;
                }
                if (event.key.code == sf::Keyboard::B) {
                    btn0.press();
                    btn0.printState();
                    btn1.printState();
                    andGate.emulate();
                    andGate.printState();
                    std::cout << "\n";
                }
            }
            if (event.type == sf::Event::MouseButtonPressed && event.key.code == sf::Mouse::Left) {
                for (UIButton& button : uiTools::getButtonList()) {
                    if (button.inBounds((sf::Vector2f)sf::Mouse::getPosition(window))) {
                        std::cout << "clicked, highlight" << std::endl;

                        button.highlight();

                        //highlight button but dont click

                        clickingAndHolding = true;
                    }
                }
                for (BaseGate* gate : uiTools::getGateList()) {
                    if (gate->inBounds((sf::Vector2f)sf::Mouse::getPosition(window))) {
                        std::cout << "clicked, highlight" << std::endl;

                        //button.highlight();

                        //highlight button but dont click

                        clickingAndHolding = true;
                    }
                }
                
            }

            if (event.type == sf::Event::MouseButtonReleased && event.key.code == sf::Mouse::Left) {
                if (clickingAndHolding) {
                    clickingAndHolding = false;
                    for (UIButton& button : uiTools::getButtonList()) {
                        if (button.inBounds((sf::Vector2f)sf::Mouse::getPosition(window))) {

                            //click button and unhighlight
                            button.click();
                            button.unhighlight();


                            std::cout << "released, click and unhighlight" << std::endl;
                        }
                        else {

                            button.unhighlight();
                            std::cout << "unhighlight" << std::endl;

                            //unhighlight button

                        }
                    }
                    for (BaseGate* gate : uiTools::getGateList()) {
                        if (gate->inBounds((sf::Vector2f)sf::Mouse::getPosition(window))) {

                            //click button and unhighlight
                            if (gate->getType() == "BUTTON") {
                                std::cout << "button" << std::endl;
                                Button* temp = (Button*)gate;
                                temp->click();
                                
                            }

                            
                            
                            //gate.unhighlight();


                            std::cout << "released, click and unhighlight" << std::endl;
                        }
                        else {

                            //gate.unhighlight();
                            std::cout << "unhighlight" << std::endl;

                            //unhighlight button

                        }
                    }
                }

            }
        }





        
        for (UIButton button : uiTools::getButtonList()) {
            window.draw(*button.getDrawable());
            window.draw(*button.getText());
        }

        for (BaseGate* gate : uiTools::getGateList()) {
            window.draw(*gate->getDrawable());
        }


        
        window.display();
    }

    return 0;
}