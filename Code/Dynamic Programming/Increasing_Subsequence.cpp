
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<int> array(n, 0);
    set<pair<int,int>> numbers;
    //unordered_map<int,int> longestSub;

    for(int i=0; i<n; i++) 
    {
        int num;
        cin>>num;
        array[i] = num;

        numbers.insert({-1,0});
        

        auto it = numbers.lower_bound({num, INT_MIN});
        if(it!=numbers.begin())
        {
            if(it==numbers.end())
            {
                --it;
                numbers.insert({num, (*it).second+1});
            }
            if(num<(*it).first)
            {
                auto prevIt = prev(it);
                numbers.erase(it);
                numbers.insert({num, (*prevIt).second+1});
            }
        }

    }

    auto last = prev(numbers.end());
    cout<<(*last).second;
}