#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
void clearScreen();//清除螢幕
void showScream();//展示螢幕風格

void cleaScreen(){
    system("CLS||clear");
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
    int error=0,pw;
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
                        printf("輸入一個n(5~10)的整數:");
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



