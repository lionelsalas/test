#include <stdio.h>
#include <stdlib.h>

int recursive_fact(int entier){
	if (entier == 0){
		return 1;
	}
	entier *= recursive_fact(entier-1);
	return entier;
	}
	
	
int main(){
	int entier;
	printf("Entrez un entier: ");
	scanf("%d",&entier);
	int factorielle = recursive_fact(entier);
	printf("La factorielle de cet entier est : %d \n", factorielle);
	
}
