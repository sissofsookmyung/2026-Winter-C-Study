#include <stdio.h>

int main() {
    int N;
    char friends[55][55];
    int max_2_friends = 0;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%s", friends[i]);
    }


    for (int i = 0; i < N; i++) {
        int count = 0;
        for (int j = 0; j < N; j++) {
            if (i == j)continue;
            int is_2_friend = 0;
            if (friends[i][j] == 'Y') {
                is_2_friend = 1;

            }
            else {
                for (int k = 0; k < N; k++) {
                    if (friends[i][k] == 'Y' && friends[k][j] == 'Y') {
                        is_2_friend = 1;
                        break;
                    }
                }
            }
            if (is_2_friend == 1) {
                count++;
            }
        }
        if (count > max_2_friends) {
            max_2_friends = count;
        }
    }
    printf("%d\n", max_2_friends);
    return 0;


}
/*문제 설명
모든 사람(i)을 for 반복문으로 한 명씩 불러와서, 다른 모든 사람(j)와의 관계를 찔러본다.
직접 알면 넘어가고, 모르면 중간에 아는 사람(k)가 있는지 확인한다.
그렇게 순 숫자가 지금까지 중 최고라면 max_2_friends에 기록하고 마지막에 최고기록만 알려준다
*/