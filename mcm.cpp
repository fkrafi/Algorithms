#include<stdio.h>
#define SZ 505
#define INF 999999999

int p[SZ];
int m[SZ][SZ];

int mcm(int i, int j){
	if( i==j )return 0;
	int k, q;
	m[i][j] = INF;
	for(k=i; k<j; k++){
		q = mcm(i, k) + mcm(k+1, j) + p[i-1]*p[k]*p[j];
		if( q<m[i][j] ){
			m[i][j] = q;
		}
	}
	return m[i][j];
}

int main(){
	freopen("mcm.txt", "r", stdin);
	int i, n;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &p[i]);
	}
	printf("%d\n", mcm(1, n-1));
	return 0;
}