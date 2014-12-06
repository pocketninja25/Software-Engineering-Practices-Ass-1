#include "stdafx.h"
#include "usefilter.h"


int Process(Measurement measurements[], int size, TCHAR* filterName, TCHAR* parameter)
{
	HINSTANCE hinstLib;
	Filter FilterProc;			//Function pointer to filter function
	BOOL fFreeResult, fRunTimeLinkSuccess, fLibFound = FALSE;
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

void Swap(void* value1, void* &measurement2, int itemSize)
{
	char hold;

	for (int i = 0; i < itemSize; i++)	//Count through bytes of data items
	{
		hold = *(static_cast<char*> (value1)+i));		//Convert void pointer to char pointer to perform pointer arithmetic per byte then store value at pointer address in hold variable
		*(static_cast<char*> (value1)+i)) = *(static_cast<char*> (measurement2)+i));	//Set value at 
		*(static_cast<char*> (measurement2)+i)) = hold;
	}

	void Sort(void* base, int num, int size, Compare compareFunc)
	{
		char* incBase = static_cast<char*> (base);		//Convert pointer to char so can increment the pointer's value - char is 1 byte
		bool swapped;
		do
		{
			swapped = false;	//Have values been swapped this pass
			num--;		//Adjust the end of the sort so already sorted values are not touched 
			//also reduces size to mark the end of the list

			for (int i = 0; i < size; i++)	//Count through unsorted array
			{
				//If pair is out of order

				//Use casting to convert base pointer to char to do mathematics to find the elements of the array based on size and position of the elements
				if (compareFunc(static_cast<void*>(static_cast<char*>(base)+(i       * size)),	//basepointer + (arrayposition * sizeofelement) gives the address of the arrayposition-th item
					static_cast<void*>(static_cast<char*>(base)+((i + 1) * size))
					) > 0)																	//simplified - if (compareFunc(array[i], array[i + 1]))  > 0) //Items Need swapping
				{
					//Swap pair and note that a swap has occured
					Swap(measurements[i], measurements[i + 1]);
					swapped = true;
				} //End of if statement
			} //End of for loop

		} while (swapped);

	}	//End of sort function