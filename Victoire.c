#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#include "fonctions.h"


/*Fonction vérifiant si les conditions de victoires sont remplies*/
int fvictoire (int tuiles[], int grille[], int victoire, int nbcases){
  int i,v;
  for (i=0;i<nbcases;i++){
    if (tuiles[i]==grille[i]){
      v++;
    }
  }
  if (v==nbcases){
    victoire=1;
  }
  printf("%d\n",victoire);
  return victoire;
}


/*Fonction qui félicite le joueur et le permet de quitter la partie*/
void ecranVictoire(struct GameInfo gameinfo, char* chemin_img, int longueur, int hauteur, int lignes, int colonnes) {
  ChoisirEcran(2);
  couleur c = CouleurParComposante(205, 172, 236);
  EffacerEcran(c);

  EcrireTexte(gameinfo.screen.SCREEN_WIDTH/2, 75, "Victoire !", 2);
  EcrireTexte( 50, 100, "Revenir au menu", 2);
  EcrireTexte( 50, 150, "Quitter", 2);
  ChargerImage(chemin_img,gameinfo.screen.SCREEN_WIDTH/2, gameinfo.screen.SCREEN_HEIGHT/2, 0, 0, longueur*colonnes, hauteur*lignes);

  while(SourisCliquee()) {
    SourisPosition();
    if((_X >= 50 && _X <= 50 + TailleChaineEcran("Revenir au menu", 2))
       && (_Y >= 75 && _Y <= 100)) {
      menu(gameinfo);
    }
    if ((_X >= 50 && _X <= 50 + TailleChaineEcran("Quitter", 2)) 
        && (_Y >= 125 && _Y <= 150)) {
      fermer_jeu();
    }
  }

  CopierZone(2, 0 , 0, 0, gameinfo.screen.SCREEN_WIDTH, gameinfo.screen.SCREEN_HEIGHT, 0, 0);
}
