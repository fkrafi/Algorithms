#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
#define SZ 100
#define MAX 2147483647

int cost[SZ], wght[SZ][SZ], seen[SZ][SZ], init, pi[SZ];

class comp{
public:
	bool operator()(const int &a, const int &b)const{
		return cost[a] > cost[b];
	}
};

priority_queue<int, vector<int>, comp> q;
vector<int> edge[SZ];

int dijkstra(int S, int E){
	int u, v, i;
	cost[S] = 0;
	pi[S] = -1;
	q.push(S);
	while(!q.empty()){
		u = q.top();
		for(i=0; i<edge[u].size(); i++){
			v = edge[u][i];
			if(seen[u][v] == init)continue;
			if(cost[v] > wght[u][v] + cost[u]){
				cost[v] = wght[u][v] + cost[u];
				pi[v] = u;
				q.push(v);
			}
		}
		q.pop();
	}
	return cost[E];
}

void print_path(int i){
	if(pi[i] == -1){
		printf(" %d", i);
		return;
	}
	print_path(pi[i]);
	printf(" %d", i);
}

int main(){
	int n, i, j, t, w, v, S, E, C=1;
	init = 1;
	while(scanf("%d", &n)){
		if(!n)break;
		for(i=1; i<=n; i++)
		{
			scanf("%d", &t);
			edge[i].clear();
			cost[i] = MAX;
			for(j=0; j<t; j++)
			{
				scanf("%d%d", &v, &w);
				edge[i].push_back(v);
				wght[i][v] = w;
			}
		}
		scanf("%d%d", &S, &E);
		w = dijkstra(S, E);
		printf("Case %d: Path =", C++);
		print_path(E);
		printf("; %d second delay\n", w);
		init++;
	}
	return 0;
}