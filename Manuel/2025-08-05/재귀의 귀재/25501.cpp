#include <iostream>
#include <string>
#include <string.h>
#define endl "\n"

using namespace std;

int recursion(const char* s, int l, int r, int& call_count)
/*
    s: 문자열, l: 왼쪽 인덱스, r: 오른쪽 인덱스, call_count: 호출 횟수 (참조로 전달됨)
*/
{
    call_count++; // 호출되면 1씩 증가

    if(l >= r)
        return 1;
    else if(s[l] != s[r])
        return 0;
    else
    {
        return recursion(s, l + 1, r - 1, call_count);
    }
}

int isPalindrome(const char* s, int& call_count)
{
    call_count = 0;
    return recursion(s, 0, strlen(s) - 1, call_count);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        string S_std;
        cin >> S_std;
        
        const char *S = S_std.c_str(); // std::string을 const char*로 형 변환
        
        int call_count = 0;
        int is_Palindrome_Result = isPalindrome(S, call_count);

        cout << is_Palindrome_Result << " " << call_count << endl;
    }

    return 0;
}