#include <bits/stdc++.h>
using namespace std;
const int AX = 50+6;
int a[AX];
int base[AX] = {0};
int main(){
	int n , x , c ;
	cin >> n >> x;
	int tot = 0 ;
	int t = x;
	while( t ){
		base[tot++] = t & 1;
		t /= 2;
	}
	
	int cnt = 0;

	for( int i = 0 ; i < n ; i++ ){
		cin >> c;
		int tmp = c;
		int f = 1;
		int temp = 0;

		while( tmp ){
			if( tmp & 1 == 1 && base[temp] == 0 ){
				f = 0;
				break;
			}
			if( temp >= tot ){
				f = 0;
				break;
			}
			tmp >>= 1; 
			temp ++ ;
		}
		if( f ) a[cnt++] = c;
	}
	int re[33] = {0};
	int res = 100;
	if( !cnt ) res = 0;
	for( int i = 0 ; i < cnt ; i++ ){
		int tt = a[i];
		int tmp = 0;
		while( tt ){
			if( tt & 1 ){
				re[tmp] ++ ; 
			}
			tt >>= 1;
			tmp++;
		}	
	}
	for( int i = 0; i < 33 ; i++ ){
		if( !base[i] && !re[i] ) continue;
		if( base[i] && !re[i] ) res = 0;
		res = min( res , re[i] );
	}
	cout << res << endl;
	return 0 ;
}