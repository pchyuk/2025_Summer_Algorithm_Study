#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int m,n,sum=0, flag=0, min=0;
    cin >> m >> n;
    for(int i=m; i<=n; i++){
        for(int j=1; j<=i; j++){
            if(j*j==i){
                sum+=i;
                if(flag==0){
                    flag=1;
                    min=i;
                }
            }
        }
    }
    if(sum==0) cout << "-1\n";
    else cout << sum << "\n" << min << "\n";
    return 0;
}