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
	
int** multiplication(int** matrice1, int** matrice2,int ligne_matrice1,int colonne_matrice2){
	int** resultatmultiplication;
	int i,j,k;
	resultatmultiplication = create_tab(ligne_matrice1,colonne_matrice2);
	for (i=0; i<ligne_matrice1; i++){
		for (j=0; j<=colonne_matrice2 ;j++){
		resultatmultiplication[i][j] = 0;
			for (k=0;k<=colonne_matrice2;k++){
				resultatmultiplication[i][j]  += matrice1[i][k]*matrice2[k][j];
		 }
		}
	 }
	return resultatmultiplication;
}

int main() {
	
	int** matrice1;
	int** matrice2;
//	int** resultataddition;
	int** resultatmultiplication;
//	int ligne, colonne;
	int ligne_matrice1, colonne_matrice1;
	int ligne_matrice2, colonne_matrice2;
	
	while ( colonne_matrice1 != ligne_matrice2){
		printf("Veuillez rentrer deux matrices qui peuvent être multipliées \n ");
		printf("Entrez le nombre de ligne de la première matrice: ");
		scanf("%d", &ligne_matrice1);
		printf("Entrez le nombre de colonne de la première matrice: ");
		scanf("%d", &colonne_matrice1);
		printf("Entrez le nombre de ligne de la première matrice: ");
		scanf("%d", &ligne_matrice2);
		printf("Entrez le nombre de colonne de la première matrice: ");
		scanf("%d", &colonne_matrice2);	
		}	
		
	matrice1 = create_tab(ligne_matrice1,colonne_matrice1);
	matrice2 = create_tab(ligne_matrice2,colonne_matrice2);
	printf("\nPremière matrice aléatoire: \n");
	affichage(matrice1,ligne_matrice1,colonne_matrice1);
	printf("\nDeuxième matrice aléatoire: \n");
	affichage(matrice2,ligne_matrice2,colonne_matrice2);
	resultatmultiplication = multiplication(matrice1,matrice2,ligne_matrice1,colonne_matrice2);
	printf("\nRésultat de la multiplication des deux matrices: \n");
	affichage(resultatmultiplication,ligne_matrice1,colonne_matrice2);
	
	
	libre(ligne_matrice1,matrice1);
	libre(ligne_matrice2,matrice2);
	libre(ligne_matrice1,resultatmultiplication);
}
