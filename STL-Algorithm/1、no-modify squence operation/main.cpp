#include <algorithm>
#include <iostream>
#include <vector>
#include <functional>
#include <string>

using namespace std;

class Log
{
public:
	Log(const char * message)
		:m_message(message)
	{
		cout << endl;
		cout << "begin ---  " << m_message << endl;
		
	}
	~Log() 
	{
		cout << endl;
		cout << "end   ---  " << m_message << endl;
	}

private:
	string m_message;
};

//1、all_of
#pragma region all_of
int all_of_Func(float k,int i = 2)
{
	if (k > 0)
		return k;
	else
		return 0;
}

int all_of_Func1(float k)
{
	if (k > 0)
		return k;
	else
		return 0;
}

void test_all_of()
{
	Log log(__FUNCTION__);
	//遍历标准数组,使用lambda对象
	int arr[] = { -1,2,4,5,6 };
	if (all_of(arr,
			   arr + sizeof(arr) / sizeof(arr[0]),
			   [](int i,int k = 1)	//可以使用多个参数
	{
		return i > 0;
	}))
		cout << "ok arr" << endl;
	else
		cout << "fail arr" << endl;
	//遍历容器 使用函数指针
	vector<int> vec = { 1,2,34,5,6 };
#if 0
	//对于函数指针和函数对象，不能使用多个参数，必须只能有一个参数
	function<int(float, int)> func = all_of_Func;
	//if (all_of(vec.begin(), vec.end(), func))
	if (all_of(vec.begin(), vec.end(), all_of_Func))	//按值传递，并没有传递默认参数的值！
		cout << "ok vec" << endl;
	else
		cout << "fail vec" << endl;
#endif
	if (all_of(vec.begin(), vec.end(), all_of_Func1))
		cout << "ok vec2";
	else
		cout << "fail vec2";
}
#pragma endregion

//2、any_of
#pragma region any_of
void test_any_of()
{
	Log log(__FUNCTION__);
	vector<int> vec = { 1,2,3,4,51 };
	if (any_of(vec.begin(),
			   vec.end(),
			   [](int value) {
		if (value == 2)
			return true;
		else
			return false;
	}))
	{
		cout << "test any_of ok" << endl;
	}
	else
		cout << "test any_of fail" << endl;
}
#pragma endregion

//3、none_of
#pragma region none_of
void test_none_of()
{
	Log log(__FUNCTION__);
	vector<int> vec = { 1,1,1,1,2,3 };
	//如果序列中存在一个元素满足条件，则返回false
	if (none_of(vec.begin(), vec.end(), [](int value) {
		if (value == 0)
			return true;
		else
			return false;
	}))
	{
		cout << "test none_of ok" << endl;
	}
	else
	{
		cout << "test none_of fail" << endl;
	}
}
#pragma endregion

//4、for_each
#pragma region for_each
void test_for_each()
{
	Log log(__FUNCTION__);
	vector<int> vec = { 1,1,1,1,2,3 };

	//修改前输出序列中所有元素
	for_each(vec.begin(), vec.end(), [](int value) {
		cout << value << " ";
	});
	cout << endl;
	
	//修改元素
	for_each(vec.begin(), vec.end(), [](int & value) {		//参数类型为int&，因为会进行修改
		if (value == 1)
			value = 2;
	});

	//输出修改之后的元素
	for_each(vec.begin(), vec.end(), [](int value) {
		cout << value << " ";
	});
	cout << endl;

	//move!!!
	//std::move
}
#pragma endregion


int main()
{
	//1、all_of
	//test_all_of();

	//2、any_of
	test_any_of();

	//3、none_of
	test_none_of();

	//4、for_each
	test_for_each();


	cin.get();
	return 0;
}
