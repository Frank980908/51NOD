#include <bits/stdc++.h>
using namespace std;
const int AX = 1e4+66;
int p[AX];
int dp[AX];
char s[AX];
int main(){
	cin >> s ;
	int len = strlen(s);
	for( int i = len ; i >= 0 ; i-- ){
		s[2*i+2] = s[i]; 
		s[2*i+1] = '#';
	}
	s[0] = '$';
	int id = 0 , mx = 0 ;
	for( int i = 2 ; i < 2 * len + 1 ; i++ ){
		if( p[id] + id > i ){
			p[i] = min( p[id] + id - i , p[2*id-i] );
		}else p[i] = 1;
		while( s[i - p[i]] == s[i+p[i]] ) p[i] ++;
		if( mx < p[i] + i ){
			mx = p[i] + i;
			id = i;
		}
	}
	dp[0] = 1;
	for( int i = 1 ; i < len ; i++ ){
		dp[i] = i + 1 ;
		for( int j = 0 ; j <= i ; j++ ){
			int tm_i = 2 * i + 2 ;
			int tm_j = 2 * j + 2 ;
			int pos = ( tm_i + tm_j ) >> 1 ; 
			if( p[pos] + pos - 1 > tm_i || i == j ){
				dp[i] = min( dp[i] , dp[j-1] + 1 );	
			}			
		}
	}
	cout << dp[len-1] << endl;
	return 0 ;
}