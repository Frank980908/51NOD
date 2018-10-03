#include <bits/stdc++.h>
using namespace std;
const int AX = 2e4+66;
int a[AX];
int main(){
	int n ;
	cin >> n;
	int res = 0 ;
	for( int i = 1 ; i <= n ; i++ ){
		cin >> a[i];
		res += a[i];
	}
	for( int num = 3 ; num < n ; num++ ){
		if( n % num == 0 ){
			int t = n / num;
			int j ;
			for( int i = 1 ; i <= n ; i ++ ){
				int ans = 0;
				j = i;
				if( i + (num-1)*t > n ) break;
				while( j <= n ){
					ans += a[j];
					j += t ;
				}
				res = max( res , ans );
			}
		}		
	}
	cout << res << endl;
	return 0 ;	
}