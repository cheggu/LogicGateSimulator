#pragma once
#include "ui_base.h"

class UIButton : public UIBaseElement {
private:
	ui_element_type type = UIBUTTON;

	sf::RectangleShape drawable;
	
	bool enabled = true;

	void(*onClicked)();

	sf::Font font;
	sf::Text text;

public:

	//after instantiating a button you NEED to add a event function using setClickFunc()
	UIButton(float pos_x, float pos_y, float text_size, float width, float height) {
		if (!font.loadFromFile("arial.ttf")) {

		}

		drawable.setPosition(pos_x, pos_y);
		drawable.setSize({ width, height });
		drawable.setFillColor(sf::Color(0xc3c3c3ff));

		text.setFont(font);
		text.setCharacterSize(text_size);
		text.setString("Button");
		text.setFillColor(sf::Color::Black);

		sf::FloatRect textRect = text.getLocalBounds();
		text.setOrigin(textRect.left + textRect.width / 2.0f,
			textRect.top + textRect.height / 2.0f);
		text.setPosition(drawable.getPosition().x + drawable.getSize().x / 2.0f,
			drawable.getPosition().y + drawable.getSize().y / 2.0f);
	}


	//setClickFunc([]() {std::cout << "bar" << std::endl; });
	//onClicked = []() { std::cout << "fo" << std::endl; };
	/// <summary>
	/// Set click event func for the button.
	/// Usage: button.setClickFunc([]() { std::cout << "foobar" << std::endl; }); 
	/// </summary>
	/// <param name="newClickFunc"> new void func to set as button click func </param>
	void setClickFunc(void(*newClickFunc)()) {




		onClicked = newClickFunc;
	}

	void toggle() {
		enabled = !enabled;
	}

	void ui_setFillColor(sf::Color color) {
		drawable.setFillColor(color);
	}

	void ui_setBorderColor(sf::Color color) {
		drawable.setOutlineColor(color);
	}

	void ui_setBorderThickness(float thickness) {
		drawable.setOutlineThickness(thickness);
	}

	void ui_setTextSize(float size) {
		text.setCharacterSize(size);
	}

	void ui_setTextColor(sf::Color color) {
		text.setFillColor(color);
	}

	void highlight() {

	}

	void unhighlight() {

	}

	void click() {
		onClicked();
	}

	bool inBounds(sf::Vector2f pointer) {
		if (drawable.getGlobalBounds().contains(pointer)) {
			return true;
		}
		return false;
	}

	sf::RectangleShape* getDrawable() {
		return &drawable;
	}

	sf::Text* getText() {
		return &text;
	}

};