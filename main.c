#include "graphe.h"
#include "algo.h"

int main(){
  char nom[] = "grapheColorado.csv";
  GRAPHE G;
  T_SOMMET d, a;
  /*d.nom = calloc(1, 4*sizeof(char));
  a.nom = calloc(1, 4*sizeof(char));
  d.nom = "Aaa";
  a.nom = "Haa";*/
  
  G = ouvrirGraphe(nom);
  //afficherGraphe(G);
  d = G.sommets[5];
  a = G.sommets[10000];
  printf("mais pk ?\n");
  plusCourtChemin(G, d, a);
  
  return 0;
}
