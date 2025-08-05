/*
    별찍기를 재귀로 푼다.
    2차원 char벡터를 선언하고 거기에 *을 찍고 한 번에 출력한다.
    n/3씩 나눠서 재귀로 하다가 n==1이 되면 *을 찍는다.
*/
#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> stars;

void draw_stars(int x, int y, int n);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    stars.assign(n, vector<char>(n, ' ')); // 공백으로 초기화

    draw_stars(0, 0, n); // 0, 0부터 재귀로 n칸짜리 별찍기 -> 2차원 벡터에 저장

    for (int i = 0; i < n; i++) { // 저장한 거 출력
        for (int j = 0; j < n; j++) {
            cout << stars[i][j];
        }
        cout << '\n';
    }

    return 0;
}

void draw_stars(int x, int y, int n) {
    if (n == 1) {
        stars[x][y] = '*';
        return;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) continue; // 가운데는 빈 공간
            draw_stars(x + i * n / 3, y + j * n / 3, n / 3); // 좌표 새로 설정, 사이즈 / 3 해서 재귀
        }
    }
}