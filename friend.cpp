#include<iostream>
using namespace std;
class mean{
	public:
		int a,b;
		mean(int x,int y){
			this->a=x;
			this ->b=y;
		}
		friend int menn(mean );
};
int menn(mean m1){
	int meann;
	meann=(m1.a+m1.b)/2;
	cout<<meann;
}
int main(){
	mean m1(2,4);
menn(m1);
}