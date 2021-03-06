#include "MoveComponent.h"
#include "Actor.h"

MoveComponent::MoveComponent(class Actor* owner)
:Component(owner, 50)
,mAngularSpeed(0.0f)
,mForwardSpeed(0.0f)
,mStrafeSpeed(0.0f)
{
	
}

void MoveComponent::Update(float deltaTime)
{
    mOwner->SetRotation(mOwner->GetRotation() + mAngularSpeed * deltaTime);
    mOwner->SetPosition(Vector3(mOwner->GetPosition().x+mOwner->GetForward().x*deltaTime*mForwardSpeed, mOwner->GetPosition().y+mOwner->GetForward().y*deltaTime*mForwardSpeed, mOwner->GetPosition().z+mOwner->GetForward().z*deltaTime*mForwardSpeed));
    mOwner->SetPosition(Vector3(mOwner->GetPosition().x+mOwner->GetRight().x*deltaTime*mStrafeSpeed, mOwner->GetPosition().y+mOwner->GetRight().y*deltaTime*mStrafeSpeed, mOwner->GetPosition().z+mOwner->GetRight().z*deltaTime*mStrafeSpeed));

}
