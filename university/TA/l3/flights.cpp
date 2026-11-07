#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <limits>
using namespace std;
struct Node{int num;string from,to;Node*next;};
class HashTable{
    int m;
    vector<Node*> t;
    int h(int k)const{
        const double A=0.6180339887498949;
        double x=k*A;
        x-=floor(x);
        return(int)(m*x);
    }
public:
    HashTable(int size):m(size),t(size,nullptr){}
    ~HashTable(){for(int i=0;i<m;i++){Node*p=t[i];while(p){Node*q=p->next;delete p;p=q;}}}
    Node*find(int k)const{
        for(Node*p=t[h(k)];p;p=p->next)if(p->num==k)return p;
        return nullptr;
    }
    bool add(int k,const string&from,const string&to){
        if(find(k))return false;
        int i=h(k);
        t[i]=new Node{k,from,to,t[i]};
        return true;
    }
    bool remove(int k){
        int i=h(k);
        Node*prev=nullptr;
        for(Node*p=t[i];p;prev=p,p=p->next){
            if(p->num==k){
                if(prev)prev->next=p->next;
                else t[i]=p->next;
                delete p;
                return true;
            }
        }
        return false;
    }
    void printRow(int i)const{
        for(Node*p=t[i];p;p=p->next)cout<<"  рейс "<<p->num<<": "<<p->from<<" -> "<<p->to<<"\n";
    }
    void printAll()const{
        for(int i=0;i<m;i++){
            cout<<"[сегмент "<<i<<"]";
            if(!t[i])cout<<" порожньо\n";
            else{cout<<"\n";printRow(i);}
        }
    }
    void printSegmentOf(int k)const{
        if(!find(k)){cout<<"Рейс "<<k<<" не знайдено.\n";return;}
        int i=h(k);
        cout<<"Рейс "<<k<<" у сегменті "<<i<<". Усі рейси сегмента:\n";
        printRow(i);
    }
};
int readInt(const string&p){
    int x;
    cout<<p;
    while(!(cin>>x)){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"Помилка вводу. "<<p;
    }
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    return x;
}
string readStr(const string&p){
    string s;
    cout<<p;
    getline(cin,s);
    return s;
}
int main(){
    int m=readInt("Кількість сегментів таблиці: ");
    if(m<1)m=7;
    HashTable ht(m);
    int c;
    do{
        cout<<"\nАвіабілети\n1. Додати рейс\n2. Видалити рейс\n3. Показати таблицю\n4. Знайти рейс\n5. Усі рейси в сегменті рейсу\n6. Завантажити тестові дані\n0. Вихід\n";
        c=readInt("Вибір: ");
        if(c==1){
            int k=readInt("Номер рейсу: ");
            string a=readStr("Звідки: ");
            string b=readStr("Куди: ");
            cout<<(ht.add(k,a,b)?"Додано.\n":"Рейс з таким номером уже є.\n");
        }else if(c==2){
            int k=readInt("Номер рейсу: ");
            cout<<(ht.remove(k)?"Видалено.\n":"Не знайдено.\n");
        }else if(c==3)ht.printAll();
        else if(c==4){
            int k=readInt("Номер рейсу: ");
            Node*p=ht.find(k);
            if(p)cout<<"Рейс "<<p->num<<": "<<p->from<<" -> "<<p->to<<"\n";
            else cout<<"Не знайдено.\n";
        }else if(c==5)ht.printSegmentOf(readInt("Номер рейсу: "));
        else if(c==6){
            ht.add(101,"Київ","Львів");ht.add(202,"Львів","Варшава");ht.add(303,"Одеса","Київ");
            ht.add(404,"Чернівці","Київ");ht.add(505,"Харків","Львів");ht.add(606,"Київ","Відень");
            cout<<"Завантажено.\n";
        }else if(c!=0)cout<<"Невірний пункт меню.\n";
    }while(c!=0);
    return 0;
}
