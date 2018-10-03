#include <bits/stdc++.h>
#define LL long long 
using namespace std;
const int AX = 1e2+66;
const int MOD = 1e9+7;
int n,m;
struct Matrix{
	LL a[AX][AX];
}ori,res;

Matrix operator * ( Matrix x , Matrix y ){
	Matrix temp ;
	LL xx;
	for( int i = 0 ;i < n ; i++ ){
		for( int j = 0 ; j < n ; j ++ ){
			xx = 0LL ;
			for( int k = 0 ; k < n; k++ ){
				xx += x.a[i][k] % MOD * y.a[k][j] % MOD;
			}
			temp.a[i][j] = xx % MOD;
		}
	}
	return temp;
}

/*Matrix multiply( Matrix x , Matrix y ){
	Matrix temp ;
	memset( temp.a , 0 ,sizeof(temp.a));
	for( int i = 0 ; i < n ; i ++ ){
		for( int j = 0 ; j < n ; j ++ ){
			for( int k = 0 ; k < n ; k ++ ){
				temp.a[i][j] += x.a[i][k] % MOD *y.a[k][j] % MOD;
				temp.a[i][j] %= MOD;
			}
		}
	}
	return temp;
}*/

void cal( int b ){
	while( b ){
		if( b & 1 ) res = res * ori ;
		b >>= 1;
		ori = ori * ori ;
	}
	for( int i = 0 ; i < n ;i ++ ){
		for( int j = 0 ; j < n ; j++ ){
			cout << res.a[i][j] << ' ' ;
		}
		cout << endl;
	}
}

void init(){
	//memset(res.a , 0 , sizeof(res.a));
	for( int i = 0 ; i < n ; i++ ){
		res.a[i][i] = 1;
	}
	return ;
}

int main(){	
	cin >> n >> m ;
	init();
	for( int i = 0 ; i < n ; i ++ ){
		for( int j = 0 ; j < n ; j++ ){
			cin >> ori.a[i][j];
		}
	}
    cal(m);	
	return 0 ;
}