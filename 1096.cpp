#include <bits/stdc++.h>
using namespace std;
const int AX= 1e4+66;
int a[AX];
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for( int i = 0 ; i < n ; i++ ){
		cin >> a[i];
	}
	int k;
	sort(a,a+n);
	if( n % 2 ){
		k = a[n/2];
	}else{
		k = (a[n/2] + a[n/2-1])/2;
	}
	long long res = 0;
	for( int i = 0 ; i < n ; i ++ ){
		res += fabs(k-a[i]);
	}
	cout << res << endl;
	return 0;
}