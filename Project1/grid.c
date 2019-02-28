#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
for ( int i = 0; i <= n*n; i++ )
    {
        if ( i == 9 )
        {
            for ( int x =0; x <= 30; x++)
            {
                printf("-");
            }
            printf("\n");
            break;
        }

        if ( i == 0 || i == 3 || i == 6 )
        {
            for ( int x =0; x <= 30; x++)
            {
                printf("-");
            }
            printf("\n");
        }
        for ( int j = 0; j < n*n; j++ )
        {
            for ( k = 0; k < number; k++ )
            {
                check = '0';
                if ( j == column_random [k] && i == row_random [k] )
                {
                    check = '1';
                    break;
                }
                else
                {
                    check = '0';
                }
            }
            if ( check == '1' )
            {
                if ( check == '1' && ( j == 0 || j == 3 || j == 6 ) )
                {
                    printf("|   ");
                }
                else if ( check == '1' && j == 8 )
                {
                    printf("   |");
                }
                else
                {
                    printf("   ");
                }
            }
            else
            {
                if ( j == 0 || j == 3 || j == 6 )
                {
                    printf("|%2d ",(i*n + i/n + j) % (n*n) + 1);
                }
                else if ( check == '0' && j == 8 )
                {
                    printf("%2d |",(i*n + i/n + j) % (n*n) + 1);
                }
                else
                {
                    printf("%2d ",(i*n + i/n + j) % (n*n) + 1);
                }

            }

        }
        printf("\n");   



}
}
