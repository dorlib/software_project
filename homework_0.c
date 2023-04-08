#include <stdio.h>
#include <math.h>

int i = 0;
int sum = 0;

int rem = 0;
int num = 0;
int targetBase = 0;
char c;

void reverse(int base) {
    char c;
    if((c = getchar()) != '\n') {
        reverse(base);
        if (c >= '0' && c <= '9') {
            num = c - '0';
        } else if (c >= 'a' && c <= 'f') {
            num = c - 'a' + 10;
        } else {
            printf("Invalid character: %c\n", c);
            return;
        }
        sum += num * pow(base, i);
        i++;
    }
    return;
}

void convertToBase(int num, int base) {
    if (num == 0) {
        return;
    } else {
        convertToBase(num / base, base);
        rem = num % base;
        if (rem < 10) {
            c = rem + '0';
        } else {
            c = rem - 10 + 'a';
        }
        putchar(c);
    }
}

int main(void) {
    int base;
    printf("Enter the source base (between 2 to 16): ");
    scanf("%d", &base);

    if (base < 2 || base > 16) {
        printf("Invalid base. Please enter a value between 2 to 16.\n");
        return 1;
    }

    printf("Enter the target base (between 2 to 16): ");
    scanf("%d", &targetBase);

    if (targetBase < 2 || targetBase > 16) {
        printf("Invalid target base. Please enter a value between 2 to 16.\n");
        return 1;
    }

    printf("Enter a number in base %d: ", base);
    getchar(); 
    reverse(base);

    printf("The number in base %d is: ", targetBase);
    convertToBase(sum, targetBase);
    printf("\n");

    return 0;
}
