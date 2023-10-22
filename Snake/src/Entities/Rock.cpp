#include "Rock.h"

Rock::Rock(int x, int y, int width, int height): StaticEntity(x, y, width, height) {

}

Rock:: ~Rock() {
}

void Rock::draw(){
ofSetColor(255,255,255);

ofDrawRectangle(100,100, 25 ,25);
}

void Rock::update(Snake* snake){
    if(snake->getHead()[0]*this->width == this->getX() && snake->getHead()[1]*this->height == this->getY()){
        snake->setCrashed(true);
    }
}

void Rock::reset() {
    
}