#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> pii;

vector<pii> A;
int p[200005], rank[200005];
int nE, nV;

struct graph{
	int u, v, c;
}edges[200005];

void make_set(int x){
	p[x] = x;
	rank[x] = 0;
}


int find_set(int x){
	if( x != p[x] )
		p[x] = find_set(p[x]);
	return p[x];
}

void link(int x, int y){
	if( rank[x] > rank[y] ){
		p[y] = x;
	}else{
		p[x] = y;
		if( rank[x] == rank[y] )
			rank[y]++;
	}
}

void Union(int x, int y){
	link(find_set(x), find_set(y));
}


bool comp( graph a, graph b ){
	return a.c<b.c;
}


int MSTKruskal(){
	int i, ret=0;
	pii node;
	for(i=0; i<nV; i++)
		make_set(i);
	sort(edges, edges+nE, comp);
	for(i=0; i<nE; i++){
		node.first = edges[i].u;
		node.second= edges[i].v;
		if( find_set(node.first) != find_set(node.second) ){
			A.push_back(node);
			ret += edges[i].c;
			Union(node.first, node.second);
		}
	}
	return ret;
}


int main(){
	int i;
	scanf("%d%d", &nV, &nE);
	for(i=0; i<nE; i++){
		scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].c);
	}
	printf("%d\n", MSTKruskal());
	
	return 0;
}