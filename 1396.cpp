#include <bits/stdc++.h>
using namespace std;
const int AX = 1e6+666;
char s[AX];
int sum0[AX];
int sum1[AX];
int main(){
	scanf("%s",s);
	int len = strlen(s);
	sum0[0] = 0;
	sum1[0] = 0;
	for( int i = 1 ; i <= len ; i++ ){
		int tmp;
		if( s[i-1] == '0' ) tmp = 1;
		else tmp = 0;
		sum0[i] = sum0[i-1] + tmp;
		sum1[i] = sum1[i-1] + !tmp;
	}
	int k = -1;
	for( int i = 0 ; i <= len ; i++ ){
		int tmp1 = sum1[len] - sum1[i];
		int tmp0 = sum0[i];
		if( i == len ) tmp1 = 0;
		if( i == 0 ) tmp0 = 0;
		if( tmp0 == tmp1 ){
			k = i ;
			break;
		}
	}
	cout << k << endl;
	return 0;
}