#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000009
using namespace std;

struct Matrix
{
	LL a[2][2];
}origin,res;
Matrix multiply( Matrix x , Matrix y ){
	Matrix temp ;
	memset(temp.a,0,sizeof(temp.a));
	for( int i = 0 ; i < 2;  i++ ){
		for( int j = 0 ; j < 2 ; j++ ){
			for( int k = 0 ; k < 2 ; k++ ){
				temp.a[i][j] += (x.a[i][k]%MOD*y.a[k][j]%MOD)%MOD;
				temp.a[i][j] %= MOD;
			}
		}
	}
	return temp;
}
void cal(LL n){
	origin.a[0][0] = origin.a[0][1] = 1;
    origin.a[1][0] = 1 ; origin.a[1][1] = 0;

    res.a[0][0] = res.a[1][1] = 1;
    res.a[0][1] = res.a[1][0] = 0;
	while(n){
		if( n & 1 ) res = multiply(res,origin);
		origin = multiply(origin,origin);
		n>>=1;
	}
	cout<<res.a[0][1]%MOD<<endl;
}
int main(){
	LL n;
	while(cin>>n){
		cal(n);
	}
	return 0;
}