#include <bits/stdc++.h>

#define MAXLEN 100001
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))


using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;


const int N = 3;
int board[N][N];
int x = 1, y = 1;
int mnb = INT_MAX, mxb = INT_MIN;


int win() {
    bool win = false;
    bool loose = false;

    int sumr, sumc;
    for (int i = 0; !win && i < N; i++) {
        sumr = sumc = 0;
        for (int j = 0; j < N; j++) {
            sumr += board[i][j];
            sumc += board[j][i];
        }
        win = win || (sumr == N) || (sumc == N);
        loose = loose || (sumr == -N) || (sumc == -N);
    }

    sumr = sumc = 0;
    for (int i = 0; i < N; i++) {
        sumr += board[i][i];
        sumc += board[i][N-i-1];
    }
    win = win || (sumr == N) || (sumc == N);
    loose = loose || (sumr == -N) || (sumc == -N);

    return (win ? 1 : (loose ? -1 : 0));    
}

int MIN(int l);
int MAX(int l);


int MIN(int l) {
    int f = 1, mn = INT_MAX, tmp;

    if (win() != 0) return win();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                f = 0;

                board[i][j] = -1;

                tmp = MAX(l+1);
                if (tmp < mn) {
                    mn = tmp;
                    if (l == 0)
                        x = i, y =  j;
                }

                board[i][j] = 0;
            }
        }
    }

    return (f ? win() : mn);
}


int MAX(int l) {
    int f = 1, mx = INT_MIN, tmp;

    if (win() != 0) return win();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0) {
                f = 0;

                board[i][j] = 1;

                tmp = MIN(l+1);
                if (tmp > mx) {
                    mx = tmp;
                    if (l == 0) 
                        x = i, y = j;
                }
                
                board[i][j] = 0;
            }
        }
    }

    return (f ? win() : mx);
}


void printboard() {
    cout << '\n';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            switch (board[i][j]) {
                case -1:
                    cout << "O ";
                    break;
                case 0:
                    cout << "  ";
                    break;
                case 1:
                    cout << "X ";
                    break;
            }
            if (j != N-1)
                cout << "| " ;
        }
        cout << "\n----------\n";
    }
    cout << '\n';
}

int main() {
    memset(&board, 0, sizeof(board));

    cout << "FIRST TURN[0/1]:- ";
    bool t;
    cin >> t;

    int a, b;
    printboard();
    for (int i = 0; i < 9; i++) {
        if (win() != 0) break;

        if (i % 2 != t) {
            cout << "YOUR MOVE:- ";
            cin >> a >> b;
            board[a][b] = -1;
        } else {
            MAX(0);
            board[x][y] = 1;
        }

        printboard();
    }

    switch (win())
    {
    case 1:
        cout << "YOU LOOSE\n";
        break;
    case 0:
        cout << "ITS A DRAW\n";
        break;
    case -1:
        cout << "YOU WIN\n";
        break;
    }

    return 0;
}
