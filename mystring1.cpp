//
//  PIC 10A Homework 1, mystring.cpp
//  Author: Hailee Julius
//
//  Date: 4/15/23.
//

#include <iostream>
#include<string>
using namespace std;

int main() {
    //telling user to write something
    cout<< "Type a long word: ";
    
    //getting the entire input as a string using getline
    string user_input;
    getline(cin, user_input);
    
    //getting the number of characters
    double number_of_characters;
    number_of_characters = user_input.length();
    cout<<"The length of your sentence is: "<<number_of_characters<<endl;
    
    // example input:+-*/%abc 123 10A
    //getting the first five characters
    string first_five_char;
    first_five_char = user_input.substr(0,5);
    cout<< "The first 5 characters of your word is: "<<first_five_char<<endl;
    
    //last 5 characters:
    string last_five_char;
    last_five_char = user_input.substr(number_of_characters-5,number_of_characters);
    cout<< "The last 5 characters of your word is: "<<last_five_char<<endl;
    
    //the word after deleting the last five characters
    //i think i might be able to do this two ways
    //first way:
    string phrase_minus_five;
    phrase_minus_five = user_input.substr(0,number_of_characters - 5);
    cout<<"The word after deleting the last 5 characters is: "<< phrase_minus_five<<endl;
    
  
    //second way:
    /*
     string dupe_of_input;
    dupe_of_input = user_input;
    dupe_of_input.erase(number_of_characters-5,number_of_characters);
    cout<<"The word after deleting the last 5 characters is: "<< dupe_of_input<<endl;
     */
    //yeah both worked
    return 0;
}
