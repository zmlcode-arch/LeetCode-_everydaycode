class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int ans=0;
        int cnt_=0,cnt_L=0,cnt_R=0;
        for(char it:moves){
            if(it=='L'){
                cnt_L++;
            }else if(it=='R'){
                cnt_R++;
            }else{
                cnt_++;
            }
        }
        if(cnt_L>=cnt_R){
            return cnt_L-cnt_R+cnt_;
        }else{
            return cnt_R-cnt_L+cnt_;
        }
    }
};
