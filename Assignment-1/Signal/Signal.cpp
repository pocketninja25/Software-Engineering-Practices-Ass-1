// signal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "usefilter.h"
#include <iostream>
#include <fstream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream inp;
	ofstream outp;
	char dummy[100];

	cout << "program starting" << endl;

	Measurement theMeasurements[MAXMEASUREMENTS];
	int numMeasurements = 0;

	char * inFileName = "..\\Debug\\measurements.txt"; // Change "Debug" for release mode
	char * outFileName = "..\\Debug\\measurementsout.txt"; // Change "Debug" for release mode

	inp.open(inFileName);
	while (inp && numMeasurements < MAXMEASUREMENTS)
	{
		inp >> theMeasurements[numMeasurements].theTime;
		inp >> theMeasurements[numMeasurements].theReading;
		if (inp)
		{
			numMeasurements++;
			// read the rest of the line - should just be a carriage return
			inp.getline(dummy, 100);
		}
	}
	inp.close();
