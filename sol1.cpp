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
class board : public table
{
    public:
    void die_cutting(table &p,string dir,int x,int y);
};

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    board a;
    a.import_table();
    table b;
    b.import_table();
    a.die_cutting(b,"left",1,2);
    a.print_table();
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
    return a[y][x];
}
void board::die_cutting(table &p,string dir,int x,int y)
{
    int p_size = p.height();
    if(dir == "left")
    {
        for(int i = y;i < y + p_size;++i)
        {
            int cnt = 0;
            vector<int> temp1;
            for(int j = x;j < x + p_size;++j)
            {
                int p_x = j - x;
                int p_y = i - y;
                //cout << i << " " << j << " " << p_x << " " << p_y << " " << p.get(p_x,p_y) << '\n';
                //cout << p_x << " " << p_y << " " << p.get(p_x,p_y) << '\n';

                if(p.get(p_x,p_y) == 0)
                {
                    a[i][j - cnt] = a[i][j];
                }
                else
                {
                    temp1.push_back(a[i][j]);
                    ++cnt;
                }
            }
            for(int j = x + p_size ;j < n;++j)
            {
                a[i][j - cnt] = a[i][j];
            }
            int sz = temp1.size();
            for(int j = 0;j < cnt;++j)
            {
                a[i][n - 1 - j] = temp1[sz - 1 - j];
            }
        }
    }
    if(dir == "right")
    {
        for(int i = y;i < y + p_size;++i)
        {
            int cnt = 0;
            vector<int> temp1;
            for(int j = x + p_size - 1;j >= x;--j)
            {
                int p_x = j - x;
                int p_y = i - y;
                if(p.get(p_x,p_y) == 0)
                {
                    a[i][j + cnt] = a[i][j];
                }
                else
                {
                    temp1.push_back(a[i][j]);
                    ++cnt;
                }
            }
            for(int j = x - 1;j >= 0;--j)
            {
                a[i][j + cnt] = a[i][j];
            }
            int sz = temp1.size();
            for(int j = 0;j < cnt;++j)
            {
                a[i][j] = temp1[sz - 1 - j];
            }
        }
    }
    if(dir == "up")
    {
        for(int i = x;i < x + p_size;++i)
        {
            int cnt = 0;
            vector<int> temp1;
            for(int j = y;j < y + p_size;++j)
            {
                int p_x = i - x;
                int p_y = j - y;
                if(p.get(p_x,p_y) == 0)
                {
                    a[i - cnt][j] = a[i][j];
                }
                else
                {
                    temp1.push_back(a[i][j]);
                    ++cnt;
                }
            }
            for(int j = y + p_size;j < n;++j)
            {
                a[i - cnt][j] = a[i][j];
            }
            int sz = temp1.size();
            for(int j = 0;j < cnt;++j)
            {
                a[i][n - 1 - j] = temp1[sz - 1 - j];
            }
        }
    }
    if(dir == "down")
    {
        for(int i = x;i < x + p_size;++i)
        {
            int cnt = 0;
            vector<int> temp1;
            for(int j = y;j < y + p_size;++j)
            {
                int p_x = i - x;
                int p_y = j - y;
                if(p.get(p_x,p_y) == 0)
                {
                    a[i + cnt][j] = a[i][j];
                }
                else
                {
                    temp1.push_back(a[i][j]);
                    ++cnt;
                }
            }
            for(int j = y + p_size;j < n;++j)
            {
                a[i + cnt][j] = a[i][j];
            }
            int sz = temp1.size();
            for(int j = 0;j < cnt;++j)
            {
                a[i][n - 1 - j] = temp1[sz - 1 - j];
            }
        }
    }
}