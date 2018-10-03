#include <iostream>
#include <algorithm>
using namespace std;
const int AX = 1e5+666;

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
	int o , r ;
	for( int i = 0 ; i < n ; i++ ) {
		cin >> o >> r;
		e[i].l = o - r ; 
		e[i].r = o + r ;
	}
	sort( e , e + n ,cmp );
	int res = 0;
	for( int i = 0 ; i < n ; i++ ){
		int l = 0 , r = n - 1 ; 
		int mid;
		while( l <= r ){
			mid = ( l + r ) >> 1;
			if( e[mid].r >= e[i].l ) r = mid - 1 ;
			else l = mid + 1;
		}
		res += l;
	}
	cout<< res <<endl;
	return 0;
}