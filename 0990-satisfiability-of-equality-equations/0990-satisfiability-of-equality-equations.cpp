class Solution {
public:

    vector<int> parent;
    vector<int> rank;

    int find(int u){
        if(u == parent[u])return u;

        return parent[u] = find(parent[u]);
    }

    void Union(int x, int y){
        int parent_x = find(x);
        int parent_y = find(y);
        
        if(parent_x == parent_y)return;
        
        if(rank[parent_x] > rank[parent_y]){
            parent[parent_y] = parent_x;
        }
        else if(rank[parent_y] > rank[parent_x]){
            parent[parent_x] = parent_y;
        }
        else{
            parent[parent_y] = parent_x;
            rank[parent_x]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26);
        for(int i=0;i<26;i++){
            parent[i] = i;
            rank[i] = 1;
        }

        for(auto& str : equations){
            if(str.substr(1,2) == "!=")continue;
            int x = str[0] - 'a';
            int y = str.back() - 'a';

            if(find(x) != find(y)){
                Union(x,y);
            }
        }

        for(auto& str : equations){
            if(str.substr(1,2) == "==")continue;

            int x = str[0] - 'a';
            int y = str.back() - 'a';

            if(find(x) == find(y))return false;
        }
        


        return true;
    }
};