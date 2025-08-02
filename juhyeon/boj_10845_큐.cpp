/* 명령어를 문자열로 입력받고 해당 명령어가 일치할 경우 조건문 실행 */
#include <iostream>
#include <string>
#include <queue> // 큐 헤더파일
using namespace std;

int main() {
    int n; // 명령어 개수
    string op; // 명령어 저장 문자열
    queue<int> q; // 정수 큐

    cin >> n;

    while(n--) {
        cin >> op; // 각 반복마다 명령어 입력받기
        if(op == "push") { // push x형태일 경우 x를 push
            int x;
            cin >> x;
            q.push(x);
        }
        else if(op == "pop") { // empty가 아니면 front 출력 후 pop (pop()은 리턴값이 없음)
            if (q.empty()) cout << -1 << endl;
            else {
                cout << q.front() << endl;
                q.pop();
            }
        }
        else if (op == "size") { // q.size() 출력
            cout << q.size() << endl;
        }
        else if (op == "empty") { // empty이면 1, 아니면 0
            cout << (q.empty() ? 1 : 0) << endl;
        }
        else if (op == "front") { // empty일 경우 -1, 아니면 front 출력
            cout << (q.empty() ? -1 : q.front()) << endl;
        }
        else if (op == "back") { // empty일 경우 -1, 아니면 back 출력
            cout << (q.empty() ? -1 : q.back()) << endl;
        }       
    }
}