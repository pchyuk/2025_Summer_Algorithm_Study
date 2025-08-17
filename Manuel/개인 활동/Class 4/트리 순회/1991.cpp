#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

// 트리를 저장할 구조체 배열
// first는 왼쪽 자식, second는 오른쪽 자식, '.'은 자식이 없음을 의미
pair<char, char> tree[26];

// 전위 순회: 루트 -> 왼쪽 -> 오른쪽
void preorder(char node)
{
    if(node == '.')
    {
        return;
    }
    cout << node;
    // ex) node가 'B'일 때 'B' - 'A'는 66 - 65이므로 1. tree[1]에 접근하는 것과 같음
    // 이 트리는 항상 'A'가 루트 노드가 되므로 'A'를 뺴면 됨
    preorder(tree[node - 'A'].first);
    preorder(tree[node - 'A'].second);
}

// 중위 순회: 왼쪽 -> 루트 -> 오른쪽
void inorder(char node)
{
    if(node == '.')
    {
        return;
    }
    inorder(tree[node - 'A'].first);
    cout << node;
    inorder(tree[node - 'A'].second);
}

// 후위 순회: 왼쪽 -> 오른쪽 -> 루트
void postorder(char node)
{
    if(node == '.')
    {
        return;
    }
    postorder(tree[node - 'A'].first);
    postorder(tree[node - 'A'].second);
    cout << node;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        char root, left, right;
        cin >> root >> left >> right;
        tree[root - 'A'] = {left, right};
    }

    preorder('A');
    cout << endl;
    inorder('A');
    cout << endl;
    postorder('A');
    cout << endl;

    return 0;
}