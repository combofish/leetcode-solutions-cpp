#include <icecream.hpp>
#include <stdio.h>
#include <string.h>
int main() {

    char sentance[100] = "helo the a the";
    // fgets(sentance, sizeof(sentance), stdin);


    sentance[strcspn(sentance, "\n")] = '\0';

    int sz = strlen(sentance);
    char word[20] = {0};
    memset(word, 0, sizeof(word));

    int idx = 0;
    int cnt = 0;

    for (int i = 0; i < sz; ++i) {
        if (sentance[i] == ' ' || sentance[i] == ',' || sentance[i] == '.') {
            IC(word);

            if (word[0] == 't' && word[1] == 'h' && word[2] == 'e' && word[3] == '\0') {
                ++cnt;
            }

            idx = 0;
            memset(word, 0, sizeof(word));
        } else {

            word[idx++] = sentance[i];
        }
    }

    if (word[0] == 't' && word[1] == 'h' && word[2] == 'e' && word[3] == '\0') {
        ++cnt;
    }
    memset(word, 0, sizeof(word));


    printf("%s\n", sentance);
    printf("%d\n", cnt);

    return 0;
}