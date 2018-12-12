#pragma once
#include "Contact.h"

class CollisionData
{
public:
	Contact* contacts;
	int contactsRestant;
	CollisionData();
};

