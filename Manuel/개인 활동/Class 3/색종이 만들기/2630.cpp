#include <iostream>
#define endl "\n"

using namespace std;

const int MAX = 128;

int board[MAX][MAX];

int white_count = 0;
int blue_count = 0;

bool check_colour(int row, int col, int size)
{
    int standard_colour = board[row][col];
    for(int i = row; i < row + size; i++)
    {
        for(int j = col; j < col + size; j++)
        {
            if(board[i][j] != standard_colour)
            {
                return false;
            }
        }
    }
    return true;
}

void solve(int row, int col, int size)
{
    if(check_colour(row, col, size))
    {
        if(board[row][col] == 0)
        {
            white_count++;
        }
        else
        {
            blue_count++;
        }
        return;
    }
    int new_size = size / 2;
    solve(row, col, new_size);
    solve(row, col + new_size, new_size);
    solve(row + new_size, col, new_size);
    solve(row + new_size, col + new_size, new_size);
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
            cin >> board[i][j];
        }
    }
    
    solve(0, 0, N);
    
    cout << white_count << endl;
    cout << blue_count << endl;

    return 0;
}