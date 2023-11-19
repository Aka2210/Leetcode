#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>> &edges) {
        int root[n], height[n];
        for(int i = 0; i < n; i++)
        {
            height[i] = 1;
            root[i] = i;
        }

        for(int i = 0; i < edges.size(); i++)
        {
            if(Union(edges[i][0], edges[i][1], root, height)) //偵測兩點是否連通，若否則n--並將其連通
                n--;
        }

        return n;
    }

private:
    int find(int val, int *root)
    {
        if(root[val] != val)
            root[val] = find(root[val], root); //查找val的根節點並壓縮
        return root[val];
    }

    bool Union(int a, int b, int *root, int *height)
    {
        a = find(a, root);
        b = find(b, root);

        if(a == b)
            return false;
        
        if(height[a] >= height[b])
        {
            height[a] += height[b];
            root[b] = a;
        }
        else
        {
            height[b] += height[a];
            root[a] = b;
        }

        return true;
    }
};