#pragma once
#include "includes.h"
#include "ui_element_type.h"
#include "SFML/Graphics.hpp"

class ui_element {
public:
	ui_element_type element_type;
	sf::RectangleShape dimensions;
	
	ui_element(ui_element_type type, int pos_x, int pos_y, int width, int height) {
		element_type = type;
		dimensions.setPosition({ pos_x, pos_y } );
		dimensions.setSize( {width, height} );
	}

};

namespace ui_elements {

	std::vector<ui_element> ui_elements_list;

	void addButton(sf::Vector2f pos, sf::Vector2f size) {
		ui_element btn = ui_element(BUTTON, 0, 0, 0, 0);



	}
	void addGate();
	void addText();
	void addTextBox();

}