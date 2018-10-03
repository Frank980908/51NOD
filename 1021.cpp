#include <bits/stdc++.h>
#define INF 0x3f3f3f
using namespace std;
const int AX = 1e2+6;
int m[AX][AX];
int sum[AX];
int main(){
	int n;
	cin >> n ;
	int x;
	cin >> x;
	sum[0] = x;
	for( int i = 1 ; i < n ; i++ ){
		cin >> x;
		sum[i] = sum[i-1] + x;
	}	
	for( int i = 0 ; i < n ; i++ ){
		m[i][i] = 0;
	}
	for( int r = 2 ; r <= n ;r ++ ){
		for( int i = 0 ; i <= n - r; i++ ){
			int j = i + r - 1;
			m[i][j] = INF;
			int tmp = sum[j] - ( i > 0 ? sum[i-1] : 0 );
			for( int k = i ; k < j ; k++ ){
				m[i][j] = min( m[i][j] , m[i][k] + m[k+1][j] + tmp );
			}
		}
	}
	cout << m[0][n-1] << endl;
	return 0;
}