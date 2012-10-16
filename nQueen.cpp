#include<stdio.h>
#define SZ 1000

int x[SZ];

int ABS(int n){
	return (n<0)?-n:n;
}

int Place(int k, int i){
	int j;
	for(j=1; j<=k-1; j++){
		if((x[j]==i) || (ABS(x[j]-i) == ABS(j-k)))
			return 0;
	}
	return 1;
}

void BtKt(int r, int n){
	if( r>n ){
		/*for(int i=1; i<=n; i++)
			printf("%d ", x[i]);
		printf("\n");*/
		return;
	}
	for(int c=1; c<=n; c++){
		if( Place(r, c) ){
			x[r] = c;
			BtKt(r+1, n);
		}
	}
}

int main(){
	int n;
	printf("No of Queens :: ");
	scanf("%d", &n);
	BtKt(1, n);
	return 0;
}
