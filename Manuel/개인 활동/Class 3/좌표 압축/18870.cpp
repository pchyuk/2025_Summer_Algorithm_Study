#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N; // 좌표 개수 N
    vector<int> original_coords(N); // 원본 좌표가 저장될 벡터
    vector<int> sorted_coords(N); // 정렬, 중복 제거된 좌표가 저장될 벡터

    for(int i = 0; i < N; i++)
    {
        cin >> original_coords[i]; // 원본 좌표 입력받음
        sorted_coords[i] = original_coords[i]; // 정렬할 벡터로 복사
    }

    // 1. 중복 좌표 제거
    sort(sorted_coords.begin(), sorted_coords.end()); // 벡터 정렬
    sorted_coords.erase(
        unique(sorted_coords.begin(), sorted_coords.end()),
        sorted_coords.end()
    ); // 실제 벡터의 크기는 줄어들지 않으므로, erase 사용

    // 2. 새로운 값 매핑 및 출력
    for(int i = 0; i < N; i++)
    {
        // original_coords[i]가 sorted_coords에서 몇 번째에 위치하는지 찾기
        // lower_bound는 정렬된 범위에서 특정 값 이상인 첫 번째 원소의 iterator를 반환
        auto iterator = lower_bound(sorted_coords.begin(), sorted_coords.end(), original_coords[i]);
        // iterator에서 begin()을 빼면 해당 원소의 인덱스를 구할 수 있음
        cout << (iterator - sorted_coords.begin()) << " ";
    }
    cout << endl;

    return 0;
}