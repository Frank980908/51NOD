#include <bits/stdc++.h>
#define LL long long 
using namespace std;
const int AX = 2e2+6;
LL a[20][AX];
LL sum = 0 ;
int vis[AX];
LL col[AX];
LL n , m , x, k ;
LL maxn = 0 ;

LL cal( int count ){
	memset(col,0,sizeof(col));
	sum = 0;
	for( int i = 0 ; i < m ; i++ ){
		for( int j = 0 ; j < n ; j++ ){
			if( vis[j] ){
				col[i] += x ;
			}else col[i] += a[j][i];
		}
		sum += col[i];
	}
	sort( col , col + m );
	int tmp = k - count ;

	for( int i = 0 ; i < m ; i++ ){
		if( tmp == 0 ) break;
		if( col[i] < n * x ){
			sum -= col[i];
			sum += n * x;
			tmp -- ;
		}else break;
	}
	maxn = max( maxn , sum );
}

void dfs( int r , int sta ){
	if( sta > k ) return;
	if( r == n ){
		cal(sta);
		return ;
	}
	vis[r] = 1 ;
	dfs( r + 1 , sta + 1 );
	vis[r] = 0 ;
	dfs( r + 1 , sta ) ;
}

int main(){

	scanf("%lld%lld%lld%lld",&n,&m,&x,&k);
	for( int i = 0 ; i < n ; i ++ ){
		for( int j = 0 ; j < m ; j ++ ){
			scanf("%lld",&a[i][j]);
			maxn += a[i][j];
		}
	}
	memset( vis ,0 , sizeof(vis) ) ;
	sum = 0;
	dfs( 0 , 0 );
	printf("%lld\n",maxn);
	return 0 ;
}