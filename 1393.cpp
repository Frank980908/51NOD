#include <bits/stdc++.h>
using namespace std;
const int AX = 2e6+66;
char s[AX];
int sum[AX];
int hash[AX];
int main(){
	scanf("%s",s);
	int len = strlen(s);
	sum[0] = 0;
	int x;
	for( int i = 1 ; i <= len ; i++ ){
		if(s[i-1] == '0') x = -1;
		else x = 1;
		sum[i] = sum[i-1] + x; 
	}
	int maxum = 0 ;
	memset( hash , -1 , sizeof(hash) );
	int tmp;
	for( int i = 0 ; i < len ; i++ ){
		if( sum[i] < 0 ) tmp = sum[i] + 1e6;
		else tmp = sum[i];
		if( hash[tmp] == -1 ){
			hash[tmp] = i;
		}else{
			maxum = max( maxum , i - hash[tmp] );
		}
	}
	cout << maxum << endl;
	return 0;
}