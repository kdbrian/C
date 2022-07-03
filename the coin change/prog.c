#include<stdio.h>
/**Outputs the minimum ways in which a change can be provided*/
const int DENOMINATIONS[]= {1,5,10,25};
int row=(sizeof(DENOMINATIONS)/4);
static int col;

int main(){
    int AMOUNT;
    printf("Denominations available are : ");
    for(int i=0;i<sizeof(DENOMINATIONS)/4;i++)
        printf("%d ",DENOMINATIONS[i]);

    printf("\n\nEnter amount to give change : ");
    scanf("%d",&AMOUNT);

    col=AMOUNT+1;


    int table[row][col];


        printf("\t  0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15\n");
        printf("\t************************************************\n");

    for(int i=0;i<row;i++){

        for(int j=0;j<col;j++){

            table[i][0]=1;

            if(i==0)
                table[i][j]=(j%DENOMINATIONS[i]==0?1:0);

            if(i>0){

                if(DENOMINATIONS[i]>j){
                    table[i][j]=table[i-1][j];//taking the value above it
                }else{

                    table[i][j]=table[i-1][j]+(table[i][j-DENOMINATIONS[i]]);
                }
            }

        }
    }
    print_arry(table);

    printf("\n\nThere are %d ways to give a %d change using the denominations available\n\n",table[row-1][col-1],AMOUNT);

    return 0;
}

void print_arry(int nums[row][ col]){

    for(int i=0;i<row;i++){
        printf("%d\t|",DENOMINATIONS[i]);
        for(int j=0;j<col;j++){
            printf("%3d",nums[i][j]);
        }

        printf("\n");
    }


}

