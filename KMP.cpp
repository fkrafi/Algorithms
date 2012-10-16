#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define SZ 1000005

int pi[SZ];
char T[SZ], P[SZ];
int tsize, psize;

void compute_prefix_function(){
	int k = -1;
	int i = 1;
	pi[0] = k;
	for (i = 1; i < psize; i++) {
		while (k > -1 && P[k+1] != P[i])
			k = pi[k];
		if (P[i] == P[k+1])
			k++;
		pi[i] = k;
	}
}

int kmp(){
	int i;
	int k = -1;
	compute_prefix_function();
	for (i = 0; i < tsize; i++) {
		while (k > -1 && P[k+1] != T[i])
			k = pi[k];
		if (T[i] == P[k+1])
			k++;
		if (k == psize - 1) {
			printf("Pattern found at %d\n", i-k);
			k = pi[k];
		}
	}
	return 1;
}

int main(){
	gets(T);
	gets(P);
	tsize = strlen(T);
	psize = strlen(P);
	kmp();
	return 0;
}