
#ifndef G_HEADERS
#define G_HEADERS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int arrivee;
  double cout;
}T_ARC;

typedef struct lsucc{ //lsucc ?
  T_ARC val;
  struct lsucc *suiv;
}*L_ARC;

typedef struct {
  char *nom;
  double x,y;
  L_ARC voisins;
}T_SOMMET;

typedef struct {
  int n;
  T_SOMMET *sommets;
}GRAPHE;


GRAPHE ajouterSommet(GRAPHE G, T_SOMMET sommet);
GRAPHE supprimerSommet(GRAPHE G, T_SOMMET sommet);
GRAPHE ajouterArc(GRAPHE G, T_SOMMET A, T_SOMMET B, int valeur);
GRAPHE supprimerArc(GRAPHE G, T_SOMMET A, T_SOMMET B);
int valeurArc(GRAPHE G, T_SOMMET A, T_SOMMET B);
int voisin(GRAPHE G, T_SOMMET A, T_SOMMET B);
T_SOMMET* voisinS(GRAPHE G, T_SOMMET A);
GRAPHE ouvrirGraphe(char *nom);
L_ARC plusCourtChemin(GRAPHE , T_SOMMET , T_SOMMET );
void afficherGraphe(GRAPHE G);
int appartient(long int *S, int a);
void libererGraphe(GRAPHE G);
#endif
