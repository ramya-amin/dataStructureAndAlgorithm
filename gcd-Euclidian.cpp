#include<iostream>
using namespace std;

class numbers:{

public: int findGcd(int n, int m)
        {
            if(n == 0)
            return m;
            else
            return findGcd(m%n , n);
        }

};

int main(){
    numbers num;
    cout<<num.findGcd(3,4);

    return 0;
}