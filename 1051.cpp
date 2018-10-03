#include <bits/stdc++.h>
#define LL long long 
using namespace std;
const int AX = 5e2+66;
LL a[AX][AX];
LL sum[AX][AX];
LL b[AX][AX];
LL res ;

int main(){
	int n , m ;
	scanf("%d%d",&m,&n);
	int ok = 0 ;
	memset(sum,0,sizeof(sum));
	for( int i = 1 ; i <= n; i ++ ){
		for( int j = 1 ; j <= m ; j++ ){
			scanf("%lld",&a[i][j]);
			if( a[i][j] ) ok = 1;
		}
	}
	for( int i = 1 ; i <= n ; i ++ ){
		for( int j = 1 ; j <= m ; j ++ ){
			sum[j][i] = sum[j-1][i] + a[i][j];
		}
	}

	if( !ok ){
		printf("0\n");
		return 0;
	}
	res = 0;
	for( int i = 1 ; i <= m ; i ++ ){
		for(int j = i ; j <= m ; j++ ){
			LL temp = sum[j][1] - sum[i-1][1];
			res = max(res,temp);
			for( int k = 2 ; k <= n ; k++ ){
				temp = max(temp , 0LL) + (sum[j][k] - sum[i-1][k]) ;
				res = max(res,temp);
			}
		}
	}
	printf("%lld\n",res);
	return 0 ;
}