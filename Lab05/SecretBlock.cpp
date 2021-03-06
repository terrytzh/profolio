//
//  SecretBlock.cpp
//  Game-mac
//
//  Created by Terry Tang on 2019/10/9.
//  Copyright © 2019 Sanjay Madhav. All rights reserved.
//

#include "SecretBlock.h"
#include "Game.h"
#include "SpriteComponent.h"
#include "CollisionComponent.h"
#include "Door.h"


SecretBlock::SecretBlock(Game* g) : Actor(g){
    cc = new CollisionComponent(this);
    cc->SetSize(BLOCK_WIDTH, BLOCK_WIDTH);
    sprite = new SpriteComponent(this);
    sprite->SetTexture(mGame->GetTexture("Assets/SecretBlock.png"));
    
    direction = SecretBlockDirection::Down;
}

void SecretBlock::Move(float distance){
    if(moveDistance > BLOCK_WIDTH && !isUnlocked){
        Mix_PlayChannel(-1, GetGame()->GetSound("Assets/Sounds/Secret.wav"), 0);
        OpenClosedDoors();
        isUnlocked = true;
        return;
    }
    else if(isUnlocked)
        return;
    Vector2 pos = GetPosition();
    switch (direction) {
        case SecretBlockDirection::Left:
            pos.x += distance;
            break;
            
        case SecretBlockDirection::Right:
            pos.x -= distance;
            break;
        
        case SecretBlockDirection::Up:
            pos.y += distance;
            break;
        
        case SecretBlockDirection::Down:
            pos.y -= distance;
            break;
    }
    SetPosition(pos);
    moveDistance += distance;
}

void SecretBlock::OpenClosedDoors(){
    for(auto d : mGame->GetDoors()){
        if(d->GetState() == DoorState::Closed){
            d->SetState(DoorState::Open);
            d->UpdateComponents();
        }
    }
}
