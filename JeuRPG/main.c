#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include "structure.h"
#include "fonction.h"

// INITIALISATION DES FONCTIONS ! //

// DECLARATION DES VARIABLES DES TYPES PERSONNAGES ET MONSTREFAIBLES ET INVENTAIRE
    personnage Player1;
    inventaire Sac;
    monstre Monster1;
    monstre Monster2;
    monstre Monster3;
    monstre MonsterBoss;

// FONCTION PRINCIPALE

    int backupHpLvl1 = 500;
    int degatArcBackup = 150;
    int degatBackupMonstreFaible = 20;
    int degatBackupMonstreMoyen = 50;
    int degatBackupMonstreFort = 100;
    int degatBackupMonstreBoss = 200;
    int hpBackupMonstreFaible = 200;
    int hpBackupMonstreMoyen = 500;
    int hpBackupMonstreFort = 1000;
    int hpBackupMonstreBoss = 2000;
    int potionHealth = 200;
    int potionAtk = 50;
    int x = 0;
    int y = 0;
    int xp = 600;
    int stockXP = 0;
    int fincombat = 0;
    int dejapasse00 = 1;
    int dejapasse01 = 0;
    int dejapasse02 = 0;
    int dejapasse03 = 0;
    int dejapasse10 = 0;
    int dejapasse11 = 0;
    int dejapasse12 = 0;
    int dejapasse13 = 0;
    int dejapasse20 = 0;
    int dejapasse21 = 0;
    int dejapasse22 = 0;
    int dejapasse23 = 0;
    int dejapasse30 = 0;
    int dejapasse31 = 0;
    int dejapasse32 = 0;
    int dejapasse33 = 0;
    int revenir = 0;






void main(void)
{

// DECLARATION DES VALEURS DU TYPE PERSONNAGES POUR LA VARIABLE PLAYER1
    Player1.niveau = 1;
    Player1.barreHP = 500 * Player1.niveau;
    Player1.degat = 100 * Player1.niveau;
    Player1.barreXP1 = 600;
    Player1.barreXP2 = 2000;
    Player1.barreXP3 = 5000;
    Player1.deplacementFaux = 0;
    Player1.degatArc = 150;
    Player1.hpbackUp = 500*Player1.niveau;
    Player1.degatbackUp = 100*Player1.niveau;

// DECLARATION DES VALEURS POUR LA VARIABLE MONSTER1 FAIBLE

    Monster1.barreHP = 200;
    Monster1.degat = 20;
    Monster1.niveau = 5;

// DECLARATION DES VALEURS POUR LA VARIABLE MONSTER2 MOYEN

    Monster2.barreHP = 500;
    Monster2.degat = 50;
    Monster2.niveau = 10;

// DECLARATION DES VALEURS POUR LA VARIABLE MONSTER3 FORT

    Monster3.barreHP = 1000;
    Monster3.degat = 100;
    Monster3.niveau = 20;

// DECLARATION DES VALEURS POUR LA VARIABLE MONSTER4 BOSS

    MonsterBoss.barreHP = 2000;
    MonsterBoss.degat = 200;
    MonsterBoss.niveau = 50;

// DECLARATION DES VALEURS POUR LA VARIABLE SAC

    Sac.potion = 10;
    Sac.potionRenvoi = 5;
    Sac.potionAtk = 5;
    Sac.arc = 0;

// DECLARATION DES VARIABLES NECESSAIRES POUR LE CODE


// PREMIER SWITCH POUR LAFFICHAGE DU MENU
    do{
    switch(afficheMenu()){

// SI LE CHOIX EST 1 ALORS
        case 1:
            revenir = 1;
            printf("\nWelcome new player, what is your name?\n");
            printf("Enter an user name between 1 & 25 letters: ");
            scanf("%s", Player1.userName);
            printf("Hi, %s\n", Player1.userName);
            Sleep(2000);
            printf("You appeared in a dark forest surrounded by a big tree.\n");
            Sleep(2000);
            printf("In front of you, you see a monster.. \n");
            Sleep(2000);
            color(4,0);
            printf("It's a level 5 monster !! \n\n");
            color(7,0);
            Sleep(1000);


            combat();
            cartographie();
            do{
            fonctionCase();
            }while(MonsterBoss.barreHP >= 0);



            break;




            // CAS 2: POUR LANCER UNE PARTIE SAUVEGARDER ( PAS ENCORE FAIT)

            case 2:
                color(8,0);
                printf("Sauvegarde plus tard!");
                color(7,0);
                revenir = 1;
                break;

            // CAS 3: PETIT RESUME DU JEU ( PAS FAIT )

            case 3:
                color(8,0);
                printf("The game relies on a turn-by-turn combat system that forces the player to plan his attacks and take risks. \nYou will be the protagonist who will evolve in a fantasy world where he must fight enemies history begins \nin a sinister forest when you are in pursuit of Shinnok a monster that terrorizes your village for centuries \nyour adventure will unfold in a 4x4 tray each area will inhabit a monster, The more you advance in history the \nstronger will be your opponents to choose which path will be the wisest in order to achieve shinnok. of course \nas you move forward in history you will be able to get new weapons ( with new skills) and many objects that can \nhelp you on your journey.Good luck to you young adventurers\n\n- Lecornet Killian B1A\n- Crespo Matthias B1A\n\n");
                color(7,0);
                break;

            // QUITTER LE PROGRAMME

            case 4:
                exit(0);
                break;

            // SI AUTRE CHOSE QUITTER LE PROGRAMME

            default:
                exit(0);
                break;


            }
    }while(revenir == 0);

        }

void    color(int text,int font)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,font*16+text);
}


int choixDeplacement(){

    int choixxxxx;


    Sleep(2000);
    color(6,0);
    printf("\nMOVEMENT: \n\n");
    printf("-1 NORTH \n");
    printf("-2 SOUTH\n");
    printf("-3 EAST\n");
    printf("-4 WEST\n\n");
    scanf("%d", &choixxxxx);
    color(7,0);

    return choixxxxx;
}

int cartographie(){


    do{
    switch(choixDeplacement()){



    case 1:
        y--;
        Player1.deplacementFaux = 0;
        if(x<0 || x>3 || y<0 || y>3){
            color(4,0);
            printf("This place is blocked. \n");
            printf("Try another direction. \n");
            y++;
            Player1.deplacementFaux = 1;
        }
        else{
            color(11,0);
            printf("You are heading NORTH...\n");
            printf("Loading...\n\n");
            Sleep(3000);
            printf("You are located at %d,%d\n\n", y,x);
            color(7,0);

        }
        break;

    case 2:
        y++;
        Player1.deplacementFaux = 0;
        if(x<0 || x>3 || y<0 || y>3){
            y--;
            color(4,0);
            printf("This place is blocked. \n");
            printf("Try another direction. \n");
            Player1.deplacementFaux = 1;



        }
        else{
            color(11,0);
            printf("You are heading SOUTH...");
            printf("Loading...\n\n");
            Sleep(3000);
            printf("You are located at %d,%d\n\n", x,y);
            color(7,0);

        }
        break;

    case 3:
        x++;
        Player1.deplacementFaux = 0;
        if(x<0 || x>3 || y<0 || y>3){
            x--;
            color(4,0);
            printf("This place is blocked. \n");
            printf("Try another direction. \n");
            Player1.deplacementFaux = 1;


        }
        else{
            color(11,0);
            printf("You are heading EAST...");
            printf("Loading...\n\n");
            Sleep(3000);
            printf("You are located at %d,%d\n\n", x,y);
            color(7,0);
        }
        break;

    case 4:
        x--;
        Player1.deplacementFaux = 0;
        if(x<0 || x>3 || y<0 || y>3){
            color(4,0);
            printf("This place is blocked. \n");
            printf("Try another direction. \n");
            x++;
            Player1.deplacementFaux = 1;

        }
        else{
            color(11,0);
            printf("You are heading WEST...");
            printf("Loading...\n\n");
            Sleep(3000);
            printf("You are located at %d,%d\n\n", x,y);
            color(7,0);
        }
        break;

    }
    }while(x<0 || x>3 || y<0 || y>3  ||  Player1.deplacementFaux == 1);

 return 0;
}



    int afficheMenu(){

    int choix;
    printf("MAIN MENU: \n");
    printf("1- Create a new game.\n");
    printf("2- Load a save game.\n");
    printf("3- About.\n");
    printf("4- Exit\n\n");
    scanf("%d", &choix);

    return choix;
}


int degatPerso(){

    srand(time(NULL));
    int v = rand() % 10;

    if(v < 2){
        Player1.degat += Player1.degat;
        Monster1.barreHP -= Player1.degat;
    }
    if(v == 9){
        Player1.degat = 0;
        Monster1.barreHP -= Player1.degat;
    }
    if(v > 1 && v < 9){
        Monster1.barreHP -= Player1.degat;
    }

    return v;

}
int degatPersoMoyen(){

    srand(time(NULL));
    int v = rand() % 10;

    if(v < 2){
        Player1.degat += Player1.degat;
        Monster2.barreHP -= Player1.degat;
    }
    if(v == 9){
        Player1.degat = 0;
        Monster2.barreHP -= Player1.degat;
    }
    if(v > 1 && v < 9){
        Monster2.barreHP -= Player1.degat;
    }

    return v;

}
int degatPersoFort(){

    srand(time(NULL));
    int v = rand() % 10;

    if(v < 2){
        Player1.degat += Player1.degat;
        Monster3.barreHP -= Player1.degat;
    }
    if(v == 9){
        Player1.degat = 0;
        Monster3.barreHP -= Player1.degat;
    }
    if(v > 1 && v < 9){
        Monster3.barreHP -= Player1.degat;
    }

    return v;

}
int degatPersoBoss(){

    srand(time(NULL));
    int v = rand() % 10;

    if(v < 2){
        Player1.degat += Player1.degat;
        MonsterBoss.barreHP -= Player1.degat;
    }
    if(v == 9){
        Player1.degat = 0;
        MonsterBoss.barreHP -= Player1.degat;
    }
    if(v > 1 && v < 9){
        MonsterBoss.barreHP -= Player1.degat;
    }

    return v;

}
int choixAction(){

    int choice;
    color(14,0);
    printf("\nWhat do you want to do: \n");
    printf("1- Attack the monster\n");
    printf("2- Open your inventory\n");
    printf("3- Run away (50 percent chance to get mid health) \n\n");
    scanf("%d", &choice);
    color(7,0);

    return choice;
}

int degatMonstreFaible(){

    srand(time(NULL));

    int c = rand()% 10;

    if(c == 9){
        Monster1.degat = 0;
        Player1.barreHP -= Monster1.degat;
    }
    if(c < 2){
        Monster1.degat += Monster1.degat;
        Player1.barreHP -=Monster1.degat;
    }
    if(c > 1 && c < 9){
        Player1.barreHP -=Monster1.degat;
    }

    return c;



}
int degatMonstreMoyen(){

    srand(time(NULL));

    int c = rand()% 10;

    if(c == 9){
        Monster2.degat = 0;
        Player1.barreHP -= Monster2.degat;
    }
    if(c < 2){
        Monster2.degat += Monster2.degat;
        Player1.barreHP -=Monster1.degat;
    }
    if(c > 1 && c < 9){
        Player1.barreHP -=Monster2.degat;
    }

    return c;



}
int degatMonstreFort(){

    srand(time(NULL));

    int c = rand()% 10;

    if(c == 9){
        Monster3.degat = 0;
        Player1.barreHP -= Monster3.degat;
    }
    if(c < 2){
        Monster3.degat += Monster3.degat;
        Player1.barreHP -=Monster3.degat;
    }
    if(c > 1 && c < 9){
        Player1.barreHP -=Monster3.degat;
    }

    return c;



}
int degatMonstreBoss(){

    srand(time(NULL));

    int c = rand()% 10;

    if(c == 9){
        MonsterBoss.degat = 0;
        Player1.barreHP -= MonsterBoss.degat;
    }
    if(c < 2){
        MonsterBoss.degat += MonsterBoss.degat;
        Player1.barreHP -=Monster1.degat;
    }
    if(c > 1 && c < 9){
        Player1.barreHP -=MonsterBoss.degat;
    }

    return c;



}
int OpenInventaire(){

    int choixx;
    color(2,0);
    printf("\INVENTORY : (If you don't have an item return to the menu or your turn will pass\n\n");
    printf("1- Health potion : %d\n", Sac.potion);
    printf("2- Return damage potion : %d\n", Sac.potionRenvoi);
    printf("3- Offensive potion : %d\n", Sac.potionAtk);
    printf("4- Return to choice menu\n\n");
    scanf("%d", &choixx);
    color(2,0);

    return choixx;
}
int degatPotionRenvoi(){

    srand(time(NULL));

    int c = rand()% 10;

    if(c == 9){
        Monster1.degat = 0;
        Monster1.barreHP -= Monster1.degat;
    }
    if(c < 2){
        Monster1.degat += Monster1.degat;
        Monster1.barreHP -=Monster1.degat;
    }
    if(c > 1 && c < 9){
        Monster1.barreHP -=Monster1.degat;
    }

    return c;



}
int degatPotionRenvoiMoyen(){

    srand(time(NULL));

    int c = rand()% 10;

    if(c == 9){
        Monster2.degat = 0;
        Monster2.barreHP -= Monster2.degat;
    }
    if(c < 2){
        Monster2.degat += Monster2.degat;
        Monster2.barreHP -=Monster2.degat;
    }
    if(c > 1 && c < 9){
        Monster2.barreHP -=Monster2.degat;
    }

    return c;



}
int degatPotionRenvoiFort(){

    srand(time(NULL));

    int c = rand()% 10;

    if(c == 9){
        Monster3.degat = 0;
        Monster3.barreHP -= Monster3.degat;
    }
    if(c < 2){
        Monster3.degat += Monster3.degat;
        Monster3.barreHP -=Monster3.degat;
    }
    if(c > 1 && c < 9){
        Monster3.barreHP -=Monster3.degat;
    }

    return c;



}
int degatPotionRenvoiBoss(){

    srand(time(NULL));

    int c = rand()% 10;

    if(c == 9){
        MonsterBoss.degat = 0;
        MonsterBoss.barreHP -= MonsterBoss.degat;
    }
    if(c < 2){
        MonsterBoss.degat += MonsterBoss.degat;
        MonsterBoss.barreHP -=MonsterBoss.degat;
    }
    if(c > 1 && c < 9){
        MonsterBoss.barreHP -=MonsterBoss.degat;
    }

    return c;



}
int degatPotionAtk(){

    srand(time(NULL));
    int v = rand() % 10;

    if(v < 2){
        Player1.degat += Player1.degat + potionAtk;
        Monster1.barreHP -= Player1.degat;
    }
    if(v == 9){
        Player1.degat = 0;
        Monster1.barreHP -= Player1.degat;
    }
    if(v > 1 && v < 9){
        Player1.degat += potionAtk;
        Monster1.barreHP -= Player1.degat;
    }

    return v;

}
int degatPotionAtkMoyen(){

    srand(time(NULL));
    int v = rand() % 10;

    if(v < 2){
        Player1.degat += Player1.degat + potionAtk;
        Monster2.barreHP -= Player1.degat;
    }
    if(v == 9){
        Player1.degat = 0;
        Monster2.barreHP -= Player1.degat;
    }
    if(v > 1 && v < 9){
        Player1.degat += potionAtk;
        Monster2.barreHP -= Player1.degat;
    }

    return v;

}
int degatPotionAtkFort(){

    srand(time(NULL));
    int v = rand() % 10;

    if(v < 2){
        Player1.degat += Player1.degat + potionAtk;
        Monster3.barreHP -= Player1.degat;
    }
    if(v == 9){
        Player1.degat = 0;
        Monster3.barreHP -= Player1.degat;
    }
    if(v > 1 && v < 9){
        Player1.degat += potionAtk;
        Monster3.barreHP -= Player1.degat;
    }

    return v;

}
int degatPotionAtkBoss(){

    srand(time(NULL));
    int v = rand() % 10;

    if(v < 2){
        Player1.degat += Player1.degat + potionAtk;
        MonsterBoss.barreHP -= Player1.degat;
    }
    if(v == 9){
        Player1.degat = 0;
        MonsterBoss.barreHP -= Player1.degat;
    }
    if(v > 1 && v < 9){
        Player1.degat += potionAtk;
        MonsterBoss.barreHP -= Player1.degat;
    }

    return v;

}

int combat(){

do{
        switch(choixAction()){

            //CAS 1 COUP DE POING AU MONSTRE



            case 1:
                printf("You just punched the monster! \n");
                degatPerso();
                Sleep(1000);
                printf("The monster took %d damage !\n", Player1.degat);
                Player1.degat = Player1.degatbackUp;
                Sleep(2000);
                printf("The monster still has %d life left! \n", Monster1.barreHP);
                Sleep(2000);

                // SI LE MONSTRE A ENCORE DE LA VIE, IL ATTAQUE

                if(Monster1.barreHP > 0){
                    printf("Be careful the monster replies! \n");
                    Sleep(2000);
                    degatMonstreFaible();
                    printf("The monster did %d damage!\n", Monster1.degat);
                    Monster1.degat = degatBackupMonstreFaible;
                    Sleep(1000);
                    printf("You have %d life left! \n", Player1.barreHP);

                }

                // SI LE MONSTRE N'A PLUS DE VIE: MESSAGE POUR AFFICHER QUE TU L'AS BATTU

                if(Monster1.barreHP <= 0){

                        printf("\nYou have beaten the monster! \n");
                        printf("You won %d XP\n", xp);
                        stockXP += xp;
                        printf("Barre XP %d/%d\n\n", stockXP,Player1.barreXP1);
                        fincombat = 1;
                        Monster1.barreHP = hpBackupMonstreFaible;
                        Sleep(2000);
                        color(10,0);
                        printf("\nYou picked up a bow\n");
                        color(7,0);
                        Sleep(2000);
                        printf("You can now use the skill 'Bow hit'\n" );
                        Sac.arc = 1;

                    if(stockXP >= Player1.barreXP1){
                        Player1.niveau++;
                        Player1.barreHP = backupHpLvl1 * Player1.niveau;
                        Player1.degat = Player1.degat * Player1.niveau;
                        printf("You are now level %d, Congratulations! \n", Player1.niveau);
                        printf("Your damage and your health level up too!\n\n");
                        printf("Health: %d\n", Player1.barreHP);
                        printf("Damage: %d\n", Player1.degat);

                        fincombat = 1;
                        Monster1.barreHP = hpBackupMonstreFaible;

                    }

                break;

                // CAS 2: OUVERTURE DE LINVENTAIRE
            case 2:

            // SWITCH FONCTION OPEN INVENTAIRE

                switch(OpenInventaire()){

                // CAS 1: UTILISATION D'UNE POTION DE SOIN
                    case 1:

                        // SI YA PAS DE POTION : MESSAGE ERREUR PAS DE POTION

                        if(Sac.potion == 0){
                            printf("You don't have any health potion.");
                        }

                        // SI YA DES POTIONS : TU GAGNES DES HP MAIS TU PERDS 1 POTION !

                        if(Sac.potion > 0){

                            Player1.barreHP += potionHealth;
                            Sac.potion --;

                        // A RENDRE ADAPTATIF

                        if(Player1.barreHP > Player1.hpbackUp){
                        Player1.barreHP = Player1.hpbackUp;
                        }
                        printf("\nYou now have %d health point\n", Player1.barreHP);
                        }

                        break;

                // CAS 2: POTION DE RENVOI DE SORT ( SP5 E BOUCLIER TU CONNAIS )

                case 2:

                    // SI TA PAS DE POTION: MESSAGE ERREUR PAS DE POTION

                    if(Sac.potionRenvoi == 0){
                        printf("You don't have any Return damage potion !\n\n");
                        Sleep(2000);
                    }

                    // SI TU AS UNE POTION: TU UTILISE LA FONCTION DEGAT POTION RENVOI ET TU PERD UNE POTION

                    if(Sac.potionRenvoi > 0){
                        printf("Prepare to fire the monster attack\n\n");
                        Sac.potionRenvoi--;
                        Sleep(2000);
                        printf("You have returned %d damage !\n", Monster1.degat);
                        degatPotionRenvoi();
                        Monster1.degat = degatBackupMonstreFaible;
                        Sleep(2000);
                        printf("The monster still has %d life left! \n", Monster1.barreHP);
                        Sleep(2000);
                    }
                    if(Monster1.barreHP <= 0){

                            printf("You have beaten the monster! \n");
                            printf("You won %d XP\n\n", xp);
                            stockXP += xp;
                            printf("Barre XP %d/%d \n\n", stockXP,Player1.barreXP1);
                            fincombat = 1;
                            Monster1.barreHP = hpBackupMonstreFaible;
                            Sleep(2000);
                            printf("\nYou picked up a bow\n");
                            Sleep(2000);
                            printf("You can now use the skill 'Bow hit'\n" );
                            Sac.arc = 1;


                        if(stockXP >= Player1.barreXP1){
                            Player1.niveau++;
                            Player1.barreHP = backupHpLvl1 * Player1.niveau;
                            Player1.degat = Player1.degat * Player1.niveau;
                            printf("You are now level %d, Congratulations! \n", Player1.niveau);
                            printf("Your damage and your health level up too!\n\n");
                            printf("Health: %d\n", Player1.barreHP);
                            printf("Damage: %d\n", Player1.degat);
                            Sleep(2000);
                            printf("\nYou picked up a bow\n");
                            Sleep(2000);
                            printf("You can now use the skill 'Bow hit'\n" );
                            Sac.arc = 1;
                            fincombat = 1;
                            Monster1.barreHP = hpBackupMonstreFaible;


                        }
                    }
                        break;

                case 3:
                    // SI YA PAS DE POTION : MESSAGE ERREUR PAS DE POTION

                        if(Sac.potionAtk == 0){
                            printf("You don't have any health potion.");
                        }
                        if(Sac.potionAtk >0){
                                Sac.potionAtk--;
                                printf("You are going to attack!\n");
                                Sleep(2000);
                                printf("WOW! Your attack potion has done a lot of damage! \n");
                                degatPotionAtk();
                                Sleep(1000);
                                printf("The monster took %d damage !\n", Player1.degat);
                                Player1.degat = Player1.degatbackUp;
                                Sleep(2000);
                                printf("The monster still has %d life left! \n", Monster1.barreHP);
                                Sleep(2000);
                        }
                        if(Monster1.barreHP > 0){
                            printf("Be careful the monster replies! \n");
                            Sleep(2000);
                            degatMonstreFaible();
                            printf("The monster did %d damage!\n", Monster1.degat);
                            Monster1.degat = degatBackupMonstreFaible;
                            Sleep(1000);
                            printf("You have %d life left! \n", Player1.barreHP);

                        }
                        if(Monster1.barreHP <= 0){

                                printf("You have beaten the monster! \n");
                                printf("You won %d XP\n\n", xp);
                                stockXP += xp;
                                printf("Barre XP %d/%d", stockXP,Player1.barreXP1);
                                fincombat = 1;
                                Monster1.barreHP = hpBackupMonstreFaible;
                                Sleep(2000);
                                printf("\nYou picked up a bow\n");
                                Sleep(2000);
                                printf("You can now use the skill 'Bow hit'\n" );
                                Sac.arc = 1;

                            if(stockXP >= Player1.barreXP1){
                                Player1.niveau++;
                                Player1.barreHP = backupHpLvl1 * Player1.niveau;
                                Player1.degat = Player1.degat * Player1.niveau;
                                printf("You are now level %d, Congratulations! \n", Player1.niveau);
                                Sleep(2000);
                                printf("Your damage and your health level up too!\n\n");
                                Sleep(1000);
                                printf("Health: %d\n", Player1.barreHP);
                                printf("Damage: %d\n", Player1.degat);
                                fincombat = 1;
                                Monster1.barreHP = hpBackupMonstreFaible;

                            }

                        }
                        break;

                    case 4:
                        break;

                    }

            // PAS ENCORE FAIS MAIS C'EST POUR FUIR

                case 3:
//

                    break;


            }
        }

           // TOUT CA A FAIRE TANT QUE TU N'AS PAS PERDU TOUTE TA VIE OU QUE LE MONSTRE N'EST PAS MORT

        }while(Player1.barreHP > 0 && fincombat == 0);

}

int ChoixAttack(){

    int choixatk;

    printf("\nChoose an attack: \n\n");
    printf("-1 Punch!\n");
    printf("-2 Bow hit! \n\n");
    scanf("%d", &choixatk);

    return choixatk;
}

int BowHit(){

srand(time(NULL));
    int v = rand() % 10;


    if(v < 2){
        Player1.degatArc += Player1.degatArc;
        Monster1.barreHP -= Player1.degatArc;
    }
    if(v == 9){
        Player1.degatArc = 0;
        Monster1.barreHP -= Player1.degatArc;
    }
    if(v > 1 && v < 9){
        Monster1.barreHP -= Player1.degatArc;
    }
    return v;
}

int BowHitMoyen(){

srand(time(NULL));
    int v = rand() % 10;


    if(v < 2){
        Player1.degatArc += Player1.degatArc;
        Monster2.barreHP -= Player1.degatArc;
    }
    if(v == 9){
        Player1.degatArc = 0;
        Monster2.barreHP -= Player1.degatArc;
    }
    if(v > 1 && v < 9){
        Monster2.barreHP -= Player1.degatArc;
    }
    return v;
}

int BowHitFort(){

srand(time(NULL));
    int v = rand() % 10;


    if(v < 2){
        Player1.degatArc += Player1.degatArc;
        Monster3.barreHP -= Player1.degatArc;
    }
    if(v == 9){
        Player1.degatArc = 0;
        Monster3.barreHP -= Player1.degatArc;
    }
    if(v > 1 && v < 9){
        Monster3.barreHP -= Player1.degatArc;
    }
    return v;
}

int BowHitBoss(){

srand(time(NULL));
    int v = rand() % 10;


    if(v < 2){
        Player1.degatArc += Player1.degatArc;
        MonsterBoss.barreHP -= Player1.degatArc;
    }
    if(v == 9){
        Player1.degatArc = 0;
        MonsterBoss.barreHP -= Player1.degatArc;
    }
    if(v > 1 && v < 9){
        MonsterBoss.barreHP -= Player1.degatArc;
    }
    return v;
}

int combatAvecArc(){

do{
        switch(choixAction()){

            //CAS 1 COUP DE POING AU MONSTRE

            case 1:

                switch(ChoixAttack()){

            case 1:
                printf("You just punched the monster! \n");
                degatPerso();
                Sleep(1000);
                printf("The monster took %d damage !\n", Player1.degat);
                Player1.degat = Player1.degatbackUp;
                Sleep(2000);
                printf("The monster still has %d life left! \n", Monster1.barreHP);
                Sleep(2000);

                // SI LE MONSTRE A ENCORE DE LA VIE, IL ATTAQUE

                if(Monster1.barreHP > 0){
                    printf("Be careful the monster replies! \n");
                    Sleep(2000);
                    degatMonstreFaible();
                    printf("The monster did %d damage!\n", Monster1.degat);
                    Monster1.degat = degatBackupMonstreFaible;
                    Sleep(1000);
                    printf("You have %d life left! \n", Player1.barreHP);

                }

                // SI LE MONSTRE N'A PLUS DE VIE: MESSAGE POUR AFFICHER QUE TU L'AS BATTU

                if(Monster1.barreHP <= 0){

                        printf("\nYou have beaten the monster! \n");
                        printf("You won %d XP\n", xp);
                        stockXP += xp;
                        printf("Barre XP %d/%d\n\n", stockXP,Player1.barreXP2);
                        fincombat = 1;
                        Monster1.barreHP = hpBackupMonstreFaible;

                    if(stockXP >= Player1.barreXP2){
                        Player1.niveau++;
                        Player1.barreHP = backupHpLvl1 * Player1.niveau;
                        Player1.degat = Player1.degat * Player1.niveau;
                        printf("You are now level %d, Congratulations! \n", Player1.niveau);
                        printf("Your damage and your health level up too!\n\n");
                        printf("Health: %d\n", Player1.barreHP);
                        printf("Damage: %d\n", Player1.degat);
                        Sleep(2000);
                        printf("\nYou picked up a potion\n");
                        Sleep(2000);

                        Sac.potion += 1;
                        fincombat = 1;

                    }
                }
                break;

            case 2:
                if(Sac.arc == 0){
                    printf("You don't have any bow to use this skill\n");
                }
                if(Sac.arc > 0){
                    printf("You throw a flaming arrow at the monster\n");
                    BowHit();
                    printf("The monster took %d damage !\n", Player1.degatArc);
                    Player1.degatArc = degatArcBackup;
                    Sleep(2000);
                    printf("The monster still has %d life left! \n\n", Monster1.barreHP);
                    Sleep(2000);
                }

                if(Monster1.barreHP > 0){
                    printf("Be careful the monster replies! \n");
                    Sleep(2000);
                    degatMonstreFaible();
                    printf("The monster did %d damage!\n", Monster1.degat);
                    Monster1.degat = degatBackupMonstreFaible;
                    Sleep(1000);
                    printf("You have %d life left! \n", Player1.barreHP);

                }
                if(Monster1.barreHP <= 0){

                        printf("\nYou have beaten the monster! \n");
                        printf("You won %d XP\n", xp);
                        stockXP += xp;
                        printf("Barre XP %d/%d\n\n", stockXP,Player1.barreXP2);
                        fincombat =1;
                        Monster1.barreHP = hpBackupMonstreFaible;

                    if(stockXP >= Player1.barreXP2){
                        Player1.niveau++;
                        Player1.barreHP = backupHpLvl1 * Player1.niveau;
                        Player1.degat = Player1.degat * Player1.niveau;
                        printf("You are now level %d, Congratulations! \n", Player1.niveau);
                        printf("Your damage and your health level up too!\n\n");
                        printf("Health: %d\n", Player1.barreHP);
                        printf("Damage: %d\n", Player1.degat);
                        printf("\nYou picked up an Offensive potion\n");
                        Sleep(2000);
                        Sac.potionAtk += 1;
                        fincombat = 1;
                    }
                }

                }



                break;

                // CAS 2: OUVERTURE DE LINVENTAIRE
            case 2:

            // SWITCH FONCTION OPEN INVENTAIRE

                switch(OpenInventaire()){

                // CAS 1: UTILISATION D'UNE POTION DE SOIN
                    case 1:

                        // SI YA PAS DE POTION : MESSAGE ERREUR PAS DE POTION

                        if(Sac.potion == 0){
                            printf("You don't have any health potion.");
                        }

                        // SI YA DES POTIONS : TU GAGNES DES HP MAIS TU PERDS 1 POTION !

                        if(Sac.potion > 0){

                            Player1.barreHP += potionHealth;
                            Sac.potion --;

                        // A RENDRE ADAPTATIF

                        if(Player1.barreHP > Player1.hpbackUp){
                        Player1.barreHP = Player1.hpbackUp;
                        }
                        printf("\nYou now have %d health point\n", Player1.barreHP);
                        }

                        break;

                // CAS 2: POTION DE RENVOI DE SORT ( SP5 E BOUCLIER TU CONNAIS )

                case 2:

                    // SI TA PAS DE POTION: MESSAGE ERREUR PAS DE POTION

                    if(Sac.potionRenvoi == 0){
                        printf("You don't have any Return damage potion !\n\n");
                        Sleep(2000);
                    }

                    // SI TU AS UNE POTION: TU UTILISE LA FONCTION DEGAT POTION RENVOI ET TU PERD UNE POTION

                    if(Sac.potionRenvoi > 0){
                        printf("Prepare to fire the monster attack\n\n");
                        Sac.potionRenvoi--;
                        Sleep(2000);
                        printf("You have returned %d damage !\n", Monster1.degat);
                        degatPotionRenvoi();
                        Monster1.degat = degatBackupMonstreFaible;
                        Sleep(2000);
                        printf("The monster still has %d life left! \n", Monster1.barreHP);
                        Sleep(2000);
                    }
                    if(Monster1.barreHP <= 0){

                            printf("You have beaten the monster! \n");
                            printf("You won %d XP\n\n", xp);
                            stockXP += xp;
                            printf("Barre XP %d/%d \n\n", stockXP,Player1.barreXP1);
                            fincombat = 1;
                            Monster1.barreHP = hpBackupMonstreFaible;


                        if(stockXP >= Player1.barreXP2){
                            Player1.niveau++;
                            Player1.barreHP = backupHpLvl1 * Player1.niveau;
                            Player1.degat = Player1.degat * Player1.niveau;
                            printf("You are now level %d, Congratulations! \n", Player1.niveau);
                            printf("Your damage and your health level up too!\n\n");
                            printf("Health: %d\n", Player1.barreHP);
                            printf("Damage: %d\n", Player1.degat);
                            Sleep(2000);
                            printf("\nYou picked up a Return damage potion\n");
                            Sleep(2000);
                            Sac.potionRenvoi += 1;
                            fincombat = 1;




                        }
                    }
                        break;

                case 3:
                    // SI YA PAS DE POTION : MESSAGE ERREUR PAS DE POTION

                        if(Sac.potionAtk == 0){
                            printf("You don't have any health potion.");
                        }
                        if(Sac.potionAtk >0){
                                Sac.potionAtk--;
                                printf("You are going to attack!\n");
                                Sleep(2000);
                                printf("WOW! Your attack potion has done a lot of damage! \n");
                                degatPotionAtk();
                                Sleep(1000);
                                printf("The monster took %d damage !\n", Player1.degat);
                                Player1.degat = Player1.degatbackUp;
                                Sleep(2000);
                                printf("The monster still has %d life left! \n", Monster1.barreHP);
                                Sleep(2000);
                        }
                        if(Monster1.barreHP > 0){
                            printf("Be careful the monster replies! \n");
                            Sleep(2000);
                            degatMonstreFaible();
                            printf("The monster did %d damage!\n", Monster1.degat);
                            Monster1.degat = degatBackupMonstreFaible;
                            Sleep(1000);
                            printf("You have %d life left! \n", Player1.barreHP);

                        }
                        if(Monster1.barreHP <= 0){

                                printf("You have beaten the monster! \n");
                                printf("You won %d XP\n\n", xp);
                                stockXP += xp;
                                printf("Barre XP %d/%d", stockXP,Player1.barreXP1);
                                fincombat = 1;
                                Monster1.barreHP = hpBackupMonstreFaible;

                            if(stockXP >= Player1.barreXP1){
                                Player1.niveau++;
                                Player1.barreHP = backupHpLvl1 * Player1.niveau;
                                Player1.degat = Player1.degat * Player1.niveau;
                                printf("You are now level %d, Congratulations! \n", Player1.niveau);
                                Sleep(2000);
                                printf("Your damage and your health level up too!\n\n");
                                Sleep(1000);
                                printf("Health: %d\n", Player1.barreHP);
                                printf("Damage: %d\n", Player1.degat);
                                Sleep(2000);
                                fincombat = 1;

                            }

                        }
                        break;

                    case 4:
                        break;

                    }

            // PAS ENCORE FAIS MAIS C'EST POUR FUIR

                case 3:
//

                    break;


                }

           // TOUT CA A FAIRE TANT QUE TU N'AS PAS PERDU TOUTE TA VIE OU QUE LE MONSTRE N'EST PAS MORT

        }while(Player1.barreHP > 0 && fincombat == 0);
}



int combatAvecArcMonstreMoyen(){

do{
        switch(choixAction()){

            //CAS 1 COUP DE POING AU MONSTRE

            case 1:
                switch(ChoixAttack()){

            case 1:
                printf("You just punched the monster! \n");
                degatPersoMoyen();
                Sleep(1000);
                printf("The monster took %d damage !\n", Player1.degat);
                Player1.degat = Player1.degatbackUp;
                Sleep(2000);
                printf("The monster still has %d life left! \n", Monster2.barreHP);
                Sleep(2000);

                // SI LE MONSTRE A ENCORE DE LA VIE, IL ATTAQUE

                if(Monster2.barreHP > 0){
                    printf("Be careful the monster replies! \n");
                    Sleep(2000);
                    degatMonstreMoyen();
                    printf("The monster did %d damage!\n", Monster2.degat);
                    Monster2.degat = degatBackupMonstreMoyen;
                    Sleep(1000);
                    printf("You have %d life left! \n", Player1.barreHP);

                }

                // SI LE MONSTRE N'A PLUS DE VIE: MESSAGE POUR AFFICHER QUE TU L'AS BATTU

                if(Monster2.barreHP <= 0){

                        printf("\nYou have beaten the monster! \n");
                        printf("You won %d XP\n", xp);
                        stockXP += xp;
                        printf("Barre XP %d/%d\n\n", stockXP,Player1.barreXP3);
                        fincombat = 1;
                        Monster2.barreHP = hpBackupMonstreMoyen;

                    if(stockXP >= Player1.barreXP3){
                        Player1.niveau++;
                        Player1.barreHP = backupHpLvl1 * Player1.niveau;
                        Player1.degat = Player1.degat * Player1.niveau;
                        printf("You are now level %d, Congratulations! \n", Player1.niveau);
                        printf("Your damage and your health level up too!\n\n");
                        printf("Health: %d\n", Player1.barreHP);
                        printf("Damage: %d\n", Player1.degat);
                        Sleep(2000);
                        printf("\nYou picked up a potion\n");
                        Sleep(2000);

                        Sac.potion += 1;
                        fincombat = 1;

                    }
                }
                break;

            case 2:
                if(Sac.arc == 0){
                    printf("You don't have any bow to use this skill\n");
                }
                if(Sac.arc > 0){
                    printf("You throw a flaming arrow at the monster\n");
                    BowHitMoyen();
                    printf("The monster took %d damage !\n", Player1.degatArc);
                    Player1.degatArc = degatArcBackup;
                    Sleep(2000);
                    printf("The monster still has %d life left! \n\n", Monster2.barreHP);
                    Sleep(2000);
                }

                if(Monster2.barreHP > 0){
                    printf("Be careful the monster replies! \n");
                    Sleep(2000);
                    degatMonstreMoyen();
                    printf("The monster did %d damage!\n", Monster2.degat);
                    Monster2.degat = degatBackupMonstreMoyen;
                    Sleep(1000);
                    printf("You have %d life left! \n", Player1.barreHP);

                }
                if(Monster2.barreHP <= 0){

                        printf("\nYou have beaten the monster! \n");
                        printf("You won %d XP\n", xp);
                        stockXP += xp;
                        printf("Barre XP %d/%d\n\n", stockXP,Player1.barreXP3);
                        fincombat =1;
                        Monster2.barreHP = hpBackupMonstreMoyen;

                    if(stockXP >= Player1.barreXP3){
                        Player1.niveau++;
                        Player1.barreHP = backupHpLvl1 * Player1.niveau;
                        Player1.degat = Player1.degat * Player1.niveau;
                        printf("You are now level %d, Congratulations! \n", Player1.niveau);
                        printf("Your damage and your health level up too!\n\n");
                        printf("Health: %d\n", Player1.barreHP);
                        printf("Damage: %d\n", Player1.degat);
                        printf("\nYou picked up an Offensive potion\n");
                        Sleep(2000);
                        Sac.potionAtk += 1;
                        fincombat = 1;
                    }
                }

                }


                break;

                // CAS 2: OUVERTURE DE LINVENTAIRE
            case 2:

            // SWITCH FONCTION OPEN INVENTAIRE

                switch(OpenInventaire()){

                // CAS 1: UTILISATION D'UNE POTION DE SOIN
                    case 1:

                        // SI YA PAS DE POTION : MESSAGE ERREUR PAS DE POTION

                        if(Sac.potion == 0){
                            printf("You don't have any health potion.");
                        }

                        // SI YA DES POTIONS : TU GAGNES DES HP MAIS TU PERDS 1 POTION !

                        if(Sac.potion > 0){

                            Player1.barreHP += potionHealth;
                            Sac.potion --;

                        // A RENDRE ADAPTATIF

                        if(Player1.barreHP > Player1.hpbackUp){
                        Player1.barreHP = Player1.hpbackUp;
                        }
                        printf("\nYou now have %d health point\n", Player1.barreHP);
                        }

                        break;

                // CAS 2: POTION DE RENVOI DE SORT ( SP5 E BOUCLIER TU CONNAIS )

                case 2:

                    // SI TA PAS DE POTION: MESSAGE ERREUR PAS DE POTION

                    if(Sac.potionRenvoi == 0){
                        printf("You don't have any Return damage potion !\n\n");
                        Sleep(2000);
                    }

                    // SI TU AS UNE POTION: TU UTILISE LA FONCTION DEGAT POTION RENVOI ET TU PERD UNE POTION

                    if(Sac.potionRenvoi > 0){
                        printf("Prepare to fire the monster attack\n\n");
                        Sac.potionRenvoi--;
                        Sleep(2000);
                        printf("You have returned %d damage !\n", Monster2.degat);
                        degatPotionRenvoiMoyen();
                        Monster2.degat = degatBackupMonstreMoyen;
                        Sleep(2000);
                        printf("The monster still has %d life left! \n", Monster2.barreHP);
                        Sleep(2000);
                    }
                    if(Monster2.barreHP <= 0){

                            printf("You have beaten the monster! \n");
                            printf("You won %d XP\n\n", xp);
                            stockXP += xp;
                            printf("Barre XP %d/%d \n\n", stockXP,Player1.barreXP3);
                            fincombat = 1;
                            Monster2.barreHP = hpBackupMonstreMoyen;


                        if(stockXP >= Player1.barreXP3){
                            Player1.niveau++;
                            Player1.barreHP = backupHpLvl1 * Player1.niveau;
                            Player1.degat = Player1.degat * Player1.niveau;
                            printf("You are now level %d, Congratulations! \n", Player1.niveau);
                            printf("Your damage and your health level up too!\n\n");
                            printf("Health: %d\n", Player1.barreHP);
                            printf("Damage: %d\n", Player1.degat);
                            Sleep(2000);
                            printf("\nYou picked up a Return damage potion\n");
                            Sleep(2000);
                            Sac.potionRenvoi += 1;
                            fincombat = 1;




                        }
                    }
                        break;

                case 3:
                    // SI YA PAS DE POTION : MESSAGE ERREUR PAS DE POTION

                        if(Sac.potionAtk == 0){
                            printf("You don't have any health potion.");
                        }
                        if(Sac.potionAtk >0){
                                Sac.potionAtk--;
                                printf("You are going to attack!\n");
                                Sleep(2000);
                                printf("WOW! Your attack potion has done a lot of damage! \n");
                                degatPotionAtkMoyen();
                                Sleep(1000);
                                printf("The monster took %d damage !\n", Player1.degat);
                                Player1.degat = Player1.degatbackUp;
                                Sleep(2000);
                                printf("The monster still has %d life left! \n", Monster2.barreHP);
                                Sleep(2000);
                        }
                        if(Monster2.barreHP > 0){
                            printf("Be careful the monster replies! \n");
                            Sleep(2000);
                            degatMonstreFaible();
                            printf("The monster did %d damage!\n", Monster2.degat);
                            Monster2.degat = degatBackupMonstreMoyen;
                            Sleep(1000);
                            printf("You have %d life left! \n", Player1.barreHP);

                        }
                        if(Monster2.barreHP <= 0){

                                printf("You have beaten the monster! \n");
                                printf("You won %d XP\n\n", xp);
                                stockXP += xp;
                                printf("Barre XP %d/%d", stockXP,Player1.barreXP1);
                                Sac.potionAtk += 1;
                                fincombat = 1;
                                Monster2.barreHP = hpBackupMonstreMoyen;

                            if(stockXP >= Player1.barreXP3){
                                Player1.niveau++;
                                Player1.barreHP = backupHpLvl1 * Player1.niveau;
                                Player1.degat = Player1.degat * Player1.niveau;
                                printf("You are now level %d, Congratulations! \n", Player1.niveau);
                                Sleep(2000);
                                printf("Your damage and your health level up too!\n\n");
                                Sleep(1000);
                                printf("Health: %d\n", Player1.barreHP);
                                printf("Damage: %d\n", Player1.degat);
                                Sleep(2000);
                                Sac.potion +=1;
                                fincombat = 1;

                            }

                        }
                        break;

                    case 4:
                        break;

                    }

            // PAS ENCORE FAIS MAIS C'EST POUR FUIR

                case 3:
//
                    break;


            }

           // TOUT CA A FAIRE TANT QUE TU N'AS PAS PERDU TOUTE TA VIE OU QUE LE MONSTRE N'EST PAS MORT

        }while(Player1.barreHP > 0 && fincombat == 0);

}

int combatAvecArcMonstreFort(){

do{
        switch(choixAction()){

            //CAS 1 COUP DE POING AU MONSTRE

            case 1:
                switch(ChoixAttack()){

            case 1:
                printf("You just punched the monster! \n");
                degatPersoFort();
                Sleep(1000);
                printf("The monster took %d damage !\n", Player1.degat);
                Player1.degat = Player1.degatbackUp;
                Sleep(2000);
                printf("The monster still has %d life left! \n", Monster3.barreHP);
                Sleep(2000);

                // SI LE MONSTRE A ENCORE DE LA VIE, IL ATTAQUE

                if(Monster3.barreHP > 0){
                    printf("Be careful the monster replies! \n");
                    Sleep(2000);
                    degatMonstreFort();
                    printf("The monster did %d damage!\n", Monster3.degat);
                    Monster3.degat = degatBackupMonstreFort;
                    Sleep(1000);
                    printf("You have %d life left! \n", Player1.barreHP);

                }

                // SI LE MONSTRE N'A PLUS DE VIE: MESSAGE POUR AFFICHER QUE TU L'AS BATTU

                if(Monster3.barreHP <= 0){

                        printf("\nYou have beaten the monster! \n");
                        printf("You won %d XP\n", xp);
                        stockXP += xp;
                        printf("Barre XP %d/%d\n\n", stockXP,Player1.barreXP3);
                        Sac.potion += 1;
                        fincombat = 1;
                        Monster3.barreHP = hpBackupMonstreFort;


                    if(stockXP >= Player1.barreXP3){
                        Player1.niveau++;
                        Player1.barreHP = backupHpLvl1 * Player1.niveau;
                        Player1.degat = Player1.degat * Player1.niveau;
                        printf("You are now level %d, Congratulations! \n", Player1.niveau);
                        printf("Your damage and your health level up too!\n\n");
                        printf("Health: %d\n", Player1.barreHP);
                        printf("Damage: %d\n", Player1.degat);
                        Sleep(2000);
                        printf("\nYou picked up a potion\n");
                        Sleep(2000);

                        Sac.potion += 1;
                        fincombat = 1;

                    }
                }
                break;

            case 2:
                if(Sac.arc == 0){
                    printf("You don't have any bow to use this skill\n");
                }
                if(Sac.arc > 0){
                    printf("You throw a flaming arrow at the monster\n");
                    BowHitFort();
                    printf("The monster took %d damage !\n", Player1.degatArc);
                    Player1.degatArc = degatArcBackup;
                    Sleep(2000);
                    printf("The monster still has %d life left! \n\n", Monster3.barreHP);
                    Sleep(2000);
                }

                if(Monster3.barreHP > 0){
                    printf("Be careful the monster replies! \n");
                    Sleep(2000);
                    degatMonstreFort();
                    printf("The monster did %d damage!\n", Monster3.degat);
                    Monster3.degat = degatBackupMonstreFort;
                    Sleep(1000);
                    printf("You have %d life left! \n", Player1.barreHP);

                }
                if(Monster3.barreHP <= 0){

                        printf("\nYou have beaten the monster! \n");
                        printf("You won %d XP\n", xp);
                        stockXP += xp;
                        printf("Barre XP %d/%d\n\n", stockXP,Player1.barreXP3);
                        fincombat =1;
                        Monster3.barreHP = hpBackupMonstreFort;
                        Sac.potionAtk += 1;

                    if(stockXP >= Player1.barreXP3){
                        Player1.niveau++;
                        Player1.barreHP = backupHpLvl1 * Player1.niveau;
                        Player1.degat = Player1.degat * Player1.niveau;
                        printf("You are now level %d, Congratulations! \n", Player1.niveau);
                        printf("Your damage and your health level up too!\n\n");
                        printf("Health: %d\n", Player1.barreHP);
                        printf("Damage: %d\n", Player1.degat);
                        printf("\nYou picked up an Offensive potion\n");
                        Sleep(2000);
                        Sac.potionAtk += 1;
                        fincombat = 1;
                    }
                }

                }


                break;

                // CAS 2: OUVERTURE DE LINVENTAIRE
            case 2:

            // SWITCH FONCTION OPEN INVENTAIRE

                switch(OpenInventaire()){

                // CAS 1: UTILISATION D'UNE POTION DE SOIN
                    case 1:

                        // SI YA PAS DE POTION : MESSAGE ERREUR PAS DE POTION

                        if(Sac.potion == 0){
                            printf("You don't have any health potion.");
                        }

                        // SI YA DES POTIONS : TU GAGNES DES HP MAIS TU PERDS 1 POTION !

                        if(Sac.potion > 0){

                            Player1.barreHP += potionHealth;
                            Sac.potion --;

                        // A RENDRE ADAPTATIF

                        if(Player1.barreHP > Player1.hpbackUp){
                        Player1.barreHP = Player1.hpbackUp;
                        }
                        printf("\nYou now have %d health point\n", Player1.barreHP);
                        }

                        break;

                // CAS 2: POTION DE RENVOI DE SORT ( SP5 E BOUCLIER TU CONNAIS )

                case 2:

                    // SI TA PAS DE POTION: MESSAGE ERREUR PAS DE POTION

                    if(Sac.potionRenvoi == 0){
                        printf("You don't have any Return damage potion !\n\n");
                        Sleep(2000);
                    }

                    // SI TU AS UNE POTION: TU UTILISE LA FONCTION DEGAT POTION RENVOI ET TU PERD UNE POTION

                    if(Sac.potionRenvoi > 0){
                        printf("Prepare to fire the monster attack\n\n");
                        Sac.potionRenvoi--;
                        Sleep(2000);
                        printf("You have returned %d damage !\n", Monster3.degat);
                        degatPotionRenvoiFort();
                        Monster3.degat = degatBackupMonstreFort;
                        Sleep(2000);
                        printf("The monster still has %d life left! \n", Monster3.barreHP);
                        Sleep(2000);
                    }
                    if(Monster3.barreHP <= 0){

                            printf("You have beaten the monster! \n");
                            printf("You won %d XP\n\n", xp);
                            stockXP += xp;
                            printf("Barre XP %d/%d \n\n", stockXP,Player1.barreXP3);
                            fincombat = 1;
                            Sac.potionRenvoi += 1;
                            Monster3.barreHP = hpBackupMonstreFort;


                        if(stockXP >= Player1.barreXP3){
                            Player1.niveau++;
                            Player1.barreHP = backupHpLvl1 * Player1.niveau;
                            Player1.degat = Player1.degat * Player1.niveau;
                            printf("You are now level %d, Congratulations! \n", Player1.niveau);
                            printf("Your damage and your health level up too!\n\n");
                            printf("Health: %d\n", Player1.barreHP);
                            printf("Damage: %d\n", Player1.degat);
                            Sleep(2000);
                            printf("\nYou picked up a Return damage potion\n");
                            Sleep(2000);
                            Sac.potionRenvoi += 1;
                            fincombat = 1;




                        }
                    }
                        break;

                case 3:
                    // SI YA PAS DE POTION : MESSAGE ERREUR PAS DE POTION

                        if(Sac.potionAtk == 0){
                            printf("You don't have any health potion.");
                        }
                        if(Sac.potionAtk >0){
                                Sac.potionAtk--;
                                printf("You are going to attack!\n");
                                Sleep(2000);
                                printf("WOW! Your attack potion has done a lot of damage! \n");
                                degatPotionAtkFort();
                                Sleep(1000);
                                printf("The monster took %d damage !\n", Player1.degat);
                                Player1.degat = Player1.degatbackUp;
                                Sleep(2000);
                                printf("The monster still has %d life left! \n", Monster3.barreHP);
                                Sleep(2000);
                        }
                        if(Monster3.barreHP > 0){
                            printf("Be careful the monster replies! \n");
                            Sleep(2000);
                            degatMonstreFaible();
                            printf("The monster did %d damage!\n", Monster3.degat);
                            Monster3.degat = degatBackupMonstreFort;
                            Sleep(1000);
                            printf("You have %d life left! \n", Player1.barreHP);

                        }
                        if(Monster3.barreHP <= 0){

                                printf("You have beaten the monster! \n");
                                printf("You won %d XP\n\n", xp);
                                stockXP += xp;
                                printf("Barre XP %d/%d", stockXP,Player1.barreXP3);
                                fincombat = 1;
                                Monster3.barreHP = hpBackupMonstreFort;

                            if(stockXP >= Player1.barreXP3){
                                Player1.niveau++;
                                Player1.barreHP = backupHpLvl1 * Player1.niveau;
                                Player1.degat = Player1.degat * Player1.niveau;
                                printf("You are now level %d, Congratulations! \n", Player1.niveau);
                                Sleep(2000);
                                printf("Your damage and your health level up too!\n\n");
                                Sleep(1000);
                                printf("Health: %d\n", Player1.barreHP);
                                printf("Damage: %d\n", Player1.degat);
                                Sleep(2000);
                                fincombat = 1;

                            }

                        }
                        break;

                    case 4:
                        break;

                    }

            // PAS ENCORE FAIS MAIS C'EST POUR FUIR

                case 3:

                    break;


            }

           // TOUT CA A FAIRE TANT QUE TU N'AS PAS PERDU TOUTE TA VIE OU QUE LE MONSTRE N'EST PAS MORT

        }while(Player1.barreHP > 0 && fincombat == 0);
}

int combatBoss(){

do{
        switch(choixAction()){

            //CAS 1 COUP DE POING AU MONSTRE

            case 1:

                switch(ChoixAttack()){

            case 1:
                printf("You just punched the monster! \n");
                degatPersoBoss();
                Sleep(1000);
                printf("The monster took %d damage !\n", Player1.degat);
                Player1.degat = Player1.degatbackUp;
                Sleep(2000);
                printf("The monster still has %d life left! \n", MonsterBoss.barreHP);
                Sleep(2000);

                // SI LE MONSTRE A ENCORE DE LA VIE, IL ATTAQUE

                if(MonsterBoss.barreHP > 0){
                    printf("Be careful the monster replies! \n");
                    Sleep(2000);
                    degatMonstreBoss();
                    printf("The monster did %d damage!\n", MonsterBoss.degat);
                    MonsterBoss.degat = degatBackupMonstreBoss;
                    Sleep(1000);
                    printf("You have %d life left! \n", Player1.barreHP);

                }

                // SI LE MONSTRE N'A PLUS DE VIE: MESSAGE POUR AFFICHER QUE TU L'AS BATTU

                if(MonsterBoss.barreHP <= 0){

                        printf("\nYou have beaten the monster! \n");
                        printf("You won %d XP\n", xp);
                        stockXP += xp;
                        printf("Barre XP %d/%d\n\n", stockXP,Player1.barreXP3);
                        fincombat = 1;
                        MonsterBoss.barreHP = hpBackupMonstreBoss;
                        printf("\n\n GG !!!! YOU JUST KILLED THE BOSS !");
                        exit(0);

                    if(stockXP >= Player1.barreXP3){
                        Player1.niveau++;
                        Player1.barreHP = backupHpLvl1 * Player1.niveau;
                        Player1.degat = Player1.degat * Player1.niveau;
                        printf("You are now level %d, Congratulations! \n", Player1.niveau);
                        printf("Your damage and your health level up too!\n\n");
                        printf("Health: %d\n", Player1.barreHP);
                        printf("Damage: %d\n", Player1.degat);
                        Sleep(2000);
                        printf("\nYou picked up a potion\n");
                        Sleep(2000);

                        Sac.potion += 1;
                        fincombat = 1;

                    }
                }
                break;

            case 2:
                if(Sac.arc == 0){
                    printf("You don't have any bow to use this skill\n");
                }
                if(Sac.arc > 0){
                    printf("You throw a flaming arrow at the monster\n");
                    BowHit();
                    printf("The monster took %d damage !\n", Player1.degatArc);
                    Player1.degatArc = degatArcBackup;
                    Sleep(2000);
                    printf("The monster still has %d life left! \n\n", Monster1.barreHP);
                    Sleep(2000);
                }

                if(MonsterBoss.barreHP > 0){
                    printf("Be careful the monster replies! \n");
                    Sleep(2000);
                    degatMonstreBoss();
                    printf("The monster did %d damage!\n", MonsterBoss.degat);
                    MonsterBoss.degat = degatBackupMonstreBoss;
                    Sleep(1000);
                    printf("You have %d life left! \n", Player1.barreHP);

                }
                if(MonsterBoss.barreHP <= 0){

                        printf("\nYou have beaten the monster! \n");
                        printf("You won %d XP\n", xp);
                        stockXP += xp;
                        printf("Barre XP %d/%d\n\n", stockXP,Player1.barreXP3);
                        fincombat =1;
                        MonsterBoss.barreHP = hpBackupMonstreBoss;
                        printf("\n\n GG !!!! YOU JUST KILLED THE BOSS !");
                        exit(0);

                    if(stockXP >= Player1.barreXP3){
                        Player1.niveau++;
                        Player1.barreHP = backupHpLvl1 * Player1.niveau;
                        Player1.degat = Player1.degat * Player1.niveau;
                        printf("You are now level %d, Congratulations! \n", Player1.niveau);
                        printf("Your damage and your health level up too!\n\n");
                        printf("Health: %d\n", Player1.barreHP);
                        printf("Damage: %d\n", Player1.degat);
                        printf("\nYou picked up an Offensive potion\n");
                        Sleep(2000);
                        Sac.potionAtk += 1;
                        fincombat = 1;
                    }
                }

                }



                break;

                // CAS 2: OUVERTURE DE LINVENTAIRE
            case 2:

            // SWITCH FONCTION OPEN INVENTAIRE

                switch(OpenInventaire()){

                // CAS 1: UTILISATION D'UNE POTION DE SOIN
                    case 1:

                        // SI YA PAS DE POTION : MESSAGE ERREUR PAS DE POTION

                        if(Sac.potion == 0){
                            printf("You don't have any health potion.");
                        }

                        // SI YA DES POTIONS : TU GAGNES DES HP MAIS TU PERDS 1 POTION !

                        if(Sac.potion > 0){

                            Player1.barreHP += potionHealth;
                            Sac.potion --;

                        // A RENDRE ADAPTATIF

                        if(Player1.barreHP > Player1.hpbackUp){
                        Player1.barreHP = Player1.hpbackUp;
                        }
                        printf("\nYou now have %d health point\n", Player1.barreHP);
                        }

                        break;

                // CAS 2: POTION DE RENVOI DE SORT ( SP5 E BOUCLIER TU CONNAIS )

                case 2:

                    // SI TA PAS DE POTION: MESSAGE ERREUR PAS DE POTION

                    if(Sac.potionRenvoi == 0){
                        printf("You don't have any Return damage potion !\n\n");
                        Sleep(2000);
                    }

                    // SI TU AS UNE POTION: TU UTILISE LA FONCTION DEGAT POTION RENVOI ET TU PERD UNE POTION

                    if(Sac.potionRenvoi > 0){
                        printf("Prepare to fire the monster attack\n\n");
                        Sac.potionRenvoi--;
                        Sleep(2000);
                        printf("You have returned %d damage !\n", MonsterBoss.degat);
                        degatPotionRenvoiBoss();
                        MonsterBoss.degat = degatBackupMonstreBoss;
                        Sleep(2000);
                        printf("The monster still has %d life left! \n", MonsterBoss.barreHP);
                        Sleep(2000);
                    }
                    if(MonsterBoss.barreHP <= 0){

                            printf("You have beaten the monster! \n");
                            printf("You won %d XP\n\n", xp);
                            stockXP += xp;
                            printf("Barre XP %d/%d \n\n", stockXP,Player1.barreXP3);
                            fincombat = 1;
                            MonsterBoss.barreHP = hpBackupMonstreBoss;
                            printf("\n\n GG !!!! YOU JUST KILLED THE BOSS !");
                            exit(0);


                        if(stockXP >= Player1.barreXP3){
                            Player1.niveau++;
                            Player1.barreHP = backupHpLvl1 * Player1.niveau;
                            Player1.degat = Player1.degat * Player1.niveau;
                            printf("You are now level %d, Congratulations! \n", Player1.niveau);
                            printf("Your damage and your health level up too!\n\n");
                            printf("Health: %d\n", Player1.barreHP);
                            printf("Damage: %d\n", Player1.degat);
                            Sleep(2000);
                            printf("\nYou picked up a Return damage potion\n");
                            Sleep(2000);
                            Sac.potionRenvoi += 1;
                            fincombat = 1;




                        }
                    }
                        break;

                case 3:
                    // SI YA PAS DE POTION : MESSAGE ERREUR PAS DE POTION

                        if(Sac.potionAtk == 0){
                            printf("You don't have any health potion.");
                        }
                        if(Sac.potionAtk >0){
                                Sac.potionAtk--;
                                printf("You are going to attack!\n");
                                Sleep(2000);
                                printf("WOW! Your attack potion has done a lot of damage! \n");
                                degatPotionAtkBoss();
                                Sleep(1000);
                                printf("The monster took %d damage !\n", Player1.degat);
                                Player1.degat = Player1.degatbackUp;
                                Sleep(2000);
                                printf("The monster still has %d life left! \n", MonsterBoss.barreHP);
                                Sleep(2000);
                        }
                        if(Monster1.barreHP > 0){
                            printf("Be careful the monster replies! \n");
                            Sleep(2000);
                            degatMonstreFaible();
                            printf("The monster did %d damage!\n", MonsterBoss.degat);
                            MonsterBoss.degat = degatBackupMonstreBoss;
                            Sleep(1000);
                            printf("You have %d life left! \n", Player1.barreHP);

                        }
                        if(MonsterBoss.barreHP <= 0){

                                printf("You have beaten the monster! \n");
                                printf("You won %d XP\n\n", xp);
                                stockXP += xp;
                                printf("Barre XP %d/%d", stockXP,Player1.barreXP3);
                                fincombat = 1;
                                MonsterBoss.barreHP = hpBackupMonstreBoss;
                                printf("\n\n GG !!!! YOU JUST KILLED THE BOSS !");
                                exit(0);

                            if(stockXP >= Player1.barreXP3){
                                Player1.niveau++;
                                Player1.barreHP = backupHpLvl1 * Player1.niveau;
                                Player1.degat = Player1.degat * Player1.niveau;
                                printf("You are now level %d, Congratulations! \n", Player1.niveau);
                                Sleep(2000);
                                printf("Your damage and your health level up too!\n\n");
                                Sleep(1000);
                                printf("Health: %d\n", Player1.barreHP);
                                printf("Damage: %d\n", Player1.degat);
                                Sleep(2000);
                                fincombat = 1;

                            }

                        }
                        break;

                    case 4:
                        break;

                    }

            // PAS ENCORE FAIS MAIS C'EST POUR FUIR

                case 3:

                    break;


                }

           // TOUT CA A FAIRE TANT QUE TU N'AS PAS PERDU TOUTE TA VIE OU QUE LE MONSTRE N'EST PAS MORT

        }while(Player1.barreHP > 0 && fincombat == 0);
}





void fonctionCase(){

if (y == 0 && x == 0){
    if(dejapasse00 == 1){
            printf("You have been already here.. ");
            cartographie();

}

}

if(y == 0 && x == 1){
    if(dejapasse01 == 1){
            printf("You have been already here.. ");
            cartographie();

}
else{

    fincombat = 0;
    annonceMonstreFaible();
    while(fincombat == 0){
    combatAvecArc();
    }
    fincombat = 0;
    dejapasse01 = 1;

    cartographie();
}


}
if (y == 0 && x == 2){
        if(dejapasse02 == 1){
            printf("You have been already here.. ");
            cartographie();

}
else{

    annonceMonstreFaible();
    while(fincombat == 0){
    combatAvecArc();
    }
    fincombat = 0;
    dejapasse02 = 1;
    cartographie();
}
}

if(y == 1 && x == 0){
    if(dejapasse10 == 1){
            printf("You have been already here.. ");
            cartographie();

}
 else{
    fincombat = 0;
    annonceMonstreFaible();
    while(fincombat == 0){
    combatAvecArc();
    }
    fincombat = 0;
    dejapasse10 = 1;
    cartographie();
 }
}

if(y == 2 && x == 0){
        if(dejapasse20 == 1){
            printf("You have been already here.. ");
            cartographie();

}
else{
    annonceMonstreFaible();
    while(fincombat==0){
    combatAvecArc();
    }
    fincombat = 0;
    dejapasse20 = 1;
    cartographie();
}
}

if( y == 1 && x == 1){
        if(dejapasse11 == 1){
            printf("You have been already here.. ");
            cartographie();

}
else{
    annonceMonstreFaible();
    while(fincombat == 0){
    combatAvecArc();
    }
    fincombat = 0;
    dejapasse11 = 1;
    exit(0);
}
}






if(x == 3 && y == 0){
        if(dejapasse03 == 1){
            printf("You have been already here.. ");
            cartographie();

}
else{
    annonceMonstreMoyen();
    while(fincombat == 0){
    combatAvecArcMonstreMoyen();
    }
    fincombat = 0;
    dejapasse03 = 1;
    cartographie();
}
}


if(x == 3 && y == 1){
        if(dejapasse13 == 1){
            printf("You have been already here.. ");
            cartographie();

}
else{

    annonceMonstreMoyen();
    while(fincombat == 0){
    combatAvecArcMonstreMoyen();
    }
    fincombat = 0;
    dejapasse13 = 1;
    cartographie();

}
}


if(x == 2 && y == 1 ){
        if(dejapasse12 == 1){
            printf("You have been already here.. ");
            cartographie();

}
else{
    annonceMonstreMoyen();
    while(fincombat==0){
    combatAvecArcMonstreMoyen();
    }
    fincombat = 0;
    dejapasse12 = 1;
    cartographie();

}
}

if(x == 2 && y ==2){
        if(dejapasse22 == 1){
            printf("You have been already here.. ");
            cartographie();

}
else{
    annonceMonstreMoyen();
    while(fincombat==0){
    combatAvecArcMonstreMoyen();
    }
    fincombat = 0;
    dejapasse22 = 1;
    cartographie();
}

}
    if(x == 1 && y == 2){
            if(dejapasse21 == 1){
            printf("You have been already here.. ");
            cartographie();

}
else{
    annonceMonstreMoyen();
    while(fincombat==0){
    combatAvecArcMonstreMoyen();
    }
    fincombat = 0;
    dejapasse21 = 1;
    cartographie();
}


}

    if(x == 1 && y == 3){
            if(dejapasse31 == 1){
            printf("You have been already here.. ");
            cartographie();

}
else{
    annonceMonstreMoyen();
    while(fincombat==0){
    combatAvecArcMonstreMoyen();
    }
    fincombat = 0;
    dejapasse31 = 1;
    cartographie();

}
    }

    if(y == 3 && x == 0){
            if(dejapasse30 == 1){
            printf("You have been already here.. ");
            cartographie();

}
else{
    annonceMonstreMoyen();
    while(fincombat==0){
    combatAvecArcMonstreMoyen();
    }
    fincombat = 0;
    dejapasse30 = 1;
    cartographie();

}
}






    if(x == 3 && y == 2){
            if(dejapasse23 == 1){
            printf("You have been already here.. ");
            cartographie();

}
else{

        annonceMonstreFort();
        while(fincombat==0){
        combatAvecArcMonstreFort();
        }
        fincombat = 0;
        dejapasse23 = 1;
        cartographie();
        }
    }




    if(x == 2 && y == 3){
            if(dejapasse32 == 1){
            printf("You have been already here.. ");
            cartographie();

}
else{
        annonceMonstreFort();
        while(fincombat==0){
        combatAvecArcMonstreFort();
        }
        fincombat = 0;
        dejapasse32 = 1;
        cartographie();
    }
    }




    if(x==3 && y==3){
        annonceMonstreBoss();
        while(fincombat==0){
        combatBoss();
        }




}

return 0;
}



void annonceMonstreFaible(void){

            printf("\nYou are traveling in a dark place, surrounded by strange noise.\n");
            Sleep(2000);
            printf("Suddenly, a weak monster, you must defeat it! \n");
            Sleep(2000);
            color(4,0);
            printf("It's a level 5 monster !! \n\n");
            color(7,0);
            Sleep(1000);
}

void annonceMonstreMoyen(void){

    printf("\nYou travel and arrive in a cave, the bats circle around you.\n");
    Sleep(2000);
    printf("Suddenly, a medium monster, you must defeat it! \n");
    Sleep(2000);
    color(4,0);
    printf("It's a level 10 monster !! \n\n");
    color(7,0);
    Sleep(1000);


}

void annonceMonstreFort(void){

    printf("\nYou travel through the mountains and enter an abandoned warehouse.\n");
    Sleep(2000);
    printf("Suddenly, an hard monster, you must defeat it! \n");
    Sleep(2000);
    color(4,0);
    printf("It's a level 20 monster !! \n\n");
    color(7,0);
    Sleep(1000);


}

void annonceMonstreBoss(void){

    printf("\nYou travel through the mountains and enter an abandoned warehouse.\n");
    Sleep(2000);
    printf("Suddenly, THE BOSS IS COMING , you must defeat it! \n");
    Sleep(2000);
    color(4,0);
    printf("It's a level 50 monster !! \n\n");
    color(7,0);
    Sleep(1000);



}









