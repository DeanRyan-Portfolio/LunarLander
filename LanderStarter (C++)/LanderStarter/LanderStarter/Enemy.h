#pragma once
#include "opengl.h"
#include "Vector.h"


class Enemy
{
	double rotation; 
    double rotationSpeed;
	Vector engine_acceleration;
	double gravity;
    bool flame;  
	bool explosion;
	bool Draw_Ship;
	Vector pos,vel;
	Vector pos2,vel2;
	int radius;
	bool dead;
	bool landed;
	int fuel;
	int lives;
	int explosion_random;
	bool BulletShowing;
	


	
public:
    Enemy(void);
public:
    ~Enemy(void);
public:
	Vector bulletPos,bulletVel;
	Vector bulletPos2,bulletVel2;
    void Draw(void);
	void DrawSecondEnemy();
	void Update();
	void Reset();
	void DrawBullet();
	void DrawBullet2();
	
};