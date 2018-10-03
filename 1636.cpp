#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int AX = 1e2+6;
int n , m , K;
struct Node
{
	LL l,r,c;
}a[AX];
LL dp[52][52][AX];

bool cmp( const Node &a , const Node &b ){
	return a.c < b.c;
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for( int i = 1 ; i <= m ; i++ ){
		scanf("%lld%lld%lld",&a[i].l,&a[i].r,&a[i].c);
	}
	sort( a + 1 , a + m + 1 , cmp );
	memset(dp,-1,sizeof(dp));

	for( int i = 1 ; i <= m ; i ++ ){
		for( LL k = a[i].l ; k <= a[i].r ; k++ ){
			dp[i][1][k-a[i].l] = k;
			for( int t = m ; a[t].c > a[i].c ; t-- ){
				if( k + K >= a[t].l && k + K <= a[t].r ){
					for( int j = min( i , n - 1 ) ; j ; j-- ){
						if( dp[i][j][k-a[i].l] > 0 ){
							dp[t][j+1][k+K-a[t].l] = max( dp[t][j+1][k+K-a[t].l] , dp[i][j][k-a[i].l] + k + K );
						}
					}
				}
				if( k * K >= a[t].l && k * K <= a[t].r ){
					for( int j = min( i , n - 1 ) ; j ; j-- ){
						if( dp[i][j][k-a[i].l] > 0 ){
							dp[t][j+1][k*K-a[t].l] = max( dp[t][j+1][k*K-a[t].l] ,dp[i][j][k-a[i].l] + K * k );
						}
					}
				}
			}
		}
	}
	LL res = -1;
	for( int i = 1 ; i <= m ; i++ ){
		for( int k = a[i].r - a[i].l ; k >= 0 ; k-- ){
			res = max( res , dp[i][n][k] );
		}
	}
	if( res == -1 ){
		printf("NO\n");
	}else{
		printf("YES\n%lld\n",res);
	}
	return 0;
}

