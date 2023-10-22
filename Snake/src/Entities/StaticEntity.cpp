#include "StaticEntity.h"

StaticEntity::StaticEntity(int x, int y, int width, int height): Entity(x, y, width, height){
 
}
StaticEntity::~StaticEntity(){}


bool StaticEntity::collides(StaticEntity* statice){}