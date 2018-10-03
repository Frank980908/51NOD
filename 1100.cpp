#include <bits/stdc++.h>
using namespace std;
const int AX = 1e4+66;
struct Node
{
	int x, y;
	int id ;
}s[AX],res[AX];

bool cmp( const Node &a , const Node &b ){
	if( a.x == b.x ){
		return a.y < b.y;
	}else return a.x < b.x;
}

int main(){
	int n ;
	cin >> n;
	for( int i = 0 ; i < n ; i ++ ){
		cin >> s[i].x >> s[i].y ;
		s[i].id = i;
	}
	sort( s , s + n , cmp );
	double minus = -1.0;
	int tot = 0;
	for( int i = 1 ; i < n ; i++ ){
		double k = ( s[i].y - s[i-1].y ) / ( s[i].x - s[i-1].x );
		if( -1.0 == minus ){
			minus = k;
			res[tot].x = s[i-1].id ;
			res[tot++].y = s[i].id ;
		}else if( minus == k ){
			res[tot].x = s[i-1].id;
			res[tot].y = s[i].id;
			tot ++;
		}else if( minus < k ){
			tot = 0;
			res[tot].x = s[i-1].id ;
			res[tot].y = s[i].id;
			tot ++ ;
			minus = k;
		}
	}
	for( int i = 0 ; i < tot ; i++ ){
		cout << ( res[i].x + 1 ) << ' ' << ( res[i].y + 1 ) << endl;
	} 
	return 0 ;
}