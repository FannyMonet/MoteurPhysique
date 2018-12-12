#pragma once
#include "Contact.h"

class CollisionData
{
public:
	Contact* contacts;
	int contactsRestant =0;
	CollisionData();
	void AddContact(Contact	newContact) {
		contactsRestant++;
		contacts[contactsRestant] = newContact;
	}
	
	
};

