#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
//清除螢幕指令
void clearScreen() {
    system("CLS||clear");//CLS是windows clear是linux
}

int main(void){
    int pw,error=0,i,j,k,n; // pw是密碼 error是錯誤次數,n是整數 在B階段
    char ch;

    do{
        printf("口口口口口口口口\n");
        printf("輸入密碼:");
        scanf("%d", &pw); // 輸入密碼

        if(error==2) {
            printf("ERROR!\n");
            ch=getchar(); // 看到此訊息再關掉
            error=0; // 錯誤計數
            break; // END
        } // 連續錯三次

        if(pw!=2023){
            error++;
            printf("錯誤密碼%d\n", pw);
        } 
        else{
            char q;
            char con;//continous
            do{
                clearScreen(); // 清除螢幕
                printf("口口口口口口口口\n");
                printf("a. 畫出直角三角形\n");
                printf("b. 顯示乘法表\n");
                printf("c. 結束\n");
                printf("口口口口口口口口\n");
                printf("輸入選項\n");
                scanf(" %c",&q); // 注意空格，換行符號

                getchar(); 

                if(q=='a'||q=='A'){
                    printf("輸入一個'a'到'n'的字元\n");
                    int rows;
                    char an;
                    scanf(" %c", &an); // 輸入a~n字元
                    getchar(); 
                    if(an>='a'&&an<='n'){
                        rows=an-'a';
                        //得到行數
                        for(i=0;i<=rows;i++){
                            for(j=0;j<rows-i;j++){
                                printf(" ");//空格
                            }
                            for(k=0;k<=i;k++){
                                printf("%c",'a'+k);//字元
                            }
                            printf("\n");//換行
                        }
                        getchar();
                        printf("任意鍵繼續");
                        getch();
                        clearScreen();
                    } 
                    else{
                        printf("\nERROR!請重新輸入\n");
                        getchar();
                    }
                }
                if(q=='b'||q=='B'){
                    printf("輸入一個1至9的整數n:");
                    scanf("%d", &n);
                    getchar();
                    if(n>0&&n<10){
                        for(i=1;i<n+1;i++){
                            for(j=1;j<n+1;j++){
                            printf("%dx%d=%d\t",i,j,i*j);//乘法表
                            }
                        printf("\n");
                        }
                        getchar();
                        printf("任意鍵繼續");
                        getch();
                        clearScreen();
                    }
                    else{
                        printf("\nERROR!請重新輸入\n");
                        getchar();
                    }
                }
                if(q=='c'||q=='C'){//結束
                    printf("Continue? (y/n)");
                    scanf(" %c",&con);
                    getchar(); 
                    if(con=='N'||con=='n'){
                        return 0;
                    }
                    else if(con=='Y'||con=='y'){
                        getchar();
                        printf("任意鍵繼續");
                        getch();
                        clearScreen();
                    }
                    else{
                        printf("\nERROR!請重新輸入\n");
                        getchar();
                    }
                }
            } while (1);
        } // 密碼正確
    } while (1);
    return 0;
}


