#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;
#define SZ 105


int nV, nC;
int seen[SZ], vst;
stack<int> S, ES;
vector<int> edge[SZ], rEdge[SZ];

void init(){
	int i;
	vst++;
	S = ES;
	for(i=0; i<SZ; i++){
		edge[i].clear();
		rEdge[i].clear();
	}
}

void dfs(int u){
	int i, v;
	seen[u] = vst;
	for(i=0; i<edge[u].size(); i++){
		v = edge[u][i];
		if( seen[v] != vst )
			dfs(v);
	}
	S.push(u);
}

void scc(int u, int flag){
	int i, v;
	seen[u] = vst;
	if( flag ){
		printf("%d", u);
	}else{
		printf(", %d", u);
	}
	for(i=0; i<rEdge[u].size(); i++){
		v = rEdge[u][i];
		if( seen[v] != vst )
			scc(v, 0);
	}
}

void input_graph(){
	int i, u, v;
	for(i=0; i<nC; i++){
		scanf("%d%d", &u, &v);
		edge[u].push_back(v);
		rEdge[v].push_back(u);
	}
}


int main(){
	int i;
	scanf("%d%d", &nV, &nC);
	init();
	input_graph();
	for(i=1; i<=nV; i++){
		if( seen[i] != vst )
			dfs(i);
	}
	vst++;
	while( !S.empty() ){
		i = S.top(); S.pop();
		if( seen[i] != vst ){
			scc(i, 1);
			printf("\n");
		}
	}
	return 0;
}