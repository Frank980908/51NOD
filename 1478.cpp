#include <bits/stdc++.h>  
using namespace std;  
int main()  
{  
	string a;  
	stack<int>s;  
	s.push(-1);  
	cin>>a;  
	int len = a.size();  
	s.push(0);  
	for(int i=1;i<len;i++)  
	{  
		if(a[s.top()]=='('&&a[i]==')') s.pop();  
		else s.push(i);  
	}  
	int flag = len;  
	int tmp;  
	int mm = -1;  
	int num = 0;
	while(!s.empty()){  
		tmp = s.top();  
		s.pop();  
		if( mm < abs(tmp-flag) ){
			mm = abs(tmp-flag);
			num = 1;
		}else if( mm == abs(tmp-flag) ){
			num ++;
		}
		flag=tmp;  
	}  
	if( mm - 1 == 0  ) num = 1;
	cout << mm - 1 << ' ' << num << endl;  

	return 0;  
}  