#include<iostream>
using namespace std;

typedef int DataType;
#define Node ElemType
#define ERROR NULL

//创建一个节点类
class Node
{
public:
    int data;      //数据域
    Node *next;     //指针域
};

//创建一个单链表类
class Linklist
{
public:
    Linklist(); //构建一个单链表
    ~Linklist(); //销毁一个单链表
    void Createlinklist(int n);//创建一个单链表
    void Travallinklist();  //遍历线性表
private:
    ElemType *head; //头节点
};

//初始化单链表
Linklist::Linklist()
{
    head = new ElemType;
    head -> data = 0;   //头节点的数据域定义为0
    head -> next = NULL;    //头节点的指针域为空
}

Linklist::~Linklist()
{
    delete head;
}

void Linklist::Createlinklist(int n)
{
    ElemType *pnew, *ptemp;
    ptemp = head;
    if(n < 0){
        cout<<"the input number of nodes is incorrect"<<endl;
        exit(EXIT_FAILURE);
    }
    for(int i=0; i<n; i++){     //将个值一个一个插入到链表中
        pnew = new ElemType;
        cout<< "type in "<< i+1 << "-th"<<endl;
        cin>> pnew -> data;
        pnew -> next = NULL; //新节点的下一个地址为空
        ptemp -> next = pnew; //当前节点的下一个地址设为新节点
        ptemp = pnew; //将当前节点设定为新节点
    }
}

void Linklist::Travallinklist(){
    
}

int main()
{

    return 0;
}
