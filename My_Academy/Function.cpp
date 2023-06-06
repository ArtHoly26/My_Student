#define _CRT_SECURE_NO_WARNINGS
#include "Function.h"

void print(Human** group, const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << *group[i] << endl;
	}
}
void save(Human** group, const int n, const char* filename)
{
	ofstream fout(filename);
	for (int i = 0; i < n; i++)
	{
		fout << typeid(*group[i]).name() << ":\t";
		fout << *group[i] << endl;
	}
	fout.close();
	char command[FILENAME_MAX] = "notepad ";
	strcat(command, filename);
	system(command);
}
Human* HumanFactory(const std::string& type)
{
	if (type.find("Student") != std::string::npos)  return new Student("", "", 0, "", "", 0, 0);
	if (type.find("Graduate") != std::string::npos) return new Graduate("", "", 0, "", "", 0, 0, "");
	if (type.find("Teacher") != std::string::npos) return new Teacher("", "", 0, "", 0);
}
Human** load(const std::string& filename, int& n)
{
	std::ifstream fin(filename);
	Human** group = nullptr;
	if (fin.is_open())
	{
		std::string buffer;
		for (n = 0; !fin.eof(); n++)
		{
			std::getline(fin, buffer);
			if (buffer.empty())n--;
		}
		group = new Human * [n] {};

		fin.clear();
		fin.seekg(0);

		for (int i = 0; i < n; i++)
		{
			std::getline(fin, buffer, ':');
			group[i] = HumanFactory(buffer);
			fin.ignore();
			fin >> *group[i];
		}

		fin.close();
	}
	else
	{
		cout << "Error: file not found" << endl;
	}

	return group;
}