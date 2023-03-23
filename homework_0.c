#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int quotient = 0;
int num = 0;
int source = 0;
int target = 0;
int decimal = 0;

int charToDigit(char c){
    if(c >= '0' && c <= '9') {
        return c - '0';
    } else if(c >= 'a' && c <= 'z') {
        return c - 'a' + 10;
    } else {
        return -1;
    }
}


int convertToDecimal(int num, int base){
    int decimal = 0, i = 0;
    while(num != 0){
        decimal += (num % 10) * pow(base, i);
        num /= 10;
        i++;
    }
    return decimal;
}

void convertToBase(int decimal, int base){
    if(decimal == 0){
        printf("0");
        return;
    }

    convertToBase(decimal / base, base);
    quotient = decimal % base;
    if(quotient < 10) {
        printf("%d", quotient);
    } else {
        printf("%c", quotient - 10 + 'A');
    }
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

    decimal = convertToDecimal(num, source);
    printf("The number in base %d is: ", target);

    convertToBase(decimal, target);
    printf("\n");

    return 0;
}
