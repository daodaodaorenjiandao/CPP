#include <iostream>
#include <vector>
#include <functional>
#include <tuple>

using namespace std;

#pragma region for function

//////////////////////////////////////////////////////////////////////////
// 1 用于函数：递归、可变参数
//////////////////////////////////////////////////////////////////////////

void Print()
{
	cout << "the Print end." << endl;
}

//
void Print(int arg)
{
	cout << "arg is : " << arg << endl;
}

template<typename T, typename ... Types>
void Print(const T& arg1, const Types& ... args)
{
	cout << "arg1 is : " << arg1 << endl;
	//note: sizeof... is a operator
	cout << "the number of args is : " << sizeof...(args)+1 << endl << endl;

	//must have ... to extent arguments package
	Print(args...);
}

int main()
{
	//the last, call Print()
	Print(1, 2, 3, "123");

	//the last,call Print(int) best match
	Print(1, 2, 3, "123", 5);

	cin.get();
	return 0;
}

#pragma endregion


#pragma region for class

//////////////////////////////////////////////////////////////////////////
// 2 用于类的继承
//////////////////////////////////////////////////////////////////////////

//1
template<typename ...Values> class MyTuple;
//2.3 先写1 才能写出特例 (特例1)
template<>
class MyTuple<>
{

};

//2.2 (特例2)
template<class T>
class MyTuple<T>
{
public:
	MyTuple() {};
	MyTuple(const T& t)
		:data(t)
	{

	}

	T& head() { return data; }

private:
	T data;
};

template<class T1, class ... Types>
class MyTuple<T1, Types...> : public MyTuple<Types...>
{
public:
	typedef MyTuple<Types...> Tail;

	MyTuple() {}
	MyTuple(const T1& t1, const Types& ... args)
		:data(t1),
		MyTuple<Types...>(args...)
	{

	}

	T1& head() { return data; }
	Tail& tail() { return *this; }
private:
	T1 data;
};

int main2()
{
	MyTuple<int, const char*> tup(1, "char");

	cout << tup.head() << endl;
	cout << tup.tail().head() << endl;


	cin.get();
	return 0;
}

#pragma endregion