#include<stdio.h>
#include<stdlib.h>
int getInput();
void getGrid(int, int, int**);
void calculateDiffMatrix(int, int, int**, int**, int, int, int**);
void displayResult(int, int, int**);
int main()
{
    int row, colm, **mat1, **mat2, **count;
    printf("Enter the no. of rows of matrix = ");
    row = getInput();
    printf("Enter the no. of columns of the matrix = ");
    colm = getInput();
    int factor1 = (row>colm)? row:colm;
    int factor2 = (row<colm)? row:colm;
    printf("\nfactor = %d\n", factor1);
    mat1 = (int **) malloc(row);
    mat2 = (int **) malloc(row);
    count = (int **) malloc(factor1);
    for(int i=0; i<row; i++)
    {
        mat1[i] = (int *) calloc(colm, sizeof(int));
        mat2[i] = (int *) calloc(colm, sizeof(int));
        count[i] = (int *) calloc((row+colm)/factor2, sizeof(int));
    }
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<colm; j++)
        {
            count[i][j] = -1;
        }
    }
    getGrid(row, colm, mat1);
    calculateDiffMatrix(row, colm, mat1, mat2, 0, 0, count);
    displayResult(row, colm, mat2);
    free(mat1);
    free(mat2);
    return 0;
}
int getInput()
{
    int n;
    scanf("%d",&n);
    return n;
}
void getGrid(int r, int c, int **m)
{
    printf("Enter the elements of the matrix or grid :\n");
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }
}
void calculateDiffMatrix(int row, int colm, int **m1, int **m2, int r_index, int c_index, int **count)
{
    if(r_index>=row || c_index>=colm)
        return;
    int z_count1 = 0;
    int z_count2 = 0;
    int o_count1 = 0;
    int o_count2 = 0;
    if(count[0][r_index] == -1)
    {
        for(int i=0; i<colm; i++)
        {
            if(m1[r_index][i] == 0)
                z_count1++;
            else
                o_count1++;
        }
        count[0][r_index] = z_count1;
    }
    else
    {
        z_count1 = count[0][r_index];
        o_count1 = colm-count[0][r_index];
    }
    if(count[1][c_index] == -1)
    {
        for(int i=0; i<row; i++)
        {
            if(m1[i][c_index] == 0)
                z_count2++;
            else
                o_count2++;
        }
        count[1][c_index] = z_count2;
    }
    else
    {
        z_count2 = count[1][c_index];
        o_count2 = row-count[1][c_index];
    }
    m2[r_index][c_index] = o_count1 + o_count2 - z_count1 - z_count2;
    calculateDiffMatrix(row, colm, m1, m2, r_index+1, c_index, count);
    calculateDiffMatrix(row, colm, m1, m2, r_index, c_index+1, count);

}
void displayResult(int r, int c, int **m)
{
    printf("Matrix of calculated difference is : \n");
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    printf("Completed.....\n");
}
