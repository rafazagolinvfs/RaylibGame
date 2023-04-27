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
    virtual void SetPosition(Vector2 pos);
    virtual bool Smash(bool isSmashing);
    virtual void Render(Color color);
    virtual void OnOverlap(Actor* collidedActor) {};
    Vector2 GetPosition() const;
    bool IsNotBelowScreen();

public:
    Texture2D sprite;
    bool ignoreCollision = false;
    bool isSmashing = false;

    bool isActive = true; //will determine if the update will run or not

    union
    {
        Rectangle shape;
    };

    float movSpeed;
    Level* level;
    UserInterface* ui;

    void ResetPosition(float resetPosition = -SCREEN_Y);
protected:
    Actor(); //default constructor
    ~Actor(); //default destructor
    Actor(const Actor& actor); //copy constructor
    Actor(Vector2 position, Vector2 size); //custom constructor


protected:
    int mUID;


private: 
    void CollisionCheck();
};