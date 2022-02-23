#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum(vector<int>& num, int target)
{
    map<int,int>mapping;
    vector<int> result;
    for(int i=0;i<num.size();++i)
        mapping[num[i]]=i;
    for(int i=0;i<num.size();++i)
    {
        int gap=target-num[i];
        /*
        if(mapping.find(gap)!=mapping.end())
        {
            result.push_back(i+1);
            result.push_back(mapping[gap]+1);
            break;
        }
        */
       if(mapping.count(gap) && mapping[gap]!=i)
       {
            result.push_back(i);
            result.push_back(mapping[gap]);
            break;
       }
    }
    return result;
}

int main()
{
    int a[4]={2,11,7,15};
    vector<int> arr(a,a+4);
    vector<int> index;
    int target=9;
    index=twoSum(arr,target);
    cout<<"index1= "<<index[0]<<endl<<"index2= "<<index[1]<<endl;
    return 0;
}