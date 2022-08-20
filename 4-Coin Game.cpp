//Huda Rauf,CS-182014,BS-CS-6B

#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

char board[3][3]; //took a 3x3 matrix bcos we needed 9 vals on board.
int choice=0;
int loc,pos= 0;
int row, column = 0;
char turn = 'R'; //default player is red queen
int space = 0 ;
int redCoins = 4; //for my red queen
int blueCoins = 4; //for my blue queen
void CBoard();
void createBoard();
void playerTurn();
int QueenMovement();


int main()
{
	createBoard();
	CBoard();
	playerTurn();
	   	
	return 0;
}

void playerTurn()
{
	//this loop will keep a check on how many spaces are left on board to be filled.
		while(space != 2)
	   	{
	   		space = 0;
			for (int i = 0; i < 3; i++)
			{
    		    for (int j = 0; j < 3; j++)
				{        
					if(board[i][j] == 'X')
					{		
							space++;
					}	
    	        
       			}
			}		
			cout<<"Space left ---> " << space<<endl;
			//for Red-Queens Turn
		   	if (turn == 'R')
			{
				cout<<"\nYour Turn Player-1[R]: ";
			}
			//for Blue Queens Turn
			else if(turn == 'B')
			{
				cout<<"\nYour Turn Player-2[B]: ";
			}
	
	    	cin>> choice;
	        //this switch case will keep a check that which row and col players are selecting
	   		switch(choice)
			{
	    	    case 1: row=0; column=0; 
				break;
	    	    case 2: row=0; column=1;
				break;
	        	case 3: row=0; column=2;
				break;
	        	case 4: row=1; column=0; 
				break;
	        	case 5: row=1; column=1; 
				break;
	        	case 6: row=1; column=2; 
				break;
	        	case 7: row=2; column=0; 
				break;	
       			case 8: row=2; column=1; 
				break;	
				case 9: row=2; column=2; 
				break;
				
        		default: 
				cout<<"\nInvalid Move" <<endl;
    		}
    
    		//this is for putting the values of red queen and blue queen on the board. like till 1-8 
    		if(turn == 'R' && board[row][column] == 'X')
			{ 
    		    board[row][column] = 'R';
    		    turn = 'B';
    		}
			else if(turn == 'B' && board[row][column] == 'X')
			{
    		    board[row][column] = 'B';
    		    turn = 'R';
    		}
    		
    		CBoard();
    	}
	//if the board is full this error will appear
	 if(space == 2)
	{
		cout <<"NO space on Board !!" << endl;
		QueenMovement();
	}
	
}


/*this function is actually going to do the movement for the queens. From moving from one location to another. 
and checking for the rules  discussed in class that when any of the Queen is going to be killed.s*/
int QueenMovement()
{
	//needed these vars bcos we had to do swapping with empty spaces.
	int locRow , locCol=0;
	int posRow , posCol=0;
	
	while(redCoins > 0 && blueCoins > 0)
	{
		if (turn == 'R')
		{
			cout<<"\nYour Turn Player-1[R]: -->> ";
		}
		else if(turn == 'B')
		{
			cout<<"\nYour Turn Player-2[B]: -->> ";
		}
		
		cout<<"enter your location : ";
		cin>>loc;
		cout <<"enter the swap location : ";
		cin >>pos;
		
		//these switch function will keep a check of the location and position that players will enter
		switch(loc)
		{
    	case 1: locRow=0; locCol=0; 
		break;
	    case 2: locRow=0; locCol=1; 
		break;
		case 3: locRow=0; locCol=2; 
		break;
		case 4: locRow=1; locCol=0; 
		break;
		case 5: locRow=1; locCol=1; 
		break;
	    case 6: locRow=1; locCol=2; 
		break;
	   	case 7: locRow=2; locCol=0; 
		break;	
      	case 8: locRow=2; locCol=1; 
		break;	
	    case 9: locRow=2; locCol=2; 
		break;
					
        default: 
		cout<<"\nInvalid location choice.." <<endl;
		}
		
	switch(pos)
	{
	case 1: posRow=0; posCol=0; 
	break;
    case 2: posRow=0; posCol=1;
	break;
	case 3: posRow=0; posCol=2; 
	break;
	case 4: posRow=1; posCol=0; 
	break;
	case 5: posRow=1; posCol=1; 
	break;
	case 6: posRow=1; posCol=2; 
	break;
    case 7: posRow=2; posCol=0; 
	break;	
  	case 8: posRow=2; posCol=1; 
	break;	
	case 9: posRow=2; posCol=2; 
	break;
					
   	default: 
	cout<<"\nInvalid position choice.." <<endl;
	}
	
	//the red queen can only move up , down and to the 3 and 7.	
   	if(turn == 'R')
    {   
   	// loc 1 = right, down , X to 3 and 7
   	if(loc == 1)
   	{

   	// For moving Right
	if(loc == 1 && pos == 2 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X')
	{
	swap(board[locRow][locCol] , board[posRow][posCol]);
	turn ='B';
	}
	
	//down
	else if(loc == 1 && pos == 4 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X')
	{
	swap(board[locRow][locCol] , board[posRow][posCol]);
	turn ='B';
	}
	
	// X to 3
	else if(loc == 1 && pos == 3 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X' && board[locRow][locCol+1] == 'B' )
	{
	//swap
	swap(board[locRow][locCol] , board[posRow][posCol]);
	// eliminate B
	board[locRow][locCol+1] = 'X';
	blueCoins--;
	turn ='B';
	}

	// X to 7
	else if(loc == 1 && pos == 7 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X' && board[locRow+1][locCol] == 'B' )
	{	
	//swap
	swap(board[locRow][locCol] , board[posRow][posCol]);
   // eliminate B
	board[locRow+1][locCol] = 'X';
	blueCoins--;
	turn ='B';
	}		
	}
			
  	// loc 2 = right, left, down , X to 8
	else if (loc == 2)
	{
	// Right
    if(loc == 2 && pos == 3 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X')
	{
	swap(board[locRow][locCol] , board[posRow][posCol]);
	turn ='B';
	}

	//left
	else if(loc == 2 && pos == 1 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X')
	{
    swap(board[locRow][locCol] , board[posRow][posCol]);
	turn ='B';
	}
	
	//down
    else if(loc == 2 && pos == 5 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X')
	{
	swap(board[locRow][locCol] , board[posRow][posCol]);
	turn ='B';
	}
			
	// X to 8
	else if(loc == 2 && pos == 8 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X' && board[locRow+1][locCol] == 'B' )
	{
	//swap
	swap(board[locRow][locCol] , board[posRow][posCol]);
    // eliminate B
	board[locRow+2][locCol] = 'X';
	blueCoins--;
	turn ='B';
	}	
	}

	// loc 3 = left , down , X to 1 and 9
	else if(loc == 3 )
	{
	
	//left
	if(loc == 3 && pos == 2 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X')
	{
	swap(board[locRow][locCol] , board[posRow][posCol]);
	turn ='B';
	}

	//down
	else if(loc == 3 && pos == 6 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X')
    {
	swap(board[locRow][locCol] , board[posRow][posCol]);
    turn ='B';
	}
	
	// X to 1
	else if(loc == 3 && pos == 1 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X' && board[locRow][locCol-1] == 'B' )
	{

	//swap
	swap(board[locRow][locCol] , board[posRow][posCol]);
	
	// eliminate B
	board[locRow][locCol-1] = 'X';
	blueCoins--;
	turn ='B';
	}
	}
	
	// loc 4 = up, down , right and X to 6
	else if(loc == 4)
	{
	// up
	if(loc == 4 && pos == 1 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X')
	{
	swap(board[locRow][locCol] , board[posRow][posCol]);
	turn ='B';
    }
	//down
	else if(loc == 4 && pos == 7 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X') 
   {
	swap(board[locRow][locCol] , board[posRow][posCol]);
	turn ='B';
	}
	//right
	else if(loc == 4 && pos == 5 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X')
	{
	swap(board[locRow][locCol] , board[posRow][posCol]);
	turn ='B';
	}
	
	// X to 6
	else if(loc == 4 && pos == 6 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X' && board[locRow][locCol+1] == 'B' )
	{
	//swap
	swap(board[locRow][locCol] , board[posRow][posCol]);
	// Blue Queen would be eliminated.
    board[locRow][locCol+1] = 'X';
	blueCoins--;
	turn ='B';
	}
	}
   
   // loc 5 = up, down , left , right
	else if(loc == 5)
	{
	// up
	if(loc == 5 && pos == 2 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X')
   {
	swap(board[locRow][locCol] , board[posRow][posCol]);
	turn ='B';
	}
	//down
	else if(loc == 5 && pos == 8 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X')
	{
	swap(board[locRow][locCol] , board[posRow][posCol]);
	turn ='B';
	}
	
	//left
	else if(loc == 5 && pos == 4 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X')
	{
	swap(board[locRow][locCol] , board[posRow][posCol]);
	turn ='B';
	}
	//right
	else if(loc == 5 && pos == 6 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X')
	{
	swap(board[locRow][locCol] , board[posRow][posCol]);
	turn ='B';
	}
	}

	// loc 6 = up, down , left  and X to 4
	else if(loc == 6)
	{
	// up
	if(loc == 6 && pos == 3 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X')
	{
		swap(board[locRow][locCol] , board[posRow][posCol]);
		turn ='B';
	}
	//down
	else if(loc == 6 && pos == 9 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X')
	{
	  swap(board[locRow][locCol] , board[posRow][posCol]);
      turn ='B';
    }
				
	//left
	else if(loc == 6 && pos == 5 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X')
	{
	swap(board[locRow][locCol] , board[posRow][posCol]);
	turn ='B';
	}

	// X to 4
	else if(loc == 6 && pos == 4 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X' && board[locRow][locCol-1] == 'B' )
	{
	//swap
	swap(board[locRow][locCol] , board[posRow][posCol]);
	// eliminate B
	board[locRow][locCol-1] = 'X';
	blueCoins--;
	turn ='B';
	}
	}
	//From loc 7 = up, right,and X to 1 and 9
	else if(loc == 7)
	{
	// up
	if(loc == 7 && pos == 4 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X')
	{
		swap(board[locRow][locCol] , board[posRow][posCol]);
    	turn ='B';
	}

	//right
	else if(loc == 7 && pos == 8 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X')
	{
		swap(board[locRow][locCol] , board[posRow][posCol]);
		turn ='B';
	}
	
	// X to 1
	else if(loc == 7 && pos == 1 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X' && board[locRow-1][locCol] == 'B' )
	{
	//swap
	swap(board[locRow][locCol] , board[posRow][posCol]);
	// eliminate B
	board[locRow-1][locCol] = 'X';
	blueCoins--;
	turn ='B';
	}

	// X to 9
	else if(loc == 7 && pos == 9 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X' && board[locRow][locCol+1] == 'B' )
	{
	//swap
    swap(board[locRow][locCol] , board[posRow][posCol]);
	// eliminate B
	board[locRow][locCol+1] = 'X';
	blueCoins--;
	turn ='B';
	}
	}
	// loc 8 = up, left,  right and X to 2
	else if(loc == 8)
   {
	// up
	if(loc == 8 && pos == 5 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X')
	{
	swap(board[locRow][locCol] , board[posRow][posCol]);
	turn ='B';
	}
	
	//left
	else if(loc == 8 && pos == 7 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X')
	{
	swap(board[locRow][locCol] , board[posRow][posCol]);
	turn ='B';
	}
    //right
	else if(loc == 8 && pos == 9 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X')
	{
	swap(board[locRow][locCol] , board[posRow][posCol]);
	turn ='B';
	}
				
	// X to 2
	else if(loc == 8 && pos == 2 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X' && board[locRow-1][locCol] == 'B' )
	{
		//swap
	swap(board[locRow][locCol] , board[posRow][posCol]);
	// eliminate B
	board[locRow-1][locCol] = 'X';
	blueCoins--;
	turn ='B';
	}
	}
    // loc 9 = up, left, and X to 3 and 7
	else if(loc == 9)
	{
	// up
	if(loc == 9 && pos == 6 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X')
	{
	swap(board[locRow][locCol] , board[posRow][posCol]);
	turn ='B';
	}
    //left
    else if(loc == 9 && pos == 8 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X')
	{
		swap(board[locRow][locCol] , board[posRow][posCol]);
		turn ='B';
	}

	// X to 3
	else if(loc == 9 && pos == 3 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X' && board[locRow-1][locCol] == 'B' )
	{
	//swap
    swap(board[locRow][locCol] , board[posRow][posCol]);
   // eliminate B
	board[locRow-1][locCol] = 'X';
	blueCoins--;
	turn ='B';
	}

	// X to 7
	else if(loc == 9 && pos == 7 && board[locRow][locCol] == 'R' && board[posRow][posCol]== 'X' && board[locRow][locCol-1] == 'B' )
	{
	//swap
	swap(board[locRow][locCol] , board[posRow][posCol]);
	// eliminate B
	board[locRow][locCol-1] = 'X';
	blueCoins--;
	turn ='B';
	}
	}	
	CBoard();
	
	}
	else if(turn == 'B')
	{
	 if(loc ==1)
	   {
		 // Right
		if(loc == 1 && pos == 2 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X')
		{
		  swap(board[locRow][locCol] , board[posRow][posCol]);
		  turn ='R';
		}
				//down
		else if(loc == 1 && pos == 4 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X')
		{
			swap(board[locRow][locCol] , board[posRow][posCol]);
			turn ='R';
		}
		
		// X to 3
		else if(loc == 1 && pos == 3 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X' && board[locRow][locCol+1] == 'R' )
		{
			//swap
			swap(board[locRow][locCol] , board[posRow][posCol]);
			// eliminate B
			board[locRow][locCol+1] = 'X';
			redCoins--;
			turn ='R';
		}
			// X to 7
		else if(loc == 1 && pos == 7 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X' && board[locRow+1][locCol] == 'R' )
		{	
		   //swap
			swap(board[locRow][locCol] , board[posRow][posCol]);
			// eliminate B
			board[locRow+1][locCol] = 'X';
		    redCoins--;
			turn ='R';
		}		
	}
			
	else if(loc ==2)
		{
			// Right
			if(loc == 2 && pos == 3 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X')
				{
					swap(board[locRow][locCol] , board[posRow][posCol]);
					turn ='B';
				}
				//left
			else if(loc == 2 && pos == 1 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X')
				{
					swap(board[locRow][locCol] , board[posRow][posCol]);
					turn ='B';
				}
				//down
			else if(loc == 2 && pos == 5 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X')
				{
					swap(board[locRow][locCol] , board[posRow][posCol]);
					turn ='B';
				}
			
				// X to 8
			else if(loc == 2 && pos == 8 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X' && board[locRow+1][locCol] == 'R' )
				{
					
					//swap
					swap(board[locRow][locCol] , board[posRow][posCol]);
					// eliminate B
					board[locRow+2][locCol] = 'X';
					redCoins--;
					turn ='R';
				}
			}
	else if(loc ==3)
			{
				//left
				if(loc == 3 && pos == 2 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X')
				{
					swap(board[locRow][locCol] , board[posRow][posCol]);
					turn ='R';
				}
				//down
				else if(loc == 3 && pos == 6 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X')
				{
					swap(board[locRow][locCol] , board[posRow][posCol]);
					turn ='R';
				}
				// X to 1
				else if(loc == 3 && pos == 1 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X' && board[locRow][locCol-1] == 'R' )
				{
					//swap
					swap(board[locRow][locCol] , board[posRow][posCol]);
					// eliminate B
					board[locRow][locCol-1] = 'X';
					redCoins--;
					turn ='R';
				}
			}	
	else if(loc == 4)
			{
				// up
				if(loc == 4 && pos == 1 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X')
				{
					swap(board[locRow][locCol] , board[posRow][posCol]);
					turn ='R';
				}
				//down
				else if(loc == 4 && pos == 7 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X')
				{
					swap(board[locRow][locCol] , board[posRow][posCol]);
					turn ='R';
				}
				//right
				else if(loc == 4 && pos == 5 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X')
				{
					swap(board[locRow][locCol] , board[posRow][posCol]);
					turn ='R';
				}
				// X to 6
				else if(loc == 4 && pos == 6 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X' && board[locRow][locCol+1] == 'R' )
				{
					//swap
					swap(board[locRow][locCol] , board[posRow][posCol]);
					// eliminate B
					board[locRow][locCol+1] = 'X';
					redCoins--;
					turn ='R';
				}
			}	
	else if(loc ==5)
			{
						// up
				if(loc == 5 && pos == 2 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X')
				{
					swap(board[locRow][locCol] , board[posRow][posCol]);
					turn ='R';
				}
				//down
				else if(loc == 5 && pos == 8 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X')
				{
					swap(board[locRow][locCol] , board[posRow][posCol]);
					turn ='R';
				}
				//left
			else if(loc == 5 && pos == 4 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X')
				{
					swap(board[locRow][locCol] , board[posRow][posCol]);
					turn ='R';
				}
				//right
			else if(loc == 5 && pos == 6 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X')
				{
					swap(board[locRow][locCol] , board[posRow][posCol]);
					turn ='R';
				}
			}	
	else if(loc ==6)
			{
				// up
				if(loc == 6 && pos == 3 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X')
				{
					swap(board[locRow][locCol] , board[posRow][posCol]);
					turn ='R';
				}
				//down
		    	else if(loc == 6 && pos == 9 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X')
				{
					swap(board[locRow][locCol] , board[posRow][posCol]);
					turn ='R';
				}
				//left
		    	else if(loc == 6 && pos == 5 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X')
				{
					swap(board[locRow][locCol] , board[posRow][posCol]);
					turn ='R';
				}
				// X to 4
				else if(loc == 6 && pos == 4 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X' && board[locRow][locCol-1] == 'R' )
				{
					//swap
					swap(board[locRow][locCol] , board[posRow][posCol]);
					// eliminate B
					board[locRow][locCol-1] = 'X';
					redCoins--;
					turn ='R';
				}
			}	
	else if(loc ==7)
			{
					// up
				if(loc == 7 && pos == 4 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X')
				{
					swap(board[locRow][locCol] , board[posRow][posCol]);
					turn ='R';
				}
				//right
				else if(loc == 7 && pos == 8 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X')
				{
					swap(board[locRow][locCol] , board[posRow][posCol]);
					turn ='R';
				}
				// X to 1
				else if(loc == 7 && pos == 1 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X' && board[locRow-1][locCol] == 'R' )
				{
					//swap
					swap(board[locRow][locCol] , board[posRow][posCol]);
					// eliminate B
					board[locRow-1][locCol] = 'X';
					redCoins--;
					turn ='R';
				}
				// X to 9
				else if(loc == 7 && pos == 9 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X' && board[locRow][locCol+1] == 'R' )
				{
					//swap
					swap(board[locRow][locCol] , board[posRow][posCol]);
					// eliminate B
					board[locRow][locCol+1] = 'X';
					redCoins--;
					turn ='R';
				}
			}
	else if(loc ==8)
			{
				// up
				if(loc == 8 && pos == 5 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X')
				{
					swap(board[locRow][locCol] , board[posRow][posCol]);
					turn ='R';
				}
				//left
				else if(loc == 8 && pos == 7 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X')
				{
					swap(board[locRow][locCol] , board[posRow][posCol]);
					turn ='R';
				}
				//right
				else if(loc == 8 && pos == 9 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X')
				{
					swap(board[locRow][locCol] , board[posRow][posCol]);
					turn ='R';
				}
				
				// X to 2
				else if(loc == 8 && pos == 2 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X' && board[locRow-1][locCol] == 'R' )
				{
					
					//swap
					swap(board[locRow][locCol] , board[posRow][posCol]);
					// eliminate B
					board[locRow-1][locCol] = 'X';
					redCoins--;
					turn ='R';
				}
			}
	else if(loc ==9)
			{
					// up
				if(loc == 9 && pos == 6 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X')
				{
					swap(board[locRow][locCol] , board[posRow][posCol]);
					turn ='R';
				}
				//left
				else if(loc == 9 && pos == 8 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X')
				{
					swap(board[locRow][locCol] , board[posRow][posCol]);
					turn ='R';
				}
				// X to 3
				else if(loc == 9 && pos == 3 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X' && board[locRow-1][locCol] == 'R' )
				{
					//swap
					swap(board[locRow][locCol] , board[posRow][posCol]);
					// for eliminating blue Queen
					board[locRow-1][locCol] = 'X';
					redCoins--;
					turn ='R';
				}
				// X to 7
				else if(loc == 9 && pos == 7 && board[locRow][locCol] == 'B' && board[posRow][posCol]== 'X' && board[locRow][locCol-1] == 'R' )
				{
					//swap
					swap(board[locRow][locCol] , board[posRow][posCol]);
					// For eliminating Blue Queen
					board[locRow][locCol-1] = 'X';
					redCoins--;
					turn ='R';
				}
			}
			
			CBoard();
		}
	
	}
	// while bracket
	if(redCoins == 0)
	{
		cout << "Player Blue has won..." << endl;
		return 0;
	}
	else if(blueCoins == 0)
	{
		cout << "Player Red has won..." << endl;
		return 0;
	}
}

// X = Empty space
void createBoard()
{
	//this function is going to put all X's on the board when the game will begin. where X= emptyspace.
	for (int i = 0; i < 3; i++)
	{
        for (int j = 0; j < 3; j++)
		{        	
            board[i][j]='X';
        }
	}
}

void CBoard()
{
   //this function is simply going to print the chess board for croxtokill
    cout << "\n\n\t CroXtoKill\n\n";

    cout << "Player 1 (R)  -  Player 2 (B)" << endl << endl;
    cout << endl;

    cout << "     |     |     " << endl;
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << endl;

    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;

    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << endl;

    cout << "     |     |     " << endl << endl;
}
