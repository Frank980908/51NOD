#include <bits/stdc++.h>
using namespace std;
const int AX = 1e3+66;
struct Node{
	int d;
	int v;
}a[AX];

int main(){
	int n , h ;
	scanf("%d%d",&n,&h);
	int tot = 0;
	int hi , pi;
	for( int i = 0 ; i < n ; i++ ){
		cin >> hi >> pi ;
		if( 2 + 2 * hi > 2 * h ) continue;
		a[tot].d = hi; 
		a[tot++].v = pi;
	}

	return 0;
}