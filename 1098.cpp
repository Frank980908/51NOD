#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int AX = 1e4+666;
int a[AX];
LL sum[AX];
LL s[AX];
int main(){
	int m , n ;
	cin >> m >> n ;
	for( int i = 1 ; i <= m; i++ ){
		cin >> a[i];
	}
	sort( a + 1 , a + m + 1 );
	s[0] = sum[0] = 0 ;
	for( int i = 1 ; i <= m ; i++ ){
		sum[i] = sum[i-1] + a[i];
		s[i] = s[i-1] + a[i] * a[i];
	}
	double minus = (double)1e16;
	for( int i = n; i <= m; i ++ ){
		double tmp = ( s[i] - s[i-n] ) - 1.0 * ( sum[i] - sum[i-n] ) * ( sum[i] - sum[i-n] ) / n ;
		if( tmp < minus )
			minus = tmp;
	}
	printf( "%lld\n" , (LL)minus );
	return 0 ;
}