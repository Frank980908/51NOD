#include <bits/stdc++.h>
using namespace std;
const int AX = 1e7;
int a[AX];
int main(){
	int n;
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n ;
	int x;
	memset( a , 0 , sizeof(a) );
	for( int i = 0 ; i < n ; i ++ ){
		cin >> x;
		a[x] ++;
	}
	for( int i = 0 ; i <= AX ; i++ ){
		if( a[i] >= 2 ){
			a[i+1] += a[i] / 2;
			a[i] %= 2 ;
		} 
	}	
	int res = 0;
	for( int i = 0 ; i <= AX ; i++ ){
		if( a[i] ) res ++ ;
	}
	cout << res << endl;
	return 0;
}