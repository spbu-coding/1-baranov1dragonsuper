#include <stdio.h>
#include <math.h>
//-lm
#define PI 3.14159265359

long double rect_method(long double a, long double b, long double c){
	long double res = 0; long double step = (b - a) / c;
	for (long double i = a; i < b; i += step){
		res += step * (sin(i) + sin(i+step)) / 2;
	}
	return(res);
}

long double simpsons_rule(long double a, long double b, long double c){
	long double res = 0; long double step = (b - a) / c;
	for (long double i = a; i < b; i += step){
		res += (step * (sin(i) + 4 * sin(step / 2 + i) + sin(step + i)) / 6);
	}
	return(res);
}

void main(){
	long double a; long double b; long long c;
	printf("Enter left border and right border:  \n");
	scanf("%Lf%Lf", &a, &b);
	printf("[for exit type -1]\n");
	while(c!=-1){
		scanf("%lli", &c);
		if(a < b && a >= 0 && (PI - b) > 0.00000001 && c > 0){
			printf("%lli %.5Lf %.5Lf\n",c,rect_method(a,b,c),simpsons_rule(a,b,c));
		}
		else{
			printf("Wrong input.\n");
		}
	}
	printf("end.\n");
}
