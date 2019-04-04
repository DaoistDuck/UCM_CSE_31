#include <stdio.h>
#include <stdlib.h>

// Declare printSudoku function
void printSudoku(int***);
// Declare solveSudoku function
int solveSudoku(int***);

//Helper functions. You can define any functions that can help your solve the problem

int findingZeros(int *** blocks);

int numberUsedInRow(int *** blocks, int row, int grid, int number);


int numberUsedInColumn(int *** blocks, int column, int grid, int number);


int numberUsedInBox(int *** blocks, int row, int column, int grid, int number);


int isSafeToPlugInNumber(int *** blocks, int row, int column, int grid, int number);



/*
The main program reads a text file containing the block values of the Sudoku grid.
It then saves each 3x3 block into a 2D array. The Sudoku grid is composed of 9 3x3 blocks.
DO NOT MODIFY THE MAIN FUNTION!!!
*/
int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file name>\n", argv[0]);
		return 2;
	}
    int i, j;
    FILE *fptr;
    int ***blocks = (int***)malloc(9 * sizeof(int**));

    // Open file for reading
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        printf("Cannot Open File!\n");
        return 0;
    }

	// Read 9x9 blocks into 2D arrays
    for(i=0; i<9; i++)
    {
        *(blocks+i) = (int**)malloc(3 * sizeof(int*));
        printf("Reading numbers in block %d... \n", i+1);
        for(j=0; j<3; j++)
        {
            *(*(blocks+i)+j) = (int*)malloc(3 * sizeof(int));

                fscanf(fptr, "%d %d %d", *(*(blocks+i)+j), *(*(blocks+i)+j)+1, *(*(blocks+i)+j)+2);
                printf("%d %d %d\n", *(*(*(blocks+i)+j)), *(*(*(blocks+i)+j)+1), *(*(*(blocks+i)+j)+2));
        }
    }

	// Print out original Sudoku grid
    printf("Printing Sudoku before being solved:\n");
    printSudoku(blocks);
    
	// Call solveSudoku and print out result
    printf("\nSolving Sudoku...\n\n");
    if(solveSudoku(blocks)){
        printf("Sudoku solved!\n");
        printSudoku(blocks);
    }
    else
        printf("This Sudoku cannot be solved!\n");

    return 0;
}


void printSudoku(int*** arr){
	// This function will print out the complete Sudoku grid (arr). It must produce the output in the SAME format as the samples in the instructions.

  	// Your implementation here
    int row, column, location ,grid, puzzle = 3; // grid 0-2 is the first 3x3 row, 3-5 is the second 3x3 row, 6-8 is the third 3x3 row
    for(grid = 0; grid < 9; grid += 3){
        for(row = 0; row < 3; row ++){ // row 0 is the first row of all 3x3, row 1 is the second row of all 3x3, row 2 is the third row of all 3x3
            for(location = grid; location < puzzle; location++){
                for(column = 0; column < 3; column++){
                    printf("%d ", *(*(*(arr + location)+row)+column));
                    if(column == 2){
                        printf("|");
                    }                
                }              
            }
            printf("\n");
        }
        puzzle += 3;
        if(grid ==  0 || grid == 3){
            printf("---------------------\n");
        }
    } 
}

int solveSudoku(int*** blocks){
	// This is the function to solve the Sudoku (blocks). Feel free to use any helper functions.
	// YOU MUST NOT USE ANY ARRAY NOTATION ([])!

	//Your implementation here

    int row, column, grid, number;
    
    if(!findingZeros(blocks)){
        return 1;
    }

    for(grid = 0; grid < 9; grid ++){
        for(row = 0; row < 3; row ++){
            for(column = 0; column < 3; column++){
                if(*(*(*(blocks+grid)+row)+column) == 0){
                    for(number = 1; number <=9; number ++){
                        if(isSafeToPlugInNumber(blocks, row, column, grid, number)){
                            *(*(*(blocks+grid)+row)+column) = number;

                            if(solveSudoku(blocks)){
                                return 1;
                            }            
                        }
                    }
                    *(*(*(blocks+grid)+row)+column) = 0;
                    return 0; // this is the recursive part as if its fails, it just reruns solveSudoku
                }
            }
        }
    }
    return 1; 
}

int findingZeros(int *** arr){
    int row, column, grid;
    for(grid = 0; grid < 9; grid ++){
        for(row = 0; row < 3; row ++){
            for(column = 0; column < 3; column++){
                if(*(*(*(arr+grid)+row)+column) == 0){
                    return 1; // if found a zero return true;
                }              
            }
        }
    }  
    return 0;
}

int numberInRow(int *** arr, int row, int grid, int number){ //since each 1 is in 3x3, we just need to check per 3
    int column = 0;
    if(grid <=2){ // for this it checks the first 3 3x3 
        for(grid = 0; grid <= 2; grid++){
            for(column = 0; column < 3; column++){
                if(*(*(*(arr + grid)+row)+column) == number){
                    return 0; // if found the number return false
                }
            }
        }
    } else if(grid >= 3 && grid <=5){ // checks the second 3 3x3
        for(grid = 3; grid <= 5; grid++){
            for(column = 0; column < 3; column++){
                if(*(*(*(arr + grid)+row)+column) == number){
                    return 0; // if found the number return false
                }
            }
        }
    } else{ // checks the last 3 3x3
        for(grid = 6; grid <= 8; grid++){
            for(column = 0; column < 3; column++){
                if(*(*(*(arr + grid)+row)+column) == number){
                    return 0; // if found the number return false
                }
            }
        }
    }
    return 1; // otherwise return true to the number that isnt present in the row
}

int numberInColumn(int *** arr, int column, int grid, int number){//since its 3 by 3, we have to check column by each grid
    int row = 0;
    
    if(grid == 0 || grid == 3 || grid == 6){ // so since there are 9 3x3, this checks the 1st, 4rd, and 7th 3x3 
        for(grid = 0; grid <= 6; grid += 3){
            for(row = 0; row < 3; row ++){
                if(*(*(*(arr+grid)+row)+column) == number){
                    return 0; // if found the number return false
                }
            }
        }        
    } else if(grid == 1 || grid == 4 || grid == 7){// this checks the 2nd, 5th, and 8th 3x3
        for(grid = 1; grid < 7; grid += 3){
            for(row = 0; row < 3; row ++){
                if(*(*(*(arr+grid)+row)+column) == number){
                    return 0; // if found the number return false           
                }
            }
        } 
    } else{
        for(grid = 2; grid < 8; grid += 3){// this checks the 3rd, 6th, and 9th 3x3 
            for(row = 0; row < 3; row ++){
                if(*(*(*(arr+grid)+row)+column) == number){
                    return 0; // if found the number return false            
                }
            }
        } 
    }
    return 1; // otherwise return true to the number that isnt present in the column
}

int numberInBox(int *** arr, int grid, int number){//its already in a 3x3 box
    int row = 0, column = 0;
    for(row = 0; row < 3; row ++){ // since the grid tells us which 3x3 box we are looking for, its fine to just check row and column
        for(column = 0; column < 3; column++){
            if(*(*(*(arr + grid)+row)+column) == number){
                return 0; // if found the number return false  
            }
        }
    }  
    return 1; // otherwise return true to the number that isnt present in the box
}

int isSafeToPlugInNumber(int *** arr, int row, int column, int grid, int number){//combine all the helper functions into this 1
    return numberInRow(arr, row, grid, number)
        && numberInColumn(arr, column, grid, number)
        && numberInBox(arr, grid, number);
        //return the opposite because I want to find a number that isnt already there;
    
}