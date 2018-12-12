#include "stdafx.h"
#include "CollisionData.h"

CollisionData::CollisionData()
{
	contacts = new Contact[100];
}

void CollisionData::AddContact(Contact newContact)
{
	contactsRestant++;
	contacts[contactsRestant] = newContact;
}

bool CollisionData::ContactNull()
{
	if (contactsRestant == 0)
		return true;
	else
	{
		return false;
	}
	
}
