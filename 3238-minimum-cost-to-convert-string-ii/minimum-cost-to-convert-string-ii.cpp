

class Solution {
public:
    typedef long long ll;
    typedef pair<ll , string> p;
    ll BIG_VALUE=1e10;
    unordered_map<string, vector<pair<string , ll>>> adjList;


    unordered_map<string, unordered_map<string , ll>> dijkstraMemo;

    vector<ll>dpMemo;

    string sourcestr;
    string targetstr;

    set<int>validLengths;

    ll dijkstra(string &start ,  string &end){      if(dijkstraMemo[start].count(end)) return dijkstraMemo[start][end];
       priority_queue<p , vector<p> , greater<p>>pq;

       unordered_map<string , ll>result;
       result[start]=0;
       pq.push({0, start});

       while(!pq.empty()){
        ll currCost=pq.top().first;
        string node=pq.top().second;

        pq.pop();
         if(node==end) break;

         for(auto &edge:adjList[node]){
            string adjNode=edge.first;
            ll edgeCost=edge.second;

            if(!result.count(adjNode) || currCost+edgeCost < result[adjNode]){
                result[adjNode]=currCost+edgeCost;
                pq.push({currCost+edgeCost , adjNode});
            }
         }
        

       }                                                              

       ll finalCost=result.count(end) ? result[end] : BIG_VALUE;
       return dijkstraMemo[start][end]=finalCost;
    }

    ll solve(int idx){
        if(idx>=sourcestr.size()) return 0;
        if(dpMemo[idx]!= -1) return dpMemo[idx];

        ll minCost=BIG_VALUE;

        if(sourcestr[idx]== targetstr[idx])  minCost=solve(idx+1);

        for(auto &len:validLengths){
            if(idx+len > sourcestr.size()) break;

            string srcSub=sourcestr.substr(idx , len);
            string tgtSub=targetstr.substr(idx , len);

            if(!adjList.count(srcSub)) continue;

            ll minPathCost=dijkstra(srcSub ,tgtSub );

            if(minPathCost==BIG_VALUE) continue;

            minCost=min(minCost ,minPathCost+solve(idx+len) );


        }
      return dpMemo[idx]=minCost;
    }

    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        sourcestr=source;
        targetstr=target;

        dpMemo.resize(10001 , -1);
        for(int i=0;i<original.size();i++){
            adjList[original[i]].push_back({changed[i] , cost[i]});
        }

        for(auto &s:original){
            validLengths.insert(s.size());
        }

        ll result=solve(0);

        return result==BIG_VALUE ? -1 :result;
        
    }
};