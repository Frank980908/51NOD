#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL ex_gcd( int a , int b , int &x , int &y ){
	if( b == 0 ){
		x = 1;
		y = 0;
		return a;
	}
	LL ans = ex_gcd( b , a % b , x, y );
	int tmp = x;
	x = y ;
	y = tmp - a / b * y ;
	return ans ;
}
int main(){
	int T;
	scanf("%d",&T);
	LL n ,a , b;
	while( T-- ){	
		scanf("%lld%lld%lld",&n,&a,&b);
		int x , y ;
		LL res = 0 ;
		LL gc = ex_gcd( a , b , x , y );
		LL lcm = a * b / gc;
		n++;
		if( n % gc == 0 ){
			LL xx = x * ( n / gc ) ;
			LL r = b / gc;
			xx = ( xx % r + r ) % r;
			if( xx == 0 ) xx = r;
			LL y = n - xx * a;
			if( y < 0 ) res = 0;
			else{
				res = (( y % lcm ) ? y / lcm + 1 : y / lcm);
			}
		}else{
			res = 0;
		}
		printf("%lld\n",res);
	}
	return 0;	
}	