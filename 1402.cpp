#include <bits/stdc++.h>
using namespace std;
const int AX = 1e5+66;
int a[AX];
int b[AX];
int lim[AX];
int main(){
	int T;
	cin >> T;
	while( T -- ){
		int n , m;
		memset( lim, -1 , sizeof(lim));
		memset( a, 0 , sizeof(a));
		memset( b, 0 , sizeof(b));
		cin >> n >> m;
		int x , y ;
		for( int i = 0 ; i < m ; i++ ){
			cin >> x >> y;
			lim[x] = y;
		}
		lim[1] = 0;
		int ans2 , ans1;
		ans1 = 0;
		ans2 = 0x3f3f3f;
		for( int i = 1 ; i <= n ; i ++ ){
			ans1++ ;
			if( lim[i] >= 0 ) ans1 = min( ans1 , lim[i] );
			a[i] = ans1;
		}
		for( int i = n ; i >= 1 ; i-- ){
			ans2++ ;
			if( lim[i] >= 0 ) ans2 = min( ans2 , lim[i] ); 
			b[i] = ans2;
		}
		int res = 0;
		for( int i = 1 ; i <= n ; i++ ){
			res = max( res ,min(a[i],b[i]));
		}
		cout << res << endl;
	}
	return 0;
}