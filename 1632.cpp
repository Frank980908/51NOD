#include <bits/stdc++.h>
#define LL long long
using namespace std;
const LL MOD = 1e9+7;
LL quick( LL a , LL b , LL c ){
	LL ans = 1;
	while( b ){
		if( b & 1 ){
			ans = ( ans * a ) % c;
		}
		b >>= 1;
		a = ( a * a ) % c;
	}
	return ans % c ;
}
int main(){
	LL n;
	cin >> n;
	LL x ,y ;
	cout << ((n + 1) * quick( 2 , n - 2 , MOD )) % MOD;
	return 0;
}