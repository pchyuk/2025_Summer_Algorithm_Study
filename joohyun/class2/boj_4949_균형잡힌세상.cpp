/* https://www.acmicpc.net/problem/4949
    "짝을 이루는 두 괄호가 있을 때, 그 사이에 있는 문자열도 균형이 잡혀야 한다."
    char형 스택으로 구현한다. 각 괄호를 만나면 푸쉬 팝을 하여 검사한다.
    다음은 안 되는 경우의 예시다.
    1. [주의] 괄호의 짝이 종류나 순서에 맞지 않는 경우 (예: (], ([)])
    2. 여는 괄호만 있고 닫는 괄호가 없는 경우 (예: ( ()
    3. 닫는 괄호가 더 많은 경우 (예: ()))
    문자열 입력은 getline(cin, string)을 이용한다.(cin은 공백에서 끊김)
*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while(true) {
        string sen;
        getline(cin, sen);
        if (sen == ".") break;

        stack<char> s;
        int len = sen.size();
        bool is_balanced = true;

        for (char c : sen) {
            if (c == '(' || c == '[') s.push(c);
            else if (c == ')') {
                if (s.empty() || s.top() == '[') {
                    is_balanced = false;
                    break;
                }
                else s.pop();
            }
            else if (c == ']') {
                if (s.empty() || s.top() == '(') {
                    is_balanced = false;
                    break;
                }
                else s.pop();
            }
        }
        if (!s.empty()) is_balanced = false;
        
        if (is_balanced) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}