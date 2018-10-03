#include <bits/stdc++.h>
using namespace std;
int main(){

	char a[100];
	char b[100];
	scanf("%s",a+1);
	cout<<strlen(a+1);
	scanf("%s",b);
	if( strcmp( a+2 , b+1 ) == 0 ){
		cout<<'Y'<<endl;
	}else cout<<'N'<<endl;
	return 0;
}