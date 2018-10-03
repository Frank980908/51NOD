#include <bits/stdc++.h>
using namespace std;
const int AX = 50+6;
char G[AX][AX];
int vis[AX][AX];
map<char,int>mp;
int m , n ;
int dir[4][2] = {
	{ 1 , 0 },
	{ 0 , 1 },
	{ -1 , 0 },
	{ 0 , -1 }
};
int falg ;
void dfs( char c , int step , int sx , int sy ,int x , int y ){
	if( step >= 3 && (( abs(x - sx) == 1 && y == sy ) || ( x == sx && abs(y - sy) == 1 )) ){
		falg = 1 ;
		return ;
	}
	for( int i = 0 ; i < 4 ; i ++ ){
		if( falg ) return ;
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if( xx >= 0 && xx < m && yy >= 0 && yy < n && G[xx][yy] == c && !vis[xx][yy] ){
			vis[xx][yy] = 1;
			dfs( c , step+1 , sx, sy, xx ,yy ) ;
			vis[xx][yy] = 0;
		}
	}
}

int main(){
	scanf("%d%d",&m,&n);
	for( int i = 0 ; i < m ; i ++ ){
		scanf("%s",G[i]);
	}
	falg = 0;
	for( int i = 0 ; i < m ; i++ ){
		for( int j = 0 ; j < n ; j++ ){
			if( falg ) break;
			vis[i][j] = 1;
			dfs( G[i][j] , 0 , i , j , i , j );
			vis[i][j] = 0;
			
		}
		if( falg ) break;
	}
	if( !falg ) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}