#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "champion.h"


int main(int argc, char* argv[]){

    int n;

    if (argc != 2) {
        printf ("Error: Invalid number of command line arguments\n");
        exit(1);
    }else{
   n = atoi(argv[1]);
    // check if n is positive
    if (n < 1){
        printf("ERROR: Problem with arguments");
        exit(1);
        }
    }
    
    Champion* player1 = buildChampionList(n);
    Champion* player2 = buildChampionList(n);
    
    printf("Peyton Malveaux\n");
    printf("============= PLAYER 1 V PLAYER 2 SHOWDOWN ============\n\n");
    
   


int i = 0;

    while(player1 != NULL && player2 != NULL){
        
        printf("-----Round %d-----\n", i);
        //printf("")
        printf("Player 1 Current Champions: ");
        printChampionList(player1);
        printf("\n");
        
        printf("Player 2 Current Champions: ");
        printChampionList(player2);
        printf("\n");
        
         int level1 = player1->level;
         int level2 = player2->level;

         ChampionRoll roll1 = player1->roll;
         ChampionRoll roll2 = player2->roll;
//__________________MAGE & MAGE__________________________
         if(roll1 == MAGE && roll2 == MAGE){
            printf("Player 1: MAGE || Player 2: MAGE\n");
                if(level1 > level2){
                    printf("Player 1 WINS (P1: +1, P2: -1)\n\n");
                    Champion* champ = createChampion();
                    champ = addChampion(player1, champ);
                    removeChampion(player2);
                }if(level2 > level1){
                    printf("Player 2 WINS (P1: -1, P2: +1)\n\n");
                    Champion* champ = createChampion();
                    champ = addChampion(player2, champ);
                    removeChampion(player1);
                }if(level1 == level2){
                    printf("TIE\n\n");
                    }
         }
//___________________MAGE AND FIGHTER_______________________
         else if(roll1 == MAGE && roll2 == FIGHTER){
            printf("Player 1: MAGE || Player 2: FIGHTER\n");
                if(level1 > level2){
                    printf("Player 1 WINS (P1: +1)\n\n");
                    Champion* champ = createChampion();
                    champ = addChampion(player1, champ);
                }if(level2 > level1){
                    printf("Player 2 WINS (P1: -1)\n\n");
                    removeChampion(player1);
                }if(level1 == level2){
                    printf("TIE\n\n");
                }

         }else if(roll2 == MAGE && roll1 == FIGHTER){
            printf("Player 1: FIGHTER || Player 2: MAGE\n");
                if(level2 > level1){
                    printf("Player 2 WINS (P2: +1)\n\n");
                    Champion* champ = createChampion();
                    champ = addChampion(player2, champ);
                }if(level1 > level2){
                    printf("Player 1 WINS (P2: -1)\n\n");
                    removeChampion(player2);
                }if(level1 == level2){
                    printf("TIE\n\n");
                }
         }
//_______________________MAGE AND SUPPORT_________________________
         else if(roll1 == MAGE && roll2 == SUPPORT){
            printf("Player 1: MAGE || Player 2: SUPPORT\n");
            if(level1 > level2){
                    printf("Player 1 WINS (P1: +1, P2: -2)\n\n");
                    Champion* champ = createChampion();
                    champ = addChampion(player1, champ);
                    removeChampion(player2);
                    removeChampion(player2);
            }if(level2 > level1){
                    printf("Player 2 WINS (P1: -2, P2: +2)\n\n");
                    Champion* champ = createChampion();
                    champ = addChampion(player2, champ);
                    Champion* champ2 = createChampion();
                    champ2 = addChampion(player2, champ2);
                    removeChampion(player1);
            }if(level1==level2){
                    printf("TIE\n\n");
            }
         }else if(roll2 == MAGE && roll1 == SUPPORT){
            printf("Player 1: SUPPORT || Player 2: MAGE\n");
                if(level2 > level1){
                    printf("Player 2 WINS (P1: -2, P1: +1)\n\n");
                    Champion* champ = createChampion();
                    champ = addChampion(player1, champ);
                    removeChampion(player1);
                    removeChampion(player1);
                }if(level1 > level2){
                    printf("Player 1 WINS (P1: +2, P2: -1)\n\n");
                    Champion* champ = createChampion();
                    champ = addChampion(player1, champ);
                    Champion* champ2 = createChampion();
                    champ2 = addChampion(player1, champ2);
                    removeChampion(player2);
                }else{
                    printf("TIE\n\n");
                }
        }
//_______________________MAGE AND TANK_______________________
        else if(roll1 == MAGE && roll2 == TANK){
            printf("Player 1 : MAGE || Player 2 : TANK\n");
            printf("Player 1 WINS (P1: +1)\n\n");
            Champion* champ = createChampion();
            champ = addChampion(player1, champ);
            removeChampion(player2);
        }else if(roll2 == MAGE&&roll1 == TANK){
            printf("Player 1 : TANK || Player 2 : MAGE\n");
            printf("Player 2 WINS (P2: +1)\n\n");
            Champion* champ = createChampion();
            champ = addChampion(player2, champ);
            removeChampion(player1);
        }
//_________________FIGHTER AND FIGHTER________________________
        else if(roll1 == FIGHTER && roll2 == FIGHTER){
            printf("Player 1 : FIGHTER || Player 2 : FIGHTER\n(+1) For Both Players\n\n");
                Champion* champ = createChampion();
                champ = addChampion(player1, champ);
                Champion* champ2 = createChampion();
                champ2 = addChampion(player2, champ2);
        }
//____________________FIGHTER AND SUPPORT____________________
        else if(roll1 == FIGHTER && roll2 == SUPPORT){
            printf("Player 1 : FIGHTER || Player 2 : SUPPORT");
                if(level1 > level2){
                    printf("Player 1 WINS (P2: -1)\n\n");
                    removeChampion(player2);
                }else if(level2 > level1){
                    printf("Player 2 WINS (P2: +1)\n\n");
                    Champion* champ = createChampion();
                    champ = addChampion(player2, champ);
                }else{
                    printf("TIE\n\n");
                }
        }else if(roll2 == FIGHTER && roll1 == SUPPORT){
            printf("Player 1 : SUPPORT || Player 2 : FIGHTER");
                if(level2 > level1){
                    printf("Player 2 WINS (P1: -1)\n\n");
                    removeChampion(player1);
                }else if(level1 > level2){
                    printf("Player 1 WINS (P1: +1)\n\n");
                    Champion* champ = createChampion();
                    champ = addChampion(player1, champ);
                }else{
                    printf("TIE\n\n");
                }
        }
//__________________________________FIGHETER AND TANK________________________________
        else if(roll1 == FIGHTER && roll2 == TANK){
            printf("Player 1 : FIGHTER || Player 2 : TANK\n");
                printf("Player 1 WINS (P1: +1)\n\n");
                Champion* champ = createChampion();
                champ = addChampion(player1, champ);
        }else if(roll2 == FIGHTER && roll1 == TANK){
            printf("Player 1 : TANK || Player 2 : FIGHTER\n");
                printf("Player 2 WINS (P2: +1)\n\n");
                Champion* champ = createChampion();
                champ = addChampion(player2, champ);
        }
//________________________________SUPPORT AND TANK____________________________________
        else if(roll1 == SUPPORT && roll2 == TANK){
            printf("Player 1 : SUPPORT || Player 2 : TANK\n");
                printf("Everyone Loses 1\n\n");
                removeChampion(player1);
                removeChampion(player2);

        }
//________________________________TANK AND TANK_______________________________________
        else{
            printf("Player 1 : TANK || Player 2 : TANK\nNothing Happens\n\n");
        }
      
        player1 = player1->next;
        player2 = player2->next;

        if(player1 == NULL){
            printf("PLAYER 2 WINS! GAME OVER");
        }
        if(player2 == NULL){
            printf("PLAYER 1 WINS! GAME OVER");
        }


        i++;
    }
    destroyChampionList(player1);
    destroyChampionList(player2);

    return 0;
}
