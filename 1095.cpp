#include <bits/stdc++.h>
using namespace std;
const int AX = 1e4+6;
char a[AX][60];
map<char,int>mp;
map<string,int>mp1;
map<string,int>mp2;
map<char,int>b;
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for( int i = 0 ; i < n ; i++ ){
		char s[20];
		cin >> s;
		mp1[s]++;
		mp.clear();
		for( int j = 0 ; j < strlen(s) ; j++ ){
			mp[s[j]]++;
		}
		for( int j = 0 ; j < 52; j++ ){
			if( j < 26 )
				a[i][j] = mp[(char)(j+'a')]+'0';
			else 
				a[i][j] = mp[(char)(j-26+'a'-32)]+'0';
		}
	}
	for( int i = 0 ; i < n ; i++ ){
		mp2[a[i]] ++;
	}
	int query;
	cin >> query;
	while( query-- ){
		char que[20];
		char temp[60];
		cin >> que;
		b.clear();
		for( int i = 0 ; i < strlen(que) ; i++ ){
			b[que[i]]++;
		}
		for( int i = 0 ; i < 52 ; i++ ){
			if( i < 26 )
				temp[i] = b[(char)(i+'a')]+'0';
			else 
				temp[i] = b[(char)(i-26+'a'-32)]+'0';
		}
		temp[52] = '\0';
		if( mp2[temp] != 0 ){
			cout << mp2[temp]-mp1[que] << endl;
		}else{
			cout << 0 << endl;
		}
	}
	return 0;
}