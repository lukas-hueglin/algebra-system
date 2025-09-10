#pragma once
#include "CAS.h"
#include <string>
#include <list>

class Variable;

class CAS_API Environment {

private:
	const std::string& m_name;

	std::list<Variable*> mp_variables;

public:
	Environment(const std::string& name);
	~Environment();
	Environment(const Environment&) = delete;
};