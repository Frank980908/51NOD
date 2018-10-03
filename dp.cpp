#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int AX = 2520 ;
const int MOD = 2520 ;
int a[50];
LL dp[50][AX][50];
int index[2550];

int gcd( int a , int b ){
	return b == 0 ? a : gcd(b,a%b);
}

int lcm( int a , int b ){
	return a / gcd(a,b) * b ;
}

void init(){
	int tot = 0 ;
	for( int i = 1 ; i <= MOD ; i++ ){
		if( MOD % i == 0 )  index[i] = tot++;
	}
}

LL dfs( int pos , int sta , int prelcm , bool limit ){
	if( pos == -1 ) return sta % prelcm == 0 ;
	if( !limit && dp[pos][sta][index[prelcm]] != -1 ){
		return dp[pos][sta][index[prelcm]];
	}
	LL ans = 0 ;
	int up = limit ? a[pos] : 9 ;
	for( int i = 0 ; i <= up ; i++ ){
		int nowsta = ( sta * 10 + i ) % MOD ;
		int nowclm = prelcm ;
		if(i) nowclm = lcm(nowclm,i);
		ans += dfs( pos-1 , nowsta , nowclm , limit && i == up );
	}
	if( !limit ) dp[pos][sta][index[prelcm]] = ans ;
	return ans ;
} 

LL solve( LL x ){
	int tot = 0 ;
	while( x ){
		a[tot++] = x % 10;
		x /= 10;
	}
	return dfs( tot - 1 , 0 , 1 , true );
}

int main(){
	int T;
	init();
	memset(dp,-1,sizeof(dp));
	cin>>T;
	while(T--){
		LL l,r;
		cin>>l>>r;
		cout<< ( solve(r) - solve(l-1) ) << endl;
	}
	return 0;
}