#include <bits/stdc++.h>
using namespace std;
const int AX = 1e5+66;
int a[AX];
int b[1000000+6];
int prime[1000000];
int num = 0;
void init( ){
	b[1] = 1;
	for( int i = 2 ; i < 1e6 ; i++ ){
		if( !b[i] ){
			prime[num++] = i;
			for( int j = 2 ; j * i < 1e6 ; j++ ){
				b[j*i] = 1;
			}
		}
	}
}
int main(){
	int n ;
	init();
	scanf("%d",&n);
	int tmp = n;
	int cnt = 0;
	int flag = 0;
	for( int i = 0 ; i < num ; i ++ ){
		int t = prime[i];
		if( t > n ) break;
		int ans = 0;
		if( tmp % t == 0 ){
			cnt ++ ;
			while( tmp % t == 0 ){
				ans ++ ;
				tmp /= t ;
				if( ans % 2 == 0 ){
					flag = 1;
					break;
				}
			}
			if( flag ) break;
		}
	}
	if( tmp != 1 ) cnt ++ ;
	int res = ( cnt % 2 == 0 ? 1 : -1 );
	if( flag ) printf("0\n");
	else printf("%d\n",res);
	return 0 ;
}