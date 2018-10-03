#include <bits/stdc++.h>
#define INF 0x3f3f3f
using namespace std;
const int AX = 1e5+666;
int a[AX];
int main(){
	int T;
	cin >> T;
	int n;
	while( T -- ){
		cin >> n ;
		if( n == 1 ) { cout << 1 <<endl; continue; }
		a[0] = 0;
		a[1] = 1;
		int maxn = 1;
		for( int i = 2 ; i <=n ;i++){
			if( i % 2 == 0 ) a[i] = a[i/2];
			else a[i] = a[(i-1)/2] + a[(i-1)/2+1];
			maxn = max(maxn,a[i]);
		} 
		cout << maxn << endl;
	}
	
	return 0;
}