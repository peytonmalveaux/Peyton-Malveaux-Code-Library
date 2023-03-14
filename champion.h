#ifndef CHAMPION
#define CHAMPION

typedef enum ChampionRoll{MAGE = 1, FIGHTER = 2, SUPPORT = 3, TANK = 4}ChampionRoll;

typedef struct Champion{
    enum ChampionRoll roll;
    int level;
    struct Champion* next;

}Champion;

Champion* createChampion();
Champion* addChampion( Champion *head, Champion *c );
Champion* buildChampionList( int n );
void printChampionList(Champion *head);
Champion* removeChampion(Champion *head);
Champion* destroyChampionList( Champion *head );
#endif
