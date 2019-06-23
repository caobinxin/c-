#include <iostream>
#include <string>
#include <list>

using namespace std;

class IFile{
    
    public:
        virtual void display() = 0;
        virtual int add(IFile *ifile) = 0;
        virtual int remove(IFile *ifile) = 0;
        virtual list<IFile *>* getChild() = 0;
};

class File: public IFile{
    
    public:
        File(string name){
            m_name = name;
        }

        virtual void display(){
            cout << m_name << endl;
        }

        virtual int add(IFile *ifile){
            return -1;
        }

        virtual int remove(IFile *ifile){
            return -1;
        }

        virtual list<IFile *>* getChild(){
            return NULL;
        }

    private:
        string m_name;
};

class Dir : public IFile{
    
    public:
        Dir(string name){
            m_name = name;
            m_list = new list<IFile *>;
            m_list->clear();
        }

        virtual void display(){
            cout << m_name << endl;
        }

        virtual int add(IFile* ifile){
            m_list->push_back(ifile);
            return 0;
        }

        virtual int remove(IFile* ifile){
            m_list->remove(ifile);
            return 0;
        }

        virtual list<IFile *> * getChild(){
            return m_list;
        }

        private:
            string m_name;
            list<IFile*> *m_list;
};


void showTree(IFile* root, int level){

    int i = 0;
    if(root == NULL){
        return;
    }

    for(i = 0; i < level; i++){
        printf("\t");
    }

    // 1. 显示根 节点
    root->display();

    // 2. 若根节点有孩子
    // 判断孩子是文件，显示名字
    // 判断孩子是目录， showTree(子目录)

    list<IFile *> *mylist = root->getChild();
    if(mylist != NULL){ // 说明是一个目录
        for(list<IFile *>::iterator it = mylist->begin(); it != mylist->end(); it++){
            if( (*it)->getChild() == NULL){
                for(i = 0; i <= level; i++){
                    printf("\t");
                }
                (*it)->display();
            }else{
                showTree(*it, level + 1);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    Dir *root = new Dir("c");

    Dir *dir1 = new Dir("111dir");
    File *aaafile = new File("aaa.txt");

    //获取root结点下的 孩子集合
    list<IFile *>  *mylist =  root->getChild();

    root->add(dir1);
    root->add(aaafile);

    for ( list<IFile *>::iterator it=mylist->begin(); it!=mylist->end(); it++ )
    {
        (*it)->display();
    }

    Dir *dir222 = new Dir("222dir");
    File *bbbfile = new File("bbb.txt");
    dir1->add(dir222);
    dir1->add(bbbfile);

    cout << "通过 showTree 方式显示 root 结点下的所有子结点" << endl;

    showTree(root, 0);

    system("pause");
    return 0;
}
