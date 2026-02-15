#include <stdio.h>
#include <string.h>

// 같은 글자는 똑같은 다른 글자로 바껴야 한다(예: 단어의 모든 a는 c로)
// 서로 다른 글자는 같은 글자로 갈 수 없다(예: a -> c, b -> c가 될 수 없다)
int similar(char *a, char *b) {
    char m1[26] = {0};  // 첫번째 단어에서 두번째 단어로 가면서 비교 
    char m2[26] = {0};  // 두번째 단어에서 첫번째 단어로 가면서 비교

    for (int i = 0; a[i]; i++) {
        int x = a[i] - 'a'; //무슨 알파벳인지
        int y = b[i] - 'a';

        if (m1[x] == 0 && m2[y] == 0) {
            m1[x] = b[i];
            m2[y] = a[i];
        }
        // 같은 글자가 똑같은 다른 글자로 안바뀔 경우
        else if (m1[x] != b[i] || m2[y] != a[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int N;
    scanf("%d", &N);

    char word[100][501];

    for (int i = 0; i < N; i++)
        scanf("%s", word[i]);

    int count = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (similar(word[i], word[j]))
                count++;
        }
    }

    printf("%d\n", count);
    return 0;
}
