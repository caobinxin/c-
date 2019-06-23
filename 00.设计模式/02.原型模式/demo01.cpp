#include <iostream>
#include <string>

using namespace std;

class Resume{
    
    private:
        string name, sex, age, timeArea, company;

    public:
        Resume(){}
        Resume(string n){
            name = n;
        }

    void setPersonalInfo(string sex, string age){
        
        this->sex = sex;
        this->age = age;
    }

    void setName(string name){
        this->name = name;
    }

    void setWorkAttr(string timeArea, string company){
        
        this->timeArea = timeArea;
        this->company = company;
    }  

    void displayInfo(){
        cout << this->name<< " "<<endl;
        cout <<"    "<< timeArea << "    " << company << "      " << age << "       " << endl;
    }

    Resume * cloneWorkAttr(){
        Resume *tmp = new Resume();

        tmp->setName(this->name);
        tmp->setWorkAttr(this->timeArea, this->company);

        return tmp;
    }
};


int main(int argc, char const *argv[])
{
    Resume cbx("曹斌鑫");

    cbx.setPersonalInfo("男", "25");

    cbx.setWorkAttr("2019.4","北京超卓科技");


    Resume *cbx1 = cbx.cloneWorkAttr();
    
    cbx1->displayInfo();

    return 0;
}
