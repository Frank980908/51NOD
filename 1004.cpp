#include <bits/stdc++.h>
#define LL long long
using namespace std;
int main(){	
	int n;
	cin>>n;
	int single = n%10;
	 n = n % 4 + 4;
	cout<< (int)(pow(single,n))%10 <<endl; 
	return 0;
}