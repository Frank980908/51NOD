/*#include <bits/stdc++.h>
#define LL long long 
using namespace std;
const int AX = 1e5+66;
struct Node{
	LL v,id;
}dp[AX][20];

int n;
void RMQ(){
	for( int j = 1 ; (1 << j) <= n ; j ++ ){
		for( int i = 0 ; i + (1<<j) - 1 < n ; i++ ){
			if( dp[i][j-1].v > dp[i+(1<<(j-1))][j-1].v ){
				dp[i][j].v = dp[i][j-1].v;
				dp[i][j].id = dp[i][j-1].id;
			}else{
				dp[i][j].v = dp[i+(1<<(j-1))][j-1].v;
				dp[i][j].id = dp[i+(1<<(j-1))][j-1].id;
			}
		}
	}
}

Node query( int l , int r ){
	int k = (int)(log(r-l+1)/log(2));
	return ( dp[l][k].v > dp[r-(1<<k)+1][k].v ? dp[l][k] : dp[r-(1<<k)+1][k] );
}

int dfs( int l , int r ){
	if( l == r ) return 1;
	if( l > r ) return 0;
	Node tmp = query( l , r );
	return max( dfs( l, tmp.id - 1 ) , dfs( tmp.id + 1 , r ) ) + 1 ;
}

int main(){
	cin >> n ;
	for( int i = 0 ; i < n ; i++ ){
		cin >> dp[i][0].v;
		dp[i][0].id = i;
	}
	RMQ();
	int res = dfs( 0 , n - 1 );
	cout << res << endl;
	return 0 ;
}*/
#include <bits/stdc++.h>
using namespace std;
const int AX = 1e5+66;
struct Node
{
	int v,len;
}a[AX];
stack<int>s;
int main(){
	int n ;
	cin >> n ;
	int res = 0 ;
	for( int i = 0 ; i < n ; i++ ){
		cin >> a[i].v;
		int tmp = 0 ;
		while( !s.empty() ){
			int t = s.top();
			if( a[i].v > a[t].v ){
				tmp = max( tmp , a[t].len );
				s.pop();
			}else break;
		}
		tmp ++;
		int size = s.size();
		tmp = max( tmp , size + 1 );
		a[i].len = tmp;
		res = max( res , a[i].len ); 
		s.push(i);
	}
	cout << res << endl;
	return 0 ;
}