#include<iostream>
using namespace std;

class BaseString
{
	//函数重载可以让常量也可以调用GetData(), 必须有引用&, 否则无法修改数据
	friend char* GetData(BaseString& str);
	friend const char* GetData(const BaseString& str);
public:
	BaseString();
	BaseString(const char* Data);
	unsigned int GetLength() const;
	void Display();
	void Input();
	~BaseString();
protected:
	char Data[50];
	unsigned int Length;
};

BaseString::BaseString()
{
	cout << "BaseString无参构造函数" << endl;
	Length = 0;
	Data[0] = '\0';
}

BaseString::BaseString(const char* Data)
{
	cout << "BaseString的有参构造函数" << endl;
	int cnt = 0;
	while (Data[cnt] != '\0' && cnt < 49)
	{
		this->Data[cnt] = Data[cnt];
		cnt++;
	}
	this->Data[cnt] = '\0';
	this->Length = cnt;
}

BaseString::~BaseString() 
{ 
	cout << "BaseString的析构函数" << endl;
}
//常函数
unsigned int BaseString::GetLength() const
{
	return this->Length;
}

void BaseString::Display()
{
	for (int i = 0; i < this->Length; i++)
		cout << this->Data[i];
	cout << endl;
}

void BaseString::Input()
{
	cin >> Data;
	int cnt = 0;
	while (Data[cnt] != '\0')
		cnt++;
	Length = cnt;
}

char* GetData(BaseString& str)
{
	return (str.Data);
}

const char* GetData(const BaseString& str)
{
	return (str.Data);
}

class ReString : public BaseString
{
public:
	ReString();
	ReString(const char* Data);
	void Inverse();
	~ReString();
};

ReString::ReString()
{
	cout << "ReString无参构造函数" << endl;
}
ReString::ReString(const char* Data) : BaseString(Data) 
{
	cout << "ReString的有参构造函数" << endl;
}
void ReString::Inverse()
{
	int length = GetLength();
	char* ptr = GetData(*this);
	int left = 0, right = length - 1;
	while (left < right)
	{
		char tmp = ptr[left];
		ptr[left] = ptr[right];
		ptr[right] = tmp;
		left++;
		right--;
	}
}
ReString::~ReString() 
{
	cout << "ReString析构函数" << endl;
};

class CopyString : protected BaseString
{
public:
	CopyString();
	CopyString(const char* Data);
	void Copy(const CopyString& ob);
	void Display();
	~CopyString();
};

CopyString::CopyString() : BaseString()
{
	cout << "CopyString无参构造函数" << endl;
}
CopyString::CopyString(const char* Data) : BaseString(Data)
{
	cout << "CopyString有参构造函数" << endl;
}

void CopyString::Display()
{
	BaseString::Display();
}

void CopyString::Copy(const CopyString& ob)
{
	const char* ptr1 = GetData(ob);
	char* ptr2 = GetData(*this);
	int cnt = 0;
	while (ptr1[cnt] != '\0')
	{
		ptr2[cnt] = ptr1[cnt];
		cnt++;
	}
	ptr2[cnt] = '\0';
	this->Length = cnt;
}

CopyString::~CopyString() 
{
	cout << "CopyString析构函数" << endl;
}

class CmpString : private BaseString
{
public:
	CmpString();
	CmpString(const char* Data);
	int Compare(const CmpString& ob);
	~CmpString();
	void Display();

};

CmpString::CmpString() : BaseString()
{
	cout << "CmpString无参构造函数" << endl;
}

CmpString::CmpString(const char* Data) : BaseString(Data) 
{
	cout << "CmpString有参构造函数" << endl;
}

//因为这里是常参数，所有要将GetLength()定义为常函数
int CmpString::Compare(const CmpString& ob)
{
	if (this->GetLength() > ob.BaseString::GetLength())
		return 1;
	else if (this->GetLength() < ob.BaseString::GetLength())
		return -1;
	else
		return 0;
}
CmpString::~CmpString()
{
	cout << "CmpString析构函数" << endl;
}

void CmpString::Display()
{
	BaseString::Display();
}

class NewString : public ReString, public CopyString, public CmpString
{
public:
	//解决二义性方式3：使用using申明
	using BaseString::Display;
	//using BaseString::Display;
	//using CmpString::Display;
	//using CopyString::Display;
	//using ReString::Display;
	NewString();
	void Display();
	~NewString();
};

NewString::NewString()
{
	cout << "NewString无参构造函数" << endl;
}

//解决二义性方式1：重写父类中的同名函数
void NewString::Display()
{
	//可以使用不同的父类成员函数
	//BaseString::Display();
	ReString::Display();
	//CmpString::Display();
	//CopyString::Display();
	
}
NewString::~NewString()
{
	cout << "NewString析构函数" << endl;
}
//解决二义性方式2：使用类名限定
void test01()
{
	NewString new_string;
	//new_string.BaseString::Display();
	//new_string.CmpString::Display();
	//new_string.CopyString::Display();
	//new_string.ReString::Display();
}
int main()
{
	//基础字符串类型
	cout << endl;
	cout << "基础字符串类型" << endl;
	BaseString base_string("abcdef");
	base_string.Display();
	cout << endl;
	cout << base_string.GetLength() << endl;
	//反转字符串
	cout << endl;
	cout << "反转字符串" << endl;
	ReString re_string("abcdef");
	re_string.Inverse();
	re_string.BaseString::Display();
	cout << endl;
	//拷贝字符串
	cout << endl;
	cout << "拷贝字符串" << endl;
	CopyString copy_string1("abcdefghi");
	CopyString copy_string2;
	copy_string2.Copy(copy_string1);
	copy_string2.Display();
	cout << endl;
	//比较字符串
	cout << endl;
	cout << "比较字符串" << endl;
	CmpString cmp_string1("abc");
	CmpString cmp_string2("abcde");
	cout << cmp_string1.Compare(cmp_string2) << endl;
	cout << endl;
	cout << "测试函数" << endl;
	test01();
	return 0;
}