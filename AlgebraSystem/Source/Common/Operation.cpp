#include "CAS.h"
#include "Common/Operation.h"
#include <cassert>

Operation::Operation(int precedence, std::string opSymbol) : m_precedence(precedence), m_opSymbol(opSymbol) { }

BinaryOperation::BinaryOperation(int precedence, std::string opSymbol, Expression* p_a, Expression* p_b) : Operation(precedence, opSymbol), mp_a(p_a), mp_b(p_b) { }

std::string BinaryOperation::toString() const {
	// convert both expressions to strings
	std::string aStr = mp_a->toString();
	std::string bStr = mp_b->toString();

	if (mp_a->isOperation() && reinterpret_cast<Operation*>(mp_a)->m_precedence < m_precedence) {
		aStr = "(" + aStr + ")";
	}

	if (mp_b->isOperation() && reinterpret_cast<Operation*>(mp_b)->m_precedence < m_precedence) {
		bStr = "(" + bStr + ")";
	}

	return aStr + m_opSymbol + bStr;
}

void BinaryOperation::drawTreeLines(std::vector<std::string>& lines, int& head) const {

	// get tree from both expressions
	std::vector<std::string> aLines, bLines;
	int aHead, bHead;
	mp_a->drawTreeLines(aLines, aHead);
	mp_b->drawTreeLines(bLines, bHead);

	// get sizes
	int aHeight = aLines.size();
	int aWidth = aLines[0].length();
	int bHeight = bLines.size();
	int bWidth = bLines[0].length();
	
	// calculate new quantities
	int minSpacing = 2; // minimal horizontal spacing between two objects
	int numSpacesToFill = aWidth - aHead - 1 + minSpacing + bHead; // -1 because of the symbol of a

	if (numSpacesToFill % 2 == 0) {
		++numSpacesToFill; // num Spaces to fill has to be odd
		++minSpacing;
	}

	int numRows = (numSpacesToFill - 1) / 2;
	head = aHead + numRows + 1;

	// create new lines
	std::string line = std::string(aHead + numRows + 1, ' ') + m_opSymbol + std::string(bWidth - bHead + numRows, ' ');
	lines.push_back(line);

	int sideSpaces = numRows; // number of spaces on the side of the lines
	int centerSpaces = 1; // number of spaces between the lines
	while (sideSpaces > 0) {
		std::string line;

		line += std::string(aHead + sideSpaces, ' ');
		line += '/';
		line += std::string(centerSpaces, ' ');
		line += '\\';
		line += std::string(bWidth - bHead + sideSpaces - 1, ' ');

		--sideSpaces;
		centerSpaces += 2;

		lines.push_back(line);
	}

	// add old lines
	for (int i = 0; i < std::max(aHeight, bHeight); ++i) {
		std::string line;

		// add a
		if (i < aHeight)
			line += aLines[i];
		else
			line += std::string(aWidth, ' ');

		// add spacing
		line += std::string(minSpacing, ' ');

		// add b
		if (i < bHeight)
			line += bLines[i];
		else
			line += std::string(bWidth, ' ');

		lines.push_back(line);
	}
}

Expression& BinaryOperation::a() {
	return *mp_a;
}

Expression& BinaryOperation::b() {
	return *mp_b;
}

Add::Add(Expression* p_a, Expression* p_b) : BinaryOperation(0, "+", p_a, p_b) {}

Subtract::Subtract(Expression* p_a, Expression* p_b) : BinaryOperation(0, "-", p_a, p_b) {}

Multiply::Multiply(Expression* p_a, Expression* p_b) : BinaryOperation(1, "*", p_a, p_b) {}

Divide::Divide(Expression* p_a, Expression* p_b) : BinaryOperation(1, "/", p_a, p_b) {}
