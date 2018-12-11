#pragma once
#include "vecteur3D.h"

// Simple point data type to insert into the tree.
// Have something with more interesting behavior inherit
// from this in order to store other attributes in the tree.
class OctreePoint {
	vecteur3D position;
public:
	OctreePoint() { }
	OctreePoint(const vecteur3D& position) : position(position) { }
	inline const vecteur3D& getPosition() const { return position; }
	inline void setPosition(const vecteur3D& p) { position = p; }
};