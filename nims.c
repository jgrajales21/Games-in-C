#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int valid_pile(int pile0, int pile1, int pile2, int input_pile) {
    int i = 0;
    if (input_pile == 0) {
        if (pile0 == 0) { i = 0; }
        else if (pile0 > 0) { i = 1; }
    }
    else if (input_pile == 2) {
        if (pile2 == 0) { i = 0; }
        else if (pile2 > 0) {i = 1;}
    }
    else if (input_pile == 1) {
        if (pile1 == 0) {i = 0;}
        else if (pile1 > 0) {i = 1;}
    }
    return i;
}

int valid_stick(int pile, int input_s) {
    int i = 0;
    if (input_s > pile || input_s <= 0) { i = 0; }
    else if (input_s > 0 && input_s <= pile) { i =1; }
    return i;
}

int nim() {
    srand(time(NULL));
    int pile1, pile2, pile0;
    do {
        pile1 = rand()%11;
        pile2 = rand()%11;
        pile0 = rand()%11;
    }while(pile0 == 0 || pile1 == 0 || pile2 == 0);
    int input_p,input_s,user_input_p,user_input_s,comp_p,computer_s;


    printf("Pile 0: %d\n", pile0);
    printf("Pile 1: %d\n", pile1);
    printf("Pile 2: %d\n", pile2);

    int i = 0;

    do {
        i = i + 1;
        if (i%2 != 0) {
            do {
                printf("From which pile (0-2) do you you want to remove sticks? ");
                scanf(" %d", &user_input_p);


            }while (valid_pile(pile0,pile1,pile2,user_input_p) == 0);
            input_p = user_input_p;
        }
        else {
            srand(time(NULL));
            do {
                comp_p = rand()%4;
            } while(valid_pile(pile0,pile1,pile2,comp_p) != 1);
            input_p = comp_p;
        }



        if (input_p == 1) {
            if (i%2 != 0) {
                do{
                    printf("How many sticks (1-%d) do you want to remove? ",pile1);
                    scanf(" %d", &user_input_s);
                }while(valid_stick(pile1, user_input_s) != 1);
                input_s = user_input_s;
            }
            else {
                do {
                    computer_s = rand()%pile1+1;
                } while(valid_stick(pile1, computer_s) != 1);
                input_s = computer_s;
                printf("I choose to remove %d sticks from pile 1\n", input_s);
            }
            pile1 = pile1 - input_s;
        }
        else if (input_p == 2) {
            if (i%2 != 0) {
                do {
                    printf("How many sticks (1-%d) do you want to remove? ",pile2);
                    scanf(" %d", &user_input_s);
                }while(valid_stick(pile2, user_input_s) != 1);
                input_s = user_input_s;
            }
            else {
                do {
                    computer_s = rand()%pile2+1;
                } while(valid_stick(pile2, computer_s) != 1);
                input_s = computer_s;
                printf("I choose to remove %d sticks from pile 2\n", input_s);
            }
            pile2 = pile2 - input_s;
        }
        else if (input_p == 0) {
            if (i%2 != 0) {
                do {
                    printf("How many sticks (1-%d) do you want to remove? ", pile0);
                    scanf(" %d", &user_input_s);
                }while(valid_stick(pile0, user_input_s) != 1);
                input_s = user_input_s;
            }
            else {
                do{
                    computer_s = rand()%pile0+1;
                } while(valid_stick(pile0, computer_s) != 1) ;
                input_s = computer_s;
                printf("I choose to remove %d sticks from pile 0\n", input_s);
            }
            pile0 = pile0 - input_s;
        }
        printf("Pile 0: %d\n", pile0);
        printf("Pile 1: %d\n", pile1);
        printf("Pile 2: %d\n", pile2);
    } while (pile0 +pile1 + pile2 > 0);

    if (i%2 == 0) { printf("Oh no! I lose!\n"); }
    else { printf("You lose!\n"); }

    return 0;
}

int main(void) {

    nim();

    return 0;

}
