#include <iostream>

using namespace std;

enum X
{
	a = 1, b, c, d, e, f, g, h
};

std::istream& operator>>(std::istream& is, X& f)
{
	std::string s;
	is >> s;
	if (s == "a") f = X::a;
	else if (s == "b") f = X::b;
	else if (s == "c") f = X::c;
	else if (s == "d") f = X::d;
	else if (s == "e") f = X::e;
	else if (s == "f") f = X::f;
	else if (s == "g") f = X::g;
	else if (s == "h") f = X::h;
	else throw exception("Out of range");
	return is;
}


class Figure
{
	public:

		virtual bool go() {
			return false;
		}

};

class Shashka : public Figure
{
public:
	Shashka(X x,X x1,int y,int y1) : x(x),x1(x1),y(y),y1(y1) {

	}

	bool go() override {
		if (((x1 == x - 1 || x1 == x + 1) && y1 == y + 1))
		{
			cout << "Turn is correct!\n";
			return true;
		}
		cout << "Turn is not correct!\n";
		return false;
	}

private:
	X x= a, x1= a;
	int y=0, y1=0;
};

class Damka : public Figure
{
public:
	Damka(X x, X x1, int y, int y1) : x(x), x1(x1), y(y), y1(y1) {

	}

	bool go() override {
		if (abs(x-x1)==abs(y-y1))
		{
			cout << "Turn is correct!\n";
			return true;
		}
		cout << "Turn is not correct!\n";
		return false;
	}

private:
	X x= a, x1= a;
	int y=0, y1=0;
};

int main()
{
	X x,x1;
	int y,y1;
	bool leaver;
	cout << "Write position of your figure\n";
	cout << "Write letter coordinate -> \n";
	cin >> x;
	cout << "Write number coordinate -> \n";
	cin >> y;
	cout << "Sashka or damka -> \n";
	cout << "0 - shashka\n";
	cout << "1 - damka\n";
	cin >> leaver;
	cout << "Write position where you want to go\n";
	cout << "Write letter coordinate -> \n";
	cin >> x1;
	cout << "Write number coordinate -> \n";
	cin >> y1;

	Damka dam(x, x1, y, y1);
	Shashka sh(x, x1, y, y1);

	if (y < 1 || y>8 || y1 < 1 || y1>8)
	{
		cout << "Wrong coordinate!\n";
		return 0;
	}

	Figure* fig;
	leaver ? fig = &dam : fig = &sh;
	fig->go();
}
