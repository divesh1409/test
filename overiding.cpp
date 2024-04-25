#include<iostream>
using namespace std;
class P{public:
	shiftgear(){
		cout<<"p";
	}
};
class c:public P{
	public:
	shiftgear(){
		cout<<"c";
	}
};
int main(){
	c c1;
	c1.shiftgear();
	}