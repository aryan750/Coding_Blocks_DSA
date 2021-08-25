#include<bits/stdc++.h>
using namespace std;

class Student{
public:
	string firstname;
	string lastname;
	string rollno;

	Student(string f, string l, string no){
		firstname = f;
		lastname = l;
		rollno = no;
	}

	bool operator==(const Student &s) const{
		return rollno == s.rollno;
	}
};


class HashFn{
public:
	size_t operator()(const Student &s) const{
		return s.firstname.length() + s.lastname.length() ? true:false;
	}
};




int main(){

	unordered_map<Student,int,HashFn> student_map;

	Student s1("Aryan", "Gupta","010");
	Student s2("Rahul", "Kamara","023");
	Student s3("Aryan", "Gupta","030");
	Student s4("Rahul", "Kamara","050");

	//add student-marks to hashmap

	student_map[s1] = 100;
	student_map[s2] = 120;
	student_map[s3] = 11;
	student_map[s4] = 100;


	//find the marks of student s3
	cout<<student_map[s3]<<endl;

	for(auto s: student_map){
		cout<<s.first.firstname<<" "<<s.first.rollno<<" Marks: "<<s.second<<endl;;
	}



	return 0;
}