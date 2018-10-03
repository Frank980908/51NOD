#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MOD = 1000000007;
struct Matrix
{
	LL a[2][2];
}origin,res;

void init(){
	memset(res.a,0,sizeof(res.a));
	memset(origin.a,0,sizeof(origin.a));
	origin.a[0][0] = 3 ; origin.a[0][1] = 0;
	origin.a[1][0] = 1 ; origin.a[1][1] = 1;
	res.a[0][0] = res.a[0][1] = 1;
}

Matrix multiply( Matrix x , Matrix y ){
	Matrix temp;
	memset(temp.a,0,sizeof(temp.a));
	for( int i = 0 ; i < 2 ; i ++ ){
		for( int j = 0 ; j < 2 ; j++ ){
			for( int k = 0 ; k < 2 ; k++ ){
				temp.a[i][j] = (temp.a[i][j] + x.a[i][k] * y.a[k][j] % MOD)%MOD;
			}
		}
	}
	return temp;
}

void cal(int n){
	while(n){
		if( n & 1 ) res = multiply(res,origin);
		n >>= 1;
		origin = multiply(origin,origin);
	}
}
int main(){
	int n ;
	cin >> n;
	init();
	cal(n);
	cout << res.a[0][0]%MOD << endl;
	return 0;
}
/*#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int MOD = 1e9+7;
LL quick(LL a,LL b){
	a %= MOD;
	LL res = 1;
	while( b ){
		if( b & 1 ) res = ( res * a ) %MOD;
		b >>= 1;
		a = (a*a)%MOD;
	}
	return res%MOD;
}
int main(){
	int n ;
	cin >> n;
	LL res = (quick(3,n+1)%MOD-3)*500000004%MOD;
	cout << res + 1 << endl;
	return 0;
}*/