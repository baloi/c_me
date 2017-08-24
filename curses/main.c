#include <curses.h>
#include <stdlib.h>

typedef struct Player {
    int x_position;
    int y_position;
    int health;
} Player;

int screen_setup();
int map_setup();
Player * player_setup();

int main() {

    Player *user;


    screen_setup();
    map_setup();

    user = player_setup();

    getch();
    endwin();

    return 0;
}

int screen_setup() {
    initscr();
    printw("hello world!\n");
    noecho();
    refresh();
    return 0;
}

int map_setup() {
    mvprintw(13, 13, "--------");
    mvprintw(14, 13, "|------|");
    mvprintw(15, 13, "|------|");
    mvprintw(16, 13, "|------|");
    mvprintw(17, 13, "|------|");
    mvprintw(18, 13, "--------");

    return 0;
}

Player * player_setup() {
    Player *new_player;
    new_player = malloc(sizeof(Player));

    new_player->x_position = 14;
    new_player->y_position = 14;
    new_player->health = 20;

    mvprintw(new_player->y_position, new_player->x_position, "@");
    return new_player;
}
