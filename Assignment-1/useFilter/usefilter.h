#ifndef USEFILTER_H
#define USEFILTER_H

#include "stdafx.h"
#include "filtertypes.h"
#include <Windows.h>
#include <stdio.h>

int Process(Measurement measurements[], int size, TCHAR * filterName, TCHAR * parameter);

void Sort(Measurement measurements[], int size);

void Sort(void* base, int num, int size, Compare );

#endif