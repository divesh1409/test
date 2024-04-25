Ques 1. Employee, Manager, Worker

/* 1 Solve this.
Fresh business scenario to apply inheritance , polymorphism   to emp based organization scenario.

Create Emp based organization structure --- Emp , Mgr , Worker


1.1 Emp state--- id(int), name, deptId , basicSalary(double)
Accept all of above in constructor arguments.

Methods ---
1.2. compute net salary ---ret 0
(eg : public double computeNetSalary(){return 0;})

1.2 Mgr state  ---id,name,basic,deptId , perfBonus
Add suitable constructor
Methods ----
1. compute net salary (formula: basic+perfBonus) -- override computeNetSalary


1.3 Worker state  --id,name,basic,deptId,hoursWorked,hourlyRate
Methods : 
1.  compute net salary (formula:  = basic+(hoursWorked*hourlyRate) --override computeNetSalary
2. get hrlyRate of the worker  -- add a new method to return hourly rate of a worker.(getter)

Create suitable array to store organization details.
Provide following options
1. Hire Manager
I/P : all manager details

2. Hire Worker  
I/P : all worker details

3. Display information of all employees net salary (by invoking computeNetSal), 

4. Exit
----------------------------------------------------
*/


#include<iostream>
#include <string.h>
#include<typeinfo>

using namespace std;

class Employee{
	int empid;
	string name;
	int deptid;
	double salary;
	
	public:
		Employee(){
			empid = 100;
			name = "abc";
			deptid = 1;
			salary = 50000;
		}
		
		Employee(int empid, string name, int deptid, double salary){
			this->empid = empid;
			this->name = name;
			this->deptid = deptid;
			this->salary = salary;
		}
		
		virtual double computeNetSalary(){
			return this->salary;
		}
		
		virtual void display(){
			cout << "--------------------------------" << endl;
			cout << "empid =" << empid << endl;
			cout << "name =" << name << endl;
			cout << "deptid =" << deptid << endl;
			cout << "salary =" << salary << endl;
		}
	
};

class Manager : public Employee {
	
	double perfBonus;
	
	public:
		Manager(){
			this->perfBonus = 30000;
		}
		
		Manager(int empid, string name, int deptid, double salary, double perfBonus) : Employee(empid, name, deptid, salary){
			this->perfBonus = perfBonus;
		}
		
		double computeNetSalary(){
			double sal = Employee :: computeNetSalary() ;
			return sal + perfBonus;
		}
		
		void display(){
			Employee :: display ();
			cout << "perfBonus =" << perfBonus << endl;
			cout << "Net Salary =" << this->computeNetSalary() << endl;
			cout << "-----------------------------------------" << endl;
		}
	
};

class Worker : public Employee{
	int hoursWorked;
	double hourlyRate;
	 public:
	 	Worker(){
	 		this->hoursWorked = hoursWorked;
	 		this->hourlyRate = hourlyRate;
		 }
		 
		 Worker(int empid, string name, int deptid, double salary, int hoursWorked, double hourlyRate) : Employee(empid, name, deptid,salary){
		 	 this->hoursWorked = hoursWorked;
	 		this->hourlyRate = hourlyRate;
		 }
		 
		double getHourlyRate(){
			return this->hourlyRate;
		}
		
		double computeNetSalary(){
			double sal = Employee :: computeNetSalary() ;
			return sal + (hoursWorked * hourlyRate);
		}
	
		void display(){
			Employee :: display ();
			cout << "hoursWorked =" << hoursWorked << endl;
			cout << "hourlyRate =" << hourlyRate << endl;
			cout << "Net Salary =" << this->computeNetSalary() << endl;
			cout << "-------------------------------" << endl;
		}
	
	
	
};

int main(){
	
//	Employee e1(125, "Aman", 325, 200000);
//	Manager m1(128, "Divesh", 328, 250000, 50000);
//	Manager m2(130, "Vikram", 330, 220000, 40000);
	
//	e1.display();
//	m1.display();
//	
//	cout << e1.computeNetSalary() << endl;
//	cout << m1.computeNetSalary() << endl;
//	
//	Worker w1(129, "iacsd", 329, 10000, 8, 50);
//	cout << w1.computeNetSalary() << endl;
//	w1.display();
	
	Employee* Arr[10];
//	Arr [0] = &e1;
//	Arr [1] = &m1;
//	Arr [2] = &w1;
//	Arr [3] = &m2;
	
	int choice;
	int counter = -1;
	int empid, deptid;
	string name;
	double bsalary, bonus;
	double hwork, hrate;
	Manager m1;
	Worker w1;
	
	do{	
	cout << "OPTIONS :" << endl;
	cout << "1. Hire Managers" << endl;
	cout << "2. Hire Workers" << endl;
	cout << "3. Exit" << endl;
	cout << "Enter your choice :" << endl;
	cin >> choice;
	
		switch(choice){
			
		case 1:
			counter++;
//			int empid, deptid;
//			string name;
//			double bsalary, bonus;
			cout << "Enter empid, name, deptid, basic salary, performance bonus"<<endl;
			cin >> empid >> name >> deptid >> bsalary >> bonus;
			m1 = Manager(empid, name, deptid, bsalary, bonus);
			Arr[counter] = &m1;
			break;
			
			case 2:
			counter++;
			cout << "Enter empid, name, deptid, basic salary, hours worked, hourly rate"<<endl;
			cin >> empid >> name >> deptid >> bsalary >> hwork >> hrate;
			w1 = Worker(empid, name, deptid, bsalary, hwork, hrate);
			Arr[counter] = &w1;
			break;
			
			case 3:
				break;
				
			default:
				cout << "Invalid Option. Please try again." << endl;
				break;
			
		}
		
	}while(choice != 3);
	
	for(int i = 0; i <= counter; i++){
		
		if(typeid (*Arr[i]) == typeid(Manager)){
			
			Manager* mobj = dynamic_cast<Manager*> (Arr[i]);
			mobj->display();
			
		}else if(typeid (*Arr[i]) == typeid(Worker)){
			
			Worker* wobj = dynamic_cast<Worker*> (Arr[i]);
			wobj->display();
			
		}else{
			
			Arr[i]->display();
			
		}
		
	}
	
	
	return 0;
}

