#include <bits/stdc++.h>
#define LL long long 
using namespace std;
const int AX = 5e2+6;
int a[AX][AX];
int b[AX][AX];
int vis[AX];
int n , m , p;
int tot ;
map<int,int>mp[AX];
int main(){
	tot = 0;
	scanf("%d%d%d",&n,&m,&p);
	for( int i = 0 ; i < n ; i++ ){
		for( int j = 0 ; j < m ; j++ ){
			scanf("%d",&a[i][j]);
		}
		sort( a[i] , a[i] + m );
	}
	for( int i = 0 ; i < n ;  i++ ){
		for( int j = m - 1; j > 0 ; j-- ){
			b[i][j] = a[i][j] - a[i][j-1] ;
			mp[i][b[i][j]] = j;
		}
		b[i][0] = b[i][m-1] - b[i][0];
	}	
	cout << endl; 
	for( int i = 0 ; i < n ; i++ ){
		for( int j = 0 ; j < n ; j++ )
		cout << b[i][j] << ' ';
		cout << endl;
	}
	for( int i = 0 ; i < n ; i++ ){
		vis[i] = i;
	}
	for( int i = 0 ; i < n ; i++ ){
		if( vis[i] != i ) continue;
		for( int j = 0 ; j < n ; j++ ){
			if( vis[j] != j ) continue;
			if( i == j ) continue;
			int f1 = 1;
			int t = 1;
			if( mp[j][b[i][t]] ){
				int id = mp[j][b[i][1]];
				for( int k = id + 1 ; k < n ; k ++ ){
					if( b[j][k] != b[i][++t] ){
						f1 = 0 ; break;
					}
				}
				for( int k = 0 ; k < id ; k++ ){
					if( b[j][k] != b[i][++t] ){
						f1 = 0 ; break;
					}
				}
			}else f1 = 0;
			if( f1 ){
				vis[j] = i;
			}
		}
	}
	LL res = 0LL ;
	for( int i = 0; i < n ; i++ ){
		int ans = 0;
		for( int j = 0 ; j < n ; j++ ){
			if( vis[j] == i ){
				ans ++;
			}
		}
		res += ans * ( ans - 1 ) / 2;
	}
	cout << res << endl;
	return 0 ;
}
