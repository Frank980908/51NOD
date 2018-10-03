#include <bits/stdc++.h>
using namespace std;
const int AX = 1e5+666;
char s[AX];
map<char,int>mp1;
int main(){
	cin >> s;
	int len = strlen(s);
	int rt = 0;
	int index ;
	for( int i = 0 ; i < len ;i ++ ){
		if( rt == 26 ){
			index = i;
			break;
		}
		if( !mp1[s[i]] ){
			mp1[s[i]] = 1;
			rt ++ ;
		} 
	}
	if( rt < 26 ) printf("No Solution\n"); 
	else{
		map<int,int>mp;
		int st = 0 , e = 0 , num = 0 , ans = len;
		while( true ){
			while( e < len && num < 26 ){
				if( !mp[s[e]] ){
					num ++ ;
				}
				mp[s[e]]++;
				e++;
			}
			if( num < 26 ) break;
			ans = min( ans , e - st );
			if( --mp[s[st]] == 0 ){
				num--;
			}
			st++;
		}
		cout << ans  << endl;
	}
	return 0 ;
}