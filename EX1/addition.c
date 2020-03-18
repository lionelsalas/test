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

void libre(int ligne,int** a){
	int i;
	for (i=0;i<ligne;i++){
		free(a[i]);
	}
	free(a);
}

int** addition(int** matrice1, int** matrice2, int ligne, int colonne){
	int** resultataddition;
	int i,j;
	resultataddition = create_tab(ligne,colonne);
	for (i=0;i<ligne;i++){
		for (j=0;j<colonne;j++){
			resultataddition[i][j]= matrice1[i][j]+matrice2[i][j];
		 }
	 }
	return resultataddition;
}
	


int main() {
	
	int** matrice1;
	int** matrice2;
	int** resultataddition;
	int ligne, colonne;
	int ligne_matrice1, colonne_matrice1;
	int ligne_matrice2, colonne_matrice2;
	
	while ((ligne_matrice1 != ligne_matrice2) && (colonne_matrice1 != colonne_matrice2)){
		printf("Veuillez rentrer deux matrices de même dimensions! \n ");
		printf("Entrez le nombre de ligne de la première matrice: ");
		scanf("%d", &ligne_matrice1);
		printf("Entrez le nombre de colonne de la première matrice: ");
		scanf("%d", &colonne_matrice1);
		printf("Entrez le nombre de ligne de la deuxième matrice: ");
		scanf("%d", &ligne_matrice2);
		printf("Entrez le nombre de colonne de la deuxième matrice: ");
		scanf("%d", &colonne_matrice2);
		
		
		}	
	ligne = ligne_matrice1;
	colonne = colonne_matrice1;
	matrice1 = create_tab(ligne,colonne);
	matrice2 = create_tab(ligne,colonne);
	printf("\nPremière matrice aléatoire: \n");
	affichage(matrice1,ligne,colonne);
	printf("\nDeuxième matrice aléatoire: \n");
	affichage(matrice2,ligne,colonne);
	resultataddition = addition(matrice1,matrice2,ligne,colonne);
	printf("\nRésultat de l'addition des deux matrices: \n");
	affichage(resultataddition,ligne,colonne);
	
	
	libre(ligne,matrice1);
	libre(ligne,matrice2);
	libre(ligne,resultataddition);
}
