#include <bits/stdc++.h>
using namespace std;
const int AX = 5e4+66;
int a[AX];
int b[AX];
int vis[AX];
int res ;
int n ;

bool check( int len ){
	sort( b , b + len );
	for( int i = 1 ; i < len ; i++ ){
		if( a[i] != a[i-1] + 1 ){
			return false;
		}
	}
	return true;
}

void dfs( int id , int len , int lim ){
	b[len-1] = a[id];
	if( lim > n ){
		return ;
	}
	if( len == lim ){
		if( check( len ) ){
			res ++ ;
		}
		if( id == n - 1 ){
			dfs( 0 , 1 , lim + 1 );
		}
		return ;
	}
	vis[id] = 1;
	for( int i = 0 ; i < n ; i++ ){
		if( !vis[i] ){
			vis[i] = 1;
			dfs( i , len + 1 , lim )
			vis[i] = 0;
		}
	}
}

int main(){
	res = 0;
	cin >> n ;
	for( int i = 0 ; i < n ; i++ ){
		cin >> a[i];
	}
	dfs( 0 , 1 , 2 );
	cout << res << endl;
	return 0 ;	
}