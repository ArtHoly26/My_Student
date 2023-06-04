#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define HUMAN_TAKE_PARAMETRS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETRS last_name, first_name, age
class Human
{
	static const int LAST_NAME_WIDTH = 18;
	static const int FIRST_NAME_WIDTH = 10;
	std::string last_name;
	std::string first_name;
	int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}

	Human(HUMAN_TAKE_PARAMETRS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
	}
	~Human()
	{

	}

	virtual std::ostream& print(std::ostream& os)const
	{
		return os << last_name << " " << first_name << " " << age << " y/o";
	}
	virtual std::ofstream& print(std::ofstream& ofs)const
	{
		ofs.width(LAST_NAME_WIDTH);
		ofs << std::left;
		ofs << last_name;
		ofs.width(FIRST_NAME_WIDTH);
		ofs << first_name;
		ofs.width(3);
		ofs << age;
		return ofs;
	}
	virtual std::ifstream& scan(std::ifstream& ifs)
	{
		ifs >> last_name >> first_name >> age;
		return ifs;
	}
};

std::ostream& operator <<(std::ostream& os, const Human& obj)
{
	return obj.print(os);
}
std::ofstream& operator <<(std::ofstream& ofs,const Human& obj) 
{
	obj.print(ofs);
	return ofs;
}
std::ifstream& operator >>(std::ifstream& ifs,Human& obj)
{
	return obj.scan(ifs);
}

#define STUDENT_TAKE_PARAMETRS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETRS speciality, group, rating, attendance
class Student :public Human
{
	static const int SPECIALITY_WIDTH = 20;
	static const int GROUP_WIDTH = 8;
	static const int RATING_WIDTH = 8;
	static const int ATTENDANCE_WIDTH = 8;
	std::string speciality;
	std::string group;
	double rating;
	double attendance;

public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	Student(HUMAN_TAKE_PARAMETRS, STUDENT_TAKE_PARAMETRS) :Human(HUMAN_GIVE_PARAMETRS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
	}

	~Student()
	{

	}

	std::ostream& print(std::ostream& os) const
	{
		return Human::print(os)<<" "<< speciality << " " << group << " " << rating << " " << attendance;
	}
	std::ofstream& print (std::ofstream& ofs) const
	{
		Human::print(ofs);
		ofs.width(SPECIALITY_WIDTH);
		ofs << speciality;
		ofs.width(GROUP_WIDTH);
		ofs << group;
		ofs.width(RATING_WIDTH);
		ofs << rating;
		ofs.width(ATTENDANCE_WIDTH);
		ofs << attendance;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)
	{
		Human::scan(ifs);
		char buffer[SPECIALITY_WIDTH+1] = {};
		ifs.read(buffer, SPECIALITY_WIDTH);
		for (int i = strlen(buffer) - 1; buffer[i] == ' '; i--) buffer[i] = 0;
		while (buffer[0] == ' ')for (int i = 0; buffer[i]; i++) buffer[i] = buffer[i + 1];
		speciality = buffer;
		ifs >> group;
		ifs >> rating >> attendance;
		return ifs;
	}

};

#define TEACHER_TAKE_PARAMETRS const std::string& speciality,int experience
#define TEACHER_GIVE_PARAMETRS speciality, experience
class Teacher : public Human
{
	static const int SPECIALITY_WIDTH = 22;
	static const int EXPERIENCE_WIDTH = 3;
	std::string speciality;
	int experience;

public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(int experience)
	{
		this->experience = experience;
	}

	Teacher(HUMAN_TAKE_PARAMETRS, TEACHER_TAKE_PARAMETRS) :Human(HUMAN_GIVE_PARAMETRS)
	{
		set_speciality(speciality);
		set_experience(experience);
	}

	~Teacher()
	{

	}

	std::ostream& print(std::ostream& os)const
	{
		return Human::print(os)<<" " << speciality << " " << experience;
	}
	std::ofstream& print(std::ofstream& ofs)const
	{
		Human::print(ofs);
		ofs.width(SPECIALITY_WIDTH);
		ofs << speciality;
		ofs.width(EXPERIENCE_WIDTH);
		ofs << experience;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)
	{
		Human::scan(ifs);
		char buffer[SPECIALITY_WIDTH + 1] = {};
		ifs.read(buffer, SPECIALITY_WIDTH);
		speciality = buffer;
		ifs >> experience;
		return ifs;
	}
	
};

class Graduate : public Student
{
	std::string subject;

public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}

	Graduate(HUMAN_TAKE_PARAMETRS, STUDENT_TAKE_PARAMETRS, const string& subject) :Student(HUMAN_GIVE_PARAMETRS, STUDENT_GIVE_PARAMETRS)
	{
		this->subject = subject;
	}
	
	std:: ostream& print(std::ostream& os)const
	{
		return Student::print(os) << " " << subject;
	}
	std::ofstream& print(std::ofstream& ofs) const
	{
		Student::print(ofs);
		ofs << subject;
		return ofs;
	}
	std::ifstream& scan(std::ifstream& ifs)
	{
		Student::scan(ifs);
		std::getline(ifs, subject);
		return ifs;
	}
};

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
	if (type.find("Graduate") != std::string::npos) return new Graduate("", "", 0, "", "", 0, 0,"");
	if (type.find("Teacher") != std::string::npos) return new Teacher("", "", 0, "",0);
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
		group = new Human *[n]{};

		fin.clear();
		fin.seekg(0);

		for (int i = 0; i < n; i++)
		{
			std::getline(fin, buffer, ':');
			group[i] = HumanFactory(buffer);
			fin.ignore();
			fin >>*group[i];
		}

		fin.close();
	}
	else
	{
		cout << "Error: file not found" << endl;
	}

	return group;
}

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