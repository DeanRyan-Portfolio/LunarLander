#pragma once
#include"opengl.h"
#include "Lander.h"
#include "time.h"
#include "Terrain.h"
#include "Ufo.h"
#include "Crash.h"
#include "Shield.h"


class Game
{
    int height,width;
	Lander lander;
	Terrain terrain;
	Ufo ufo;
	Crash effect[50];
	Shield shieldEffect[50];
	

public:
	
    Game(void);
	int mainMenu;
	
	int landed;
	int inGame;
	int gameOver;
	int gameState;
	int easy;
	int hard;
	int wft;
	int difficulty;
	bool greatLanding;
	
    ~Game(void);
    int Init(void);
    int Loop();
    int Done(void);
	void text();
	void terrainCollision();
	void scoreAccumlator();
	void UFOCollision();
	void CheckingLives();
	void difficultyText();
	void CrashWithTerrain();
	void Shield();
	void LandSucces();
	void PadCollision();


};
