//
//  Player.cpp
//  Homework 7, PIC10A
//
//  Created by Hailee Julius on 6/5/23.
//

#include "Player.h"

//still don't use namespace std

//setter, not sure why we need this one if both player initializations in the provided int mains use the constructor below this one
Player::Player(){
    //this just creates a generic player with zero health, wins, and remaining battles
    name = "MyPlayer";
    health = 0;
    n_battles = 0;
    n_wins = 0;
}



//constructor that will be used to initialize the players
Player::Player(std::string myname, int myhealth, int mybattles){
    name = myname;
    health = myhealth;
    n_battles = mybattles;
}




//display function
void Player::display(){
    //we can use default variables
    std::cout<< "Player name: "<< name << std::endl;
    std::cout<< "Remaining health: "<< health << std::endl;
    std::cout<< "Remaining battle: "<< n_battles <<std::endl;
}




//game function, will contain battle function
bool Player::game(Player& enemy){
    //start the battle number at 1 for the big astrics line
        //we will use this to increment a loop of battles
    int current_battle_number = 1;
    
    //variable for the number of total battles we need to do
        //we will compare current_battle_number with this to know when the loop ends
    int initial_battles = n_battles;
    
    //introducing variables to count the number of wins for human and computer respectively
    //have to make them outside the loop so we can call them later outside of it
    int h_count = 0;
    int c_count = 0;
    
    //for loop because we know how many times we want the loop to run already. It will be given in main
    for(current_battle_number = 1; current_battle_number <= initial_battles; current_battle_number++){
        //for each batter we print out this printing statement
        //current_battle number starts at 1 and increments
        //initial_battles stays the same
        std::cout<< "********************** Current Battle Status: " <<current_battle_number <<"/"<<initial_battles<< " **********************"<< std::endl;
        
        //from our battle function, we know who wins based on the value of this boolean
        //1 if player won, 0 if enemy won
        bool player_win = Player::battle(enemy);
        
        //if player won, increment the number of player wins and print that they won
        if(player_win == 1){
            std::cout<< name <<" wins this battle!"<<std::endl; //still need to add more to these i think
            h_count++;
        }
        else{ //if enemy won, incrememnt the number of computer wins and print that enemy won
            std::cout<< enemy.name << " wins this battle!"<<std::endl;
            c_count++;
        }
        std::cout<<std::endl;
        
    }
    //after all battles have been played, compare the number of wins for human and computer respectively using an if-else statement
    std::cout<<"********************** The final winner is: ";
    if(c_count >= h_count){
        std::cout<<enemy.name<<". **********************"<<std::endl;
        return 0; //boolean for game function is false if enemy won
      
    }
    else {//(c_count < h_count){
        std::cout<<name<<". **********************"<<std::endl;
        return 1;//boolean for game function is true if player won
    }
    
}




//battle function innards
bool Player::battle(Player& enemy){
    
    //initial printing statement including the current health of the player
    //initial health is given in main
    std::cout<< "---- Battle starts ----"<< std::endl;
    std::cout<< "You have "<< health <<" health points left."<< std::endl;
    std::cout<< "How many health points do you want to use? ";
    
    //taking in the user input for how many points they want to use
    //will be an integer I think
    //gonna introduce a new integer to take this value
    int points_using;
    std::cin>>points_using;
    
    
    //printing statement stating how many points the user chose to use
    std::cout << name <<" chose to use "<<points_using<< " health points."<<std::endl;
    
    //updating the health value, subtracting the ponts the user chose to use
    health = health - points_using;
    
    //new integer for how many points the computer chooses to use
    int enemy_using;
    
    //decresing the number of remaining battles by one
    --n_battles;
    
    //if there are no more remaing battles, the computer uses all of its remaining health, otherwise it chooses a random number between 0 and its remaining health value
    if(n_battles == 0){
        enemy_using = enemy.health;
    }
    else{
        enemy_using = 0 + rand() % (enemy.health - 0 + 1);
    }
    
    //printing statement for how many health points the enemy chose to use
    std::cout << enemy.name <<" chose to use "<< enemy_using << " health points."<<std::endl;
     
    
    

        
    //need to do something to change the remaining number of points the computer has
    enemy.health = enemy.health - enemy_using;
    
    //if statement for if the number of health points the player chose to use is larger than the number of health points the comp chose to use, then the player wins and vice versa
    if(enemy_using >= points_using){
            return 0; // returns fals if enemy wins
        }
    else{  //}(enemy_using < points_using)
            n_wins++;
            //std::cout<<n_wins<<std::endl;
            return 1; //returns true if player wins
        }
    
    
    
    
    


}
