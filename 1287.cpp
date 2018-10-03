/*
#include <bits/stdc++.h>
using namespace std;
const int AX = 5e4+66;
int a[AX];
int b[AX];
int c[AX<<2];

void pushUp(int rt){
	c[rt] = max( c[rt<<1] , c[(rt<<1)|1] );
}

void build( int rt , int l , int r ){
	if( l == r ){
		c[rt] = a[l];
		return;
	}
	int m = ( l + r ) >> 1;
	build( rt << 1 , l , m );
	build( (rt << 1) | 1 , m + 1, r );
	pushUp(rt);
}

int query( int rt , int l , int r , int v ){
	if( l == r ){
		return l ;
	}
	int m = ( l + r ) >> 1;
	if( c[rt<<1] >= v ){
		query( rt << 1 , l , m , v );
	}else{
		query( (rt << 1) | 1 , m + 1, r , v);
	}
}

void update( int rt , int l , int r , int x ){
	if( l == r ){
		c[rt] = a[l];
		return;
	}
	int m = ( l + r ) >> 1 ;
	if( x <= m ){
		update( rt << 1 , l , m , x );
	}else{
		update( (rt<<1)|1 , m + 1, r , x );
	}
	pushUp(rt);
}

int main(){
	ios_base::sync_with_stdio(false) ;
	cin.tie(0);
	int n , m ;
	cin >> n >> m ;
	int x ;
	for( int i = 1 ; i <= n ; i++ ){
		cin >> a[i];
	}
	build( 1 , 1 , n );
	for( int i = 0 ; i < m ; i++ ){
		cin >> x;
		if( x <= a[1] || x > c[1] ) continue;
		int pos = query( 1 , 1 , n , x );
		a[pos-1]++;
		update( 1,1,n,pos-1);
	}
	for( int i = 1 ; i <= n ; i++ ){
		cout << a[i] << endl;
	}
	return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
const int AX = 5e4+66;
int a[AX];
int b[AX];
int c[AX];
int main(){
	ios_base::sync_with_stdio(false) ;
	cin.tie(0);
	int n , m ;
	cin >> n >> m ;

	int tmp = 0 ;
	for( int i = 0 ; i < n ; i++ ){
		cin >> a[i];
		tmp = max( tmp , a[i] );
		c[i] = tmp;
	}
	int x ; 
	for( int i = 0 ; i < m ; i++ ){
		cin >> x;
		if( x > tmp || x <= a[0] ) continue;
		int pos = lower_bound( c + 1 , c + n + 1 , x ) - c;
		a[pos-1] ++;
		c[pos-1] = max( c[pos-1] , a[pos-1] );
	}
	for( int i = 0 ; i < n ; i++ ){
		cout << a[i] << endl;
	}
	return 0 ;
}