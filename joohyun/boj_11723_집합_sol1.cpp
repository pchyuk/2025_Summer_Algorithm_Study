/*
    크기가 0인 정수형 벡터를 이용하여 구현한다.
    명령어를 입력받으면 맞는 함수를 실행시킨다.
    all, empty, add는 main함수에서 직접 실행하고
    check, remove, toggle은 함수를 만든다.
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int check(const vector<int>& s, int x);
void remove(vector<int>& s, int x);
void toggle(vector<int>& s, int x);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string op;
    vector<int> s;
    int m, x;

    cin >> m;
    while (m--) {
        cin >> op;
        if (op == "add") {
            cin >> x;
            if (!check(s, x)) s.push_back(x);
        }
        else if (op == "remove") {
            cin >> x;
            remove(s, x);
        }
        else if (op == "check") {
            cin >> x;
            cout << check(s, x) << '\n';
        }
        else if (op == "toggle") {
            cin >> x;
            toggle(s, x);
        }
        else if (op == "all") {
            s.clear();
            for (int i = 1; i <= 20; ++i) {
                s.push_back(i);
            }
        }
        else if (op == "empty") {
            s.clear();
        }
    }

    return 0;
}

// 벡터를 처음부터 검사해서 x가 있으면 1을 반환
int check(const vector<int>& s, int x) {
    for (int a : s) {
        if (a == x) return 1;
    }
    return 0;
}

// 벡터의 처음부터 x가 있는지 검사해서 있으면 제거 후 종료
void remove(vector<int>& s, int x) {
    for (auto it = s.begin(); it != s.end(); ++it) {
        if (*it == x) {
            s.erase(it);
            break;
        }
    }
}

// x를 check하고 있으면 x를 remove, 없으면 추가
void toggle(vector<int>& s, int x) {
    if (check(s, x)) remove(s, x);
    else s.push_back(x);
}