#include "CAS.h"
#include "Common/Set.h"

CartesianProduct Set::operator*(Set b) {
    return CartesianProduct({*this, b});
}

CartesianProduct::CartesianProduct(std::list<Set> sets) : sets(sets) { }

Union::Union(std::list<Set> sets) : sets(sets) { }

Difference::Difference(Set a, Set b) : a(a), b(b) { }
