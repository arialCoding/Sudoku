#pragma once

#include "Engine.hpp"
#include <cstdio>

enum gameState{
    MAINMENU,
    PLAYING,
    WON
};


int Run();

void init();

void update(float dt);
void render();

//MAINMENU//
void initMAINMENU();
void updateMAINMENU(float dt);
void renderMAINMENU();

//PLAYING//
void initPLAYING();
void updatePLAYING(float dt);
void renderPLAYING();

//WON//
void initWON();
void updateWON(float dt);
void renderWON();
