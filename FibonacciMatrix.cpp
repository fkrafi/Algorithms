#include <stdio.h>

// z = x*y, mult of 2-by-2 matrices
void mult(int x[2][2], int y[2][2], int z[2][2]){
	int i, j, k;
	for (i = 0; i < 2; i++) {
		for (j = 0; j < 2; j++) {
			z[i][j] = 0;
			for (k = 0; k < 2; k++){
				z[i][j] += x[i][k] * y[k][j];
			}
		}
	}
}

// y = x, perhaps confusing order
void copy(int x[2][2], int y[2][2]) {
	int i, j;
	for (i = 0; i < 2; i++){
		for (j = 0; j < 2; j++){
			y[i][j] = x[i][j];
		}
	}
}


int get_fib(int n){
	int a[2][2] = {{0, 1}, {1, 1}}, b[2][2], c[2][2];
	copy(a, c);
	copy(c, b);
	mult(a, b, c);
	return c[0][1];
}


int main(){
	int n;
	while( scanf("%d", &n) && n ){
		printf("%2d\t=\t%10d\n", get_fib(n));
	}
	return 0;
}