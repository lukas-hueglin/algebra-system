#pragma once
#include "CAS.h"
#include "Common/Expression.h"

class CAS_API Operation : public Expression {

public:
	int m_precedence;
	std::string m_opSymbol;

public:
	Operation(int precedence, std::string opSymbol);

public:
	bool isOperation() const override { return true; }
};

class CAS_API BinaryOperation : public Operation {

private:
	Expression* mp_a;
	Expression* mp_b;

public:
	BinaryOperation(int precedence, std::string opSymbol, Expression* p_a, Expression* p_b);

public:
	std::string toString() const override;
	void drawTreeLines(std::vector<std::string>& lines, int& head) const override;
	Expression& a();
	Expression& b();
};

struct CAS_API Add : public BinaryOperation {
	
	Add(Expression* p_a, Expression* p_b);
};

struct CAS_API Subtract : public BinaryOperation {

	Subtract(Expression* p_a, Expression* p_b);
};

struct CAS_API Multiply : public BinaryOperation {

	Multiply(Expression* p_a, Expression* p_b);
};

struct CAS_API Divide : public BinaryOperation {

	Divide(Expression* p_a, Expression* p_b);
};