// Evyatar Borohov 325702322
// Eitan Ikar 213450661
#include<iostream>
#include<string>
#include "IntHash.h"
#include "StringHash.h"
#include "College.h"

using namespace std;
enum options {
	EXIT, ADD_COURSE, REMOVE_COURSE, ADD_STUDENT,
	REMOVE_STUDENT, REGISTRATION, REMOVE_REG, PRINT_STUDENT_INFO, PRINT_ALL_STUDENTS_TABLE, PRINT_ALL_COURSES_TABLE
};
void menu()
{
	cout << "Choose an option :\n";
	cout << "0 - to exit\n";
	cout << "1 - to add a course to the courses table\n";
	cout << "2 - to delete a course from the table\n";
	cout << "3 - to add a student to the students table\n";
	cout << "4 - to delete student from the table\n";
	cout << "5 - to register a student for the course\n";
	cout << "6 - to delete a student's registration from a course\n";
	cout << "7 - to print the names of the courses that a particular student is studying\n";
	cout << "8 - to print the students' table\n";
	cout << "9 - to print the courses' table\n";

}
int main()
{

	int maxNumStudents;
	cout << "Enter the maximal number of students\n";
	cin >> maxNumStudents;
	int maxNumCourses;
	cout << "Enter the maximal number of courses\n";
	cin >> maxNumCourses;

	College college(maxNumStudents, maxNumCourses);
	int choice;
	menu();
	do
	{
		cin >> choice;
		switch (choice)
		{
		case ADD_COURSE:		college.addCourse();		break;
		case REMOVE_COURSE:		college.removeCourse();		break;
		case ADD_STUDENT:		college.addStudent();		break;
		case REMOVE_STUDENT:	college.removeStudent();	break;
		case REGISTRATION:		college.registration();		break;
		case REMOVE_REG:		college.removeReg();		break;
		case PRINT_STUDENT_INFO:				college.print();			break;
		case PRINT_ALL_STUDENTS_TABLE:				college.printStudentsTable();			break;
		case PRINT_ALL_COURSES_TABLE:				college.printCoursesTable();			break;
		};
	} while (choice != EXIT);




	//******************************* Evytar"s main: *******************************
	//try {
	///*	IntHash<int> H(10);
	//	H.insert(8, 350);
	//	H.insert(4, 49);
	//	H.insert(5, 13);
	//	H.insert(46, 700);
	//	H.insert(4, 46);

	//	H.print();

	//	H.remove(4);
	//	cout << endl;
	//	H.print();
	//	cout << endl;
	//	cout << H.search(4) << endl;
	//	H.remove(4);*/

	//	/*StringHash<string> H(10);
	//	H.insert("hello", "evyatar");
	//	H.insert("hello", "johnni");

	//	H.insert("amiiii", "evyatar");
	//	H.print();
	//	cout << endl;
	//	H.remove("hello");
	//	H.print();
	//	cout << H.search("amiiii") << endl;
	//	cout << H.search("hello") << endl;*/

	//}
	//catch (const char* msg) {
	//	cout << msg << endl;
	//}	
	return 0;
}