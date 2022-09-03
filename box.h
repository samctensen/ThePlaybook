#ifndef BOX_H
#define BOX_H
#include "Box2D/Box2D.h"
#include "QTimer"

class Box
{
public:
    Box();
    void continueBounce();
    float getX();
    float getY();

private:
    b2World world;
    float timeStep;
    int32 velocityIterations;
    int32 positionIterations;
    b2Body* body;
    b2Vec2 position;

};

#endif // BOX_H
