#include<stdio.h>
#include<vector>
using namespace std;
#define SZ 100
#define NIL -1
#define WHITE 0
#define GRAY 1
#define BLACK 2

int nV, nE, Time;
vector<int> edge[SZ];
int color[SZ], d[SZ], f[SZ], pi[SZ];



void dfs_visit(int u){
	color[u] = GRAY;
	Time = Time + 1;
	d[u] = Time;
	for(int i=0; i<edge[u].size(); i++){
		int v = edge[u][i];
		if( color[v] == WHITE ){
			pi[v] = u;
			dfs_visit(v);
		}
	}
	color[u] = BLACK;
	f[u] = Time = Time + 1;
}

void dfs(){
	int u;
	for(u=1; u<=nV; u++){
		color[u] = WHITE;
		pi[u] = -1;
	}
	Time = 0;
	for(u=1; u<=nV; u++){
		if( color[u] == WHITE ){
			dfs_visit(u);
		}
	}
}


void input(){
	int i, u, v;
	printf("Insert number of node and number of edges :: ");
	scanf("%d%d", &nV, &nE);
	puts("Insert edges :: ");
	for(i=0; i<nE; i++){
		scanf("%d%d", &u, &v);
		edge[u].push_back(v);
	}
}

int main(){
	input();
	dfs();
	return 0;
}