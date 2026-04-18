class Solution {
public:
    int mirrorDistance(int n) {
        int res=0;
        int x=n;
        for(;x>0;x/=10){
            res=res*10+x%10;
        }
        return abs(res-n);
    }
};
