/************ Articulation_Points ************/
#include<stdio.h>
#include<string.h>
#include<vector>
#include<set>
using namespace std;

#define SZ 10005
#define WHITE 0
#define GREY 1
#define BLACK 2
#define Null -1


int tm;
int d[SZ];
int Low[SZ];
int pred[SZ];
int color[SZ];

set<int> S;
vector<int> edges[SZ];

void init(int n){
	tm = 0;
	S.clear();
	for(int i=0; i<=n; i++){
		pred[i] = Null;
		color[i] = WHITE;
		edges[i].clear();
	}
}

int MIN(int a, int b){
	return (a<b)?a:b;
}

void ArtPt(int v) {
	int i, w, cnt=0;
	color[v] = GREY;
	Low[v] = d[v] = ++tm;
	for(i=0; i<edges[v].size(); i++){
		w = edges[v][i];
		if(color[w] == WHITE) {
			pred[w] = v;
			ArtPt(w);
			cnt++;
			if (pred[v] == Null) {
				if(cnt==2)S.insert(v);
			}else if (Low[w] >= d[v])S.insert(v);
			Low[v] = MIN(Low[v], Low[w]);
		}else if (w != pred[v]) { 
			Low[v] = MIN(Low[v], d[w]);
		}
	}
	color[v] = BLACK;
}

int main(){
	freopen("input.txt", "r", stdin);
	int t, i, n, m, u, v, cs;
	scanf("%d", &t);
	for(cs=1; cs<=t; cs++){
		scanf("%d%d", &n, &m);
		init(n);
		for(i=0; i<m; i++){
			scanf("%d%d", &u, &v);
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		for(i=1; i<=n; i++){
			if( color[i]==WHITE ){
				ArtPt(i);
			}
		}
		printf("Case %d: %d\n", cs, S.size());
	}
	return 0;
}