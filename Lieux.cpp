#ifndef LIEUX_CPP
#define LIEUX_CPP

#include "Lieux.h"
#include <iostream>
#include <vector>

Lieux::Lieux() : nom("Dreamland"), description("Lieux magique emplie de bonheur."), difficulte(1), liste({1,2,3}), refuge(true) {};

Lieux::Lieux(std::string name, std::string resume, int diff, std::vector<char> l, bool safe) : nom(name), description(resume), difficulte(diff), liste(l),refuge(safe) {};

#endif