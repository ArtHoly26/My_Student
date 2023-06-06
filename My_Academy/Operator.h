#pragma once
#include "Human.h"

std::ostream& operator <<(std::ostream& os, const Human& obj);
std::ofstream& operator <<(std::ofstream& ofs, const Human& obj);
std::ifstream& operator >>(std::ifstream& ifs, Human& obj);