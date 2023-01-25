#include <bits/stdc++.h>
#include "draw.h"
//#include "agorithm.h"
using namespace std;

const int maxn = 1000;

class Graph {

protected :

    vector<Vertex> vList;
    vector<pair<int,pair<int,string>>> adj[maxn]; // cạnh kề, (tên,kc)
    int numberofVertex;
    int numberofEdge;
public :
    Graph(){
        numberofEdge = 0;
        numberofVertex = 0;    
        initwindow(900,700,"Visualization"); // khởi tạo cửa sổ
        setbkcolor(WHITE); // set backgroundcolor là white
        cleardevice();
        setcolor(BLACK); // đổi màu để vẽ thành màu đen
        drawxyAxis(); // vẽ trục tọa độ
    }
    ~Graph() = default;
    void addVertex(int x, int y, string placeName){ //đỉnh: tọa độ x, y, tên điểm
        // Thêm vertex đấy vào trong vector để lưu
        Vertex temp = {x,y,placeName};
        vList.push_back(temp);
        // B2 : vẽ lên màn hình
        drawVertex(x,y,stringToChars(placeName));
    }
    void addOneWayEdge(string name1, string name2,string streetName, string cost){ 
    // đường 1 chiều: điểm đầu, điểm cuối, tên đường, khoảng cách
    //    Thêm đường đấy vào trong danh sách kề array adj.
       int intCost = stoi(cost);
       int index1 = getVertex(name1);
       int index2 = getVertex(name2);
    //    adj[index1] : là 1 cái vector chứa các thông tin của các đỉnh kề với đỉnh index1  dưới dạng {index của đỉnh,{khoảng cách, tên đường}};
       adj[index1].push_back({index2,{intCost,streetName}});
    //    Vẽ lên màn hình
       drawOneWayEdge(vList[index1],vList[index2],stringToChars(cost));
    }
    void addTwoWayEdge(string name1, string name2,string streetName, string cost){
    //đường 2 chiều: điểm đầu, điểm cuối, tên đường, khoảng cách
        cout << "Add two-way edge" << endl;
    }
    void removeEdge(string streetName){
        cout << "Remove Edge" << endl; // xóa đường
    }
    void removeVertex(string placeName){
        cout << "Remove Vertex" << endl; // xóa đỉnh
    }
    void removeAll() {
        cout << "Remove All" << endl;
    };
    vector<int> getShortestWay(string name1, string name2){
        vector<int> temp;
        temp.push_back(1);
    };
    void highlightWay(vector<int> path){
        cout << "Highlight Way" << endl;
    }
    void unhighlightWay(vector<int> path){
        cout << "Un-highlight Way" << endl;
    }
    void dfs(); // Minh 
    void printList(){
    for (int i = 0; i < numberofVertex;i++){
            cout<< vList[i].name << ":" << " ";
            for (auto x : adj[i]){
                cout << "{" << vList[x.first].name  << ",{" << x.second.first << ","<< x.second.second << "},";
            }
            cout << endl;
        } 
    }
    int getVertex(string name){
        for(int i=0;i< numberofVertex;i++){
            
            if (vList[i].name == name) return i;
            
            }
        return -1;
    }

    int getCost(string name1, string name2);
    pair<int,int> getEdge(string name){
        for(int i=0;i <numberofVertex;i++){
            for(auto x:adj[i]){
                if(x.second.second==name) return{i,x.first};
            }
        }
    }
    
};

// Mai
class Menu{

private:
    Graph graph1;
public:
    void AddPlace() {
        
        int x,y;
        string name;
        system("cls");
        cout << "=== ADD PLACE ===" << endl;
        cout << "Codinates: ";
        cin >> x >> y;
        cout << "Name: ";
        fflush(stdin);
        getline(cin,name);
        graph1.addVertex(x,y,name);
        system("pause");
    };
    void AddWay() {
        int option;
        string s1,s2,name,distance;
        do {
            cout << "=== ADD WAY ===" << endl;
            cout << "1. Add two-way street" << endl;
            cout << "2. Add one-way street" << endl;
            cout << "0. Back" << endl;
            cin >> option;
            system("cls");
            switch (option) 
            {
            case 1:
                cout << "=== ADD TWO-WAY STREET ===" << endl;
                cout << "Way between 2 place" << endl;
                cout << "from: ";
                fflush(stdin);
                getline(cin,s1);
                cout << "to: "; 
                fflush(stdin);
                getline(cin,s2);
                cout << "Name of the way: ";
                fflush(stdin);
                getline(cin,name);
                cout << "Distance: ";
                cin >> distance;
                graph1.addTwoWayEdge(s1,s2,name,distance);
                system("pause");
                break;
            case 2:
                cout << "=== ADD ONE-WAY STREET ==="<< endl;
                cout << "Way between 2 place" << endl;
                cout << "from: ";
                fflush(stdin);
                getline(cin,s1);
                cout << "to: "; 
                fflush(stdin);
                getline(cin,s2);
                cout << "Name of the way: ";
                fflush(stdin);
                getline(cin,name);
                cout << "Distance: ";
                cin >> distance;
                graph1.addOneWayEdge(s1,s2,name,distance);
                system("pause");
                break;
            default:
                break;
            }
        } while (option!=0);
        
    };
    void Remove() {
        string p,w;
        int option;
        do {
            cout << "=== REMOVE ===" << endl;
            cout << "1. Revome a place" << endl;
            cout << "2. Remove a way" << endl;
            cout << "3. Remove all" << endl;
            cout << "0. Back" << endl;
            cin >> option;
            system("cls");
            switch (option)
            {
            case 1:
                cout << "=== REMOVE A PLACE ===" << endl;
                cout << "Enter place: ";
                fflush(stdin);
                getline(cin,p);
                graph1.removeVertex(p);
                system("pause");
                break;
            case 2: 
                cout << "=== REMOVE A WAY ===" << endl;
                cout << "Enter name of the way: ";
                fflush(stdin);
                getline(cin,w);
                graph1.removeEdge(w);
                system("pause");
                break;
            case 3:
                cout << "=== REMOVE ALL ===" << endl;
                graph1.removeAll();
                break;
            default:
                break;
            }
        } while (option!=0);
    };
    void Edit() {
        string w,p,place;
        int way,option;
        do {
            cout << "=== EDIT INFO ===" << endl;
            cout << "1. Edit name of a place";
            cout << "2. Edit distance of a way";
            cout << "0. Back";
            cin >> option;
            switch(option) 
            {
                case 1: 
                    cout << "Edit name of a place: ";
                    getline(cin, p);
                    //place.getVertex(p);
                    break;
                case 2:
                    cout << " Edit distance of a way";
                    break;
                default: 
                break;
            }
        } while (option!=0);
    };
    void Hightlight() {
        // fflush(stdin);
        string begin, end;
        cout << "=== FIND SHORTEST WAY ===" << endl;
        cout << "from: "; getline(cin, begin); fflush(stdin);
        cout << " to: ";
        getline(cin, end);

        vector<int> path = graph1.getShortestWay(begin,end);
        graph1.highlightWay(path);
        system("pause");
        graph1.unhighlightWay(path);       
    };
};

int main(){
    int option;
    Menu menu1;
    do {
        system("cls");
        cout << "==== MAPS ====" << endl;
        cout << "1. Add place" << endl;
        cout << "2. Add way" << endl;
        cout << "3. Remove" << endl;
        cout << "4. Edit info" << endl;
        cout << "5. Highlight" << endl;
        cout << "0. Exit" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            menu1.AddPlace();
            break;
        case 2:
            menu1.AddWay();
            break;
        case 3:
            menu1.Remove();
            break;
        case 4:
            menu1.Edit();
            break;
        case 5:
            menu1.Hightlight();
            break;
        default:
            break;
        }
    } while (option!=0);
    // Graph graph1;
    // graph1.addVertex(200,200,"DHBK");
    // graph1.addVertex(400,400,"DHKTQD");
    // graph1
    // graph1.addOneWayEdge("DHBK","DHKTQD","TDN","500");
    // getch();
    // closegraph();
    return 0;
}