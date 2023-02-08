#include <stdlib.h>
#include <stdio.h>
#include <graph.h>
#include <time.h>
#include "fonctions.h"


/* Fonction qui prend en compte les paramètres choisi par l'utilisateur et affiche la partie */
void game(struct GameInfo gameinfo, int img, int lignes, int colonnes) {
  int i, j, m=0,n=0;
  int longueur = 0, hauteur = 0;
  int nbcases = lignes*colonnes;
  char* chemin_img;
  int x = 0, y = 0;
  int* tuiles = (int*) calloc(sizeof(int), (nbcases-1));
  int* grille = (int*) calloc(sizeof(int), (nbcases-1));
  int deplacement=4, nbr_deplacement=0;
  int victoire=0;

ChoisirEcran(1);
  couleur c;
  c = CouleurParComposante(215, 172, 236);
  EffacerEcran(c);
  
  if(img == 1) {
    longueur = 681 / colonnes;
    hauteur = 401 / lignes;
    chemin_img = "totoro.png";
    x = (gameinfo.screen.SCREEN_WIDTH - 681) / 2;
    y = (gameinfo.screen.SCREEN_HEIGHT - 401) / 2;
  }
  if(img == 2) {
    longueur = 654 / colonnes;
    hauteur = 368 / lignes;
    chemin_img = "chihiro.png";
    x = (gameinfo.screen.SCREEN_WIDTH - 654) / 2;
    y = (gameinfo.screen.SCREEN_HEIGHT - 368) / 2;
  }
  if(img == 3) {
    longueur = 638 / colonnes;
    hauteur = 359 / lignes;
    chemin_img = "sky.png";
    x = (gameinfo.screen.SCREEN_WIDTH - 638) / 2;
    y = (gameinfo.screen.SCREEN_HEIGHT - 359) / 2;
  }

  remplissage(grille,nbcases);
  remplissage(tuiles,nbcases);
  melange(tuiles,lignes,colonnes);

  affichage(gameinfo, tuiles, lignes, colonnes, x, y, longueur, hauteur, chemin_img, nbr_deplacement);
  verifzero(tuiles,n,nbcases);

  /*Déplacements au clavier*/

  KeySym touche = XK_A;
  while(1) {
    printf("%d\n",n );
    if(ToucheEnAttente()) {   
      touche = Touche();
      n= verifzero(tuiles, n, nbcases);
      if(touche == XK_Up) {
        deplacement=0;
        /* Déplacement vers le haut de la case vide*/
        if ((deplacement==0)&&(n>=colonnes)) {    /*Vérifie que la case vide ne se trouve pas à a ligne la plus haute.*/
          m=tuiles[n];
          tuiles[n]=tuiles[n-colonnes];
          tuiles[n-colonnes]=m;
          n= n - colonnes;
          nbr_deplacement++;
          affichage(gameinfo, tuiles, lignes, colonnes, x, y, longueur, hauteur, chemin_img, nbr_deplacement);
          victoire = fvictoire(tuiles, grille, victoire, nbcases);
          if(victoire == 1) {
            ecranVictoire(gameinfo, chemin_img, longueur, hauteur, lignes, colonnes);
          } 
        }
	     printf("0\n");
      }
      if(touche == XK_Down){
        deplacement=1;
        /* Déplacement vers le bas de la case vide*/
        if ((deplacement==1)&&(n<(lignes*colonnes-colonnes))){    /*Vérifie que la case vide ne se trouve pas déjà en bas du taquin.*/
          m=tuiles[n];
          tuiles[n]=tuiles[n+colonnes];
          tuiles[n+colonnes]=m;
          n= n + colonnes;
          nbr_deplacement++;
          affichage(gameinfo, tuiles, lignes, colonnes, x, y, longueur, hauteur, chemin_img, nbr_deplacement);
          victoire = fvictoire(tuiles, grille, victoire, nbcases);
          if(victoire == 1) {
            ecranVictoire(gameinfo, chemin_img, longueur, hauteur, lignes, colonnes);
          }
        } 
	      printf("1\n");
      }
      if(touche == XK_Left){
        deplacement=2;
        /* Déplacement vers la gauche*/
        if ((deplacement==2)&&((n%colonnes)!=0)){   /*Vérifie que la case vide ne soit pas déjà tout à gauche.*/
          m=tuiles[n];
          tuiles[n]=tuiles[n-1];
          tuiles[n-1]=m;
          n= n -1;
          nbr_deplacement++;
          affichage(gameinfo, tuiles, lignes, colonnes, x, y, longueur, hauteur, chemin_img, nbr_deplacement);
          victoire = fvictoire(tuiles, grille, victoire, nbcases);
          if(victoire == 1) {
            ecranVictoire(gameinfo, chemin_img, longueur, hauteur, lignes, colonnes);
          }
        } 
	      printf("2\n");
      }
      if(touche == XK_Right){
        deplacement=3;
        /* Déplacement vers la droite*/
        if ((deplacement==3)&&((((n+1)%colonnes)!=0 )|| (n==0))){ /*Vérifie que la case vide ne soit pas tout à droite.*/
          m=tuiles[n];
          tuiles[n]=tuiles[n+1];
          tuiles[n+1]=m;
          n= n +1;
          nbr_deplacement++;
          affichage(gameinfo, tuiles, lignes, colonnes, x, y, longueur, hauteur, chemin_img, nbr_deplacement);
          victoire = fvictoire(tuiles, grille, victoire, nbcases);
          if(victoire == 1) {
            ecranVictoire(gameinfo, chemin_img, longueur, hauteur, lignes, colonnes);
          }
        }
	      printf("3\n");
      }
    }

    if(SourisCliquee()) {
      SourisPosition();
      if((_X >= 50  &&  _X <= 50 + TailleChaineEcran("Retour au menu", 2))
          && (_Y >= 75  &&  _Y <= 100)) {
        printf("retour\n");
        CopierZone(0, 0, 0, 0, gameinfo.screen.SCREEN_WIDTH, gameinfo.screen.SCREEN_HEIGHT, 0, 0);
        menu(gameinfo);
      }
    }
   printf("victoire: %d\n", victoire);   
  }

  CopierZone(1, 0, 0, 0, gameinfo.screen.SCREEN_WIDTH, gameinfo.screen.SCREEN_HEIGHT, 0, 0);
}


/*Fonction qui renvoie l'indice de la case vide*/
int verifzero (int tuiles[],int n,int nbcases){
  int i;
  for (i=0;i<nbcases;i++){
    if (tuiles[i]==0){
      n=i;
    }
  }
  printf("%d\n",n );
  return n;
}


/*Fonction qui affiche les tuiles*/
void affichage (struct GameInfo gameinfo, int tuiles[], int lignes, int colonnes,
int x, int y, int longueur, int hauteur, char chemin_img[], int nbr_deplacement){
  int img;
  int i,n,j,m=0;
  int verifligne=0;
  char nbr_depChar[999];

  couleur c = CouleurParComposante(205, 172, 236);
  EffacerEcran(c);

  for(i = 0; i < lignes; i++) {
    for(j = 0; j < colonnes; j++) {
      if(tuiles[m]== 0) {
      } else {
	        verifligne=tuiles[m]/colonnes;
          ChargerImage(chemin_img, x+((longueur+5)*j), y+((hauteur+5)*i),
          (longueur*(tuiles[m]-(verifligne*colonnes))), (hauteur*verifligne), longueur, hauteur);
        }
        m++;
    } 
    printf("\n");
  }
  c = CouleurParNom("black");
  ChoisirCouleurDessin(c);
  EcrireTexte(50, 100, "Retour au menu", 2);
  EcrireTexte(50, 625, "Nombre de deplacements:", 2);
  sprintf(nbr_depChar, "%03d", nbr_deplacement);
  EcrireTexte(100, 660, nbr_depChar, 2);

  CopierZone(1, 0, 0, 0, gameinfo.screen.SCREEN_WIDTH, gameinfo.screen.SCREEN_HEIGHT, 0, 0);
}



/*Fonction qui remplie grille et tuiles*/
void remplissage (int grille[], int nbcases){
	int i;
	for (i=0;i<nbcases;i++){
		grille[i]=i;
	}
}


/*Fonction qui va executer une série de mouvements aléatoires possibles dans le taquin afin de mélanger les tuiles*/
void melange (int tuiles[], int lignes, int colonnes){
	srand(time(NULL));
	int i,n=0,m=0;		/*n est l'indice qui suit la case vide et m permet de */
	int deplacement = (rand()%4);		/*Permet d'avoir un type de mouvement choisi au hasard*/
	
	for (i=0;i<50*lignes*colonnes;i++){
		
		/* Déplacement vers le haut*/
		if ((deplacement==0)&&(n>=colonnes)) {		/*Vérifie que la case vide ne se trouve pas à a ligne la plus haute.*/
				m=tuiles[n];
				tuiles[n]=tuiles[n-colonnes];
				tuiles[n-colonnes]=m;
				n= n - colonnes;
			}
		
		/* Déplacement vers le bas*/
		if ((deplacement==1)&&(n<(lignes*colonnes-colonnes))){		/*Vérifie que la case vide ne se trouve pas déjà en bas du taquin.*/
				m=tuiles[n];
				tuiles[n]=tuiles[n+colonnes];
				tuiles[n+colonnes]=m;
				n= n + colonnes;			
			}	
		
		/* Déplacement vers la gauche */
		if ((deplacement==2)&&((n%colonnes)!=0)){		/*Vérifie que la case vide ne soit pas déjà tout à gauche.*/
				m=tuiles[n];
				tuiles[n]=tuiles[n-1];
				tuiles[n-1]=m;
				n= n -1;
			}	
	
		/* Déplacement vers la droite*/
		if ((deplacement==3)&&((((n+1)%colonnes)!=0 )|| (n==0))){	/*Vérifie que la case vide ne soit pas tout à droite.*/
				m=tuiles[n];
				tuiles[n]=tuiles[n+1];
				tuiles[n+1]=m;
				n= n +1;

			}
		/*Choisi de  nouveau un mouvement au hasard*/
		deplacement=(rand()%4);		
		
	}
}



