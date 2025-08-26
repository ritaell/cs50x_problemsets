/*
INSTRUCTIONS---------------------------------------------------------------------------------------------------------------------
Problem to Solve
A credit (or debit) card, of course, is a plastic card with which you can pay for goods and services. Printed on that card is a number that’s also stored in a database somewhere, so that when your card is used to buy something, the creditor knows whom to bill. There are a lot of people with credit cards in this world, so those numbers are pretty long: American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers. And those are decimal numbers (0 through 9), not binary, which means, for instance, that American Express could print as many as 10^15 = 1,000,000,000,000,000 unique cards! (That’s, um, a quadrillion.)

Actually, that’s a bit of an exaggeration, because credit card numbers actually have some structure to them. All American Express numbers start with 34 or 37; most MasterCard numbers start with 51, 52, 53, 54, or 55 (they also have some other potential starting numbers which we won’t concern ourselves with for this problem); and all Visa numbers start with 4. But credit card numbers also have a “checksum” built into them, a mathematical relationship between at least one number and others. That checksum enables computers (or humans who like math) to detect typos (e.g., transpositions), if not fraudulent numbers, without having to query a database, which can be slow. Of course, a dishonest mathematician could certainly craft a fake number that nonetheless respects the mathematical constraint, so a database lookup is still necessary for more rigorous checks.

In a file called credit.c in a folder called credit, implement a program in C that checks the validity of a given credit card number.

Luhn’s Algorithm
So what’s the secret formula? Well, most cards use an algorithm invented by Hans Peter Luhn of IBM. According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) valid as follows:

Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
Add the sum to the sum of the digits that weren’t multiplied by 2.
If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
That’s kind of confusing, so let’s try an example with David’s Visa: 4003600000000014.

For the sake of discussion, let’s first underline every other digit, starting with the number’s second-to-last digit:

4003600000000014

Okay, let’s multiply each of the underlined digits by 2:

1•2 + 0•2 + 0•2 + 0•2 + 0•2 + 6•2 + 0•2 + 4•2

That gives us:

2 + 0 + 0 + 0 + 0 + 12 + 0 + 8

Now let’s add those products’ digits (i.e., not the products themselves) together:

2 + 0 + 0 + 0 + 0 + 1 + 2 + 0 + 8 = 13

Now let’s add that sum (13) to the sum of the digits that weren’t multiplied by 2 (starting from the end):

13 + 4 + 0 + 0 + 0 + 0 + 0 + 3 + 0 = 20

Yup, the last digit in that sum (20) is a 0, so David’s card is legit!

So, validating credit card numbers isn’t hard, but it does get a bit tedious by hand. Let’s write a program.
*/

#include <stdio.h>
#include <cs50.h>

int len(char n[]);
bool isnum(char n[]);

int len(char n[]){
    int x=0;
    for(int i=0;n[i]!='\0';i++){
        x++;
    }
    return x;
}



bool isnum(char n[]){
    for (int i=0; i<len(n); i++){
        if ((n[i] >= 'a' && n[i] <= 'z') || (n[i] >= 'A' && n[i] <= 'Z')){
            return false;
        }
    }
    return true;
}

bool isvalid(char n[]){
    int x=0;
    int y=0;
    int r=0;
    for (int i=len(n)-2; i>=0; i-=2){
        char c = n[i];
        int d = c - '0';
        d*=2;
        if (d>9){
            d=d/10+d%10;
        }
        x+=d;
    }
    for (int i=len(n)-1; i>=0; i-=2){
        char f = n[i];
        int s = f - '0';
        y+=s;
    }
    r=x+y;

    if (r%10==0){
        return true;
    }
    else{
        return false;
    }
}


int main(void){
    char str[20];
    long int num;
    do{
      num=get_long("Number: ");
      snprintf(str,sizeof(str),"%li",num);
    }while(!isnum(str));


    if (isvalid(str)) {


    if ((str[0]=='3' && (str[1]=='4' || str[1]=='7')) && (len(str) == 15)) {
        printf("AMEX\n");
    }
    else if ((str[0]=='5' && (str[1]=='1' || str[1]=='2' || str[1]=='3' || str[1]=='4' || str[1]=='5')) && (len(str) == 16)) {
        printf("MASTERCARD\n");
    }
    else if ((str[0]=='4') && (len(str) == 13 || len(str) == 16)) {
        printf("VISA\n");
    }
    else {
        printf("INVALID\n");
    }

}
else {
    printf("INVALID\n");
}



}
