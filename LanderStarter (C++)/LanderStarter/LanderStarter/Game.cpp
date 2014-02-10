#include "StdAfx.h"
#include "Game.h"
#include "opengl.h"
#include <string>
#include <sstream>
#include "Crash.h"
#include "Shield.h"


using namespace std;

Game::Game(void)
{	
	 
	 
	 lander.lives = 3;
	 mainMenu = 1;
	 inGame	  = 2;
	 gameOver = 3;
	 gameState= 1;
	 landed = 4;
	 difficulty = 0;
	 easy  = 0;
	 hard  = 0;
	 wft = 0;
	 greatLanding = false;

	 glPushMatrix();
	 glColor3f(139.0,69.0,19.0);
	 terrain.start1=Vector(0,0);
	 terrain.end1=Vector(300,200);
	 //  vector1
	 terrain.start2 = Vector(300,200);
	 terrain.end2  = Vector(600,100);
	 //  vector2
	 terrain.start3 = Vector(600,100);
	 terrain.end3 = Vector(900,300);
	 //  vector3
	 terrain.start4 = Vector(900,300);
	 terrain.end4 = Vector(1350,-100);	
	 //  vector4

	 //
	 ufo.start1Ufo = Vector(-20,-20);
	 ufo.end1Ufo = Vector(-20,20);
	//
	 ufo.start2Ufo = Vector(-20,20);
	 ufo.end2Ufo = Vector(20,20);
	
	 ufo.start3Ufo = Vector(20,20);
	 ufo.end3Ufo = Vector(20,-20);
	
	 ufo.start4Ufo  = Vector(20,-20);
	 ufo.end4Ufo = Vector(-20,-20);
}

Game::~Game(void)
{
}

int Game::Init(void)
{
    glEnable(GL_DEPTH_TEST); // check for depth
    
    return 0;
}

void Game::PadCollision()
{
	Terrain landingPadCollision;
	if(lander.pos.y < landingPadCollision.landingPadArray[0][1] + 12 && lander.pos.x > 0 && lander.pos.x < landingPadCollision.landingPadArray[1][0])
	{	 
     	if(!lander.rotation == 0)
		{
			lander.StopShip();
			CheckingLives();
			lander.Reset();
			if(lander.dead == true)
			{
				for(int i = 0; i < 50; i++)
				{
					if(effect[i].radius < 200)
					{
						effect[i].radius = effect[i].radius + 10;
						effect[i].crashEffect(lander.pos.x,lander.pos.y);
					}
				
				}
				for(int i = 0; i < 50; i++)
				{
					if(effect[i].radius < 200)
					{
						effect[i].radius = effect[i].radius + 10;
						effect[i].crashEffect(lander.pos.x,lander.pos.y);
					}
				
				}
		}
		lander.Reset();
		}
		else
		{

			greatLanding = true;
			lander.landed = true;
			lander.StopShip();
		}
	}
}
void Game::Shield()
{
	if(GetKeyState('H') & 128 )
	{
		if(lander.dead == false)
		{
				for(int i = 0; i < 50; i++)
				{
					if(shieldEffect[i].radiusOfShield < 200)
					{
						shieldEffect[i].shieldShowing (lander.pos.x,lander.pos.y);
					}
				}
		}
	
	}
}


void Game::CrashWithTerrain()
{
		if(lander.dead == true)
		{
				for(int i = 0; i < 50; i++)
				{
					if(effect[i].radius < 200)
					{
						effect[i].radius = effect[i].radius + 10;
						effect[i].crashEffect(lander.pos.x,lander.pos.y);
					}
				
				}
				for(int i = 0; i < 50; i++)
				{
					glColor3f(1.0,2,3);
					if(effect[i].radius < 200)
					{
						effect[i].radius = effect[i].radius + 10;
						effect[i].crashEffect(lander.pos.x,lander.pos.y);
					}
				
				}
		}
}

void Game::difficultyText()
{
		stringstream out;
		out << "1) EASY "; //String to output
		glRasterPos2i(900,600); //location of string
		glCallLists(out.str().length(),GL_UNSIGNED_BYTE,out.str().c_str());   
				
		stringstream out1;
		out1 << "2) HARD "; // String to Output
		glRasterPos2i(900,550); // location of string
		glCallLists(out1.str().length(),GL_UNSIGNED_BYTE,out1.str().c_str());

		stringstream out3;
		out3 << "3) WTF "; //String to output
		glRasterPos2i(900,500); //location of string
		glCallLists(out3.str().length(),GL_UNSIGNED_BYTE,out3.str().c_str()); 
}
void Game::CheckingLives()
{
	lander.lives = lander.lives - 1;
	if(lander.lives <= 0)
	{				
		gameState =1;
		lander.lives = 3;
	}
}
void Game::terrainCollision()
{
		if(terrain.WithinFirstSegment(lander.pos) && terrain.Distance1(lander.pos)<0 )
		{
				lander.dead=true;
				CrashWithTerrain();
				lander.Reset();
				CheckingLives();
		}

		if(terrain.WithinSecondSegement(lander.pos) && terrain.Distance2(lander.pos)<0)
		{
				lander.dead=true;
				CrashWithTerrain();
				lander.Reset();
				CheckingLives();
		}
		if(terrain.WithinThirdSegement(lander.pos) && terrain.Distance3(lander.pos)<0 )
		{
				lander.dead=true;
				CrashWithTerrain();
				lander.Reset();
				CheckingLives();
				
		}
		if(terrain.WithinForthSegement(lander.pos) && terrain.Distance4(lander.pos)<0)
		{
				lander.dead=true;
				CrashWithTerrain();
				lander.Reset();
				CheckingLives();
		}
}


void Game::text()
{
		stringstream out;
		out << "Fuel: " << lander.fuel; //String to output
		glRasterPos2i(900,500); //location of string
		glCallLists(out.str().length(),GL_UNSIGNED_BYTE,out.str().c_str());   
			
		stringstream out1;
		out1 << "velocity: " << lander.vel.y; // String to Output
		glRasterPos2i(900,600); // location of string
		glCallLists(out1.str().length(),GL_UNSIGNED_BYTE,out1.str().c_str());

		stringstream out3;
		out3 << "Lives: " << lander.lives; // String to Output
		glRasterPos2i(900,550); // location of string
		glCallLists(out3.str().length(),GL_UNSIGNED_BYTE,out3 .str().c_str());

		stringstream out4;
		out4 << "Score: " << lander.score; // String to Output
		glRasterPos2i(900,450); // location of string
		glCallLists(out4.str().length(),GL_UNSIGNED_BYTE,out4 .str().c_str());
}



int Game::Loop()

{///////////////////////////
	//main game logic goes here
	///////////////////////////
	static float angle =0.0f; // angle of rotation (in degrees)
	// Prepare to draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//clear buffers
	glMatrixMode(GL_MODELVIEW); // reset modelview matrix
	glLoadIdentity();
    OpenGL::Enable2D();	
	
	if(gameState == mainMenu)
	{
		difficultyText();
		if(GetKeyState('1') & 128 )
		{
			easy = 1;
			gameState =2;
			difficulty = easy;
			lander.fuel = 10000;
		}
		if(GetKeyState('2') & 128)
		{
			hard = 2;
			gameState = 2;
			difficulty = hard;
			lander.fuel = 1000;

		}
		if(GetKeyState('3') & 128)
		{
			wft = 3;
			gameState = 2;
			difficulty = wft;
			lander.fuel = 100;
		}
	}
	if(greatLanding  == true)
	{
		stringstream Gameover;
		Gameover << "Great Landing"; //String to output
		glRasterPos2i(500,500); //location of string
		glCallLists(Gameover.str().length(),GL_UNSIGNED_BYTE,Gameover.str().c_str());

		stringstream PlayAgain;
		PlayAgain << "Play Again"; //String to output
		glRasterPos2i(500,400); //location of string
		glCallLists(PlayAgain.str().length(),GL_UNSIGNED_BYTE,PlayAgain.str().c_str());
		
		stringstream Yes;
		Yes << "Y)es"; //String to output
		glRasterPos2i(400,350); //location of string
		glCallLists(Yes.str().length(),GL_UNSIGNED_BYTE,Yes.str().c_str());	

		stringstream No;
		No << "N)o"; //String to output
		glRasterPos2i(650,350); //location of string
		glCallLists(No.str().length(),GL_UNSIGNED_BYTE,No.str().c_str());	
		
		stringstream yourscore;
		yourscore << "Your Score is" << lander.score; //String to output
		glRasterPos2i(600,300); //location of string
		glCallLists(yourscore.str().length(),GL_UNSIGNED_BYTE,yourscore.str().c_str());	
		if(GetKeyState('Y') & 128 )
		{
			greatLanding  = false;
			gameState = 1;
			difficulty = 0;
			lander.Reset();
			ufo.Reset();
		}
		if(GetKeyState('N') & 128 )
		{
			return true;
		}
	}
	if(gameState == inGame && difficulty == easy )
	{
		if(lander.dead == false && lander.landed == false )
		{
			lander.score += 2;
		}
		if(lander.fuel == 0)
		{
			lander.dead = true;
			greatLanding = true;
		}
		Shield();
		PadCollision();
		terrainCollision();
		// update  the lander and draw it
		lander.Update();
		lander.Draw();
		//draw the terrain and landing pad
		terrain.landingPad();
		terrain.Draw();
		// drawing text for hud values 
		text();
	}
	if(gameState == inGame && difficulty == hard)
	{
		
		if(lander.dead == false && lander.landed == false )
		{
			lander.score += 2;
		}
		if(lander.fuel <= 0)
		{
			lander.dead = true;
			greatLanding = true;
		}
		Shield();
		PadCollision();
		terrainCollision();
		// terrain and pad collision
		ufo.Update();
		ufo.Draw();
		// update  the lander and draw it
		lander.Update();
		lander.Draw();
		//draw the terrain and landing pad
		terrain.landingPad();
		terrain.Draw();
		// drawing text for hud values 
		text();
	}
	if(gameState == inGame && difficulty == wft)
	{
		
		if(lander.dead == false && lander.landed == false )
		{
			lander.score += 2;
		}
		if(lander.fuel <= 0)
		{
			lander.dead = true;
			greatLanding = true;
		}
		Shield();
		PadCollision();
		terrainCollision();
		ufo.Update();
		ufo.Draw();
		// update  the lander and draw it
		lander.Update();
		lander.Draw();
		//draw the terrain and landing pad
		terrain.landingPad();
		terrain.Draw();
		// drawing text for hud values 
		
	}






	

	
	

	

	
	

	

				

	

	
	//put other drawing code here
	//....
    

	

	//then wait fot a key to quit
	//if the lander lands ok
	//display a message and wait for a key to quit
	
	if(GetKeyState(VK_ESCAPE) & 128)
		return true; //return true to quit the game

    
    OpenGL::Disable2D();
    OpenGL::Swap();
    return false; //return false if you want to continue game
}

int Game::Done(void)
{
    return 0;
}
