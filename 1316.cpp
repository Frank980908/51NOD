#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
const int AX = 100;
char s[AX][AX];
int n , m;
int visR[AX];
int visC[AX];
int vis[AX];
int pre[AX];
int Rc , Cc;
int res ;
int find( int x ){
	return x == pre[x] ? x : pre[x] = find(pre[x]);
}

void mix( int x , int y ){
	int xx = find(x);
	int yy = find(y);
	if( xx != yy ){
		pre[xx] = yy;
		return ;
	}
}

void solve(){
	for( int i = 0 ; i <= n * m ; i++ ) pre[i] = i;
		for( int i = 0 ; i < n ; i ++ ){
			if( visR[i] ){
				for( int j = 0 ; j < m ; j ++ ){
					int x = i * m + j;
					int y = i * m + m - j - 1;
					if( find(x) != find(y) ){
						mix( x , y );
					}
				}
			}	
		}
		for( int j = 0 ; j < m ; j++ ){
			if( visC[j] ){
				for( int i = 0 ; i < n ; i++ ){
					int x = i * m + j;
					int y = ( n - 1 - i ) * m + j;
					if( find(x) != find( y ) ){
						mix( x , y );
					}
				} 
			}
		}
		int tmp = 0 ;
		for( int k = 0 ; k < n * m ; k ++ ){
			int t = 1;
			int one = 0 , zero = 0;
			for( int i = 0 ; i < n ; i++ ){
				for( int j = 0 ; j < m ; j ++ ){
					int kk = i * m + j ;
					if( find(kk) == k ){
						t++;
						s[i][j] == '1' ? (one++) : (zero++);
					}
				}
			}
			if( t > 1 ){
				tmp += min(zero,one);
			}
		}
		res = min( res , tmp );
	}

	void createC( int x , int tot ){  
		if( x >= m ) return;
		if( tot > Cc ) return;
		if( tot + m - 1 - x < Cc ) return; 
		visC[x] = 1;  
		if( tot == Cc ){
			solve();
			return;  
		}  
		for( int i = x + 1 ;  i < m ; i++ ){  
			if( !visC[i] ){  
				createC( i , tot + 1 );  
				visC[i] = 0;  
			}  
		}  
	}  

	void createR( int x , int tot ){  
		if( x >= n ) return ;
		if( tot > Rc ) return;
		if( tot + n - 1 - x < Rc  ) return;
		visR[x] = 1;  
		if( tot == Rc ){
			for( int j = 0 ; j < m ; j++ ){
				memset( visC , 0 ,sizeof(visC));
				createC( j , 1 ); 
			}  
			return;  
		}  
		for( int i = x + 1 ;  i < n ; i++ ){  
			if( !visR[i] ){  
				createR( i , tot + 1 );  
				visR[i] = 0;  
			}  
		}  
	}  

	int main(){
		scanf("%d%d",&Rc,&Cc);
		scanf("%d",&n);
		res = 100000;
		for( int i = 0 ; i < n ; i++ ){
			scanf("%s",s[i]);
		}
		if( !Rc && !Cc ){
			cout << 0 << endl;
			return 0;
		}
		m = strlen(s[0]);
		for( int i = 0 ; i < n ; i++ ){
			memset( visR , 0 ,sizeof(visR) );
			createR( i , 1 );
		}
		cout << res << endl;
		return 0 ;
	}