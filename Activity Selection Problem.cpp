#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of activities:";
    cin>>n;

    vector<pair<int,int>> act(n);
    cout<<"Enter start and finish times:\n";

    for(int i=0;i<n;i++){
        cin>>act[i].first>>act[i].second;
    }
    sort(act.begin(), act.end(), [](auto &a, auto &b){
        return a.second<b.second;
    });
    cout<<"\nSelected Activities(start, end):\n";

    int count=1;
    cout<<act[0].first<<" "<<act[0].second<<"\n";

    int last_end=act[0].second;

    for(int i=1;i<n;i++){
        if(act[i].first>=last_end){
            cout<<act[i].first <<" "<<act[i].second<<"\n";
            count++;
            last_end=act[i].second;
        }
           }

    cout<<"\nTotal selected activities:"<<count<<endl;

    return 0;
}
