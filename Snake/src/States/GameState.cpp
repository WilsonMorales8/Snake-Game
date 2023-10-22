#include "GameState.h"

//--------------------------------------------------------------
GameState::GameState() {
    foodSpawned = false;
    cellSize = 25;
    boardSizeWidth = 64;
    boardSizeHeight = 36;
    snake = new Snake(cellSize, boardSizeWidth, boardSizeHeight);
    hp = 0;
    rock = new Rock(100, 100, 25, 25);
}
//--------------------------------------------------------------
GameState::~GameState() {
    delete snake;
}
//--------------------------------------------------------------
void GameState::reset() {
    delete snake;
    snake = new Snake(cellSize, boardSizeWidth, boardSizeHeight);
    foodSpawned = false;
    gamescore = 0;
}
//--------------------------------------------------------------
void GameState::update() {

    if(snake->isCrashed()) {
        this->setNextState("LoseState");
        this->setFinished(true);
        return;
    }

    if(snake->getHead()[0] == currentFoodX && snake->getHead()[1] == currentFoodY) {
        gamescore += 10;
        snake->grow();                
        foodSpawned = false;
    }

    foodSpawner();
    if(ofGetFrameNum() % 10 == 0) {
        snake->update();
    }
    hp += 1;
    if(hp >= 900){
        foodSpawned = false;
        hp = 0;
    }
  

}
void GameState:: powerUpSpawner()  {
    if (gamescore == 50){
        Active = true;
        snake->setSpeed(8);
    }
    if (gamescore == 100){
        Active = true;
    snake->grow(); 
    snake->grow(); 
    }
    if (gamescore == 150){
        Active = true;
    for (hp = 0; hp<= 10; hp++ ){
        inmortal = true;

    }
    inmortal = false;

    }


}
void GameState::setInmortal(bool checkInmortal)
{
    this->inmortal = checkInmortal;
}
//--------------------------------------------------------------
void GameState::draw() {
    drawBoardGrid();
    snake->draw();
    drawFood();
    drawGameScore();
    rock->draw();
}
//--------------------------------------------------------------
void GameState::keyPressed(int key) {
    switch(key) {
        case OF_KEY_LEFT:
            snake->changeDirection(LEFT);
            break;
        case OF_KEY_RIGHT:
            snake->changeDirection(RIGHT);
            break;
        case OF_KEY_UP:
            snake->changeDirection(UP);
            break;
        case OF_KEY_DOWN:
            snake->changeDirection(DOWN);
            break;
        case 'a':
            gamescore += 10;
            break;
        case 'u':
            if (snake->getBody().size() > 2){
                snake->undo();
            }break;
        case 'p':
            this -> setNextState("PauseState");
            this -> setFinished(true);
    }
}
//--------------------------------------------------------------
void GameState::foodSpawner() {
    if(!foodSpawned) {
        bool isInSnakeBody;
        do {
            isInSnakeBody = false;
            currentFoodX = ofRandom(1, boardSizeWidth-1);
            currentFoodY = ofRandom(1, boardSizeHeight-1);
            for(unsigned int i = 0; i < snake->getBody().size(); i++) {
                if(currentFoodX == snake->getBody()[i][0] and currentFoodY == snake->getBody()[i][1]) {
                    isInSnakeBody = true;
                }
            }
        } while(isInSnakeBody);
        foodSpawned = true;
    }
    
    
}
//--------------------------------------------------------------
void GameState::drawFood() {
    ofSetColor(255, 0, 0);
    if(hp >= 300 && hp < 20){
        ofSetColor(200, 25, 0);
    }
    if(hp >= 600 && hp < 25){
        ofSetColor(175, 50, 0);
    }
    if(hp >= 750){
        ofSetColor(150, 75, 0);
    }
    //brown es 150, 75, 0 

    if(foodSpawned) {
        ofDrawRectangle(currentFoodX*cellSize, currentFoodY*cellSize, cellSize, cellSize);
    }

}
 
   
   

//--------------------------------------------------------------
void GameState::drawGameScore(){                                       //draw score
    ofSetColor(ofColor :: white);
    ofDrawBitmapString("Game Score: " + ofToString(gamescore),24,42);
}

//--------------------------------------------------------------
void GameState::drawStartScreen() {
    ofSetColor(ofColor::black);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    ofSetColor(ofColor::white);
    string text = "Press any arrow key to start.";
    ofDrawBitmapString(text, ofGetWidth()/2-8*text.length()/2, ofGetHeight()/2-11);
    return;
}
//--------------------------------------------------------------
void GameState::drawLostScreen() {
    ofSetColor(ofColor::black);
    ofDrawRectangle(0,0,ofGetWidth(),ofGetHeight());
    ofSetColor(ofColor::white);
    string text = "You lost! Press any arrow key to play again";
    string text2 = "or press ESC to exit.";
    string text3 = "Score: " + ofToString(2);
    ofDrawBitmapString(text, ofGetWidth()/2-8*text.length()/2, ofGetHeight()/2-11);
    ofDrawBitmapString(text2, ofGetWidth()/2-8*text2.length()/2, ofGetHeight()/2+2);
    ofDrawBitmapString(text3, ofGetWidth()/2-8*text2.length()/2, ofGetHeight()/2+12);
    return;
}
//--------------------------------------------------------------
void GameState::drawBoardGrid() {
    
    ofDrawGrid(25, 64, false, false, false, true);
    
    // ofSetColor(ofColor::white);
    // for(int i = 0; i <= boardSize; i++) {
    //     ofDrawLine(i*cellSize, 0, i*cellSize, ofGetHeight());
    //     ofDrawLine(0, i*cellSize, ofGetWidth(), i*cellSize);
    // }
}
//--------------------------------------------------------------

