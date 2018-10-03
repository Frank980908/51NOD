#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
	int c , hr , hb , wr , wb;
	cin >> c >> hr >> hb >> wr >> wb;
	LL maxum = 0;
	for( LL i = 0 ; i <= sqrt(c) ; i++ ){
		if( i * wr <= c ){
			maxum = max( maxum , i * hr + (c-i*wr)/wb * hb );
		}
		if( i * wb <= c ){
			maxum = max( maxum , i * hb + (c-i*wb)/wr * hr );
		}
	}
	cout << maxum << endl;
	return 0;
}