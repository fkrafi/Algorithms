#include<stdio.h>
#include<string.h>
#include<string>
using namespace std;
#define SZ 1005
#define DELETE	1
#define INSERT	2
#define CHANGE	3
#define SAME	4


char s1[SZ], s2[SZ];
int d[SZ][SZ];
int op[SZ][SZ];
int len1, len2;

int MIN(int a, int b){
	return (a<b)?a:b;
}


void dp(){
	int a[3], i, j, k;
	for(i=0; i<SZ; i++){
		d[i][0] = i;
		op[i][0] = DELETE;
		d[0][i] = i;
		op[0][i] = INSERT;
	}
	for(i=1; i<=len1; i++){
		for(j=1; j<=len2; j++){
			a[0] = d[i-1][j] + 1;
			a[1] = d[i][j-1] + 1;
			a[2] = d[i-1][j-1] + (s1[i-1]!=s2[j-1]);
			d[i][j] = MIN(a[0], MIN(a[1], a[2]));
			for(k=0; k<3; k++){
				if( d[i][j]==a[k] ){
					op[i][j] = k+1;
				}
				if( k==2 && s1[i-1]==s2[j-1] ){
					op[i][j] = 4;
				}
			}
		}
	}
}

void backtrace(int i, int j){
	if( i<=0 && j<=0 )return;
	if( op[i][j] == DELETE ){
		backtrace(i-1, j);
		printf("Delete %d\n", j+1);
	}else if( op[i][j] == INSERT ){
		backtrace(i, j-1);
		printf("Insert %d,%c\n", j, s2[j-1]);
	}else if( op[i][j] == CHANGE ){
		backtrace(i-1, j-1);
		printf("Replace %d,%c\n", j, s2[j-1]);
	}else{
		backtrace(i-1, j-1);
	}
}


void print(){
	for(int i=0; i<=len1; i++){
		for(int j=0; j<=len2; j++){
			printf("%2d", op[i][j]);
		}
		printf("\n");
	}
}

int main(){
	gets(s1);
	gets(s2);
	len1 = strlen(s1);
	len2 = strlen(s2);
	dp();
	printf("%d\n", d[len1][len2]);
	print();
	return 0;
}