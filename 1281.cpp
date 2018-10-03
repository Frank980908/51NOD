/*#include <bits/stdc++.h>
using namespace std;
const int AX = 5e4+66;
int a[AX];
int b[AX];

int solve( int x  , int tot ){
	int i = b[0] ;
	int num = 1 ;
	while( i <= b[tot-1] ){
		i += x;
		int pos = lower_bound( b , b + tot , i ) - b;
		if( pos >= x ) break;
		i = b[pos] ;
		num ++ ;
	}
	return ( num >= x ? 1 : 0 );
}

int main(){
	int n ;
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n ;
	int tot = 0 ;
	for( int i = 0 ; i < n ; i++ ){
		cin >> a[i];
	}
	for( int i = 1 ; i < n - 1 ; i ++ ){
		if( a[i] > a[i-1] && a[i] > a[i+1] ){
			b[tot++] = i;
		}
	}
	int res  ;
	int l = 0 , r = tot ;
	while( l <= r ){
		int mid = l + ( r - l ) / 2 ;
		if( solve(mid,tot) ){
			l = mid + 1 ;
		}else r = mid ;
	}
	cout << r << endl;
	return 0 ;
}*/
#include <bits/stdc++.h>
using namespace std;
const int AX = 5e4+66;
int a[AX];
int b[AX];

int solve( int x  , int tot ){
	int ans = 1 ;
	int re = b[0];
	for( int i = 1 ; i < tot ; i++ ){
		if( b[i] - re >= x ){
			ans ++;
			re = b[i];
		}
	}
	return ( ans >= x ? 1 : 0 );
}

int main(){
	int n ;
	cin >> n ;
	int tot = 0 ;
	for( int i = 0 ; i < n ; i++ ){
		cin >> a[i];
	}
	for( int i = 1 ; i < n - 1 ; i ++ ){
		if( a[i] > a[i-1] && a[i] > a[i+1] ){
			b[tot++] = i;
		}
	}
	int l = 0 , r = tot ;
	while( l <= r ){
		int mid = l + ( r - l ) / 2 ;
		if( solve(mid,tot) ){
			l = mid + 1 ;
		}else{
			r = mid - 1 ;
		}
	}
	cout << l - 1 << endl;
	return 0 ;
}