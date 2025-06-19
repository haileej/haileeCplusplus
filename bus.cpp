//
//  bus.cpp
//  Created by Hailee Julius on 5/28/23.
//  Homework 6 PIC10A
//
//

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class bus
{
    public:
        bus(int n);
        void board(string name);
        void drive(double m);
        void show_information() const;
    private:
        int capacity;
        double mileage;
        vector<string> passengers;
};

bus::bus(int _capacity){
    capacity = _capacity;
    mileage = 0;
    vector<string> passengers;
}

void bus::board(string name){
    if(passengers.size() != capacity){
        passengers.push_back(name);
        
    }
    else if(passengers.size() >= capacity){
        cout<< "The bus is full!" <<endl;
    }
}

void bus::drive(double m){
    mileage+= m;
}

void bus::show_information() const{
    cout<< "The bus has driven " << mileage<< " miles. ";
    cout<< "The current passengers are:"<<endl;
    for(int i = 0; i < passengers.size(); ++i){
        cout<< passengers[i]<<endl;
    }
}

/*
put your code here!
do not modify other exisiting code
*/
int main()
{
    bus RedLine(4);
    RedLine.board("Tim");
    RedLine.board("Jim");
    RedLine.board("Kim");
    RedLine.drive(1.5);
    RedLine.show_information();
    RedLine.board("Pam");
    RedLine.board("Cam");
    RedLine.board("Sam");
    RedLine.drive(0.15);
    RedLine.show_information();
    
    return 0;
}
