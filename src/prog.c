#include <stdio.h>
#include <math.h>

long double calculate_by_rect_method(long double a, long double b, long double count){
	long double res = 0; long double step = (b - a) / count;
	for (long double i = a; i < b; i += step){
		res += step * (sin(i) + sin(i+step)) / 2;
	}
	return(res);
}

long double calculate_by_simpsons_rule(long double a, long double b, long double count){
	long double res = 0; long double step = (b - a) / count;
	for (long double i = a; i < b; i += step){
		res += (step * (sin(i) + 4 * sin(step / 2 + i) + sin(step + i)) / 6);
	}
	return(res);
}

void main(){
	long double a; long double b; long long count; //count (of rectangles)
	printf("Enter left border and right border: ");
	scanf("%Lf%Lf", &a, &b);
	printf("[for exit type -1]\n");
	while(count!=-1){
		printf("Enter count of rectangles: ");
		scanf("%lli", &count);
		if(a < b && a >= 0 && (M_PI - b) > 0.00000001 && count > 0){
			printf("%lli %.5Lf %.5Lf\n", count, calculate_by_rect_method(a, b, count), calculate_by_simpsons_rule(a, b, count));
		}
		else{
			printf("Wrong input. ");
			if (a >= b){
				printf("Left  border should be less than right border. Please, enter them again: ");
				scanf("%Lf%Lf", &a, &b);
			}
			else if (a < 0){
				printf("Left border should be not less than 0. Please, enter left border and right border again: ");
				scanf("%Lf%Lf", &a, &b);
			}
			else if ((M_PI - b) < 0.00000001){
				printf("Right border should be not more than pi. Please, enter left border and right border again: ");
				scanf("%Lf%Lf", &a, &b);
			}
			else if (count <= 0 && count != -1) {
				printf("Count should be more than 0.\n");
			}
			else if (count != -1) {
				printf("Unexpected error. Make sure that borders are real numbers and count of rectangles is natural number. Enter left border and right border: ");
				scanf("%Lf%Lf", &a, &b);
			}
		}
	}
	printf("end.\n");
}
