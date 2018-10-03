#include <bits/stdc++.h>
#define INF 1e18
#define LL long long
using namespace std;
const int AX = 5e4+666;
int a[AX];
LL sum[AX];
map<int,int>mp_min;
map<int,int>mp_max;
int main(){
	int n;
	cin >> n;
	for( int i = 0 ; i < n ; i++ ){
		scanf("%d",&a[i]);
	}
	sum[0] = 0;
	for( int i = 1 ; i <= n;  i++ ){
		sum[i] = a[i-1] + sum[i-1];
		if( mp_min[sum[i]] ){
			mp_min[sum[i]] = min( mp_min[sum[i]] , i );
		}else{
			mp_min[sum[i]] = i;
		}
		mp_max[sum[i]] = max( mp_max[sum[i]] , i );
	}
	sort( sum , sum + n + 1 );
	LL minus = INF;
	for( int i = 1 ; i <= n ; i++ ){
		if( mp_max[sum[i]] > mp_min[sum[i-1]] ){
			if( sum[i] - sum[i-1] > 0 ){
				minus = min( minus , sum[i] - sum[i-1] );
			}
		}
	}
	cout << minus << endl;
	return 0;
}