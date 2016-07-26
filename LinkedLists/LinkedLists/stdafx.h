// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

// TODO: reference additional headers your program requires here
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>


// create a node (the building block of a singly linked list)
struct Node
{
	int Data;
	struct Node *Next;
};