#include <iostream>
#include <string>
#include <vector>
#define endl "\n"

using namespace std;

int checkSecret = 0;
vector<int> checkList(4);
vector<int> myList(4, 0);

void myadd(char c)
{
    switch(c)
    {
        case 'A':
            myList[0]++;
            if(myList[0] == checkList[0])
                checkSecret++;
            break;
        case 'C':
            myList[1]++;
            if(myList[1] == checkList[1])
                checkSecret++;
            break;
        case 'G':
            myList[2]++;
            if(myList[2] == checkList[2])
                checkSecret++;
            break;
        case 'T':
            myList[3]++;
            if(myList[3] == checkList[3])
                checkSecret++;
            break;
    }
}

void myremove(char c)
{
    switch(c)
    {
        case 'A':
            if(myList[0] == checkList[0])
                checkSecret--;
            myList[0]--;
            break;
        case 'C':
            if(myList[1] == checkList[1])
                checkSecret--;
            myList[1]--;
            break;
        case 'G':
            if(myList[2] == checkList[2])
                checkSecret--;
            myList[2]--;
            break;
        case 'T':
            if(myList[3] == checkList[3])
                checkSecret--;
            myList[3]--;
            break;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int S, P;
    cin >> S >> P;
    string A;
    cin >> A;

    for(int i = 0; i < 4; i++)
    {
        cin >> checkList[i];
    }
    
    int result = 0;

    for(int i = 0; i < 4; i++)
    {
        if(checkList[i] == 0)
        {
            checkSecret++;
        }
    }

    for(int i = 0; i < P; i++)
    {
        myadd(A[i]);
    }
    if(checkSecret == 4)
    {
        result++;
    }
    
    for(int i = P; i < S; i++)
    {
        int j = i - P;
        myadd(A[i]);
        myremove(A[j]);
        if(checkSecret == 4)
        {
            result++;
        }
    }
    
    cout << result << endl;

    return 0;
}