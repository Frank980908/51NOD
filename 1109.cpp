#include <bits/stdc++.h>
using namespace std;
const int AX = 1e6+66;
int n ;
struct Node{
	int x ;
	int fa;
}ans[AX],cur;
queue<Node>q;
int vis[AX];
void dfs( int id ){
	int tmp = ans[id].fa;
	if( tmp <= 0 ) {
		cout << 1 ;
		return ;
	} 
	dfs( tmp );
	cout << ans[tmp].x;
}

void bfs(){
	
	cur.x = 1 ;
	cur.fa = 0;
	int tot = 1;
	q.push(cur);
	ans[0].x = 1;
	ans[0].fa = 0;
	while( !q.empty() ){
		Node tmp = q.front();
		q.pop();
		for( int i = 0 ; i <= 1 ; i ++ ){
			cur.x = tmp.x * 10 + i ;
			cur.x %= n; 
			if( !vis[cur.x] ){
				cur.fa = tot ;
				vis[cur.x] = 1;
				ans[tot].x = i;
				ans[tot].fa = tmp.fa;
				q.push(cur);
				if( cur.x == 0 ){
					dfs(tot);
					cout << i << endl;
					return ;
				}
				tot ++ ;
			}
		}		
	}
}

int main(){
	cin >> n;
	bfs();	
	return 0 ;
}