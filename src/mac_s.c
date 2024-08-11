#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "This is a test string.";
    const char delimiters[] = " ";
    char *token;
    char *context = NULL; // 用于存储 strtok_s 的上下文

    // 初始化 strtok_s
    token = strtok_s(str, delimiters, &context);

    // 循环获取所有 token
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok_s(NULL, delimiters, &context); // 后续调用使用 NULL 作为第一个参数
    }

    return 0;
}