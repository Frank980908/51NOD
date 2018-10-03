#include <iostream>
#include <cstdio>
using namespace std;
const int AX = 5e4+666;
const int inf = 0x3f3f3f3f;
int a[AX];
int n,m;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	while(~scanf("%d%d", &n, &m)) {
		a[0] = inf;
		for(int i = 1; i <= n; ++i) {
			int x;
			scanf("%d", &x);
			a[i] = min(a[i-1], x);
		}
		int ans = 0;
		int cur = n;
		for(int i = 0; i < m; ++i) {
			int x;
			scanf("%d", &x);
			while(a[cur] < x) cur--;
			if(cur > 0) {
				//cout << endl << "cur: " << cur << "x: " << x << endl;
				ans++;
				cur--;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
