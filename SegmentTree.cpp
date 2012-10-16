#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<sstream>
#include<iostream>
using namespace std;
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
#define memo(a,v) memset(a,v,sizeof(a))
#define PI 2*acos(0.0)
#define pb push_back
#define all(a) a.begin(),a.end()
#define EPS 1e-8
#define i64 long long
#define MAX 100005

#define QUERY 1
#define UPDATE 2

int A[MAX<<2];

int lazy[MAX<<2],input[MAX];

void update(int lf,int rt,int idx,int x,int y,int val){
	if(lf>=x && rt<=y){
		lazy[idx] += val;
		A[idx]+= (rt - lf + 1)*val;
		return;
	}
	int mid = (lf + rt) /2;
	if(x<=mid)                 // some part of the update range is in the left side
		update(lf,mid,2*idx,x,y,val);
    if(y>mid)                  // some part of the update range is in the right side
        update(mid+1,rt,2*idx+1,x,y,val);
    A[idx] = A[2*idx] + A[2*idx+1];   // update the value of the current node from its children
}

int query(int lf,int rt,int idx,int x,int y){
	
	if(lf>=x && rt<=y){
		
		return A[idx];
	}
	int mid = (lf + rt) / 2 ,ret = 0;
	if(lazy[idx]){ // have to propagate the lazy value to the children
		lazy[2*idx] += lazy[idx];     // pass lazy to children
		lazy[2*idx+1] += lazy[idx];
		
		A[2*idx] += (mid - lf +1)*lazy[idx];  // adjust the original sum of children
		A[2*idx+1] += (rt - mid) * lazy[idx];
		lazy[idx] = 0;      // reset the lazy value of current node
	}
	
	if(x<=mid)                 // some part of the query range is in the left side
		ret+=query(lf,mid,2*idx,x,y);
    if(y>mid)                  // some part of the query range is in the right side
        ret+=query(mid+1,rt,2*idx+1,x,y);
	
	
	return ret;
	
}
void build(int lf,int rt,int idx){
	lazy[idx] = 0;           // initialize lazy vlue to 0
	if(lf==rt){
		A[idx] = input[lf];
		return ;
	}
	int mid = (lf + rt) /2;
	
	build(lf,mid,2*idx);       // call left child
	build(mid+1,rt,2*idx + 1);  // call right child
	A[idx] = A[2*idx] + A[2*idx+1];  // answer for current node is the sum of its children value
}
int main()
{
    int n,i,q,type,x,y,val;
	scanf("%d",&n);     // number of integer in total
	for(i = 0;i<n;i++)
        scanf("%d",&input[i]);
    build(0,n-1,1);     // build the tree, root node is in index 1
    scanf("%d",&q);   // number of query
    for(i = 0;i<q;i++){
        scanf("%d",&type);     // which type , query or update, QUERY = 1, UPDATE = 2
        if(type == QUERY){
            scanf("%d %d",&x,&y);  // print the sum from index x to y
            printf("%d\n",query(0,n-1,1,x,y));
        }
        else if(type == UPDATE){
            scanf("%d %d %d",&x,&y,&val);   // add val to each index from x to y
            update(0,n-1,1,x,y,val);
        }
    }
	
	return 0;
}
