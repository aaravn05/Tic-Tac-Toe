//tic tac toe


#include <iostream>
#include <ctime>

using namespace std;
//using pointers to work with the variables directly not copies of it, call by reference

 const char COMP = 'O';
 const char PLAYER = 'X';

int playerMovement(char board[3][3]){
int playerMove;
cout<<"Enter box number to place in: ";
cin>>playerMove;

return playerMove;
}


void placeMove(int playerMove, char board[3][3], char moveIcon){


if(playerMove<1 || playerMove>9)
    cout<<"ERROR";
else{
int row = (playerMove - 1) / 3;
int col = (playerMove - 1) % 3;
 board[row][col]=moveIcon;
}

}

bool checkBox(char board[3][3], int playerMove){

//input validation
if(playerMove < 1 || playerMove > 9)
{
    return false;
}


int row = (playerMove - 1) / 3;
int col = (playerMove - 1) % 3;
if(board[row][col]==' ')
{
    return true;
}
else 
{
    cout<<"choose a different box\n";
    return false;
    
}
    
}

void playerTurn(char board[3][3])
{ 
    
    
    int playerMove = playerMovement(board);

     while(!checkBox(board, playerMove))
    {
        playerMove = playerMovement(board);
    }

    placeMove(playerMove, board, PLAYER);


}






int computerMovement(){

    
int computerMove=(rand()%9)+1;
return computerMove;
}

void computerTurn(char board[3][3])
{
   
    int computerMove = computerMovement();

while(!checkBox(board,computerMove)){
 computerMove = computerMovement();

}

placeMove(computerMove, board, COMP);


}


void printBoard(char board[3][3]){


cout<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<"\n";

cout <<"__|___|__\n";
cout<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<"\n";

cout <<"__|___|__\n";
cout<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<"\n";


cout<<"\n";
}







//win states
bool checkTie(char board[3][3]){


    //check if any thing is empty
for(int i = 0; i<3; i++)
{
    for(int j=0; j<3; j++)
    {
            if(board[i][j] == ' ')
            {
                
                return false;
            }

    }
}

    cout<<"TIE!\n";
    return true;

}





 
bool checkWin(char board[3][3]){

    //wincons: 1 full row or column or diagonal left or right ie(1,5,9) or (3,5,7)
    //rows
    
    for(int i = 0; i<=2; i++)
    {
    if(board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0]!=' ')
    {
        if(board[i][0]==PLAYER)
        {   
            printBoard(board);
            cout<<"Player wins";
            return true;
        }
        else
        {
            printBoard(board);
            cout<<"Computer wins";
            return true;
        }
    }
}

    //column
    for(int i = 0; i<=2; i++){
    if(board[0][i]== board[1][i] && board[0][i]== board[2][i] && board[0][i]!=' ')
    {
        if(board[0][i]==PLAYER)
        {   
            printBoard(board);
            cout<<"Player wins";
            return true;
        }
        else
        {   
            printBoard(board);
            cout<<"Computer wins";
            return true;
        }
    }

   
}

//diagonals
 if(board[0][0]== board[1][1] && board[0][0]== board[2][2] && board[0][0]!=' ')
    {
        if(board[0][0]==PLAYER)
        {
            printBoard(board);
            cout<<"Player wins";
            return true;
        }
        else
        {   printBoard(board);
            cout<<"Computer wins";
            return true;
        }
    }
    else if(board[0][2]== board[1][1] && board[0][2]== board[2][0] && board[0][2]!=' ')
    {
        if(board[0][2]==PLAYER)
        {
            printBoard(board);
            cout<<"Player wins\n";
            return true;
        }
        else
        {
            printBoard(board);
            cout<<"Computer wins\n";
            return true;

        }
    }


    return false;
}

int main(){

srand(time(NULL));
char board[3][3]={{' ',' ',' '},
    {' ',' ',' '},
    {' ',' ',' '}};


while(true){

printBoard(board);

if(checkWin(board))
    {
        break;
    }

    if(checkTie(board))
    {
        break;
    }

playerTurn(board);





printBoard(board);

computerTurn(board);

if(checkWin(board))
    {
        break;
    }

    else if(checkTie(board))
{
    break;
}

printBoard(board);
}

    return 0;
}