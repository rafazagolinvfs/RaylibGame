#pragma once

#include "EngineUtils.h"
#include "Utils.h"
#include "Level.h"


//forward declare class template
template <typename T>
class FactoryActor;

class Actor
{
    //Give access to controller class
    friend class Controller;

    template <typename T>
    friend class FactoryActor;

public:
    //This is a function pointer that will allow us to bind it to the OnOverlap method when the actor overlaps with some actor
    using OverlapDelegate = void(Actor::*)(Actor*);
    OverlapDelegate collisionOverlapBind;

    
    virtual void Update();
    virtual void Move(Vector2 dir);
    virtual bool Smash(bool isSmashing);
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
    Actor(); //default constructor
    ~Actor(); //default destructor
    Actor(const Actor& actor); //copy constructor
    Actor(Vector2 position, Vector2 size); //custom constructor
    int mUID;

    void ResetPosition(float resetPosition = -SCREEN_Y);

private: 
    void CollisionCheck();
};