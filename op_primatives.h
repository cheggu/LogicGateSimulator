#pragma once
#include "op_primative_types.h"

namespace primative_operations {
	GateState AND(bool b0, bool b1);
	GateState OR(bool b0, bool b1);
	GateState NOT(bool bit);
	GateState NAND(bool b0, bool b1);
	GateState NOR(bool b0, bool b1);
	GateState XOR(bool b0, bool b1);
	GateState XNOR(bool b0, bool b1);
	void NOP();
	
}