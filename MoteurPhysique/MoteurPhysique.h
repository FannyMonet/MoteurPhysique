#pragma once
#include "stdafx.h"
#include <vector>
using namespace std;

vector<particule> integrer(const vector<particule> &particules, double rate);
void showResult(const vector<particule> &particules, double totalTime);
