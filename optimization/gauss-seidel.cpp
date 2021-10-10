#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
#define int long long
const int N = 1e3 + 10;
double A[N][N], B[N], X[N];
int n;
void jacobi()
{
    int k = N;
    while (k--)
    {
        double X2[N];
        for (int i = 0; i < n; i++)
        {
            double cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (j == i)
                    continue;
                else
                    cnt += A[i][j] * X[j];
            }
            X2[i] = (B[i] - cnt) / A[i][i];
        }
        for(int i= 0; i < n; i++) X[i]=X2[i];
    }
    for (int i = 0; i < n; i++)
        printf("X[%d]=%lf%c", i + 1, X2[i], i == n - 1 ? '\n' : ' ');
}

signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    for (int i = 0; i < n; i++)
        cin >> B[i];
    jacobi();
    return 0;
}

