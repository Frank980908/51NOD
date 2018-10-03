/*#include <bits/stdc++.h>
using namespace std;
const int AX = 1e4+66;
int index1 , tot ;
int head[AX];
struct Node{
	int u , v;
	int next1;
}G[AX*2];
int n , m ;
int bcc_cnt;
int DFN[AX];
int iscut[AX];
int bccno[AX];
int LOW[AX];
stack<Node>S;
vector<int> bcc[AX];

void init(){
	bcc_cnt = 0;
	tot = 0 ;
	index1 = 0;
	memset(head , -1 , sizeof(head));
}

void add( int u , int v ){
	G[tot].u = u ;  G[tot].v = v;
	G[tot].next1 = head[u];
	head[u] = tot ++ ;
	G[tot].u = v; G[tot].v = u;
	G[tot].next1 = head[v];
	head[v] = tot ++ ;
}

void Tarjan( int x , int fa ){
	int son = 0;
	DFN[x] = LOW[x] = ++index1;
	for( int i = head[x] ; ~i ; i = G[i].next1 ){
		if( !DFN[G[i].v] ){
			S.push(G[i]);
			son ++ ;
			Tarjan( G[i].v , x );
			LOW[x] = min( LOW[x] , LOW[G[i].v] );
			if( LOW[G[i].v] >= DFN[x] ){
				iscut[x] = 1;
				++bcc_cnt;
				bcc[bcc_cnt].clear();
				while(1){
					Node tmp = S.top(); S.pop();
					if( bccno[tmp.u] != bcc_cnt ){
						bcc[bcc_cnt].push_back(tmp.u);
						bccno[tmp.u] = bcc_cnt;
					}
					if( bccno[tmp.v] != bcc_cnt ){
						bcc[bcc_cnt].push_back(tmp.v);
						bccno[tmp.v] = bcc_cnt;
					}
					if( tmp.u == x && tmp.v == G[i].v ){
						break;
					}
				}
			}
		}else{
			if( DFN[G[i].v] < DFN[x] && G[i].v != fa ){
				S.push(G[i]);
				LOW[x] = min( LOW[x] , DFN[G[i].v] );
			}
		}
	}
	if( fa < 0 && son == 1 ){
		iscut[x] = 0;
	}
}

void Find_Cut( ){
	memset( DFN , 0 ,sizeof(DFN) );
	memset( LOW , 0 ,sizeof(LOW) );
	memset( iscut , 0 ,sizeof(iscut) );
	memset( bccno , 0 ,sizeof(bccno) );
	for( int i = 1 ; i <= n ; i++ ){
		if( !DFN[i] ){
			Targan( 1 , -1 );
		}
	}
}

int main(){
	cin >> n >> m ;
	init();
	int x , y ;
	for( int i = 0 ; i < m ; i++ ){
		add( x , y );
	}
	Find_Cut();
	return 0;
}*/

#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int AX = 1e5+66;
int index1 , tot ;
int head[AX];
struct Node{
	int u , v;
	int next1;
}G[AX*2];
int n , m ;
int bcc_cnt;
int DFN[AX];
int iscut[AX];
int bccno[AX];
int LOW[AX];
stack<Node>S;
vector<int> bcc[AX];

void init(){
	tot = 0 ;
	memset(head , -1 , sizeof(head));
}

void add( int u , int v ){
	G[tot].u = u ; G[tot].v = v;
	G[tot].next1 = head[u];
	head[u] = tot ++;

	G[tot].u = v; G[tot].v = u;
	G[tot].next1 = head[v];
	head[v] = tot++;
}

void Tarjan( int x , int fa ){
	int son = 0;
	DFN[x] = LOW[x] = ++index1;
	for( int i = head[x] ; ~i ; i = G[i].next1 ){
		if( !DFN[G[i].v] ){
			S.push(G[i]);
			son ++ ;
			Tarjan( G[i].v , x );
			LOW[x] = min( LOW[x] , LOW[G[i].v] );
			if( LOW[G[i].v] >= DFN[x] ){
				iscut[x] = 1;
				++bcc_cnt;
				bcc[bcc_cnt].clear();
				while(1){
					Node tmp = S.top(); S.pop();
					if( bccno[tmp.u] != bcc_cnt ){
						bcc[bcc_cnt].push_back(tmp.u);
						bccno[tmp.u] = bcc_cnt;
					}
					if( bccno[tmp.v] != bcc_cnt ){
						bcc[bcc_cnt].push_back(tmp.v);
						bccno[tmp.v] = bcc_cnt;
					}
					if( tmp.u == x && tmp.v == G[i].v ){
						break;
					}
				}
			}
		}else{
			if( DFN[G[i].v] < DFN[x] && G[i].v != fa ){
				S.push(G[i]);
				LOW[x] = min( LOW[x] , DFN[G[i].v] );
			}
		}
	}
	if( fa < 0 && son == 1 ){
		iscut[x] = 0;
	}
}

void Find_Cut( ){
	bcc_cnt = 0;
	index1 = 0;
	memset( DFN , 0 ,sizeof(DFN) );
	memset( LOW , 0 ,sizeof(LOW) );
	memset( iscut , 0 ,sizeof(iscut) );
	memset( bccno , 0 ,sizeof(bccno) );
	for( int i = 1 ; i <= n ; i++ ){
		if( !DFN[i] ){
			Tarjan( i , -1 );
		}
	}
}

int main(){
	int C = 0;
	while( ~scanf("%d",&m ) && m ){
		init();
		int x , y ;
		n = 0;
		for( int i = 0 ; i < m ; i++ ){
			cin >> x >> y;
			n = max( n , max(x,y) );
			add( x , y );
		}
		Find_Cut();
	/*	cout << "-------" << endl;
		for( int i = 1 ; i <= bcc_cnt ; i ++ ){
			for( int j = 0 ; j < bcc[i].size() ; j ++ ){
				cout << bcc[i][j] << ' ';
			}
			cout << endl;
		}
		for( int i = 1 ; i <= n ;i ++ ){
			if( iscut[i] ) cout << i << endl;
		}
		cout << "-------" << endl;*/
		cout << "Case "<< ++C << ": " ;
		if( bcc_cnt == 1 ){
			cout << 2 << ' ' << (LL)n*(n-1) / 2 << endl;
		}else{
			LL res = 1;
			LL ans = 0;
			for( int i = 1 ; i <= bcc_cnt ; i ++ ){
				int size = bcc[i].size();
				int cut_tot = 0;
				for( int j = 0 ; j < size ; j++ ){
					if( iscut[bcc[i][j]] ){
						cut_tot ++ ;
					}
				}	
				if( cut_tot == 1 ){
					ans ++ ;
					res *= (LL)(size-1);
				}
			}
			cout << ans << ' ' << res << endl;
			
		}

	}
	return 0;
}
