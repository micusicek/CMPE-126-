#pragma once
#include <ostream>

class clockType
{
private:
	int Hour;
	int Minutes;
	int Seconds;
public:
	clockType(int Hour, int Minutes, int Seconds = 0);
	~clockType();
	friend std::ostream& operator << (std::ostream& os, const clockType& c);
	friend clockType operator + (const clockType& one, const clockType& two);
};

