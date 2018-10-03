#include <iostream>
#include <cstdio>
#include <string.h>
#define LL long long
using namespace std;
const int MOD = 1e9+7;
int a[25];
LL dp[25][25][3];
LL dfs( int pos , int sta , int mark , bool limit ){
	if( pos == -1 ) return mark == 2 && sta == 0 ;
	if( !limit && dp[pos][sta][mark] != -1 ) return dp[pos][sta][mark];
	LL ans = 0 ;
	int up = limit ? a[pos] : 9 ;
	for( int i = 0 ; i <= up ; i ++ ){
		int temp = ( sta * 10 + i ) % 13;
		int tmp = mark;
		if( mark == 0 && i == 1 ) tmp = 1;
		if( mark == 1 && i != 1 ) tmp = 0;
		if( mark == 1 && i == 3 ) tmp = 2; 
		ans += dfs( pos - 1 , temp , tmp , limit && i == up ) ;
	}
	if( !limit )  dp[pos][sta][mark] = ans ;
	return ans ;
}

LL solve( LL x ){
	int tot = 0 ;
	while( x ){
		a[tot++] = x % 10 ;
		x /= 10;
	}
	return dfs( tot - 1 , 0 , 0 , true );
}

int main(){
	//ios_base::sync_with_stdio(false); cin.tie(0);
	memset(dp,-1,sizeof(dp));
	LL n;
	while(~scanf("%lld",&n))
		printf("%lld\n",solve(n));
	return 0;
}