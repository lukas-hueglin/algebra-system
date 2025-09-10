#pragma once
#include "CAS.h"
#include "Common/Set.h"
#include <string>
#include <vector>

class CAS_API Add;
class CAS_API Subtract;
class CAS_API Multiply;
class CAS_API Divide;

struct CAS_API Expression {

public:
	Expression();

public:
	virtual std::string toString() const = 0;

	std::string drawTree() const;
	virtual void drawTreeLines(std::vector<std::string>& lines, int& head) const = 0;

public:
	virtual bool isOperation() const { return false; }

public:
	Expression& operator+(Expression& other);
	Expression& operator-(Expression& other);
	Expression& operator*(Expression& other);
	Expression& operator/(Expression& other);
};