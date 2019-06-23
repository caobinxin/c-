#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Component{

    private:
        string m_name;
    
    public:
        Component(string name):m_name(name){}
    public:
        virtual void onAdd(Component*) = 0;
        virtual void onRemove(Component*) = 0;
        virtual void onDisplay(int depth) = 0;
        virtual string onGetName(){
            return m_name;
        }      
};

class Leaf: public Component{

    public:
        Leaf(string name):Component(name){}

        virtual void onAdd(Component* c){
            printf("叶子节点不能添加");
        }

        virtual void onRemove(Component* c){
            printf("叶子节点不能删除");
        }

        virtual void onDisplay(int depth){
            string str(depth, '-');
            str += onGetName();

            cout << str << endl;
        }
};

// 树枝节点
class Composite:public Component{
    
    private:
        vector<Component *> component;
    public:
        Composite(string name):Component(name){}

        virtual void onAdd(Component* c){
            component.push_back(c);
        }

        virtual void onRemove(Component* c){
            
            vector<Component *>::iterator iter = component.begin();
            while (iter != component.end())
            {
                if(*iter == c){
                    component.erase(iter);
                }

                iter++;
            }
            
        }

        virtual void onDisplay(int depth){

            string str(depth,'-');
            str += onGetName();

            cout << str << endl;

            vector<Component *>::iterator iter = component.begin();
            while ((iter != component.end()))
            {
                (*iter)->onDisplay(depth + 8);
                iter++;
            }
            
        }
        
};


int main(int argc, char const *argv[])
{
    Component *p = new Composite("小李");
    p->onAdd(new Leaf("李1"));
    p->onAdd(new Leaf("李2"));
    p->onAdd(new Leaf("李3"));

    Component *sub = new Composite("小虎");
    sub->onAdd(new Leaf("虎1"));
    sub->onAdd(new Leaf("虎2"));
    sub->onAdd(new Leaf("虎3"));

    p->onAdd(sub);

    p->onDisplay(4);
    
    return 0;
}
