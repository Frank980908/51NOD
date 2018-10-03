#include <bits/stdc++.h>
using namespace std;
stack<int>s;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	int x , dir;
	int ans = n;
	for( int i = 0 ; i < n ; i++ ){
		cin >> x >> dir;
		if( dir == 1 ){
			s.push(x);
		}else{
			while( !s.empty() ){
				if( s.top() < x ){
					ans -- ;
					s.pop();
				}else{
					ans -- ;
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}