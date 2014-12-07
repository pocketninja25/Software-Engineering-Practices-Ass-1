// signal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "usefilter.h"
#include <iostream>
#include <fstream>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream inp;											//file input stream
	ofstream outp;											//file output stream
	char dummy[100];

	cout << "program starting" << endl << endl;

	Measurement theMeasurements[MAXMEASUREMENTS];
	int numMeasurements = 0;								//Running count of loaded measurements

#ifdef _DEBUG
	//Use Debug folder for debug version
	char * inFileName = "..\\Debug\\measurements.txt";		
	char * outFileName = "..\\Debug\\measurementsout.txt";	
#else
	//Use Release folder for release version
	char * inFileName = "..\\Release\\measurements.txt";	
	char * outFileName = "..\\Release\\measurementsout.txt";
#endif

	/*Read in measurements from file*/
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
	/*End of file read-in*/

	//Output read-in values to screen
	cout << "Original:" << endl;
	for (int i = 0; i < numMeasurements; i++)
	{
		cout << "Time: " << theMeasurements[i].theTime <<
			" " << "Reading: " << theMeasurements[i].theReading << endl; //Output to screen
	}
	cout << endl;

	int result;		//Code returned by filter

	//Sort(theMeasurements, numMeasurements, CompareTimeAsc);	//Sort file in ascending order based on time

	result = Process(theMeasurements, numMeasurements, TEXT("clip"), TEXT("76"));	//Call the filter handler function to appy the filter
	if (result != Success)
	{
		cout << "Filter failed with error code: " << result << endl;	//Report error code returned by process
	}
	else	//Output 
	{
		outp.open(outFileName);
		cout << "Filtered: " << endl;
		for (int i = 0; i < numMeasurements; i++)
		{
			//Output to file
			outp << theMeasurements[i].theTime << " " << theMeasurements[i].theReading << endl;
			//Output to screen
			cout << "Time: " << theMeasurements[i].theTime << 
				" " << "Reading: " << theMeasurements[i].theReading << endl; 

		}
		outp.close();
	}
	cout << endl;

	system("pause");
	return 0;
}

