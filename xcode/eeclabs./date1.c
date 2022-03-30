//
//  main.c
//  Three
//
//  Created by 👻 on 21/03/2022.
#include <stdio.h>
#include <stdlib.h>

const int minYear=1;//----------> minimum Year
const int maxYear=10000 ;//-----> maximum Year
const int minMonth=1;//---------> minimum Month
const int maxMonth=12;//--------> maximum Month
////////////////////////////////////////////////////////////////////////////////////////
////////////D I F F E R E N C E     CALCULATION ////////////
///////////////////////////////////////////////////////////////////////////////////////
void Difference(int D1,int D2,int M1,int M2,int Y1,int Y2)
{
    const int Days_in_One_Month[12]= { 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31 };
    
    //we can calculate days before finding the difference
        long int No_Days_1 = Y1 * 365 + D1;
    // Add days for months in given date
        for (int i = 0; i < M1 - 1; i++)
        {
            No_Days_1 += Days_in_One_Month[i];
        }
    //counting number of days for date 2
        long int No_Days_2 = Y2 * 365 + D2;
    // Add days for months in given date
    for (int i = 0; i < M2 - 1; i++)
        No_Days_2 += Days_in_One_Month[i];

    long int days =(No_Days_2 - No_Days_1);
    printf("\nDifference of %ld days\n",days);
}
////////////////////////////////////////////////////////////////////////////////////////
//////////////////////  D a t e   V a l i d a t i o n           /////////////
///////////////////////////////////////////////////////////////////////////////////////
int dateValidation(int dd, int mm, int yy){
        int valid = 1;
        if (yy > minYear && yy < maxYear){
            if(mm >= minMonth && mm <=maxMonth)
            //month should start from 1
            //should ends at 12
            {
                if (mm == 1 || mm == 3 || mm == 5 || mm == 7 ||mm == 8 || mm == 10 || mm == 12){
                    if (dd <= 30){
                        valid = 1;
                    }
                }
                else if (mm == 2 && dd <=28){
                    valid = 1;
                }
                else if (mm == 4 || mm == 6 || mm == 9 || mm == 11){
                    if (dd <= 30){
                        valid = 1;
                    }
                }
                    
            }
            else{
                valid = 0;
            }
        }

        return valid;
}

int main(){
    int dd1 ,dd2;
    int mm1 ,mm2;
    int yy1 ,yy2;
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////LOOP WILL CONTINUE UNTIL DATE ONE IS NOT VALID    //////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    while (1) {
        printf("Input Date1  =>  (DD/MM/YY): ");
        scanf("%d/%d/%d", &dd1, &mm1, &yy1);
        
        if(dateValidation(dd1, mm1, yy1)==1){
            break;
        }
        else{
            fprintf(stderr, "[ERROR] Enter Date Again!\n");
            //standard Error
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////LOOP WILL CONTINUE UNTIL DATE TWO IS NOT VALID    //////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    while (1) {
        printf("Input Date1  =>  (DD-MM-YY): ");
        scanf("%d-%d-%d", &dd2, &mm2, &yy2);
        if(dateValidation(dd2, mm2, yy2)==1){
            break;
        }
        else{
            fprintf(stderr, "[ERROR] Enter Date Again!\n");
            //Standard Error
        }
    }

    
    Difference(dd1, dd2, mm1, mm2, yy1, yy2);
    
    return 0;
}
