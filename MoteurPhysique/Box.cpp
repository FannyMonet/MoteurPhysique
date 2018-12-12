#include "stdafx.h"
#include "Box.h"
#include "RectangleBody.h"


Box::Box()
{
}

Box::Box(RectangleBody* _body)
{
	body = _body;
	halfsizes.x = _body->dimensions.x / 2;
	halfsizes.y = _body->dimensions.y / 2;
	halfsizes.z = _body->dimensions.z / 2;
}


