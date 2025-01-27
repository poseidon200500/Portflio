#ifndef FRONTEND_H
#define FRONTEND_H

#include "../../../brick_game/tetris/tetris2.h"

#ifndef GAME_INFO_STRUCT
#define GAME_INFO_STRUCT
typedef struct Figure_t{
  /// @brief Массив для хранения фигуры.
  int **array;
  /// @brief Координата.
  int x;
  /// @brief Координата.
  int y;
  int size;
} Figure_t;

typedef struct GameInfo_t{
  int **field;
  int **color_field;
  int **next;
  int next_size;
  int next_color;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
  Figure_t figure;
  Figure_t next_figure;
} GameInfo_t;
#endif


void init_ncurses();
void init_colors();
void render(int status, bool win, GameInfo_t gi);
WINDOW *print_controls();
WINDOW *print_game_field(GameInfo_t gi);
void print_start_menu();
void print_pause_menu();
void print_win(GameInfo_t gi);
void print_game_over(GameInfo_t gi);
WINDOW *print_game_info(GameInfo_t gi);
void print_next_figure(WINDOW *info_window, GameInfo_t gi);

int start_tetris();
void game_loop();

#endif