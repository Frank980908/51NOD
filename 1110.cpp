#include <bits/stdc++.h>
#define LL long long 
using namespace std;
const LL AX = 1e4+66;
struct Node{
	LL x,v;
}a[AX];
bool cmp( const Node &a , const Node &b ){
	return a.x < b.x;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	LL n ;
	cin >> n ;
	LL len = 0 ;
	for( LL i = 0 ; i < n ; i++ ){
		cin >> a[i].x >> a[i].v;
		len += a[i].v;
	}
	sort( a , a + n , cmp );
	LL tmp = len / 2 + 1 ;
	LL mm;
	for( LL i = 0 ; i < n ; i++ ){
		if( tmp > a[i].v ){
			tmp -= a[i].v;
		}else{
			mm = a[i].x;
			break;
		}
	}
	LL res = 0;
	for( LL i = 0 ; i < n ; i++ ){
		res += abs(a[i].x-mm)*a[i].v;
	}
	cout << res << endl;
	return 0;
}