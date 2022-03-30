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
/////////////////////////////////////////////////////////////////////////////////////////
////////////C H E C K     F O R     L E A P Y E A R //////////////
///////////////////////////////////////////////////////////////////////////////////////
int LeapYears(int year ,int month)
{
    int years = year;
 
    if (month <= 2)
        years--;

    return years / 4  - years / 100 + years / 400;
}
////////////////////////////////////////////////////////////////////////////////////////
//////////////////////  D a t e   V a l i d a t i o n  Fun    /////////////
///////////////////////////////////////////////////////////////////////////////////////
int dateValidation(int dd, int mm, int yy){
        int valid = 1;
        int is_leap=0;
        
        if (yy > minYear && yy < maxYear){
        //---------->  check for leap year
            if ((yy % 4 == 0 && yy % 100 != 0) || (yy % 400 == 0))
            {
                is_leap = 1;
            }
            if(mm > 0 && mm < 13)
            //month should start from 1
            //should ends at 12
            {
                if (mm == 1 || mm == 3 || mm == 5 || mm == 7 ||mm == 8 || mm == 10 || mm == 12){
                    if (dd <= 30){
                        valid = 1;
                    }
                }
                else if (mm == 2)
                {
                    //here we can check for leap years
                    //  check whether year is a leap year
                    if (is_leap && dd == 29){
                        valid = 1;
                        }
                    else if(dd > 28){
                        valid = 0;
                        }
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

////////////////////////////////////////////////////////////////////////////////////////
////////////D I F F E R E N C E     CALCULATION ////////////
///////////////////////////////////////////////////////////////////////////////////////
void Difference(int D1,int D2,int M1,int M2,int Y1,int Y2){
    const int Days_in_One_Month[12]= { 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31 };
    
    //we can calculate days before finding the difference
        long int No_Days_1 = Y1 * 365 + D1;
    // Add days for months in given date
    int i=0;
        for (i = 0; i < M1 - 1; i++)
            No_Days_1 += Days_in_One_Month[i];
            No_Days_1 += LeapYears(Y1,M1);
    //counting number of days for date 2
        long int No_Days_2 = Y2 * 365 + D2;
    // Add days for months in given date
    for (i = 0; i < M2 - 1; i++)
        No_Days_2 += Days_in_One_Month[i];
        No_Days_2 += LeapYears(Y2,M2);
    
    long int days =(No_Days_2 - No_Days_1);
        printf("\nDifference of %d days\n",days);
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
