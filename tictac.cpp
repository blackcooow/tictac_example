//
//  tictac.cpp
//  tictac
//
//  Created by  on 14/07/2020.
//  Copyright © 2020 . All rights reserved.
//

#include "tictac.hpp"




Tictac::Tictac(int nHeight, int nWidth ) : mHeight(nHeight), mWidth(nWidth)
{
    
}

Tictac::~Tictac()
{
    free(mBoard);
}

void Tictac::SetBoard()
{
    mSize = mHeight * mWidth;
    mBoard = (char *)malloc(mSize + 1);
    
    for(int i = 0; i< mHeight * mWidth; i++)
    {
        mBoard[i] = '0';
    }
    mBoard[mHeight*mWidth] ='\0';
}

const void Tictac::ShowBoard()
{
    for(int i=0;i<mHeight*mWidth;i++)
    {
        std::cout<<mBoard[i]<<" ";
        if(i%mHeight == mWidth-1)
        {
            std::cout<<std::endl;
        }
    }
}

int Tictac::SetData(int id, int choice)
{
    if(choice > mSize || choice < 1)
    {
        printf("choose other number\n");
        return -1;
    }
    else if ( mBoard[choice-1] != '0' )
    {
        printf("choose other number\n");
        return -1;
    }
    
    if( id % 2 == 0 ) // my turn
    {
        mBoard[choice-1] = 'M';
    }
    else // computer turn
    {
        mBoard[choice-1] = 'C';
    }
    return 0;
}

int Tictac::GameWin()
{
    
    if (mBoard[0] == mBoard[1] && mBoard[2] == mBoard[2] && mBoard[0] != '0')
        return 1;
    else if (mBoard[3] == mBoard[4] && mBoard[4] == mBoard[5] && mBoard[3] != '0')
        return 1;
    else if (mBoard[6] == mBoard[7] && mBoard[7] == mBoard[8] && mBoard[6] != '0')
        return 1;
    else if (mBoard[0] == mBoard[3] && mBoard[3] == mBoard[6] && mBoard[0] != '0')
        return 1;
    else if (mBoard[1] == mBoard[4] && mBoard[4] == mBoard[7] && mBoard[1] != '0')
        return 1;
    else if (mBoard[2] == mBoard[5] && mBoard[5] == mBoard[8] && mBoard[2] != '0')
        return 1;
    else if (mBoard[0] == mBoard[4] && mBoard[4] == mBoard[8] && mBoard[0] != '0')
        return 1;
    else if (mBoard[2] == mBoard[4] && mBoard[4] == mBoard[6] && mBoard[2] != '0')
        return 1;
    else
        return -1;
}
