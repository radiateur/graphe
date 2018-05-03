#include "graphe.h" //stdio.h et string.h sont dedans
#include "graphe.c" //seul ajouterArc sert

GRAPHE ajouterCorrespondancesUneStation(GRAPHE G){
	/*si deux lignes se croisent à une même station,
	alors il faut ajouter un arc joignant les deux sommets
	de coût 360*/
	G.n = nb_sommets;
	int i, j;
	for(i=0; i<nb_sommets; i++){
		for(j=0; i<nb_sommets; j++){
			if (!strcmp(G.sommets[i].nom, G.sommet[j].nom)){ // si chaînes identiques
				ajouterArc(G, G.sommets[i], G.sommets[j], 360); //penser à mettre double dans graphe.h
			}
		}
	}
}

GRAPHE ajouterChoixDepart(GRAPHE G, char* nom){
	/*si plusieurs lignes passent par la station de départ
	alors on relie les sommets correspondant à cette station
	pour chaque ligne par un arc de poids nul*/
	G.n = nb_sommets;
	T_SOMMET precedent = NULL;
	T_SOMMET actuel = NULL; //je ne sais pas les initialiser
	int i;
	for(i=0; i<nb_sommets; i++){				
		if (!strcmp(G.sommets[i].nom, nom)){ //si on trouve un arrêt de ce nom
			precedent = actuel;
			actuel = G.sommets[i];
			if(!precedent){ajouterArc(G, precedent, actuel, 0);} //si précédent est non nul, on le relie avec actuel
		}
	}
}
