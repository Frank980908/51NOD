/*#include <bits/stdc++.h>
using namespace std;
map<char,int>mp;
map<char,int>mp2; 

void update( char c ){
	int k = c-'a';
	for( int j = k + 1 ; j < 26 ; j++ ){
		mp2[(char)('a'+j)] --;
	}
	mp[c] = 0;
}

int main(){
	string s;
	cin >> s;
	int size =s.size();
	int num = 0;
	int id = -1;
	for( int i = 0 ; i < size; i ++ ){
		mp[s[i]]++;
	}
	for( int i = 0 ; i < 26 ; i++ ){
		int num = 0;
		for( int j = 0 ; j < i ; j++ ){
			if( mp[(char)(j+'a')] ){
				num ++;
			}
		}
		mp2[(char)('a'+i)] = num;
	}
	for( int i = 0 ; i < size ; i++ ){
		if( !mp[s[i]] ) continue;
		if( mp[s[i]] == 1 ){
			if( !mp2[s[i]] ){
				cout << s[i];
				update(s[i]);
				id = i;
			}else{
				while( true ){
					char tmp = s[i];
					int t = id;
					for( int j = id + 1 ; j < i ; j ++ ){
						if( mp[s[j]] && s[j] <= tmp ){
							tmp = s[j];
							id = j;
						}
					}
					if( t == id ){
						if( mp[s[i]] ){
							id = i;
							cout << s[i];
							update(s[i]);
						}
						break;
					}
					cout << s[id] ;
					update(s[id]);
				}
			}
		}else{
			if( mp[s[i]] && !mp2[s[i]] ){
				cout << s[i] ;
				update(s[i]);
				id = i;
			}
		}
		if( mp[s[i]] ){
			mp[s[i]] --;
		}
	}
	cout << endl;
	return 0 ;
}*/
#include <bits/stdc++.h>
using namespace std;
const int AX = 1e5+66;
map<char,int>mp;
map<char,int>mp1;
char res[AX];
int main(){
	string s;
	cin >> s;
	int size = s.size();
	for( int i = 0 ; i < size ; i++ ){
		mp[s[i]] ++;
	}
	int tot = 0 ;
	for( int i = 0 ;i < size ; i++ ){
		mp[s[i]]--;
		if( mp1[s[i]] ) continue;
		if( !tot ){
			res[++tot] = s[i];
			mp1[s[i]] = 1;
		}else{
			while( true ){
				char c = res[tot];
				if( c > s[i] && mp[c] ){
					mp1[c] = 0;
					tot--;
				}else{
					res[++tot] = s[i];
					mp1[s[i]] = 1;
					break;
				}
				if( !tot ){
					res[++tot] = s[i];
					mp1[s[i]] = 1;
					break;
				}
			}
		}
	}
	for( int i = 1 ; i <= tot ; i++ ){
		cout << res[i] ;
	}cout << endl;
	return 0;
}