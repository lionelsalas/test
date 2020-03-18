#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void affiche_poly(double poly[], int i){
	for (int y=0; y<i; y++){
		if (y>0 && poly[y]>0) 
            printf(" + ");
		if (poly[y]!=0) 
            printf("%lf*x^%d", poly[y],y);
	}
	
}

double eval_x(double poly[], double longueur, double y){
	double resultat=0;
	for (int x=0; x<longueur; x++) 
        resultat+=poly[x]*pow(y,(double) x);
	return resultat;
}

void deriv_x(double poly[], double longueur, double derive[]){
      for (int n=0; n<longueur-1; n++){
          derive[n]=(n+1)*poly[n+1];     }
}
 
double main(){

	double tab[]={5,4,-3,2,0};
	double derive[]={0,0,0,0,0};
	affiche_poly(tab,5);
	printf("\n");
	
	double eval=18;
	printf("Pour x=%lf, le polynôme est égal à : %lf \n",eval,eval_x(tab,5,eval));
	printf("\n");

	deriv_x(tab,5,derive);
	printf("La dérivé du polynôme est : \n");
	affiche_poly(derive,4);
	
    return 0;
}
