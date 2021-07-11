#include <iostream>
void drawboard(char board[8][8])
{
    for(int i = 0; i < 8; ++i)
    {
        for(int j = 0; j < 8; ++j)
        {
            if(j % 8 == 0)
            {
                std::cout << std::endl;
            }
            std::cout << board[j][i]/* << '(' << j << ',' << i << ')'*/;
        }
    }
    std::cout << std::endl;
}
bool isPossible(short int x, short int y, short int n)
{
    // < 0 || > 7
    //n[0] = (2, -1)
    //n[1] = (1, -2)
    //n[2] = (-1, -2)
    //n[3] = (-2, -1)
    //n[4] = (-2, 1)
    //n[5] = (-1, 2)
    //n[6] = (1, 2)
    //n[7] = (2, 1)
    if(x < 0 || x > 7 || y < 0 || y > 7)
    {
        return false;
    }
    switch (n)
    {
    case 0:
        if((x + 2) > 7 || (y - 1) < 0)
        {
            return false;
        }
        else
        {
            return true;
        }
        break;
    case 1:
        if((x + 1) > 7 || (y - 2) < 0)
        {
            return false;
        }
        else
        {
            return true;
        }
        break;
    case 2:
        if((x - 1) < 0 || (y - 2) < 0)
        {
            return false;
        }
        else
        {
            return true;
        }
        break;
    case 3:
        if((x - 2) < 0 || (y - 1) < 0)
        {
            return false;
        }
        else
        {
            return true;
        }
        break;
    case 4:
        if((x - 2) < 0 || (y + 1) > 7)
        {
            return false;
        }
        else
        {
            return true;
        }
        break;
    case 5:
        if((x - 1) < 0 || (y + 2) > 7)
        {
            return false;
        }
        else
        {
            return true;
        }
        break;
    case 6:
        if((x + 1) > 7 || (y + 2) > 7)
        {
            return false;
        }
        else
        {
            return true;
        }
        break;
    case 7:
        if((x + 2) > 7 || (y + 1) > 7)
        {
            return false;
        }
        else
        {
            return true;
        }
        break;
    }
}
int main()
{
    short int xCoord;
    short int yCoord;
    unsigned short int movChs;
    char board[8][8];
    std::cout << "X coordinate: ";
    std::cin >> xCoord;
    if(xCoord < 0 || xCoord > 7)
    {
        std::cout << "Invalid value passed, please, re-run." << std::endl;
        return -1;
    }
    std::cout << "Y coordinate: ";
    std::cin >> yCoord;
    if(yCoord < 0 || yCoord > 7)
    {
        std::cout << "Invalid value passed, please, re-run." << std::endl;
        return -1;
    }
    while(1)
    {
        for(int i = 0; i < 8; ++i)   
        {
            for(int j = 0; j < 8; ++j)
            {
                board[i][j] = '#';
            }
        }
        board[xCoord][yCoord] = 'K';
        for(int i = 0; i < 8; ++i)
        {
            if(isPossible(xCoord, yCoord, i))
            {
                // < 0 || > 7
                //n[0] = (2, -1)
                //n[1] = (1, -2)
                //n[2] = (-1, -2)
                //n[3] = (-2, -1)
                //n[4] = (-2, 1)
                //n[5] = (-1, 2)
                //n[6] = (1, 2)
                //n[7] = (2, 1)
                switch (i)
                {
                    case 0:
                        board[xCoord + 2][yCoord - 1] = '0';
                        break;
                    case 1:
                        board[xCoord + 1][yCoord - 2] = '1';
                        break;
                    case 2:
                        board[xCoord - 1][yCoord - 2] = '2';
                        break;
                    case 3:
                        board[xCoord - 2][yCoord - 1] = '3';
                        break;
                    case 4:
                        board[xCoord - 2][yCoord + 1] = '4';
                        break;
                    case 5:
                        board[xCoord - 1][yCoord + 2] = '5';
                        break;
                    case 6:
                        board[xCoord + 1][yCoord + 2] = '6';
                        break;
                    case 7:
                        board[xCoord + 2][yCoord + 1] = '7';
                        break;
                }            
            }
        }
        drawboard(board);
        std::cout << "Type the movement number: >";
        std::cin >> movChs;
        if(movChs > 7 || movChs < 0)
        {
            std::cout << "Invalid value passed, please, re-run." << std::endl;
            return -1;
        }
        switch (movChs)
                {
                    case 0:
                        if(isPossible(xCoord, yCoord, movChs))
                        {
                            xCoord += 2;
                            yCoord -= 1;
                        }
                        break;
                    case 1:
                        if(isPossible(xCoord, yCoord, movChs))
                        {
                            xCoord += 1;
                            yCoord -= 2;
                        }
                        break;
                    case 2:
                        if(isPossible(xCoord, yCoord, movChs))
                        {
                            xCoord -= 1;
                            yCoord -= 2;
                        }
                        break;
                    case 3:
                        if(isPossible(xCoord, yCoord, movChs))
                        {
                            xCoord -= 2;
                            yCoord -= 1;
                        }
                        break;
                    case 4:
                        if(isPossible(xCoord, yCoord, movChs))
                        {
                            xCoord -= 2;
                            yCoord += 1;
                        }
                        break;
                    case 5:
                        if(isPossible(xCoord, yCoord, movChs))
                        {
                            xCoord -= 1;
                            yCoord += 2;
                        }
                        break;
                    case 6:            
                        if(isPossible(xCoord, yCoord, movChs))
                        {
                            xCoord += 1;
                            yCoord += 2;
                        }
                        break;
                    case 7:
                        if(isPossible(xCoord, yCoord, movChs))
                        {
                            xCoord += 2;
                            yCoord += 1;
                        }
                        break;
                }
    }
    /*for(int i = 0; i < 8; ++i)
    {
        if(isPossible(xCoord, yCoord, i))
        {
            std::cout << "The " << i << "th movement is possible." << std::endl;
        }
        else
        {
            std::cout << "The " << i << "th movement is NOT possible." << std::endl;
        }
    }*/
}