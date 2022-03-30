//
//  main.c
//  Three
//
//  Created by 👻 on 22/03/2022.
#include <stdio.h>
#include <stdlib.h>

const int minYear=1;//----------> minimum Year
const int maxYear=10000 ;//-----> maximum Year
const int minMonth=1;//---------> minimum Month
const int maxMonth=12;//--------> maximum Month


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


int main(){
    int day[30] ,month[30] ,year[30] ;//limit we can only save 30 dates
    int dummy;
    while(1)
    {
    printf("How many dates you want to Enter ");
    scanf("%d",&dummy);
    if(dummy>30){
        fprintf(stderr, "[ERROR] you can only enter upto 30 dates!\n Enter Again : \n");
    }
    else{
        break;
    }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    ////////LOOP WILL CONTINUE UNTIL DATE ONE IS NOT VALID    //////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    for(int i=0;i<dummy;i++)
    {
        while (1) {
            printf("Input Date  =>  (DD/MM/YY): ");
            scanf("%d/%d/%d", &day[i], &month[i], &year[i]);
        
            if(dateValidation(day[i], month[i], year[i])==1){
            break;
            }
        else{
            fprintf(stderr, "[ERROR] Enter Date Again!\n");
            //standard Error
        }
    }

}
    ////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////    S O R T I N G     D A T E           /////////////
    ///////////////////////////////////////////////////////////////////////////////////////
    for (int i=0; i<dummy-1; i++)
    {
        for (int j=i+1; j<dummy; j++)
        {
            if (year[i] > year[j])
            {
                int temp = year[i];
                year[i] = year[j];
                year[j] = temp;
                
                int temp2 = month[i];
                month[i] = month[j];
                month[j] = temp2;
                
                int temp3 = day[i];
                day[i] = day[j];
                day[j] = temp3;
                
            }
            else if (year[i] == year[j] && month[i] > month[j])
            {
                int temp = year[i];
                year[i] = year[j];
                year[j] = temp;
                
                int temp2 = month[i];
                month[i] = month[j];
                month[j] = temp2;
                
                int temp3 = day[i];
                day[i] = day[j];
                day[j] = temp3;
            }
            else if (year[i] == year[j] && month[i] == month[j] && day[i] > day[j])
            {
                int temp = year[i];
                year[i] = year[j];
                year[j] = temp;
                
                int temp2 = month[i];
                month[i] = month[j];
                month[j] = temp2;
                
                int temp3 = day[i];
                day[i] = day[j];
                day[j] = temp3;
            }
  
        }
}
    ////////////////////////////////////////////////////////////////////////////////////////
    ////////////////////   O U T P U T   S O R T E D         /////////////
    ///////////////////////////////////////////////////////////////////////////////////////
    for(int i=0;i<dummy;i++)
    {
        printf(" %d/%d/%d\n", day[i], month[i], year[i]);
    }
    return 0;
}
