#include<iostream>
using namespace std;
class A{
	public:
		f1(){
			cout<<"f1";
		}
};
class B1:virtual public A
{
	public:
		f2(){
			cout<<"f2";
		}
};
class B2:virtual public A
{
	public:
		f3(){
			cout<<"f3";
		}
};
class C:public B1,public B2
{
	public:
		f4(){
			cout<<"f4";
		}
};
int main(){
	C c1;
	c1.f4();
	c1.f3();
	c1.f2();
	c1.f1();
}