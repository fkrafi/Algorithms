#include<stdio.h>
#define SZ 50005

int can[SZ];
int coins[105];

void init(int T){
	int i;
	for(i=0; i<T; i++)
		can[i] = 0;
	can[0] = 1;
}

void coin_change(int N, int T){
	int i, j;
	for(i=0; i<N; i++){
		for(j=T; j>=1; j--){
			if( j-coins[i]<0 )continue;
			if( can[j-coins[i]] )
				can[j] = 1;
		}
	}
}

int ABS(int n){
	return (n<0)?-n:n;
}

int main(){
	int N, M, i;
	scanf("%d%d", &N, &M);
	for(i=0; i<N; i++){
		scanf("%d", &coins[i]);
	}
	init(M);
	coin_change(N, M);
	printf("%s\n", can[M] ? "Can Make" : "Cannot Make");
	return 0;
}