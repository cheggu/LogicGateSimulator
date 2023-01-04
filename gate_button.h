#pragma once
#include <vector>
#include "gate_primatives.h"
#include "gate_base.h"

class Button : public BaseGate {
public:

	Button() {
		type = BUTTON;

		drawable.setFillColor(sf::Color::Red);
		drawable.setOutlineThickness(3);
		drawable.setOutlineColor(sf::Color::Black);
		drawable.setRadius(20);
		

	}

	void press() {
		if (state == OFF) {
			state = ON;
		}
		else {
			state = OFF;
		}
	}

	
	void click() override {
		press();
		if (state == ON) {
			drawable.setFillColor(sf::Color::Green);
		}
		else {
			drawable.setFillColor(sf::Color::Red);
		}
	}



};