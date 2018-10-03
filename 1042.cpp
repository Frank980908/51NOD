#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int AX = 20;
LL x[AX];
LL y[AX];
void dfs( LL a , LL mul , LL c[] ){
	LL n = a / 10 ;
	int m = a % 10;
	for( int i = 0 ; i <= m ; i++ ) c[i] += mul;
		for( int i = 0 ; i < 10 ; i++ ) c[i] += mul*n;
			c[0] -= mul;
		LL temp = n;
		while( temp ){
			c[temp%10] += mul*(m+1);
			temp /= 10;
		}
		if(n) dfs(n-1,mul*10,c);
	}
	int main(){
		LL a , b ;
		cin >> a >> b ;
		dfs(b,1,y);
		dfs(a-1,1,x);
		for( int i = 0 ; i < 10 ; i++ ){
			cout << y[i] - x[i] << endl;
		}
		return 0;	
	}