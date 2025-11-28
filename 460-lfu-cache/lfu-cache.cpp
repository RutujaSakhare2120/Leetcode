class LFUCache {
public:
    map<int , list<vector<int>>>freq;//counter->{key , val , counter}
    unordered_map<int ,list<vector<int>>::iterator >mp;//key->addrss
    int size=0;
    int cap;
    LFUCache(int capacity) {
        cap=capacity;
    }
    void MakeMostFreqUsed (int key){
        auto &vec=*(mp[key]);

        int f=vec[2];
        int value=vec[1];

        freq[f].erase(mp[key]);
        if(freq[f] . empty()) freq.erase(f);
        f++;

        freq[f].push_front({key , value , f});
        mp[key]=freq[f].begin();

    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;

        auto vec=(*mp[key]);//{key , val , counter}
        int val=vec[1];
        MakeMostFreqUsed(key);
        return val;
        
    }
    
    void put(int key, int value) {
        if(cap==0) return;
        //alredy present
        if(mp.find(key)!=mp.end()){
          //only update val;
          auto &vec=*(mp[key]);
          vec[1]=value;
          MakeMostFreqUsed(key);
         

        }
        else if(size<cap){
            size++;
            //push it is fresh element
            freq[1].push_front(vector<int>{key , value , 1});
            mp[key]=freq[1].begin();

        }
        else{
            //remove lfu or lru

            auto &kon_sa_list=freq.begin()->second;
            int key_to_del = (kon_sa_list.back())[0];//lastwali
            
            

            kon_sa_list.pop_back();
            if(kon_sa_list.empty()){
                freq.erase(freq.begin()->first);
            }
            //push new ele
            freq[1].push_front(vector<int>{key , value , 1});
            //also delete from mp;
            mp.erase(key_to_del);
            mp[key]=freq[1].begin();


        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */