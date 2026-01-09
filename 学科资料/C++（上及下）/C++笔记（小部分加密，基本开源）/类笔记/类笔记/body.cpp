#define _CRT_SECURE_NO_WARNINGS //防止vs警告c语言中的函数
//#include<iostream>
//#include<string>
//using namespace std;
////struct默认为共有，class默认为私有
//
//class circle   //设计一个圆类，求周长
//{
//
//public:
//	int r;
//	const double PI = 3.14;
//
//	double zhouchang()
//	{
//		return 2 * PI * r;
//	}
//};
//class student
//{
//public:
//	string name;
//	int id;
//
//	void showS()
//	{
//		cout << "name: " << name << endl << "id: " << id << endl;
//	}
//	void setS()
//	{
//		cout << "name: ";  cin >> name;
//		cout << "id: ";    cin >> id;
//		cout << "Successful" << endl;
//	}
//};
//class person1
//{
//public:
//	string name;
//
//protected://类外无法访问，类内可以，儿子可以访问
//	string car;
//
//private://类外无法访问，类内可以,儿子不可以访问
//	int password;//银行卡密码
//
//public:
//	void func()
//	{
//		name = "张三";
//		car = "拖拉机";
//		password = 10086;
//	}
//};
//class person2 //自己控制读写权限
//{
//public:
//	void setName(string name0)//重写姓名
//	{
//		name = name0;
//	}
//	string getName()//读取姓名
//	{
//		return name;
//	}
//	int getAge()
//	{
//		return age;
//	}
//	void setAge(int age0)
//	{
//		if (age0 < 0 || age0>150)
//		{
//			cout << "年龄输入有误" << endl;
//			return;
//		}
//		age = age0;
//	}
//	void setIdol(string idol0)
//	{
//		idol = idol0;
//	}
//
//private:
//	string name = "阿巴阿巴"; //可读可写
//	int age = 18;     //只可读 写只能在0~150
//	string idol = "坤坤"; //只可写
//};
//
//int main()
//{
//	circle c1;
//	c1.r = 10;
//	cout << "圆的周长： " << c1.zhouchang() << endl;
//
//	student s2;
//	//s2.setS();
//	s2.showS();
//
//	person1 p1;
//	p1.name = "李四";//可以改名，可访问和修改；
//	//cout << p1.car << p1.password; 不可以访问
//	//p1.car = 和 p1.password =  不能修改
//
//	person2 p2;
//	p2.setName("大黄");
//	cout << "name: " << p2.getName() << endl;
//	p2.setAge(160);
//	p2.setAge(66);
//	cout << "age: " << p2.getAge() << endl;
//	p2.setIdol("小王");
//
//	return 0;
//}

//案例：圆和点的关系
//#include<iostream>
//using namespace std;
//
//#include"circle.h"// 分文件编写
//#include"point.h"
//
//void CP(Circle &c, Point &p)
//{
//	double d2 = (c.getx() - p.getx()) * (c.getx() - p.getx())
//		+ (c.gety() - p.gety()) * (c.gety() - p.gety());
//	double r2 = c.getr() * c.getr();
//	if (d2 > r2)cout << "点在圆外" << endl;
//	else if (d2 == r2)cout << "点在圆上" << endl;
//	else cout << "点在圆内" << endl;
//}
//int main()
//{
//	Circle c;
//	Point p1, p2, p3;
//	c.setC(2, 2, 2);
//	p1.setP(1, 2);
//	p2.setP(2, 4);
//	p3.setP(6, 6);
//	CP(c, p1);
//	CP(c, p2);
//	CP(c, p3);
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	//普通构造函数
//	Person()
//	{
//		cout << "Person 的无参构造函数调用" << endl;
//	}
//	Person(int a)
//	{
//		cout << "Person 的有参构造函数调用" << endl;
//		age = a;
//	}
	//拷贝构造函数：将传入的人身上的所有属性拷贝到调用者身上
//	Person( const Person &p )
//	{
//		cout << "Person 的拷贝构造函数调用" << endl;
//		age = p.age;//拷贝
//	}
//
//	~Person()
//	{
//		cout << "Person 的 析构 函数调用" << endl;
//	}
//
//	int age;
//};
//void test1()
//{
////括号法：
//	Person p1;//默认(无参)构造函数的调用
//  //Person p1();  这个不能调用无参构造函数！
//  //因为编译器会认为这是一个函数的声明，不会认为在创建对象！
//
//	Person p2(10);//有参构造函数的调用
//	Person p3(p2);//拷贝构造函数的调用
//	cout << "p2 age: " << p2.age << endl;
//	cout << "p3 age: " << p3.age << endl;
//
////显示法：
//	Person x1;//无参
//	Person x2 = Person(18);//有参
//	Person x3 = Person(x2);//拷贝
//
//	Person(18);//匿名对象
//	//当前这一行命令执行结束后会立马回收匿名对象
//	cout << "---------" << endl;
//
//  //Person(p3);
//	//不要用拷贝构造函数初始化匿名对象
//	//编译器会认为 Person(p3)==Person p3; 对象的声明
//
////隐式转换法
//	Person y1 = 10;//相当于 Person(y1) 有参
//	Person y2 = y1;//拷贝
//}
//void test2()
//{
//	cout << "test2" << endl;
//	Person p1(18);
//	Person p2(p1);
//	cout << "p2 age: " << p2.age << endl;
//}
//void dowork(Person p)//拷贝了给了形参，所以调用了拷贝构造函数
//{
//
//}
//void test3()
//{
//	cout << "test3" << endl;
//	Person p;
//	dowork(p);
//}
//Person dowork2()
//{
//	Person p1;
//	return p1;//值传递时会调用拷贝构造函数
//}
//void test4()
//{
//	cout << "test4" << endl;
//	Person p = dowork2();
//}
//

//#include<iostream>
//using namespace std;
//class Person
//{
//public:
//	Person()
//	{
//		cout << "Person 的无参构造函数调用" << endl;
//	}
//	Person(int a,int h)
//	{
//		cout << "Person 的有参构造函数调用" << endl;
//		age = a;
//		height = new int(h);
//	}
//	Person(const Person& p)
//	{
//		cout << "Person 的拷贝构造函数调用" << endl;
//		age = p.age;   //浅拷贝
//		height = new int(*p.height);//深拷贝，堆区
//	}
//
//	~Person()
//	{
//		//析构代码，释放堆区内存
//		if (height != NULL)
//		{
//			delete height;
//			height=NULL;
//		}
//		cout << "Person 的 析构 函数调用" << endl;
//	}
//	int age;
//	int* height;
//};
//void test()
//{
//	Person p1(18, 170);
//	cout << p1.age << "  " << *p1.height << endl;
//	Person p2(p1);
//	cout << p2.age << "  " << *p2.height << endl;
//}
//int main()
//{
//	test();
//	system("pause");
//	return 0;
////}
//
//
//#include<iostream>
//using namespace std;
//
//class Person
//{
//public://初始化赋初值：
//	Person(int a, int b, int c) :m_a(a), m_b(b), m_c(c)
//	{}
//
//	int m_a;
//	int m_b;
//	int m_c;
//};
//void test1()
//{
//	Person p1(10, 20, 30);
//	cout << p1.m_a << endl;
//	cout << p1.m_b << endl;
//	cout << p1.m_c << endl;
//}
//
//
//int main()
//{
//	test1();
//	return 0;
//}
//
//
//#include<iostream>
//#include<string>
//using namespace std;
//
//class Phone
//{
//public:
//	Phone(string n)
//	{
//		m_pname = n;
//		cout << "Phone的构造函数调用" << endl;
//	}
//	~Phone()
//	{
//		cout << "Phone的析构函数调用" << endl;
//	}
//	string m_pname;
//
//	//静态成员变量：
//	static int id;
//	//静态成员函数：
//	static void func()
//	{
//		cout << "static void func 调用" << endl;
//		mimi = 18;//静态成员函数可以访问静态成员变量
//		//m_pname = "阿巴阿巴"; //静态的成员函数不能访问非静态的成员变量
//		     //这是因为当使用类名访问时，无法区分是那个成员对象的非静态属性！
//	}
//private:
//	static int mimi;
//}; 
//int Phone::id = 10086;
//int Phone::mimi = 520;
//
//class Person
//{
//public:
//	Person(string name, string pname) :m_name(name), m_phone(pname)
//	{
//		cout << "Person的构造函数调用" << endl;
//	}
//	~Person()
//	{
//		cout << "Person的析构函数调用" << endl;
//	}
//	string m_name;
//	Phone m_phone;
//
//};
//void test1()
//{
//	Person p1("小王", "遥遥领先");
//	cout << p1.m_name << "拿着" << p1.m_phone.m_pname << endl;
//}
//void test2()
//{
//	//静态成员变量 不属于某个对象，所有对象都共用一份数据
//	Phone p2("遥遥领先");
//	cout << p2.id << endl;
//	Phone p3("???");
//	p3.id = 10101;
//	cout << p2.id << endl;//通过对象进行访问
//	cout << Phone::id << endl;//通过类名进行访问
//  //cout << Phone.mimi << endl;//类名访问也访问不了私有
//	
//	Phone::func();
//}
//
//int main()
//{
//	test1();
//	cout << endl;
//	test2();
//	return 0;
//}
//
//
//#include<iostream>
//using namespace std;
//
//class Person1
//{
//public:
//	int m_a;//非静态成员变量 属于类的对象上的
//	static int m_b;//静态成员变量 不属于类的对象上
//
//	void func(){}//非静态成员函数 不属于类的对象上
//	static void func2(){}//静态成员函数 不属于类对象上
//	//总结：只有非静态成员变量属于类的对象上
//};
//class Person2
//{
//public:
//	Person2(int age)
//	{
//		//this指针指向的是被调用的成员函数 所属的对象
//		this->age = age;
//	}
//
//	Person2& personadd(Person2& p)
//	{
//		this->age += p.age;
//		return *this;
//	}
//    int age;//习惯用m_age就不会有名称冲突的发生
//
//	void showclassname()
//	{
//		cout << "this is Person class" << endl;
//	}
//	void showclassage()
//	{
//		if (this == NULL)//提高代码的健壮性（防止出错）
//		{
//			cout << "NULL" << endl;
//			return;
//		}
//		cout << "age = " << age << endl;
//	}
//	
//};
//class Person3
//{
//public:
//	//this指针的本质 是指针常量 指针的指向是不能修改的
//	//const Person * const this;
//	//在成员函数后面加const，修饰的实际上是this指针，让指针的值也不能改；
//	void showPerson() const//常函数
//	{
//		//this->m_a = 100;//不能改
//		//this->NULL;//this指针不能修改指针的指向
//		this->m_b = 100;
//	}
//	void persontest() {};
//	int m_a;
//	mutable int m_b;//特殊变量，加关键字mutable,在常函数中也能更改值
//};
//
//void test1()
//{
//	Person1 p;
//	// 空对象占用内存为：1    //这是为了区分空对象占用内存的位置
//	cout << "size of p = " << sizeof(p) << endl;
//}
//void test2()
//{
//	Person2 p1(10);
//	Person2 p2(8);
//	p2.personadd(p1);
//	cout << "p2 age = " << p2.age << endl;
//	p2.personadd(p1).personadd(p1).personadd(p1).personadd(p1);//链式编程思想
//	cout << "p2 age = " << p2.age << endl;
//}
//void test3()
//{
//	Person2* p = NULL;
//	p->showclassname();
//	p->showclassage();//没有if的话会报错，传入的指针为空
//}
//void test4()
//{
//	Person3 p;
//	p.showPerson();
//	const Person3 p1;//常对象
//	//p1.m_a = 100;
//	p1.m_b = 100;//特殊变量在常对象中也能更改
////常对象只能调用常函数
//    p1.showPerson();
//	//p1.persontest();//常对象 不可以调用普通成员函数
//	//因为普通成员函数可以修改属性，而常对象本身就不允许修改属性
//	
//}
//int main()
//{
//	test1();
//	cout << endl;
//	test2();
//	cout << endl;
//	test3();
//	cout << endl;
//	test4();
//	return 0;
//}
//

////友元：
//#include<iostream>
//#include<string>
//using namespace std;
//
//class Building;//提前声明
//class Goodgay
//{
//public:
//	Goodgay();
//	~Goodgay();
//	void visit();
//	Building* building;
//};
//class Goodgay1
//{
//public:
//	Goodgay1();
//	~Goodgay1();
//
//	void visit1();//可以访问私有
//	void visit2();//不可以访问私有
//
//	Building* building1;
//};
//class Building
//{
//	//加friend 可以访问私有成员,全局函数作友元
//	friend void goodGay(Building* building);
//	//类作友元
//	friend class Goodgay;
//	//成员函数作友元
//	friend void Goodgay1::visit1();
//public:
//	Building();
//	string m_Settingroom;
//private:
//	string m_Bedroom;
//
//};
//
//Building:: Building()
//{
//	m_Bedroom = "卧室";
//	m_Settingroom = "客厅";
//}
//Goodgay::Goodgay()
//{
//	//创建建筑物对象
//	building = new Building;
//}
//Goodgay::~Goodgay()
//{
//	if(building!=NULL)
//	{
//		delete building;
//		building = NULL;
//	}
//}
//void Goodgay::visit()
//{
//	cout << "好基友的类的函数正在访问：" << building->m_Settingroom << endl;
//	cout << "好基友的类的函数正在访问：" << building->m_Bedroom << endl;
//}
//
//Goodgay1::Goodgay1()
//{
//	building1 = new Building;
//}
//Goodgay1::~Goodgay1()
//{
//	if (building1 != NULL)
//	{
//		delete building1;
//		building1 = NULL;
//	}
//}
//void Goodgay1::visit1()//可访问私有
//{
//	cout << "好基友的成员函数正在访问：" << building1->m_Settingroom << endl;
//	cout << "好基友的成员函数正在访问：" << building1->m_Bedroom << endl;
//}
//void Goodgay1::visit2()//不可以访问私有
//{
//	cout << "成员函数正在访问：" << building1->m_Settingroom << endl;
//  //cout << "好基友的全局函数正在访问：" << building1->m_Bedroom << endl;
//}
//
//
////全局函数作友元
//void goodGay(Building* building)
//{
//	cout << "好基友的全局函数正在访问：" << building->m_Settingroom << endl;
//
//	cout << "好基友的全局函数正在访问：" << building->m_Bedroom << endl;
//}
//
//void test1()
//{
//	Building building1;
//	goodGay(&building1);
//	cout << endl;
//
//	Goodgay gg;
//	gg.visit();
//	cout << endl;
//
//	Goodgay1 gg1;
//	gg1.visit1();
//	gg1.visit2();
//}
//int main()
//{
//	test1();
//	return 0;
//}
//
////运算符重载
//#include<iostream>
//#include<string>
//using namespace std;
//class Person
//{
//public:
//	//成员函数重载运算符
//	//Person operator+(Person& p)
//	//{
//	//	Person t;
//	//	t.m_a = m_a + p.m_a;
//	//	t.m_b = m_b + p.m_b;
//	//	return t;
//	//}
//	int m_a;
//	int m_b;
//};
////全局函数重载运算符：
//Person operator + (Person & p1,Person& p2)//加号运算符重载
//{
//	Person t;
//	t.m_a = p1.m_a + p2.m_a;
//	t.m_b = p1.m_b + p2.m_b;
//	return t;
//}
//Person operator+(Person& p1, int a)
//{
//	Person t;
//	t.m_a = p1.m_a + a;
//	t.m_b = p1.m_b + a;
//	return t;
//}
////cout属于输出流类型ostream
//ostream & operator<<(ostream &cout, Person &p)
//{
//	cout << "m_a=" << p.m_a << " m_b=" << p.m_b;
//	return cout; //链式编程的思想
//}
//
//class Myint
//{
//	friend ostream& operator<<(ostream& cout,const Myint& myint);
//public:
//	Myint()
//	{
//		m_a = 0;
//	}
//	//前置递增
//	Myint& operator++()
//	{
//		m_a++;
//		return *this;
//	}
//	//后置递增
//	//int代表占位参数，用来区分前置和后置递增
//	Myint operator++(int)
//	{
//		Myint t = *this;
//		this->m_a++;
//		return t;
//	}
//private:
//	int m_a;
//};
//ostream& operator<<(ostream& cout,const Myint& myint)
//{
//	cout << myint.m_a;
//	return cout;
//}
//
//class Man
//{
//public:
//	Man(){}
//	Man(int age)
//	{
//		m_age = new int(age);
//	}
//	~Man()
//	{
//		if (m_age != NULL)
//		{
//			delete m_age;
//			m_age = NULL;
//		}
//	}
//	//重载复制运算符 =
//	Man & operator=(Man & m)
//	{
//		if (m_age != NULL)
//		{
//			delete m_age;
//			m_age = NULL;
//		}
//		m_age = new int (*m.m_age);
//		return *this;
//	}
//
//	int* m_age;
//};
//class MyPrint
//{
//public:
//	void operator()(string t)
//	{
//		cout << t << endl;
//	}
//};
//class MyAdd
//{
//public:
//	int operator()(int a, int b)
//	{
//		return a + b;
//	}
//};
//void test1()
//{
//	//+
//	Person p1;
//	p1.m_a = 10; p1.m_b = 20;
//	Person p2;
//	p2.m_a = 30; p2.m_b = 40;
//
//	Person p3 = p1 + p2;
//	//本质是：p3 = p1.operator+(p2); 或 p3=operator(p1,p2);
//	cout << "p3.m_a=" << p3.m_a << "  p3.m_b=" << p3.m_b << endl;
//	//运算符重载还能发生函数重载
//	Person p4 = p1 + 100;
//	cout << "p4.m_a=" << p4.m_a << "  p4.m_b=" << p4.m_b << endl;
//	cout << endl;
//
//	// <<  （左移运算符）
//	cout << p1 << endl;
//	cout << endl;
//
//	//++
//	Myint myint;
//	cout << myint << endl;//0
//	cout << ++myint << endl;//1
//	cout << ++(++myint) << endl;//3
//	cout << myint++ << endl;//3
//	cout << myint << endl;//4
//	cout << endl;
//
//	// =
//	Man m1(18);
//	Man m2(20);
//	cout << *m1.m_age << endl;
//	cout << *m2.m_age << endl;
//	m2 = m1;
//	cout << *m2.m_age << endl;
//	//赋值运算符是从右往左运算：(把右值赋给左值）
//	int a = 10, b = 20, c = 30;
//	a = b = c;
//	cout << "a=" << a << " b=" << b << " c=" << c << endl;//30 30 30
//	//链式编程思想
//	Man m3(28);
//	m1 = m2 = m3;
//	cout << "m1=" << *m1.m_age << " m2=" << *m2.m_age << " m3=" << *m3.m_age << endl;
//	cout << endl;
//	// > < 和上面同理
//
//
//	//函数调用运算符 () 的重载
//	//重载后的使用方式非常像函数的调用，也成为仿函数，没有固定写法，非常灵活
//	MyPrint mp;
//	mp("hello world");//很像函数调用
//	MyAdd ma;
//	int ret = ma(10, 8);
//	cout << "ret=" << ret << endl;
//	//匿名函数对象
//	cout << MyAdd()(100, 100) << endl;//MyAdd()为匿名对象
//}
//int main()
//{
//	test1(); 
//	return 0;
//}
//
//
//继承
//#include<iostream>
//#include<string>
//using namespace std;
////愚蠢的方式实现：
//class Java
//{
//public:
//	void header()
//	{
//		cout << "登录注册（公共头部）" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心（公共底部）" << endl;
//	}
//	void left()
//	{
//		cout << "Java  C++  Python（公共分类列表）" << endl;
//	}
//	void content()
//	{
//		cout << "Java学科视频" << endl;
//	}
//};
//class Python
//{
//public:
//	void header()
//	{
//		cout << "登录注册（公共头部）" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心（公共底部）" << endl;
//	}
//	void left()
//	{
//		cout << "Java  C++  Python（公共分类列表）" << endl;
//	}
//	void content()
//	{
//		cout << "Python学科视频" << endl;
//	}
//};
//class Cpp
//{
//public:
//	void header()
//	{
//		cout << "登录注册（公共头部）" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心（公共底部）" << endl;
//	}
//	void left()
//	{
//		cout << "Java  C++  Python（公共分类列表）" << endl;
//	}
//	void content()
//	{
//		cout << "C++学科视频" << endl;
//	}
//};

//继承的方式实现：class 子类 : 继承方式  父类  {  };
// 子类 也称为 派生类
// 父类 也称为 基类
//可以减少重复的代码
//class BasePage //公共的页面
//{
//public:
//    void header()
//	{
//		cout << "登录注册（公共头部）" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心（公共底部）" << endl;
//	}
//	void left()
//	{
//		cout << "Java  C++  Python（公共分类列表）" << endl;
//	}
//};
////各类页面：
//class Java :public BasePage  //  :public BasePage 为继承BasePage的公共部分 
//{
//public:
//	void content()
//	{
//		cout << "Java学科视频" << endl;
//	}
//};
//class Python :public BasePage
//{
//public:
//	void content()
//	{
//		cout << "Python学科视频" << endl;
//	}
//};
//class Cpp :public BasePage
//{
//public:
//	void content()
//	{
//		cout << "C++学科视频" << endl;
//	}
//};
//
//void test1()
//{
//	cout << "Java下载视频页面如下：" << endl;
//	Java ja;
//	ja.header();  ja.left(); ja.footer();ja.content();
//	cout << "------------------------------" << endl;
//	cout << "Python下载视频页面如下：" << endl;
//	Python py;
//	py.header();  py.left();  py.footer();py.content();
//	cout << "------------------------------" << endl;
//	cout << "C++下载视频页面如下：" << endl;
//	Cpp cp;
//	cp.header();  cp.left();  cp.footer();cp.content();
//	cout << "------------------------------" << endl;
//}
//
////继承方式：
////父类，基类
//class A 
//{
//public:
//	A()
//	{
//		cout << "父类构造" << endl;
//	}
//	~A()
//	{
//		cout << "父类析构" << endl;
//	}
//	void func()
//	{
//		cout << "父类下的同名函数调用" << endl;
//	}
//public:
//	int a = 200;
//protected:
//	int b;
//private:
//	int c;
//};
//
////子类，派生类：
//class B1 :public A   //公有继承
//{
//    //  a 继承为public
//	//  b 继承为protected
//	//  c 不能继承 不可访问
////相当于：
////public:
////	int a = 100;
////protected:
////	int b;
//public:
//	B1()
//	{
//		cout << "子类构造" << endl;
//	}
//	~B1()
//	{
//		cout << "子类析构" << endl;
//	}
//	void func()
//	{
//		cout << "子类下的同名函数调用" << endl;
//	}
//};
//
//class B2 :protected A  //保护继承
//{
//	//  a和b 都继承为protected
//	//  c 不能继承 无法访问
////相当于：
//protected:
//	int a;
//	int b;
//};
//
//class B3 :private A  //私有继承
//{
//	//  a和b 都继承为private
//	//  c 不能继承，无法访问
////相当于：
//private:
//	int a;
//	int b;
//};
//
////利用开发人员命令提示工具查看对象模型
////跳转盘符 C：
////跳转文件路径  cd 输入具体路径
////查看命名
//// cl /d1 reportSingleClassLayout类名 文件名
//
//
//void test2()
//{
//	cout << "size of Son = " << sizeof(B1) << endl; //20 （5个int类）
//	//父类所有的非静态成员都会被子类继承下去，虽然访问不到  但确实都被继承了！
//	
//	//继承中的构造和析构顺序:
//	B1 b;
//}
//void test3()
//{
//	//继承中同名成员的处理
//	B1 b;
//	cout << "子类下的 a = " << b.a << endl;//直接调用就是子类的
////如果通过子类对象 访问到父类的同名成员 要加上作用域。
//	cout << "父类下的 a = " << b.A::a << endl;
//
//	b.func();//直接调用是子类的
//	b.A::func();//加上作用域就是调用父类的同名函数。
//}
//int main()
//{
//	test1();
//	test2();
//	cout << "--------------------------" << endl;
//	test3();
//	return 0;
//}
//
//#include<iostream>
//using namespace std;
//class Base
//{
//public:
//	static int m_a;
//	static void func()
//	{
//		cout << "Base静态成员函数调用" << endl;
//	}
//};
//int Base::m_a = 100;
//class Son:public Base
//{
//public:
//	static int m_a;
//	static void func()
//	{
//		cout << "Son静态成员函数调用" << endl;
//	}
//};
//int Son::m_a = 200;
////多继承(不建议开发时使用)
//class Base1
//{
//public:
//	int m_a;
//	Base1()
//	{
//		m_a = 100;
//	}
//};
//class Base2
//{
//public:
//	int m_a;
//	Base2()
//	{
//		m_a = 200;
//	}
//};
////继承Base1和Base2
//class Son0:public Base1,public Base2
//{
//public:
//	Son0()
//	{
//		m_c = 300;
//		m_d = 400;
//	}
//	int m_c;
//	int m_d;
//};
//void test1()
//{
////同名静态成员
//	//通过对象访问
//	Son s;
//	cout << "Son m_a = " << s.m_a << endl;
//	cout << "Base m_a = " << s.Base::m_a << endl;
//	cout << endl;
//	//通过类名访问
//	cout << "Son m_a = " << Son::m_a << endl;
//	cout << "Base m_a = " << Son::Base::m_a << endl;
////同名静态成员函数
//	//对象
//	s.func();
//	s.Base::func();
//	//类名
//	Son::func();
//	Son::Base::func();
//}
//void test2()
//{
//	Son0 s;
//	cout << "sizeof son = " << sizeof(s) << endl;
//	//父类中出现同名成员，要加作用域区分
//	cout << "Base1::m_a = " << s.Base1::m_a << endl;
//	cout << "Base2::m_a = " << s.Base2::m_a << endl;
//}
//int main()
//{
//	test1();
//	cout << "--------------------------" << endl;
//	test2();
//	return 0;
//}

//菱形继承
//#include<iostream>
//using namespace std;
//
//class Animal
//{
//public:
//	int m_age;
//};
////利用虚继承来解决菱形继承的问题
////继承之前加上 virtual 变为虚继承
////Animal为虚基类
//class Sheep :virtual public Animal {};
//
//class Camel :virtual public Animal {};
//
//class YangTuo :public Sheep, public Camel {};
//
//void test1()
//{
//	YangTuo st;
//	st.Sheep::m_age = 18;
//	cout << "sheep age = " << st.Sheep::m_age << endl;
//	st.Camel::m_age = 20;
//	cout << "camel age = " << st.Camel::m_age << endl;
////菱形继承，导致有两份age的数据，资源浪费
//	//加上 virtual 后，从继承值变为继承 指向animal中m_age的一个指针(vbptr)
//	//所以无论从sheep还是camel上更改age 都相当于更改同一份animal上的m_age
//	cout << "sheep age = " << st.Sheep::m_age << endl;
//	cout << "st.m_age = " << st.m_age << endl;
//}
//int main()
//{
//	test1();
//	return 0;
//}



多态:
#include<iostream>
#include<string>
using namespace std;
静态多态： 函数重载和运算符重载，复用函数名
 在编译阶段确定函数地址 （早绑定）
动态多态： 派生类和虚函数实现运行多态
 在运行阶段确定函数地址 （晚绑定）
class Animal
{
public:
	virtual void speak()
	{
		cout << "动物说话" << endl;
	}
	virtual void speak() = 0;//纯虚函数,这个类变为抽象类。
	Animal()
	{
		cout << "animal的构造函数调用" << endl;
	}
	//虚析构
	virtual ~Animal()
	{
		cout << "animal的虚析构函数调用" << endl;
	}

	virtual ~Animal() = 0;//纯虚析构
};
Animal::~Animal()//纯虚析构类外实现
{
	cout << "animal的纯虚析构函数调用" << endl;
}

class Cat :public Animal
{
public:
	Cat() {}
	Cat(string name)
	{
		cout << "cat的构造函数调用" << endl;
		m_name = new string(name);
	}
	~Cat()
	{
		cout << "cat的析构函数调用" << endl;
		if (m_name != NULL)
		{
			delete m_name;
			m_name = NULL;
		}
	}
	void speak()
	{
		cout << *m_name << "小猫说话" << endl;
	}
	string* m_name;
};
class Dog :public Animal
{
public:
	void speak()
	{
		cout << "小狗说话" << endl;
	}
};
class Bird :public Animal
{
public:

};

地址早绑定：在编译阶段就确定函数地址
如果要猫说话，地址就不能提前绑定，要晚绑定，在animal说话函数前加virtual，变为虚函数
void doSpeak(Animal& animal)
{
	animal.speak();
}
动态函数的条件：
 1、有继承关系
 2、子类要重写父类的虚函数
父类的指针或者引用 执行子类对象
void test1()
{
	Cat cat("cici");
	doSpeak(cat);//变为先传入什么，再确定地址，执行函数
	Dog dog;
	doSpeak(dog);
}
void teat2()
{
	cout << "size of animal = " << sizeof(Animal) << endl;
	加上virtual后，变为指针（vfptr）虚函数指针
}
void test3()
{
	Animal animal; //报错，不能用抽象类实例化对象
	Bird bird;  //抽象类的子类必须重写父类的纯虚函数，否则也属于抽象类，无法实例化对象

	Animal* animal = new Cat("Tom");
	animal->speak();
	
	delete animal;
}
int main()
{
	test1();
	cout << "---------------------------" << endl;
	teat2();
	cout << "------------------------------" << endl;
	test3();
	return 0;
}