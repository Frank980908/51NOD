#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int AX = 1e3+2;
int a[AX];
int main(){
	int n;
	cin >> n;
	a[0] = 0 ;
	a[1] = 1 ;
	a[2] = 2 ;
	for( int i = 3 ; i <= AX ; i++ ){
		a[i] = ( a[i-1] + a[i-2] ) % MOD ;
	}
	cout << a[n] << endl ;
	return 0;
}	 