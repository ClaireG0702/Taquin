#include<stdio.h>
#include<stdlib.h>
#include<graph.h>
#include<time.h>
#include "fonctions.h"


void fermer_jeu() {
  FermerGraphique();
}


/* Fonction menu, sert a faire l'affichage de la fenetre au démarrage du code,
attend que l'utilisateur appuie sur une touche pour faire l'action demandé */
void menu(struct GameInfo gameinfo) {
  int lignes = 0, colonnes = 0;
  int choixImage = 0;
  int espace = 40;
  int marge = 10;
  int width_X = gameinfo.screen.SCREEN_WIDTH;
  int height_Y = gameinfo.screen.SCREEN_HEIGHT;
  int tailleChar = TailleChaineEcran("3", 2) + 5;

  ChoisirEcran(0);

  /* Définition de la couleur de fond du menu */
  couleur c = CouleurParComposante(205,172,236);
  EffacerEcran(c);

  /* Définition de la couleur de l'écriture */
  c = CouleurParNom("black");
  ChoisirCouleurDessin(c);
  /* Définition du texte et de son emplacement sur le menu */
  EcrireTexte(width_X / 3, 50, "Taquin", 2);
  EcrireTexte(width_X / 5, 90, "Choisissez l'image que vous voulez :", 2);
  /* Mise en place des images disponible pour le jeu */
  /* Marge: 21 1ere img: 406, espace: 20, 2eme img: 406, espace: 20, 3eme img: 406, marge: 21 */
  ChargerImage("totoro.png", 10, 120, 150, 0, 380, 300);
  ChargerImage("chihiro.png", 400, 120, 150, 0, 380, 300);
  ChargerImage("sky.png", 790, 120, 150, 0, 380, 300);
  /* Texte pour le choix des lignes */
  EcrireTexte(width_X / 5, 460, "Nombre de lignes:", 2);
  EcrireTexte(width_X / 5, 510, "3", 2);
  EcrireTexte((width_X / 5) + (tailleChar + espace), 510, "4", 2);
  EcrireTexte((width_X / 5) + ((tailleChar + espace) * 2), 510, "5", 2);
  EcrireTexte((width_X / 5) + ((tailleChar + espace) * 3), 510, "6", 2);
  EcrireTexte((width_X / 5) + ((tailleChar + espace) * 4), 510, "7", 2);
  EcrireTexte((width_X / 5) + ((tailleChar + espace) * 5), 510, "8", 2);
  /* Texte pour le choix des colonnes */
  EcrireTexte(width_X / 5, 560, "Nombre de colonnes:", 2);
  EcrireTexte(width_X / 5, 610, "3", 2);
  EcrireTexte((width_X / 5) + (tailleChar + espace), 610, "4", 2);
  EcrireTexte((width_X / 5) + ((tailleChar + espace) * 2), 610, "5", 2);
  EcrireTexte((width_X / 5) + ((tailleChar + espace) * 3), 610, "6", 2);
  EcrireTexte((width_X / 5) + ((tailleChar + espace) * 4), 610, "7", 2);
  EcrireTexte((width_X / 5) + ((tailleChar + espace) * 5), 610, "8", 2);
  /* Texte / Bouton pour lancer la partie et quitter la partie */
  EcrireTexte(width_X / 5, 660, "Lancer la partie", 2);
  EcrireTexte(width_X / 1.5, 660,  "Quitter", 2);
  KeySym touche = XK_A;
  CopierZone(0, 0, 0, 0, gameinfo.screen.SCREEN_WIDTH, gameinfo.screen.SCREEN_HEIGHT, 0, 0);

  while(1) {
    /* Choix des paramètres et actions à la souris */
    if(SourisCliquee()) {
      SourisPosition();
      /* Choix de l'image, attribution de la valeur 1, 2 ou 3 en fonction de l'image choisi
      par l'utilisateur, un rectangle noir apparait autour de l'image selectionné */
      if((_X >= 10  &&  _X <= 380) && (_Y >= 120  &&  _Y <= 420)) {
        choixImage = 1;
        c = CouleurParNom("black");
        ChoisirCouleurDessin(c);
        DessinerRectangle(10, 120, 380, 300);
        c = CouleurParComposante(205, 172, 236);
        ChoisirCouleurDessin(c);
        DessinerRectangle(400, 120, 380, 300);
        DessinerRectangle(790, 120, 380, 300);
      }
      if((_X >= 400  &&  _X <= 780) && (_Y >= 120  &&  _Y <= 420)) {
        choixImage = 2;
        c = CouleurParNom("black");
        ChoisirCouleurDessin(c);
        DessinerRectangle(400, 120, 380, 300);
        c = CouleurParComposante(205, 172, 236);
        ChoisirCouleurDessin(c);
        DessinerRectangle(10, 120, 380, 300);
        DessinerRectangle(790, 120, 380, 300);
      }
      if((_X >= 790  &&  _X <= 1170) && (_Y >= 120  &&  _Y <= 420)) {
        choixImage = 3;
        c = CouleurParNom("black");
        ChoisirCouleurDessin(c);
        DessinerRectangle(790, 120, 380, 300);
        c = CouleurParComposante(205, 172, 236);
        ChoisirCouleurDessin(c);
        DessinerRectangle(10, 120, 380, 300);
        DessinerRectangle(400, 120, 380, 300);
      }


      /* Choix du nombre de lignes, en fonction de chiffre que selectionne l'utilisateur
      le if donne la bonne valeur à la variable et affice un rectangle noir autour du chiffre selectionné */
      if((_X >= width_X / 5  
          &&  _X <= width_X / 5 + tailleChar) 
        && (_Y >= 485  
            &&  _Y <= 510)) {
        lignes = 3;
        c = CouleurParNom("black");
        ChoisirCouleurDessin(c);
        DessinerRectangle(width_X / 5, 485, tailleChar, 25);
        c = CouleurParComposante(205, 172, 236);
        ChoisirCouleurDessin(c);
        DessinerRectangle((width_X / 5) + (tailleChar + espace), 485, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 2), 485, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 3), 485, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 4), 485, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 5), 485, tailleChar, 25);
      }
      if((_X >= (width_X / 5) + (tailleChar + espace)  
          &&  _X <= (width_X / 5) + (tailleChar + espace) + tailleChar) 
        && (_Y >= 485  
            &&  _Y <= 510)) {
        lignes = 4;
        c = CouleurParNom("black");
        ChoisirCouleurDessin(c);
        DessinerRectangle((width_X / 5) + (tailleChar + espace), 485, tailleChar, 25);
        c = CouleurParComposante(205, 172, 236);
        ChoisirCouleurDessin(c);
        DessinerRectangle(width_X / 5, 485, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 2), 485, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 3), 485, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 4), 485, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 5), 485, tailleChar, 25);
      }
      if((_X >= (width_X / 5) + ((tailleChar + espace) * 2) 
          && _X <= (width_X / 5) + ((tailleChar + espace) * 2) + tailleChar) 
        && (_Y >= 485 
            && _Y <= 510)) {
        lignes = 5;
        c = CouleurParNom("black");
        ChoisirCouleurDessin(c);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 2), 485, tailleChar, 25);
        c = CouleurParComposante(205, 172, 236);
        ChoisirCouleurDessin(c);
        DessinerRectangle(width_X / 5, 485, tailleChar, 25);
        DessinerRectangle((width_X / 5) + (tailleChar + espace), 485, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 3), 485, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 4), 485, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 5), 485, tailleChar, 25);
      }
      if((_X >= (width_X / 5) + ((tailleChar + espace) * 3) 
          && _X <= (width_X / 5) + ((tailleChar + espace) * 3) + tailleChar) 
        && (_Y >= 485 
            && _Y <= 510)) {
        lignes = 6;
        c = CouleurParNom("black");
        ChoisirCouleurDessin(c);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 3), 485, tailleChar, 25);
        c = CouleurParComposante(205, 172, 236);
        ChoisirCouleurDessin(c);
        DessinerRectangle(width_X / 5, 485, tailleChar, 25);
        DessinerRectangle((width_X / 5) + (tailleChar + espace), 485, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 2), 485, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 4), 485, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 5), 485, tailleChar, 25);
      }
      if((_X >= (width_X / 5) + ((tailleChar + espace) * 4) 
          && _X<= (width_X / 5) + ((tailleChar + espace) * 4) + tailleChar) 
        && (_Y >= 485 
            && _Y <= 510)) {
        lignes = 7;
        c = CouleurParNom("black");
        ChoisirCouleurDessin(c);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 4), 485, tailleChar, 25);
        c = CouleurParComposante(205, 172, 236);
        ChoisirCouleurDessin(c);
        DessinerRectangle(width_X / 5, 485, tailleChar, 25);
        DessinerRectangle((width_X / 5) + (tailleChar + espace), 485, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 2), 485, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 3), 485, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 5), 485, tailleChar, 25);
      }
      if((_X >= (width_X / 5) + ((tailleChar + espace) * 5)
          && _X <= (width_X / 5) + ((tailleChar + espace) * 5) + tailleChar) 
        && (_Y >= 485 
            && _Y <= 510)) {
        lignes = 8;
        c = CouleurParNom("black");
        ChoisirCouleurDessin(c);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 5), 485, tailleChar, 25);
        c = CouleurParComposante(205, 172, 236);
        ChoisirCouleurDessin(c);
        DessinerRectangle(width_X / 5, 485, tailleChar, 25);
        DessinerRectangle((width_X / 5) + (tailleChar + espace), 485, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 2), 485, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 3), 485, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 4), 485, tailleChar, 25);
      }


      /* Choix du nombre de colonnes, en fonction de chiffre que selectionne l'utilisateur
      le if donne la bonne valeur à la variable et affice un rectangle noir autour du chiffre selectionné */
      if((_X >= width_X / 5  
          &&  _X <= width_X / 5 + tailleChar) 
        && (_Y >= 585  
            &&  _Y <= 610)) {
        colonnes = 3;
        c = CouleurParNom("black");
        ChoisirCouleurDessin(c);
        DessinerRectangle(width_X / 5, 585, tailleChar, 25);
        c = CouleurParComposante(205, 172, 236);
        ChoisirCouleurDessin(c);
        DessinerRectangle((width_X / 5) + (tailleChar + espace), 585, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 2), 585, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 3), 585, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 4), 585, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 5), 585, tailleChar, 25);
      }
      if((_X >= (width_X / 5) + (tailleChar + espace)  
          &&  _X <= (width_X / 5) + (tailleChar + espace) + tailleChar) 
        && (_Y >= 585  
            &&  _Y <= 610)) {
        colonnes = 4;
        c = CouleurParNom("black");
        ChoisirCouleurDessin(c);
        DessinerRectangle((width_X / 5) + (tailleChar + espace), 585, tailleChar, 25);
        c = CouleurParComposante(205, 172, 236);
        ChoisirCouleurDessin(c);
        DessinerRectangle(width_X / 5, 585, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 2), 585, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 3), 585, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 4), 585, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 5), 585, tailleChar, 25);
      }
      if((_X >= (width_X / 5) + ((tailleChar + espace) * 2) 
          && _X <= (width_X / 5) + ((tailleChar + espace) * 2) + tailleChar) 
        && (_Y >= 585 
            && _Y <= 610)) {
        colonnes = 5;
        c = CouleurParNom("black");
        ChoisirCouleurDessin(c);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 2), 585, tailleChar, 25);
        c = CouleurParComposante(205, 172, 236);
        ChoisirCouleurDessin(c);
        DessinerRectangle(width_X / 5, 585, tailleChar, 25);
        DessinerRectangle((width_X / 5) + (tailleChar + espace), 585, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 3), 585, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 4), 585, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 5), 585, tailleChar, 25);
      }
      if((_X >= (width_X / 5) + ((tailleChar + espace) * 3) 
          && _X <= (width_X / 5) + ((tailleChar + espace) * 3) + tailleChar) 
        && (_Y >= 585 
            && _Y <= 610)) {
        colonnes = 6;
        c = CouleurParNom("black");
        ChoisirCouleurDessin(c);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 3), 585, tailleChar, 25);
        c = CouleurParComposante(205, 172, 236);
        ChoisirCouleurDessin(c);
        DessinerRectangle(width_X / 5, 585, tailleChar, 25);
        DessinerRectangle((width_X / 5) + (tailleChar + espace), 585, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 2), 585, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 4), 585, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 5), 585, tailleChar, 25);
      }
      if((_X >= (width_X / 5) + ((tailleChar + espace) * 4) 
          && _X<= (width_X / 5) + ((tailleChar + espace) * 4) + tailleChar) 
        && (_Y >= 585 
            && _Y <= 610)) {
        colonnes = 7;
        c = CouleurParNom("black");
        ChoisirCouleurDessin(c);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 4), 585, tailleChar, 25);
        c = CouleurParComposante(205, 172, 236);
        ChoisirCouleurDessin(c);
        DessinerRectangle(width_X / 5, 585, tailleChar, 25);
        DessinerRectangle((width_X / 5) + (tailleChar + espace), 585, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 2), 585, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 3), 585, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 5), 585, tailleChar, 25);
      }
      if((_X >= (width_X / 5) + ((tailleChar + espace) * 5)
          && _X <= (width_X / 5) + ((tailleChar + espace) * 5) + tailleChar) 
        && (_Y >= 585 
            && _Y <= 610)) {
        colonnes = 8;
        c = CouleurParNom("black");
        ChoisirCouleurDessin(c);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 5), 585, tailleChar, 25);
        c = CouleurParComposante(205, 172, 236);
        ChoisirCouleurDessin(c);
        DessinerRectangle(width_X / 5, 585, tailleChar, 25);
        DessinerRectangle((width_X / 5) + (tailleChar + espace), 585, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 2), 585, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 3), 585, tailleChar, 25);
        DessinerRectangle((width_X / 5) + ((tailleChar + espace) * 4), 585, tailleChar, 25);
      }

      /* Choix de lancer la partie ou de quitter à la souris */
      if((_X >= width_X / 5 
          && _X <= width_X / 5 + TailleChaineEcran("Lancer la partie", 2)) 
        && (_Y >= 635 
            && _Y <= 660)) {
        /* La partie se lance à condition que tous les paramètres soit selectionné */
        if(choixImage != 0 && lignes != 0 && colonnes != 0)
          game(gameinfo, choixImage, lignes, colonnes);
      }
      if((_X >= width_X / 1.5 
          && _X <= (width_X / 1.5 + TailleChaineEcran("Quitter", 2))) 
        && (_Y >= 635 
            && _Y <= 660)) {
        fermer_jeu();
      }

    }

    /* Choix de lancer la partie ou quitter au clavier */
    if(ToucheEnAttente()) {
      touche = Touche();
      /* La touche Entrer stop la boucle et lance la fonction game */
      if(touche == XK_Return) {
        /* La partie se lance à condition que tous les paramètres soit selectionné */
        if(choixImage != 0 && lignes != 0 && colonnes != 0)
          game(gameinfo, choixImage, lignes, colonnes);
      }
      /* La touche Esc quitte le programme */
      if(touche == XK_Escape) {
        fermer_jeu();
      }
    }
  }
}


int main(int argc, char const *argv[]) {
  GameInfo gameinfo;
  gameinfo.screen.SCREEN_WIDTH = 1180; /* Longueur de la fenetre */
  gameinfo.screen.SCREEN_HEIGHT = 700; /* Hauteur de la fenetre */

  InitialiserGraphique();
  CreerFenetre((Maxx()-gameinfo.screen.SCREEN_WIDTH)/2, (Maxy()-gameinfo.screen.SCREEN_HEIGHT)/2, gameinfo.screen.SCREEN_WIDTH, gameinfo.screen.SCREEN_HEIGHT);
  menu(gameinfo);

  return EXIT_SUCCESS;
}
