#include <iostream>
using namespace std;

void printStar() {
    for (int i = 0; i < 10; i++) {
        cout << '*';
    }
    cout << '\n';
}
int main() {
    for (int i = 0; i < 5; i++) printStar();
    return 0;
}