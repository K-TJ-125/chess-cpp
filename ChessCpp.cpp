#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// 보드 클래스 (말 없이, 기본 틀만 구현)
class Board {
private:
    string squares[8][8];  // 말 대신 문자열로 저장 (기호, 빈칸 등)
public:
    Board() {
        // 전부 빈칸으로 초기화
        for (int r = 0; r < 8; r++)
            for (int c = 0; c < 8; c++)
                squares[r][c] = "   ";
    }

    bool isInside(int r, int c) const {
        return (r >= 0 && r < 8 && c >= 0 && c < 8);
    }

    // ------------------------------
    // 초기 말 위치를 단순 문자로 표시 (말 구현 X)
    void setupInitialPosition() {
        // 1~8행을 간단히 "B" / "W"로만 표현
        for (int c = 0; c < 8; c++) {
            squares[1][c] = " B ";  // 블랙 진영의 앞줄
            squares[6][c] = " W ";  // 화이트 진영의 앞줄
        }
        // 가장 바깥줄에는 간단히 R/N/B/Q/K 표시
        squares[0][0] = squares[0][7] = "RB ";
        squares[7][0] = squares[7][7] = "RW ";
        squares[0][1] = squares[0][6] = "NB ";
        squares[7][1] = squares[7][6] = "NW ";
        squares[0][2] = squares[0][5] = "BB ";
        squares[7][2] = squares[7][5] = "BW ";
        squares[0][3] = "QB ";
        squares[7][3] = "QW ";
        squares[0][4] = "KB ";
        squares[7][4] = "KW ";
    }

    // ------------------------------
    // 말 이동 (심플하게 문자열만 이동)
    void movePiece(int fromR, int fromC, int toR, int toC) {
        if (!isInside(fromR, fromC) || !isInside(toR, toC)) return;
        if (squares[fromR][fromC] == "   ") return; // 빈칸이면 이동 불가

        squares[toR][toC] = squares[fromR][fromC];
        squares[fromR][fromC] = "   ";
    }

    // ------------------------------
    // 보드 출력
    void draw() const {
        cout << setw(5)
            << "a" << setw(5)
            << "b" << setw(5)
            << "c" << setw(5)
            << "d" << setw(5)
            << "e" << setw(5)
            << "f" << setw(5)
            << "g" << setw(5)
            << "h" << setw(5) << "\n";
        for (int r = 0; r < 8; r++) {
            cout << 8 - r << " ";
            for (int c = 0; c < 8; c++) {
                cout << "[" << squares[r][c] << "]";
            }
            cout << " " << 8 - r << "\n";
        }
        cout << setw(5) 
            << "a" << setw(5)
            << "b" << setw(5)
            << "c" << setw(5)
            << "d" << setw(5)
            << "e" << setw(5)
            << "f" << setw(5)
            << "g" << setw(5)
            << "h" << setw(5) << "\n";
    }
};

// 메인 함수
int main() {
    Board board;
    board.setupInitialPosition();

    cout << "=== 체스 보드 초기 상태 ===\n";
    board.draw();

    return 0;
}

