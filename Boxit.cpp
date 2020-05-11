/*
	Problem:

	Design a class named Box whose dimensions are integers and private to the class. The dimensions are labelled: length , breadth , and height .

	The default constructor of the class should initialize , , and  to .

	The parameterized constructor Box(int length, int breadth, int height) should initialize Box's  and  to length, breadth and height.

	The copy constructor BoxBox ) should set  and  to 's  and , respectively.

	Apart from the above, the class should have  functions:

	int getLength() - Return box's length
	int getBreadth() - Return box's breadth
	int getHeight() - Return box's height
	long long CalculateVolume() - Return the volume of the box
	Overload the operator  for the class Box. Box   Box  if:
		1. A.l < B.l
		2. A.b < B.b and A.l == B.l
		3. A.h < B.h and A.b == B.b and A.l == B.l

	Overload operator << for the class Box().

	If B is an object of class Box:
		cout << B should print B.l, B.b and B.h on a single line separated by spaces.

	Constraints:
	0 <= l,b,h <= 100000

*/


//SOLUTION
#include<bits/stdc++.h>

using namespace std;

class Box {
private:
	int l, b, h;

public:
	// default constructor of the class
	Box() {
		l = 0, b = 0, h = 0;
	}

	//parameterized constructor Box
	Box(int length, int breadth, int height) {
		l = length;
		b = breadth;
		h = height;
	}
	//copy constructor Box
	Box(Box& B) {
		l = B.l;
		b = B.b;
		h = B.h;
	}
	//Return box's length
	int getLength() {
		return l;
	}
	//Return box's breadth
	int getBreadth() {
		return b;
	}
	//Return box's height
	int getHeight() {
		return h;
	}
	// Return the volume of the box
	long long CalculateVolume() {
		return (long long)l * b * h;
	}

	bool operator <(const Box& d) {
		bool status = false;
		if ((l < d.l) || (b < d.b && l == d.l) || (h < d.h && b == d.b && l == d.l)) {
			status = true;
		}
		return status;
	}


	friend ostream& operator << (ostream& out, const Box& B);
};



// printing the length, breadth and height of Box B
ostream& operator << (ostream& out, const Box& B)
{
	out << B.l << " " << B.b << " " << B.h;

	return out;
}


void check2()
{
	int n;
	cin >> n;
	Box temp;
	for (int i = 0; i < n; i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if (type == 2)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if (type == 3)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox < temp)
			{
				cout << "Lesser\n";
			}
			else
			{
				cout << "Greater\n";
			}
		}
		if (type == 4)
		{
			cout << temp.CalculateVolume() << endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			cout << NewBox << endl;
		}

	}
}

int main()
{
	check2();
}




