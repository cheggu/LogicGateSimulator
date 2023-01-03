#pragma once
#include <vector>
#include "gate_primatives.h"
#include "gate_base.h"

class Button : public BaseGate {
public:
	void press() {
		if (state == OFF) {
			state = ON;
		}
		else {
			state = OFF;
		}
	}

};