#include <stdio.h>
#include <stdlib.h>

const int minYear=1;
const int maxYear=10000 ;
const int minMonth=1;
const int maxMonth=12;

void Difference(int D1,int D2,int M1,int M2,int Y1,int Y2)
{
    const int Days_in_One_Month[12]= { 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31 };
    

        long int No_Days_1 = Y1 * 365 + D1;

    int i=0;
        for (i = 0; i < M1 - 1; i++)
        {
            No_Days_1 += Days_in_One_Month[i];
        }

        long int No_Days_2 = Y2 * 365 + D2;
    
    for (i = 0; i < M2 - 1; i++)
        No_Days_2 += Days_in_One_Month[i];

    long int days =(No_Days_2 - No_Days_1);
    printf("\nDifference of %ld days\n",days);
}

int dateValidation(int dd, int mm, int yy){
        int valid = 1;
        if (yy > minYear && yy < maxYear){
            if(mm >= minMonth && mm <=maxMonth)
           
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

    while (1) {
        printf("Input Date1  =>  (DD/MM/YY): ");
        scanf("%d/%d/%d", &dd1, &mm1, &yy1);
        
        if(dateValidation(dd1, mm1, yy1)==1){
            break;
        }
        else{
            fprintf(stderr, "[ERROR] Enter Date Again!\n");
     
        }
    }

    while (1) {
        printf("Input Date1  =>  (DD-MM-YY): ");
        scanf("%d-%d-%d", &dd2, &mm2, &yy2);
        if(dateValidation(dd2, mm2, yy2)==1){
            break;
        }
        else{
            fprintf(stderr, "[ERROR] Enter Date Again!\n");
     
        }
    }

    
    Difference(dd1, dd2, mm1, mm2, yy1, yy2);
    
    return 0;
}
