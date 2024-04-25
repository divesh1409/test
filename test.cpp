#include<iostream>
using namespace std;
class complex{
	public:
	int a, b;
	setdata(int x,int y){
		this->a=x;
		this->b=y;
	}	
	display(){
		cout<<"a : "<<a<<"b: "<<b;
	}
	complex operator +(complex z){
	complex temp;
	temp.a=	a+z.a;
	temp.b=	b+z.b;
	return temp;
	}
};

int main(){
complex c1,c2,c3;
c1.setdata(2,3);
c2.setdata(3,2);
c3=c1+c2;
c3.display();
	return 0;
}