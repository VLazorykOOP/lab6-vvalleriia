#define _USE_MATH_DEFINES
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int task_manager()
{
    int task_number;
RENUMBER:        printf("Menu:\n     1.  Task 1\n     2.  Task 2\n     3.  Task 3\n");
    printf("Enter task number you wanna do: ");
    scanf_s("%d", &task_number);
    if (task_number < 1 || task_number > 3)
    {
        system("cls");
        printf("There is only 3 options!\n\n");
        goto RENUMBER;
    }
    return task_number;
}
/*
Задача 1. Створити дві ієрархії класів з віртуальним та без віртуального успадкуванням з елементами даних класів у кожному класі.
Схема успадкування на рисунку за варіантами.
Створити об’єкти похідних класів з віртуальним та без віртуального успадкуванням. Вивести розміри об’єктів даних класів.
*/
class Base {
protected:
    int dat;

public:
    Base() { dat = 0; }
    Base(int d) { dat = d; }
};

class DR1 : public Base {
public:
    int dr1;
    DR1() : Base() { dr1 = 0; }
    DR1(int dr) : Base() { dr1 = dr; }
    DR1(int dr, int d) : Base(d) { dr1 = dr; }
};

class DR2 : public DR1 {
public:
    int dr2;
    DR2() : DR1() { dr2 = 0; }
    DR2(int dr) : DR1() { dr2 = dr; }
    DR2(int dr, int drr) : DR1(drr) { dr2 = dr; }
    DR2(int dr, int drr, int d) : DR1(drr, d) { dr2 = dr; }
};

class DL1 : protected Base {
protected:
    int dl1;

public:
    DL1() : Base() { dl1 = 0; }
    DL1(int d) : Base() { dl1 = d; }
    DL1(int d, int dt) : Base(dt) { dl1 = d; }
};

class R : public Base, public DR2, public DL1 {
public:
    int dt;
    R() : Base(), DR2(), DL1() { dt = 0; }
    R(int d) : Base(), DR2(), DL1() { dt = d; }
    R(int d, int ld1, int rd2, int main)
        : Base(main), DR2(rd2, main), DL1(ld1, main) {
        dt = d;
    }
    void print() {
        std::cout << "dat =? Error C2385 ambiguous access level dat " << std::endl;
    }
};

class R2 : public Base, public DR1, public DR2 {
public:
    int dt;
    R2() : DR1(), DR2() { dt = 0; }
    R2(int d) : DR1(), DR2() { dt = d; }
    R2(int d, int rd1, int rd2, int main)
        : DR1(rd1, main), DR2(rd2, main) {
        dt = d;
    }
    void print() {
        std::cout << "dat =? Error C2385 ambiguous access level dat " << std::endl;
    }
};

//virtual:
class DVR1 : virtual public Base {
public:
    int dr1;
    DVR1() : Base() { dr1 = 0; }
    DVR1(int dr) : Base() { dr1 = dr; }
    DVR1(int dr, int d) : Base(d) { dr1 = dr; }
};

class DVR2 : virtual public DVR1 {
public:
    int dr2;
    DVR2() : DVR1() { dr2 = 0; }
    DVR2(int dr) : DVR1() { dr2 = dr; }
    DVR2(int dr, int drr) : DVR1(drr) { dr2 = dr; }
    DVR2(int dr, int drr, int d) : DVR1(drr, d) { dr2 = dr; }
};

class DVL1 : virtual protected Base {
protected:
    int dl1;

public:
    DVL1() : Base() { dl1 = 0; }
    DVL1(int d) : Base() { dl1 = d; }
    DVL1(int d, int dt) : Base(dt) { dl1 = d; }
};

class RV : virtual public Base, virtual public DVR2, virtual public DVL1 {
public:
    int dt;
    RV() : Base(), DVR2(), DVL1() { dt = 0; }
    RV(int d) : Base(), DVR2(), DVL1() { dt = d; }
    RV(int d, int ld1, int rd2, int main)
        : Base(main + 1), DVR2(rd2, main), DVL1(ld1, main) {
        dt = d;
    }
    void print() {
        std::cout << "dat = " << dat << std::endl;
        std::cout << "Base::dat = " << Base::dat << std::endl;
        std::cout << "DVR2::DVR1::Base::dat = " << DVR2::DVR1::Base::dat
            << std::endl;
        std::cout << "DVL2::Base::dat = " << DVR2::DVR1::Base::dat
            << std::endl;
    }
};

class RV2 : virtual public DVR2, virtual public DVR1 {
public:
    int dt;
    RV2() : DVR2(), DVR1() { dt = 0; }
    RV2(int d) : DVR2(), DVR1() { dt = d; }
    RV2(int d, int rd1, int rd2, int main)
        : DVR2(rd2, main), DVR1(rd1, main) {
        dt = d;
    }
    void print() {
        std::cout << "dat = " << dat << std::endl;
        std::cout << "Base::dat = " << Base::dat << std::endl;
        std::cout << "DVR2::DVR1::Base::dat = " << DVR2::DVR1::Base::dat
            << std::endl;
        std::cout << "DVL2::Base::dat = " << DVR2::DVR1::Base::dat
            << std::endl;
    }
};
int Task1() {

    std::cout << " Example1  \n";

    RV d(4, 5, 6, 7);
    R r(3, 5, 6, 7);


    std::cout << "Size for Base " << sizeof(Base) << std::endl;
    std::cout << "Size for DR1 " << sizeof(DR1) << std::endl;
    std::cout << "Size for DR2 " << sizeof(DR2) << std::endl;
    std::cout << "Size for DL1 " << sizeof(DL1) << std::endl;

    std::cout << "Size for Base " << sizeof(Base) << std::endl;
    std::cout << "Size for DVL1 " << sizeof(DVL1) << std::endl;
    std::cout << "Size for DVR1 " << sizeof(DVR1) << std::endl;
    std::cout << "Size for DVR2 " << sizeof(DVR2) << std::endl;
    r.print();
    d.print();
    return 0;
}
/*Створити абстрактний базовий клас фігура із віртуальною функцією -
площа поверхні. Створити похідні класи: паралелепіпед, тетраедр, куля зі своїми
функціями площі поверхні. (Площа поверхні : паралелепіпеда - S=6xy, кулі - S=4πr2.Площа поверхні тетраедра: S=a2π3).*/

using namespace std;

class Figure {
public:
    string name;
    virtual float S() = 0;
};

class Rectangle : public Figure {
    float width, height;

public:
    Rectangle(float w, float h) : width(w), height(h) { name = "Rectangle"; }
    virtual float S() override { return width * height; }
};

class Circle : public Figure {
    float radius;

public:
    Circle(float r) : radius(r) { name = "Circle"; }
    virtual float S() override { return 4 * 3.14159 * radius * radius; }
};

class RightTriangle : public Figure {
    float base, height;

public:
    RightTriangle(float b, float h) : base(b), height(h) { name = "Right Triangle"; }
    virtual float S() override { return 0.5 * base * height; }
};

class Trapezoid : public Figure {
    float base1, base2, height;

public:
    Trapezoid(float b1, float b2, float h) : base1(b1), base2(b2), height(h) { name = "Trapezoid"; }
    virtual float S() override { return (base1 + base2) * height / 2; }
};

int Task2() {
    cout << "Example 2\n";
    Rectangle r(4, 5);
    Circle c(2);
    RightTriangle t(3, 4);
    Trapezoid z(2, 5, 3);

    Figure* figures[] = { &r, &c, &t, &z };
    int n = sizeof(figures) / sizeof(Figure*);

    for (int i = 0; i < n; i++) {
        cout << "S of figure " << figures[i]->name << ": " << figures[i]->S() << endl;
    }
    return 0;
}

int mainExample() {
    Task2();
    return 0;
}
using namespace std;

class WaterBody {
protected:
    string name;

public:
    WaterBody() {}
    WaterBody(string n) {
        name = n;
    }

    virtual void printInfo() {
        cout << "Name: " << name << endl;
    }

    virtual ~WaterBody() {}
};

class Bay : public WaterBody {
protected:
    int bayArea;

public:
    Bay() {}
    Bay(string n, int area) : WaterBody(n) {
        bayArea = area;
    }

    void printInfo() override {
        cout << "Bay Name: " << name << endl;
        cout << "Bay Area: " << bayArea << " square kilometers" << endl;
    }

    ~Bay() {}
};

class Cove : public WaterBody {
protected:
    int coveDepth;

public:
    Cove() {}
    Cove(string n, int depth) : WaterBody(n) {
        coveDepth = depth;
    }

    void printInfo() override {
        cout << "Cove Name: " << name << endl;
        cout << "Cove Depth: " << coveDepth << " meters" << endl;
    }

    ~Cove() {}
};

class Sea : public WaterBody {
protected:
    string seaType;

public:
    Sea() {}
    Sea(string n, string type) : WaterBody(n) {
        seaType = type;
    }

    void printInfo() override {
        cout << "Sea Name: " << name << endl;
        cout << "Sea Type: " << seaType << endl;
    }

    ~Sea() {}
};

class Ocean : public WaterBody {
protected:
    int oceanVolume;

public:
    Ocean() {}
    Ocean(string n, int volume) : WaterBody(n) {
        oceanVolume = volume;
    }

    void printInfo() override {
        cout << "Ocean Name: " << name << endl;
        cout << "Ocean Volume: " << oceanVolume << " cubic kilometers" << endl;
    }

    ~Ocean() {}
};

int Task3() {
    WaterBody* waterBodies[] = {
      new Bay("San Francisco Bay", 400),
      new Cove("Emerald Cove", 30),
      new Sea("Mediterranean Sea", "Saltwater"),
      new Ocean("Pacific Ocean",100)
    };

    for (int i = 0; i < 4; i++) {
        waterBodies[i]->printInfo();
        cout << endl;
    }

    for (int i = 0; i < 4; i++) {
        delete waterBodies[i];
    }

    return 0;
}
int main()
{
TASK:        int task_number = task_manager();
    switch (task_number)
    {
    case 1:
        Task1();
        break;
    case 2:
        Task2();
        break;
    case 3:
        Task3();
        break;
    default:
        break;
    }

    string answer;
FIN:        printf("\nDo you want to do one more task? Enter '1' if you do, and '0' if you don`t: ");
    cin >> answer;
    if (answer == "1")
    {
        system("cls");
        goto TASK;
    }
    if (answer == "0")
    {
        system("cls");
        printf("Bye!");
    }
    else
    {
        printf("Please enter 'yes' or 'no'\n");
        goto FIN;
    }
}
