#pragma once
#include <vector>
#include "gate_primative_inputs.h"
#include "gate_state.h"
#include "op_primatives.h"
#include "utils_math.h"
#include "SFML/Graphics.hpp"

class BaseGate {
protected:
	sf::CircleShape drawable;

	std::vector<std::reference_wrapper<BaseGate>> children = {};

	std::vector<std::reference_wrapper<BaseGate>> a_parents = {};
	std::vector<std::reference_wrapper<BaseGate>> b_parents = {};

	GateState a, b;

	std::string name = genUID();

	GateState(*operation)(bool, bool);
	bool nop = false;
	bool not_op = false;

	PrimativeGateType type;

	GateState state = OFF;

	GateState calc_state_from_parents(InputType input) {
		if (input == InputType::A) {
			for (auto parent : a_parents) {
				//std::cout << parent.get().state << std::endl;
				if (parent.get().state == ON) {
					return ON;
				}
			}
			return OFF;
		}
		else {
			for (auto parent : b_parents) {
				//std::cout << parent.get().state << std::endl;
				if (parent.get().state == ON) {
					return ON;
				}
			}
			return OFF;
		}
		
	}

public:
	GateState getState() {
		return state;
	}

	std::string getName() {
		return name;
	}

	std::string getType() {
		switch (type) {
		case 0:
			return "AND";
		case 1:
			return "OR";
		case 2:
			return "NOT";
		case 3:
			return "NAND";
		case 4:
			return "NOR";
		case 5:
			return "XOR";
		case 6:
			return "XNOR";
		case 7:
			return "NOP";
		case 8:
			return "BUTTON";
		default:
			return "?";

		}
	}

	void printState() {
		std::cout << "-- STATE STATUS OF GATE '" << getName() << "' (type " << getType() << ") -- " << getState() << std::endl;
	}

	void printAllChildren() {
		for (auto child : children) {
			std::cout << "child: " + child.get().name << std::endl;
		}
	}

	void printAllParents() {
		for (auto parent : a_parents) {
			std::cout << "a_parent: " + parent.get().name << std::endl;
		}
		for (auto parent : b_parents) {
			std::cout << "b_parent: " + parent.get().name << std::endl;
		}
	}

	/// <summary>
	/// Connects two gates together. This gate will be added as a parent for 'other' and other will be added as a child for this gate.
	/// </summary>
	/// <param name="other">Gate to add as a child</param>
	void connect(BaseGate &other, InputType otherInput) {
		children.push_back(other);

		if (otherInput == A) {
			other.a_parents.push_back(*this);
		}
		else {
			other.b_parents.push_back(*this);
		}
	}

	bool inBounds(sf::Vector2f pointer) {
		if (drawable.getGlobalBounds().contains(pointer)) {
			return true;
		}
		return false;
	}

	void setPosition(float x, float y) {
		drawable.setPosition(x, y);
	}

	sf::CircleShape* getDrawable() {
		return &drawable;
	}

	virtual void click() {
		std::cout << "foopbar" << std::endl;
	};

};