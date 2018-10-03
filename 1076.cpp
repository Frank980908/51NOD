
#include <bits/stdc++.h>
using namespace std;
const int AX = 2e6+6;
int head[AX] , DFN[AX] , LOW[AX] , cutEdge[AX];
map<int,int>mp;
int n , m ;
int index , tot;
struct Node{
	int u,v;
	int next1;
}G[AX];
int id;
void init( ){
	tot = 0 ;
	id = 0;
	memset( head , -1 , sizeof(head));
}
void add( int u , int v ){
	G[tot].u = u ; G[tot].v = v;
	G[tot].next1 = head[u];
	head[u] = tot ++;

	G[tot].u = v; G[tot].v = u;
	G[tot].next1 = head[v];
	head[v] = tot++;
}

void tarjan( int x , int fa ){
	LOW[x] = DFN[x] = ++index;
	for( int i = head[x] ; ~i ; i = G[i].next1 ){
		if( !DFN[G[i].v] ){
			tarjan( G[i].v , x );
			LOW[x] = min( LOW[x] , LOW[G[i].v] );
			if( LOW[G[i].v] > DFN[x] ){
				cutEdge[i] = cutEdge[i^1] = 1;
			}
		}else if( G[i].v != fa ){
			LOW[x] = min( LOW[x] , DFN[G[i].v] );
		}
	}
} 


void Find_CutEage(){
	index = 0 ;
	memset( LOW , 0 , sizeof(LOW));
	memset( DFN , 0 , sizeof(DFN));
	memset( cutEdge , 0 , sizeof(cutEdge));
	for( int i = 1 ; i <= n ; i++ ){
		if( !DFN[i] ){
			tarjan( i , -1 );
		}
	}
}

void dfs( int x ){
	DFN[x] = 1;
	for( int i = head[x] ; ~i ; i = G[i].next1 ){
		if( !cutEdge[i] ){
			mp[x] = mp[G[i].v] = id;
			if( !DFN[G[i].v] ) dfs(G[i].v);
		}
	}
}

void BccEdge(){
	memset(DFN, 0 , sizeof(DFN));
	for( int i = 1; i <= n ; i ++ ){
		if( !DFN[i] ){
			id ++ ;
			dfs(i);
		}
	}
}

int main(){	
	cin >> n >> m ;
	int x , y;
	init();
	for( int i = 0 ; i < m ; i ++ ){
		cin >> x >> y;
		add(x ,y);
	}
	Find_CutEage();
	BccEdge();
	int q;
	cin >> q;

	while(q--){
		cin >> x >> y;
		if( mp[x] && mp[y] && mp[x] == mp[y] ){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0 ;
}