#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>
#include "game.h"
#include "entity.h"

class Game
{
public:
    Game(SDL_Texture* p_xTex, SDL_Texture* p_oTex, std::vector<Entity>* p_pieces);
    int placePiece(int p_x, int p_y, char player);
    void clear();
    int checkWin(char p_player);
private:
    int turn;
    char board[3][3];
    SDL_Texture* xTex;
    SDL_Texture* oTex;
    int findPos(int x, int y);
    std::vector<Entity>* pieces;
    char winPositions[8][3][3] = {
        {
            {'X','X','X'},
            {'-','-','-'},
            {'-','-','-'}
        },
        {
            {'-','-','-'},
            {'X','X','X'},
            {'-','-','-'}
        },
        {
            {'-','-','-'},
            {'-','-','-'},
            {'X','X','X'}
        },
        {
            {'X','-','-'},
            {'X','-','-'},
            {'X','-','-'}
        },
        {
            {'-','X','-'},
            {'-','X','-'},
            {'-','X','-'}
        },
        {
            {'-','-','X'},
            {'-','-','X'},
            {'-','-','X'}
        },
        {
            {'X','-','-'},
            {'-','X','-'},
            {'-','-','X'}
        },
        {
            {'-','-','X'},
            {'-','X','-'},
            {'X','-','-'}
        },
    };
};