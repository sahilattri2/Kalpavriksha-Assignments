/*
A user enters a list of timestamps in the format "hh:mm am/pm" separated by commas (e.g., "10:30 am, 2:45 pm, 6:10 am").
 
Extracts the hour and minute from each timestamp and Converts it into 24-hour format.
 
INPUT :
 
"10:30 am, 2:45 pm, 6:10 am, 12:00 am, 12:30 pm"
 
OUTPUT:
 
10:30 am → 10:30
 
2:45 pm → 14:45
 
6:10 am → 06:10
 
12:00 am → 00:00
 
12:30 pm → 12:30
 
*/
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void convertfunction(int hr, int min, char period[])
{
    if(strcmp(period,"am")==0)
    {
        if(hr==12)
        {
            hr=0;
        }
        printf("%02d:%02d\n",hr,min);
    }
    else{
        if(hr!=12)
        {
            hr+=12;
        }
        printf("%02d:%02d\n",hr,min);
    }
}
int main()
{
    char str[100]="10:30 am, 2:45 pm, 6:10 am, 12:00 am, 12:30 pm";
    char *token=strtok(str,",");
    while (token !=NULL)
    {
        while(*token==' ')
        {
            token++;
        }
        int hr,min;
        char period[10];
        // printf("%s\n",token);
        if(sscanf(token,"%d:%d %s",&hr,&min,period)==3){
            printf("%s->",token);
            convertfunction(hr,min,period);
        }
        token=strtok(NULL,",");
    }
    

}