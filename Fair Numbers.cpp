#include<iostream>
long long n,m;
int t;
using namespace std;
int f(){
	for(m=n;m&&!(m%10>1&&n%(m%10));m/=10);
	return m;
}
int main(){
	for(std::cin>>t;std::cin>>n;std::cout<<n<<endl)
	while(f())n++;
}