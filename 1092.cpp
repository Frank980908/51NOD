#include <bits/stdc++.h>
using namespace std;
const int AX = 1e3+6;
int dp[AX][AX];
int main(){
	string a , b;
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a ;
	int len = a.size();
	b = a;
	reverse( b.begin(), b.end() );
	for( int i = 0 ; i < len ; i++ ){
		for( int j = 0 ; j < len ; j++ ){
			if( a[i] == b[j] ) dp[i+1][j+1] = dp[i][j] + 1;
			else dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
		}
	}
	cout << len - dp[len][len] << endl;
	return 0 ;
}
