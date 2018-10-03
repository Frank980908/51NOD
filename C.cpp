#include <bits/stdc++.h>
using namespace std;
const int AX = 2e5+666;

struct Node
{
	int l,r;
}e[AX];

bool cmp( const Node &a ,const Node &b ){
	if( a.r == b.r ) return a.l < b.l;
	else return a.r < b.r;
}

int main(){
	int n ;
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ ){
		scanf("%d%d",&e[i].l,&e[i].r);
	}
	sort(e,e+n,cmp);
	int tv1,tv2;
	tv1 = e[0].r , tv2 = e[1].r;
	int flag = 1;
	for( int i = 2 ; i < n ; i++ ){
		if( e[i].l < tv1 && e[i].l < tv2 ) {flag = 0 ; break;}
	}
	cout << ( flag == 1 ? "YES" << "NO" ) << endl; 
	return 0;
}