#include "CAS.h"
#include "Common/Variable.h"

Variable::Variable(std::string name) : name(name) { }

std::string Variable::toString() const {
	return name;
}

void Variable::drawTreeLines(std::vector<std::string>& lines, int& head) const {
	lines = { name };
	head = 0;
}
