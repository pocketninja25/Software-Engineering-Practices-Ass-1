#include "stdafx.h"

const int Success = 0;
const int FilterNotFound = 103; // can't find dll for the filter
const int FilterInvalidFormat = 105; // Unable to find function in the dll
const int UnknownError = 107;

const int NAMESIZE = 20; // one more than the maximum number of filter (dll) name
const int MAXMEASUREMENTS = 1000;  // the maximum size of the array of MEASUREMENTS

class Measurement {
public:
	double theTime;
	double theReading;
};
