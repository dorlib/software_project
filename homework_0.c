#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int num = 0;
int source = 0;
int target = 0;
int result = 0;

int i = 0;
int sum = 0;

int charDigitConverter(char c){
    if(c >= '0' && c <= '9') {
        return c - '0';
    } else if(c >= 'a' && c <= 'z') {
        return c - 'a' + 10;
    } else {
        return -1;
    }
}


int reverse(){
    char c;

    if((c = getchar()) != '\n'){
        reverse();
        sum += charDigitConverter(c) * pow(target,i);
        i++;
    }

    return 0;
}

int main(){
    printf("enter the source base: \n");
    scanf("%d", &source);
    if(source < 2 || source > 16) {
        fprintf(stderr, "Invalid source base!\n");
        exit(EXIT_FAILURE);
   }

    printf("enter the target base: \n");
    scanf("%d", &target);
    if(target < 2 || target > 16) {
        fprintf(stderr, "Invalid target base!\n");
        exit(EXIT_FAILURE);
   }

    printf("Enter the number: ");
    scanf("%d", &num);

    result = reverse();
    printf("The number in base %d is: %d", target, sum);

    return 0;
}
