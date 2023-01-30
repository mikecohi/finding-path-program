#include <bits/stdc++.h>
#include <graphics.h>
using namespace std;
const int radius = 20;
struct Vertex
    {
        int x;
        int y;
        char *name;
    };
char* tochars(int number){
    stringstream strs;
    strs << number;
    string temp_str = strs.str();
    char* char_type = (char*) temp_str.c_str();
    return char_type;
}
void drawVertex(int x, int y, char* name){
    circle(x+10,y+10,radius);
    outtextxy(x+10-radius,y+10+radius+2, name);
}
void highlightEdge(Vertex v1, Vertex v2){
    setcolor(BLUE);
    line(v1.x+10,v1.y+10,v2.x+10,v2.y+10);
    setcolor(BLACK);
}
void drawEdge(Vertex v1, Vertex v2,char* cost){
    line(v1.x+10,v1.y+10,v2.x+10,v2.y+10);
    // setcolor(BLACK);
    outtextxy((v1.x+v2.x)/2+10,(v1.y+v2.y)/2-6, cost);
}
void drawxyAxis(){
    int x = getmaxx();
    int y = getmaxy();
    setcolor(BLACK);
    line(10,10,x,10);
    line(10,10,10,y);
    outtextxy(12,12,"0");
    outtextxy(110,12,"100");
    outtextxy(210,12,"200");
    outtextxy(310,12,"300");
    outtextxy(410,12,"400");
    outtextxy(510,12,"500");
    outtextxy(610,12,"600");
    outtextxy(710,12,"700");
    outtextxy(810,12,"800");
    outtextxy(12,110,"100");
    outtextxy(12,210,"200");
    outtextxy(12,310,"300");
    outtextxy(12,410,"400");
    outtextxy(12,510,"500");
    outtextxy(12,610,"600");
}
const int maxn = 100001;
const int INF = 1e9;
using ll = long long;
// template <typename T>
class Graph
{
public: 
    
        
protected:
    vector<Vertex> vList;
    vector<pair<int,int>> adj[maxn];
    int numberofVertex;
    int numberofEdge;

public:
    Graph()
    {
        numberofEdge = 0;
        numberofVertex = 0;
        setbkcolor(WHITE);
        cleardevice();
        setcolor(BLACK);
        drawxyAxis();
    }
    ~Graph() = default;
    void addVertex(int x, int y, char* name)
    {
        Vertex temp = {x,y,name};
        vList.push_back(temp);
        numberofVertex++;
        drawVertex(x,y,name);
        delay(1000);
    }
    int getVertex(char* name){
        char* temp;
        for (int i = 0;i< numberofVertex;i++){
            temp = vList[i].name;
            if (temp == name ) return i;
        }
        
        return -1;
    }
    char* getCost(int index1,int index2){
        for (auto x : adj[index1]){
            if (x.first == index2) return tochars(x.second);
        }
    }
    void addEdge(char* name1, char* name2, char* cost)
    {   
        int intcost = stoi(cost);
        int index1 = getVertex(name1);
        int index2 = getVertex(name2);
        // cout << intcost << " " << index1 << " " << index2 << endl;
        adj[index1].push_back({index2, intcost});
        // adj[index2].push_back({index1, intcost});
        drawEdge(vList[index1],vList[index2],cost);
        delay(1000);
    }
    void shortestWay(int s, int t)
    {
        int previous[maxn];
        vector<long long> d(numberofVertex + 1, INF);//vector luu khoang cách ngắn nhất
        d[s] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
        Q.push({0, s});
        while (!Q.empty())
        {
            pair<int, int> top = Q.top();
            Q.pop();
            int u = top.second;
            int length = top.first;
            if (length > d[u])
                continue;
            for (auto it : adj[u])
            {
                int v = it.first;
                int w = it.second;
                if (d[v] > d[u] + w)
                {
                    d[v] = d[u] + w;
                    Q.push({d[v], v});
                    previous[v] = u;
                }
            }
        }
        // for (int i = s; i <= n; i++)
        // {
        //     cout << d[i] << " ";
        // }
        // cout << "Shortest distance : " << d[t] << endl;
        vector<int> path;
        while (1)
        {
            path.push_back(t);
            if (t == s)
                break;
            t = previous[t];
        }
        reverse(path.begin(), path.end());
        
        for (int i = 0;i< path.size()-1;i++){
            highlightEdge(vList[i],vList[i+1]);
            // cout << getCost(i,i+1);
            delay(1000);
        }
        // for (auto x : path)
        // {
        //     cout << x << " ";
        // }
        cout << endl;
    }
    void printList(){
        for (int i = 0; i < numberofVertex;i++){
            cout << i << ":" << " ";
            for (auto x : adj[i]){
                cout << "{" << x.first << "," << x.second << "}, ";
            }
            cout << endl;
        }
    }
    // void illustrateGraph()
    // {
    // }
};
int main()
{
    initwindow(900,700,"Visualization");
    Graph graph1;

    graph1.addVertex(100,100,"HaNoi");
    graph1.addVertex(200,200,"ThaiBinh");
    graph1.addVertex(400,200,"HaiPhong");
    graph1.addVertex(330,100,"ThanhHoa");
    graph1.addEdge("HaNoi","ThaiBinh","141");
    graph1.addEdge("HaiPhong","ThaiBinh","200");
    graph1.addEdge("HaNoi","HaiPhong","550");
    graph1.addEdge("HaNoi","ThanhHoa","230");
    graph1.addEdge("HaiPhong","ThanhHoa","200");
    // int x,y;
    // char* s = "Camau" ; 
    // cin >> x >> y;
    // cin >> s;
    // graph1.addVertex(x,y,s);
    cout << tochars(902);
    // graph1.addEdge("ThaiBinh","ThanhHoa","500");
    // cout << graph1.getVertex("HaNoi") << endl;
    // cout << graph1.getVertex("ThanhHoa");
    // graph1.printList();
    graph1.addVertex(600,600,"VanDon");
    graph1.addEdge("ThaiBinh", "VanDon", "300");
    graph1.addVertex(642,240,"ThaiNguyen");
    graph1.addEdge("ThaiNguyen", "VanDon", "230");
    graph1.shortestWay(0,2);
    getch();
    closegraph();
    // throw("Success");
    return 0;
}
