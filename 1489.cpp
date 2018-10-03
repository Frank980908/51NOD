#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f;
const int AX = 10+5;
int blood[AX];
int n , a , b;
int ans = INF;

void dfs(int pos , int num){
	if( pos == n ){
		ans = min(num,ans);
		return;
	}
	if(blood[pos-1] < 0) dfs(pos+1,num);

	int temp = 0;
	if(blood[pos-1] >= 0){
		temp = blood[pos-1] / b + 1;
		blood[pos] -= temp * a;
		blood[pos-1] -= b*temp;
		blood[pos+1] -= b*temp;
		num += temp;
		dfs(pos+1,num);
		num -= temp;
		blood[pos] += temp * a;
		blood[pos-1] += b*temp;
		blood[pos+1] += b*temp;
	}

	int temp_x = blood[pos] / a + 1;
	if( blood[pos] >= 0 && temp < temp_x ){
		for( int i = temp+1 ; i <= temp_x ; i++ ){
			blood[pos] -= a*i;
			blood[pos-1] -= b*i;
			blood[pos+1] -= b*i;
			num += i;
			dfs(pos,num);
			num -= i;
			blood[pos] += a*i;
			blood[pos-1] += b*i;
			blood[pos+1] += b*i;
		}
	}
	return;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> a >> b;
	for( int i = 1 ; i <= n ;i++ ){
		cin >> blood[i];
	}
	int res = 0;
	int num = blood[1]/b+1;
	res += num;
	blood[1] -= b*num;
	blood[2] -= a*num;
	blood[3] -= b*num;
	if(blood[n] >= 0){
		num = blood[n]/b+1;
		blood[n] -= b*num;
		blood[n-1] -= a*num;
		blood[n-2] -= b*num;
		res += num;
	}
	dfs(2,0);
	res += (ans == INF ? 0 : ans);
	cout << res << endl;
	return 0;
}