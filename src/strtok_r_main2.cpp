#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "This is a test string.";
    const char delimiters[] = " ";
    char *token;
    char *saveptr;

    // 初始化 strtok_r
    token = strtok_r(str, delimiters, &saveptr);

    // 循环获取所有 token
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok_r(NULL, delimiters, &saveptr);
    }

    return 0;
}