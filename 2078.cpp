class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n=colors.size();
        int ans=-1;
        if(colors[0]!=colors[n-1]){
            return n-1;
        }else{
            int x=colors[0];
            for(int i=1;i<n-1;i++){
                if(colors[i]!=x){
                    ans=max(max(i,n-1-i),ans);
                }
            }
        }
        return ans;
    }
};
