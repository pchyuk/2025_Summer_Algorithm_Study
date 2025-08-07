#include <iostream>
#include <vector>
#include <numeric> // std::iota를 사용하기 위함
#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> input_notes(8); // 8개의 음을 저장할 벡터
    for(int i = 0; i < 8; i++)
    {
        cin >> input_notes[i]; // 8개의 음 입력받기
    }

    // ascending 기준 배열 생성
    vector<int> ascending_notes(8);
    iota(ascending_notes.begin(), ascending_notes.end(), 1); // 1부터 8까지 채움

    // descending 기준 배열 생성
    vector<int> descending_notes(8);
    iota(descending_notes.begin(), descending_notes.end(), 1); // 1부터 8까지 채우고 나서
    reverse(descending_notes.begin(), descending_notes.end()); // 뒤집기

    bool is_ascending = true;
    bool is_descending = true;

    // ascending인지 확인
    for(int i = 0; i < 8; i++)
    {
        if(input_notes[i] != ascending_notes[i])
        {
            is_ascending = false;
            break;
        }
    }
    // descending인지 확인
    if(!is_ascending)
    {
        for(int i = 0; i < 8; i++)
        {
            if(input_notes[i] != descending_notes[i])
            {
                is_descending = false;
                break;
            }
        }
    }

    // 결과 출력
    if(is_ascending)
    {
        cout << "ascending" << endl;
    }
    else if(is_descending)
    {
        cout << "descending" << endl;
    }
    else
    {
        cout << "mixed" << endl;
    }

    return 0;
}