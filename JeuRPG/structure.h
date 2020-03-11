#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

// DECLARATION DE LA STRUCTURE PERSONNAGE

typedef struct personnage personnage;
    struct personnage{

        char userName[25];
        int barreHP;
        int barreXP1;
        int barreXP2;
        int barreXP3;
        int degat;
        int niveau;
        int deplacementFaux;
        int degatArc;
        int hpbackUp;
        int degatbackUp;


    };

// DECLARATION DE LA STRUCTURE MONSTRE FAIBLE

    typedef struct monstre monstre;

    struct monstre{

        int barreHP;
        int niveau;
        int degat;

    };



    typedef struct inventaire inventaire;
    struct inventaire{

        int potion;
        int potionRenvoi;
        int potionAtk;
        int arc;

        };


#endif // STRUCTURE_H_INCLUDED
