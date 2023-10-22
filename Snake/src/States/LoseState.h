#pragma once

#include "GameState.h"
#include "State.h"
#include "ofMain.h"

class LoseState : public State {
public:
    LoseState(GameState* gameStatePtr);
    ~LoseState();
    void reset();
    void update();
    void draw();
    void keyPressed(int key);
    GameState* gameState;
};