#pragma once
#include "opengl.h"
#include "Vector.h"


class Ufo
{
	Vector engine_acceleration;
	double gravity;
    bool flame;  
	bool explosion;
	bool Draw_Ship;
	float sides ;
	
	
	int radius;
	bool dead;
	bool landed;
	int fuel;
	int lives;
	int explosion_random;
	bool BulletShowing;
	
public:
    Ufo(void);
public:
    ~Ufo(void);
public:
	Vector pos,vel;
	Vector bulletPos,bulletVel;
	
	//
	Vector start1Ufo,end1Ufo,start2Ufo,end2Ufo,start3Ufo,end3Ufo,start4Ufo,end4Ufo;
    void Draw(void);
	void Update();
	void Reset();
	void DrawBullet();
	
};