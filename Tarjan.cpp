/*#include <bits/stdc++.h>
using namespace std;
const int AX = 1e3+66;
struct Node
{
	int v;
	int next1;
}G[AX];

int head[AX];
int vis[AX];
	int tot = 0;
int index = 0 ;

int DFN[AX], LOW[AX];

int cnt = 0;
void add( int u , int v ){
	G[++cnt].next1 = head[u];
	G[cnt].v = v;
	head[u] = cnt;
}
int stack1[AX];
void tarjan( int x ){
	DFN[x] = LOW[x] = ++tot;
	stack1[++index] = x;
	vis[x] = 1;
	for( int i = head[x] ; ~i ; i = G[i].next1 ){
		if( !DFN[G[i].v] ){
			tarjan(G[i].v);
			LOW[x] = min(LOW[x],LOW[G[i].v]);
		}else if( vis[G[i].v] ){
			LOW[x] = min( LOW[x] , DFN[G[i].v] );
		}
	}
	if( LOW[x] == DFN[x] ){
		do{
			printf("%d ",stack1[index]);
			vis[stack1[index]] = 0;
			index --;
		}while( x != stack1[index+1] );
		printf("\n");
	}
}

int main(){
	int n , m ;
	memset( head , -1 , sizeof(head) );
	cin >> n >> m ;
	int x , y; 
	for( int i = 1 ; i <= m; i  ++ ){
			cin >> x >> y;
			add(x,y);
	}
	for( int i = 1 ; i <= n ; i ++ ){
		if( !DFN[i] ) tarjan(i);
	}
	return 0 ;
}
*/
#include <bits/stdc++.h>
using namespace std;
const int AX = 1e5+6;
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
	//int flag = 0;
	DFN[x] = 1;
	for( int i = head[x] ; ~i ; i = G[i].next1 ){
		if( !cutEdge[i] ){
			cutEdge[i] = cutEdge[i^1] = 1;
			mp[x] = mp[G[i].v] = id;
			/*flag = 1;
			printf("%d %d",x , G[i].v);*/
			if( !DFN[G[i].v] ) dfs(G[i].v);
		}
	}
	//return flag;
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
		if(  mp[x] && mp[y] && mp[x] == mp[y]){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0 ;
}