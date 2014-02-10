#pragma once

class Shield
{
public:

	int shield1;
	int shield2;
	int sidesOfShield;
	int PI;
	int radiusOfShield;
	

public:
	Shield(void);
	~Shield(void);
	int shieldShowing(int point1, int point2);
};