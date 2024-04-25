/* 3:Create a abstract class Shape with pure virtual method area;
Create Rectangle,Circle,Square class..inherit them from Shape class..Override area method.
Test these all classes by creating object of respective class. */


CODE:
#include<iostream>
#define pi 3.14
using namespace std;

class shape{
	public:
		virtual void area() = 0;
};

class rectangle : public shape{
	int l, b;
	
	public:
		
		rectangle(int l, int b){
			this->l = l;
			this->b = b;
		}
		
		void area(){
			cout << "Area of rect. is " << l*b << endl;
		}
};

class circle : public shape{
	int r;
	
	public:
		
		circle(int r){
			this->r = r;
		}
		
		void area(){
			cout << "Area of circle is " << pi*r*r << endl;
		}
};

class square : public shape{
	int s;
	
	public:
		
		square(int s){
			this->s = s;
		}
		void area(){
			cout << "Area of square is " << s*s << endl;
		}
};

int main(){
	
	rectangle r1(4,5);
	circle c1(7);
	square s1(3);
	
	s1.area();
	c1.area();
	r1.area();

	return 0;
}
