#include <bits/stdc++.h>
using namespace std;
const int AX = 1e3+66;
int a[AX];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n ;
	cin >> n ;
	int zero = 0 ;
	int five = 0 ;
	for( int i = 0 ; i < n ; i ++ ){
		cin >> a[i];
		if( a[i] == 0 ) zero ++ ;
		else five ++ ;
	}
	if( !zero  ) cout << "-1" << endl;
	else if( five < 9 ) cout << 0 << endl;
	else{
		int m = five - five % 9  ;
		for( int i = 0 ; i < m ; i++ ){
			cout << 5 ;
		}
		for( int i = 0 ; i < zero ; i++ ){
			cout << 0 ;
		}
		cout << endl ;
	}
	return 0;
}