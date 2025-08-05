#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

class MinHeap
{
private:
    vector<int> heap;
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int left(int i)
    {
        return 2 * i + 1;
    }
    int right(int i)
    {
        return 2 * i + 2;
    }

    void heapifyUp(int i)
    {
        while(i > 0 && heap[parent(i)] > heap[i])
        {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }
    void heapifyDown(int i)
    {
        int smallest = i;
        int l = left(i);
        int r = right(i);

        if(l < heap.size() && heap[l] < heap[smallest])
        {
            smallest = l;
        }
        if(r < heap.size() && heap[r] < heap[smallest])
        {
            smallest = r;
        }
        if(smallest != i)
        {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }
public:
    void push(int val)
    {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }
    int top()
    {
        if(heap.empty())
        {
            return 0;
        }
        return heap.front();
    }
    void pop()
    {
        if(heap.empty())
        {
            return;
        }
        swap(heap.front(), heap.back());
        heap.pop_back();
        heapifyDown(0);
    }
    bool empty()
    {
        return heap.empty();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    MinHeap min_heap;

    for(int i = 0; i < N; i++)
    {
        int x;
        cin >> x;

        if(x == 0)
        {
            if(min_heap.empty())
            {
                cout << 0 << endl;
            }
            else
            {
                cout << min_heap.top() << endl;
                min_heap.pop();
            }
        }
        else
        {
            min_heap.push(x);
        }
    }
    return 0;
}