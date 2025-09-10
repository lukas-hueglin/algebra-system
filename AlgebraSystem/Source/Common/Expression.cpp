#include "CAS.h"
#include "Common/Expression.h"
#include "Common/Operation.h"

Expression::Expression() { }

std::string Expression::drawTree() const {
	// get all lines of tree
	std::vector<std::string> lines;
	int head;
	drawTreeLines(lines, head);

	// combine all lines
	std::string res;
	for (const std::string& l : lines) {
		res += l + "\n";
	}

	return res;
}

Expression& Expression::operator+(Expression& other) {
	return *(new Add(this, &other));
}

Expression& Expression::operator-(Expression& other) {
	return *(new Subtract(this, &other));
}

Expression& Expression::operator*(Expression& other) {
	return *(new Multiply(this, &other));
}

Expression& Expression::operator/(Expression& other) {
	return *(new Divide(this, &other));
}
