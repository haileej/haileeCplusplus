//
//  average.cpp
//  PIC10A Homework 5
//  Created by Hailee Julius on 5/20/23.
//

#include <iostream>
#include <iomanip>
#include <vector>
// #include<algorithm> // it is not recommended to use std::sort or any other sorting functions to complete this homework, but if that is the only way you can think of, you are allowed to uncomment this line and use 'sort' in your code.

using namespace std;

void read_grades(vector<double>& dummy_quiz, double& dummy_project, double& dummy_exam){
    cout << "Please enter quiz grades 0-100 (There are six): ";
    for (int i = 0; i < 6; i++)
    { cin >> dummy_quiz[i];}
    
    cout << "Please enter project grade 0-100 (There is one): ";
    cin >> dummy_project;
    
    cout<<"Please enter exam grade 0-100 (There is one): ";
    cin >> dummy_exam;
}

double compute_average(vector<double>& dummy_quiz, double& dummy_project, double& dummy_exam){
    //first I am going to find the smallest value of the quizzes and its index number:
    double smallest = dummy_quiz[0];
    int smallest_index = 0;
    for (int i = 0; i < dummy_quiz.size(); i++)
    {
        if(dummy_quiz[i] < smallest)
        {
            smallest = dummy_quiz[i];
            smallest_index = i;
        }
    }
    //now i am goig to find the second smallest of the quizzes and its index number:
    double second_smallest = dummy_quiz[0];
    int second_smallest_index = 0;
    for (int i = 0; i < dummy_quiz.size(); i++)
    {
        if(dummy_quiz[i] == dummy_quiz[smallest_index] && smallest_index == 0){
            second_smallest=dummy_quiz[1];
            second_smallest_index = 1;
        }
            
        if(dummy_quiz[i] == dummy_quiz[smallest_index] && smallest_index == i)
        {}
        else if(smallest <= dummy_quiz[i] && dummy_quiz[i] <second_smallest)
        {
            second_smallest = dummy_quiz[i];
            second_smallest_index = i;
        }
    }
    /*  I used this to make sure my smallest and second smallest were actually correct
    cout<< "the index of the smallest is "<<smallest_index<<endl;
    cout<<"the smallest is "<<smallest<<endl;
    cout<< "the index of the second-smallest is "<<second_smallest_index<<endl;
    cout<<"the second smallest is "<< second_smallest<<endl;
    */
    
    //printing the quizzes and 'Dropped' next to the two that are dropped:
    for(int i = 0; i < dummy_quiz.size(); i++){
        cout << setw(8) << right << "Quiz " << (i+1) << setw(8) << dummy_quiz[i];
        if(i == smallest_index || i ==second_smallest_index){
            cout<<" (Dropped)";
        }
        cout << endl;
    }
    
    //printing the project grade
    cout << setw(9) << right << "Project" << setw(8) << dummy_project << endl;
    
    //printing the exam grade
    cout << setw(9) << right << "Exam" << setw(8) << dummy_exam << endl;
    
    //now i have to actually calculate the two possible averages and say which one will be used, i.e. gives the greater overall grade
    double quiz_avg = 0;
    for(int i = 0; i < dummy_quiz.size(); i++)
    {
        if(i == smallest_index || i == second_smallest_index)
        {
        }
        else{
            quiz_avg = quiz_avg + dummy_quiz[i];
            //cout<<quiz_avg<<endl;
        }
    }
    quiz_avg = (quiz_avg/4);
    //cout<<"the quiz average is "<<quiz_avg<<endl;
    //scheme 1:
    double average_one;
    average_one = (quiz_avg * .3)+ (dummy_project* .25)+ (dummy_exam*.45);
    
    //scheme 2:
    double average_two;
    average_two = (quiz_avg * .22)+ (dummy_project* .32)+ (dummy_exam*.46);
    
    //simple if-else for which scheme is higher
    double average;
    if(average_one >= average_two)
    {
        cout<< "Scheme I is used."<<endl;
        average = average_one;
    }
    else{average = average_two;
        cout<<"Scheme II is used."<<endl;
    }
    return average;
}
                       
                       
int main( ) {
    
    // declare containers for different grade items
    vector<double> quiz(6);
    double exam, project; // contains midterm and final
    
    // read grades from user
    read_grades(quiz, project, exam);
    
    // compute average based on the grading scheme
    // print items to the console, including dropped situation
    double average = compute_average(quiz, project, exam);
    
    // output average grade
    cout << "The average grade is " << average << "." << endl;
    
    return 0;
}
