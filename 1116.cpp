#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int AX = 1e5+66;
char s[AX];
map<char,int>mp;

LL quick( LL a , LL b , LL c ){
	LL ans = 1;
	while( b ){
		if( b & 1 ) ans = (ans * a)%c;
		b >>= 1 ;
		a = ( a*a ) % c; 
	}
	return ans % c ;
}

int main(){
	cin >> s;
	for( int i = 0 ; i < 26 ; i++ ){
		mp[(char)( 65 + i )] = 10 + i ;
	}
	int len = strlen(s);
	int k = 2 ;
	for( int i = 0 ; i < len ; i++ ){
		if( s[i] >= 'A' && s[i] <= 'Z' ){
			k = max( k , mp[s[i]] );
		} 
	}
	for( ; k <= 36 ; k++ ){
		int mi = 0;
		LL tmp = 0 ;
		for( int i = len - 1 ; i >= 0 ; i -- , mi++ ){
			LL bit ;
			if( s[i] >= 'A' && s[i] <= 'Z' ){
				bit = mp[s[i]];
			}else bit = s[i] - '0';
			tmp = ( tmp + bit * quick( k + 1 , mi , k ) ) % k;
		}
		if( !tmp ) break;
	}
	if( k > 36 ) cout << "No Solution" << endl;
	else cout << k + 1 << endl;
	return 0;
}