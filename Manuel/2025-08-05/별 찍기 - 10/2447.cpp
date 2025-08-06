#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

const int MAX_N = 2500;
char board[MAX_N][MAX_N];

// x, y: 상단 시작 좌표
// n: 현재 패턴의 크기
void draw_star(int x, int y, int n)
{
    if(n == 3)
    {
        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                if(i == 1 && j == 1)
                {
                    board[x + i][y + j] = ' ';
                }
                else
                {
                    board[x + i][y + j] = '*';
                }
            }
        }
        return;
    }

    int new_n = n / 3;
    
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(i == 1 && j == 1)
            {
                for(int row = x + i * new_n; row < x + (i + 1) * new_n; row++)
                {
                    for(int col = y + j * new_n; col < y + (j + 1) * new_n; col++)
                    {
                        board[row][col] = ' ';
                    }
                }
            }
            else
            {
                draw_star(x + i * new_n, y + j * new_n, new_n);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            board[i][j] = ' ';
        }
    }

    draw_star(0, 0, N);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }

    return 0;
}