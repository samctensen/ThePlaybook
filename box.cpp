#include "box.h"

Box::Box() : world(b2Vec2(0.0f, 0.0f))
{
    b2BodyDef leftWallDef;
    leftWallDef.position.Set(0.0f, 0.0f);
    b2Body* leftWallBody = world.CreateBody(&leftWallDef);
    b2PolygonShape leftWall;
    leftWall.SetAsBox(0.0f, 900.0f);
    leftWallBody->CreateFixture(&leftWall, 0.0f);

    b2BodyDef topWallDef;
    topWallDef.position.Set(0.0f, 0.0f);
    b2Body* topWallBody = world.CreateBody(&topWallDef);
    b2PolygonShape topWall;
    topWall.SetAsBox(1500.0f, 0.0f);
    topWallBody->CreateFixture(&topWall, 0.0f);

    b2BodyDef rightWallDef;
    rightWallDef.position.Set(1150.0f, 0.0f);
    b2Body* rightWallBody = world.CreateBody(&rightWallDef);
    b2PolygonShape rightWall;
    rightWall.SetAsBox(0.0f, 800.0f);
    rightWallBody->CreateFixture(&rightWall, 0.0f);

    b2BodyDef bottomWallDef;
    bottomWallDef.position.Set(0.0f, 700.0f);
    b2Body* bottomWallBody = world.CreateBody(&bottomWallDef);
    b2PolygonShape bottomWall;
    bottomWall.SetAsBox(1500.0f, 0.0f);
    bottomWallBody->CreateFixture(&bottomWall, 0.0f);

    // Label position and body definitions.
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(800.0f, 450.0f);
    body = world.CreateBody(&bodyDef);

    // Dynamic body of the label
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.0f;
    fixtureDef.restitution = 1.0f;

    body->CreateFixture(&fixtureDef);
    body->ApplyLinearImpulse(b2Vec2(1000.0f, 1000.0f), b2Vec2(0.0f, 0.0f), true);

    timeStep = 1.0f / 60.0f;

    velocityIterations = 6;
    positionIterations = 2;

    continueBounce();
}

void Box::continueBounce() {
    world.Step(timeStep, velocityIterations, positionIterations);
    position = body->GetPosition();
}

float Box::getX() {
    return(position.x);
}

float Box::getY() {
    return(position.y);
}
