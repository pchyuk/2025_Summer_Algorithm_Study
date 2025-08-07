#include <iostream>
#include <cmath>
#define endl "\n"
using namespace std;

long long visit_order = 0;

// n: 2^n * 2^n 배열의 크기
// r, c: 찾고자 하는 배열의 좌표
void solve(int n, int r, int c)
{
    if(n == 0)
        return;
    
    int half = pow(2, n - 1);
    long long area = (long long)half * half; // 각 사분면의 넓이

    // 왼쪽 위 사분면에 r, c가 속하는 경우:
    if(r < half && c < half)
    {
        solve(n - 1, r, c);
    }
    // 오른쪽 위 사분면에 속하는 경우:
    else if(r < half && c >= half)
    {
        visit_order += area;
        solve(n - 1, r, c - half);
    }
    // 왼쪽 아래:
    else if(r >= half && c < half)
    {
        visit_order += 2 * area;
        solve(n - 1, r - half, c);
    }
    // 오른쪽 아래:
    else
    {
        visit_order += 3 * area;
        solve(n - 1, r - half, c - half);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, r, c;
    cin >> N >> r >> c;
    
    solve(N, r, c);

    cout << visit_order << endl;
    
    return 0;
}