#include <bits/stdc++.h>
using namespace std;
const int AX = 5e4+66;
int n,m;
int a[AX];
struct Node{
	int k,Q;
	int id;
}b[AX];
int vis[AX];
bool cmp( const Node &a , const Node &b ){
	return a.k > b.k;
}
struct cmp1{
	bool operator() (Node a , Node b ){
		return a.Q > b.Q;
	}
};
priority_queue<Node,vector<Node> ,cmp1>q;
int main(){
	cin >> n >> m;
	for( int i = 0; i < n ; i ++ ){
		cin >> a[i];
	}
	for( int i = 0 ; i < m ; i ++ ){
		cin >> b[i].k >> b[i].Q;
	}
	sort( a , a + n );
	sort( b , b + m , cmp );
	memset( vis , 0 ,sizeof(vis) );
	int res = 0;
	int j = 0 ;
	for( int i = n - 1 ; i >= 0 ; i -- ){
		for( ; j < m ; j++ ){
			if( b[j].k >= a[i] ){
				q.push(b[j]);
			}else break;
		}
		if( q.empty() ){
			res = -1;
			break;
		}
		res += q.top().Q;
		q.pop();
	}
	if( res == -1 ){
		cout << "No Solution" << endl;
	}else{
		cout << res << endl;
	}
	return 0;
}