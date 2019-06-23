#include <iostream>
#include <string>

using namespace std;

class Persion
{
    public:
        string name;
        string age;
    public:
        virtual Persion* clone() = 0;
        virtual void printT() = 0;
        Persion(string name, string age):name(name),age(age){}
        Persion(){}
};

class Man: public Persion
{
    public:
        Man(string name, string age): Persion(name, age){
            cout << "Man(name, age)" << endl;
        }

        Man(){}

        Persion * clone(){
            Man *tmp = new Man;
            *tmp = *this; // 浅拷贝
            return tmp;
        }

        void printT(){
            cout << "Man printT... name:"<< name << " age:"<< age << endl;
        }
};

int main(int argc, char const *argv[])
{
    Persion *p1 = new Man("曹斌鑫", "25");
    p1->printT();

    Persion *p2 = p1->clone();
    p2->printT();

    Persion *p3 = new Man;
    Persion *p4 = p3->clone();
    p4->printT();

    return 0;
}



