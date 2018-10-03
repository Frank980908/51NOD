#include <bits/stdc++.h>
using namespace std; 
int main()
{
	int n;
	cin >> n;
	double ans = 1.0;
	for( int i = 2 ; i <= n ; i++ ){
		ans = ans * 2 * (i-1) / (2 * i - 1);
	}
	printf("%.6lf\n",ans);
	return 0;
}