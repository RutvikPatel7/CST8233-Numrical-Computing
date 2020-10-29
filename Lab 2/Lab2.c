#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int main() {

    long long binary;
    int decimal;
    long long conBin = 0;
    int conDec, i, left, step;
    while (1)
    {
        int userInput;
        printf("1- Convert Binary to Decimal \n");
        printf("2- Convert Decimal to Binary\n");
        printf("3- Quit\n");
        printf("Please choose an option: ");
        scanf("%d", &userInput);

        switch (userInput) {
        case 1:
            conDec = 0;
            i = 0;
            printf("Enter Binary Number:");
            scanf("%lld", &binary);
            while (binary != 0) {
                left = binary % 10;
                binary /= 10;
                conDec += left * pow(2, i);
                ++i;
            }
            printf("binary to decimal is: %d\n", conDec);

            break;
        case 2:
            i = 1;
            step = 1;
            printf("Enter Decimal Number:");
            scanf("%d", &decimal);
            while (decimal != 0) {
                left = decimal % 2;
                decimal /= 2;
                conBin = conBin + (left * i);
                i *= 10;
            }
            printf("decimal to binary = %lld\n", conBin);
            break;
        case 3:
            printf("thank you!!!");
            exit(0);

            break;
        }
    }
    return 0;

}

