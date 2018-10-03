#include <bits/stdc++.h>
#define INF 12345678
using namespace std;
const int AX = 4e2 + 6;
int G[AX][AX];
int G2[AX][AX];  
int P[AX];
int dis[AX];
int n , m ;

void init( int v0 ){
	for( int i = 1 ; i <= n ; i++ ){
		for( int j = 1 ; j <= n ; j ++ ){
			G[i][j] = INF;
		}
	}
	for( int i = 1 ; i <= n ; i++ ){
		dis[i] = INF;
		P[i] = 0;
	}
	memset(P,0,sizeof(P));
	dis[v0] = 0;
	P[v0] = 1;
}
void init2( int v0 ){
	for( int i = 1 ; i <= n ; i++ ){
		for( int j = 1 ; j <= n ; j ++ ){
			G2[i][j] = INF;
		}
	}
	for( int i = 1 ; i <= n ; i++ ){
		dis[i] = INF;
		P[i] = 0;
	}
	memset(P,0,sizeof(P));
	dis[v0] = 0;
	P[v0] = 1;
}

void dijista1( int v0 ){
	int k = v0;
	for( int t = 1 ; t < n ; t++ ){
		for( int i = 1 ; i <= n ; i++ ){
			if( !P[i] && (G[k][i] != 0) ){ 
				if( dis[i] > dis[k] + G[k][i] ){
					dis[i] = dis[k] + G[k][i];
				}
			}
		}
		int index , minus = INF;
		for( int i = 1 ; i <= n ; i++ ){
			if( !P[i] ){
				if( minus > dis[i] ){
					minus = dis[i];
					index = i;
				}
			}	
		}
		k = index;
		P[k] = 1;
	}
}

void dijista2( int v0 ){
	int k = v0;
	for( int t = 1 ; t < n ; t++ ){
		for( int i = 1 ; i <= n ; i++ ){
			if( !P[i] && (G2[k][i] != 0) ){ 
				if( dis[i] > dis[k] + G2[k][i] ){
					dis[i] = dis[k] + G2[k][i];
				}
			}
		}
		int index , minus = INF;
		for( int i = 1 ; i <= n ; i++ ){
			if( !P[i] ){
				if( minus > dis[i] ){
					minus = dis[i];
					index = i;
				}
			}	
		}
		k = index;
		P[k] = 1;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	if( m == 0 ){
		printf("-1\n");
	}else{

		int u , v;
		init(1);
		for( int i = 0 ; i < m ; i++ ){
			scanf("%d%d",&u,&v);
			G[u][v] = 1;
			G[v][u] = 1;
		}
		if( m == (n-1)*n/2 ){
			printf("-1\n");
			return 0;
		}
		dijista1(1);
		int a = dis[n];
		init2(1);
		for( int i = 1 ; i <= n ; i++ ){
			for( int j = 1 ; j <= n ; j++ ){
				if( i == j ) continue;
				if( G[i][j] == INF ){
					G2[i][j] = 1 ;
					G2[j][i] = 1 ;
				}
			}
		}
		dijista2(1);
		int b = dis[n];
		if( a == INF || b == INF ){
			printf("-1\n");
		}else{
			printf("%d\n",max(a,b));
		}
	}
	return 0;
}