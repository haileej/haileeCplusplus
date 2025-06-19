//
//  PIC 10A Homework 3, randomWalk.cpp
//  Author: Hailee Julius
//  Date: 4/30/23.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int main() {
    
    int x_coordinate = 0;
    int y_coordinate = 0;
    
    //make sure the rand() gives a different value each time it runs:
    srand(static_cast<int>(time(nullptr)));
    
    //while the robot is in the 10x10 area
    while(-4 <= x_coordinate && x_coordinate <= 4 && -4 <= y_coordinate && y_coordinate <= 4){
        
        //random number between 0 and 1 to decide whether the x or y coordinate will be changing
        int x_or_y = 0 + rand() % (1 - 0 +1); //0 is x, 1 is y
        
        //if the x value is changing
        if(x_or_y == 0){
            
            //random value to decide whether it will move left or right
            int up_or_down_x = 0 + rand() % (1 - 0 +1); //0 is left, 1 is right
            if(up_or_down_x == 0){
                //if it is zero, move to the left one space
                x_coordinate = x_coordinate - 1;
                cout<<setw(10)<<left<<"Left" << "("<< x_coordinate <<"," << y_coordinate<< ")" << endl;
                
            }
            else{
                //otherwise (if it is 1) move to the right one space
                x_coordinate++;
                cout<< setw(10)<<left<<"Right" << "("<< x_coordinate <<"," << y_coordinate<< ")" << endl;
            }
            
        }
        else //else it is the y coordinate that changes
        {
            //random value to decide whether it moves up or down
            int up_or_down_y = 0 + rand() % (1 - 0 +1); //0 is down, 1 is up
            if(up_or_down_y == 0)
            {
                //it moves down
                y_coordinate = y_coordinate -1;
                cout<<setw(10)<<left<< "Down" << "("<< x_coordinate <<"," << y_coordinate<< ")" << endl;
            }
            else
            {
                //it moves up
                y_coordinate++;
                cout<< setw(10)<< left<<"Up" << "("<< x_coordinate <<"," << y_coordinate<< ")" << endl;
            } }
        //need to break the loop if it goes back to the origin
        if(x_coordinate ==0 && y_coordinate==0)
            break;
        }
    //need to say again that it is out of the loop because it went to the origin:
    if(x_coordinate ==0 && y_coordinate==0){
        cout<< "Back to the origin!"<<endl;}
    else{
        //otherwise, the other reason it when out of the loop is because it hit a boundary
        cout<< "Hit the boundary!" << endl;}
    
    return 0;
}
