#pragma once
#include "stdafx.h"
#include "opengl.h"
#include "Vector.h"
#include "Lander.h"


class Terrain
{
	Lander lander;
	Ufo ufo;
	
public:
	Terrain(void);
    ~Terrain(void);
	
	float landPadRandom;
	int landingPadArray[2][2];
	void landingPad(void);
	
	Vector start1,end1,start2,end2,start3,end3,start4,end4;
	//
	//
	int Distance1(Vector p);
	int Distance2(Vector p);
	int Distance3(Vector p);
	int Distance4(Vector p);
	//
	//
	//
	//
	//
	//
	//
	bool WithinFirstSegment(Vector p);
	bool WithinSecondSegement(Vector p);
	bool WithinThirdSegement(Vector p);
	bool WithinForthSegement(Vector p);
	//
	//
	//
	//
	//
	//
	void Draw();
	void DrawEnemy();
	void TerrainCollision();
	


	
};
