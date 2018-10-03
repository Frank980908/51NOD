#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned LL
#define INF ~0ULL  
using namespace std;
int p[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};  
LL n ;
ULL res ;
int ibest; 
void dfs( int depth , ULL tmp , int num , int lim ){
	if( depth > 16 ) return;
	if( num > ibest ){
		ibest = num;
		res = tmp;
	}
	if( num == ibest && tmp < res ) res = tmp;
	for( int i = 1 ; i <= lim ; i++ ){

		if( n / p[depth] < tmp ) break;
		dfs( depth + 1 , tmp *= p[depth] , num * (i+1) , i );
	}
}

int main(){
	int T ;
	scanf("%d",&T);
	while( T-- ){
		res = INF;
		ibest = 0;
		scanf("%lld",&n);
		dfs( 0 , 1 , 1 , 10 );		
		cout << res << ' ' << ibest << endl;
	}
	return 0 ;
}
