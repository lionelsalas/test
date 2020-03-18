#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int**  create_tab(int ligne, int colonne) {
	int k,h,l;
//	printf("Nombre de lignes: %d \nNombre de colonne: %d \n", ligne,colonne);
    int** tab;
    tab = malloc(ligne*sizeof(int*)); 
    for(k=0;k<ligne;k++){
        tab[k] = malloc(colonne*sizeof(int));
    }
    for (h=0; h<ligne; h++){
		for (l=0; l<colonne; l++){
			tab[h][l]=(rand())%10;
		}
	}
	return tab ;
  }



void affichage(int** tab, int ligne, int colonne){ // varibale qui contient l'adresse d'un entier (pointeur)
    int h,l;
    for (h=0; h<ligne; h++){
		for (l=0; l<colonne; l++){
			printf("%d ", tab[h][l]);
		}
		printf("\n");	
	}
}



void libre(int ligne,int** matrice){
	int i;
	for (i=0;i<ligne;i++){
		free(matrice[i]);
	}
	free(matrice);
}


int trace(int ligne, int** matrice){
	int i, resultat=0;
	for (i=0;i<ligne;i++){
		resultat += matrice [i] [i];
	}
	return resultat;	
}


int main() {
	
	int** matrice;
	int lignecolonne;
	int resultat;

	printf("Entrez le nombre de ligne de la matrice carrée: ");
	scanf("%d", &lignecolonne);

		
	matrice = create_tab(lignecolonne , lignecolonne);
	printf("\nVotre Matrice carée: \n");
	affichage(matrice,lignecolonne,lignecolonne);
	
	resultat=trace(lignecolonne, matrice);
	printf("\nTrace de la matrice carée:\n ");
	printf("%d ", resultat);
	

	
	
	libre(lignecolonne,matrice);
}
