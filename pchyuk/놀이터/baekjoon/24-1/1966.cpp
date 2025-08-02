#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int T, N, M, n;
    cin >> T;

    while (T--){
        queue<pair<int, int>> q;
        pair<int, int> val;
        priority_queue<pair<int,int>> pq;
        cin >> N >> M;

        if (M <= 1) M = 1;

        for (int i = 0; i < N; ++i){
            cin >> n;
            q.push({ n, i + 1 });
            pq.push({n, i + 1});

            if (i == M - 1) val = { n, i + 1 };
        }

        pair<int, int> imp = pq.top();
        int index = 0;

        while (true){
            q.push(q.front());
            q.pop();
            if (q.front() == imp) break;
        }

        while (!q.empty()){
            index++;
            if (q.front() == val){
                cout << index << "\n";
                break;
            }
            q.pop();
        }
    }
}