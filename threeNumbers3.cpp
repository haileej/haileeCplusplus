//
//  PIC 10A Homework 3, threeNumbers.cpp
//  Author: Hailee Julius
//  Date: 4/30/23.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    //asking to enter integers:
    cout<<"Please enter three different integers: ";
    
    //assinging the variables as integers:
    int integer_one, integer_two, integer_three;
    
    //retiriving the input:
    cin>> integer_one >> integer_two>> integer_three;
    
    int sum = integer_one + integer_two + integer_three;
    
    while(cin.fail()|| integer_one == integer_two || integer_two == integer_three ||integer_one == integer_three || sum != 100){
        //first testing whether integers were actually inputted by the user
        //cin. fail is true when the input for any of the variables is not an integer
        while(cin.fail()) {
            
            //
            cout<< "Fail to enter three integers. Please enter three different integers: ";
            
            //this resets the value of cin.fail, otherwise it won't re-evaluate itself and will perpeutuable be false:
            cin.clear();
            
            //this is ignoring anything left in the buffer:
            cin.ignore(1000, '\n');
            
            //re-recieving the inputted integers
            cin >> integer_one >>integer_two>> integer_three;
            sum = integer_one + integer_two + integer_three;
            if(sum == 100)
                break;
            
        }
        
        
        
        //now testing whether any inputted integers were repeated
        while(integer_one == integer_two || integer_two == integer_three ||integer_one == integer_three){
            
            //this is breaking the loop and sending us back to the cin failure loop because we need the specific error message in it if non integers are entered:
            if(cin.fail() == true)
                break;
            
            //ignoring anything left in buffer again, in the case that numbers were repeated:
            cin.ignore(10000, '\n');
            
            //asking for new integers
            cout<<"Please enter three different integers: ";
            
            //recieving the new integers
            cin>>integer_one >> integer_two>> integer_three;
            if(cin.fail() == true)
                break;
            sum = integer_one + integer_two + integer_three;
            if(sum == 100){
                break;
            }
        }
        
        
        //testing whether the numbers add up to 100
        int sum = integer_one + integer_two + integer_three;
        while(sum != 100){
            
            //this is breaking the loop and sending us back to the cin failure loop because we need the specific error message in it if non integers are entered:
            if(cin.fail() == true)
                break;
            //ignoring anything left in buffer again, in the case that the integers don't add to 100
            cin.ignore(100000, '\n');
            
            //asking for new
            cout<<"Please enter three different integers: ";
            
            //receiving
            cin>>integer_one >>integer_two>> integer_three;
            sum = integer_one + integer_two + integer_three;
        }
    }
        
        
        //finally, now that we know the integers don't fail any of the criteria
        cout << "The three different integers are: " << integer_one<< " "<< integer_two<< " "<< integer_three<< endl;
    
        return 0;
        
    }
    
