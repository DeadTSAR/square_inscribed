#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>

using namespace std;

//Задания.
//1. Создать два класса : 
//1) окружность, 2) точка на плоскости,
//определить дружественную функцию вхождения точки на плоскости в окружность.
//2. Добавить класс «квадрат», создать для класса «окружность» и класса «квадрат»
//дружественные функции определения того, может ли окружность быть вписанной 
//или описанной для квадрата.
//(https://ru.wikipedia.org/wiki/Вписанная_окружность)

class orbit;
class cqare;
class point;

class point
{private:
	double x;
	double y;
	friend cqare;
	friend orbit;
public:
	point(double x = 0, double y = 0)
	{
		
		this->x = x;
		this->y = y;
		std::cout << "zadana to4ka x: " << x << " y: " << y << endl;
	};


};

class orbit
{private:
	double x;
	double y;
	double R;
	friend point;
	friend cqare;
public:
	orbit(double x=0, double y=0, double R=0) {
		this->x = x;
		this->y = y;
		this->R = R;
	}
	void printOrb();

	/*orbit(point & position , double R)
	{
	
		
		this->R=R;
		std::cout << "zadan orbit " << endl;
		std::cout << "x " << x;
		std::cout << "y " << y;
		std::cout << "R " << R << endl;
	};
	*/
};

class cqare
{private:
	double w,h;
	friend point;
	friend orbit;
public:
	cqare(double w=0)
	{
		
		this->w = h = w;// h = w;// у квадрата 4 стороны равны. w^2; d=кореньКВ2 * а;
		std::cout << "zadan cqare " << w << endl;
	};
	double cqareDiag(double w);


};


//point::point()
//{
//}
//
//point::~point()
//{
//}
//
//forAngl::forAngl()
//{
//}
//
//forAngl::~forAngl()
//{
//}
//
//orbit::orbit()
//{
//}
//
//orbit::~orbit()
//{
//}

int main() { // задать АВ ВС СД ДА - точки (А1.А2.)
	setlocale(LC_ALL, "rus");
	double x, y, R0, r1, w;


	std::cout << "задайте входную точку (x,y) для круга и квадрата" << endl;
	std::cin >> x >> y;
	point x1(x, y);
	
	if (x > y) 
	{
		r1 = abs(x);
		w = abs(x) * 2;
	}
	else
	{
		r1 = abs (y);
		w = abs( y) * 2;
	}

	cqare cq(w);
	R0 = (cq.cqareDiag(w)/2);

	orbit o1(x, y, R0);
	o1.printOrb();
	std::cout << "окружность описывает квадрат R = " << R0 << endl;
	
	
	orbit o2(x, y, r1);
	o2.printOrb();
	std::cout << "окружность вписанна в квадрат r1 = " << r1 << endl;

	

	std::system("pause");
	return 0;
}

double cqare::cqareDiag(double w)
{
	double d = sqrt(2)*w;
	std::cout << " cqrt " << d << endl;

	//d = (sqrt(2)*w)/2;
	//std::cout << "1/2 cqrt " << d << endl;
			
	return d;
}

void orbit::printOrb()
{
	std::cout << "printOrb xy(R/r):" << endl;
	std::cout << "x: " << x << endl;
	std::cout << "y: " << y << endl;
	std::cout << "R/r: " << R << endl;
}
//Окружность описанная вокруг квадрата
//Определение.Кругом описанным вокруг квадрата называется круг проходящий 
//через четыре вершины квадрата и имеющий центр на пересечении диагоналей квадрата.
//Радиус окружности описанной вокруг квадрата всегда больше радиуса вписанной окружности в√2 раз.
//
//Радиус окружности описанной вокруг квадрата равен половине диагонали.
//
//Площадь круга описанного вокруг квадрата большая площадь того же квадрата в π / 2 раз.

//Формула радиуса окружности ОПИСАННОЙ вокруг квадрата через сторону квадрата :
//R = w*(sqrt(2)/2)

// Формула радиуса круга вписанного в квадрат через сторону квадрата :
// r = w/2 
// r = d / (2 * (sqrt(2)));

