#include <iostream>
#include <string>
#include <queue>

#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; // 명령의 수
    cin >> N;

    queue<int> q; // int 타입을 저장하는 큐 선언

    for(int i = 0; i < N; i++)
    {
        string op; // 명령어를 저장할 문자열
        cin >> op;

        if(op == "push")
        {
            int X;
            cin >> X;
            q.push(X); // 정수 X를 입력받고 큐에 넣기
        }
        else if(op == "pop")
        {
            if(q.empty()) // 큐가 비어 있는지 확인
            {
                cout << -1 << endl;
            }
            else
            {
                cout << q.front() << endl; // 맨 앞 요소 확인
                q.pop(); // 맨 앞 요소 제거
            }
        }
        else if(op == "size")
        {
            cout << q.size() << endl; // 큐 안의 정수 개수 출력
        }
        else if(op == "empty")
        {
            if(q.empty())
            {
                cout << 1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if(op == "front")
        // 큐의 가장 앞에 있는 정수 출력
        {
            if(q.empty()) // 큐가 비어있는지 확인
            {
                cout << -1 << endl;
            }
            else
            {
                cout << q.front() << endl; // 맨 앞 요소 확인 (제거는 하지 않음!)
            }
        }
        else if(op == "back")
        // 큐에 가장 뒤 정수 출력
        {
            if(q.empty()) // 큐가 비어있는지 확인
            {
                cout << -1 << endl;
            }
            else
            {
                cout << q.back() << endl; // 맨 뒤 요소 확인 (제거하지 않음)
            }
        }
    }

    return 0;
}