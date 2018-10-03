#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
const int AX = 5e4+66;
int a[AX];
int pre[AX];
int rear[AX]; 
map<int,int>mp;
int main(){
	int n ;
	scanf("%d",&n);
	for( int i = 0 ; i < n ; i++ ){
		scanf("%d",&a[i]);
	}
	memset( pre , 0 ,sizeof(pre) );
	memset( rear , 0 ,sizeof(rear) );
	mp[a[0]] = 1;
	pre[0] = 1;
	for( int i = 1 ; i < n ; i ++ ){
		if( !mp[a[i]] ){
			mp[a[i]] = 1;
			pre[i] = pre[i-1] + 1;
		}else{
			pre[i] = pre[i-1];
		}
	}
	mp.clear();
	mp[a[n-1]] = 1;
	rear[0] = 1;
	for( int i = n - 2 ; i >= 0 ; i -- ){
		if( !mp[a[i]] ){
			mp[a[i]] = 1;
			rear[n-1-i] = rear[n-i-2] + 1 ;
		}else{
			rear[n-1-i] = rear[n-i-2];
		}
	}
	int num = pre[n-1];
	int res = 0;
	int pos1 = lower_bound( pre, pre + n , num )-pre;
	int pos2 = lower_bound( rear , rear + n , num )-rear;
	int id1 = pos1;
	int id2 = pos2;
	int x1 = n - pos1;
	int x2 = n - pos2;
	res += x1 * x2;
	for( int i = num - 1 ; i >= 2 ; i -- ){
		if( a[pos1] == a[n-1-pos2] ){
			pos1 = lower_bound( pre , pre + n , i ) - pre;
			pos2 = lower_bound( rear , rear + n , i ) - rear;
			res += ( pos1 - id1 ) * ( pos2 - id2 );
			id1 = pos1;
			id2 = pos2;	
		}else break;
	}
	pos1 = upper_bound( pre , pre + n , 1 ) - pre;
	pos2 = upper_bound( rear , rear + n , 1 ) - rear;
	if( a[0] == a[n-1] ){
		res += ( pos1 ) * ( pos2 );
	}
	cout << res << endl;
	return 0;
}