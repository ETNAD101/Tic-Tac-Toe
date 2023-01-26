#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include "game.h"
#include "entity.h"

Game::Game(SDL_Texture* p_xTex, SDL_Texture* p_oTex)
    :xTex(p_xTex), oTex(p_oTex)
{
    clear();
}

int Game::placePiece(int p_x, int p_y, char player, std::vector<Entity>& pieces) {
    int pos = findPos(p_x, p_y);
    int x = 0, y = 0;

    for (int i = 1; i < pos; i++) {
        x++;
        if (x > 2) {
            x = 0;
            y++;
        }
    }

    if (board[y][x] == '-') {
        turn++;
        board[y][x] = player;
        if (pos == 1) {
            x = 55;
            y = 55;
        }
        if (pos == 2) {
            x = 256;
            y = 55;
        }
        if (pos == 3) {
            x = 481;
            y = 55;
        }
        if (pos == 4) {
            x = 55;
            y = 256;
        }
        if (pos == 5) {
            x = 256;
            y = 256;
        }
        if (pos == 6) {
            x = 481;
            y = 256;
        }
        if (pos == 7) {
            x = 55;
            y = 481;
        }
        if (pos == 8) {
            x = 256;
            y = 481;
        }
        if (pos == 9) {
            x = 481;
            y = 481;
        }

        SDL_Texture* tex;
        if (player == 'X') {
            tex = xTex;
        }
        else {
            tex = oTex;
        }

        pieces.push_back(Entity(Vector2f(x, y), 64, 64, tex));
        int winner = checkWin(player);
        if (winner == 0 && turn == 9)
        {
            return 3;
        }
        else
        {
            return winner;
        }
    }
    else {
        return -1;
    }
}

int Game::checkWin(char p_player) {
    int row = 0;
    for (int a = 0; a < 8; a++) {
        for (int b = 0; b < 3; b++) {
            for (int c = 0; c < 3; c++) {
                if (winPositions[a][b][c] == 'X' && board[c][b] == p_player) {
                    row++;
                }
            }
        }
        if (row == 3) {
            if (p_player == 'X') {
                return 1;
            }
            else {
                return 2;
            }
        }
        else {
            row = 0;
        }
    }
    return 0;
}

void Game::clear() {
    turn = 0;
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            board[x][y] = '-';
        }
    }
}

int Game::findPos(int x, int y) {
    if (x < 175 && y < 175) {
        return 1;
    }
    if (x < 375 && y < 175) {
        return 2;
    }
    if (x < 600 && y < 175) {
        return 3;
    }
    if (x < 175 && y < 375) {
        return 4;
    }
    if (x < 375 && y < 375) {
        return 5;
    }
    if (x < 600 && y < 375) {
        return 6;
    }
    if (x < 175 && y < 600) {
        return 7;
    }
    if (x < 375 && y < 600) {
        return 8;
    }
    if (x < 600 && y < 600) {
        return 9;
    }
    return -1;
}