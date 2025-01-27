#ifndef TETRIS_H
#define TETRIS_H

#define START_X 4
#define START_Y (-4)
#define NUM_FIGURES 7
#define MAX_LEVEL 10
#define SCORE_PER_LEVEL 600
#define DELAY_MS 1100

#define GAME_FIELD_N (FIELD_N + 2)
#define GAME_FIELD_M (FIELD_M * 3 + 2)
#define START_MENU_N 8
#define START_MENU_M 24
#define PAUSE_MENU_N 5
#define PAUSE_MENU_M 24
#define FINISH_GAME_N 10
#define FINISH_GAME_M 24
#define GAME_INFO_M 25
#define CONTROLS_M 24

#define TOP_MARGIN 0
#define LEFT_MARGIN 0

#define O_FIGURE 10
#define I_FIGURE 11
#define S_FIGURE 12
#define Z_FIGURE 13
#define L_FIGURE 14
#define J_FIGURE 15
#define T_FIGURE 16

#define FIELD_N 20
#define FIELD_M 10

#define KEY_R 114
#define KEY_P 112
#define KEY_Q 113
#define KEY_Z 122

#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/time.h>
//#include <ncurses.h>

#include "../../gui/cli/interface/frontend.h"

typedef enum UserAction_t{
  Start,
  Pause,
  Terminate,
  Left,
  Right,
  Up,
  Down,
  Action
} UserAction_t;

typedef enum GameStatus_t{
  Initial,
  Spawn,
  Moving,
  Shifting,
  Attaching,
  GameOver
} GameStatus_t;

typedef struct GameState_t{
  int **field;
  int **color_field;
  int **figure;
  int figure_color;
  int figure_size;
  int **next_figure;
  int next_figure_size;
  int next_figure_color;
  int x;
  int y;
  int status;
  int score;
  int high_score;
  int level;
  int speed;
  bool pause;
  bool is_playing;
  bool win;
  long long time;
} GameState_t;


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

void init_game();
int **generate_figure(int *size, int *color);
void fill_figure(int number, int **figure, int *color);
GameInfo_t updateCurrentState(GameState_t *gs);
void update_field(GameState_t *gs, int **field, int **color_field);
UserAction_t get_user_action(int ch);
void userInput(GameState_t *gs, UserAction_t action);
void finish_game(GameState_t *gs);
void spawn_figure(GameState_t *gs);
void move_figure(GameState_t *gs, UserAction_t action);
void move_left(GameState_t *gs);
void move_right(GameState_t *gs);
void move_down(GameState_t *gs);
void rotate(GameState_t *gs);
void attach_figure(GameState_t *gs);
bool check_top_line(GameState_t *gs);
void process_full_lines(GameState_t *gs);
void shift_lines(GameState_t *gs, int i);
void fill_top_line(GameState_t *gs);
void update_score_and_level(GameState_t *gs, int num_full_lines);

// Utils
GameState_t *get_game_state();
int **create_matrix(int N, int M);
void copy_matrix(int N, int M, int **src_matrix, int **dest_matrix);
void free_matrix(int N, int **matrix);
bool figure_is_attaching(GameState_t *gs);
long long get_time();
bool timer(GameState_t *gs, int delay);
void free_game_info(GameInfo_t *gi);

#endif