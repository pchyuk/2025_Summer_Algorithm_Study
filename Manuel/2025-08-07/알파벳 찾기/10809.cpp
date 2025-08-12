#include <iostream>
#include <string>
#include <vector>
#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s; // 단어 입력
    vector<int> result(26, -1); // 알파벳의 등장 위치를 저장할 벡터. 26개의 알파벳에 대해 -1로 초기화.
    
    // 단어를 순회하며 각 알파벳의 첫 등장 위치 기록
    for(int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        int index = c - 'a'; // 'a'를 0으로 세팅

        // 해당 알파벳이 아직 등장하지 않았다면
        if(result[index] == -1)
        {
            result[index] = i;
        }
    }

    for(int i = 0; i < 26; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}