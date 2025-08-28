/*
    https://www.acmicpc.net/problem/25501
    펠린드롭을 재귀를 이용하여 판별하고,
    리커전 함수의 호출 횟수를 카운트한다.
*/
#include <iostream>
#include <string>
using namespace std;

int recursion_count;

int recursion(const string& s, int l, int r) {
    recursion_count++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1);
}

int isPalindrome (const string& s) {
    return recursion(s, 0, s.size() - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    
    while (t--) {
        string s;
        cin >> s;

        recursion_count = 0;
        cout << isPalindrome(s) << ' ' << recursion_count << '\n';
    }

    return 0;
}