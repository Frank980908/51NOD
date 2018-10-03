#include <iostream>
#include <algorithm>
using namespace std;
const int AX = 1e4+666;

struct  Node
{
	int l , r ;
}e[AX];

bool cmp( const Node &a , const Node &b ){
	if( a.r == b.r ) return a.l > b.l;
	else return a.r < b.r;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for( int i = 0 ; i < n ; i++ ) {
		cin >> e[i].l >> e[i].r;
	}
	sort( e , e + n ,cmp );
	int far_r = e[0].r;
	int res = 1;
	for( int i = 1 ; i < n ; i++ ){
		if( e[i].l >= far_r  ) {
			res++;
			far_r = e[i].r;
		}
	}	
	cout<<res<<endl;
	return 0;
}