#ifndef LIEUX_H
#define LIEUX_H

#include <string>
#include <vector>

class Lieux{

public:

    std::string nom;
    std::string description;
    int difficulte;
    std::vector<char> liste;
    bool refuge;


    Lieux();
    Lieux(std::string name, std::string resume, int diff, std::vector<char> l, bool safe);
};
#endif
