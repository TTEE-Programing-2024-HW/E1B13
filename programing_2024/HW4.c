#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX_STUDENTS 10
#define MIN_STUDENTS 5

void clearScreen();//清除螢幕
void showScream();//展示螢幕風格
void clearInputBuffer();//清除多餘字符

struct student {
    char name[50];
    int id;
    int math;
    int physics;
    int english;
} 

void cleaScreen(){
    system("CLS||clear");
}

void clearInputBuffer() {
    while (getchar() != '\n');
}

void showScream(){
    printf("口口口口口口口口口口口口口口口口口口口口口\n");
    printf("E 1 B 1 3\n");
    printf("WWWWW                          WWWWW\n");
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
    printf("                /WWWWW\"                   ");
    printf("               /WWWWWWW\"                ");
    printf("                                          ");
    printf("                 -----                 ");
    printf("                 -----                 ");
    printf("                                      ");
    printf("               c8 c8c c8 c8c c8c                       ");
    printf("                 -----               ");
    printf("\n");

}

int main()
{
    showScream();
    int error=0,pw,n;
    printf("輸入密碼");
    while (error < 3) {
        printf(":");
        scanf("%d", &pw);
        if (pw == 2024) {
            clearScreen();
            char R;
            do {
                printf("  ----------[Grade System]----------  \n");
                printf("a. Enter student grades             ||\n");
                printf("b. Display student grades           ||\n");
                printf("c. Search for student grades        ||\n");
                printf("d. Grade ranking                    ||\n");
                printf("e. Exit system                      ||\n");
                printf("|------------------------------------\n");
                getchar();
                scanf(" %c", &R);
                switch (R) {
                    case 'a':
                        clearScreen();
                        for (i = 0; i < n; i++) {
                            printf("請輸入第%d位學生的姓名：\n", i + 1);
                            scanf("%s", students[i].name);

                            printf("請輸入第%d位學生的學號（6位整數）：\n", i + 1);
                            while (1) {
                                    int id;
                                    if (scanf("%d", &id) == 1 && id >= 100000 && id <= 999999) {
                                        students[i].id = id;
                                        break;
                                    } 
                                    else {
                                        printf("輸入錯誤，請輸入一個6位整數：\n");
                                        clearInputBuffer();
                                    }
                                }

                            printf("請輸入第%d位學生的數學成績（0到100）：\n", i + 1);
                            while (1) {
                                int math;
                            if (scanf("%d", &math) == 1 && math >= 0 && math <= 100) {
                students[i].math = math;
                break;
            } else {
                printf("輸入錯誤，請輸入範圍內的數學成績（0到100）：\n");
                clearInputBuffer();
            }
        }

        printf("請輸入第%d位學生的物理成績（0到100）：\n", i + 1);
        while (1) {
            int physics;
            if (scanf("%d", &physics) == 1 && physics >= 0 && physics <= 100) {
                students[i].physics = physics;
                break;
            } else {
                printf("輸入錯誤，請輸入範圍內的物理成績（0到100）：\n");
                clearInputBuffer();
            }
        }

        printf("請輸入第%d位學生的英文成績（0到100）：\n", i + 1);
        while (1) {
            int english;
            if (scanf("%d", &english) == 1 && english >= 0 && english <= 100) {
                students[i].english = english;
                break;
            } else {
                printf("輸入錯誤，請輸入範圍內的英文成績（0到100）：\n");
                clearInputBuffer();
            }
        }
    }
                        printf("按任意键返回主菜單...\n");
                        getchar();
                        getchar();
                        clearScreen();
                        break;
                    case 'b':
                        
                       
                        
                        printf("按任意键返回主菜单...\n");
                        getchar();
                        getchar();
                        clearScreen();
                        break;
                    case 'c':
                       
                        break;
                    case 'd':
                        
                        clearScreen();
                        break;
                    default:
                        printf("有問題?\n");
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



