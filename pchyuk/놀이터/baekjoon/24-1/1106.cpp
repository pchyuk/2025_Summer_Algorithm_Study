#include <iostream>
using namespace std;

typedef struct {
    double cost;
    double customer;
    double ratio;
} Hotel;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    Hotel hotel[20];
    int c, n;
    cin >> c >> n;
    for(int i=0; i<n; i++){
        cin >> hotel[i].cost >> hotel[i].customer;
        hotel[i].ratio = hotel[i].customer / hotel[i].cost;
    }

    
    return 0;
}