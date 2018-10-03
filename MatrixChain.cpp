#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int AX = 1e3+6;
int p[AX];
int s[AX][AX];
LL m[AX][AX];
int n ;

void printMatrix( int l , int r ){
	if( l == r ) printf("A%d",l);
	else{
		cout << "(";
		printMatrix(l , l + s[l][r]);
		printMatrix(l + s[l][r] + 1 , r);
		cout << ")";
	}
}

LL MatrixChain( ){
	for( int i = 0 ; i < n ; i++ ){
		m[i][i] = 0;
	}
	for( int r = 2 ; r <= n ; r ++ ){
		for( int i = 0 ; i <= n - r ; i++ ){
			int j = i + r - 1;
			m[i][j] = m[i][i] + m[i+1][j] + p[i]*p[i+1]*p[j+1];
			s[i][j] = i;
			for( int k = i + 1  ; k < j ; k++ ){
				LL tmp = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
				if( tmp < m[i][j] ){
					m[i][j] = tmp;
					s[i][j] = k;
				}
			}
		}
	}
	return m[0][n-1];
}

int main(){
	cin >> n;
	for( int i = 0 ; i < n+1 ; i++ ){
		cin >> p[i];
	}
	cout << MatrixChain( ) << endl; 
	printMatrix(0 , n-1);
	puts("\n");
	return 0 ;
} 