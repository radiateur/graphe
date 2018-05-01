#include <float.h>

#include "algo.h"

L_ARC creerLArc(){
  return NULL;
}

L_ARC ajoutArc(L_ARC L, T_ARC A){
  /*if (LArcEstVide(L)){
    L = creerLArc();
    }*/
  L_ARC n;
  n = (L_ARC) calloc(1, sizeof(*n));
  if (n==NULL) {
      fprintf(stderr, "Erreur fatale, mémoire insuffisante");
      exit(1);
    }
  n->val = A;
  n->suiv = L;
  return n;
}

L_ARC copieLArc(L_ARC L1, L_ARC L2){//copie de L1 dans L2
  while(!LArcEstVide(L1)){
    L2 = ajoutArc(L2, L1->val);
    L1 = L1->suiv;
  }
  return L2;
}

int minimum(double *pcc, long int *C, int n){
  int i;
  double m = DBL_MAX;
  int indice_m=-1;//Boooof
  for(i=0; i<n; i++){
    if (C[i] != -1){
      if (pcc[i] < m){
	indice_m = i;
	m = pcc[i];
      }
    }
  }
  return indice_m;
}
int chercherSommet(T_SOMMET x, GRAPHE G){
  int i;
  char nom[256];
  strcpy(nom, x.nom);
  int taille = G.n;
  for(i=0; i<taille; ++i){
    printf("%s %s\n", G.sommets[i].nom, nom);
    if (!strcmp(G.sommets[i].nom, nom))
      return i;
  }
  fprintf(stderr, "Ce sommet n'existe pas !");
  exit(1);
}

int LArcEstVide(L_ARC L){
  if (L==NULL)
    return 1;
  else
    return 0;
 }

int appartient(long int *S, int a){
  if (S[a] == a){
    return 1;
  }
  else{
    return 0;
  }
}
  
L_ARC plusCourtChemin(GRAPHE G, T_SOMMET d, T_SOMMET a){
  int taille = G.n;
  int d_int;
  int a_int;
  //double pcc[taille];
  double *pcc;
  pcc = calloc(taille, sizeof(*pcc));
  //int pere[taille];
  int *pere;
  pere = calloc(taille, sizeof(*pere));
  /*
  long int C[taille];//On représente les sommets par leurs positions
  long int S[taille];
  */
  long int *C;
  long int *S;
  C = calloc(taille, sizeof(*C));//en pratique un seul tableau necessaire et de int de surcroit !
  S = calloc(taille, sizeof(*C));
  int i,j,k;
  double cout;
  printf("zouuuu\n");
  for(i=0; i<taille; ++i){
    //printf("truc\n");
    //printf("%d\n", i);
    C[i] = i;
    S[i] = -1;
    pcc[i] = DBL_MAX;
    pere[i] = -1;
  }
  printf("ici !\n");
  d_int = chercherSommet(d, G);
  a_int = chercherSommet(a, G);
  printf("D_INT A_INT: %d %d\n", d_int, a_int);
  pcc[d_int] = 0;  
  do{
    //printf("là !\n");
    j = minimum(pcc, C, taille); 
    //printf("%d \n", j);
    C[j] = -1;
    S[j] = j;
    //printf("et là !\n");
    L_ARC p;
    p = G.sommets[j].voisins;
    while(!LArcEstVide(p)){
      //printf("coince ici !\n");
      k = p->val.arrivee;
      cout = p->val.cout;
      if (pcc[k] > pcc[j] + cout){
	pcc[k] = pcc[j] + cout;
	pere[k] = j;
      }
      p = p->suiv;
    }
  }while(!appartient(S, a_int) && pcc[j] != DBL_MAX);
  
  while(a_int != d_int){
    printf("%d\n", pere[a_int]);
    a_int = pere[a_int];
  }
}
