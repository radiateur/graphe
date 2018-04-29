#include "graphe.h"
#include "algo.h"

int main(){
  char nom[] = "graphe1.txt";
  GRAPHE G;
  T_SOMMET d, a;
  /*d.nom = calloc(1, 4*sizeof(char));
  a.nom = calloc(1, 4*sizeof(char));
  d.nom = "Aaa";
  a.nom = "Haa";*/
  
  G = ouvrirGraphe(nom);
  afficherGraphe(G);
  d = G.sommets[0];
  a = G.sommets[7];
  //plusCourtChemin(G, d, a);
  
  return 0;
}
