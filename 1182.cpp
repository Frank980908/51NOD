#include <bits/stdc++.h>
using namespace std;
const int AX = 1e5+66;
char s[AX];
int num[26];
bool cmp(int a, int b){
	return a > b;
}

int main(){
	cin>>s;
	int len = strlen(s);
	memset( num , 0 , sizeof num );
	for( int i = 0 ; i < len ; i++ ){
		if( s[i] >='A' && s[i] <= 'Z' ){
			s[i] = tolower(s[i]);
		}
		num[s[i]-'a'] ++;
	}
	sort(num,num+26,cmp);
	int res = 0;
	int t = 26;
	for( int i = 0 ; i < 26 ; i++ ){
		res += t * num[i];
		t--;
	}
	cout<<res<<endl;
	return 0;
}