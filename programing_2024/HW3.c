#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include <stdbool.h>

// 函數原型聲明
void clearScreen();
void u_wantseat();
void like();
void seat();
void watch_seat();
void want_seat();
void want_seat2();

char sit[9][9];
bool seat_reserved[9][9] = {false}; //save u want seat value

void clearScreen() {
    system("CLS||clear");
}

void u_wantseat() {
    watch_seat();
    int row, col;
    printf("\n u want seat:");
    do {
        scanf("%d-%d", &row, &col);
        if (row < 1 || row > 9 || col < 1 || col > 9) {
            printf("\nERROR:");
        }
        else if (sit[row - 1][col - 1] == '@' || sit[row - 1][col - 1] == '*') {
            printf("\nthe seat not space，try:");
        }
        else if(sit[row - 1][col - 1] == '-') {
            sit[row - 1][col - 1] = '@';
            seat_reserved[row - 1][col - 1] = true; // point u save seat
            watch_seat();
            printf("\nOK?(y/n)\n");
            like();
            getchar(); 
            clearScreen();
            break;
        }
        else{
            printf("dont do that");
        }
    } while (1);
}

void like() {
    char love;
    scanf(" %c", &love);
    if (love == 'y') {
        getchar();
        clearScreen();
    }
    else {// clear now seat
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    if (sit[i][j] == '@') {
                        sit[i][j] = '-';
                        seat_reserved[i][j] = false;
                    }
                }
            }
        
        getchar();
        clearScreen();
    }
}


void seat() {
    int i, j, k;
    srand(time(NULL));
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            sit[i][j] = '-';
        }
        k = rand() % 9;
        sit[i][k] = '*';
    }
}


void watch_seat() {
    int i, j;
    printf("now seat：\n");
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (seat_reserved[i][j]) {
                printf("*");
            } else {
                printf("%c", sit[i][j]);
            }
        }
        printf("\n");
    }
}

void watch_seat2() {
    int i, j;
    printf("now seat：\n");
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (seat_reserved[i][j]) {
                printf("@");
            } else {
                printf("%c", sit[i][j]);
            }
        }
        printf("\n");
    }
}


void want_seat() {
    seat(); // clear seat and re seat
    int i, j, k, l;
    int need, startRow, startCol;
    printf("how many seats（1~4）?\n");
    scanf("%d", &need);
    if (need > 0 && need < 4) {
        startRow = rand() % (9 - need + 1);
        startCol = rand() % 9;
        for (i = 0; i < need; i++) {
            sit[startRow + i][startCol] = '@';
            seat_reserved[startRow + i][startCol] = true; // point save seat
        }
    }
    else if (need == 4) {
        int choose;
        choose = rand() % 2;
        if (choose == 0) {
            startCol = rand() % 6;
            startRow = rand() % 9;
            for (i = 0; i < 4; i++) {
                sit[startRow][startCol + i] = '@';
                seat_reserved[startRow][startCol + i] = true; // point save seat
            }
        } else {
            startRow = rand() % 8;
            startCol = rand() % 8;
            for (i = 0; i < 2; i++) {
                sit[startRow][startCol + i] = '@';
                sit[startRow + 1][startCol + i] = '@';
                seat_reserved[startRow][startCol + i] = true; // point save seat
                seat_reserved[startRow + 1][startCol + i] = true; // point save seat
            }
        }
    }
    else {
        printf("are u sure?\n");
        return;
    }
    watch_seat2(); // show seat
}


int main(void) {
    int pw, error = 0;

    seat(); // re 0 seat

    printf("口口口口口口口口口口口口口口口口口口口口口\n");
    printf("E 1 B 1 3\n");
    printf("-----                          -----\n");
    printf("-----                          -----\n");
    printf("-----                          -----\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("                  / \"           ");
    printf("                 /   \"             ");
    printf("                /     \"                  ");
    printf("                -------               ");
    printf("                                         \n");
    printf("                /=====\"                   ");
    printf("               /=======\"                ");
    printf("                                          ");
    printf("                 -----                 ");
    printf("                 -----                 ");
    printf("                                      ");
    printf("                                     ");
    printf("                 -----               ");
    printf("\n");

    printf("password");
    while (error < 3) {
        printf(":");
        scanf("%d", &pw);
        if (pw == 2024) {
            clearScreen();
            char R;
            do {
                printf("----------[BookingSystem]----------  \n");
                printf("a. Available seats                 ||\n");
                printf("b. Arrange for you                 ||\n");
                printf("c. Choose by yourself              ||\n");
                printf("d. Exit                            ||\n");
                printf("|------------------------------------\n");
                getchar();
                scanf(" %c", &R);
                switch (R) {
                    case 'a':
                        watch_seat(); //show seat
                        printf("enter...\n");
                        getchar();
                        getchar();
                        clearScreen();
                        break;
                    case 'b':
                        want_seat();
                        printf("\nlike it?(y/n)\n");
                        like();
                        printf("enter...\n");
                        getchar();
                        getchar();
                        clearScreen();
                        break;
                    case 'c':
                        u_wantseat();
                        clearScreen();
                        break;
                    case 'd':
                        printf("Continue? (y/n)");
                        char end;
                        scanf(" %c", &end);
                        if (end == 'y') {
                            return 0;
                        }
                        clearScreen();
                        break;
                    default:
                        printf("what are u doing?\n");
                        getchar();
                        getchar();
                        clearScreen();
                }
            } while (R != 'q');
        }
        else if (pw != 2024) {
            error++;
            if (error < 3) {
                printf("\nworng\n");
            }
            else {
                printf("three error and END");
                getchar();
                break;
            }
        }
    }

    return 0;
}
//心得: 怎麼那麼難，要連續，還要儲存預定座位。
