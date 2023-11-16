#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(), root[n + 1];
        vector<int> result;

        for(int i = 1; i < n + 1; i++)
            root[i] = i;

        for(int i = 0; i < n; i++)
        {
            int A = find(root, edges[i][0]), B = find(root, edges[i][1]); //找出此edge關聯的兩個node的根節點
            if(A == B) //根節點相同代表此edge造成circle，直接回傳
                return {edges[i][0], edges[i][1]};
            else //根節點不同代表此edge不造成circle，使其連線
                root[B] = A;
        }

        return result;
    }

private:
    int find(int *root, int A) //找A的根節點並同時做壓縮
    {
        if(root[A] != A)
            root[A] = find(root, root[A]);
        return root[A];
    }   
};