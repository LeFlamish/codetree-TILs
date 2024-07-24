#include <bits/stdc++.h>
using namespace std;

int N, ret;
string s;

bool isSubstringInOtherPart(const string& substr) {
    // `substr`이 문자열 `s`의 첫 부분에서 발견되면 안 됨
    size_t pos = s.find(substr);
    if (pos == string::npos || pos + substr.length() == s.size()) {
        return false; // `substr`이 문자열 끝 부분에서만 발견됨
    }

    // `substr`이 다른 위치에서도 발견되는지 확인
    while ((pos = s.find(substr, pos + 1)) != string::npos) {
        if (pos + substr.length() <= s.size()) {
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> s;

    ret = 0; // 최대 길이를 0으로 초기화

    for (int S = 0; S < s.size(); S++) {
        for (int E = S; E < s.size(); E++) {
            string tmp = s.substr(S, E - S + 1); // 부분 문자열 생성

            // 부분 문자열이 문자열의 다른 부분에서도 발견되는지 확인
            if (isSubstringInOtherPart(tmp)) {
                ret = max(ret, E - S + 1); // 가장 긴 부분 문자열 길이를 저장
            }
        }
    }

    cout << ret + 1;
    return 0;
}