//
//  main.cpp
//  tictac
//
//  Created by on 14/07/2020.
//  Copyright © 2020 . All rights reserved.
//

#include <random>

#include "tictac.hpp"


int main(int argc, const char * argv[]) {
    srand((unsigned)(time)(NULL));
    Tictac game(3, 3);
    game.SetBoard();
    game.ShowBoard();

    int id = 0;
    
  
    bool bStatus = true;
    int counter = 0;
    int choice;
    int check;

    
    while(bStatus)
    {
        counter ++;
    
        if(id %2 == 0)
        {
            std::cin>>choice;
            std::cout<<std::endl;
            check = game.SetData(id%2, choice);
            if(check == -1)
            {
                counter--;
                id --;
            }
        }
        else
        {
            int randomNumber = random()%9;
            randomNumber ++;
            
            check = game.SetData(id%2, randomNumber);
            if(check == -1)
            {
                counter--;
                id --;
            }
        }
        if(counter == 9)
        {
            bStatus = false;
        }
        game.ShowBoard();
        int b;
        
        b = game.GameWin();
        if (b == 1)
        {
            if(id %2 == 0)
                printf("USER WIN");
            else
                printf("COMPUTER WIN");
            
            bStatus = false;
        }
        id ++;
    }

    
}
