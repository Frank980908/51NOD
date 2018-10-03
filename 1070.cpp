#include <bits/stdc++.h>
#define LL long long 
#define MAXN 1e9
using namespace std;
const int AX = 1e5;
int a[AX];
int num = 1 ;
void init(){
	int f1 = 3 , f2 = 5;
	a[0] = 5 ;
	while( f1 <= MAXN && f2 <= MAXN){
		int temp = f2;
		f2 = f1 + f2 ;
		a[num++] = f2;
		f1 = temp ;
	}
}
int main(){
	int T ;
	init();
	scanf("%d",&T);
	LL n ;
	while( T-- ){
		scanf("%lld",&n);
		if( n <= 3 ) printf("B\n");
		else{
			int id = lower_bound( a , a + num, n) - a;
			if( a[id] == n ){
				printf("B\n");
			}else{
				printf("A\n");
			}
		}
	}
	return 0 ;
}