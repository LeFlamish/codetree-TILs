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

// 코드트리 풀이
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
string str;

int main() {
    // 입력
    cin >> n;
    
    cin >> str;

    int ans = 1;

    // 1씩 늘려가면서 어느 길이까지 2번 등장하지는지 모두 시도해봅니다.
    for(int i = 1; i < n; i++) {
        // 모든 길이가 i인 부분 문자열에 대해 쌍을 짓고
        // 둘이 완전히 똑같은지 확인합니다.

        // twice : i 길이의 2회 이상 등장하는 부분 문자열이 존재하면 true
        bool twice = false;

        for(int j = 0; j <= n - i; j++) {
            for(int k = j + 1; k <= n - i; k++) {
                // issame : j부터 i길이의 부분 문자열과
                // k부터 i길이의 부분 문자열이 완전히 같으면 true
                bool issame = true;

                for(int l = 0; l < i; l++) {
                    if(str[j + l] != str[k + l])
                        issame = false;
                }

                if(issame) twice = true;
            }
        }

        if(twice)
            ans = i + 1;
        else
            break;
    }

    cout << ans;
    
    return 0;
}
