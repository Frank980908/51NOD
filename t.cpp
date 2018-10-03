#include <bits/stdc++.h>
using namespace std;
map<string,int>mp;
int main(){
	char s[20];
	cin >> s ;
	mp[s]++;
	char que[20];
	char t[20];
	for( int i = 0 ; i < 6; i++ ){
		cin >> que[i];
	}
	strcpy(t,que);
	que[6] = '\0';
	//t[6] = '\0';
		cout << mp[que] << endl;
	return 0;
}