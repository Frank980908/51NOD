#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int AX = 1e4+666;
LL a[AX];
int main(){
	int n,w;
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> w;
	for( int i = 0 ; i < n ; i++ ){
		cin >> a[i];
	}
	sort(a,a+n);
	int ans = n ;
	int res = 0 ;
	int tot = 0 ;
	for( int i = n-1 ; i > tot ; i-- ){
		if( a[i] + a[tot] <= w ){
			a[i] = 0;
			a[tot] = 0;
			tot++;
			res++;
		}
	}
	for( int i = 0 ; i < n ; i++ ){
		if( a[i] ) res ++;
	}
	cout << res << endl;
	return 0;
}