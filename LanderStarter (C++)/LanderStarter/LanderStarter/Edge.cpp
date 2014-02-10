#include "Edge.h"




bool Edge::WithinFirstSegment(Vector p)
{
	if(p.x>= start1.x && p.x <= end1.x)// 
		return true;

	else
		return false;
}
bool Edge::WithinSecondSegement(Vector p)
{

	if(p.x>= start2.x && p.x <= end2.x)// 
		return true;

	else
		return false;
}
bool Edge::WithinThirdSegement(Vector p)
{

	if(p.x>= start3.x && p.x <= end3.x)// 
		return true;

	else
		return false;
}
bool Edge::WithinForthSegement(Vector p)
{

	if(p.x>= start4.x && p.x <= end4.x)// 
		return true;

	else
		return false;
}


int Edge::Distance1(Vector p)
{
	float m=(float)(end1.y-start1.y)/(end1.x-start1.x);
	float y= m*(p.x-start1.x)+start1.y;
	return p.y-y;
}
int Edge::Distance2(Vector p)
{
	
	float m=(float)(end2.y-start2.y)/(end2.x-start2.x);
	float y= m*(p.x-start2.x)+start2.y;
	return p.y-y;

}
int Edge::Distance3(Vector p)
{
	
	float m=(float)(end3.y-start3.y)/(end3.x-start3.x);
	float y= m*(p.x-start3.x)+start3.y;
	return p.y-y;
}
int Edge::Distance4(Vector p)
{
	
	float m=(float)(end4.y-start4.y)/(end4.x-start4.x);
	float y= m*(p.x-start4.x)+start4.y;
	return p.y-y;
}



void Edge::TerrainCollision();
{
	
		if(edge.WithinFirstSegment(lander.pos) && edge.Distance1(lander.pos)<0 )
		{
			lander.dead=true;
		}
		if(edge.WithinSecondSegement(lander.pos) && edge.Distance2(lander.pos)<0)
		{
			lander.dead=true;
		}
		if(edge.WithinThirdSegement(lander.pos) && edge.Distance3(lander.pos)<0 )
		{
			lander.dead=true;
		}
		if(edge.WithinForthSegement(lander.pos) && edge.Distance4(lander.pos)<0)
		{
			lander.dead=true;
		}
}
void Edge::Draw()
{
		glBegin(GL_LINES);
		glVertex2d(start1.x,start1.y);
		glVertex2d(end1.x,end1.y);
		glVertex2d(start2.x,start2.y);
		glVertex2d(end2.x,end2.y);
		glVertex2d(start3.x,start3.y);
		glVertex2d(end3.x,end3.y);
		glVertex2d(start4.x,start4.y);
		glVertex2d(end4.x,end4.y);
		glEnd();


}
