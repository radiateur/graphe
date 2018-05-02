#include "graphe.h"
#include "algo.h"

int main(){
  //char nom[] = "grapheColorado.csv";
  char nom[] = "graphe2.txt";
  GRAPHE G;
  T_SOMMET d, a;
  /*d.nom = calloc(1, 4*sizeof(char));
  a.nom = calloc(1, 4*sizeof(char));
  d.nom = "Aaa";
  a.nom = "Haa";*/
  
  G = ouvrirGraphe(nom);
  //afficherGraphe(G);
  d = G.sommets[0];
  //a = G.sommets[10000];
  a = G.sommets[6];
  //printf("mais pk ?\n");
  plusCourtChemin(G, d, a);
  libererGraphe(G);
  return 0;
}
