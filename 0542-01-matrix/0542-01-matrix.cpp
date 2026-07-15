class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& v) {
        int m = v.size();
        int n = v[0].size();
        vector<vector<bool>>b(m,vector<bool>(n,false));
        vector<pair<int,int>> dir = {{1, 0},{-1, 0},{0, -1},{0, 1}};
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(v[i][j]==0)
                {
                q.push({i,j});
                b[i][j]=true;
                }
            }
        }
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(auto d: dir)
            {
                int nx=d.first+x;
                int ny=d.second+y;
                if(nx >=0 && nx < m && ny >=0 && ny < n && !b[nx][ny])
                {
                    v[nx][ny]=v[x][y]+1;
                    b[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
        }
        return v;
    }
};