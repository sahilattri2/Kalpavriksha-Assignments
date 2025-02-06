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
#include<string.h>
 
void convertto24hours(char*time){
    int hour,min;
    char ch[3];
   
    sscanf(time,"%d:%d %s",&hour,&min,ch);
 
    if(strcmp(ch,"pm")==0&& hour!=12){
        hour=hour+12;
    }
    else if (strcmp(ch, "am") == 0 && hour == 12){
        hour=0;
    }
    printf("%d:%d\n",hour,min);
 
}
int main() {
    char input[] = "10:30 am, 2:45 pm, 6:10 am, 12:00 am, 12:30 pm";
    char *token = strtok(input, ",");
 
    while (token != NULL) {
        convertto24hours(token);
        token = strtok(NULL, ",");
    }
 
    return 0;
}