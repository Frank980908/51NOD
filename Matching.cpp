#include <bits/stdc++.h>
using namespace std;
const int AX = 200;
int g[AX][AX];
int linker[AX];
bool used[AX];
int m,n;

bool dfs( int u ){
	int v;
	for( v = m+1 ; v <= n ;v ++ ){
		if( g[u][v] && !used[v] ){
			used[v] = true;
			if( linker[v] == -1 || dfs(linker[v]) ){
				linker[v] = u;
				return true;
			}
		}
	}
	return false;
}

int xyl(){
	int res = 0;
	int u;
	memset(linker,-1,sizeof(linker));
	for( u = 1 ; u <= m ; u++ ){
		memset(used,0,sizeof(used));
		if( dfs(u) ) res++;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>m>>n;
	int x,y;
	while( cin>>x>>y && x != -1 && y != -1 ){
		g[x][y] = 1;
	}
	int ans = xyl();
	if( ans == 0  ) printf("No Solution!\n");
	else cout<<ans<<endl;
	return 0;
}