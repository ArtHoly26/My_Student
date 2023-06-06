#define _CRT_SECURE_NO_WARNINGS
#include "Human.h"
#include "Student.h"
#include "Graduate.h"
#include "Teacher.h"
#include "Operator.h"
#include "Function.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Rus");
	int n = 0;
	/*Human* group[] =
	{
		new Student("Oleg", "Zelenskii", 25, "Game-dev", "221SBD ", 85, 70),
		new Teacher("White", "Walter", 50, "Chemistry ", 20),
		new Graduate("Schreader", "Hank", 40, "Criminalistic", "OBN", 90, 70, "How to catch Heizenburg"),
		new Student("Nikolay", "Remark", 36,"Front-dev","245SBD",90,80),
		new Teacher("Dmitry", "Gorlan", 25,"Weapons distr",25),
		new Graduate("Rosenberg","Ken", 27, "Lower","Vice", 75,20,"Get money back")
	};*/
	Human** group = load("group.txt", n);
	print(group, n);

	for (int i = 0; i < n; i++)
	{
		delete group[i];
	}
	delete[] group;
	group = nullptr;

}