/*#include <bits/stdc++.h>
using namespace std;
const int AX = 5e4+66;
typedef struct Node{
	struct Node *next1[2];
	int sum ;
	int val ;
	int id ; 
}TrieNode,*Trie;
Trie t[AX];
int root[AX];
int cnt ;

TrieNode* Trie_creatroot(){
	TrieNode* root = new TrieNode();
	root -> sum = 0 ;
	memset( root -> next1 , 0 , sizeof(root->next1) );
	return root ;
}

void insert( int val , int &x , int y ){
	x = ++cnt;
	int tmp = x ;
	t[x] = Trie_creatroot();
	for( int i = 31 ; i >= 0 ; i-- ){
		int c = ( val >> i ) & 1 ;

		t[tmp].next1[c^1] = t[y].next1[c^1];
		if( t[tmp] -> next1[c] == NULL ) t[tmp] -> next1[c] = Trie_creatroot();
		t[tmp] -> next1[c] -> id = ++cnt ;
		tmp = cnt ; y = t[y] -> next1[c] -> id;
	}
	t[tmp] -> sum = t[y] -> sum + 1 ;
}

int query( int val , int x , int y ){
	int ans = 0 ;
	int id_l ;
	int id_r ;
	for( int i = 31 ; i >= 0 ; i-- ){
		int j = ( val >> i ) & 1 ;
		id_l = t[x] -> next1[j] -> id;
		id_r = t[y] -> next1[j] -> id;
		if( t[id_r] -> sum - t[id_l] -> sum > 0 ){
			ans |= ( 1 << i ) ;
			x = t[x] -> next1[j] -> id ;
			y = t[y] -> next1[j] -> id;
		}else{  x = t[x] -> next1[j^1] -> id ; y = t[y] -> next1[j^1] -> id ;}
	}
	return ans ;
}


int main(){
	cnt = 0 ;
	int n , m;
	scanf("%d",&n);
	int x ; 
 	t[0] = Trie_creatroot();
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%d",&x);
		insert( x , root[i] , root[i-1] );
	}
	int l , r ;
	for( int i = 0 ; i < m ; i++ ){
		scanf("%d%d%d",&x,&l,&r);
		l++ ; r ++ ;
		printf("%d\n",query( x , root[l-1] , root[r] ) );
	}
	return 0 ;
}*/

#include <bits/stdc++.h>
using namespace std;
const int AX = 5e4+66;
int t[AX*35][2]; 
int sum[AX*35];
int root[AX];
int cnt ;

void insert( int val , int &x , int y ){	
	x = ++cnt ;
	int tmp = x; 
	for( int i = 31 ; i >= 0 ; i-- ){
		t[tmp][0] = t[y][0] ; t[tmp][1] = t[y][1];
		sum[tmp] = sum[y] + 1 ;
		int c = ( val >> i ) & 1 ;
		t[tmp][c] = ++cnt;
		tmp = t[tmp][c] ; y = t[y][c] ;
	}
	sum[tmp] = sum[y] + 1 ;
}

int query( int val , int x , int y ){
	int ans = 0 ;
	for( int i = 31 ; i >= 0 ; i-- ){
		int c = ( val >> i ) & 1 ;
		if( sum[t[y][c^1]] - sum[t[x][c^1]] > 0 ){
			ans |= ( 1 << i );
			x = t[x][c^1] ; y = t[y][c^1];
		}else{
			x = t[x][c] ; y = t[y][c];
		}
	}
	return ans ;
}

int main(){
	cnt = 0 ;
	int n , m;
	scanf("%d%d",&n,&m);
	int x ; 
	for( int i = 1 ; i <= n ; i ++ ){
		scanf("%d",&x);
		insert( x , root[i] , root[i-1] );
	}
	int l , r ;
	for( int i = 0 ; i < m ; i++ ){
		scanf("%d%d%d",&x,&l,&r); 
		l++ ; r ++ ;
		printf("%d\n",query( x , root[l-1] , root[r] ) );
	}
	return 0 ;
}