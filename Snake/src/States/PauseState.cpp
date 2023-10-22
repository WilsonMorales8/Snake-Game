#include "PauseState.h"

PauseState::PauseState(){}

PauseState::~PauseState(){}


void PauseState:: reset(){
    setFinished(false);
    setNextState("");
}

void PauseState::update(){}

void PauseState::draw() {
    ofSetColor(ofColor::white);
    string text = "Paused";
    ofDrawBitmapString(text, ofGetWidth()/2-8*text.length()/2, ofGetHeight()/2-11);
}

void PauseState::keyPressed(int key) {
    if(key == 'p') {
        setFinished(true);
        setNextState("GameState");
        return;
    }
}