#pragma once

#include "Engine.hpp"
#include <cstdio>

enum gameState{
    MAINMENU,
    PAUSED,
    PLAYING,
    WON
};


int Run();

void init();

void update(float dt);
void render();

//MAINMENU//
void updateMAINMENU(float dt);
void renderMAINMENU();

//PAUSED//
void updatePAUSED(float dt);
void renderPAUSED();

//PLAYING//
void updatePLAYING(float dt);
void renderPLAYING();

//WON//
void updateWON(float dt);
void renderWON();
