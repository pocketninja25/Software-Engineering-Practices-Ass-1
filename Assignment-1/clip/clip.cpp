// clip.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#define ASEXPORT
#include "filterdll.h"
#include <cstdlib>

int filter(Measurement measurements[], int size, char* parameter)
{
	//Bug in this where if the parameter > 1 character, it is chopped down to a single digit number 76 becomes 7, 4.5 becomes 4 etc...
	double limit = atof(parameter);

	for (int i = 0; i < size; i++)
	{
		if (measurements[i].theReading > limit)
		{
			measurements[i].theReading = limit;
		}
		else if (measurements[i].theReading < (-limit))
		{
			measurements[i].theReading = (-limit);
		}
	}
	return Success;
}