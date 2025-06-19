//
//  PIC 10A Homework 1, digits.cpp
//  Author: Hailee Julius
//  Date: 4/15/23.
//

#include <iostream>
using namespace std;

int main() {
    int two_digit_input;
    cout<< "Input a two-digit number (10 - 99): ";
    cin >> two_digit_input;
    
    //getting the ones digit:
    double remainder = two_digit_input % 10;
    cout <<"The ones-digit is "<< remainder<< "."<<endl;
    
    //getting the tens digit:
    int tens_digit = two_digit_input/10;
    cout << "The tens-digit is "<<tens_digit <<"."<<endl;
    
    //division: ones/tens
    double ones = static_cast<double>(remainder);
    double quotient = ones/tens_digit;
    cout<< "The division of two digits is "<< quotient<<"."<< endl;
    
    //reversed number
    int reverse_number = (10 * remainder) + tens_digit;
    cout<< "The reversed number is "<<reverse_number<<"."<<endl;
    
    return 0;
}
