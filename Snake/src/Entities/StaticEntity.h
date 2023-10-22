#include "Entity.h"
#pragma once




class StaticEntity: public Entity {
	public:
		explicit StaticEntity(int x, int y, int width, int height);
		virtual ~StaticEntity();
		void damage(StaticEntity* damageSource);
		bool collides(StaticEntity* statice);
		int getX();
		int getY();
		int getWidth();
		int getHeight();

		
};