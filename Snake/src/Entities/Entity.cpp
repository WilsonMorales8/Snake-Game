#include "Entity.h"

Entity::Entity(int x, int y, int width, int height){
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}
Entity::~Entity(){}


bool Entity::collides(Entity* entity){
    
}
int Entity :: getX(){
    return x;
}
int Entity :: getY(){
    return y;
}
