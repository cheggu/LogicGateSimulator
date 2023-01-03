#pragma once
#include "includes.h"

class Connection {
public:

	BaseGate parent;
	BaseGate child;

	Connection(BaseGate _parent, BaseGate _child) {
		parent = _parent;
		child = _child;
	}

};



namespace wire {
	Connection createConnection(BaseGate parent, BaseGate child) {
		return Connection(parent, child);
	}
}