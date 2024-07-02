#include <iostream>
using namespace std;

int Y, M, D;

bool isLeapYear(int Y) {
    if (Y % 4) return false;
    else {
        if (!(Y % 100) && Y % 400) return false;
        else return true;
    }
}

bool isValidDate(int Y, int M, int D) {
    if (M < 1 || M > 12 || D < 1 || D > 31) return false;
    if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12) return true;
    else {
        if (M == 2) {
            if (isLeapYear(Y)) {
                if (D > 29) return false;
                else return true;
            }
            else {
                if (D > 28) return false;
                else return true;
            }
        }
        else {
            if (D > 30) return false;
            else return true;
        }
    }
}

void checkSeason(int Y, int M, int D) {
    if (isValidDate(Y, M, D)) {
        if (M >= 3 && M <= 5) cout << "Spring";
        else if (M >= 6 && M <= 8) cout << "Summer";
        else if (M >= 9 && M <= 11) cout << "Fall";
        else cout << "Winter";
    }
    else cout << -1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> Y >> M >> D;
    checkSeason(Y, M, D);
    return 0;
}