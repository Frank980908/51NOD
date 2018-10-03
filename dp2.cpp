#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int AX = 2e4+666;
LL dp[25][AX];
int a[25];
int fa ;

int dfs( int pos , int sta , bool limit ){
	if( sta < 0 ) return 0 ;
	if( pos == -1 ) return sta >= 0 ;
	if( !limit && dp[pos][sta] != -1 ) return dp[pos][sta];
	int up = limit ? a[pos] : 9 ;
	int ans = 0;
	for( int i = 0 ; i <= up ; i++ ){
		int stanow = sta - ( 1 << pos ) * i ;
		ans += dfs( pos-1 , stanow , limit && up == i );
	} 
	if( !limit ) dp[pos][sta] = ans ;
	return ans ;
}

int solve( int x ){
	int tot = 0 ;
	while( x ){
		a[tot++] = x % 10 ;
		x /= 10 ;
	}
	return dfs( tot - 1 , fa , true );
}

void F( int x ){
	int i = 0 ;
	fa = 0 ;
	while( x ){
		fa += ( 1 << i ) * ( x % 10 );
		x /= 10;
		i ++ ;
	}
}

int main(){
	int T;
	cin >> T;
	int a , b;
	memset(dp,-1,sizeof(dp));
	int cas = 0;
	while( T -- ){
		cin >> a >> b ;
		F(a);
		printf("Case #%d: %d\n",++cas,solve(b));
	}
	return 0;
}