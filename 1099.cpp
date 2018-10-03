#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int AX = 1e5+66;
struct Node{
	int x , y ,z;
}s[AX];
bool cmp( const Node &a , const Node &b ){
	if( a.z == b.z ){
		if( a.x == b.x ) return a.y < b.y;
		return a.x < b.x;
	}
	else return a.z > b.z;
}
int main(){
	int n;
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ ){
		scanf("%d%d",&s[i].x, &s[i].y);
		s[i].z = s[i].x - s[i].y;
	}
	
	sort( s , s + n , cmp );
	LL minus = s[0].x ; 
	LL left = s[0].z ;

	LL c = s[0].y;

	for( int i = 1 ; i < n ; i++ ){
		if( left < s[i].x ){
			minus += s[i].x - left;
		}

		c += s[i].y;
		left = minus - c; 
	}
	cout << minus << endl;
	return 0;
}