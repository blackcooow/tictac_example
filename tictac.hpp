//
//  tictac.hpp
//  tictac
//
//  Created by  on 14/07/2020.
//  Copyright © 2020 . All rights reserved.
//

#ifndef tictac_hpp
#define tictac_hpp
#include <stdio.h>
#include <stdlib.h>

#include <iostream>

class Tictac
{
private:
    char* mBoard;
    int mWidth;
    int mHeight;
    int mSize;

    
public:
    Tictac(int , int );
    ~Tictac();
    
    void SetBoard();
    int SetData(int id, int choice); // whos turn and where choice
    const void ShowBoard();
    
    int GameWin();
    
};

#endif /* tictac_hpp */
