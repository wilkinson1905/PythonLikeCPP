#include "all.h"
#include "range.hpp"
using namespace std;

int main(){
    ios::sync_with_stdio(false); 
    int L,N;
    list<int> x;
    cin >> L;
    cin >> N;
    while(true){
        int tmp;
        cin >> tmp;
        if (cin.eof()){break;}
        x.push_back(tmp);
    }
    int pos = 0;
    int walk_length = 0;
    while(!x.empty()){
        auto l = *x.begin();
        auto r = *x.rbegin();
        auto ldistance = (l - pos < 0? l - pos + L:l-pos);
        auto rdistance = (pos - r < 0? pos  + L - r:pos - l);
        if(ldistance < rdistance){
            pos = *x.rbegin();
            x.pop_back();
            walk_length += rdistance;
        }else{
            pos = *x.begin();
            x.pop_front();
            walk_length += ldistance;
        }
        print("distance",ldistance, rdistance);
        print(x);
        print("pos",pos,"walklen",walk_length);
    }




}
