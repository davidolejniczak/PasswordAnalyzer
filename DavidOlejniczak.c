#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int hasLowercase(char x[],int len) {
int i;
for (i=0;i<len;i++){
    if (x[i] > 96 && x[i] < 123){
        return 1 ; 
    }
}
}

int hasUppercase(char x[], int len){
int i; 
for (i=0;i<len;i++) {
    if(x[i] > 64 && x[i] < 91) {
        return 1; 
    }
}
}

int hasDigit(char x[], int len){
int i; 
for (i=0;i<len;i++) {
    if(x[i] > 47 && x[i] < 58) {
        return 1; 
    }
}
}

int hasSpecialChar(char x[], int len){
int i; 
for (i=0;i<len;i++){
    if (x[i] == 33 || x[i] > 34 && x[i] < 38 || x[i] > 39 && x[i] < 43 || x[i] == 64 || x[i] == 94){
    return 1; 
    }
}
}

const char* eveluateStrength(int src){
if (src <= 2) {
    return "Weak"; }
else if (src == 3 || src ==4) {
    return "Moderate";}
else {
    return "Strong";}
}

int main() {
char path;
char lastscore[20];
char password[500];
while (1){
    printf("\n");
    printf("Password Resilience Analyzer\n");
    printf("A: Test a password\n");
    printf("B: View strength of last tested password\n");
    printf("C: Exit program\n");
    printf("Enter your choice:\n");
    scanf("%s",&path);  
    switch(path) {
        case 'A':
            printf("Enter your password\n");
            scanf("%s",password);
            while (strlen(password) < 8) {
                printf("Error\n");
                printf("Password must be longer then 8 characters re-enter a longer password\n");
                scanf("%s",&password);
            }
            int score = 0; 
            char word[15];
            int length = strlen(password);
            if (length > 11) {
                score++;}
            if (hasLowercase(password,length) == 1) {
                score++;}
            if (hasUppercase(password,length) == 1) {
                score++;}
            if (hasDigit(password,length) == 1) {
                score++;}
            if (hasSpecialChar(password,length) == 1) {
                score++;} 
            printf("Password Strength: %s\n",eveluateStrength(score));
            strcpy(lastscore,eveluateStrength(score));
            break;
        case 'B':
            printf("You chose Option 2.\n");
            printf("Lasted tested password strength: %s\n",lastscore);
            break;
        case 'C':
            printf("You chose Option 3.\n");
	  printf("Exiting...\n");
            printf("Bye Bye\n");
            return 0; 
        default:
            printf("Letter not valid, enter a valid choice.\n");
    }
}
}



