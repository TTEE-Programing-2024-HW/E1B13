#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX_STUDENTS 10
#define MIN_STUDENTS 5
// 學生結構
struct student {
    char name[50];
    int id;
    int math;
    int physics;
    int english;
};
// 函數宣告
void clearScreen(); // 清除螢幕
void showScream(); // 展示螢幕風格
void clearInputBuffer(); // 清除多餘字符
void printStudentInfo(struct student); // 展示學生資料
void sortStudentsByAverage(struct student students[], int n); // 高低分數分類

// 按平均成績高低順序分類學生
void sortStudentsByAverage(struct student students[], int n) {
    // 使用冒泡排序來排序學生數組
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // 按平均成績比較學生
            float average1 = (students[j].math + students[j].physics + students[j].english) / 3.0;
            float average2 = (students[j + 1].math + students[j + 1].physics + students[j + 1].english) / 3.0;
            if (average1 < average2) {
                // 如果平均成績較小，則交換學生位置
                struct student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}


// 展示學生資訊
void printStudentInfo(struct student student) {
    float average = (student.math + student.physics + student.english) / 3.0;
    printf("姓名: %s\n", student.name);
    printf("學號: %d\n", student.id);
    printf("數學成績: %d\n", student.math);
    printf("物理成績: %d\n", student.physics);
    printf("英文成績: %d\n", student.english);
    printf("平均成績: %.1f\n", average);
}

// 按平均成績高低順序列出的學生信息
void printSortedStudents(struct student students[], int n) {
    printf("\n按平均成績高低順序列出的學生信息：\n");
    for (int i = 0; i < n; i++) {
        printStudentInfo(students[i]);
        printf("\n");
    }
}



// 清除螢幕
void clearScreen() {
    system("CLS||clear");
}

// 清除多餘字符
void clearInputBuffer() {
    while (getchar() != '\n');
}

// 展示螢幕風格
void showScream() {
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

int main() {
    showScream();
    int error = 0, pw, n;
    struct student students[MAX_STUDENTS];
    printf("輸入密碼: ");
    while (error < 3) {
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
                        // 獲取學生資訊
                        printf("輸入n(5~10");
                        while(1){
                            scanf("%d",&n);
                            if(n>4&&n<11){
                                break;
                            }
                        }
                        
                        for (int i = 0; i < n; i++) {
                            printf("請輸入第%d位學生的姓名：\n", i + 1);
                            scanf("%s", students[i].name);

                            printf("請輸入第%d位學生的學號（6位整數）：\n", i + 1);
                            while (1) {
                                int id;
                                if (scanf("%d", &id) == 1 && id >= 100000 && id <= 999999) {
                                    students[i].id = id;
                                    break;
                                } else {
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
                                                printf("按任意鍵返回主菜單...\n");
                        getchar();
                        getchar();
                        clearScreen();
                        break;
                    case 'b':
                        clearScreen();
                        printf("所有學生信息\n");
                        for (int i = 0; i < n; i++) {
                            printStudentInfo(students[i]);
                        }
                        printf("按任意鍵返回主菜單...\n");
                        getchar();
                        getchar();
                        clearScreen();
                        break;
                    case 'c':
                        clearScreen();
                        char searchName[50];
                        printf("請輸入要搜尋的姓名：\n");
                        scanf("%s", searchName);
                        clearInputBuffer();
                        int found = 0;
                        for (int i = 0; i < n; i++) {
                            if (strcmp(students[i].name, searchName) == 0) {
                                printStudentInfo(students[i]);
                                found = 1;
                                break;
                            }
                        }
                        if (!found) {
                            printf("資料不存在。\n");
                        }
                        printf("按任意鍵返回主菜單...\n");
                        getchar();
                        getchar();
                        clearScreen();
                        break;
                    case 'd':
                        clearScreen();
                        sortStudentsByAverage(students, n);
                        printSortedStudents(students, n);
                        printf("按任意鍵返回主選單...\n");
                        getchar();
                        getchar();
                        break;
                    case 'e':
                        clearScreen();
                        while (1) {
                            printf("確定離開？ (y/n)\n");
                            char exitChoice;
                            scanf(" %c", &exitChoice);
                            clearInputBuffer();
                            if (exitChoice == 'y') {
                                return 0;
                            } else if (exitChoice == 'n') {
                                break;
                            } else {
                                printf("無效選項，請輸入 'y' 或 'n'。\n");
                            }
                        }
                        break;
                    default:
                        printf("有問題?\n");
                        getchar();
                        getchar();
                        clearScreen();
                }
            } while (R != 'q');
        } else if (pw != 2024) {
            error++;
            if (error < 3) {
                printf("\n輸入錯誤，重新輸入\n");
            } else {
                printf("錯誤三次達上限");
                getchar();
                break;
            }
        }
    }

    return 0;
}



