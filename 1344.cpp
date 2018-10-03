#include <bits/stdc++.h>
#define LL __int64
#define INF 0x3f3f3f
using namespace std;
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	LL mins;
	LL x;
	LL sum = 0;
	cin>>x;
	mins = x;
	sum = x;
	for( int i = 1 ; i < n ; i++ ){
		cin>>x;
		sum += x;
		if( mins > sum ){
			mins = sum;
		}
	}
	cout<<0-mins<<endl;
	return 0;
}