#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
	int n , k ,c ;
	cin >> n >> k >> c ;
	int res = 0;
	while( c ){
		if( k <= n ){
			res += n;
			c = 0;
		}else{
			if( c <= n ){
				res += c;
				c = 0;
			}else{
				res += n;
				c -= n;
			}
			k -= n ;
		}
	}
	cout << res << endl;
	return 0;	
}