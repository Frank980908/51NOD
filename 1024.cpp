#include <bits/stdc++.h>
#define eps 1e-9
using namespace std;
const int AX = 2e4+666;
double ans[AX];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int m,n,a,b;
	cin >> m >> n >> a >> b ;
	int tot = 0 ;
	for( int i = a ; i <= a + n - 1 ; i ++ ){
		for( int j = b ; j <= b + m - 1 ; j ++ ){
			ans[tot++] =   j * log(i) * 1.0 ;
		}
	}
	int i , j ;
	int res = 0 ;
	for( i = 0 ; i < tot ; i++ ){
		for( j = i + 1 ; j < tot ; j++ ){
			if( fabs(ans[i] - ans[j]) <= eps ) break;
		}
		if( j == tot ) res++;
	}
	cout << res << endl ;
	return 0;
}