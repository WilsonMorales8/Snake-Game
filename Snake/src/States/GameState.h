#pragma once

#include "State.h"
#include "Snake.h"
#include "ofMain.h"
#include "Rock.h"

class GameState : public State {
    

    public:
    int hp;

        GameState();
        ~GameState();
        void reset();
        void update();
        void draw();
        void keyPressed(int key);
        void foodSpawner();
        void drawFood();
        void drawStartScreen();
        void drawLostScreen();
        void drawBoardGrid();
        void drawGameScore();          //visual score
        void powerUpSpawner();
        bool isReady = false;
        bool Active = false;
        bool powerUpSpawned;

        Snake* snake;
        Rock* rock;
        
        bool foodSpawned = false;
        bool foodGone = false;

        int currentFoodX;
        int currentFoodY;
        int currentRockX;
        int currentRockY;

        int boardSizeWidth, boardSizeHeight;
        int cellSize; // Pixels
        int gamescore;
        int getHp(){return hp;}

    
        int gamescore;  
        bool inmortal = false;
        bool getInmortal();
        void setInmortal(bool checkInmortal);              //score value
};