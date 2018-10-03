#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int AX = 5e4+666;

struct Node
{
	int l , r;
}e[AX];
bool cmp( const Node &a , const Node &b){
	if( a.l == b.l ) return a.r > b.r;
	else return a.l < b.l;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for( int i = 0 ; i < n ; i++ ){
		cin >> e[i].l >> e[i].r;
	}
	sort( e, e + n, cmp );
	int far_r = e[0].r;
	int maxn = 0;
	for( int i = 1 ; i  < n ; i++ ){
		maxn = max( maxn , min(e[i].r , far_r) - e[i].l );
		if( e[i].r > far_r ){
			far_r = e[i].r;
		}
	}
	cout<<maxn<<endl;
	return 0;
}