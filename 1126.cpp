#include <bits/stdc++.h>
using namespace std;
const int AX = 1e6+666;
long long f[AX]; 
int main(){
	long long a,b,n;
	cin >> a >> b >> n;
	f[1] = 1 ;
	f[2] = 1 ;
	int i;
	for( i = 3 ; i <= 7 * 7 ; i++ ){
		f[i] = ((a * f[i-1] )%7  + (b * f[i-2] )%7 + 7 ) % 7;
		if( f[i] == 1 && f[i-1] == 1 ) break;
	}
	i -= 2;
	if( n % i == 0 ) cout << f[i] << endl;
	else cout << f[n%i] << endl;
	return 0;
}