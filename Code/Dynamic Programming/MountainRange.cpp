#include<bits/stdc++.h>
using namespace std;


int find_max_in_range(int l, int r, const vector<int>& range, int peek){
    if(abs(r-l)<=1) return 0;
    int max_el = -1, max_idx = -1;
    for(int i=l+1; i<r; i++)
    {
        if(range[i]>max_el)
        {
            max_idx = i;
            max_el = range[i];
        }
    }

    if(max_el<peek)
    {
        return 1+max(find_max_in_range(l,max_idx, range, max_el), find_max_in_range(max_idx, r,range, max_el));
    }
    else{
        return max(find_max_in_range(l,max_idx, range, max_el), find_max_in_range(max_idx, r,range, max_el));
    }
}


int main(){
    int n;
    cin>>n;
    vector<int> mountains(n);

    for(int i=0; i<n; i++)
    {
        cin>>mountains[i];

    } 

    cout<<find_max_in_range(-1, n, mountains, INT_MAX);


}