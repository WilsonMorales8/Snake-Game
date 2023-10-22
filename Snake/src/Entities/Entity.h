#pragma once



class Entity {
	protected:
		int x, y, width, height;
	public:
		explicit Entity(int x, int y, int width, int height);
		virtual ~Entity();
		bool remove = false;
		void damage(Entity* damageSource);
		bool collides(Entity* entity);
		int getX();
		int getY();


		
};