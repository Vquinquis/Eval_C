#include <iostream>
#include "Lieux.h"
#include <list>


int ex1() {
    int x;
    std::cout << "Ecrire un numero entre 1 et 2 \n";
    std::cin >> x;
    if (x == 1) {
        std::cout << "La destination " << x << " a ete atteinte.\n";
        return 1;
    }
    else if (x == 2) {
        std::cout << "La destination " << x << " a ete atteinte.\n";
        return 2;
    }
    else { ex1(); };
};

int ex2() {
    
    std::string y;
    std::cout << "Ecrire 'un' ou 'deux'. \n";
    std::cin >> y;
    if (y == "un") {
        std::cout << "La destination 1 a ete atteinte.\n";
        return 1;
    }
    else if (y == "deux") {
        std::cout << "La destination 2 a ete atteinte.\n";
        return 2;
    }
    else { ex2(); };
    
}

void etablirCampement(Lieux position) {
    position.description += " Il y'a un campement dans ce lieu.\n";
    position.difficulte /=  2;
    position.refuge = true;
    std::cout << "Vous etablissez un campement a " << position.nom << std::endl;
    std::cout << position.description << std::endl;
    std::cout << "Difficulte de la zone divise par 2" << std::endl;
    std::cout << "Difficulte actuelle de la zone " << position.difficulte;
};

void deplacement(Lieux actuel, std::vector<Lieux> liste) {
    bool fin = false;

    int y;
    std::cout << "Ecrire l'index de votre destination. \n";
    std::cin >> y;
    for (int i = 0; i < actuel.liste.size(); i++) {
        if (y == actuel.liste[i]) {
            std::cout << liste[y].nom << std::endl;
            std::cout << liste[y].description << std::endl;
            fin = true;
            if (liste[y].difficulte > 10) {
                std::string rep;
                std::cout << "L'endroit est plutot dangereux.\nVoulez vous y installer un campement ? Oui/Non \n";
                std::cin >> rep;
                if (rep == "Oui") {
                    etablirCampement(liste[y]);
                }
                else if (rep == "Non") {
                    std::cout<<"Tres bien, comme vous voulez" << std::endl;
                }
            
            }
            break;
        }
    }
    if (fin == false) {
        deplacement(actuel, liste);
    };
    };

void gestionEndurance(int end, Lieux depart, Lieux arrivee) {
    end -= (depart.difficulte + arrivee.difficulte);
    std::cout << "Endurance restante : " << end << std::endl;
};

void repos(Lieux actuel, int endurance) {
    if (actuel.refuge == true) {
        std::string rep;
        std::cout << "Cet endroit possede un refuge.\nVoulez-vous vous reposer ? Oui/Non\n";
        std::cin >> rep;
        if (rep == "Oui") {
            std::cout << "Vous decidez de vous reposer\n";
            std::cout << "Vous recupérez "<<100- endurance<<" points d'endurance.\n";
            endurance += 50;
            if (endurance > 100) {
                endurance = 100;
            }
        }
        else if (rep == "Non") {
            std::cout << "Tres bien, comme vous voulez" << std::endl;
        }
    }
}


int main()
{   Lieux Lieux1 = Lieux();
    Lieux Lieux2 = Lieux("GreenHill", "Grande zone parsemee de loopings.", 2, { 0,2 },false);
    Lieux Lieux3 = Lieux("Royaume Champignon", "Royaume paisible.", 2, { 0,1 },false);
    Lieux Lieux4 = Lieux("Mont Celeste", "Montagne extremement difficile a escalader.", 14, { 0 },false);
    int endurance = 100;
    std::vector<Lieux> lieux{ Lieux1,Lieux2, Lieux3, Lieux4 };
    
    while (endurance != 0) {
        deplacement(Lieux1, lieux);
        gestionEndurance(endurance, lieux[0], lieux[1]);
        repos(lieux[1], endurance);
        repos(lieux[0], endurance);

    }
};
