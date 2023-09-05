/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

// 
//
// Name: Ken Wu
// login ID: 20999205
//////////////////////////////////////////////////////////////////////////////////////////

#include <assert.h>
#include <stdio.h>
#include "connect.h"
#include "cs136-trace.h"

const char NONE = '_';
const char RED = 'R';
const char YELLOW = 'Y';

// The number of pieces that have to be in a straight line (horizontal of
//   vertical) in order to win the game.
static const int WINLENGTH = 4;

// The width / number of columns of the Connect Four board.
static const int WIDTH = 7;

// The height / number of rows of the Connect Four board.
static const int HEIGHT = 6;

// See connect.h for documentation.
struct connect connect_init() {
    struct connect game = {RED};
    for (int i = 0; i < WIDTH * HEIGHT; ++i) {
        game.board[i] = NONE;
    }
    return game;
}

static char get_value(const char *board, int c, int r) {
    assert(c >= 0);
    assert(c < WIDTH);
    assert(r >= 0);
    assert(r < HEIGHT);
    return board[r * WIDTH + c];
}

static void set_value(char *board, int c, int r, char player) {
    assert(c >= 0);
    assert(c < WIDTH);
    assert(r >= 0);
    assert(r < HEIGHT);
    board[r * WIDTH + c] = player;
}

// See connect.h for documentation.
bool connect_drop_piece(struct connect *cf, int col) {
    assert(col >= 0 && col < WIDTH);
    
    for (int r = HEIGHT - 1; r >= 0; r--) {
        if (get_value(cf->board, col, r) == NONE) {
            set_value(cf->board, col, r, cf->current_player);
            cf->current_player = (cf->current_player == RED) ? YELLOW : RED;
            return true;
        }
    }
    return false;
}

bool is_out_of_bounds(int col, int row) {
  return col < 0 || col >= WIDTH || row < 0 || row >= HEIGHT;
}

static bool checks_in_direction(const struct connect *cf, int start_col, int start_row, int delta_col, int delta_row) {

  char first_cell = get_value(cf->board, start_col, start_row);

  for (int i = 1; i < WINLENGTH; i++) {
    int col = start_col + i * delta_col;
    int row = start_row + i * delta_row;

    if (is_out_of_bounds(col, row) || get_value(cf->board, col, row) != first_cell) {
      return false;
    }
  }

  return true;

}

// See connect.h for documentation.
char connect_has_won(const struct connect *cf) {
    for (int c = 0; c < WIDTH; c++) {
        for (int r = 0; r < HEIGHT; r++) {
            char start = get_value(cf->board, c, r);
            if (start != NONE) {
                if (checks_in_direction(cf, c, r, 1, 0) ||
                    checks_in_direction(cf, c, r, 0, 1) ||
                    checks_in_direction(cf, c, r, 1, 1) ||
                    checks_in_direction(cf, c, r, 1, -1)) {
                        return start;
                }
            }
        }
    }
    return NONE;
}

// See connect.h for documentation.
bool connect_has_finished(const struct connect *cf) {
    char winner = connect_has_won(cf);
    if (winner == RED || winner == YELLOW) {
        return true;
    }

    for (int c = 0; c < WIDTH; c++) {
        for (int r = 0; r < HEIGHT; r++) {
            if (get_value(cf->board, c, r) == NONE) {
                return false;
            }
        }
    }

    return true;
}

// See connect.h for documentation.
void connect_print(struct connect *cf) {
    assert(cf);
    for (int r = 0; r < HEIGHT; ++r) {
        printf("|");
        for (int c = 0; c < WIDTH; ++c) {
            printf(" %c |", get_value(cf->board, c, r));
        }
        printf("\n");
    }
    printf("%c", cf->current_player);
    for (int w = 0; w < 4 * WIDTH - 1; ++w) {
        printf("-");
    }
    printf("%c\n\n", cf->current_player);
}