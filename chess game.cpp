#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

/*
  ASCII Chess Board Layout Example:

      a   b   c   d   e   f   g   h
    +---+---+---+---+---+---+---+---+
  8 | r | n | b | q | k | b | n | r | 8
    +---+---+---+---+---+---+---+---+
  7 | p | p | p | p | p | p | p | p | 7
    +---+---+---+---+---+---+---+---+
  6 | . | . | . | . | . | . | . | . | 6
    +---+---+---+---+---+---+---+---+
  5 | . | . | . | . | . | . | . | . | 5
    +---+---+---+---+---+---+---+---+
  4 | . | . | . | . | . | . | . | . | 4
    +---+---+---+---+---+---+---+---+
  3 | . | . | . | . | . | . | . | . | 3
    +---+---+---+---+---+---+---+---+
  2 | P | P | P | P | P | P | P | P | 2
    +---+---+---+---+---+---+---+---+
  1 | R | N | B | Q | K | B | N | R | 1
    +---+---+---+---+---+---+---+---+
      a   b   c   d   e   f   g   h

  - White pieces: Uppercase (R, N, B, Q, K, P)
  - Black pieces: Lowercase (r, n, b, q, k, p)
*/

class ChessGame {
private:
    vector<vector<char>> board;
    bool whiteToMove; // true if it's White's turn, false if Black's turn

public:
    ChessGame() {
        // Standard chess opening position
        board = {
            {'r','n','b','q','k','b','n','r'},
            {'p','p','p','p','p','p','p','p'},
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.'},
            {'P','P','P','P','P','P','P','P'},
            {'R','N','B','Q','K','B','N','R'}
        };
        whiteToMove = true; // White starts
    }

    // Print the board in a neat ASCII layout
    void printBoard() {
        cout << endl << "    a   b   c   d   e   f   g   h" << endl;
        cout << "  +---+---+---+---+---+---+---+---+" << endl;
        for (int row = 0; row < 8; row++) {
            cout << (8 - row) << " | ";
            for (int col = 0; col < 8; col++) {
                cout << board[row][col] << " | ";
            }
            cout << (8 - row) << endl;
            cout << "  +---+---+---+---+---+---+---+---+" << endl;
        }
        cout << "    a   b   c   d   e   f   g   h" << endl << endl;
    }

    // Convert algebraic notation (e.g., 'e2' -> row,col) into board indices
    bool parseMove(const string& move, int &startRow, int &startCol, int &endRow, int &endCol) {
        // Expecting exactly 4 characters, e.g. e2e4
        // e2 -> file = 'e', rank = '2'
        // file 'a' -> col 0, rank '1' -> row 7
        // file 'h' -> col 7, rank '8' -> row 0
        if (move.size() != 4) return false;

        char file1 = move[0]; // 'e'
        char rank1 = move[1]; // '2'
        char file2 = move[2]; // 'e'
        char rank2 = move[3]; // '4'

        if (file1 < 'a' || file1 > 'h') return false;
        if (rank1 < '1' || rank1 > '8') return false;
        if (file2 < 'a' || file2 > 'h') return false;
        if (rank2 < '1' || rank2 > '8') return false;

        startCol = file1 - 'a';        // 'a' -> 0, 'h' -> 7
        startRow = 8 - (rank1 - '0');  // '1' -> row 7, '8' -> row 0
        endCol   = file2 - 'a';
        endRow   = 8 - (rank2 - '0');

        return true;
    }

    // Check if a move is within the board
    bool inBounds(int row, int col) {
        return (row >= 0 && row < 8 && col >= 0 && col < 8);
    }

    // Basic check: piece belongs to current player
    bool isCurrentPlayerPiece(char piece) {
        if (whiteToMove && isupper(piece)) return true;  // White's piece is uppercase
        if (!whiteToMove && islower(piece)) return true; // Black's piece is lowercase
        return false;
    }

    // Check if the destination square is either empty or occupied by the opponent
    bool canCaptureOrEmpty(char piece, char target) {
        if (target == '.') return true; // Empty square
        // Opposite colors can capture
        if (isupper(piece) && islower(target)) return true;
        if (islower(piece) && isupper(target)) return true;
        return false;
    }

    // Very simplified movement check (doesn't enforce all rules like castling, en passant, etc.)
    bool isValidMove(int sr, int sc, int er, int ec) {
        // Basic checks
        if (!inBounds(sr, sc) || !inBounds(er, ec)) return false;
        char piece = board[sr][sc];
        char target = board[er][ec];
        if (!isCurrentPlayerPiece(piece)) return false;     // Must move own piece
        if (!canCaptureOrEmpty(piece, target)) return false; // Can't capture own piece

        // Direction and distance checks vary by piece
        // We'll do a simple approach for each piece type:
        switch (tolower(piece)) {
            case 'p': return validPawnMove(sr, sc, er, ec);
            case 'r': return validRookMove(sr, sc, er, ec);
            case 'n': return validKnightMove(sr, sc, er, ec);
            case 'b': return validBishopMove(sr, sc, er, ec);
            case 'q': return (validRookMove(sr, sc, er, ec) || validBishopMove(sr, sc, er, ec));
            case 'k': return validKingMove(sr, sc, er, ec);
            default:  return false;
        }
    }

    bool validPawnMove(int sr, int sc, int er, int ec) {
        char pawn = board[sr][sc];
        int direction = (pawn == 'P') ? -1 : 1; // White moves up (row decreasing), Black down (row increasing)
        // Single step forward (must be empty)
        if (ec == sc && er == sr + direction && board[er][ec] == '.') {
            return true;
        }
        // Double step from initial row
        if (ec == sc && ((sr == 6 && pawn == 'P') || (sr == 1 && pawn == 'p')) && er == sr + 2*direction) {
            // Must be empty path
            int midRow = sr + direction;
            if (board[midRow][sc] == '.' && board[er][ec] == '.') {
                return true;
            }
        }
        // Capture diagonally
        if (abs(ec - sc) == 1 && er == sr + direction && board[er][ec] != '.') {
            // Ensure target is opponent piece
            char target = board[er][ec];
            if ((isupper(pawn) && islower(target)) || (islower(pawn) && isupper(target))) {
                return true;
            }
        }
        return false;
    }

    bool validRookMove(int sr, int sc, int er, int ec) {
        // Must move in a straight line
        if (sr != er && sc != ec) return false;
        // Check path is clear
        if (sr == er) {
            // Horizontal
            int colStep = (ec > sc) ? 1 : -1;
            for (int c = sc + colStep; c != ec; c += colStep) {
                if (board[sr][c] != '.') return false;
            }
        } else {
            // Vertical
            int rowStep = (er > sr) ? 1 : -1;
            for (int r = sr + rowStep; r != er; r += rowStep) {
                if (board[r][sc] != '.') return false;
            }
        }
        return true;
    }

    bool validKnightMove(int sr, int sc, int er, int ec) {
        int dr = abs(er - sr);
        int dc = abs(ec - sc);
        // Knight moves in L shape
        return (dr == 2 && dc == 1) || (dr == 1 && dc == 2);
    }

    bool validBishopMove(int sr, int sc, int er, int ec) {
        if (abs(er - sr) != abs(ec - sc)) return false;
        // Check diagonal path
        int rowStep = (er > sr) ? 1 : -1;
        int colStep = (ec > sc) ? 1 : -1;
        int r = sr + rowStep;
        int c = sc + colStep;
        while (r != er && c != ec) {
            if (board[r][c] != '.') return false;
            r += rowStep;
            c += colStep;
        }
        return true;
    }

    bool validKingMove(int sr, int sc, int er, int ec) {
        // King moves one square in any direction
        if (abs(sr - er) <= 1 && abs(sc - ec) <= 1) {
            return true;
        }
        // We won't handle castling here for simplicity
        return false;
    }

    // Make the move on the board, then check for check or checkmate
    bool movePiece(int sr, int sc, int er, int ec) {
        if (!isValidMove(sr, sc, er, ec)) {
            cout << "Invalid move. Try again.\n";
            return false;
        }
        // Move is valid: make the move
        char movingPiece = board[sr][sc];
        board[er][ec] = movingPiece;
        board[sr][sc] = '.';

        // Pawn promotion (simplified: auto-promote to Queen)
        if ((movingPiece == 'P' && er == 0) || (movingPiece == 'p' && er == 7)) {
            board[er][ec] = (isupper(movingPiece)) ? 'Q' : 'q';
            cout << "Pawn promoted to Queen!\n";
        }

        // Switch turns
        whiteToMove = !whiteToMove;

        // Check if the other player's king is in checkmate
        if (isCheckmate()) {
            printBoard();
            cout << "Checkmate! ";
            if (whiteToMove) {
                cout << "White is victorious.\n";
            } else {
                cout << "Black is victorious.\n";
            }
            // End the game
            exit(0);
        } else if (isInCheck()) {
            cout << "Check!\n";
        }

        return true;
    }

    // Locate the king of the current side
    pair<int,int> findKing(bool forWhite) {
        char kingChar = forWhite ? 'K' : 'k';
        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                if (board[r][c] == kingChar) {
                    return {r, c};
                }
            }
        }
        return {-1, -1}; // Should never happen if the king is on the board
    }

    // Check if the current player's king is in check
    bool isInCheck() {
        // We want to see if the king of the *current* player is attacked
        bool kingSide = !whiteToMove; 
        // Because after we move, we switch turns, so 'whiteToMove' is the new side
        // We want to check the side that just moved. So the king belongs to !whiteToMove
        pair<int,int> kingPos = findKing(kingSide);
        if (kingPos.first == -1) return false; // Should not happen

        int kr = kingPos.first;
        int kc = kingPos.second;

        // We'll do a brute force check of every piece on the board to see if it can capture the king
        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                char piece = board[r][c];
                if (piece == '.' || isupper(piece) == isupper(board[kr][kc])) {
                    // Either empty or same color as king -> skip
                    continue;
                }
                // Temporarily treat it as that piece's turn to see if it can move to king's square
                // We'll flip whiteToMove so that isValidMove sees it as the correct side
                bool oldTurn = whiteToMove;
                whiteToMove = (isupper(piece)); 
                if (isValidMove(r, c, kr, kc)) {
                    whiteToMove = oldTurn;
                    return true;
                }
                whiteToMove = oldTurn;
            }
        }
        return false;
    }

    // Check if the side that is about to move is checkmated
    bool isCheckmate() {
        // If the side to move is not in check, it can't be checkmate
        if (!isInCheck()) return false;

        // If there's any valid move that gets us out of check, it's not checkmate
        // We'll try every piece of the side to move and see if any valid move fixes the check
        bool sideToMove = whiteToMove;
        for (int r = 0; r < 8; r++) {
            for (int c = 0; c < 8; c++) {
                char piece = board[r][c];
                // Must be the correct color piece
                if (piece == '.' || (sideToMove && islower(piece)) || (!sideToMove && isupper(piece))) {
                    continue;
                }
                // Try moving this piece to every square
                for (int rr = 0; rr < 8; rr++) {
                    for (int cc = 0; cc < 8; cc++) {
                        if (isValidMove(r, c, rr, cc)) {
                            // Make a temporary move
                            char saved = board[rr][cc];
                            char movingPiece = board[r][c];
                            board[rr][cc] = movingPiece;
                            board[r][c] = '.';

                            bool oldTurn = whiteToMove;
                            whiteToMove = !whiteToMove;
                            bool stillInCheck = isInCheck();
                            whiteToMove = oldTurn;

                            // Undo the move
                            board[r][c] = movingPiece;
                            board[rr][cc] = saved;

                            if (!stillInCheck) {
                                return false; // Found a move that removes check
                            }
                        }
                    }
                }
            }
        }
        return true; // No move removes the check -> checkmate
    }

    void play() {
        while (true) {
            printBoard();
            cout << (whiteToMove ? "[White]" : "[Black]") 
                 << " Enter your move (e.g., e2e4): ";

            string move;
            cin >> move;
            int sr, sc, er, ec;
            if (!parseMove(move, sr, sc, er, ec)) {
                cout << "Invalid input format. Try again.\n";
                continue;
            }
            movePiece(sr, sc, er, ec);
        }
    }
};

int main() {
    ChessGame game;
    game.play();
    return 0;
}
