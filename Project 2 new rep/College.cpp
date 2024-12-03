#include "College.h"
void College::addCourse()
{
	string name;
	int num;
	cout << "enter course name" << endl;
	cin >> name;
	cout << "enter course id" << endl;
	cin >> num;
	courses.insert(num, name);
}
void College::removeCourse()
{
	int num;
	cout << "enter course id" << endl;
	cin >> num;
	courses.remove(num);
}
void College::addStudent()
{
	string name;
	cout << "enter students name" << endl;
	cin >> name;
	list<int> lst;
	students.insert(name, lst);
}
void College::removeStudent()
{
	string name;
	cout << "enter students name" << endl;
	cin >> name;
	students.remove(name);
}
void College::registration()
{
	string name;
	cout << "enter students name" << endl;
	cin >> name;
	int num;
	cout << "enter course id" << endl;
	cin >> num;
	try {
		students.search(name).push_back(num);
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}
void College::removeReg()
{
	string name;
	cout << "enter students name" << endl;
	cin >> name;
	int num;
	cout << "enter course id" << endl;
	cin >> num;
	try {
		students.search(name).remove(num);
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
}

void College::print()
{
	string name;
	cout << "enter students name" << endl;
	cin >> name;
	try {
		list<int> lst = students.search(name);
		for (list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		{
			Course temp = courses.search(*it);
			cout << temp.getName() << ' ';
		}
		cout << endl;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}

}

void College::printStudentsTable() {
	students.print();
}

void College::printCoursesTable() {
	courses.print();
}