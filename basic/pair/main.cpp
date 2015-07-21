#include<bits/stdc++.h>
using namespace std;
bool comp()
{
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        int n,f;
        cin>>n;
            vector< pair<int,int> > v;
            for(int i=0;i<n;i++)
                {
                    cin>>f;
                    v.push_back(make_pair(f,i));
                }
                sort(a.begin(), a.end(),std::bind(&std::pair<int, int>::second, _1) <std::bind(&std::pair<int, int>::second, _2));
            sort(v.begin(),v.end());
            //for(int i=0;i<v.size();i++)
                //cout<<v[i].first<<" "<<v[i].second<<"\n";
                int x=0;
                int y=n-1;
            for(int i=0;i<n;i++)
            {
                if((v[x].first+v[y].first)>k)y--;
                else if((v[x].first+v[y].first)<k)x++;
                else
                {
                    cout<<v[x].second+1<<" "<<v[y].second+1<<"\n";
                    break;
                }
            }
    }
return 0;
}
