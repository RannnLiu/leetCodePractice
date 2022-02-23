#include <iostream>
#include <vector>
using namespace std;

//从末尾开始加
//循环结束后，有可能i或者j还大于等于0，
//若j大于0，那么还需要继续循环，将 nums2 中的数字继续拷入 nums1。
//若是i大于等于0，那么就不用管，因为混合数组本身就放在 nums1 中
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]) nums1[k--] = nums1[i--];
            else nums1[k--] = nums2[j--];
        }
        while(j >= 0) nums1[k--] = nums2[j--];
    }
};

int main()
{
    int m, n;
    cout << "m = ";
    cin >> m;
    cout << "n = ";
    cin >> n;
    
    cout << "type in the 1st array: ";
    vector<int> list1;
    int temp1;
    do{
        cin >> temp1;
        list1.insert(list1.end(), temp1);
    }while(getchar()!='\n');
    
    cout << "type in the 2nd array: ";
    vector<int> list2;
    int temp2;
    do{
        cin >> temp2;
        list2.insert(list2.end(), temp2);
    }while(getchar()!='\n'); 
    
    Solution S;
    S.merge(list1, m, list2, n);
    for(int i = 0; i < list1.size(); i++){
        cout << list1.at(i) << " ";
    }
    cout << endl;
    return 0;
}