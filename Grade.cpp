//
//  PIC 10A Homework 2, Grade.cpp
//  Author: Hailee Julius
//  Date: 4/20/23.
//
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    //creating user response prompts and variables
    
        //homework grade
    cout<<"Please enter your homework grade (0-100): ";
    double homework_grade;
    cin >> homework_grade;
    
        //midterm grade
    cout<< "Please enter your midterm grade (0-100): ";
    double midterm_grade;
    cin >> midterm_grade;
    
        //final grade
    cout<< "Please enter your final grade (0-100): ";
    double final_grade;
    cin >> final_grade;
    
        //exam format
    string remainder;
    getline(cin,remainder); //for some reason the getline for exam_format gets skipped unless I add this flippant getline before it (maybe excess in buffer?)
    cout<< "Please enter exam format, online or in-person? ";
    string exam_format;
    getline(cin,exam_format);
    
    //in-person scheme one (40,20,40):
    double in_person_scheme_one;
    in_person_scheme_one = (homework_grade * 40)/100 + (midterm_grade * 20)/100 + (final_grade * 40)/100;
    
    //inperson scheme two (40, 0, 60):
    double in_person_scheme_two;
    in_person_scheme_two = (homework_grade * 40)/100 + (midterm_grade * 0)/100 + (final_grade * 60)/100;
    
    //online scheme one (70, 10, 20):
    double online_scheme_one;
    online_scheme_one = (homework_grade * 70)/100 + (midterm_grade * 10)/100 + (final_grade * 20)/100;
    
    //online scheme two (70, 0, 30):
    double online_scheme_two;
    online_scheme_two = (homework_grade * 70)/100 + (midterm_grade * 0)/100 + (final_grade * 30)/100;
    
    //now that I have these I have to do the if statements
        //this first if statement will make sure all inputs are in the correct formats
    if(100 >=homework_grade && homework_grade>=0 && 100>=midterm_grade && midterm_grade>=0 && 100>=final_grade && final_grade >=0 && (exam_format == "in-person" || exam_format == "online")){
        cout<<"Overall grade is ";
        
        //let's deal with in-person exam stuff first:
        if(exam_format == "in-person"){
            if(in_person_scheme_one>=in_person_scheme_two){
                cout<<in_person_scheme_one<<endl;
            }
            else{cout<<in_person_scheme_two<<endl;;}
        }
        //now for online
        else {
            if(online_scheme_one >=online_scheme_one){
                cout<<online_scheme_one<<endl;
            }
            else{cout<<online_scheme_two<<endl;}
        }
    }
    else{
        cout<<"Wrong input for grades or format!"<<endl;
    }
    return 0;
}
