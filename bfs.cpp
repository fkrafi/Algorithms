#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define SZ 100
#define INF 9867684
#define NIL -1
#define WHITE 0
#define GRAY 1
#define BLACK 2


int nV, nE;
int color[SZ];
queue<int> Q;
int d[SZ], pi[SZ];
vector<int> edge[SZ];


void bfs(int S){
	int i, u, v;
	for(u=1; u<=nV; u++){
		color[u] = WHITE;
		d[u] = INF;
		pi[u] = NIL;
	}
	color[S] = GRAY;
	d[S] = 0;
	pi[S] = NIL;
	Q.push(S);
	while( !Q.empty() ){
		u = Q.front();
		Q.pop();
		for(i=0; i<edge[u].size(); i++){
			v = edge[u][i];
			if( color[v] == WHITE ){
				color[v] = GRAY;
				d[v] = d[u] + 1;
				pi[v] = u;
				Q.push(u);
			}
		}
		color[u] = BLACK;
	}
}

void print_path(int u){
	if( pi[u] == -1 ){
		printf("%d", u);
		return;
	}
	print_path(pi[u]);
	printf(" %d", u);
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
	int S;
	input();
	scanf("%d", &S);
	bfs(S);
	return 0;
}