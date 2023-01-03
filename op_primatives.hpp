#pragma once
#include "gate_state.h"
#include "op_primatives.h"

GateState primative_operations::AND(bool b0, bool b1) {
	return (GateState)(b0 && b1);
}

GateState primative_operations::OR(bool b0, bool b1) {
	return GateState(b0 || b1);
}

GateState primative_operations::NOT(bool b) {
	return (GateState)!b;
}

GateState primative_operations::NAND(bool b0, bool b1) {
	return NOT(AND(b0, b1));
}

GateState primative_operations::NOR(bool b0, bool b1) {
	return NOT(OR(b0, b1));
}

GateState primative_operations::XOR(bool b0, bool b1) {
	if ((b0 && !b1) || (!b0 && b1)) {
		return ON;
	}
	else {
		return OFF;
	}
}

GateState primative_operations::XNOR(bool b0, bool b1) {
	return NOT(XOR(b0, b1));
}

void primative_operations::NOP() {

};