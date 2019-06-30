#include <iostream>
#include <string>

using namespace std;

class CheckDug
{

public:
    void onStart();

public:
    virtual void onReadCode() = 0;
    virtual void onLocation() = 0;
    virtual void onCheckCode() = 0;
    virtual void onFixDub() = 0;
    virtual void onComplete() = 0;
};

void CheckDug::onStart()
{
    this->onReadCode();
    this->onLocation();
    this->onCheckCode();
    this->onFixDub();
    this->onComplete();
}

class CbxCheckDug : public CheckDug
{
public:
    string name;
    CbxCheckDug(string name):name(name){}

public:
    virtual void onReadCode(){
        cout << this->name << " 看 drm 相关的代码" << endl;
    }

    virtual void onLocation(){
        cout << this->name << " 定位 drm 相关的代码" << endl;
    }
    virtual void onCheckCode(){
        cout << this->name << " 检查 drm 相关的代码" << endl;
    }
    virtual void onFixDub(){
        cout << this->name << " 修复 drm 相关的代码" << endl;
    }
    virtual void onComplete(){
        cout << this->name << " 完成 drm dug" << endl;
    }

};


class SHCheckDug : public CheckDug
{
public:
    string name;
    SHCheckDug(string name):name(name){}

public:
    virtual void onReadCode(){
        cout << this->name << " 看 also 相关的代码" << endl;
    }

    virtual void onLocation(){
        cout << this->name << " 定位 also 相关的代码" << endl;
    }
    virtual void onCheckCode(){
        cout << this->name << " 检查 also 相关的代码" << endl;
    }
    virtual void onFixDub(){
        cout << this->name << " 修复 also 相关的代码" << endl;
    }
    virtual void onComplete(){
        cout << this->name << " 完成 also dug" << endl;
    }

};


int main(int argc, char const *argv[])
{
    CheckDug *zhaoP = new CbxCheckDug("曹斌鑫");

    zhaoP->onStart();

    CheckDug* hou = new SHCheckDug("少辉");
    hou->onStart();

    return 0;
}
