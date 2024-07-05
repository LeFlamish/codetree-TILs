#include <iostream>
#include <string>
using namespace std;
string code;
char place;
int Time;

class Secret {
    public:
        string code;
        char place;
        int Time;

        Secret(string code, char place, int Time) {
            this->code = code;
            this->place = place;
            this->Time = Time;
        }
};

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> code >> place >> Time;
    Secret secret1 = Secret(code, place, Time);
    cout << "secret code : " << secret1.code << '\n';
    cout << "meeting point : " << secret1.place << '\n';
    cout << "time : " << secret1.Time;
    return 0;
}