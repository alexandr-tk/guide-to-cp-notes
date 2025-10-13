#include<bits/stdc++.h>

using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n,k;
  cin>>n>>k;
  ordered_set<int> children;

  for(int i=1; i<=n; i++) children.insert(i);


  int new_rank = k - n * (int)(k/n);
  while(children.size()!=0)
  {
    auto it = children.find_by_order(new_rank);
    cout<<*it<<" ";
    it = children.erase(it);
    if(children.size()==0) break;
    if(it == children.end()){
        it = children.begin();
    }

    new_rank = children.order_of_key(*it) + k;

    if(new_rank >= children.size()){
      new_rank = new_rank - children.size() * (int)(new_rank/children.size());
    }
    it = children.find_by_order(new_rank);
  }

}

