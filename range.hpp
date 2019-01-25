// range(n) ===> vector<int> [0,1,2, ... , n-1]
// range(s,e) ===> vector<int> [s, s+1, s+2, ... ,e]
// print()    ==> print "\n"
//print(1, 0.5, "string") ===> print "1, 0.5, string, \n"
//print(vector) ===> print "[v1, v2, v3, ... vend,]"

#include <iostream>
using namespace std;


template <typename T>
void print(vector<T> v){
    cout << "[ ";
    for(auto i: v){
        cout << i << ", ";
    }
    cout << "]" <<endl;
}

void print() {
    std::cout << endl;
}

// ひとつ以上のパラメータを受け取るようにし、
// 可変引数を先頭とそれ以外に分割する
template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail)
{
  std::cout << head << ", ";

  // パラメータパックtailをさらにheadとtailに分割する
  print(std::forward<Tail>(tail)...);
}
auto range(int start, int end){
    vector<int> v(end - start);
    iota(v.begin(), v.end(), start);
    return v;
}

auto range(int start, int end, int step){
    vector<int> v;
    if(step == 0){return v;}
    if(step > 0 && start > end){return v;}
    if(step < 0 && start < end ){return v;}
    if(step > 0){
        for(int i = start; i < end; i += step){
            v.push_back(i);
        }
    }else{
        for(int i = start; end < i; i += step){
            v.push_back(i);
        }
    }
    return v;
}

auto range(int num){
    vector<int> v(num);
    iota(v.begin(), v.end(), 0);
    return v;
}