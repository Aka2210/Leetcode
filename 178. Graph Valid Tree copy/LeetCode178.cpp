#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>> &edges) {
        if(edges.size() != n - 1)
            return false;

        int root[n], rank[n];
        for(int i = 0; i < n; i++)
        {
            root[i] = i;
            rank[i] = 0;
        }

        for(int i = 0; i < n - 1; i++)
        {
            if(!Union(edges[i][0], edges[i][1], root, rank))
                return false;
        }

        return true;
    }
private:
    int find(int val, int *root)
    {
        if(root[val] != val)
            root[val] = find(root[val], root);
        return root[val];
    }

    bool Union(int a, int b, int *root, int *rank)
    {
        a = find(a, root);
        b = find(b, root);
        if(a == b)
            return false;
        
        if(rank[a] > rank[b])
            root[b] = root[a];
        else if(rank[a] < rank[b])
            root[a] = root[b];
        else
        {
            root[b] = root[a];
            rank[a]++;
        }

        return true;
    }
};