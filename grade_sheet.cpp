#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdio>
#include <windows.h>
#include <iomanip>


using namespace std;

int total_course;
string letter_grade(int n){
	string grade;
	if(n>=80)
		grade= "A+";
	else if(n>=75)
		grade="A";
	else if(n>=70)
		grade="A-";
	else if(n>=65)
		grade="B+";
    else if(n>=60)
        grade="B";
    else if(n>=55)
        grade="B-";
    else if(n>=50)
        grade="C+";
    else if(n>=45)
        grade="C";
    else if(n>=40)
        grade="D";
    else
        grade="F";

    return grade;

}
double GPA(int n, float CH){
	double gpa;
	if(n>=80)
		gpa= CH*4.00;
	else if(n>=75)
		gpa=CH*3.75;
	else if(n>=70)
		gpa=CH*3.50;
	else if(n>=65)
		gpa=CH*3.25;
    else if(n>=60)
        gpa=CH*3.00;
    else if(n>=55)
        gpa=CH*2.75;
    else if(n>=50)
        gpa=CH*2.50;
    else if(n>=45)
        gpa=CH*2.25;
    else if(n>=40)
        gpa=CH*2.00;
    else
        gpa=CH*0.00;

    return gpa;

}
class course
{
	string course_code;
	float credit_hour;
	int obtained_marks;
public:
	course(){
		cout<<"Enter Course Code : ";
		cin>>course_code;
		cout<<"Enter Creadit Per Hour : ";
		cin>>credit_hour;
		cout<<"Enter your "<<course_code<<"  marks out of 100 : ";
		cin>>obtained_marks;
		cout<<"\n";
	}
	double sum_GPA(){
		return GPA(obtained_marks,credit_hour);
	}
	int sum_CH(){
		return credit_hour;
	}
	void show_output(){				// Function to show course info on screen;
		cout<<"\n\t"<<course_code<<"\t"<<credit_hour<<"\t\t"<<obtained_marks<<"\t\t"<<letter_grade(obtained_marks);
	}
};

void set_data(){
	string id;
	cout<<"Enter Your id: ";
	cin>>id;
	cout<<"\nEnter Your total course No: ";
	cin>>total_course;

	course cr[total_course];

	system("CLS");			// Clear console  screen

	cout<<"		\t	+-+-+-+-+-+ +-+-+-+-+-+     "<<"\n";
	cout<<"		\t	|G|R|A|D|E| |S|H|E|E|T|		"<<"\n";
	cout<<"		\t	+-+-+-+-+-+ +-+-+-+-+-+		"<<"\n";

	cout<<"\n\tId: "<<id<<"\t\t\tTotal Course : "<<total_course;
	cout<<"\n\n";
	cout<<"\n\tCourse Code\t"<<"Credit Hour\t"<<"Obtained Marks\t"<<"Letter Grade"<<"\n";

	double sum_gpa = 0;
	float sum_ch=0;
	for(int i=0;i<total_course;i++){
		cr[i].show_output();
		sum_gpa += cr[i].sum_GPA();
		sum_ch += cr[i].sum_CH();
	}

	cout<<"\n\n\t\tYour CGPA : "<<setprecision(4)<<sum_gpa/sum_ch;
}
void show_output(){
	cout<<"\n\n\n\tOptione will be avaiable soon, Please Contact Provider.";
}
int main(int argc, char const *argv[])
{
	char ch;
	do
	{
		//system("CLS");
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t01. Input Result";
		cout<<"\n\n\t02. Show Result";
		cout<<"\n\n\t03. EXIT";
		cout<<"\n\n\tPlease Select Your Option (1/2/3) ";
		cin>>ch;

		label: 
		switch(ch)
		{
            case '1':  set_data();
				break;
			case '2': show_output();
				break;
			case '3':
				break;
			default :cout<<"\a";

		}
    }while(ch!='3');
	return 0;
}