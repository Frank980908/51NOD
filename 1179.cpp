#include <bits/stdc++.h>
using namespace std;
const int AX = 1e6+6;
int b[AX];
int main(){
	int n;
	cin >> n ;
	int x ;
	memset( b, 0 , sizeof(b) );
	int res = 1;
	for( int i = 0 ; i < n ; i ++ ){
		cin >> x;
		b[x] ++ ;
		b[1] ++ ;
		for( int j = 2 ; j * j <= x ; j ++ ){
			if( x % j == 0 ){
				b[j]++;
				b[x/j]++;
				if( j * j == x ) b[j]--;
			}
		}
	}
	for( int i = AX ; i >= 1 ; i-- ){
		if( b[i] >= 2 ){
			res = i;
			break;
		}
	}
	cout << res << endl;
	return 0 ;	
}