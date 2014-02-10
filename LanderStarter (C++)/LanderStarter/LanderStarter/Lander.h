#pragma once
#include "opengl.h"
#include "Vector.h"
#include "Ufo.h"
#include "Shield.h"

class Lander
{
	
	
public:	

    double rotation; 
    double rotationSpeed;
	Vector engine_acceleration;
	double gravity;
    bool flame;  
	bool Draw_Ship;
	Vector pos,vel;
	int radius;
	bool dead;
	bool landed;
	int fuel;
	int score;

	int lives;
	
	
	
public:
    Lander(void);
public:
    ~Lander(void);
public:
    void Update();
    void Draw(void);
	void Reset();
	void Crash();
	void Landed();
	void StopShip();
	void CheckingLives();
public:
    void DrawFlame(void);
	void DrawExplosion();

};
