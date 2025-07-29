#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Member
{
    int age;
    string name;
    int original_index;
};

bool compareMembers(const Member& m1, const Member& m2)
{
    if(m1.age != m2.age)
    {
        return m1.age < m2.age;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<Member> members(N);

    for(int i = 0; i < N; i++)
    {
        cin >> members[i].age >> members[i].name;
        members[i].original_index = i;
    }

    stable_sort(members.begin(), members.end(), compareMembers);

    for(int i = 0; i < N; i++)
    {
        cout << members[i].age << " " << members[i].name << "\n";
    }
    
    return 0;
}