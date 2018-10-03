#include <bits/stdc++.h>
using namespace std;
const int AX = 1e3+6;
int prime[AX];
int main(){
	int n ;
	cin >> n ;
	int ans = 0;
	for( int i = 2 ; i <= n ; i ++ ){
		if( !prime[i] ){
			for( int j = i ; j <= n ; j *= i ){
				ans ++ ;
			}
			for( int j = i ; j * i <= n ; j ++ ){
				prime[i*j] = 1;
			}
		}
	}
	cout << ans << endl;
	return 0;	
}
