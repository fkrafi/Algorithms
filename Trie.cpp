#include<stdio.h>
#include<string.h>
#define SZ 15

char s[SZ];
bool flag;

struct node{
	int val;
	node *next[10];
	node(){
		val=0;
		memset(next,NULL,sizeof(next));
	}
};
node *root;

void insert(char *str){
	node *curr = root;
	int i, ch, len=strlen(str);
	for(i=0; i<len ;i++){
		ch = str[i] - '0';
		if(curr->next[ch] == NULL){
			curr->next[ch] = new node();
		}
		curr = curr->next[ch];
	}
	curr->val++;
}

void traverse(node *p){
	int i;
	for(i=0;i<10;i++){
		if(p->next[i]!=NULL){
			if( p->val ){
				flag =false;
			}
			traverse(p->next[i]);
			delete p->next[i];
		}
	}
}

int main(){
	root = new node();
	gets(s);
	insert(s);
	traverse(root);
	return 0;
}