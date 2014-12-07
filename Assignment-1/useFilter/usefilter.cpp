#include "stdafx.h"
#include "usefilter.h"


int Process(Measurement measurements[], int size, TCHAR* filterName, TCHAR* parameter)
{
	HINSTANCE hinstLib;
	Filter FilterProc;			//Function pointer to filter function
	BOOL fFreeResult = FALSE, fRunTimeLinkSuccess = FALSE, fLibFound = FALSE;
	int errorCode = Success;

	//Get handle to DLL
	hinstLib = LoadLibrary(filterName);

	//Try to get function address

	if (hinstLib != NULL)	//Handle is valid?
	{
		fLibFound = TRUE;
		FilterProc = (Filter)GetProcAddress(hinstLib, "filter");

		//try calling the function
		if (FilterProc != NULL)	//Function address is valid?
		{
			fRunTimeLinkSuccess = TRUE;
			errorCode = (FilterProc)(measurements, size, parameter);	//Attempt to Apply filter and take error code for returning
		}
		//Free the DLL
		fFreeResult = FreeLibrary(hinstLib);
	}


	//Error code returns

	if (!fRunTimeLinkSuccess)
	{
		//could not link to functions
		errorCode = FilterInvalidFormat;

	}
	if (!fFreeResult)
	{
		//Could not unload dll
		errorCode = UnknownError;
	}
	if (!fLibFound)
	{
		//Could not find dll
		errorCode = FilterNotFound;
	}


	return errorCode;

}

void Swap(Measurement &measurement1, Measurement &measurement2)
{
	Measurement hold;

	hold = measurement1;
	measurement1 = measurement2;
	measurement2 = hold;
	
}

void Sort(Measurement measurements[], int size, Compare compareFunction)
{
	bool swapped;
	do
	{
		swapped = false;	//Have values been swapped this pass
		size--;				//Adjust the end of the sort so already sorted values are not touched. Also reduces size to mark the end of the list

		for (int i = 0; i < size; i++)	//Count through unsorted array
		{
			//If pair is out of order

			if (compareFunction(&measurements[i], &measurements[i + 1]) > 0)	//If the measurements are not ordered
			{
				//Swap pair and note that a swap has occured
				Swap(measurements[i], measurements[i + 1]);
				swapped = true;
			} //End of if statement
		} //End of for loop

	} while (swapped);

}	//End of sort function


int CompareTimeAsc(const Measurement* item1, const Measurement* item2)
{
	return static_cast<int>(item1->theTime - item2->theTime);
}
int CompareTimeDesc(const Measurement* item1, const Measurement* item2)
{
	return static_cast<int>(item2->theTime - item1->theTime);
}