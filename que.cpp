/*#include <bits/stdc++.h>
using namespace std;
stack<int>s;
const int AX = 50;
int a[AX];
int b[AX];
int res[AX];
int main(){
	int n;
	while( ~scanf("%d",&n) ){
		while(!s.empty())  s.pop();
		string s1, s2;
		cin >> s1 >> s2;
		int j = 0 ;
		int k = 0 ;
		for(int i = 0; i < n; i++){
			s.push(s1[i]);
			res[k++] = 1;
			while(!s.empty() && s.top() == s2[j]){
				res[k++] = 0;
				s.pop();
				j++;
			}
		}
		if( j == n ){
			printf("Yes.\n");
			for( int i = 0; i < k; i++){
				if(res[i])
					printf("in\n");
				else
					printf("out\n");
			}
		}
		else
			printf("No.\n");
		printf("FINISH\n");
	}
	return 0;
}*/
#include <bits/stdc++.h>
using namespace std;
stack<double>s;
stack<char>b;
int main(){
	char c;
	string ss;
	while( getline(cin,ss) ){
		if( ss.size() == 1 && ss[0] == '0' ) break;
		int len = ss.size();
		for( int i = 0 ; i < len ; i++ ){
			if( ss[i] >= '0' && ss[i] <= '9' ){
				double a;
				int j = i;
				string temp = "" ;
				while( j <= len ){
					if( ss[j] >= '0' && ss[j] <= '9' ){
						temp += ss[j];
					}else{
						a = 0.0;
						//cout << temp << endl;
						double as = 0.0;
						double mi = 1;
						for( int k = temp.size() - 1 ; k >= 0 ; k--){
							a += (double)( temp[k] - '0' ) * (double)mi;
							mi *= 10;
						}
						i = j;
						break;
					}
					j++;
				}
				if( !s.empty() ){
					if( !b.empty() ){
						char tmp = b.top();
						if( tmp == '*' ){
							b.pop();
							double t = s.top();
							s.pop();
							double ans = t * a;
							if( b.empty() ) s.push(ans);
							else{ 
								if( b.top() == '-' ){
									b.pop();
									b.push('+');
									s.push(0-ans);
								}else s.push(ans);
							}
							
						}else if( tmp == '/' ){
							b.pop();
							double t = s.top();
							s.pop();
							double ans = t / a;
							//s.push(ans);
							if( b.empty() ) s.push(ans);
							else{ 
								if( b.top() == '-' ){
									b.pop();
									b.push('+');
									s.push(0-ans);
								}else s.push(ans);
							}
							
						}else{
							if( b.empty() ) s.push(a);
							else{ 
								if( b.top() == '-' ){
									b.pop();
									b.push('+');
									s.push(0-a);
								}else s.push(a);
							}
							//s.push(a);
						}
					}else{
						if( b.empty() ) s.push(a);
						else{ 
							if( b.top() == '-' ){
								b.pop();
								b.push('+');
								s.push(0-a);
							}else s.push(a);
						}
						//s.push(a);
					}
				}else{
					if( b.empty() ) s.push(a);
					else{ 
						if( b.top() == '-' ){
							b.pop();
							b.push('+');
							s.push(0-a);
						}else s.push(a);
					}
					//s.push(a);
				}
			}else if( ss[i] == '+' || ss[i] == '-' || ss[i] == '*' || ss[i] == '/' ){
				b.push(ss[i]);
			}else{
				continue; 
			}
		}
		while( s.size() > 1 ){
			double a = 0.0;
			double tmp1 = s.top();
			s.pop();
			double tmp2 = s.top();
			s.pop();
			char c = b.top();
			if( c == '+' ){
				a = tmp1 + tmp2;
			}else if( c == '-' ){
				if( tmp1 > tmp2 ) swap(tmp2,tmp1);
				a = tmp2 - tmp1;
			}
			s.push(a);
			b.pop();
			if( b.empty() ) break;
		}
		double res = s.top();
		printf("%.2lf\n",res);
		while( !s.empty() ) s.pop();
		while( !b.empty() ) b.pop();
	}
	return 0;
}