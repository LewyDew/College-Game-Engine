#include "ResourceManager.h"
#include "SFMLFont.h"
#include "SFMLGame.h"
#include "SFMLGameObject.h"
#include "SFMLMouse.h"
#include "SFMLRoom.h"
#include "Player.h"
#include "SFMLKeyboard.h"
#include "Solid.h"
#include "SFMLBox.h"
Player::Player(const std::string & ResourceName,
	float XStart,
	float YStart,
	int HFrames,
	int VFrames)
	:SFMLGameObject(ResourceName,
		XStart,
		YStart,
		HFrames,
		VFrames)
	,Score(0)
{

}



void Player::Update(const sf::Time & DeltaTime)
{
	if (SFMLKeyboard::GetInstance()->IsKeyPressed(sf::Keyboard::Up))
	{
		
		bool nothing_one_space_forward =
			(SFMLGameObject::PlaceMeeting<Solid>
				(sf::Vector2f(this->GetPreviousPositionX(),this->GetPreviousPositionY() - 60))
				== false);

		bool box_can_be_pushed =
			((SFMLGameObject::PlaceMeeting<SFMLBox>(sf::Vector2f(this->GetPreviousPositionX(), this->GetPreviousPositionY() - 60)) == true) &&
				(SFMLGameObject::PlaceMeeting<Solid>
					(sf::Vector2f(this->GetPreviousPositionX(), this->GetPreviousPositionY() - 120)) == false));

		if (nothing_one_space_forward)
		{
			//this->SetSpeed(10);
			//alarm[0] = 6;
			this->SetDirectionInDegrees(90);
			this->SetImageAngle(this->GetDirectionInDegrees());
			Score++;
			this->SetVelocityY(-10);
			for (int i = 0; i < 6; ++i) {
				SetPosition(GetPosition() + GetVelocity());
				SetVelocity(GetVelocity() + GetAcceleration());
				SetSpeed(GetSpeed() - GetFriction());
				SetImageIndex(GetImageIndex() + GetImageSpeed());
				SetImageAngle(GetImageAngle() + GetImageAngleSpeed());
				this->Draw();
			}
	
			this->SetVelocityY(0);
			
		}
		else if (box_can_be_pushed)
		{
			SFMLBox * ins = InstancePlace<SFMLBox>(sf::Vector2f(GetPreviousPositionX(), GetPreviousPositionY()-60));
			//this->SetSpeed(10);
			//alarm[0] = 6;
			this->SetDirectionInDegrees(90);
			ins->SetDirectionInDegrees(90);
			this->SetImageAngle(this->GetDirectionInDegrees());
			Score++;
			this->SetVelocityY(-3);
			ins->SetVelocityY(-3);
			this->SetImageIndex(1);
			for (int i = 0; i < 20; ++i) {
				
				SetPosition(GetPosition() + GetVelocity());
				SetVelocity(GetVelocity() + GetAcceleration());
				SetSpeed(GetSpeed() - GetFriction());
				SetImageIndex(GetImageIndex() + GetImageSpeed());
				SetImageAngle(GetImageAngle() + GetImageAngleSpeed());
				this->Draw();
				ins->SetPosition(ins->GetPosition() + ins->GetVelocity());
				ins->SetVelocity(ins->GetVelocity() + ins->GetAcceleration());
				ins->SetSpeed(ins->GetSpeed() - ins->GetFriction());
				ins->Draw();
			}
			this->SetImageIndex(0);
			this->SetVelocityY(0);
			ins->SetVelocityY(0);
		}
	}
	
	else if (SFMLKeyboard::GetInstance()->IsKeyPressed(sf::Keyboard::Down))
	{
		bool nothing_one_space_forward =
			(SFMLGameObject::PlaceMeeting<Solid>
			(sf::Vector2f(this->GetPreviousPositionX(), this->GetPreviousPositionY() + 60))
				== false);

		bool box_can_be_pushed =
			((SFMLGameObject::PlaceMeeting<SFMLBox>(sf::Vector2f(this->GetPreviousPositionX(), this->GetPreviousPositionY() + 60)) == true) &&
			(SFMLGameObject::PlaceMeeting<Solid>
				(sf::Vector2f(this->GetPreviousPositionX(), this->GetPreviousPositionY() + 120)) == false));

		if (nothing_one_space_forward)
		{
			//this->SetSpeed(10);
			//alarm[0] = 6;
			this->SetDirectionInDegrees(270);
			this->SetImageAngle(this->GetDirectionInDegrees());
			Score++;
			this->SetVelocityY(10);
			for (int i = 0; i < 6; ++i) {
				SetPosition(GetPosition() + GetVelocity());
				SetVelocity(GetVelocity() + GetAcceleration());
				SetSpeed(GetSpeed() - GetFriction());
				SetImageIndex(GetImageIndex() + GetImageSpeed());
				SetImageAngle(GetImageAngle() + GetImageAngleSpeed());
				this->Draw();
			}

			this->SetVelocityY(0);

		}

		else if (box_can_be_pushed)
		{
			SFMLBox * ins = InstancePlace<SFMLBox>(sf::Vector2f(GetPreviousPositionX(), GetPreviousPositionY() + 60));
			//this->SetSpeed(10);
			//alarm[0] = 6;
			this->SetDirectionInDegrees(270);
			ins->SetDirectionInDegrees(270);
			this->SetImageAngle(this->GetDirectionInDegrees());
			Score++;
			this->SetVelocityY(3);
			ins->SetVelocityY(3);
			this->SetImageIndex(1);
			for (int i = 0; i < 20; ++i) {

				SetPosition(GetPosition() + GetVelocity());
				SetVelocity(GetVelocity() + GetAcceleration());
				SetSpeed(GetSpeed() - GetFriction());
				SetImageIndex(GetImageIndex() + GetImageSpeed());
				SetImageAngle(GetImageAngle() + GetImageAngleSpeed());
				this->Draw();
				ins->SetPosition(ins->GetPosition() + ins->GetVelocity());
				ins->SetVelocity(ins->GetVelocity() + ins->GetAcceleration());
				ins->SetSpeed(ins->GetSpeed() - ins->GetFriction());
				ins->Draw();
			}
			this->SetImageIndex(0);
			this->SetVelocityY(0);
			ins->SetVelocityY(0);
		}
	}
	else if (SFMLKeyboard::GetInstance()->IsKeyPressed(sf::Keyboard::Left))
	{
		bool nothing_one_space_forward =
			(SFMLGameObject::PlaceMeeting<Solid>
			(sf::Vector2f(this->GetPreviousPositionX() - 60, this->GetPreviousPositionY()))
				== false);

		bool box_can_be_pushed =
			((SFMLGameObject::PlaceMeeting<SFMLBox>(sf::Vector2f(this->GetPreviousPositionX() - 60, this->GetPreviousPositionY())) == true) &&
			(SFMLGameObject::PlaceMeeting<Solid>
				(sf::Vector2f(this->GetPreviousPositionX() - 120, this->GetPreviousPositionY())) == false));

		if (nothing_one_space_forward)
		{
			//this->SetSpeed(10);
			//alarm[0] = 6; // not sure how to set up the alarm
			this->SetDirectionInDegrees(180);
			this->SetImageAngle(this->GetDirectionInDegrees());
			Score++;
			this->SetVelocityX(-10);
			for (int i = 0; i < 6; ++i) {
				SetPosition(GetPosition() + GetVelocity());
				SetVelocity(GetVelocity() + GetAcceleration());
				SetSpeed(GetSpeed() - GetFriction());
				SetImageIndex(GetImageIndex() + GetImageSpeed());
				SetImageAngle(GetImageAngle() + GetImageAngleSpeed());
				this->Draw();
			}

			this->SetVelocityX(0);

		}
		else if (box_can_be_pushed)
		{
			SFMLBox * ins = InstancePlace<SFMLBox>(sf::Vector2f(GetPreviousPositionX() - 60, GetPreviousPositionY()));
			//this->SetSpeed(10);
			//alarm[0] = 6;
			this->SetDirectionInDegrees(180);
			ins->SetDirectionInDegrees(180);
			this->SetImageAngle(this->GetDirectionInDegrees());
			Score++;
			this->SetVelocityX(-3);
			ins->SetVelocityX(-3);
			this->SetImageIndex(1);
			for (int i = 0; i < 20; ++i) {

				SetPosition(GetPosition() + GetVelocity());
				SetVelocity(GetVelocity() + GetAcceleration());
				SetSpeed(GetSpeed() - GetFriction());
				SetImageIndex(GetImageIndex() + GetImageSpeed());
				SetImageAngle(GetImageAngle() + GetImageAngleSpeed());
				this->Draw();
				ins->SetPosition(ins->GetPosition() + ins->GetVelocity());
				ins->SetVelocity(ins->GetVelocity() + ins->GetAcceleration());
				ins->SetSpeed(ins->GetSpeed() - ins->GetFriction());
				ins->Draw();
			}
			this->SetImageIndex(0);
			this->SetVelocityX(0);
			ins->SetVelocityX(0);
		}
	}

	else if (SFMLKeyboard::GetInstance()->IsKeyPressed(sf::Keyboard::Right))
	{
		bool nothing_one_space_forward =
			(SFMLGameObject::PlaceMeeting<Solid>
			(sf::Vector2f(this->GetPreviousPositionX() + 60, this->GetPreviousPositionY()))
				== false);

		bool box_can_be_pushed =
			((SFMLGameObject::PlaceMeeting<SFMLBox>(sf::Vector2f(this->GetPreviousPositionX() + 60, this->GetPreviousPositionY())) == true) &&
			(SFMLGameObject::PlaceMeeting<Solid> (sf::Vector2f(this->GetPreviousPositionX() + 120, this->GetPreviousPositionY())) == false));

		if (nothing_one_space_forward)
		{
			//this->SetSpeed(10);
			//alarm[0] = 6;
			this->SetDirectionInDegrees(0);
			this->SetImageAngle(this->GetDirectionInDegrees());
			Score++;
			this->SetVelocityX(10);
			for (int i = 0; i < 6; ++i) {
				SetPosition(GetPosition() + GetVelocity());
				SetVelocity(GetVelocity() + GetAcceleration());
				SetSpeed(GetSpeed() - GetFriction());
				SetImageIndex(GetImageIndex() + GetImageSpeed());
				SetImageAngle(GetImageAngle() + GetImageAngleSpeed());
				this->Draw();
			}

			this->SetVelocityX(0);

		}
		else if (box_can_be_pushed)
		{
			SFMLBox * ins = InstancePlace<SFMLBox>(sf::Vector2f(GetPreviousPositionX() + 60, GetPreviousPositionY()));
			//this->SetSpeed(10);
			//alarm[0] = 6;
			this->SetDirectionInDegrees(0);
			ins->SetDirectionInDegrees(0);
			this->SetImageAngle(this->GetDirectionInDegrees());
			Score++;
			this->SetVelocityX(3);
			ins->SetVelocityX(3);
			this->SetImageIndex(1);
			for (int i = 0; i < 20; ++i) {

				SetPosition(GetPosition() + GetVelocity());
				SetVelocity(GetVelocity() + GetAcceleration());
				SetSpeed(GetSpeed() - GetFriction());
				SetImageIndex(GetImageIndex() + GetImageSpeed());
				SetImageAngle(GetImageAngle() + GetImageAngleSpeed());
				this->Draw();
				ins->SetPosition(ins->GetPosition() + ins->GetVelocity());
				ins->SetVelocity(ins->GetVelocity() + ins->GetAcceleration());
				ins->SetSpeed(ins->GetSpeed() - ins->GetFriction());
				ins->Draw();
			}
			this->SetImageIndex(0);
			this->SetVelocityX(0);
			ins->SetVelocityX(0);
		}
	}
	
	
}

int Player::getScore() 
{
	return Score;
}