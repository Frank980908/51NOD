#include <bits/stdc++.h>
using namespace std;

int hash( int n ){
	for( int m = 1 ; ; m++ ){
		int k = 2 * n;
		int s = 0;
		while( k > n ){
			if( s ) s -= 1; 
			s = ( s + m ) % k;
			if( s <= n && s ) break;
			k -- ;
			if( k == n ){
				return m;
			}	
		}
	}
}

int main(){
	int n;
	int a[20];
	for( int i = 1 ; i < 14 ; i++ ){
		a[i] = hash(i);
	}
	while( ~scanf("%d",&n) && n ){
		printf("%d\n",a[n]);
	}
	return 0;	
}