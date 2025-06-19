//
//  PIC 10A Homework 2, RankString.cpp
//  Author: Hailee Julius
//  Date: 4/20/23.
//
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    //telling use to write three strings:
    cout<< "Please enter three strings:"<<endl;
    string sen_one, sen_two, sen_three;
    
    //retrieving the phrases from user
    getline(cin,sen_one);
    getline(cin,sen_two);
    getline(cin,sen_three);
    
    cout<<"Descending dictionary order:"<<endl;
    //now comparing the strings
    //keeping in mind: 1 < 2 < 3... A < B < C ... a < b < c ...
    if (sen_one >= sen_two && sen_two >= sen_three){
        cout<<sen_one<<"\n"<<sen_two<<"\n"<<sen_three<<"\n";
    }
    else if(sen_three >= sen_one && sen_one>=sen_two){
        cout<<sen_three<<"\n"<<sen_one<<"\n"<<sen_two<<"\n";
    }
    else if(sen_one >= sen_three && sen_three>= sen_two){
        cout<<sen_one<<"\n"<<sen_three<<"\n"<<sen_two<<"\n";
    }
    else if(sen_three >= sen_two && sen_two>=sen_one){
        cout<<sen_three<<"\n"<<sen_two<<"\n"<<sen_one<<"\n";
    }
    else if(sen_two >= sen_one && sen_one>=sen_three){
        cout<<sen_two<<"\n"<<sen_one<<"\n"<<sen_three<<"\n";
    }
    else if(sen_two >= sen_three && sen_three>=sen_one){
        cout<<sen_two<<"\n"<<sen_three<<"\n"<<sen_one<<"\n";
    }
    return 0;
}
