#include <bits/stdc++.h>
using namespace std;
const int AX = 5e4+6;
int a[AX];
int vis[AX];
int main(){
	int n ;
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n ;
	for( int i = 1 ; i <= n ; i ++ ){
		cin >> a[i];
	}
	long long sum = 0LL;
	int k ;
	int i ;
	for( i = 1 ; i <= n ; i++ ){
		sum += a[i];
		sum %= n ;
		if( sum == 0 || vis[sum] ){
			k = vis[sum];
			break;
		}
		vis[sum] = i;
	}
	cout << i - k << endl;
	for( int j = k + 1 ; j <= i ; j ++ ){
		cout << a[j] << endl;
	}
	return 0 ;
}