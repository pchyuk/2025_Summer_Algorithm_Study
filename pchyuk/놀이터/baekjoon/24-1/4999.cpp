#include <iostream>
#include <string>
using namespace std;
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int count1=0, count2=0;
    string jaehwan, doctor;
    cin >> jaehwan >> doctor;
    int len = jaehwan.length();
    for(int i=0; i<len-1; i++){
        if(jaehwan[i] == 'a') count1++;
    }
    
    len = doctor.length();
    for(int i=0; i<len-1; i++){
        if(doctor[i] == 'a') count2++;
    }

    if(count1 < count2) cout << "no\n";
    else cout << "go\n";
    return 0;
}