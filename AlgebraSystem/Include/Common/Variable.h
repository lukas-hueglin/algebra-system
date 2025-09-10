#pragma once
#include "CAS.h"
#include "Common/Expression.h"

struct CAS_API Variable : public Expression {
	
	std::string name;
	
	Variable(std::string name);

	std::string toString() const override;
	void drawTreeLines(std::vector<std::string>& lines, int& head) const override;
};