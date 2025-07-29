#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string num_str;

    while(true)
    {
        cin >> num_str;
        
        if(num_str == "0")
            break;
        
        string reversed_num_str = num_str;
        reverse(reversed_num_str.begin(), reversed_num_str.end());

        if(num_str == reversed_num_str)
            cout << "yes\n";
        else
            cout << "no\n";
    }
    
    return 0;
}