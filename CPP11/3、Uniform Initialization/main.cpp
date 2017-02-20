#include <iostream>
#include <vector>
#include <array>

using namespace std;

class MyClass
{
public:
	MyClass(int i, int j, int k)
	{
		m_datas = { i,j,k };
	}

	std::vector<int>::iterator begin()
	{
		return m_datas.begin();
	}

	std::vector<int>::iterator end()
	{
		return m_datas.end();
	}

private:
	std::vector<int> m_datas;
};

int main()
{
	//并没有利用array作为中间对象
	std::vector<int> vec = { 1,2,3 };

	for(auto e : vec)
		cout << e << " ";
	cout << endl;

	//for MyClass
	//1 error 参数太少
	//MyClass mc = { 1,2};

	//2 error 参数太多
	//MyClass mc = {1,2,3,4};

	//3 ok
	MyClass mc1 = { 1,2,3 };		//有三个参数的构造函数
	MyClass mc2{ 4,5,6 };			//有三个参数的构造函数 效果同上

	for(auto& e : mc1)
	{
		cout << e++ << " ";
	}
	cout << endl;

	for(auto e : mc1)
	{
		cout << e << " ";
	}
	cout << endl;

	cin.get();
	return 0;
}