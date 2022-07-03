#include<stdio.h>

// the denominations available
const int DENOMINATIONS[]={1,5,10,25};

//dimensions used to form the table
int row=(sizeof(DENOMINATIONS)/4);
int col;

int main(){

    int AMOUNT;

    printf("Denominations available are : ");
    for(int i=0;i<sizeof(DENOMINATIONS)/4;i++)
        printf("%d ",DENOMINATIONS[i]);

    // getting the input from the user
    printf("\n\nEnter amount to give change : ");
    scanf("%d",&AMOUNT);

    col=AMOUNT+1;

    int table[row][col];

    // resetting the default table values to zero(0)
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            table[i][j]=0;


    // filling up the table
    for(int i=0;i<row;i++){

        for(int j=0;j<col;j++){

            // there can only be a sum of zero if no coin is issued
            table[i][0]=0;

            if(DENOMINATIONS[i] == 1){

                table[i][j]=j*1;

            }else if(DENOMINATIONS[i]>j){

                table[i][j]=table[i-1][j];

            }else{
                table[i][j]=min(table[i-1][j],1+table[i][j-DENOMINATIONS[i]]);
            }

        }// end of inner for..loop
    }// end of outer for..loop

    printf("\nThe minimum number of coins needed to give a %2d change is %d\n",AMOUNT,table[row-1][col-1]);

return 0;
}

// returns the minimum of two numbers
int min(int x,int y){
    return (x>y)?y:x;
}

