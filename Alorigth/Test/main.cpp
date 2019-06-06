#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <iterator>
using namespace std;

const int maxn = 50000+10;

typedef pair<int,int> ii;
int n;
int dd[10];
int d[maxn];
bool inqueue[maxn];
int trace[maxn];
string arr[maxn];
vector<ii> ts[maxn];
map<long long, int> tele;

int find_tele(long long x){
    if (tele.find(x)!=tele.end()) return tele.find(x)->second;
    return -1;
}
long long pow(int x, int y){
    long long res = 1;
    for(int i=0;i<y;i++) res*=(long long)x;
    return res;
}

void change_one_number(long long x,int position){
    //cout << x << " " << position << endl;
    int pos[10];
    long long _x = x;
    for(int i=9;i>=0;i--){
        int c = _x % 10;
        _x /= 10;
        pos[i] = c;
    }
    for(int i=0;i<10;i++){
        //cout << pos[i]<< endl;
        for(int j=1;j<pos[i];j++){
            long long tmp = x - pow(10,9-i)*(long long)(pos[i]-j);

            int x_change = find_tele(tmp);
            if (x_change== -1) continue;
          //  cout << position << " " << x_change << endl;
            ts[position].push_back(ii(dd[i],x_change));
            ts[x_change].push_back(ii(dd[i],position));
        }
        //cout << "bigger" << endl;
        for(int j=pos[i]+1;j<10;j++){
            long long tmp = x + pow(10,9-i)*(long long)(j-pos[i]);

            int x_change = find_tele(tmp);
            if (x_change== -1) continue;
          //  cout << position << " " << x_change << endl;
            ts[position].push_back(ii(dd[i],x_change));
            ts[x_change].push_back(ii(dd[i],position));
        }
        //cout << "smaller" << endl;
    }
}

void change_two_number(long long x,int position){
    // cout << x << " " << position << endl;
    int pos[10];
    long long _x = x;
    for(int i=9;i>=0;i--){
        int c = _x % 10;
        _x /= 10;
        pos[i] = c;
    }
    for(int i=0;i<10;i++){
        for(int j=i+1;j<10;j++){
            if (pos[i] == pos[j]) continue;
            long long tmp = x;
            if (pos[i] < pos[j]){
                tmp += pow(10,9-i)*(pos[j]-pos[i]);
                tmp -= pow(10,9-j)*(pos[j]-pos[i]);
            }else{
                tmp -= pow(10,9-i)*(pos[i]-pos[j]);
                tmp += pow(10,9-j)*(pos[i]-pos[j]);
            }
            int x_change = find_tele(tmp);
            if (x_change == -1) continue;
           // cout << position << " " << x_change << endl;
            ts[position].push_back(ii(dd[i],x_change));
            ts[x_change].push_back(ii(dd[i],position));
        }
    }
}

void init(){
    for(auto i : tele){
        change_one_number(i.first,i.second);
        change_two_number(i.first,i.second);
    }
}

void bellman(int u){
    int i, v, uv;
    queue<int> qu;
    for(int i=0;i<=n;i++) trace[i] = i;
    for (i=0; i<=n; i++) d[i]=1000111000;
    d[u]=0;
    qu.push(u); inqueue[u]=true;

    while (qu.size()){
        u=qu.front(); inqueue[u]=false;
        qu.pop();

        for (i=0; v=ts[u][i].second; i++){
            uv=ts[u][i].first;
            if (d[v]>d[u]+uv){
                d[v]=d[u]+uv;
                trace[v] = u;
                if (!inqueue[v]){
                    qu.push(v);
                    inqueue[v]=true;
                }
            }
        }
    }
}
void try_trace(){
    int tr[maxn];
    int sl = 0;
    int x = n;
    while (x!= 1){
        tr[sl] = x;
        sl++;
        x = trace[x];
    }
    tr[sl] = 1;
    cout << ++sl << endl;
    for(int i=sl-1;i>=0;i--){
        cout << tr[i] << " ";
    }
}
int main(){
    cin >> n;
    for(int i=0;i<10;i++) cin >> dd[i];
    long long tmp;
    for(int i=1;i<=n;i++){
        cin >> tmp;
        tele.insert(pair<long long,int>(tmp,i));
    }
    init();

    for (int i=1; i<=n; i++) ts[i].push_back(ii(0,0));
    bellman(1);

    if (d[n] !=1000111000) {
        cout << d[n] << endl;
        try_trace();
    }    else cout << -1;
}
