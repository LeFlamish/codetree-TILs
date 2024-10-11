#include <iostream>
#include <cstdlib>
#include <climits>
#include <cstring>
using namespace std;

struct Human {
	int x;
	int y;
	int total;
	bool isOut;
};

struct Square {
	int x;
	int y;
	int side;
};

int N, M, K, ret;
int exitX, exitY;
int board[11][11];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
bool isHuman[11][11];
Human man[11];
Square S;
int tmpMap[11][11];
int exitCnt;

void check() {
	cout << "====================\n";
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (isHuman[y][x]) cout << "H ";
			else cout << board[y][x] << ' ';
		}
		cout << '\n';
	}
	cout << "--------------------\n";
	for (int y = 0; y < S.side; y++) {
		for (int x = 0; x < S.side; x++) {
			cout << tmpMap[y][x] << ' ';
		}
		cout << '\n';
	}
	cout << "--------------------\n";
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (isHuman[y][x]) cout << "1 ";
			else cout << "0 ";
		}
		cout << '\n';
	}
	cout << "--------------------\n";
	cout << "출구 : " << exitX << ", " << exitY << '\n';
	cout << "--------------------\n";
	for (int m = 1; m <= M; m++) {
		cout << m << "번 사람 : " << man[m].x << ", " << man[m].y << '\n';
		if (man[m].isOut) cout << m << "번 사람 탈출\n";
	}
	cout << "====================\n";
}

bool isArea(int nx, int ny) {
	return !(nx < 1 || nx > N || ny < 1 || ny > N);
}

void init() {
	cin >> N >> M >> K;
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			cin >> board[y][x];
		}
	}
	for (int m = 1; m <= M; m++) {
		cin >> man[m].y >> man[m].x;
		isHuman[man[m].y][man[m].x] = true;
	}
	cin >> exitY >> exitX;
	board[exitY][exitX] = -1;
}

void findSquare() {
	int X = -1, Y = -1;
	int dirX = -1, dirY = -1;
	int MinD = INT_MAX;
	int side = 0;
	for (int m = 1; m <= M; m++) {
		if (man[m].isOut) continue;
		int gapX = man[m].x - exitX;
		int gapY = man[m].y - exitY;
		int dist = abs(gapX) + abs(gapY);
		X = man[m].x;
		Y = man[m].y;
		if (gapX <= 0) dirX = -1;
		else dirX = 1;
		if (gapY <= 0) dirY = -1;
		else dirY = 1;
		if (min(exitX + dirX * side, exitX) < 1) dirX *= -1;
		if (min(exitY + dirY * side, exitY) < 1) dirY *= -1;
		side = max(abs(gapX), abs(gapY));
		if (MinD > dist) {
			S.x = min(exitX + dirX * side, exitX);
			S.y = min(exitY + dirY * side, exitY);
			S.side = side + 1;
			MinD = dist;
		}
		else if (MinD == dist) {
			int tmpX = exitX + dirX * side;
			int tmpY = exitY + dirY * side;
			if (S.y > tmpY) {
				S.x = min(tmpX, exitX);
				S.y = min(tmpY, exitY);
			}
			else if (S.y == tmpY) {
				if (S.x > tmpX) {
					S.x = min(tmpX, exitX);
					S.y = min(tmpY, exitY);
				}
			}
		}
		if (S.x < 1) S.x = 1;
		else if (S.x + S.side - 1 > N) S.x -= S.x + S.side - 1 - N;
		if (S.y < 1) S.y = 1;
		else if (S.y + S.side - 1 > N) S.y -= S.y + S.side - 1 - N;
	}
	//cout << "회전 대상 정사각형\n";
	//cout << S.x << ' ' << S.y << ' ' << S.side << '\n';
}

void setIsHuman() {
	memset(isHuman, false, sizeof(isHuman));
	for (int m = 1; m <= M; m++) {
		if (man[m].isOut) continue;
		isHuman[man[m].y][man[m].x] = true;
	}
}

void rotation() {
	for (int x = 0; x < S.side; x++) {
		for (int y = 0; y < S.side; y++) {
			if (board[S.y + S.side - 1 - y][S.x + x] == -1) tmpMap[x][y] = -1;
			else tmpMap[x][y] = max(board[S.y + S.side - 1 - y][S.x + x] - 1, 0);
			if (isHuman[S.y + S.side - 1 - y][S.x + x]) {
				for (int m = 1; m <= M; m++) {
					if (man[m].x == S.x + x && man[m].y == S.y + S.side - 1 - y) {
						isHuman[S.y + S.side - 1 - y][S.x + x] = false;
						man[m].x = S.x + y;
						man[m].y = S.y + x;
					}
				}
			}
		}
	}
	for (int y = 0; y < S.side; y++) {
		for (int x = 0; x < S.side; x++) {
			board[S.y + y][S.x + x] = tmpMap[y][x];
			if (board[S.y + y][S.x + x] == -1) {
				exitX = S.x + x;
				exitY = S.y + y;
			}
		}
	}
	setIsHuman();
}

void moveHuman() {
	for (int m = 1; m <= M; m++) {
		if (man[m].isOut) continue;
		int dist = abs(man[m].x - exitX) + abs(man[m].y - exitY);
		int tmpDir = -1;
		for (int dir = 0; dir < 4; dir++) {
			int nx = man[m].x + dx[dir];
			int ny = man[m].y + dy[dir];
			if (!isArea(nx, ny)) continue;
			if (board[ny][nx] > 0) continue;
			if (board[ny][nx] == -1) {
				man[m].total++;
				man[m].isOut = true;
				exitCnt++;
				break;
			}
			int tmp = abs(nx - exitX) + abs(ny - exitY);
			if (dist >= tmp) {
				tmpDir = dir;
				dist = tmp;
			}
		}
		if (tmpDir != -1) {
			man[m].x += dx[tmpDir];
			man[m].y += dy[tmpDir];
			man[m].total++;
		}
	}
	setIsHuman();
}

void solve(int T) {
	for (int t = 1; t <= T; t++) {
		if (exitCnt == M) break;
		moveHuman();
		//cout << t << "초 사람 이동 후\n";
		//check();
		findSquare();
		rotation();
		//cout << t << "초 회전 후\n";
		//check();
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	init();
	solve(K);
	for (int m = 1; m <= M; m++) {
		ret += man[m].total;
	}
	cout << ret << '\n' << exitY << ' ' << exitX;
	return 0;
}