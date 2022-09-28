#include <iostream>
#include <vector>
const int maxdist = 9999;
using namespace std;
/*n���ܵĽ����,v�ǳ������,dist�Ǿ���,preǰһ�����,d�ǽ����Ȩֵ*/
void Dijkstra(int n, int v, vector<int> &dist, vector<int> &pre, vector<vector<int>> &d)
{
    vector<bool> s(n+1);
    for (int i = 1; i <= n;i++)
    {
        dist[i] = d[v][i];
        if (dist[i] < maxdist)
            pre[i] = v;
        else
            pre[i] = 0;
    }
    dist[v] = 0;
    s[v] = true;
    for (int i = 2; i <= n;i++)//�ܵĵ�������
    {
        int best = v;
        int temp = maxdist;
        for (int j = 1; j <= n;j++)//�ҵ���С�ľ���
        {
            if (!s[j]&&dist[j]<temp)
            {
                temp = dist[j];
                best = j;
            }
        }
        s[best] = true;
        for (int j = 1; j <= n;j++)//����dist��pre
        {
            if (!s[j] && d[best][j] != maxdist)
            {
                int newdist = dist[best] + d[best][j];
                if (newdist<dist[j])
                {
                    dist[j] = newdist;
                    pre[j] = best;
                }
            }
        }       
    }
}

void printpath(vector<int> pre, int init, int fina)
{
    int temp=fina;
    vector<int> t;
    while (temp != init)
    {
        t.push_back(temp);
        temp = pre[fina];
        fina = temp;
    }
    cout << init << "->";
    for (int i = t.size(); i >1;i--)
    {
        cout << t[i-1] << "->";
    }
    cout << t[0];
    t.clear();
}
int main()
{
    int n, l;
    cout << "������������������";
    cin >> n >> l;
    vector<vector<int>> d(n+1, vector<int>(n+1));
    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= n; j++)
            d[i][j] = maxdist;
    }
    int p, q, len;
    for (int i = 1; i <= l; ++i)
    {
        cin >> p >> q >> len;
        if (len < d[p][q])       // ���ر�
        {
            d[p][q] = len;      // pָ��q
            d[q][p] = len;      // qָ��p��������ʾ����ͼ
        }
    }
    vector<int> dist(n+1),pre(n+1);
    for (int i = 1; i <= n; ++i)
        dist[i] = maxdist;
    Dijkstra(n, 1, dist, pre, d);
    cout << "��1����n�����·������: " << dist[n] << endl;
    cout << "��1����n��·��Ϊ: ";
    printpath(pre, 1, n);
    return 0;
}
