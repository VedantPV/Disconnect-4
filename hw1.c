#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "hw1.h"


    

char board[MAX_ROWS][MAX_COLS] = {0};
/*
Hint: Consider adding a global variable to store a string large enough to store a board.
*/
char medium_level_board[MAX_ROWS][MAX_COLS] = {0};
char init_board[MAX_ROWS*MAX_COLS]; 

void print_board(int num_rows, int num_cols)
{
    for(int row = 0; row < num_rows; row++)
    {
        for(int col = 0; col < num_cols; col++)
        {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
}

bool horizontal_check(char main_cell_token, int row_position, int col_position, int num_columns)
{
    for(int i = 0; i < 4; i++)
    {
        if(i == 0)
        {
            if(col_position + 1 >= num_columns || col_position + 2 >= num_columns || col_position + 3 >= num_columns)
            {
                continue;
            }

            

            if(board[row_position][col_position+1] == main_cell_token
            && board[row_position][col_position+2] == main_cell_token
            && board[row_position][col_position+3] == main_cell_token)
            {
                return true;
            }
    
        }
        if(i == 1)
        {
            
            if(col_position - 1 >= num_columns || col_position + 1 >= num_columns || col_position + 2 >= num_columns)
            {
                continue;
            }

            if(col_position - 1 < 0)
            {
                continue;
            }

            if(board[row_position][col_position-1] == main_cell_token
            && board[row_position][col_position+1] == main_cell_token
            && board[row_position][col_position+2] == main_cell_token)
            {
                return true;
            }   
            
        }
        if(i == 2)
        {
           
           if(col_position - 2 >= num_columns || col_position - 1 >= num_columns || col_position + 1 >= num_columns)
            {
                continue;
            }

            if(col_position - 2 < 0 || col_position - 1 < 0)
            {
                continue;
            }

            if(board[row_position][col_position-2] == main_cell_token
            && board[row_position][col_position-1] == main_cell_token
            && board[row_position][col_position+1] == main_cell_token)
            {
                return true;
            }
            
        }
        if(i == 3)
        {
            
            if(col_position - 3 >= num_columns || col_position - 2 >= num_columns || col_position - 1 >= num_columns)
            {
                continue;
            }
            
            if(col_position - 3 < 0 || col_position - 2 < 0 || col_position - 1 < 0)
            {
                continue;
            }

            if(board[row_position][col_position-3] == main_cell_token
            && board[row_position][col_position-2] == main_cell_token
            && board[row_position][col_position-1] == main_cell_token)
            {
                return true;
            }
            
        }

    }
    return false;
}

bool vertical_check(char main_cell_token, int row_position, int col_position, int num_rows)
{
     for(int i = 0; i < 4; i++)
    {
         if(i == 0)
        {
            if(row_position + 1 >= num_rows || row_position + 2 >= num_rows || row_position + 3 >= num_rows)
            {
                continue;
            }

            if(board[row_position+1][col_position] == main_cell_token
            && board[row_position+2][col_position] == main_cell_token
            && board[row_position+3][col_position] == main_cell_token)
            {
                return true;
            }
    
        }
        if(i == 1)
        {
            
            if(row_position - 1 >= num_rows || row_position + 1 >= num_rows || row_position + 2 >= num_rows)
            {
                continue;
            }

            if(row_position - 1 < 0)
            {
                continue;
            }


            if(board[row_position-1][col_position] == main_cell_token
            && board[row_position+1][col_position] == main_cell_token
            && board[row_position+2][col_position] == main_cell_token)
            {
                return true;
            }   
            
        }
        if(i == 2)
        {
            
            if(row_position - 2 >= num_rows || row_position - 1 >= num_rows || row_position + 1 >= num_rows)
            {
                continue;
            }

            if(row_position - 2 < 0 || row_position - 1 < 0)
            {
                continue;
            }


            if(board[row_position-2][col_position] == main_cell_token
            && board[row_position-1][col_position] == main_cell_token
            && board[row_position+1][col_position] == main_cell_token)
            {
                return true;
            }
            
        }
        if(i == 3)
        {
            
            
            if(row_position - 3 >= num_rows || row_position - 2 >= num_rows || row_position - 1 >= num_rows)
            {
                continue;
            }

            if(row_position - 3 < 0 || row_position - 2 < 0 || row_position - 1 < 0)
            {
                continue;
            }

            if(board[row_position-3][col_position] == main_cell_token
            && board[row_position-2][col_position] == main_cell_token
            && board[row_position-1][col_position] == main_cell_token)
            {
                return true;
            }
            
        }

    }
    return false;
}

bool main_diagonal_check(char main_cell_token, int row_position, int col_position, int num_rows, int num_columns) //20x20 fails here! at row 11, col 18
{
     for(int i = 0; i < 4; i++)
    {
         if(i == 0)
        {
            
            if(row_position + 1 >= num_rows || row_position + 2 >= num_rows || row_position + 3 >= num_rows || 
            col_position + 1 >= num_columns || col_position + 2 >= num_columns || col_position + 3 >= num_columns)
            {
                continue;
            }

            if(board[row_position+1][col_position+1] == main_cell_token
            && board[row_position+2][col_position+2] == main_cell_token
            && board[row_position+3][col_position+3] == main_cell_token)
            {
                return true;
            }
    
        }
        if(i == 1)
        {
            
            if(row_position - 1 >= num_rows || row_position + 1 >= num_rows || row_position + 2 >= num_rows || 
            col_position - 1 >= num_columns || col_position + 1 >= num_columns || col_position + 2 >= num_columns)
            {
                continue;
            }
            if(row_position - 1 < 0 || col_position - 1 < 0)
            {
                continue;
            }

            if(board[row_position-1][col_position-1] == main_cell_token
            && board[row_position+1][col_position+1] == main_cell_token
            && board[row_position+2][col_position+2] == main_cell_token)
            {
                return true;
            }   
            
        }
        if(i == 2)
        {
            
            if(row_position - 2 >= num_rows || row_position - 1 >= num_rows || row_position + 1 >= num_rows || 
            col_position - 2 >= num_columns || col_position - 1 >= num_columns || col_position + 1 >= num_columns)
            {
                continue;
            }

            if(row_position - 2 < 0 || row_position - 1 < 0 || col_position - 2 < 0 || col_position - 1 < 0)
            {
                continue;
            }

            if(board[row_position-2][col_position-2] == main_cell_token
            && board[row_position-1][col_position-1] == main_cell_token
            && board[row_position+1][col_position+1] == main_cell_token)
            {
                return true;
            }
            
        }
        if(i == 3)
        {
            
            if(row_position - 3 >= num_rows || row_position - 2 >= num_rows || row_position - 1 >= num_rows || 
            col_position - 3 >= num_columns || col_position - 2 >= num_columns || col_position - 1 >= num_columns)
            {
                continue;
            }

            if(row_position - 3 < 0 || row_position - 2 < 0 || row_position - 1 < 0 || 
            col_position - 3 < 0 || col_position - 2 < 0 || col_position - 1 < 0)
            {
                continue;
            }

            if(board[row_position-3][col_position-3] == main_cell_token
            && board[row_position-2][col_position-2] == main_cell_token
            && board[row_position-1][col_position-1] == main_cell_token)
            {
                return true;
            }
            
        }

    }
    return false;
}

bool counter_diagonal_check(char main_cell_token, int row_position, int col_position, int num_rows, int num_columns)
{
     for(int i = 0; i < 4; i++)
    {
         if(i == 0)
        {
            
            if(row_position - 1 >= num_rows || row_position - 2 >= num_rows || row_position - 3 >= num_rows || 
            col_position + 1 >= num_columns || col_position + 2 >= num_columns || col_position + 3 >= num_columns)
            {
                continue;
            }

            if(row_position - 1 < 0 || row_position - 2 < 0 || row_position - 3 < 0)
            {
                continue;
            }

            if(board[row_position-1][col_position+1] == main_cell_token
            && board[row_position-2][col_position+2] == main_cell_token
            && board[row_position-3][col_position+3] == main_cell_token)
            {
                return true;
            }
    
        }
        if(i == 1)
        {
            
            if(row_position + 1 >= num_rows || row_position - 1 >= num_rows || row_position - 2 >= num_rows || 
            col_position - 1 >= num_columns || col_position + 1 >= num_columns || col_position + 2 >= num_columns)
            {
                continue;
            }
            
            if(row_position - 1 < 0 || row_position - 2 < 0 || col_position - 1 < 0)
            {
                continue;
            }

            if(board[row_position+1][col_position-1] == main_cell_token
            && board[row_position-1][col_position+1] == main_cell_token
            && board[row_position-2][col_position+2] == main_cell_token)
            {
                return true;
            }   
            
        }
        if(i == 2)
        {
            
            if(row_position + 2 >= num_rows || row_position + 1 >= num_rows || row_position - 1 >= num_rows || 
            col_position - 2 >= num_columns || col_position - 1 >= num_columns || col_position + 1 >= num_columns)
            {
                continue;
            }

            if(row_position - 1 < 0|| col_position - 2 < 0 || col_position - 1 < 0)
            {
                continue;
            }

            if(board[row_position+2][col_position-2] == main_cell_token
            && board[row_position+1][col_position-1] == main_cell_token
            && board[row_position-1][col_position+1] == main_cell_token)
            {
                return true;
            }
            
        }
        if(i == 3)
        {
            
            if(row_position + 3 >= num_rows || row_position + 2 >= num_rows || row_position + 1 >= num_rows || 
            col_position - 3 >= num_columns || col_position - 2 >= num_columns || col_position - 1 >= num_columns)
            {
                continue;
            }

            if(col_position - 3 < 0 || col_position - 2 < 0 || col_position - 1 < 0)
            {
                continue;
            }

            if(board[row_position+3][col_position-3] == main_cell_token
            && board[row_position+2][col_position-2] == main_cell_token
            && board[row_position+1][col_position-1] == main_cell_token)
            {
                return true;
            }
            
        }

    }
    return false;
}



bool four_in_a_row_attempt(char cellToken, int rowPos, int colPos, int num_rows, int num_cols)
{
   
    //Determine if you can find an easier way if there is still time, otherwise just do this.
    if(horizontal_check(cellToken, rowPos, colPos, num_cols) || vertical_check(cellToken, rowPos, colPos, num_rows) 
    || main_diagonal_check(cellToken, rowPos, colPos, num_rows, num_cols) || counter_diagonal_check(cellToken, rowPos, colPos, num_rows, num_cols))
    {
        return true;
    }
    else
    {
        return false;
    }
    
}



int play_now(int number_of_rows, int number_of_cols)
{
    bool continue_loop = true;
    
    print_board(number_of_rows, number_of_cols);

    while(continue_loop)
    {
        char token;
        printf("Choose a piece (x or o) or q to quit: ");
        scanf(" %c", &token);
        while(token != 'x' && token != 'o' && token != 'q')
        {
            printf("Invalid choice. Choose a piece (x or o) or q to quit: ");
            scanf(" %c", &token);
        }
        if(token == 'q')
        {
            return 0;
        }

        int rowCell, colCell;
        printf("Choose a row (0-%d): ", number_of_rows-1);
        scanf("%d", &rowCell);
        while(rowCell < 0 || rowCell >= number_of_rows)
        {
            printf("Invalid choice. Choose a row (0-%d): ", number_of_rows-1);
            scanf("%d", &rowCell);
        }
    
        printf("Choose a column (0-%d): ", number_of_cols-1);
        scanf("%d", &colCell);
        while(colCell < 0 || colCell >= number_of_cols)
        {
            printf("Invalid choice. Choose a column (0-%d): ", number_of_cols-1);
            scanf("%d", &colCell);
        }
    
        if(board[rowCell][colCell] == 'x' || board[rowCell][colCell] == 'o')
        {
            printf("Invalid choice. That space is already occupied.\n");
        }
        else if(four_in_a_row_attempt(token, rowCell, colCell, number_of_rows, number_of_cols))
        {
            printf("Invalid choice. You have created 4-in-a-row.\n");
        }
        else
        {
            board[rowCell][colCell] = token;
        }

        bool stop_loop = true;
        for(int row = 0; row < number_of_rows; row++)
        {
            for(int col = 0; col < number_of_cols; col++)
            {
                if(board[row][col] == '-')
                {
                    stop_loop = false;
                }       
            }
            
        }
        
        if(stop_loop)
        {
            continue_loop = false;
            printf("Congratulations, you have filled the board with no 4-in-a-rows!\n");
        }

        for(int row = 0; row < number_of_rows; row++)
        {
            for(int col = 0; col < number_of_cols; col++)
            {
                printf("%c ", board[row][col]);
            }
            printf("\n");
        }
                                                         
    }
    return 0;
}


void initialize_board(const char *initial_state, int num_rows, int num_cols) {
    int initCell = 0; 
    
    for(int row = 0; row < num_rows; row++)
    {
        for(int col = 0; col < num_cols; col++)
        {
            board[row][col] = initial_state[initCell];
            //printf("%c ", board[row][col]);
            initCell++;
        }
        //printf("\n");
    }
    
    
}

/*Part 2 Explanation: You'll run through the solve function, going cell by cell, to check whether 'x' or 'o' should be 
placed in the empty cell (Once you run into one). If either token doesn't result in a 4-in-a-row, then skip the cell
and move onto the next one (You'll loop the solve method again, and once certain spaces are filled in the program should
be able to pick the correct token. When this situation is run into, the HEURISTIC_FAILED error should be returned at the end). 
If one token creates a 4-in-a-row, but not the other, then insert it in. 
If both tokens create a 4-in-a-row in the cell, then return the respective NO_SOULTION error int. 
This method should loop until the board is solved.*/

//CUrrently breaks at 13X8 Hard puzzle!



bool compare_two_board(int num_rows, int num_cols, char board_one[num_rows][num_cols], char board_main[MAX_ROWS][MAX_COLS])
{
    for(int row = 0; row < num_rows; row++)
    {
        for(int col = 0; col < num_cols; col++)
        {
            if(board_one[row][col] != board_main[row][col])
            {
                return false;
            }
        }
    }
    return true;
}

int solve(const char *initial_state, int num_rows, int num_cols, int *num_x, int *num_o) {   
    
    *num_x = 0;
    *num_o = 0;

    initialize_board(initial_state, num_rows, num_cols);
    //printf("_________________\n");
    
    for(int row = 0; row < num_rows; row++)
    {
        for(int col = 0; col < num_cols; col++)
        {
            if(board[row][col] != 'x' && board[row][col] != 'o' && board[row][col] != '-')
            {
                //*num_x = 0;
                //*num_o = 0;
                return INITIAL_BOARD_INVALID_CHARACTERS;
            }
            else if((board[row][col] == 'x' || board[row][col] == 'o') && four_in_a_row_attempt(board[row][col], row, col, num_rows, num_cols))
            {
                //*num_x = 0;
                //*num_o = 0;
                return INITIAL_BOARD_FOUR_IN_A_ROW;
            }
            else
            {
                if(board[row][col] == 'x')
                {
                    *num_x = *num_x + 1;
                }
                else if (board[row][col] == 'o')
                {
                    *num_o = *num_o + 1;
                }
            }
            
            
            
        }
    }



    //run a double for-loop where you test 4 possibilities ('x' works and 'o' doesn't, 'o' works and 'x' doesn't, 'o' and 'x' work, 'o' and 'x' both don't work)
   

    while(*num_x + *num_o != (num_rows * num_cols)) //This While-Loop must be changed to prevent an infinite loop in testing!
    {
        char compare_boards[num_rows][num_cols];

        for(int row = 0; row < num_rows; row++)
        {
            for(int col = 0; col < num_cols; col++)
            {
                //printf("X's: %d O's: %d Row: %d, Col: %d\n", *num_x, *num_o, row, col);
                compare_boards[row][col] = board[row][col];
                //printf("%c ", board[row][col]);

                if(board[row][col] == '-')
                {
                    if(!four_in_a_row_attempt('x', row, col, num_rows, num_cols) && four_in_a_row_attempt('o', row, col, num_rows, num_cols))
                    {
                        board[row][col] = 'x';
                        *num_x = *num_x + 1;
                    }
                    else if(four_in_a_row_attempt('x', row, col, num_rows, num_cols) && !four_in_a_row_attempt('o', row, col, num_rows, num_cols))
                    {
                        board[row][col] = 'o';
                        *num_o = *num_o + 1; 
                    }
                    else if(four_in_a_row_attempt('x', row, col, num_rows, num_cols) && four_in_a_row_attempt('o', row, col, num_rows, num_cols))
                    {
                        //*num_x = 0;
                        //*num_o = 0;
                        return INITIAL_BOARD_NO_SOLUTION;
                    }
                    else
                    {
                        continue;
                    }
                } 
           
            }
            //printf("\n");
        }
        
        if(compare_two_board(num_rows, num_cols, compare_boards, board))
        {
            return HEURISTICS_FAILED;
        }
        //printf("__________________\n");
    }
    
        //printf("X's: %d O's: %d\n", *num_x, *num_o);
        //print_board(num_rows, num_cols);
        return FOUND_SOLUTION;
    

    return 0;
}





/*Part 3 Explanation: Using the solve function, you must utilize the number of x's and o's to figure out how to 
create an initial board from a final_state board. The function must decide whether to either remove a token, replace one token
with another, or to just leave it alone. The solve is used to determine if the board has a solution. Your solve function
should not return a HEURISTIC_FAILED error through undecisveness of token choice, otherwise you've made a wrong choice. 
The tests for this function check the minimum number of 'x' and 'o' in the initial board created.*/

void initialize_final_board(const char *final_state, int num_rows, int num_cols)
{
    for(int row = 0; row < num_rows; row++)
    {
        for(int col = 0; col < num_cols; col++)
        {
            medium_level_board[row][col] = *final_state;
            //printf("%c ", medium_level_board[row][col]);
            final_state++;
        }
        //printf("\n");
    }
}

void print_medium_board(int num_rows, int num_cols)
{
    for(int row = 0; row < num_rows; row++)
    {
        for(int col = 0; col < num_cols; col++)
        {
            printf("%c ", medium_level_board[row][col]);
        }
        printf("\n");
    }
}


char* generate_medium(const char *final_state, int num_rows, int num_cols) 
{ 
    initialize_final_board(final_state, num_rows, num_cols);
//To run solve, you'll need to determine the number of x's and o's beforehand. Also, check for
//three possible choices: Deleting the token, switching the token to its opposite, or leaving it alone due to failing to 
//find a solution.

    char init_board_for_solve[num_rows*num_cols];
    int init_incrementor = 0, num_x, num_o;
    
    for(int row = 0; row < num_rows; row++)
    {
        for(int col = 0; col < num_cols; col++)
        {
            init_board[init_incrementor] = medium_level_board[row][col];
            init_board_for_solve[init_incrementor] = medium_level_board[row][col];
            init_incrementor++;
        }
        
    }

    init_incrementor = 0;
    //char initial_medium_board[num_rows][num_cols];
    bool exit_flag = true;
    //At this point, you will need to incorporate a while-loop to check for additional changes in the board.// 
    while(exit_flag)
    {
    
    exit_flag = false;

    for(int row = 0; row < num_rows; row++)
    {
        for(int col = 0; col < num_cols; col++)
        {
            
            //initial_medium_board[row][col] = medium_level_board[row][col];
            if(medium_level_board[row][col] == '-')
            {
                init_incrementor++;
                continue;

            }
            
            char orig_token = medium_level_board[row][col];
            init_board_for_solve[init_incrementor] = '-';

            if(solve(init_board_for_solve, num_rows, num_cols, &num_x, &num_o) == FOUND_SOLUTION)
            {
                init_board[init_incrementor] = '-';
                medium_level_board[row][col] = '-';
                init_incrementor++;
                exit_flag = true;
                continue;
                
            }
            
            if(orig_token == 'x')
            {
                init_board_for_solve[init_incrementor] = 'o';
            }
            else 
            {
                init_board_for_solve[init_incrementor] = 'x';
            }
            
            if(solve(init_board_for_solve, num_rows, num_cols, &num_x, &num_o) == FOUND_SOLUTION)
            {
                init_board[init_incrementor] = init_board_for_solve[init_incrementor];
                medium_level_board[row][col] = init_board_for_solve[init_incrementor];
                init_incrementor++;
            
                continue;
                
            }
            else
            {
                init_board_for_solve[init_incrementor] = orig_token;
                init_incrementor++;
            }
        }
    }
    
    
    init_incrementor = 0;
    }
    //printf("Solve Result: %d",solve(init_board, num_rows, num_cols, &num_x, &num_o));
    print_medium_board(num_rows, num_cols);
    printf("%d \n", solve(init_board, num_rows, num_cols, &num_x, &num_o));
    //init_board[7] = '-';
    printf("%d \n", solve(init_board, num_rows, num_cols, &num_x, &num_o));
    return init_board;
}

