#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetWindowTitle("Snake");

    pauseState = new PauseState();
    loseState = new LoseState(gameState);
    gameState = new GameState();
    menuState = new MenuState();
    currentState = menuState;

    sound.load("Snake.wav");
	sound.setLoop(true);
	sound.play();

}

//--------------------------------------------------------------
void ofApp::update(){
    if(currentState->hasFinished()) {
        if(currentState->getNextState() == "GameState") {
            if(currentState != pauseState){
            gameState->reset();
            }
            currentState = gameState;
            gameState -> setFinished(false);
            gameState -> setNextState("");
        } else if(currentState->getNextState() == "MenuState") {
            menuState->reset();
            currentState = menuState;    
        } else if(currentState->getNextState() == "LoseState") {
            loseState->reset();
            currentState = loseState;
        } else if(currentState->getNextState() == "PauseState") {
            pauseState->reset();
            currentState = pauseState;
        }
    }
    currentState->update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    currentState->draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    currentState->keyPressed(key);
}
//--------------------------------------------------------------