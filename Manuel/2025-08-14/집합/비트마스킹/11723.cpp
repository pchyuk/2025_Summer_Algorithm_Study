#include <iostream>
#include <string>
#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> m;
    /*
    비트마스크 정수. int는 32비트로, 1부터 20까지의 숫자를 비트로 표현하기에 충분함
    각 비트는 해당 index + 1의 원소 존재 여부를 나타냄
    ex) 5번 비트가 1이면 집합에 5가 있다는 뜻
    */
    int bitmask = 0;

    while(m--)
    {
        string command;
        cin >> command;

        if(command == "add")
        {
            int x;
            cin >> x;
            /*
            (1 << x)는 x - 1번째 비트(0부터 시작)를 1로 만듦
                ex) x = 3일 때 (1 << 3)은 000...01000이 됨
                000...01000과 x를 OR 연산하여 x번째 비트를 1로 만듦
            */
            bitmask |= (1 << x);
        }
        else if(command == "remove")
        {
            int x;
            cin >> x;
            /*
            (1 << x)를 비트 반전하면 x번째 비트만 0이 되고 나머지는 1이 됨
            이 값을 AND 연산하면 x번째 비트가 0이 됨
            */
            bitmask &= ~(1 << x);
        }
        else if(command == "check")
        {
            int x;
            cin >> x;
            /*
            비트마스크와 (1 << x)를 AND 연산했을 때 0이 아닌 값이 나오면(해당 비트가 1이면)
            x가 집합에 존재한다는 의미
            */
            if(bitmask & (1 << x))
            {
            cout << 1 << endl;
            }
           else
            {
                cout << 0 << endl;
            }
        }
        else if(command == "toggle")
        {
            int x;
            cin >> x;
            /*
            집합에 x가 있으면 제거, 없으면 추가하기
            비트마스크와 (1 << x)를 XOR(^) 연산하여 x번째 비트의 값을 반전시킴
            */
            bitmask ^= (1 << x);
        }
        else if(command == "all")
        {
            /*
            'all'은 집합을 1부터 20까지의 원소로 채우는 연산
            (1 << 21)은 21번째 비트만 1이고 나머지는 0인 값
            여기서 1을 빼면 1부터 20번째 비트가 모두 1이 됨
            */
            bitmask = (1 << 21) - 1;
        }
        else if(command == "empty")
        {
            // 집합을 비움: 모든 비트가 0
            bitmask = 0;
        }
    }

    return 0;
}