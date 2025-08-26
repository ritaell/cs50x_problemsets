/*
INSTRUCTIONS--------------------------------------------------------------------------------------------------------------
In a file called mario.c in a folder called mario-more, implement a program in C that recreates that pyramid, using hashes (#) for bricks, as in the below:

   #  #
  ##  ##
 ###  ###
####  ####
And let’s allow the user to decide just how tall the pyramids should be by first prompting them for a positive int between, say, 1 and 8, inclusive.

Examples
Here’s how the program might work if the user inputs 8 when prompted:

$ ./mario
Height: 8
       #  #
      ##  ##
     ###  ###
    ####  ####
   #####  #####
  ######  ######
 #######  #######
########  ########

Here’s how the program might work if the user inputs 4 when prompted:

$ ./mario
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
Here’s how the program might work if the user inputs 2 when prompted:

$ ./mario
Height: 2
 #  #
##  ##
And here’s how the program might work if the user inputs 1 when prompted:

$ ./mario
Height: 1
#  #
If the user doesn’t, in fact, input a positive integer between 1 and 8, inclusive, when prompted, the program should re-prompt the user until they cooperate:

$ ./mario
Height: -1
Height: 0
Height: 42
Height: 50
Height: 4
   #  #
  ##  ##
 ###  ###
####  ####
Notice that width of the “gap” between adjacent pyramids is equal to the width of two hashes, irrespective of the pyramids’ heights.

*/


#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    do {
      height=get_int("Height: ");
    }while(height<=0);

    for (int i=1; i<=height; i++){
        for (int x=height-i; x!=0; --x){
            printf(" ");
        }
        for (int j=1; j<=i; j++){
            printf("#");
        }
        printf("  ");
        for (int j=1; j<=i; j++){
            printf("#");
        }
        printf("\n");
    }
}
