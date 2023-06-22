#include "ResourceManager.h"
#include "SFMLFont.h"
#include "SFMLGame.h"
#include "SFMLGameObject.h"
#include "SFMLMouse.h"
#include "SFMLRoom.h"

SFMLGameObject::SFMLGameObject(const std::string & ResourceName,
						       float XStart,
	                           float YStart,
	                           int HFrames,
	                           int VFrames)
	: Sprite(new sf::Sprite()),
	  HorizontalFrames(HFrames),
	  VerticalFrames(VFrames),
	  TotalFrames(HorizontalFrames * VerticalFrames),
	  Visible(true),
	  Depth(0),
	  ImageIndex(0),
	  ImageSpeed(1),
	  StartPosition(sf::Vector2f(XStart, YStart)),
	  PreviousPosition(sf::Vector2f(XStart, YStart)),
	  Velocity(sf::Vector2f(0,0)),
	  Acceleration(sf::Vector2f(0, 0)),
	  DirectionInDegrees(0),
	  AccelerationDirectionInDegrees(0),
	  Friction(0),
	  ImageAngleSpeed(0),
	  RoomCreatedIn(nullptr)
{
	// NOTE:  RoomCreateIn will be filled in by the room object that creates it

	Sprite->setTexture(*(SFMLGame::GetInstance()->GetResourceManager()->GetTexture(ResourceName)));
	Sprite->setPosition(XStart, YStart);
}

SFMLGameObject::~SFMLGameObject()
{
	delete Sprite;
}

void SFMLGameObject::SetVisible(bool Value)
{
	Visible = Value;
}

bool SFMLGameObject::GetVisible()
{
	return Visible;
}

void SFMLGameObject::PreUpdate(const sf::Time & DeltaTime)
{
	PreviousPosition = Sprite->getPosition();
}

void SFMLGameObject::Update(const sf::Time & DeltaTime)
{
	SetPosition(GetPosition() + GetVelocity());
	SetVelocity(GetVelocity() + GetAcceleration());
	SetSpeed(GetSpeed() - GetFriction());
	SetImageIndex(GetImageIndex() + GetImageSpeed());
	SetImageAngle(GetImageAngle() + GetImageAngleSpeed());
}

void SFMLGameObject::Draw()
{
	int WIDTH = GetSpriteWidth(); 
	int HEIGHT = GetSpriteHeight(); 
	
	int Whole = static_cast<int>(ImageIndex);
	int XPOS = Whole % HorizontalFrames * WIDTH;
	int YPOS = Whole / HorizontalFrames * HEIGHT;
		
	Sprite->setTextureRect(sf::IntRect(XPOS, YPOS, WIDTH, HEIGHT));
	SFMLGame::GetInstance()->GetWindow()->draw(*Sprite);
}

float SFMLGameObject::GetImageAngle()
{
	return Sprite->getRotation();
}

void SFMLGameObject::SetImageAngle(float Value)
{
	Sprite->setRotation(Value);
}

void SFMLGameObject::SetImageAngleSpeed(float Value)
{
	ImageAngleSpeed = Value;
}

float SFMLGameObject::GetImageAngleSpeed()
{
	return ImageAngleSpeed;
}

float SFMLGameObject::GetImageIndex()
{
	return ImageIndex;
}

void SFMLGameObject::SetImageIndex(float Value)
{
	// A lot of math to do if image speed doesn't matter!
		ImageIndex = Value;

		if (ImageIndex >= TotalFrames)
		{
			int Whole = static_cast<int>(ImageIndex);
			float Fractional = ImageIndex - Whole;
			ImageIndex = (Whole % TotalFrames) + Fractional;
		}
		else if (ImageIndex < 0)
		{
			int Whole = static_cast<int>(ImageIndex);
			float Fractional = ImageIndex - Whole;
			ImageIndex = TotalFrames + (Whole % TotalFrames) + Fractional;
		}
	
}

int SFMLGameObject::GetDepth()
{
	return Depth;
}

void SFMLGameObject::SetDepth(int Value)
{
	if (Value != Depth)
	{
		Depth = Value;
		RoomCreatedIn->DepthOrderChangeMade();
	}
}

sf::Sprite * SFMLGameObject::GetSprite()
{
	return Sprite;
}

int SFMLGameObject::GetSpriteWidth()
{
	return Sprite->getTexture()->getSize().x / HorizontalFrames;
}

int SFMLGameObject::GetSpriteHeight()
{
	return Sprite->getTexture()->getSize().y / VerticalFrames;
}

float SFMLGameObject::GetImageSpeed()
{
	return ImageSpeed;
}

void SFMLGameObject::SetImageSpeed(float Value)
{
	ImageSpeed = Value;
}

void SFMLGameObject::SetPosition(const sf::Vector2f & Value)
{
	Sprite->setPosition(Value);
}

void SFMLGameObject::SetPosition(float X, float Y)
{
	SetPosition(sf::Vector2f(X, Y));
}

void SFMLGameObject::SetX(float Value)
{
	SetPosition(sf::Vector2f(Value, Sprite->getPosition().y));
}

void SFMLGameObject::SetY(float Value)
{
	SetPosition(sf::Vector2f(Sprite->getPosition().x, Value));
}

sf::Vector2f SFMLGameObject::GetPosition()
{
	return Sprite->getPosition();
}

float SFMLGameObject::GetX()
{
	return Sprite->getPosition().x;
}

float SFMLGameObject::GetY()
{
	return Sprite->getPosition().y;
}

void SFMLGameObject::SetStartPosition(const sf::Vector2f & Value)
{
	StartPosition = Value;
}

void SFMLGameObject::SetStartPositionX(float Value)
{
	StartPosition.x = Value;
}

void SFMLGameObject::SetStartPositionY(float Value)
{
	StartPosition.y = Value;
}

sf::Vector2f SFMLGameObject::GetStartPosition()
{
	return StartPosition;
}

float SFMLGameObject::GetStartPositionX()
{
	return StartPosition.x;
}

float SFMLGameObject::GetStartPositionY()
{
	return StartPosition.y;
}

void SFMLGameObject::SetPreviousPosition(const sf::Vector2f & Value)
{
	PreviousPosition = Value;
}

void SFMLGameObject::SetPreviousPositionX(float Value)
{
	PreviousPosition.x = Value;
}

void SFMLGameObject::SetPreviousPositionY(float Value)
{
	PreviousPosition.y = Value;
}

sf::Vector2f SFMLGameObject::GetPreviousPosition()
{
	return PreviousPosition;
}

float SFMLGameObject::GetPreviousPositionX()
{
	return PreviousPosition.x;
}

float SFMLGameObject::GetPreviousPositionY()
{
	return PreviousPosition.y;
}

int SFMLGameObject::GetImageNumber()
{
	return TotalFrames;
}

void SFMLGameObject::SetImageScale(const sf::Vector2f & Value)
{
	Sprite->setScale(Value);
}

void SFMLGameObject::SetImageScale(float ScaleX, float ScaleY)
{
	SetImageScale(sf::Vector2f(ScaleX, ScaleY));
}

void SFMLGameObject::SetImageScaleX(float Value)
{
	SetImageScale(sf::Vector2f(Value, Sprite->getScale().y));
}

void SFMLGameObject::SetImageScaleY(float Value)
{
	SetImageScale(sf::Vector2f(Sprite->getScale().x, Value));
}

sf::Vector2f SFMLGameObject::GetImageScale()
{
	return Sprite->getScale();
}

float SFMLGameObject::GetImageScaleX()
{
	return Sprite->getScale().x;
}

float SFMLGameObject::GetImageScaleY()
{
	return Sprite->getScale().y;
}

void SFMLGameObject::SetSpriteOffset(const sf::Vector2f & Value)
{
	Sprite->setOrigin(Value);
	// TODO!
	// TODO!
	// TODO:  Fix up so sprite doesn't move when you change these settings
	// TODO!
	// TODO!
}

void SFMLGameObject::SetSpriteOffsetX(float Value)
{
	SetSpriteOffset(sf::Vector2f(Value, Sprite->getOrigin().y));
}

void SFMLGameObject::SetSpriteOffsetY(float Value)
{
	SetSpriteOffset(sf::Vector2f(Sprite->getOrigin().x, Value));
}

sf::Vector2f SFMLGameObject::GetSpriteOffset()
{
	return Sprite->getOrigin();
}

float SFMLGameObject::GetSpriteOffsetX()
{
	return Sprite->getOrigin().x;
}

float SFMLGameObject::GetSpriteOffsetY()
{
	return Sprite->getOrigin().y;
}

void SFMLGameObject::DrawLine(float X0, float Y0, float X1, float Y1, const sf::Color & Color)
{
	sf::Sprite Line;
	Line.setTexture(*(SFMLGame::GetInstance()->GetResourceManager()->GetTexture("1x1White")));
	Line.setPosition(X0, Y0);
	Line.setColor(Color);

	float DX = X1 - X0;
	float DY = Y1 - Y0;
	float SCALE_Y = Line.getScale().y;

	float Direction = ConvertRadiansToDegrees(atan2(DY, DX));
	if (Direction < 0)
	{
		Direction += 360;
	}
	
	Line.setScale(sqrt((DX*DX) + (DY*DY)), SCALE_Y);
	Line.setRotation(Direction);
	SFMLGame::GetInstance()->GetWindow()->draw(Line);
}

float SFMLGameObject::DistanceToPoint(const sf::Vector2f Point)
{
	return DistanceToPoint(Point.x, Point.y);
}

float SFMLGameObject::DistanceToPoint(float X, float Y)
{
	sf::Vector2f Position(Sprite->getPosition());
	float dx = X - Position.x;
	float dy = Y - Position.y;
	return sqrt((dx * dx) + (dy * dy));
}

float SFMLGameObject::DistanceToObject(SFMLGameObject * Object)
{
	sf::Vector2f Position(Object->GetPosition());
	return DistanceToPoint(Position.x, Position.y);
}

unsigned char SFMLGameObject::GetImageAlpha()
{
	return Sprite->getColor().a;
}

void SFMLGameObject::SetImageAlpha(unsigned char Value)
{
	sf::Color Color = Sprite->getColor();
	Color.a = Value;
	Sprite->setColor(Color);
}

void SFMLGameObject::SetImageTint(const sf::Color & Value)
{
	Sprite->setColor(Value);
}

void SFMLGameObject::SetImageTint(unsigned char Red, unsigned char Green, unsigned char Blue)
{
	sf::Color Color = Sprite->getColor();
	Color.r = Red;
	Color.g = Green;
	Color.b = Blue;
	Sprite->setColor(Color);
}

void SFMLGameObject::SetImageTintRed(unsigned char Value)
{
	sf::Color Color = Sprite->getColor();
	Color.r = Value;
	Sprite->setColor(Color);
}

void SFMLGameObject::SetImageTintGreen(unsigned char Value)
{
	sf::Color Color = Sprite->getColor();
	Color.g = Value;
	Sprite->setColor(Color);
}

void SFMLGameObject::SetImageTintBlue(unsigned char Value)
{
	sf::Color Color = Sprite->getColor();
	Color.b = Value;
	Sprite->setColor(Color);
}

sf::Color SFMLGameObject::GetImageTint()
{
	return Sprite->getColor();
}

unsigned char SFMLGameObject::GetImageTintRed()
{
	return Sprite->getColor().r;
}

unsigned char SFMLGameObject::GetImageTintGreen()
{
	return Sprite->getColor().g;
}

unsigned char SFMLGameObject::GetImageTintBlue()
{
	return Sprite->getColor().b;
}

sf::Vector2f SFMLGameObject::GetVelocity()
{
	return Velocity;
}

float SFMLGameObject::GetVelocityX()
{
	return Velocity.x;
}

float SFMLGameObject::GetVelocityY()
{
	return Velocity.y;
}

float SFMLGameObject::ConvertRadiansToDegrees(float Value)
{
	return (Value * 180.0f / 3.14159265f);
}

float SFMLGameObject::ConvertDegreesToRadians(float Value)
{
	return (Value * 3.14159265f / 180.0f);
}

// ------  ABOVE "WORKS"

void SFMLGameObject::SetAcceleration(const sf::Vector2f & Value)
{
	Acceleration = Value;

	sf::Vector2f Vector = Acceleration;
	float Magnitude = sqrt((Vector.x * Vector.x) + (Vector.y * Vector.y));

	if (Magnitude != 0)
	{
		AccelerationDirectionInDegrees = ConvertRadiansToDegrees(atan2(-Acceleration.y, Acceleration.x));
	}
}

void SFMLGameObject::SetAccelerationX(float Value)
{
	SetAcceleration(sf::Vector2f(Value, GetAcceleration().y));
}

void SFMLGameObject::SetAccelerationY(float Value)
{
	SetAcceleration(sf::Vector2f(GetAcceleration().x, Value));
}

void SFMLGameObject::SetAccelerationDirectionInDegrees(float Value)
{
	AccelerationDirectionInDegrees = Value;

	// Mod it to the 360 degree circle
	if ((AccelerationDirectionInDegrees < 0) || (AccelerationDirectionInDegrees >= 360.f))
	{
		AccelerationDirectionInDegrees = static_cast<int>(Value) % 360;
		if (AccelerationDirectionInDegrees < 0)
		{
			AccelerationDirectionInDegrees += 360.0f;
		}
	}

	sf::Vector2f Vector = Acceleration;
	float Magnitude = sqrt((Vector.x * Vector.x) + (Vector.y * Vector.y));

	float Radians = ConvertDegreesToRadians(AccelerationDirectionInDegrees);
	Acceleration = sf::Vector2f(Magnitude * cos(Radians), -Magnitude * sin(Radians));
}

float SFMLGameObject::GetAccelerationDirectionInDegrees()
{
	return AccelerationDirectionInDegrees;
}

void SFMLGameObject::SetSpeed(float Value)
{
	// Speed does not change Direction but it does change Velocity, VelocityX, VelocityY
	if (Value > 0)
	{
		float Radians = ConvertDegreesToRadians(DirectionInDegrees);
		Velocity = sf::Vector2f(Value * cos(Radians), -Value * sin(Radians));
	}
	else
	{
		Velocity = sf::Vector2f(0.0f, 0.0f);
	}
}

void SFMLGameObject::SetDirectionInDegrees(float Value)
{
	// Direction does not change Speed but it does change Velocity, VelocityX, VelocityY
	float Speed = GetSpeed();

	// Mod it to the 360 degree circle
	DirectionInDegrees = Value;
	if ((DirectionInDegrees < 0) || (DirectionInDegrees >= 360.f))
	{
		DirectionInDegrees = static_cast<int>(Value) % 360;
		if (DirectionInDegrees < 0)
		{
			DirectionInDegrees += 360.0f;
		}
	}
	
	float Radians = ConvertDegreesToRadians(DirectionInDegrees);
	Velocity = sf::Vector2f(Speed * cos(Radians), -Speed * sin(Radians));
}

void SFMLGameObject::SetVelocity(const sf::Vector2f & Value)
{
	// This can potentially change Speed, Velocity, Direction, VelocityX, VelocityY
	Velocity = Value;
	
	// Only change direction if speed is not zero
	if (GetSpeed() != 0)
	{
		DirectionInDegrees = ConvertRadiansToDegrees(atan2(-Velocity.y, Velocity.x));
	}
}

void SFMLGameObject::SetVelocityX(float Value)
{
	// This can potentially change Speed, Velocity, Direction, VelocityX, VelocityY
	SetVelocity(sf::Vector2f(Value, GetVelocity().y));
}

void SFMLGameObject::SetVelocityY(float Value)
{
	// This can potentially change Speed, Velocity, Direction, VelocityX, VelocityY
	SetVelocity(sf::Vector2f(GetVelocity().x, Value));
}

sf::Vector2f SFMLGameObject::GetAcceleration()
{
	return Acceleration;
}

float SFMLGameObject::GetAccelerationX()
{
	return Acceleration.x;
}

float SFMLGameObject::GetAccelerationY()
{
	return Acceleration.y;
}

float SFMLGameObject::GetSpeed()
{
	sf::Vector2f Vector = Velocity;
	return sqrt((Vector.x * Vector.x) + (Vector.y * Vector.y));
}

float SFMLGameObject::GetDirectionInDegrees()
{
	return DirectionInDegrees;
}

void SFMLGameObject::SetFriction(float Value)
{
	Friction = std::max<float>( 0.0f, Value );
}

float SFMLGameObject::GetFriction()
{
	return Friction;
}

void SFMLGameObject::MotionSet(float Speed, float DirectionInDegrees)
{
	float Radians = ConvertDegreesToRadians(DirectionInDegrees);
	sf::Vector2f Vector(Speed * cos(Radians), -Speed * sin(Radians));
	SetVelocity(Vector);
}

void SFMLGameObject::MotionAdd(float Speed, float DirectionInDegrees)
{
	float Radians = ConvertDegreesToRadians(DirectionInDegrees);
	sf::Vector2f Vector(Speed * cos(Radians), -Speed * sin(Radians));
	SetVelocity(GetVelocity() + Vector);
}

void SFMLGameObject::SetRoomCreatedIn(SFMLRoom * Room)
{
	RoomCreatedIn = Room;
}

SFMLRoom * SFMLGameObject::GetRoomCreatedIn()
{
	return RoomCreatedIn;
}

sf::Rect<float> SFMLGameObject::GetBoundingBox()
{
	return sf::Rect<float>(Sprite->getPosition(),
		sf::Vector2f(GetSpriteWidth(), GetSpriteHeight()));
}

void SFMLGameObject::OnCollision( SFMLGameObject * Other )
{
	// Derived classes will complete this...
}