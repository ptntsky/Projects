#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <limits>
using namespace std;
// Мережа: вершини — особи та адреси, ребро особа—адреса несе номер телефону
struct Edge{int to;string phone;};
struct Vertex{string label;bool person;vector<Edge> adj;};
vector<Vertex> g;
map<string,int> pIdx,aIdx;
int getV(map<string,int>&m,const string&l,bool person){
    auto it=m.find(l);
    if(it!=m.end())return it->second;
    g.push_back({l,person,{}});
    return m[l]=g.size()-1;
}
bool addRec(const string&n,const string&a,const string&p){
    int u=getV(pIdx,n,true);
    int v=getV(aIdx,a,false);
    for(auto&e:g[u].adj)if(e.to==v&&e.phone==p)return false;
    g[u].adj.push_back({v,p});
    g[v].adj.push_back({u,p});
    return true;
}
// пошук у ширину від початкової вершини; результат — вершини на відстані 1
int search(int s){
    vector<int> d(g.size(),-1);
    queue<int> q;
    q.push(s);
    d[s]=0;
    int cnt=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(d[u]>=1)continue;
        for(auto&e:g[u].adj){
            if(d[e.to]==-1){d[e.to]=d[u]+1;q.push(e.to);}
            cout<<"  "<<g[e.to].label<<", тел. "<<e.phone<<"\n";
            cnt++;
        }
    }
    return cnt;
}
void queryPerson(const string&n){
    auto it=pIdx.find(n);
    if(it==pIdx.end()){cout<<"Такої особи немає.\n";return;}
    cout<<"Адреси особи \""<<n<<"\":\n";
    int c=search(it->second);
    cout<<"Кількість: "<<c<<"\n";
}
void queryAddr(const string&a){
    auto it=aIdx.find(a);
    if(it==aIdx.end()){cout<<"Такої адреси немає.\n";return;}
    cout<<"Особи за адресою \""<<a<<"\":\n";
    int c=search(it->second);
    cout<<"Кількість: "<<c<<"\n";
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
        cout<<"\n=== ЖРЕП (пошук у мережі) ===\n1. Додати запис\n2. Показати мережу\n3. Запит: адреса й телефон за прізвищем/ім'ям\n4. Запит: особи й телефони за адресою\n5. Завантажити тестові дані\n0. Вихід\n";
        c=readInt("Вибір: ");
        if(c==1){
            string n=readStr("Прізвище/ім'я: ");
            string a=readStr("Адреса: ");
            string p=readStr("Телефон: ");
            cout<<(addRec(n,a,p)?"Додано.\n":"Такий запис уже є.\n");
        }else if(c==2){
            if(g.empty())cout<<"Мережа порожня.\n";
            for(auto&v:g){
                if(!v.person)continue;
                cout<<v.label<<"\n";
                for(auto&e:v.adj)cout<<"   -> "<<g[e.to].label<<" ["<<e.phone<<"]\n";
            }
        }else if(c==3)queryPerson(readStr("Прізвище/ім'я: "));
        else if(c==4)queryAddr(readStr("Адреса: "));
        else if(c==5){
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
