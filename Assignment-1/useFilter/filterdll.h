#ifndef FILTERDLL_H
#define	FILTERDLL_H

#ifndef ASEXPORT
#define DLLIMPORTOREXPORT dllimport
#else
#define DLLIMPORTOREXPORT dllexport
#endif

#include "filtertypes.h"

#ifdef __cplusplus		//when using c++ use extern "c" to prevent name mangling of function
extern "C" {
#endif

_declspec(DLLIMPORTOREXPORT) int filter(Measurement measurements[], int size, const TCHAR* parameter);	//Prototype for filter function

#ifdef __cplusplus
}	//end extern "c"
#endif

#endif