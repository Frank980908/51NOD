#include <bits/stdc++.h>
using namespace std;
const int AX = 5e4+66;
struct Node{
	int x , y ;
	int pos;
}G[AX];
int c[AX];
int flect[AX];
int n ;
bool cmp( const Node &a , const Node &b ){
	if( a.x == b.x ){
		return a.y < b.y;
	}else{
		return a.x < b.x;
	}
}
bool cmp_s( const Node &a , const Node &b ){
	if( a.y == b.y ){
		return a.x < b.x;
	}else{
		return a.y < b.y;
	}
}
int lowbit( int x ){
	return x & (-x);
}
void update( int v , int site ){
	while( site <= n ){
		c[site] += v;
		site += lowbit(site);
	}
}
int getsum( int i ){
	int sum = 0;
	while( i ){
		sum += c[i];
		i -= lowbit(i);
	}
	return sum ;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n ;
	for( int i = 1 ; i <= n ; i ++ ){
		cin >> G[i].x >> G[i].y;
		G[i].pos = i;
	}
	sort( G + 1 , G + n + 1 ,cmp_s);

	int tot = 0;
	for( int i = 1 ; i <= n ; i++ ){
		if( i == 1 || G[i].y != G[i-1].y ){
			++tot;
			G[i].y = tot;
		}else{
			G[i].y = tot;
		}
	}
	sort( G + 1 , G + n + 1 , cmp);
	int res = 0;
	for( int i = 1 ; i <= n ; i++ ){
		update( 1 , G[i].y );
		res += (i - getsum(G[i].y));
	}	
	cout << res << endl;
	return 0 ;
}