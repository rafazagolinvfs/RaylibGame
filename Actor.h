#pragma once

#include "Utils.h"
#include "Level.h"
#include <raylib.h>
#include <vector>


template <typename T>
class FactoryActor;

typedef void (*CollisionAction)(Level &currentLevel, Actor* actor);

class Actor
{
    friend class Controller;


    template <typename T>
    friend class FactoryActor;
public:
    ~Actor();

    virtual void Update();
    virtual void Move(Vector2 dir);
    virtual void Render(Color color);
    void Collide(CollisionAction collisionAction, Level& currentLevel, std::vector<Actor*>& actorsToCollideWith);
    Vector2 GetPosition() const;
    Texture2D sprite;
    bool isPlayerActor = false;


    union
    {
        Rectangle shape;
    };

    float movSpeed;


protected:
    Actor();
    Actor(const Actor& actor); //copy constructor
    Actor(Vector2 position, Vector2 size);
    int mUID;

};