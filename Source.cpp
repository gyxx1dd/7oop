#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Student
{
private:
	string LastName;
	int uniquenumber;
	int rating;

public:
	Student()
	{

	}
	Student(string ln,int uniquenumber,int rating)
	{
		this->LastName = ln;
		this->uniquenumber = uniquenumber;
		this->rating = rating;
	}

	friend ostream& operator<<(ostream& os, const Student& student)
	{
		os << "LastName: " << student.LastName << ", Unique number: " << student.uniquenumber << ", Rating: " << student.rating;
		return os;
	}

	

	string getLastName() const { return LastName; }
	int getUniqueNumber() const { return uniquenumber; }
	int getRating() const { return rating; }


};

bool operator==(const Student& first, const Student& second)
{
	return (first.getLastName() == second.getLastName() &&
		first.getUniqueNumber() == second.getUniqueNumber() &&
		first.getRating() == second.getRating());
}



int main()
{
	stack<Student> inf;

	Student first("Pavlov", 123, 12);
	Student second("Maksimov", 534, 7);
	Student third("Golovach", 221, 2);

	inf.push(first);
	inf.push(second);
	inf.push(third);

	stack<Student> tempStack = inf;


	while (!tempStack.empty())
	{
		cout << tempStack.top() << endl;
		tempStack.pop();

	}
	tempStack = inf;

	string search;
	cout << endl;
	cout << "Input lastname for search: " << endl;
	cin >> search;

	
	while (!tempStack.empty())
	{
		if (tempStack.top().getLastName() == search)
		{
			cout << "Student was found!" << endl;
			cout << tempStack.top() << endl;
			break;
		}
		else
		{
			tempStack.pop();
		}


	}
	

	return 0;
}
