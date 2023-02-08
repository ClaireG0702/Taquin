#ifndef FONCTIONS_H
#define FONCTIONS_H

typedef struct Coord Coord;
typedef struct Ecran Ecran;
typedef struct GameInfo GameInfo;

struct Ecran {
  int SCREEN_WIDTH;
  int SCREEN_HEIGHT;
};

struct Coord {
  int x;
  int y;
};

struct GameInfo {
  Ecran screen;
};


void melange (int*, int , int );
void remplissage (int*, int);
void affichage (struct GameInfo, int*, int, int, int, int, int, int, char*, int);
int verifzero (int*, int, int);
int fvictoire (int*, int*, int , int);
void fermer_jeu();
void ecranVictoire(struct GameInfo, char*, int, int, int, int);
void game(struct GameInfo, int, int, int);
void menu(struct GameInfo);

#endif /*FONCTIONS_H */
