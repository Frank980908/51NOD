#include <bits/stdc++.h>
#define INF 0x3f3f3f
using namespace std;
const int AX = 5e4+666;
int main(){
	int n , L ;
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> L ;
	int x;
	int minu = 0 , maxn = 0 ;
	for( int i = 0 ; i < n ; i++ ){
		cin >> x;
		minu = max(minu,min(x,L-x));
		maxn = max(maxn,max(x,L-x));
	}
	cout << minu << ' ' << maxn << endl ;
	return 0;
}