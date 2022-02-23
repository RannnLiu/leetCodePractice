#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

//begin函数：函数原型:  iterator begin();   const_iterator begin();
//功能：返回一个指向当前vector容器中起始元素的迭代器。

//end函数：函数原型：iterator end();  const_iterator end();
//功能：返回一个指向当前vector容器中末尾元素的迭代器。

//front函数：函数原型：reference front();  const_reference front();
//功能：返回当前vector容器中起始元素的引用。

//back函数：函数原型：reference back();   const_reference back();
//功能：返回当前vector容器中末尾元素的引用。

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        unordered_set<string> st;
        if(n == 0) st.insert("");
        else{
            vector<string> pre = generateParenthesis(n - 1);
            for(auto a : pre){
                for(int i = 0; i < a.size(); ++i){
                    if(a[i] == '('){
                        a.insert(a.begin() + i + 1, '(');
                        a.insert(a.begin() + i + 2, ')');
                        st.insert(a);
                        a.erase(a.begin() + i + 1, a.begin() + i + 3);
                    }
                }
                st.insert("()" + a);
            }
        }
        return vector<string>(st.begin(), st.end());
    }
};

int main()
{
    int n;
    cin >> n;
    Solution S;
    vector<string> ans;
    ans = S.generateParenthesis(n);
    for(int i = 0; i < ans.size(); i++){
        cout << ans.at(i) << " ";
    }
    cout << endl;
    
    return 0;
}