#include<iostream>
using namespace std;

class Animal
{
public:
    int age;
};

//利用虚继承 解决菱形继承的问题
//继承之前 加上关键字virtual变为虚继承
//Animal类称为虚基类
//羊类
class Sheep : virtual public Animal
{};
//骆驼类
class Camel : virtual public Animal
{};

class SheepCamel : public Sheep, public Camel
{

};

void test01()
{
    SheepCamel st;
    st.Sheep::age = 18;
    st.Camel::age = 28;
    //当菱形继承，两个父类拥有相同的数据，需要加以作用域区分
    cout << "st.Sheep::age = " << st.Sheep::age << endl;
    cout << "st.Camel::age = " << st.Camel::age << endl;
    cout << "st.age = " << st.age << endl;
    //这份数据我们知道，只有有一份就可以，菱形继承导致数据两份，资源浪费
}
int main()
{
    test01();
    return 0;
}