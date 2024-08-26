#include<bits/stdc++.h>
using namespace std;
class table
{
    public:
    void import_table();
    void print_table();
    int height();
    int width();
    int get(int x,int y);
    protected:
    int m, n;
    int **a;
};
class board : protected table
{
    public:
    void die_cutting(table &p,string dir,int x,int y);
};
int main()
{
    return 0;
}

void table::import_table()
{
    cin >> m >> n;
    a = new int*[m];
    for(int i = 0;i < m;++i)
    {
        a[i] = new int[n];
    }
    for(int i = 0;i < m;++i)
    {
        for(int j = 0;j < n;++j)
        {
            cin >> a[i][j];
        }
    }
}
void table::print_table()
{
    for(int i = 0;i < m;++i)
    {
        for(int j = 0;j < n;++j)
        {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
}
int table::height()
{
    return m;
}
int table::width()
{
    return n;
}
int table::get(int x,int y)
{
    return a[x][y];
}
void board::die_cutting(table &p,string dir,int x,int y)
{
    int p_size = p.height();
        vector<vector<int>> temp(p_size);
        for(int i = x;i <= x + p_size - 1;++i)
        {
            for(int j = y;j <= y + p_size - 1;++j)
            {
                int p_x = i - x;
                int p_y = j - y;
                if(p.get(p_x,p_y) == 1)
                {
                    temp[i].push_back(a[i][j]);
                }
            }
        }
    if(dir == "left")
    {
        
    }
}