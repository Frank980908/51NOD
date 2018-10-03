#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int AX = 1e9;
const int manx = 1e7;
map<LL,int>mp;
int main(){
	int T;
	cin>>T;
	int n;

	int num;
	int ans = 4;
	for( num = 3 ; ans<=AX ; num ++ ){
		ans += num;
	//	cout<<ans<<",";
		mp[ans] = 1;
	}
	mp[1] = mp[2] = mp[4] = 1;
	while( T-- ){
		cin>>n;
		if( mp[n] ) cout<<1<<endl;
		else cout<<0<<endl;
	}
	return 0;
}