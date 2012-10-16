#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SZ 1005
#define INF 2147483647
#define NIL -1

typedef pair<int, int> PII;

int nV, nE;
PII edges[SZ];
int w[SZ][SZ];
int d[SZ], pi[SZ];

void initalize_single_source(int s){
	for(int v=1; v<=nV; v++){
		d[v] = INF;
		pi[v] = NIL;
	}
	d[s] = 0;
}

void Relax(int u, int v){
	if( d[v] > d[u]+w[u][v] ){
		d[v] = d[u]+w[u][v];
		pi[v] = u;
	}
}

bool bellman_ford(int s){
	int i, j, u, v;
	initalize_single_source(s);
	for(i=1; i<nV; i++){
		for(j=0; j<nE; j++){
			Relax( edges[j].first, edges[j].second );
		}
	}
	for(j=0; j<nE; j++){
		u = edges[j].first;
		v = edges[j].second;
		if( d[v] > d[u]+w[u][v] )
			return false;
	}
	return true;
}

int main(){
	int i, u, v, cst, s;
	scanf("%d%d", &nV, &nE);
	for(i=0; i<nE; i++){
		scanf("%d%d", &u, &v, &cst);
		edges[i].first = u;
		edges[i].second = v;
		w[u][v] = cst;
	}
	scanf("%d", &s);
	bellman_ford(s);
	return 0;
}