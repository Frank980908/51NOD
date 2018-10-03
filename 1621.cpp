#include <bits/stdc++.h>
#define INF 12345678
using namespace std;
const int AX = 1e4+66;
int n , k ;
char s[AX];
int a[AX];
struct Node
{
	int v;
	int id;
	int val;
	bool f;
}ans[AX];
bool cmp( const Node &a , const Node &b ){
	if( a.v != b.v ) return a.v < b.v;
	else if( a.val != b.val ) return a.val > b.val;
	else {
		if( a.f ) return a.id < b.id;
		else return a.id > b.id;
	} 
}
int main(){
	scanf("%d%d",&n,&k);
	scanf("%s",s);
	int falg = 1 ;
	memset(a,0,sizeof(a));
	for( int i = 0 ; i < n ; i++ ){
		a[s[i]-'0'] ++ ;
		if( a[s[i]-'0'] >= k ){
			falg = 0;
		}
	}

	if( falg ){
		int val;
		int coss = -1 ;
		char res[AX];  
		for( int jj = 0 ; jj <= 9 ; jj++ ){
			val = jj;
			for( int i = 0 ; i < n ; i++ ){
				ans[i].v = abs( (s[i]-'0') - val);
				ans[i].id = i;
				ans[i].val = s[i]-'0';
				ans[i].f = ( (s[i]-'0') > val ? true : false );
			}
			int cost = 0;
			sort( ans , ans + n , cmp );
			int kk = k - a[val];
			for( int i = 0 ; i < n ;i++ ){
				if( kk == 0 ) break;
				if( s[ans[i].id] == (val+'0') ) continue;
				else{
					kk--;
					cost += ans[i].v;
					ans[i].val = val;
				}
			}
			char tmp[AX];
			for( int i = 0 ; i < n ; i++ ){
				int index = ans[i].id;
				tmp[index] = (char)(ans[i].val+'0');
			}
			if( coss != -1 ){
				if( cost < coss ){
					coss = cost;
					for( int i = 0 ; i < n ; i++ ){
						res[i] = tmp[i];
					}
				}else if( coss == cost ){
					if( strcmp( res , tmp ) > 0 ){
						for( int i = 0 ; i < n ; i++ ){
							res[i] = tmp[i];
						}
					}
				}
			}else{
				coss = cost;
				for( int i = 0 ; i < n ; i++ ){
					int index = ans[i].id;
					res[index] = (char)(ans[i].val + '0');
				}
			}
		}
		cout << coss << endl;
		for( int i = 0 ; i < n ; i++ ){
			cout << res[i];
		}
		cout << endl;
	}else{
		printf("0\n");
		printf("%s\n",s);		
	}
	return 0;
}