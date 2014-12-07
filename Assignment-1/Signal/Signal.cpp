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


	//Set the input and output names based on being in the same folder as the executable
	char * inFileName = ".\\measurements.txt";		
	char * outFileName = ".\\measurementsout.txt";	


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

	Sort(theMeasurements, numMeasurements, CompareTimeAsc);	//Sort file in ascending order based on time

	//Output read-in values to screen
	cout << "Original:" << endl;
	for (int i = 0; i < numMeasurements; i++)
	{
		cout << "Time: " << theMeasurements[i].theTime <<
			" " << "Reading: " << theMeasurements[i].theReading << endl; //Output to screen
	}
	cout << endl;

	int result;		//Code returned by filter


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

