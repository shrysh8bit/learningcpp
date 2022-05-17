class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int seen[10000] = {0};
        string start = "0000";
        
        int temp;
        for (string i : deadends){
            temp = stoi(i);
            seen[temp] = 1;
        }
        
        if (seen[0] == 1) return -1;
        
        queue<pair<string, int>> que;
        que.push({start, 0});
        
        string curr_val, temp_val;
        int curr_dist, min_dist = INT_MAX;
            
        
        while(!que.empty()){
            curr_val = que.front().first;
            curr_dist = que.front().second;
            que.pop();
            
            if(curr_val == target){
                min_dist = min (min_dist, curr_dist);
            }
            
            for (int i = 0; i <= 3; i++){
                temp_val = curr_val; 
                
                if (temp_val[i] == '9'){
                    temp_val[i] = '0';
                }else{
                    temp_val[i]++;
                }
                
                temp = stoi(temp_val);
                
                if(seen[temp] != 1 && curr_dist < min_dist){
                    seen[temp] = 1;
                    que.push({temp_val, curr_dist + 1});
                }
                
                temp_val = curr_val; 
                
                if (temp_val[i] == '0'){
                    temp_val[i] = '9';
                }else{
                    temp_val[i]--;
                }
                
                temp = stoi(temp_val);
                
                if(seen[temp] != 1 && curr_dist < min_dist){
                    seen[temp] = 1;
                    que.push({temp_val, curr_dist + 1});
                }
                
            }
            
        }
        
        
        if (min_dist < INT_MAX){
            return min_dist;
        }else{
            return -1;
        }
        
        
        
        
    }
        
};