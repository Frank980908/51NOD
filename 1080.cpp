#include <bits/stdc++.h>
using namespace std;
map<int,int>mp;
int main(){
	int n;
	scanf("%d",&n);
	int j = sqrt(n);
	int flag = 0;
	for( int i = 0  ; i <= j ; i++ ){
		int v = n - i*i;
		int u = sqrt(v);
		if( u*u == v  &&  i * i + u*u == n ) {
			if( mp[i] && mp[u] ) continue;
			mp[i] = 1 ; mp[u] = 1;
			cout<< i << ' ' << u <<endl;
			flag = 1;
		}
	}
	if( !flag ) cout<<"No Solution"<<endl;
	return 0;
}