#include<stdio.h>

int main(){
	__int64 t, i, maxSum, sum, start, tempStart, end, a, N, cs;
	scanf("%I64d", &t);
	for(cs=1; cs<=t; cs++){
		scanf("%I64d", &N);
		maxSum = -1001;
		sum = 0;
		start = tempStart = 1;
		for(i=1; i<=N; i++){
			scanf("%I64d", &a);
			sum += a;
			if( maxSum<sum ){
				maxSum = sum;
				start = tempStart;
				end = i;
			}
			if( sum<0 ){
				sum = 0;
				tempStart = i+1;
			}
		}
		printf("Case %I64d:\n%I64d %I64d %I64d\n", cs, maxSum, start, end);
		if( cs!=t )printf("\n");
	}
	return 0;
}