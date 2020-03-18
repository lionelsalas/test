#include <stdio.h>
#include <stdlib.h>
int iterative_fact(int entier){
	int i;
	int factorielle=1;
	for (i=1; i<=entier; i++){
		factorielle*=i;
	}
	return factorielle;
}

int main(){
	int entier;
	printf("Entrez un entier: ");
	scanf("%d",&entier);
	int factorielle = iterative_fact(entier);
	printf("La factorielle de cet entier est : %d \n", factorielle);
	
}
