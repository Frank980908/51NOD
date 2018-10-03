#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int AX = 1e3+6;
const int MOD = 1e9+7;
LL n , dp[9005] , ans , f[9005];

int main(){
	cin >> n;
	f[0] =1 ;
	for( int i =1 ; i <= 9 ; i++ ){
		dp[i] = 1; f[i] = 1;
	}
	for( int i = 2 ; i <= n ;i ++){
		for( int j = 9*n ; j >= 1 ;j --){
			LL dpos = 0 , fpos = 0;
			for( int k = 0 ; k <= 9 ; k++ ){
				if( j - k >= 0 ){
					fpos = (fpos+f[j-k]) % MOD;
					dpos = (dp[j-k]+dpos) % MOD;
				}else break;
			}
			f[j] = fpos; dp[j] =dpos;
		}
	}
	for( int i = 1 ; i <= 9*n ; i++ ){
		ans = (ans+(dp[i]*f[i])%MOD)%MOD;
	}
	cout << ans << endl;
	return 0;
}