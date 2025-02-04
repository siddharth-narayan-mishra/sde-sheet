#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
  
int longestConsecutive(vector<int>& a) {
    int n = a.size();
    if (n == 0)
        return 0;

    //longest to store answer
    int longest = 1;

    //unordered set for efficient retrieval of elements
    unordered_set<int> st;
    for (int i = 0; i < n; i++) {
        // st.insert 'inserts' elements into an unordered set
        st.insert(a[i]);
    }

    for (auto it : st) {
        //st.find(x) to find x in set, st.erase(x) to delete it
        if (st.find(it - 1) == st.end()) {
            int count = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x++;
                count++;
            }
            longest = max(longest, count);
        }
    }
    return longest;
}