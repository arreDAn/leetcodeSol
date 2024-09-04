#include <iostream>
using namespace std;

int reverse(int x) {
    
        long ans=0;
        int rem;
        while(x!=0)
        {
            rem = x%10;
            ans = ans*10+rem;
            x=x/10;
        }
        if (ans > INT_MAX || ans < INT_MIN) {
            return 0;
        }
        return ans;
    }

int main() {
    std::cout << "Hello, World!" << std::endl;
    cout<<"Reverse 123: "<<reverse(123)<<endl;
    cout<<"Reverse -123: "<<reverse(-123)<<endl;
    cout<<"Reverse 120: "<<reverse(120);
    return 0;
}
