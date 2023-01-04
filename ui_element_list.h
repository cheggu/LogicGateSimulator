#pragma once
#include "ui_base.h"
#include "ui_button.h"

std::vector<UIButton> btn_list = {};
std::vector<BaseGate*> gate_list = {};

namespace uiTools {
	void addButton(UIButton btn) {
		btn_list.push_back(btn);
	}

	std::vector<UIButton>& getButtonList() {
		return btn_list;
	}


	void addGate(BaseGate& gate) {
		gate_list.push_back(&gate);
	}

	std::vector<BaseGate*>& getGateList() {
		return gate_list;
	}

	void addText();
	void addTextBox();

}