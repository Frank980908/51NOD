#include <bits/stdc++.h>
using namespace std;

int phi( int n ){
	int res = 1 ;
	for( int i = 2 ; i * i <= n ; i++ ){
		if( n % i == 0 ){
			n /= i, res *= i-1;
			while( n % i == 0 ) n /= i , res *= i;
		}
	}
	if( n > 1 ) res *= n-1;
	return res ;
}

int quick( int a, int b , int p ){
	int ans = 1;
	while( b ){
		if( b & 1 ){
			ans = (ans*a)%p;
		}
		b >>= 1;
		a = (a*a)%p;
	}
	return ans ;
}

int main(){
	int n;
	cin >> n ;
	int res = 0;
	int len = 0;
	for( int i = 7 ; i <= n ; i++ ){
		if( __gcd( 10 , i ) == 1 ){
			int tmp = phi(i);
			for( int j = 1 ; j <= tmp ; j++ ){
				if( tmp % j == 0 && quick(10,j,i) == 1 ){
					if( j > len ){
						len = j ;
						res = i;
					}
					break;
				}
			}
		}
	}
	cout << res << endl;
	return 0;
}

