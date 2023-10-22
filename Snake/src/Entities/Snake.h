#pragma once
#include <vector>

enum Direction {
        LEFT,
        RIGHT,
        UP,
        DOWN,
        NONE
    };

class Snake {

private:
    std::vector<std::vector<int>> body;
    Direction direction;
    int boardSizeWidth, boardSizeHeight;
    int segmentSize;
   

public:
    Snake(int segmentSize, int boardSizeW, int boardSizeH);
    ~Snake();
     bool crashed;
    void update();
    void draw();
    void changeDirection(Direction d);
    void checkSelfCrash();
    void grow();
    void undo(); //shrink snake
    bool isCrashed() {
        return this->crashed;
    }
    int speed = 4;
    int getSpeed();
    void setSpeed(int i){
        this->speed= i;
    }
    void setCrashed(bool val){
        this->crashed = val;
    }

    std::vector<int> getHead() {
        return this->body[0];
    }
    std::vector<int> getTail() {
        return this->body[this->body.size() - 1];
    }
    std::vector<std::vector<int>> getBody() {
        return this->body;
    }
    
    //rainbow colors
    float getColor(){
    static float color = 0; 
    color += 0.5; 
    if (color >= 255) {
        color = 0;
    }
    return color;
}
};
