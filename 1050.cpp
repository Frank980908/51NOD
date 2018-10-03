#include <bits/stdc++.h>
#define LL long long
#define INF 0x3f3f3f
using namespace std;
const int AX = 5e4+666;
LL a[AX];

int n ; 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n ;
	bool ok = 0;
	LL sum = 0 ;
	for( int i = 1 ; i <= n ; i++ ){
		cin >> a[i] ;
		sum += a[i] ;
		if( a[i] > 0 ) ok = true;
	}
	LL MAXN = 1e-7;
	if( ok ){
		LL res1 = 0 , res2 = 0 , res;
		res1 = a[1];
		for( int i = 2 ; i <= n ; i++ ){
			if( res1 > 0 ){
				res1 += a[i];
			}else{
				res1 = a[i];
			}
			if( MAXN < res1 ){
				MAXN = res1;
			}
		}
		LL eps = 0x3f3f3f;
		res2 = a[1];
		for( int i = 2 ; i <= n ; i++ ){
			if( res2 < 0 ){
				res2 += a[i];
			}else{
				res2 = a[i];
			}
			if( eps > res2 ){
				eps = res2;
			}
		}
		//cout << "eps: " << eps << endl;
		cout << max( MAXN , sum-eps );
	}else{
		cout << 0 << endl;
	}
	return 0;
}