#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int AX = 1e4+666;
struct Node
{
	LL l , r ;
}e[AX];

bool cmp( const Node &a , const Node &b ){
	if( a.l == b.l ) return a.r < b.r;
	else return a.l < b.l;
}

bool operator<( Node a , Node b ){
	if( a.r == b.r ) return a.l < b.l;
	else return a.r > b.r;
}

priority_queue<Node>que;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n ;
	for( int i = 0 ; i < n ; i++ ){
		cin >> e[i].l >> e[i].r ;
	}
	sort(e,e+n,cmp);
	int res = 1;
	que.push(e[0]);
	for( int i = 1 ; i < n ; i++ ){
		if( que.top().r <= e[i].l ){
			que.pop();
			que.push(e[i]);
		}else{
			que.push(e[i]);
			res++;
		}
	}
	cout << res << endl;
	return 0;
}