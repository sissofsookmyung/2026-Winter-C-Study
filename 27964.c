#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0; //토핑 개수 입력 받아

    char toppings[100][100];    //토핑 목록 이차원 배열
    char cheeses[100][101]; //그 중 치즈 토핑 목록 이차원 배열
    int count = 0;  //치즈 토핑 개수

    for (int i = 0; i < n; i++) {
        scanf("%s", toppings[i]);   //토핑 입력 받아

        int len = strlen(toppings[i]);  //토핑 배열 길이
        if (len >= 6 && strcmp(&toppings[i][len - 6], "Cheese") == 0) { //입력 받은 토핑 이름 끝이 Cheese로 끝나면
            
            bool is_new= false; //중복 구별 변수 초기화
            for (int j = 0; j < count; j++) {
                if (strcmp(cheeses[j], toppings[i]) == 0) { //Cheese로 끝나기는 하지만 이미 치즈 목록에 있던 치즈면
                    is_new = true;  //중복임 
                    break;
                }
            }

            if (!is_new) {
                strcpy(cheeses[count], toppings[i]);
                count++;
            }
        }
    }

    if (count >= 4) {
        printf("yummy\n");
    } else {
        printf("sad\n");
    }

    return 0;
}