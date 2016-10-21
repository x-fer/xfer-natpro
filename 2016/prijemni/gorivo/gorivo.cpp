#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int error(){
	printf("-1\n");
	exit(0);
}

int main(){
	int n;
	int total_fuel=0, initial_km=0, prev_d=0;
	double price=1, spending, highest_cons=0;
	int l, c, k;
	scanf(" %d", &n);
	for (int i = 0; i < n; ++i){
		scanf(" %d %d %d", &l, &c, &k);
		if (!i){
			price = c*1./l;
			initial_km = k;
		}
		else{
			if (abs(price-(c*1./l)) > 0.001){
				//fprintf(stderr,"Price%d\n", i);
				error();
			}
		}
		if (k < prev_d){
			//fprintf(stderr,"Dist%d\n", i);
			error();
		}
		prev_d = k;
		if (i && highest_cons < (prev_d - initial_km)*1./total_fuel){
			highest_cons = (prev_d - initial_km)*1./total_fuel;
		}
		total_fuel += l;
	}
	spending = (prev_d - initial_km)*1./total_fuel;
	//printf("%lf %lf\n", highest_cons, spending);
	if (highest_cons - spending > 0.001){
		//fprintf(stderr,"Spend%lf\n", highest_cons);
		error();
	} 
	scanf(" %d %d", &l, &c);
	if (abs(price) > 0.001){
		printf("%d\n", (int)((l/price + c)*spending));
	}
	else{
		printf("%d\n", (int)(c*spending));
	}
	return 0;
}