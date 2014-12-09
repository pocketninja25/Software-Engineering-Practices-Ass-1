// clip.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#define ASEXPORT
#include "filterdll.h"
#include <cstdlib>

int filter(Measurement measurements[], int size, const TCHAR* parameter)
{
	double limit = _tstof(parameter);	//Convert TCHAR* parameter to a double

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