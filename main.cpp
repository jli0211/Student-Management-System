#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct date{
    int day;
    int month;
    int year; 
};

class Classes{
    public:
        string className;
        int classId;
        string semester;
        char grade;
    
    
};
class StudentData{
    public:
        int studentIDdata[1000];
        string classes[50];
        int currEnrolledNum;
        int classTaken;
        bool init = false;
        void initialize(){
            currEnrolledNum =0;
            classTaken = 0;
            init = true;
        }
};
class Student{
    int studentId;
    int age;
    string name;
    date DOB;

    public:
        void create_new_student();
        void delete_student();
        void access_student();
        void display_all();
        void display_student();
    
};

StudentData BU;

void Student::create_new_student(){
    if(BU.init == false){
        BU.initialize();
    }
    ofstream outfile;
    string fileName = name + ".txt";
    outfile.open(fileName, ios::out| ios::trunc);
    cout << "Enter name of the student: \n";
    string x;
    cin >> x;
    name = x;
    outfile << "Student name: " + name << "\n";
    cout << "Was the Student given an ID? (Y/N) \n";
    string d;
    cin >> d;
    const char* str1 = d.c_str();
    char str2 []= "Y";
    int res = strcmp(str1, str2);
    if(res == 0){
        cout << "Enter student ID: \n";
        int id;
        cin >> id;
        studentId = id;
        BU.studentIDdata[BU.currEnrolledNum] = id;
        BU.currEnrolledNum++;
    } else{
        cout << "Generate new 4 digit ID number: \n";
        if(BU.currEnrolledNum == 0){
            int n = rand() % 9000 + 1000;
            BU.studentIDdata[0] == n;
        } else{
            redo:
            int n = rand() % 9000 + 1000;
            int i = 0;
            while(i < BU.currEnrolledNum){
                if(n == BU.studentIDdata[i]){
                    goto redo;
                }
            }
            BU.studentIDdata[BU.currEnrolledNum] == n;
            studentId = n;
        }
    }
    outfile << "Student ID: " << studentId << endl;
    cout <<"Enter age: "<< endl;
    int ageInput;
    cin >>ageInput;
    age = ageInput;
    outfile << "Age: " << age << endl;
    cout <<"Enter day: \n";
    int a, b, c;
    cin >> a;
    cout <<"Enter month of birth: " << endl;
    cin >> b;
    cout << "Enter year of birth: " << endl;
    cin >> c;
    DOB.day = a;
    DOB.month = b;
    DOB.year = c;

    outfile << "Date of Birth: "<< to_string(DOB.month) + "/" + to_string(DOB.day) + "/" + to_string(DOB.year) + '\n';
    outfile.close();
}

void Student::display_student(){
    string mytext;
    string fileName = name + ".txt";
    ifstream infile(fileName);
    while(getline(infile, mytext)){
        cout << mytext <<endl;
    }
    infile.close();
}

int main(){
    Student a;
    a.display_student();
}