#pragma once

class SFMLRoom;

#include <SFML/Graphics.hpp>

#include "SFMLRoom.h"

class SFMLGameObject
{
public:
	SFMLGameObject( const std::string & ResourceName,
		            float XStart,
		            float YStart,
		            int HFrames = 1,
		            int VFrames = 1);

	virtual ~SFMLGameObject();

	virtual void SFMLGameObject::PreUpdate(const sf::Time & DeltaTime);
	virtual void Update(const sf::Time & DeltaTime);
	virtual void Draw();

	// Visible
	void SetVisible(bool Value);
	bool GetVisible();

	// Depth
	int GetDepth();
	void SetDepth(int Value);

	// SpriteIndex
	sf::Sprite * GetSprite();

	// Position
	void SetPosition(const sf::Vector2f & Value);
	void SetPosition(float X, float Y);
	void SetX(float Value);
	void SetY(float Value);
	sf::Vector2f GetPosition();
	float GetX();
	float GetY();

	// ImageScale
	void SetImageScale(const sf::Vector2f & Value);
	void SetImageScale(float ScaleX, float Scaley);
	void SetImageScaleX(float Value);
	void SetImageScaleY(float Value);
	sf::Vector2f GetImageScale();
	float GetImageScaleX();
	float GetImageScaleY();

	// SpriteWidth and SpriteHeight
	int GetSpriteWidth();
	int GetSpriteHeight();

	// ImageAngle
	void SetImageAngle(float Value);
	void SetImageAngleSpeed(float Value);
	float GetImageAngle();
	float GetImageAngleSpeed();

	// ImageNumber
	int GetImageNumber();

	// ImageIndex
	float GetImageIndex();
	void SetImageIndex(float Value);

	// ImageSpeed
	float GetImageSpeed();
	void SetImageSpeed(float Value);

	// StartPosition
	void SetStartPosition(const sf::Vector2f & Value);
	void SetStartPositionX(float Value);
	void SetStartPositionY(float Value);
	sf::Vector2f GetStartPosition();
	float GetStartPositionX();
	float GetStartPositionY();

	// PreviousPosition
	void SetPreviousPosition(const sf::Vector2f & Value);
	void SetPreviousPositionX(float Value);
	void SetPreviousPositionY(float Value);
	sf::Vector2f GetPreviousPosition();
	float GetPreviousPositionX();
	float GetPreviousPositionY();

	// SpriteOffset
	void SetSpriteOffset(const sf::Vector2f & Value);
	void SetSpriteOffsetX(float Value);
	void SetSpriteOffsetY(float Value);
	sf::Vector2f GetSpriteOffset();
	float GetSpriteOffsetX();
	float GetSpriteOffsetY();

	// ImageAlpha
	unsigned char GetImageAlpha();
	void SetImageAlpha(unsigned char Value);

	// ImageTint
	void SetImageTint(const sf::Color & Value);
	void SetImageTint(unsigned char Red, unsigned char Green, unsigned char Blue);
	void SetImageTintRed(unsigned char Value);
	void SetImageTintGreen(unsigned char Value);
	void SetImageTintBlue(unsigned char Value);
	sf::Color GetImageTint();
	unsigned char GetImageTintRed();
	unsigned char GetImageTintGreen();
	unsigned char GetImageTintBlue();
	
	// Functions
	float DistanceToPoint(const sf::Vector2f Point);
	float DistanceToPoint(float X, float Y);
	float DistanceToObject(SFMLGameObject * Object);
	void MotionSet(float Speed, float DirectionInDegrees);
	void MotionAdd(float Speed, float DirectionInDegrees);
	void DrawLine(float X0, float Y0, float X1, float Y1, const sf::Color & Color);

	// Velocity
	void SetVelocity(const sf::Vector2f & Value);
	void SetVelocityX(float Value);
	void SetVelocityY(float Value);
	sf::Vector2f GetVelocity();
	float GetVelocityX();
	float GetVelocityY();

	// Acceleration
	void SetAcceleration(const sf::Vector2f & Value);
	void SetAccelerationX(float Value);
	void SetAccelerationY(float Value);
	sf::Vector2f GetAcceleration();
	float GetAccelerationX();
	float GetAccelerationY();

	// Speed
	void SetSpeed(float Value);
	float GetSpeed();

	// Direction
	void SetDirectionInDegrees(float Value);
	float GetDirectionInDegrees();

	// AccelerationDirection
	void SetAccelerationDirectionInDegrees(float Value);
	float GetAccelerationDirectionInDegrees();

	// Friction
	void SetFriction(float Value);
	float GetFriction();

	// Room Created In - Used for Depth settings
	void SetRoomCreatedIn(SFMLRoom * Room);
	SFMLRoom * GetRoomCreatedIn();

	sf::Rect<float> GetBoundingBox();
	virtual void OnCollision(SFMLGameObject * Other);

	template<typename T>
	bool CollisionPoint(const sf::Vector2f & Point);

	template<typename T>
	T * GetObjectAtPoint(const sf::Vector2f & Point);

	template<typename T>
	bool PlaceMeeting(const sf::Vector2f & Point);

	template<typename T>
	T * InstancePlace(const sf::Vector2f & Point);

	template<typename T>
	std::vector<T *> GetAllGameObjectsOfType();

private: 
	sf::Sprite * Sprite;
	int HorizontalFrames;
	int VerticalFrames;
	int TotalFrames;
	bool Visible;
	int Depth;
	float ImageIndex;
	float ImageSpeed;
	sf::Vector2f StartPosition;
	sf::Vector2f PreviousPosition;
	sf::Vector2f Velocity;
	sf::Vector2f Acceleration;
	float DirectionInDegrees;
	float AccelerationDirectionInDegrees;
	float Friction;
	float ImageAngleSpeed;
	SFMLRoom * RoomCreatedIn;

	float ConvertRadiansToDegrees(float Value);
	float ConvertDegreesToRadians(float Value);

};

template<typename T>
bool SFMLGameObject::CollisionPoint(const sf::Vector2f & Point)
{
	return GetRoomCreatedIn()->CollisionPoint<T>(Point);
}

template<typename T>
bool SFMLGameObject::PlaceMeeting(const sf::Vector2f & Point)
{
	return GetRoomCreatedIn()->PlaceMeeting<T>(this, Point);
}

template<typename T>
T * SFMLGameObject::GetObjectAtPoint(const sf::Vector2f & Point)
{
	return GetRoomCreatedIn()->GetObjectAtPoint<T>(Point);
}

template<typename T>
T * SFMLGameObject::InstancePlace(const sf::Vector2f & Point)
{
	return GetRoomCreatedIn()->InstancePlace<T>(this, Point);
}

template<typename T>
std::vector<T *> SFMLGameObject::GetAllGameObjectsOfType()
{
	return GetRoomCreatedIn()->GetAllGameObjectsOfType<T>();
}
