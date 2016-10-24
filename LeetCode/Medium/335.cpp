class Solution {
public:
    int DX[4] = {0, -1, 0, 1};
    int DY[4] = {-1, 0, 1, 0};
    pair<int, int> temp[2];
    bool in(int x, int y) {
        if(x < temp[1].first) {
            temp[1].first = x; 
            return true;
        }
        if(x > temp[1].second) {
            temp[1].second = x;
            return true;
        }
        if(y < temp[0].first) {
            temp[0].first = y;
            return true;
        }
        if(y > temp[0].second) {
            temp[0].second = y;
            return true;
        }
        return false;
    }
    bool isSelfCrossing(vector<int>& an) {
        if((int)an.size() < 4) return false;
        
        temp[1] = temp[0] = make_pair(0, 0);
        bool flag = false, flag2 = false;
        int x = 0, y = 0;
        for(int i = 0, tx, ty; i < (int)an.size(); ++i) {
            tx = x + DX[i%4] * an[i];
            ty = y + DY[i%4] * an[i];
            
            if(flag) {
                if(an[i] >= an[i-2]) return true;
                if(!flag2){
                    bool xt = false;
                    if(i == 4) xt = (an[1] == an[3]);
                    else if(i > 4) xt = (an[i-1] >= an[i-3]-an[i-5]);
                    
                    if(xt && an[i] >= an[i-2]-an[i-4]) return true;
                    flag2 = true;
                }
            }
            if(!flag && !in(tx, ty)) flag = true;
            
            x = tx; y = ty;
        }
        return false;
    }
};
