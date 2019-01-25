//九九サンプル
#include "all.h"
#include "range.hpp"
using namespace std;
int main(){
    for(auto i: range(1,10)){
        vector<int> v;
        for(auto j:range(1,10)){
            v.push_back(i*j);
        }
        print(v);
    }
}