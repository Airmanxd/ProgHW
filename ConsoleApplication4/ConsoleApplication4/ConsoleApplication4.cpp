#include "stdafx.h"
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <algorithm>
#include <Windows.h>
using namespace std;

class Country
{
	string Name;
	int sMedals, bMedals, points, tMedals;
public:
	string output;
	int gMedals;
public:
	void getName()
	{
		cout << "Enter the name of the country: ";
		cin >> Name;
	}
	void getMedals()
	{
		cout << "Enter the amount of gold medals " << Name << " got: ";
		cin >> gMedals;
		cout << "Enter the amount of silver medals " << Name << " got: ";
		cin >> sMedals;
		cout << "Enter the amount of bronze medals " << Name << " got: ";
		cin >> bMedals;
	}
	void process()
	{
		points = gMedals * 7 + sMedals * 6 + bMedals * 5;
		tMedals = gMedals + sMedals + bMedals;
		output = Name + " " + to_string(gMedals) + " " + to_string(sMedals) + " " + to_string(bMedals) + " " + to_string(tMedals) + " " + to_string(points) + "\n";
	}
};

void wrongInput(float variable, float limit)
{
	while (variable <= limit)
	{
		cout << "Wrong input, the variable must be more than " << limit << endl << "Input a new value: ";
		cin >> variable;
	}
}

void wrongInput(float variable, float limit, float upperlimit)
{
	while (variable < limit || variable > upperlimit)
	{
		cout << "Wrong input, the variable must be more than " << limit << " and less than " << upperlimit <<  endl << "Input a new value: ";
		cin >> variable;
	}
}

void areaofRectangle()
{
	float a, b;

	cout << "Enter a: ";
	cin >> a;
	wrongInput(a, 0);

	cout << "Enter b: ";
	cin >> b;
	wrongInput(b, 0);

	cout << a * b;
}

void areaofTriangle1()
{
	float a, h;

	cout << "Enter a: ";
	cin >> a;
	wrongInput(a, 0);

	cout << "Enter h: ";
	cin >> h;
	wrongInput(h, 0);

	cout << a * h / 2;
}

void areaofTriangle2()
{
	float a, b, angle;
	
	cout << "Enter a: ";
	cin >> a;
	wrongInput(a, 0);

	cout << "Enter b: ";
	cin >> b;
	wrongInput(b, 0);

	cout << "Enter the angle: ";
	cin >> angle;
	wrongInput(angle, 0, 180);

	float sinus = sin(angle);

	cout << a * b * sinus / 2;
}

void areaofTriangle3()
{
	float a, b, c;

	cout << "Enter a: ";
	cin >> a;
	wrongInput(a, 0);

	cout << "Enter b: ";
	cin >> b;
	wrongInput(b, 0);

	cout << "Enter c: ";
	cin >> c;
	wrongInput(c, 0);

	while (a + b <= c || a + c <= b || b + c <= a)
	{
		if (a + b <= c)
		{
			cout << "a + b must be greater than c" << endl << "Input new value of a: ";
			cin >> a;
			wrongInput(a, 0);

			cout << "Input new value of b: ";
			cin >> b;
			wrongInput(b, 0);
		}
		else if (a + c <= b)
		{
			cout << "a + c must be greater than b" << endl << "Input new value of a: ";
			cin >> a;
			wrongInput(a, 0);

			cout << "Input new value of c: ";
			cin >> c;
			wrongInput(c, 0);
		}
		else if (b + c <= a)
		{
			cout << "b + c must be greater than a" << endl << "Input new value of b: ";
			cin >> b;
			wrongInput(b, 0);

			cout << "Input new value of c: ";
			cin >> c;
			wrongInput(c, 0);
		}
	}

	float P = (a + b + c) / 2;

	cout << sqrt((P - a)*(P - b)*(P - c)*P);
}

void areaofCircle()
{
	float R;

	cout << "Enter R: ";
	cin >> R;
	wrongInput(R, 0);
	
	cout << 3.14*R*R;
}

int romantoint(char x, bool l)
{
	int a = 1;
	if (x != string::npos)
	{
		switch (x)
		{
			case 'I':
				a *= 1;
				l = true;
				break;
			case 'V':
				a *= 5;
				l = false;
				break;
			case 'X':
				a *= 10;
				l = true;
				break;
			case 'L':
				a *= 50;
				l = false;
				break;
			case 'C':
				a *= 100;
				l = true;
				break;
			case 'D':
				a *= 500;
				l = false;
				break;
			case 'M':
				a *= 1000;
				l = true;
				break;
			default:
				a *= 0;
				break;
		}
		return a;
	}
	else
		return 0;
}

string ConvertToUserBase(float tres, int b2)
{
	string s;
	float decimal, whole;
	int mod = 0, intwhole, i = 0;
	decimal = modf(tres, &whole);
	intwhole = whole;
	while (intwhole > 0)
	{
		mod = intwhole % b2;
		if (mod > 9)
			mod += 55;
		else
			mod += 48;
		s += mod;
		intwhole /= b2;
	}
	reverse(s.begin(), s.end());
	if (decimal > 0)
	{
		s += '.';
		for (i = 0; i < 3; i++)
		{
			decimal *= b2;
			decimal = modf(decimal, &whole);
			intwhole = whole;
			if (intwhole > 9)
				intwhole += 55;
			else
				intwhole += 48;
			s += intwhole;
		}
	}
	return s;
}

float ConvertToBaseTen(string s, int b1)
{
	int b2 = 10;
	int i = 0, value = 0, power, allowed = 0;
	float tres = 0;
	power = s.length();
	if (s.find_first_of(',') != -1)
	{
		power = s.find_first_of(',');
		allowed++;
	}
	if (s.find_first_of('.') != -1)
	{
		power = s.find_first_of('.');
		allowed++;
	}
	if (allowed == 2)
	{
		cout << "Incorrect input" << endl;
		return 0;
	}
	power--;

	for (i; i < s.length(); i++)
	{
		if (s[i] == ',' || s[i] == '.')
		{
			continue;
		}
		if (s[i] < 123 && s[i] > 96)
		{
			value = s[i] - 87;
		}

		if (s[i] < 58 && s[i] > 47)
		{
			value = s[i] - 48;
		}

		if (s[i] < 91 && s[i] > 64)
		{
			value = s[i] - 55;
		}

		if (value > 0 && value < b1)
		{
			tres += value * pow(b1, power);
		}

		else if (s[i] != ',' && s[i] != '.')
		{
			cout << "Your number is incorrect" << endl;
			return 0;
		}

		value = 0;
		power--;
	}
	return tres;
}

int sort(const void* a, const void* b)
{
	int g1 = *((int*)a);
	int g2 = *((int*)b);
	if (g1 < g2)
	{
		return 1;
	}
	if (g1 > g2)
	{
		return -1;
	}
	if (g1 == g2)
	{
		return 0;
	}
}

void task1()
{
	float S, V, h, R, r, l;
	float pi = 3.14;

	cout << "Enter the height of the cone" << endl;
	cin >> h;
	wrongInput(h, 0);

	cout << "Enter the base radius" << endl;
	cin >> R;
	wrongInput(R, 0);

	cout << "Enter the top surface radius" << endl << "Try again" << endl;
	cin >> r;
	wrongInput(r, 0);

	l = sqrt((R - r) * (R - r) + h * h);

	V = (pi * h * (R * R + R * r + r * r)) / 3;

	S = pi * (R * R + l * (R + r) + r * r);

	cout << "The volume of your truncated cone: " << V << endl;
	cout << "The total area of your truncated cone: " << S << endl;
}

void task2()
{
	float a, x, w;
	cin >> x >> a;
	if (x > -1 && x < 1)
	{
		if (x == 0)
		{
			"Error";
		}
		else
		{
			w = a * log(abs(x));
			cout << w;
		}
	}
	else
	{
		if ((a - x * x) < 0)
			cout << "Can't calculate";
		else
		{
			w = sqrt(a - x * x);
			cout << w;
		}
	}
}

void task3()
{
	float res, x, y, b;
	cout << "Enter x: ";
	cin >> x;
	cout << "Enter y: ";
	cin >> y;
	cout << "Enter b: ";
	cin >> b;
	while ((b - y) <= 0 && (b - x) < 0)
	{
		if ((b - y) <= 0)
		{
			cout << "b - y <= 0" << endl << "Enter new value of b: ";
			cin >> b;
			cout << "Enter new value of y: ";
			cin >> y;
		}
		else if (b - x < 0)
		{
			cout << "b - x < 0" << endl << "Enter new value of b: ";
			cin >> b;
			cout << "Enter new value of x: ";
			cin >> x;
		}
	}
	res = log(b - y) * sqrt(b - x);
	cout << "Result: " << res;
}

void task4()
{
	int N;
	cin >> N;
	if (N < 0)
		cout << "Error";
	else
		for (int i = 0; i < 10; i++)
		{
			cout << N << endl;
			N++;
		}
}

void task5()
{
	float x = -4, y = 0;
	while (x < 4.1)
	{
		if (x != 1)
		{
			y = (x * x - 2 * x + 2) / (x - 1);
			cout.precision(2);
			cout << left << "x = ";
			cout.width(5);
			cout << left << x << "y = " << y << endl;
		}
		else
			cout << "Can't calculate when x = 1" << endl;
		x += 0.5;
	}
}

void firsttask()
{
	setlocale(0, "");
	float n, m, p, S, r;

	cout << "Enter S" << endl;
	cin >> S;
	wrongInput(S, 0);

	cout << "Enter p" << endl;
	cin >> p;
	wrongInput(p, 0);

	cout << "Enter N" << endl;
	cin >> n;
	wrongInput(n, 0);

	r = p / 100;
	while ((pow((1 + r), n) - 1) == 0)
	{
		cout << "Can't divide by zero" << endl << "Input new value of p: ";
		cin >> r;
		r = p / 100;
		cout << "Enter new value of n: ";
		cin >> n;
	}

	m = (S * r * pow((1 + r), n)) / 12 * (pow((1 + r), n) - 1);

	cout << "m = " << m;
}

void secondtask()
{
	double S, m1, m2, n;
	double increment = 1, r;
	double p = increment;
	int precision;

	cout << "Enter S: ";
	cin >> S;
	wrongInput(S, 0);

	cout << "Enter m: ";
	cin >> m2;
	wrongInput(m2, 0);

	cout << "Enter n: ";
	cin >> n;
	wrongInput(n, 0);

	cout << "Enter the precision of the calculation: ";
	cin >> precision;
	while (precision <= 0 || precision > 50)
	{
		cout << "Wrong input" << endl << "Try again";
		cin >> precision;
	}

	r = p / 100;

	while ((pow((1 + r), n) - 1) == 0)
	{
		p += increment;
	}

	m1 = (S * r * pow((1 + r), n)) / 12 * (pow((1 + r), n) - 1);

	while (m1 < m2)
	{
		r = p / 100;
		p += increment;

		m1 = (S * r * pow((1 + r), n)) / 12 * (pow((1 + r), n) - 1);

		if (m1 > m2 && precision > 0)
		{
			p -= increment;
			increment /= 10;
			precision--;
		}
	}

	cout << p << "%" << endl;
}

void thirdtask()
{
	string line;
	ifstream Output;
	ofstream Fill;

	Fill.open("example.txt");
	Fill << "Cool file";
	Fill.close();
	Output.open("example.txt");
	if (Output.is_open())
	{
		while (getline(Output, line))
		{
			cout << line << endl;
		}
		Output.close();
	}
	else
		cout << "error";
}

void fourthtask()
{
	int i = 0;
	int strL;
	string line;
	ifstream reading;
	ofstream writing;
	writing.open("text.txt");
	writing << "aspdbg5032897asdpgih39L";
	writing.close();
	reading.open("text.txt");
	if (reading.is_open())
	{
		reading >> line;
		strL = line.length();
		for (int i = 0; i < strL; ++i)
		{
			switch (line[i])
			{
			case '1': cout << 1;
				break;
			case '2': cout << 2;
				break;
			case '3': cout << 3;
				break;
			case '4': cout << 4;
				break;
			case '5': cout << 5;
				break;
			case '6': cout << 6;
				break;
			case '7': cout << 7;
				break;
			case '8': cout << 8;
				break;
			case '9': cout << 9;
				break;
			case '0': cout << 0;
				break;
			}
		}
	}
	else
		cout << "The file isn't open";
}

void fifthtask()
{
	string line1, line2;
	string buffer;
	int i;
	line1 = "dsafjkpovuoytrzewanxzfdhgapocm";
	cout << "Initial string: " << line1 << endl;

	line2 = line1;
	sort(line2.begin(), line2.end());

	for (i = 0; i < line1.length() - 1; i++)
	{
		for (int j = i; j < line1.length(); j++)
		{
			if (line1[i] > line1[j])
			{
				buffer = line1[j];
				line1[j] = line1[i];
				line1[i] = buffer[0];
			}
		}
	}
	cout << "Sorted algorithimically: " << line2 << endl << "Sorted by me 8): " << line1 << endl;
}

void taskone()
{
	ofstream doco;
	ifstream doci;
	string input, buffer;
	int sum = 0, prev = 0, i = 0, number = 0;
	doco.open("doc.txt");
	if (doco.is_open())
	{
		cout << "Enter the numbers: ";
		getline(cin, input, '\n');
		doco << input;
	}
	else
		cout << "The file wasn't open";
	doco.close();
	input.clear();
	doci.open("doc.txt");
	if (doci.is_open())
	{
		getline(doci, input);
		cout << input << endl;
		for (i = 0; i < input.length(); i++)
		{
			if (input[i] < 48 || input[i] > 57)
			{
				buffer = input.substr(prev, i - prev);
				number = stoi(buffer, 0, 10);
				sum += number;
				prev = i + 1;
			}
		}
		if (prev < input.length())
		{
			buffer = input.substr(prev);
			number = stoi(buffer, 0, 10);
			sum += number;
		}
	}
	else
		cout << "The file wasn't open 2";
	doci.close();
	cout << "Sum: " << sum << endl;
}

void tasktwo()
{
	float a;
	cout << "Enter a: ";
	cin >> a;
	if (a < 0)
		cout << -1;
	if (a > 0)
		cout << 1;
	if (a == 0)
		cout << 0;
}

void taskthree()
{
	int input;
	cout << "Choose your shape (input the number)" << endl << "1. Rectangle" << endl << "2. Triangle" << endl << "3. Circle" << endl;
	cin >> input;
	switch (input)
	{
	case 1:
		areaofRectangle();
		break;
	case 2:
		cout << "Choose the formula (input the number)" << endl << "1. S = a*h/2" << endl << "2. S = a*b*sin(ab)" << endl;
		cout << "3. S = sqrt((P - a)*(P - b)*(P - c)*P)  P = (a+b+c)/2" << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			areaofTriangle1();
			break;
		case 2:
			areaofTriangle2();
			break;
		case 3:
			areaofTriangle3();
			break;
		}
		break;
	case 3:
		areaofCircle();
		break;
	}
}

void taskfour()
{
	char flag[13][64] = { ' ' };

	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 64; j++)
		{
			if (i < 6 && j < 16 && j % 2 == 1 && i % 2 == 0)
			{
				flag[i][j] = '*';
			}
			else if (i < 6 && j < 16 && j % 2 == 0 && i % 2 == 1)
			{
				flag[i][j] = '*';
			}
			else if ((j > 15 && i < 6) || i > 5)
			{
				flag[i][j] = '=';
			}
			cout << flag[i][j];
		}
		cout << endl;
	}
}

void taskfive()
{
	cout << "Not done yet...";
}

int tasksix()
{
	char input;
	int sum = 0, buffer = 0, buffer2 = 0;
	string uinput;
	bool actualnumeral = true;
	cout << "Input the roman numeral: ";
	cin >> uinput;

	for (int i = 0; i < uinput.length(); i++)
	{
		buffer = romantoint(uinput[i], actualnumeral);
		buffer2 = romantoint(uinput[i + 1], actualnumeral);
		if (buffer < buffer2)
		{
			if (buffer * 10 >= buffer2 && actualnumeral)
			{
				buffer *= -1;
			}
			else
			{
				cout << "This roman numeral doesn't exist" << endl;
				tasksix();
				return 0;
			}
		}
		sum += buffer;
	}
	cout << sum;
	return 0;
}

void taskseven()
{
	int j, s, m, c, var, i = 0;
	cout << "Which rng do you want? (type 1 or 2)" << endl;
	cin >> var;
	wrongInput(var, 1, 2);

	if (var == 1)
	{
		m = 37;
		c = 64;
		i = 3;
	}
	if (var == 2)
	{
		m = 25173;
		c = 65537;
		i = 13849;
	}
	cout << "How many random numbers do you want? ";
	cin >> var;
	wrongInput(var, 0);
	cout << "Enter the key number: ";
	cin >> s;
	for (j = 1; j <= var; j++)
	{
		s = (s*m + i) % c;
		cout << j << ": " << s << endl;
	}
}

void taskeight()
{
	float A[3][4] = { 5, 2, 0, 10, 3, 5, 2, 5, 20, 0, 0, 0 };
	float B[4][2] = { 1.20, 0.50, 2.80, 0.40, 5, 1, 2, 1.5 };
	float C[3][2] = { 0 };

	int i = 0, j = 0, minp = 0, maxp = 0, maxc = 0, minc = 0, sump = 0, sumc = 0;

	cout << "The result matrix: " << endl;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			C[i][0] += A[i][j] * B[j][0];
			C[i][1] += A[i][j] * B[j][1];
		}
		cout << i + 1 << ": " << C[i][0] << " " << C[i][1] << endl;
	}
	for (j = 0; j < 3; j++)
	{
		if (C[j][0] > C[maxp][0])
			maxp = j;

		if (C[j][0] < C[minp][0])
			minp = j;

		if (C[j][1] > C[maxc][1])
			maxc = j;

		if (C[j][1] < C[minc][1])
			minc = j;

		sump += C[j][0];
		sumc += C[j][1];
	}
	maxp++;
	maxc++;
	minc++;
	minp++;
	cout << "Seller with the maximum profit: " << maxp << endl;
	cout << "Seller with the minimum profit: " << minp << endl;
	cout << "Seller with the maximum commission: " << maxc << endl;
	cout << "Seller with the minimum commision: " << minc << endl;
	cout << "Total sale earnings: " << sump << endl;
	cout << "Total commission earnings: " << sumc << endl;
	cout << "Total money dealt with: " << sump + sumc << endl;
}

void tasknine()
{
	int i = 0, power = 0, base1, base2;
	float temp;
	string number;

	cout << "Enter the initial basis: ";
	cin >> base1;
	wrongInput(base1, 1, 37);

	cout << "Enter the number: ";
	cin >> number;
	cout << "Enter the basis of the converted number: ";
	cin >> base2;
	wrongInput(base2, 1, 37);
	temp = ConvertToBaseTen(number, base1);
	number = ConvertToUserBase(ConvertToBaseTen(number, base1), base2);
	cout << "Converted number: " << number << endl;
}

void Euclid()
{
	int a, b;
	cout << "Enter number a: ";
	cin >> a;
	cout << "Enter number b: ";
	cin >> b;
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	cout << "MCD = " << a << endl;

}

void Eratosthenes()
{
	int N, i = 0, n = 2, j = 1;
	cout << "Enter the boundary number: ";
	cin >> N;
	wrongInput(N, 1);
	N++;
	int *a = new int[N];
	for (i; i < N; i++)
	{
		a[i] = i;
		cout << a[i] << endl;
	}
	for (i = 0; i < N; i++)
	{
		if (a[i] > 1)
		{
			n = i;
			j = n;
		}
		while (j*n < N)
		{
			a[j*n] = 0;
			j++;
		}
	}
	for (i = 0; i < N; i++)
	{
		if (a[i] > 1)
			cout << a[i] << endl;
	}
}

void whatever()
{
	int n, i = 0, buffer = 0, fbase = 0;
	cout << "Enter how many numbers you will need: ";
	cin >> n;
	string *F2 = new string[n];
	string *F5 = new string[n];
	for (i; i < n; i++)
	{
		cout << "Enter the binary number: " << endl;
		cin >> F2[i];
		F5[i] = ConvertToUserBase(ConvertToBaseTen(F2[i], 2), 5);
	}
}

void files()
{
	fstream file;
	Country country[10];
	int i = 0;
	file.open("file22.txt", ios::out);
	for (i; i < 10; i++)
	{
		country[i].getName();
		country[i].getMedals();
		country[i].process();
		file << country[i].output;
	}
	qsort(country, 10, sizeof(int), sort);
	file.clear();
	for (i = 0; i < 10; i++)
	{
		file << country[i].output;
	}
	file.close();
}

void seconddz(int task)
{
	switch (task)
	{
		case '1':
			task1();
			break;
		case '2':
			task2();
			break;
		case '3':
			task3();
			break;
		case '4':
			task4();
			break;
		case '5':
			task5();
			break;
	}
}

void thirddz(int task)
{
	switch (task)
	{
		case '1':
			firsttask();
			break;
		case '2':
			secondtask();
			break;
		case '3':
			thirdtask();
			break;
		case '4':
			fourthtask();
			break;
		case '5':
			fifthtask();
			break;
	}
}

void fourthdz(int task)
{
	switch (task)
	{
		case '1':
			taskone();
			break;
		case '2':
			tasktwo();
			break;
		case '3':
			taskthree();
			break;
		case '4':
			taskfour();
			break;
		case '5':
			taskfive();
			break;
		case '6': 
			tasksix();
			break;
		case '7':
			taskseven();
			break;
		case '8':
			taskeight();
			break;
		case '9': 
			tasknine();
			break;
	}
}

void extra(char task)
{
	switch (task)
	{
		case 'E':
			Euclid();
			break;
		case 'r':
			Eratosthenes();
			break;
		case 'R':
			whatever();
			break;
		case 'F':
			files();
			break;
	}
}

int main()
{
	char task, dz;
	cout << "HW block number: " << endl;
	cin >> dz;
	cout << "Task number : " << endl;
	switch (dz)
	{
		case '2' :
			cin >> task;
			seconddz(task);
			break;
		case '3':
			cin >> task;
			thirddz(task);
			break;
		case '4':
			cin >> task;
			fourthdz(task);
			break;
		case 'e':
			cin >> task;
			extra(task);
			break;
	}
	system("Pause");
	return 0;
}