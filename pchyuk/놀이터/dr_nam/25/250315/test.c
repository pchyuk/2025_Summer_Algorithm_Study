#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *inputFile, *outputFile;
    char buffer[256];

    // 입력 파일을 읽기 모드로 엽니다.
    inputFile = fopen("test.txt", "r");
    if (inputFile == NULL) {
        perror("입력 파일을 여는 중 오류 발생");
        return EXIT_FAILURE;
    }

    // 출력 파일을 쓰기 모드로 엽니다.
    outputFile = fopen("test2.txt", "w");
    if (outputFile == NULL) {
        perror("출력 파일을 여는 중 오류 발생");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    // 입력 파일에서 각 줄을 읽어와서 출력 파일에 씁니다.
    while (fgets(buffer, sizeof(buffer), inputFile) != NULL) {
        char *result;
        result = strtok(buffer, " ");
        while (result != NULL) {
            // 콘솔에 단어를 출력합니다.
            printf("%s\n", result);

            // 출력 파일에 단어를 씁니다.
            fputs(result, outputFile);
            fputs("\n", outputFile);

            result = strtok(NULL, " ");
        }
    }

    // 파일을 닫습니다.
    fclose(inputFile);
    fclose(outputFile);

    return EXIT_SUCCESS;
}