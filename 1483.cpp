#include <bits/stdc++.h>
using namespace std;
const int AX = 1e5+1;
int vis[2*AX];
int num[2*AX];
void cal(  int x  ){
	int step = 0;
	int p = x;
	while( p < AX ){
		num[p] += step ++ ;
		vis[p]++;
		p *= 2;
	}
	p = x;
	step = 0;
	while( p ){
		if( (p & 1) && p != 1 ){
			p /= 2;
			vis[p] ++;
			step ++ ;
			num[p] += step;
			int st = step;
			int pp = p;
			while( pp < AX ){
				pp *= 2;
				st ++ ;
				if( pp < AX ) {
					vis[pp]++;
					num[pp] += st;
				}
			}
		}else{
			p /= 2;
			step++;
			num[p] += step;
			vis[p] ++ ;
		}
	}
}

int main(){
	int n ;
	cin >> n ;
	int x;
	memset( num , 0 ,sizeof(num) );
	memset( vis , 0 ,sizeof(vis) );
	for( int i = 0 ; i < n ; i++ ){
		cin >> x;
		cal(  x );
	}
	int minus = 0x3f3f3f;
	for( int i = 1 ; i < 2e5 ; i ++ ){
		if( vis[i] == n )
			minus = min( minus , num[i] );
	}
	cout << minus << endl;
	return 0;
}