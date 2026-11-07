#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <limits>
using namespace std;
struct Rec{string name,addr,phone;};
struct Entry{int cnt=0;vector<int> ids;};
vector<Rec> db;
map<string,Entry> dName,dAddr; // частотні словники: ключ -> {частота, індекси записів}
void addRec(const string&n,const string&a,const string&p){
    int id=db.size();
    db.push_back({n,a,p});
    dName[n].cnt++;
    dName[n].ids.push_back(id);
    dAddr[a].cnt++;
    dAddr[a].ids.push_back(id);
}
void printDict(const map<string,Entry>&d){
    if(d.empty()){cout<<"Словник порожній.\n";return;}
    for(auto&kv:d)cout<<"  "<<kv.first<<" — "<<kv.second.cnt<<"\n";
}
void queryAddr(const string&a){
    auto it=dAddr.find(a);
    if(it==dAddr.end()){cout<<"За цією адресою нікого немає.\n";return;}
    cout<<"За адресою \""<<a<<"\" мешкає осіб: "<<it->second.cnt<<"\n";
    for(int id:it->second.ids)cout<<"  "<<db[id].name<<", тел. "<<db[id].phone<<"\n";
}
void queryName(const string&n){
    auto it=dName.find(n);
    if(it==dName.end()){cout<<"Такої особи немає.\n";return;}
    cout<<"Знайдено записів: "<<it->second.cnt<<"\n";
    for(int id:it->second.ids)cout<<"  "<<db[id].addr<<", тел. "<<db[id].phone<<"\n";
}
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
    int c;
    do{
        cout<<"\n=== ЖРЕП (частотні словники) ===\n1. Додати запис\n2. Усі записи\n3. Частотний словник прізвищ/імен\n4. Частотний словник адрес\n5. Запит: хто мешкає за адресою (ім'я + телефон)\n6. Запит: адреси й телефони за прізвищем/ім'ям\n7. Завантажити тестові дані\n0. Вихід\n";
        c=readInt("Вибір: ");
        if(c==1){
            string n=readStr("Прізвище/ім'я: ");
            string a=readStr("Адреса: ");
            string p=readStr("Телефон: ");
            addRec(n,a,p);
            cout<<"Додано.\n";
        }else if(c==2){
            if(db.empty())cout<<"Порожньо.\n";
            for(auto&r:db)cout<<"  "<<r.name<<" | "<<r.addr<<" | "<<r.phone<<"\n";
        }else if(c==3)printDict(dName);
        else if(c==4)printDict(dAddr);
        else if(c==5)queryAddr(readStr("Адреса: "));
        else if(c==6)queryName(readStr("Прізвище/ім'я: "));
        else if(c==7){
            addRec("Іваненко Олег","вул. Руська 10","0501111111");
            addRec("Іваненко Марія","вул. Руська 10","0502222222");
            addRec("Петренко Андрій","вул. Головна 5","0673333333");
            addRec("Шевчук Ірина","вул. Руська 10","0634444444");
            addRec("Петренко Андрій","вул. Садова 1","0675555555");
            cout<<"Завантажено.\n";
        }else if(c!=0)cout<<"Невірний пункт меню.\n";
    }while(c!=0);
    return 0;
}
