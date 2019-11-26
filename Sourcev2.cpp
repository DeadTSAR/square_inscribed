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
	point() {};

	/*point(double x = 0, double y = 0)
	{
		
		this->x = x;
		this->y = y;
		std::cout << "zadana to4ka x: " << this->x << " y: " << this->y << endl;
	};*/

	void SetPoint_X(double x) { this->x = x; };
	void SetPoint_Y(double y) { this->y = y; };

	double GetPoint_x() { return x; };
	double GetPoint_y() { return y; };

};

class orbit
{private:
	double x;
	double y;
	double R;
	
	friend cqare;
public:
	friend point;
	
	orbit(double x = 0, double y = 0, double R=0) {
		
		/*this->x = x;
		this->y = y;*/
		this->R = R;
	}
	void printOrb();
	double GetPointORB_x() { return x; };
	double GetPointORB_y() { return y; };

	/* point getPoint(point &xy)
{
	this->x = x;
	this->y = y;
}*/

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
	std::cin >> x;
		std::cin >> y;
	point x1;
	x1.SetPoint_X(x);
	x1.SetPoint_Y(y);

	
	if ((x1.GetPoint_x()) > x1.GetPoint_y())
	{
		r1 = abs(x1.GetPoint_x());
		w = abs(x1.GetPoint_x()) * 2;
	}
	else
	{
		r1 = abs(x1.GetPoint_y());
		w = abs(x1.GetPoint_y()) * 2;
	}

	cqare cq(w);
	R0 = (cq.cqareDiag(w)/2);

	//double x11 = x1.GetPoint_X;
	//double y11 = x1.GetPoint_Y;


	orbit o1(x1.GetPoint_x(), x1.GetPoint_y(),  R0);
	o1.printOrb();
	std::cout << "окружность описывает квадрат R = " << R0 << endl;
	
	
	orbit o2(x1.GetPoint_x(), x1.GetPoint_y(), r1);
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

