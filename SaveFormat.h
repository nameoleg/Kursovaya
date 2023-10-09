#pragma once
#include "LinkedList.h"

class SaveFormat
{
public:
	virtual ~SaveFormat() {};
	virtual void save(LinkedList* list, string filename) = 0;
};

