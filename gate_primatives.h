#pragma once
#include <vector>
#include "gate_state.h"
#include "op_primatives.h"
#include "gate_base.h"

class PrimativeGate : public BaseGate {
public:
	PrimativeGate(PrimativeGateType type) {
		switch (type) {
		case (PrimativeGateType::AND):
			operation = primative_operations::AND;
			break;
		case (PrimativeGateType::OR):
			operation = primative_operations::OR;
			break;
		case (PrimativeGateType::NOT):
			not_op = true;
			operation = NULL;
			break;
		case (PrimativeGateType::NAND):
			operation = primative_operations::NAND;
			break;
		case (PrimativeGateType::NOR):
			operation = primative_operations::NOR;
			break;
		case (PrimativeGateType::XOR):
			operation = primative_operations::XOR;
			break;
		case (PrimativeGateType::XNOR):
			operation = primative_operations::XNOR;
			break;
		case (PrimativeGateType::NOP):
			nop = true;
			operation = NULL;
			break;
		}
	}

	void emulate() {
		a = calc_state_from_parents(InputType::A);
		b = calc_state_from_parents(InputType::B);

		std::cout << "emulating gate with a=" << a << " and b=" << b << "." << std::endl;

		if (nop) {
			primative_operations::NOP();
		}
		else if (not_op) {
			state = primative_operations::NOT(state);
		}
		else {
			state = operation(a, b);
		}
	}
	
};