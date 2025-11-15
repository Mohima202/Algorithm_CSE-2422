#include<bits/stdc++.h>
using namespace std;

int main(){
    string text, pattern;
    cout<<"Enter text:";
    cin>>text;

    cout<<"Enter pattern:";
    cin>>pattern;

    int n=text.size();
    int m=pattern.size();

    int base=256;      
    int mod=101;       

    int patHash=0;     
    int winHash=0;     
    int h=1;           

    for(int i=0;i<m-1;i++)
        h=(h*base)% mod;


    for(int i =0; i< m; i++){
        patHash =(patHash*base+pattern[i])% mod;
        winHash =(winHash*base+text[i])% mod;
    }
    cout<<"\nPattern found at index: ";

    for(int i = 0; i <= n - m; i++){

        if(patHash==winHash) {
            bool match = true;
            for(int j=0; j<m; j++){
                if(text[i + j] != pattern[j]){
                    match = false;
                    break;
                }
            }
            if(match) cout << i << " ";
        }
        if(i<n-m){
            winHash=(winHash-text[i] * h)% mod;
            winHash=(winHash*base+text[i+m])% mod;

            if(winHash<0)winHash+=mod;  
        }
    }
    cout<<endl;
    return 0;
}
