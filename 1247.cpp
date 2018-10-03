#include <stdio.h>
#define LL long long
LL gcd( LL a , LL b ){
	return b == 0 ? a : gcd(b,a%b);
}
int main(){
	int T;
	scanf("%d",&T);
	LL sx , sy , ex ,ey;
	while( T-- ){
		scanf("%lld%lld%lld%lld",&sx,&sy,&ex,&ey);
		if( gcd(sx,sy) == gcd(ex,ey) ){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}