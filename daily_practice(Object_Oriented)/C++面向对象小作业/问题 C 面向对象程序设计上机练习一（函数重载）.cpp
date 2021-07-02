#include <iostream>
using namespace std;
int max(int a[])
{
    int i;
    int m=0;
    for(i=0; i<5; i++)
    {
        if(a[i]>m)
            m=a[i];
    }
    return m;
}
float max(float a[])
{
    int i;
    float m=0.0;
    for(i=0; i<5; i++)
    {
        if(a[i]>m)
            m=a[i];
    }
    return m;
}
long max(long a[])
{
    int i;
    long m=0;
    for(i=0; i<5; i++)
    {
        if(a[i]>m)
            m=a[i];
    }
    return m;
}
int main()
{
    int j;
    int x[5];
    float y[5];
    long z[5];
    for(j=0; j<5; j++)
        cin >> x[j];
    for(j=0; j<5; j++)
        cin >> y[j];
    for(j=0; j<5; j++)
        cin >> z[j];
    int e;
    e=max(x);
    cout << e << endl;
    float f;
    f=max(y);
    cout << f << endl;
    long g;
    g=max(z);
    cout << g << endl;
    return 0;
}
