//
//  menu.cpp
//  Created by Hailee Julius on 5/13/23.
//
// PIC 10A Homework 4
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;



//creating the foremost menu function
//i'm just going to make it for printing the menu
void displayMenu(int& times){
    cout<< "================== MENU "<<times<<" =================="<<endl;
    cout<<"1. Output the median"<<endl;
    cout<<"2. Get the next permutation"<<endl;
    cout<<"3. Sort in descending order"<<endl;
    cout<<"4. Simplify the numbers"<<endl;
    cout<<"Enter your choice (1 - 4), Q to quit: ";
    
}

int median(int a, int b, int c)
{
    //initialize our returning variable:
    int median;
    
    //if statements when they are all different values is easy, just find the one that isn't the greatest or the smallest
    if( (a < b && b < c) || (c < b && b < a) || (a == b) || (b == c))
    {median = b;}
    
    else if((c < a && a < b) || (b < a && a < c) || (a ==c) )
    {median = a;}
    
    else{median = c;}
    
    return median; //we want this function to return us the new value of median
}


void mySort(int& a, int& b, int& c)
{
    //place holder variables so that our a, b, and c's don't get messed up
    int x = a;
    int y = b;
    int z = c;
    
    if((a < b && b < c) || (a == b && b < c) || (c == b && a < c) || (a == b && b == c))
    {
        a = z; //a is now the initial c value
        b = y; //b is now the initial b value
        c = x; //c is now the initial a vlaue
    }
    else if((b < a && a < c) || (b == a && a < c) || ( c == a && b < c) )
    {
        a = z; //a is now the initial c value
        b = x; //b is now the initial a value
        c = y; //c is now the initial b vlaue
    }
    else if((b < c && c < a) || (b == c && c < a) || (a == c && c > b))
    {
        a = x; //a is now the initial a value
        b = z; //b is now the initial c value
        c = y; //c is now the initial b value
    }
    else if((c < b && b < a) || (c == b && b < a) || (a == b && b > c))
    {
        //nothing should happen because it's already in descending order
    }
    else if((a < c && c < b) || (a == c && c < b) || (b == c && c < a))
    {
        a = y; //a is now the initial b value
        b = z; //b is now the initial c value
        c = x; //c is now the initial a value
    }
    else if((c < a && a < b) || (c == a && a < b) || (b == a && a > c))
    {
        a = y; //a is now the initial b value
        b = x; //b is now the initial a value
        c = z; //c is now the initial c value
    }
}

void myPermutation(int& a, int& b, int& c)
{
    //need place holder variables so that our a, b, and c's don't get messed up
    int x = a;
    int y = b;
    int z = c;
    a = z; //a is the initial c
    b = x; //b is the inital a
    c = y; //c is the initial b
    cout<<"After one permutation: "<<a<< " "<<b<<" "<<c<<endl;
}

void mySimplify(int& a, int& b, int& c)
{
    int factor; //first we're gonna find the gcf of a and b:
    int remainder;
    if(a >= b)
    {
        remainder = b; //need this so that the first division is by b
        int dividend ;
        factor = a; //the first number being divided by something is a
        while(remainder != 0)
        {
            dividend = factor;
            factor = remainder; //need this so that the division factor is changing into the previous remainder
            remainder = dividend % factor; //need to take the mod until it is zero (the remainder from that calculation is the greatest common multiple of a and b).
        }
    }
    else //(a < b) //now, b needs to be divided by the factor
    {
        remainder = a; //need this so that the first division is by a
        int dividend;
        factor = b; //the first number being divided by something is b
        while(remainder != 0)
        {
            dividend = factor;
            factor = remainder; //need this so that the division factor is changing into the previous remainder
            remainder = dividend % factor; //need to take the mod until it is zero (the remainder from that calculation is the greatest common multiple of a and b).
        }
    }
    
    //next we need to find the greatest common factor between c and the factor that we found
    int remainder_new;
    int factor_new;
    if(c >= factor)
    {
        remainder_new = factor; //need this so that the first division is by factor
        int dividend_new ;
        factor_new = c; //the first number being divided by something is c
        while(remainder_new != 0)
        {
            dividend_new = factor_new;
            factor_new = remainder_new; //need this so that the division factor is changing into the previous remainder
            remainder_new = dividend_new % factor_new; //need to take the mod until it is zero (the remainder from that calculation is the greatest common multiple of a and b).
        }
    }
    else //(c <factor) ////now, factor needs to be divided by something //c = 180, factor = 18
    {
        remainder_new = c; //need this so that the first division is by c
        int dividend_new;
        factor_new = factor; //the first number being divided by something is factor
        while(remainder_new != 0)
        {
            dividend_new = factor_new;
            factor_new = remainder_new;
            remainder_new = dividend_new % factor_new;
        }
    }
    //have to divide the previous integers by the gcf of the three
    a = a /factor_new;
    b = b /factor_new;
    c = c / factor_new;
}



int main() {
    
    //first thing printed is the asking for integers part:
    
    bool correct_integers = 1; //this will make the loop continue, and we will change it to false once we recieve the correct positive integers so that the loop stops then too
    int integer_one = 0, integer_two = 0, integer_three = 0; //initializing integer variables
    
    while(correct_integers) //while correct_integers hasn't changed from 1
    {
        //ask for integers:
        cout<<"Enter your three positive integers: ";
        cin >>integer_one>>integer_two>>integer_three; //recieve integers
        
        //if any are less than or equal to 0, don't change the boolean and have the loop run again
        if(integer_one<= 0 || integer_two<=0 ||integer_three<=0)
            {cout<<"Error: non-positive inputs received."<<endl;
                cout<<endl;
            }//if any are less than or equal to zero, the if statement says so and then the  loop continues to ask for values
        else{
            //otherwise, the integers are correct and the loop can be terminated by changing the boolean to false
            correct_integers = 0;
            }
    }
    
    
    //clearing the failure flag in case it was changed during the recieving of the integers (probably not based off of the homework instructions, but i'll still keep the cin.clear)
    cin.clear();
    
    //times_main will keep track of which menu number we are on
    int times_main = 1;
    
    //while we are recieving integers (not Q), and the failure is false:
    while(!cin.fail()){
        
        //run the displayMenu function that prints out the menu
        displayMenu(times_main);
        
        //initialize and recieve your_choice (1-4)
        int your_choice;
        cin >>your_choice;
        
        //increase the number of times the meu has been run
        times_main++;
        
        //need different if statements for 1-4
        //run the respective function and then print the new integers
        if(your_choice==1) //this is median
        {
            cout<<"The median among the three is: "<<median(integer_one, integer_two, integer_three)<<endl;
            cout<<endl;
        }
        if(your_choice == 2)//permutation
        {
            myPermutation(integer_one, integer_two, integer_three);
            cout<<endl;
        }
        if(your_choice ==3)//sorting
        {
            mySort(integer_one, integer_two, integer_three);
            cout<<"After sorting: "<<integer_one<<" "<<integer_two<<" "<<integer_three<<endl;
            cout<<endl;
        }
        if(your_choice ==4)//gcf division
        {
            mySimplify(integer_one, integer_two, integer_three);
            cout<<"After simplify: "<<integer_one<< " "<< integer_two<< " "<<integer_three<<endl;
            cout<<endl;
        }
        
    }
    
    //when Q is entered, "Exit the menu" is printed
    cout<<"Exit the menu"<<endl;
    return 0;
}
