#include<iostream>
#include<math.h>
using namespace std;

//#define INT_MAX pow(2,31)-1

class Solution{
    public:
    int reverse(int x){
        int result=0;
        while(x!=0){
            if(abs(result) >= (pow(2,31)-1)/10) return 0;
            result = result*10 + x%10;
            x /= 10; 
        }
        return result;
    }
};

int main()
{
    int x;
    cout<<"enter a number:"<<endl;
    cin>>x;
    Solution s;
    int result = s.reverse(x);
    cout<<result;
    return 0;
}