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
bool seat_reserved[9][9] = {false}; //儲存座位預訂情況的數組

void clearScreen() {
    system("CLS||clear");
}

void u_wantseat() {
    watch_seat();
    int row, col;
    printf("\n選擇你想要的座位:");
    do {
        scanf("%d-%d", &row, &col);
        if (row < 1 || row > 9 || col < 1 || col > 9) {
            printf("\n格式錯誤，重新輸入:");
        }
        else if (sit[row - 1][col - 1] == '@' || sit[row - 1][col - 1] == '*') {
            printf("\n該座位已被預訂，請重新輸入:");
        }
        else if(sit[row - 1][col - 1] == '-') {
            sit[row - 1][col - 1] = '@';
            seat_reserved[row - 1][col - 1] = true; // 標記座位為已預訂
            watch_seat();
            printf("\n確認無誤?(y/n)\n");
            like();
            getchar(); 
            clearScreen();
            break;
        }
        else{
            printf("不要再亂打了");
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
    else {// 清除當前座位安排
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
    printf("座位情况：\n");
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
    printf("座位情况：\n");
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
    seat(); // 清除座位並重新分配座位
    int i, j, k, l;
    int need, startRow, startCol;
    printf("需要幾個座位（1~4）?\n");
    scanf("%d", &need);
    if (need > 0 && need < 4) {
        startRow = rand() % (9 - need + 1);
        startCol = rand() % 9;
        for (i = 0; i < need; i++) {
            sit[startRow + i][startCol] = '@';
            seat_reserved[startRow + i][startCol] = true; // 標記座位為已預訂
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
                seat_reserved[startRow][startCol + i] = true; // 標記座位為已預訂
            }
        } else {
            startRow = rand() % 8;
            startCol = rand() % 8;
            for (i = 0; i < 2; i++) {
                sit[startRow][startCol + i] = '@';
                sit[startRow + 1][startCol + i] = '@';
                seat_reserved[startRow][startCol + i] = true; // 標記座位為已預訂
                seat_reserved[startRow + 1][startCol + i] = true; // 標記座位為已預訂
            }
        }
    }
    else {
        printf("你是不是SB?\n");
        return;
    }
    watch_seat2(); // 顯示預訂座位
}


int main(void) {
    int pw, error = 0;

    seat(); // 初始化座位表

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

    printf("輸入密碼");
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
                        watch_seat(); // 顯示座位表
                        printf("按任意键返回主菜單...\n");
                        getchar();
                        getchar();
                        clearScreen();
                        break;
                    case 'b':
                        want_seat();
                        printf("\n你喜歡嗎?(y/n)\n");
                        like();
                        printf("按任意键返回主菜单...\n");
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
                        printf("有問題嗎?叫你選a b c d其中一個選項 你給我選什麼東西?\n");
                        getchar();
                        getchar();
                        clearScreen();
                }
            } while (R != 'q');
        }
        else if (pw != 2024) {
            error++;
            if (error < 3) {
                printf("\n輸入錯誤，重新輸入\n");
            }
            else {
                printf("錯誤三次達上限");
                getchar();
                break;
            }
        }
    }

    return 0;
}
//心得: 怎麼那麼難，要連續，還要儲存預定座位。
