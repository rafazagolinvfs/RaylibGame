#pragma once

#include "Utils.h"
#include "Level.h"
#include <raylib.h>
#include <vector>


//forward declare class template
template <typename T>
class FactoryActor;

typedef void (*CollisionAction)(Level &currentLevel, Actor* actor);
//typedef void (*Collision)(Actor* actor);


class Actor
{
    //Give access to controller class
    friend class Controller;

    template <typename T>
    friend class FactoryActor;

public:
    using OverlapDelegate = void(Actor::*)(Actor*);
    OverlapDelegate collisionOverlapBind;

    virtual void Update();
    virtual void Move(Vector2 dir);
    virtual void Render(Color color);
    virtual void OnOverlap(Actor* collidedActor) {};


    Vector2 GetPosition() const;
    Texture2D sprite;
    bool IgnoreCollision = false;
    bool isSmashing = false;

    union
    {
        Rectangle shape;
    };

    float movSpeed;
    Level* level;
    UserInterface* ui;

protected:
    Actor();
    ~Actor();
    Actor(const Actor& actor); //copy constructor
    Actor(Vector2 position, Vector2 size);
    int mUID;

private: 
    void CollisionCheck();
};