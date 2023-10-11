//
// Homework 6 PIC10A
// Hailee Julius
// UID: 605533815
// Created: 5/28/2023
//


#include<string>
#include<iostream>
using namespace std;
int count_space(const string & s)
{
    int count = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == ' '){
            count++;
        }
    }
    return count;
}

int main()
{
    string s;
    cout << "Please enter a sentence:" << endl;
    getline(cin, s);
cout << "The sentence \"" << s << "\" contains " << count_space(s) << " spaces." << endl;
return 0;
}
