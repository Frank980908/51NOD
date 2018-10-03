#include <bits/stdc++.h>
using namespace std;
const int AX = 50+66;
char s[AX];
int main(){
	int T;
	cin >> T;
	while( T-- ){
		cin >> s;
		int res ;
		map<char,int>mp;
		mp[s[0]] ++ ;
		mp[s[1]] ++ ;
		mp[s[2]] ++ ;
		int len = strlen(s);
		if( len == 1 ) res = 0;
		else if( len == 2 ) res = 1;
		else if( len == 3 ) res = 3;
		else{
			res = 3; 
			for( int i = 3 ; i < len ; i++ ){
				int R = ( ( mp['R'] > 2 ) ? 2 : mp['R'] );
				int G = ( ( mp['G'] > 2 ) ? 2 : mp['G'] );
				int B = ( ( mp['B'] > 2 ) ? 2 : mp['B'] );
				res += (R + G + B);
				mp[s[i]]++;
			}
		}
		cout << res << endl;
	}
	return 0;	
}