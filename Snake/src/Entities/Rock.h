#include "StaticEntity.h"
#include "Snake.h"
#include "ofMain.h"

    class Rock : public StaticEntity{
    public:

        Rock(int x, int y, int width, int height);
        ~Rock();
        void reset();
        void update(Snake* snake);
        void draw();
};