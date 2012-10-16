#include<stdio.h>
#include<string.h>
#define SZ 105

int mem[SZ][SZ];
char s1[SZ], s2[SZ];

int MAX(int a, int b){
	return (a>b)?a:b;
}

int lcs(){
	int i, j;
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	for(i=1; i<=len1; i++){
		for(j=1; j<=len2; j++){
			if( s1[i-1] == s2[j-1] ){
				mem[i][j] = mem[i-1][j-1] + 1;
			}else{
				mem[i][j] = MAX(mem[i-1][j], mem[i][j-1]);
			}
		}
	}
	return mem[len1][len2];
}


int main(){
	gets(s1);
	gets(s2);
	printf("%d\n", lcs());
	return 0;
}