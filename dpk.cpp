#include <iostream>
#include <string.h>
#include <cstdio>
#define LL long long 
using namespace std;

int a[25];
LL dp[25][60000];

bool check( LL x ){
	for( int i = 0 ; i < 10 ; i++ ){
		if( (i&1) && (x%3==1) ) return false ;
		if( !(i&1) && (x%3==2) ) return false ;
		x /= 3;
	}
	return true;
}

LL hash( int sta , int i ){
	int b[10];
	for( int j = 0 ; j < 10 ; j++ ){
		b[j] = sta % 3 ;
		sta /= 3;
	}
	if( b[i] == 0 ) b[i] = 1 ;
	else b[i] = 3 - b[i];
	for( int j = 9 ; j >= 0 ; j -- )  sta = sta * 3 + b[j];
		return sta;
}

LL dfs( int pos , int sta , bool lead , bool limit ){
	if( pos == -1 ) return check(sta) ;
	if( !limit && dp[pos][sta] != -1 ) return dp[pos][sta];
	LL ans = 0 ;
	int up = limit ? a[pos] : 9 ;
	for( int i = 0 ; i <= up ; i++ ){
		if( lead && i == 0 ) ans += dfs( pos - 1 , sta , lead && i == 0 , limit && i == up);
		else ans += dfs( pos - 1 , hash( sta , i ) , lead && i == 0 , limit && i == up);
	}	
	if( !limit ) dp[pos][sta] = ans ;
	return ans ;
}

LL solve( LL x ){
	int tot = 0 ;
	while( x ){
		a[tot++] = x % 10;
		x /= 10 ;
	}
	return dfs( tot - 1 , 0, true, true );
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T ;
	int l , r ;
	memset(dp,-1,sizeof(dp));
	while( T-- ){
		cin >> l >> r ;
		cout << solve(r) - solve(l-1) << endl;
	}
	return 0;
}