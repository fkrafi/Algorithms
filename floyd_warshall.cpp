/************** Floyd Warshall ***********/

#include<stdio.h>
#include<math.h>
#define SZ 105
#define INF 2147483647

int nV, nC, wght[SZ][SZ];

int min(int a, int b){
	return (a<b)?a:b;
}

int max(int a, int b){
	return (a>b)?a:b;
}

void init(){
	int i, j;
	for(i=1; i<=nV; i++)
		for(j=1; j<=nV; j++)
			wght[i][j] = -INF;
}

void floyd_warshall(){
	int i, j, k;
	for(k=1; k<=nV; k++)
		for(i=1; i<=nV; i++)
			for(j=1; j<=nV; j++)
				wght[i][j] = min(wght[i][j], wght[i][k]+wght[k][j]);
}

int main(){
	int u, v, w, i, cs=1;
	scanf("%d%d", &nV, &nC);
	init();
	for(i=0; i<nC; i++){
		scanf("%d%d%d", &u, &v, &w);
		wght[u][v] = wght[v][u] = w;
	}
	floyd_warshall();
	scanf("%d%d%d", &u, &v);
	printf("%d\n", wght[u][v]);
	return 0;
}

/***************************
to find the max value 
wght[i][j] = max(wght[i][j], min(wght[i][k], wght[k][j]));
***************************/

/***************************
to find the max value 
wght[i][j] = min(wght[i][j], max(wght[i][k], wght[k][j]));

***************************/
