#include <bits/stdc++.h>
using namespace std;
const int AX = 22;
int a[AX];
int n,K;
int dfs(int ans , int dep){
	if(dep == n) return 0;
	if(ans == a[dep]) return 1;
	if(ans > a[dep]){
		ans -= a[dep];
		if(dfs(ans,dep+1)){
			return true;
		}
		ans += a[dep];
	}
	return dfs(ans,dep+1);
}

int main(){
	cin >> n >> K;
	for( int i = 0 ; i < n; i++ ){
		cin >> a[i];
	}
	if(dfs(K,0)){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}