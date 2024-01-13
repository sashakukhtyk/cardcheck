//Takes the card number and says if your card is valid VISA, MASTERCARD OR AMEX 
#include <stdio.h>
#include <math.h>

int main(void)
{
    //ask for input
    long int cardNum;
    do
    {
        printf("Type your card number : ");
        scanf("%li", &cardNum);
    }
    while((log10(cardNum) + 1) < 13 || cardNum < 0 );
    
    int digitcount = log10(cardNum) + 1;
    long int originalCardNum = cardNum;
    
    // Sum the digits
        int sum = 0;
        int digit = 0;
        int is_second_digit = 0; // Flag to track if the current digit is the second-to-last

        while (cardNum > 0)
        {
            digit = cardNum % 10;

            if (is_second_digit)
            {
                digit *= 2;

                // Add the products’ digits together if the result is more than 9
                if (digit > 9)
                {
                    digit = digit % 10 + digit / 10;
                }
            }

            sum += digit;

            // Move to the next digit
            cardNum /= 10;
            is_second_digit = !is_second_digit;
        }
        
    // Check if sum last digit == 0
        if(sum%10 == 0)
        {
            //check for length and starting digits
            if (digitcount == 13 && originalCardNum / 1000000000000 % 10 == 4)
            {
                printf("VISA\n");
            }
            if (digitcount == 16 && originalCardNum / 1000000000000000 % 10 == 4)
            {
                printf("VISA\n");
            }
            if (digitcount == 16 && originalCardNum / 1000000000000000 % 10 == 5)
            {
                if(originalCardNum / 100000000000000 % 10 == 1 
                || originalCardNum / 100000000000000 % 10 == 2 
                || originalCardNum / 100000000000000 % 10 == 3 
                || originalCardNum / 100000000000000 % 10 == 4 
                || originalCardNum / 100000000000000 % 10 == 5)
                {
                    printf("MASTERCARD\n");
                }
            }
            if (digitcount == 15 && originalCardNum / 100000000000000 % 10 == 3)
            {
                if(originalCardNum / 10000000000000 % 10 == 4 
                || originalCardNum / 10000000000000 % 10 == 7)
                {
                    printf("AMEX\n");
                }
            }
        }
        else
        {
            printf("INVALID\n");
        }
}