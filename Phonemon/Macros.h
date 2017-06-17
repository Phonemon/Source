/**
*	This file contains all the macros
**/

#pragma once

#include "Constants.h"

//Used to print some text on screen
#define DEBUG(x) \
	#if _DEBUG_\
		if (GEngine) \
			GEngine->AddOnScreenDebugMessage(MyNumberKey, 5.f, FColor::Red, TEXT(x));  \
	#endif /* _DEBUG_ */