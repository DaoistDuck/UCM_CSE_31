#include <stdio.h>
#include <stdlib.h>

// Declare printSudoku function
void printSudoku(int***);
// Declare solveSudoku function
int solveSudoku(int***);

//Helper functions. You can define any functions that can help your solve the problem

void printSudokuGrid();


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

   int row, column ,k, m;
  
   for(row = 0; row < 9; row++){
       if(row == 3 || row == 6){
           printf("---------------------\n");
       }
       for(column = 0; column < 3; column++){
        
           if(row == 0){
                if(column == 0){
                    printf("%d %d %d ", *(*(*(arr+row)+column)), *(*(*(arr+row)+column)+1), *(*(*(arr+row)+column)+2));
                }
                if(column == 1){
                    printf("%d %d %d ", *(*(*(arr+(row+1))+(column-1))), *(*(*(arr+(row+1))+(column-1))+1), *(*(*(arr+(row+1))+(column-1))+2));
                }
                if(column == 2){
                    printf("%d %d %d ", *(*(*(arr+(row+2))+(column-2))), *(*(*(arr+(row+2))+(column-2))+1), *(*(*(arr+(row+2))+(column-2))+2));
                }
                if(column == 0 || column == 1|| column == 2){
                    printf("|");
                }
            }  
            if(row == 1){
                if(column == 0){
                     printf("%d %d %d ", *(*(*(arr+(row-1))+(column+1))), *(*(*(arr+(row-1))+(column+1))+1), *(*(*(arr+(row-1))+(column+1))+2));
                }
                if(column == 1){
                    printf("%d %d %d ", *(*(*(arr+row)+column)), *(*(*(arr+row)+column)+1), *(*(*(arr+row)+column)+2));
                }
                if(column == 2){
                    printf("%d %d %d ", *(*(*(arr+(row+1))+(column-1))), *(*(*(arr+(row+1))+(column-1))+1), *(*(*(arr+(row+1))+(column-1))+2));
                }
                 if(column == 0 || column == 1|| column == 2){
                    printf("|");
                }
                
            }
            if(row == 2){
                if(column == 0){
                    printf("%d %d %d ", *(*(*(arr+(row-2))+(column+2))), *(*(*(arr+(row-2))+(column+2))+1), *(*(*(arr+(row-2))+(column+2))+2));
                }
                if(column == 1){
                    printf("%d %d %d ", *(*(*(arr+(row-1))+(column+1))), *(*(*(arr+(row-1))+(column+1))+1), *(*(*(arr+(row-1))+(column+1))+2));
                }
                if(column == 2){
                    printf("%d %d %d ", *(*(*(arr+row)+column)), *(*(*(arr+row)+column)+1), *(*(*(arr+row)+column)+2));
                }
                 if(column == 0 || column == 1|| column == 2){
                    printf("|");
                }                                  
            }
            if(row == 3){
                if(column == 0){
                    printf("%d %d %d ", *(*(*(arr+row)+column)), *(*(*(arr+row)+column)+1), *(*(*(arr+row)+column)+2));
                }
                if(column == 1){
                    printf("%d %d %d ", *(*(*(arr+(row+1))+(column-1))), *(*(*(arr+(row+1))+(column-1))+1), *(*(*(arr+(row+1))+(column-1))+2));
                }
                if(column == 2){
                    printf("%d %d %d ", *(*(*(arr+(row+2))+(column-2))), *(*(*(arr+(row+2))+(column-2))+1), *(*(*(arr+(row+2))+(column-2))+2));
                }
                if(column == 0 || column == 1|| column == 2){
                    printf("|");
                }                              
            }
             if(row == 4){
                if(column == 0){
                     printf("%d %d %d ", *(*(*(arr+(row-1))+(column+1))), *(*(*(arr+(row-1))+(column+1))+1), *(*(*(arr+(row-1))+(column+1))+2));
                }
                if(column == 1){
                    printf("%d %d %d ", *(*(*(arr+row)+column)), *(*(*(arr+row)+column)+1), *(*(*(arr+row)+column)+2));
                }
                if(column == 2){
                    printf("%d %d %d ", *(*(*(arr+(row+1))+(column-1))), *(*(*(arr+(row+1))+(column-1))+1), *(*(*(arr+(row+1))+(column-1))+2));
                }
                 if(column == 0 || column == 1|| column == 2){
                    printf("|");
                }                            
            }
             if(row == 5){
                if(column == 0){
                    printf("%d %d %d ", *(*(*(arr+(row-2))+(column+2))), *(*(*(arr+(row-2))+(column+2))+1), *(*(*(arr+(row-2))+(column+2))+2));
                }
                if(column == 1){
                    printf("%d %d %d ", *(*(*(arr+(row-1))+(column+1))), *(*(*(arr+(row-1))+(column+1))+1), *(*(*(arr+(row-1))+(column+1))+2));
                }
                if(column == 2){
                    printf("%d %d %d ", *(*(*(arr+row)+column)), *(*(*(arr+row)+column)+1), *(*(*(arr+row)+column)+2));
                }
                 if(column == 0 || column == 1|| column == 2){
                    printf("|");
                }                                   
            }
            if(row == 6){
                if(column == 0){
                    printf("%d %d %d ", *(*(*(arr+row)+column)), *(*(*(arr+row)+column)+1), *(*(*(arr+row)+column)+2));
                }
                if(column == 1){
                    printf("%d %d %d ", *(*(*(arr+(row+1))+(column-1))), *(*(*(arr+(row+1))+(column-1))+1), *(*(*(arr+(row+1))+(column-1))+2));
                }
                if(column == 2){
                    printf("%d %d %d ", *(*(*(arr+(row+2))+(column-2))), *(*(*(arr+(row+2))+(column-2))+1), *(*(*(arr+(row+2))+(column-2))+2));
                }
                if(column == 0 || column == 1|| column == 2){
                    printf("|");
                }                              
            }
             if(row == 7){
                if(column == 0){
                     printf("%d %d %d ", *(*(*(arr+(row-1))+(column+1))), *(*(*(arr+(row-1))+(column+1))+1), *(*(*(arr+(row-1))+(column+1))+2));
                }
                if(column == 1){
                    printf("%d %d %d ", *(*(*(arr+row)+column)), *(*(*(arr+row)+column)+1), *(*(*(arr+row)+column)+2));
                }
                if(column == 2){
                    printf("%d %d %d ", *(*(*(arr+(row+1))+(column-1))), *(*(*(arr+(row+1))+(column-1))+1), *(*(*(arr+(row+1))+(column-1))+2));
                }
                 if(column == 0 || column == 1|| column == 2){
                    printf("|");
                }                            
            }
             if(row == 8){
                if(column == 0){
                    printf("%d %d %d ", *(*(*(arr+(row-2))+(column+2))), *(*(*(arr+(row-2))+(column+2))+1), *(*(*(arr+(row-2))+(column+2))+2));
                }
                if(column == 1){
                    printf("%d %d %d ", *(*(*(arr+(row-1))+(column+1))), *(*(*(arr+(row-1))+(column+1))+1), *(*(*(arr+(row-1))+(column+1))+2));
                }
                if(column == 2){
                    printf("%d %d %d ", *(*(*(arr+row)+column)), *(*(*(arr+row)+column)+1), *(*(*(arr+row)+column)+2));
                }
                 if(column == 0 || column == 1|| column == 2){
                    printf("|");
                }                                   
            }          
        }
        printf("\n");
    }
}

int solveSudoku(int*** blocks){
	// This is the function to solve the Sudoku (blocks). Feel free to use any helper functions.
	// YOU MUST NOT USE ANY ARRAY NOTATION ([])!

	//Your implementation here
    

	return 0;
}

