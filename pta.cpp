/*#include <bits/stdc++.h>
#define LL long long 
using namespace std;
const int AX = 1e5+6;
double mp[AX];
int vis[AX];

double g[AX];

vector<int> G[AX];
vector<int> re;
double z , r;

double cal( int step ){
	double ans = z;
	if( step == 0 ) return ans;
	for( int i = 0 ; i < step ; i++ ){
		ans = (double)( ans * (double)( 100.0 - r ) / (double)100.0 );
	}	
	return ans ;
}
double res ;

void dfs( int u , int step ){
	vis[u] = 1;
	for( int i = 0 ; i < G[u].size() ; i ++ ){
		int v = G[u][i];
		if( !vis[v] ){
			double tmp;
			if( mp[v] != 0 ){
				tmp = cal( step );
				tmp = (double) ( tmp * (double)mp[v] );
			}else{
				tmp = cal( step + 1 );
			}
			g[v] = tmp;
			dfs( v , step + 1 );
		}
	}
	return;
}

int main(){
	int n ;
	cin >> n >> z >> r;
	memset( g, 0.0 , sizeof(g));
	g[0] = z;
	res = 0.0;
	int k ;
	memset( mp, 0.0 , sizeof(mp));
	for( int i = 0 ; i < n ; i++ ){
		cin >> k;
		if( k == 0 ){
			double x ;
			cin >> x;
			mp[i] = x ;
			re.push_back(i);
		}else{
			for( int j = 0 ; j < k ; j ++ ){
				int x ;
				cin >> x;
				G[i].push_back(x);
			}			
		}
	}
	memset( vis, 0 ,sizeof(vis) );
	dfs( 0 , 0 );
	for( int i = 0 ; i < re.size() ; i ++ ){
		res += g[re[i]];
	}
	printf("%.0llf\n",res);
	return 0 ;
}


*/
#include <bits/stdc++.h>
using namespace std;
const int AX = 1e3+6;
int a[AX];
int n ;

void permutation( ){
	int j ;
	int k ;
	while( true ){
		for( int i = 0 ; i < n ; i++ ){
			cout << a[i];
		}cout << endl;
		j = n - 2 ;
		while( j >= 0 && a[j] >= a[j+1] ) --j;
		if( j < 0 ) return;
		k = n - 1 ;
		while( k > j && a[k] <= a[j] ) --k;
		swap(a[k],a[j]);
		for( int l = j + 1 , r = n - 1 ; l < r  ; l++ , r-- ){
			swap( a[l] , a[r] );
		}
	}
}

int main(){
	cin >> n ;
	for( int i = 0 ; i < n ; i++ ){
		cin >> a[i];
	}
	permutation();
	return 0;
}