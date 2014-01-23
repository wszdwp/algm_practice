/*
先看如下的图示：


　　在图中深红色标记出来的地方正是主要问题所在，水陆两用汽车类继承了来自Car类与Boat类的属性与方法，Car类与Boat类同为AmphibianCar类的基类，在内存分配上AmphibianCar获得了来自两个类的SetWeight()成员函数，当我们调用a.SetWeight(3)的时候计算机不知道如何选择分别属于两个基类的被重复拥有了的类成员函数SetWeight()。

　　由于这种模糊问题的存在同样也导致了AmphibianCar a(4,200,1.35f);执行失败，系统会产生Vehicle”不是基或成员的错误。

　　以上面的代码为例，我们要想让AmphibianCar类既获得一个Vehicle的拷贝，而且又同时共享用Car类与Boat类的数据成员与成员函数就必须通过C++所提供的虚拟继承技术来实现。

　　我们在Car类和Boat类继承Vehicle类出，在前面加上virtual关键字就可以实现虚拟继承，使用虚拟继承后，当系统碰到多重继承的时候就会自动先加入一个Vehicle的拷贝，当再次请求一个Vehicle的拷贝的时候就会被忽略，保证继承类成员函数的唯一性。 

　　修改后的代码如下，注意观察变化：
*/
//程序作者:管宁    
//站点:www.cndev-lab.com    
//所有稿件均有版权,如要转载,请务必著名出处和作者    
  
#include <iostream>  
#include <stdio>
using namespace std;  
  
class Vehicle  
{  
    public:  
        Vehicle(int weight = 0)  
        {  
            Vehicle::weight = weight;  
            cout<<"载入Vehicle类构造函数"<<endl;  
        }  
        void SetWeight(int weight)  
        {  
            cout<<"重新设置重量"<<endl;  
            Vehicle::weight = weight;  
        }  
        virtual void ShowMe() = 0;  
    protected:  
        int weight;  
};  
class Car:virtual public Vehicle//汽车，这里是虚拟继承  
{  
    public:  
        Car(int weight=0,int aird=0):Vehicle(weight)  
        {  
            Car::aird = aird;  
            cout<<"载入Car类构造函数"<<endl;  
        }  
        void ShowMe()  
        {  
            cout<<"我是汽车！"<<endl;  
        }  
    protected:  
        int aird;  
};  
  
class Boat:virtual public Vehicle//船,这里是虚拟继承  
{  
    public:  
        Boat(int weight=0,float tonnage=0):Vehicle(weight)  
        {  
            Boat::tonnage = tonnage;  
            cout<<"载入Boat类构造函数"<<endl;  
        }  
        void ShowMe()  
        {  
            cout<<"我是船！"<<endl;  
        }  
    protected:  
        float tonnage;  
};  
  
class AmphibianCar:public Car,public Boat//水陆两用汽车,多重继承的体现  
{  
    public:  
        AmphibianCar(int weight,int aird,float tonnage)  
        :Vehicle(weight),Car(weight,aird),Boat(weight,tonnage)  
        //多重继承要注意调用基类构造函数  
        {  
            cout<<"载入AmphibianCar类构造函数"<<endl;  
        }  
        void ShowMe()  
        {  
            cout<<"我是水陆两用汽车！"<<endl;  
        }  
        void ShowMembers()  
        {  
            cout<<"重量："<<weight<<"顿，"<<"空气排量："<<aird<<"CC，"<<"排水量："<<tonnage<<"顿"<<endl;  
        }  
};  
int main()  
{  
    AmphibianCar a(4,200,1.35f);  
    a.ShowMe();  
    a.ShowMembers();  
    a.SetWeight(3);  
    a.ShowMembers();  
    system("pause");   
}