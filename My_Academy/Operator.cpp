#include "Operator.h"

std::ostream& operator <<(std::ostream& os, const Human& obj)
{
	return obj.print(os);
}
std::ofstream& operator <<(std::ofstream& ofs, const Human& obj)
{
	obj.print(ofs);
	return ofs;
}
std::ifstream& operator >>(std::ifstream& ifs, Human& obj)
{
	return obj.scan(ifs);
}