#include<stdio.h>
#include<string.h>

void converttotemp(char* temp) {
    int hour, min;
    float tempu;
    char new[3];
   
    sscanf(temp, "%d:%d-%f%s", &hour, &min, &tempu, new);

    if (strcmp(new, "F") == 0) {
        tempu = (tempu - 32) * 5.0 / 9.0;
        printf("%02d:%02d-%.1f, %.1f\n", hour, min, (tempu * 9.0 / 5.0) + 32, tempu);
    } else if (strcmp(new, "C") == 0) {
        tempu = (tempu * 9.0 / 5.0) + 32;
        printf("%02d:%02d-%.1f, %.1f\n", hour, min, (tempu - 32) * 5.0 / 9.0, tempu);
    }
}

int main() {
    char input[] = "08:30-22.5F, 12:15-25.0C, 15:45-24.8F";
    char *token = strtok(input, ", ");
 
    while (token != NULL) {
        converttotemp(token);
        token = strtok(NULL, ", ");
    }
 
    return 0;
}
