#include <bits/stdc++.h>
using namespace std;
const int AX = 1e3+6;
char G[AX][AX];
int step[AX][AX][5];
set<char>se;
map<char,int>mp;
struct Node
{
	char c;
	int v;
}dir[100002];
int main(){
	mp['N'] = 0;
	mp['S'] = 1;
	mp['W'] = 2;
	mp['E'] = 3;
	int n , m , K ;
	scanf("%d%d",&n,&m);
	for( int i = 0 ; i < n ; i ++ ){
		scanf("%s",G[i]);
	}
	scanf("%d",&K);
	for( int i = 0 ; i < K ; i ++ ){
		cin >> dir[i].c >> dir[i].v;
	}
	// ↑ ↓ ← →
	for( int i = 0 ; i < n ; i++ ){
		for( int j = 0 ; j < m ; j++ ){
			if( G[i][j] == '#' ){
				step[i][j][0] = -1;
				step[i][j][1] = -1;
				step[i][j][2] = -1;
				step[i][j][3] = -1;
			}
		}
	}
	for( int i = 0 ; i < n ; i++ ){
		for( int j = 0 ; j < m ; j++ ){
			if( G[i][j] != '#' ){
				step[i][j][0] = step[i-1][j][0] + 1;
				step[i][j][2] = step[i][j-1][2] + 1;
			}
		}
	}
	for( int i = n-1 ; i >= 0 ; i --  ){
		for( int j = m-1 ; j >= 0 ; j -- ){
			if( G[i][j] != '#' ){
				step[i][j][1] = step[i+1][j][1] + 1;
				step[i][j][3] = step[i][j+1][3] + 1;
			}
		}
	}
	for( int i = 0 ; i < n ; i++ ){
		for( int j = 0 ; j < m ; j++ ){
			if( G[i][j] >= 'A' && G[i][j] <= 'Z' ){
				int falg = 1;
				int x = i , y = j;
				for( int k = 0 ; k < K ; k++ ){
					int tmp = mp[dir[k].c];
					if( step[x][y][tmp] < dir[k].v ){
						falg = 0; break;
					}else{
						if( tmp == 0 ) x -= dir[k].v;
						else if( tmp == 1 ) x += dir[k].v;
						else if( tmp == 2 ) y -= dir[k].v;
						else if( tmp == 3 ) y += dir[k].v;
					}
				}
				if( falg ) se.insert(G[i][j]);
			}
		}
	}
	if( se.size() ){
		set<char>::iterator it;
		for( it = se.begin() ; it != se.end() ; it++ ){
			cout << *it ;
		}	
	}else{
		cout << "no solution";
	}
	cout << endl;
	return 0;
}