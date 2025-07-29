#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    queue<int> cards;
    for(int i = 1; i <= N; i++)
    {
        cards.push(i);
    }
    while(cards.size() > 1)
    {
        cards.pop();
        if(cards.empty())
            break;
        int top_card = cards.front();
        cards.pop();
        cards.push(top_card);
    }
    
    cout << cards.front() << "\n";

    return 0;
}