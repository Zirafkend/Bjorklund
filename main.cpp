#include <iostream>
#include "Bjorklund.h"


template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& va)
{
    for(std::size_t i = 0; i < va.size(); ++i) { out << va[i] << ' '; }
    return out;
}

template <typename T>
std::vector<T> shift(std::vector<T>& v, size_t idx){
    std::vector<T> result = v;
    std::rotate(result.begin(),result.begin()+idx,result.end());
    return result;
}


using namespace std;
auto pressets = init_euclidean_pressets();


int main() {

    auto kick = bjorklund(16, 4);
    // the basic 4 to the floor kick in a 16 step
    cout << kick << endl;
    //1 0 0 0 1 0 0 0 1 0 0 0 1 0 0 0

    auto hh = shift(kick, 2);
    //0 0 1 0 0 0 1 0 0 0 1 0 0 0 1 0
    cout << hh << endl;


    cout<< pressets["afro"] << endl;
    //1 0 1

    cout<< pressets["sangha"] << endl;
    //1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0


    return 0;
}