#include <stdio.h>
char B[8][9] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

char W[8][9] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

char board[51][51];

int main(){
    int row, col;
    int min = 64;
    int b, w;
    scanf("%d %d", &row, &col);

    for(int i=0; i < row; i++){
        scanf("%s", board[i]);
    }

    for(int i=0; i < row - 7; i++){
        for(int j=0; j < col - 7; j++){
            b = 0;
            w = 0;
            for(int x=i; x < i + 8; x++){
                for(int y=j; y < j + 8; y++){
                    if(board[x][y] != B[x-i][y-j]) b++;
                    if(board[x][y] != W[x-i][y-j]) w++;
                }
            }
            if(min > b) min = b;
            if(min > w) min = w;
        }
    }
    printf("%d\n", min);
    return 0;
}
