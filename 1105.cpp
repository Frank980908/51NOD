#include <bits/stdc++.h>
#define LL long long 
using namespace std;
const int AX = 5e4+66;
LL a[AX];
LL b[AX];
LL n , k ;
LL res ;
LL f( LL v ){
	LL sum = 0;
	LL j = n - 1;
	for( int i = 0 ; i < n ; i++ ){
		while( j >= 0 ){
			if( a[i]*b[j] > v ) j--;
			else break;
		}
		sum += j + 1;
	}
	return sum >= k ;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k ;
	for( int i = 0 ; i < n ; i++ ){
		cin >> a[i] >> b[i];
	}
	sort( a, a + n );
	sort( b, b + n );
	k = n * n - k + 1;
	LL l = a[0] * b[0];
	LL r = a[n-1] * b[n-1];
	while( l <= r ){
		LL mid = ( l + r ) >> 1;
		if( f( mid ) ){
			r = mid - 1 ;
		}else{
			l = mid + 1 ;
		}
	}
	cout << l << endl;
	return 0;
}