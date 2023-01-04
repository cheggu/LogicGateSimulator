#pragma once
#include "includes.h"
#include "ui_element_type.h"
#include "SFML/Graphics.hpp"

class UIBaseElement {
public:
	ui_element_type element_type;
	sf::RectangleShape dimensions;

};

