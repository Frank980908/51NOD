#include <bits/stdc++.h>
#define LL long long 
using namespace std;
const int AX = 1e4+66;
int x[AX];
int y[AX];
int z[AX];
int main(){
	int n ;
	cin >> n ;
	LL x1 = 0 , y1 = 0 ,z1 = 0;
	for( int i = 0; i < n ; i++ )
		cin >> x[i] >> y[i] >> z[i];
	sort( x , x + n );
	sort( y , y + n );
	sort( z , z + n );
	if( n % 2 ) x1 = x[n/2];
	else x1 = (x[n/2] + x[n/2-1] ) / 2;
	if( n % 2 ) y1 = y[n/2];
	else y1 = (y[n/2] + y[n/2-1] ) / 2;
	if( n % 2 ) z1 = z[n/2];
	else z1 = (z[n/2] + z[n/2-1] ) / 2;
	
	LL res = 0;
	for( int i = 0 ; i < n ; i++ ){
		res += abs( x1 - x[i] );
		res += abs( y1 - y[i] );
		res += abs( z1 - z[i] );
	}
	cout << res << endl;
	return 0 ;
}