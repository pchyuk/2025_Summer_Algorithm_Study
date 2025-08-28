/*
    시계, 반시계를 묻는 문제
    벡터의 외적을 쉽게 떠올릴 수 있다.
*/
#include <iostream>
using namespace std;

struct Point {
    long long x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Point p[3], v[2]; // 점 3개와 벡터 2개를 저장

    for (int i = 0; i < 3; i++) { // 점 3개 입력받기
        cin >> p[i].x >> p[i].y;
    }

    // 벡터 2개 구하기
    // v1 = p2 - p1, v2 = p3 - p2
    for (int i = 0; i < 2; i++) {
        v[i].x = p[i + 1].x - p[i].x;
        v[i].y = p[i + 1].y - p[i].y;
    }
    
    // 2차원 벡터((a, b), (c, d))의 외적은 ad - bc
    // 여기서 두 벡터는 (v[0].x, v[0].y), (v[1].x, v[1].y)
    long long cross_product_z = v[0].x * v[1].y - v[0].y * v[1].x;

    // 2차원 벡터의 외적의 z좌표가 양수이면 반시계, 음수이면 시계, 0이면 일직선
    if (cross_product_z > 0) cout << '1';
    else if (cross_product_z < 0) cout << "-1";
    else cout << '0';
    
    return 0;
}