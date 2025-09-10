#include "CAS.h"
#include <list>

struct CartesianProduct;

// most general type of set
struct CAS_API Set {
	CartesianProduct operator*(Set b);
};

// special types of sets
struct CAS_API Complex : Set { };
struct CAS_API Imaginary : Set { };
struct CAS_API Real : Set { };
struct CAS_API Integers : Set { };
struct CAS_API Natural : Set { };

// more versatile sets
struct CAS_API CartesianProduct : Set {

	std::list<Set> sets;

	CartesianProduct(std::list<Set> sets);
};

struct CAS_API Union : Set {

	std::list<Set> sets;

	Union(std::list<Set> sets);
};

struct CAS_API Difference : Set {

	Set a;
	Set b;

	Difference(Set a, Set b);
};