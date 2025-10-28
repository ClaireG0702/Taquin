# Taquin / Sliding puzzle

## 🇫🇷 Version française

### Description

Ce projet est une **implémentation du jeu de Taquin** en langage **C**, utilisant la **bibliothèque graphique de l’IUT de Fontainebleau** (`libgraph`).  
Le joueur doit **reconstituer une image** découpée en plusieurs morceaux en **déplaçant la case vide** pour intervertir sa position avec celle d’une tuile adjacente.

Le projet a été développé dans le cadre du **BUT Informatique (1ʳᵉ année)** afin de pratiquer la **programmation événementielle en C**, la **gestion des structures de données**, et la **manipulation graphique** via la bibliothèque `libgraph`.

### Fonctionnalités 

- Affichage graphique avec `libgraph`  
- Choix dynamique de l'image et du niveau de difficulté (taille de la grille)
- Mélange automatique des tuiles
- Détection automatique de la victoire
- Compteurs de coups joués

### Technologies

- **Langage C** – logique du jeu et gestion des événements  
- **libgraph** – affichage graphique et gestion des entrées clavier  
- **Makefile** – automatisation de la compilation et de l’exécution  

### Compilation & exécution

#### Pré-requis
Assurez-vous que la **bibliothèque `libgraph`** de l’IUT est installée et accessible.  
Documentation : [https://iut-fbleau.fr/sitebp/doc/doc_bib_graphique/index.php](https://iut-fbleau.fr/sitebp/doc/doc_bib_graphique/index.php)

#### Compilation  
Dans un terminal, exécuter :
```bash
make
```
Lancement du jeu :
```bash
./taquin
```


### Contrôles

- **Souris** : choix des paramètres
- **Flèches** ↑ / ↓ / ← / → : déplacer la case vide

### Auteurs 

Projet réalisé par 
- **Kayyissa Haïssous**  
- **Claire Gobert**  

Dans le cadre du BUT Informatique – 1ʳᵉ année (2021-2022)

---

## 🇬🇧 English version

### Description

This project is an implementation of the **Sliding Puzzle game** written in **C**, using the **Fontainebleau IUT graphical library** (`libgraph`).  
The player must **reconstruct an image** that has been divided into several tiles by **moving the empty square** to swap its position with an adjacent tile.

The project was developed as part of the **first year of the Computer Science BUT** to practise **event-driven programming in C**, **data structure management**, and **graphical manipulation** using the `libgraph` library.

### Features

- Graphical display using `libgraph`  
- Dynamic image and difficulty selection (grid size)  
- Automatic shuffling of tiles  
- Automatic victory detection  
- Move counter  

### Technologies

- **C language** – game logic and event handling  
- **libgraph** – graphical rendering and keyboard/mouse input handling  
- **Makefile** – build and execution automation  

### Installation & Compilation

#### Requirements
Make sure the **`libgraph`** library from the IUT of Fontainebleau is installed and accessible.  
Documentation: [https://iut-fbleau.fr/sitebp/doc/doc_bib_graphique/index.php](https://iut-fbleau.fr/sitebp/doc/doc_bib_graphique/index.php)

#### Compilation  
In a terminal, run:
```bash
make
```
Then start the game with:
```bash
./taquin
```

### Controls

- **Mouse**: select game parameters  
- **Arrow keys** ↑ / ↓ / ← / → : move the empty tile

### Authors

Project developed by
- **Kayyissa Haïssous**
- **Claire Gobert**

As part of the Computer Science BUT - 1st year (2021-2022)
