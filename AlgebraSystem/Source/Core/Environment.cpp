#include "CAS.h"
#include "Core/Environment.h"
#include "Common/Variable.h"

Environment::Environment(const std::string& name) : m_name(name) { }

Environment::~Environment() {
	
	for (auto var : mp_variables) {
		delete var;
	}
}
