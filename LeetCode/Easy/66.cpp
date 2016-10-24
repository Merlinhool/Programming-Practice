class Solution {
public
    vectorint plusOne(vectorint& an) {
        int n = (int)an.size() + 1;
        reverse(an.begin(), an.end());
        an.push_back(0);
        an[0] += 1;
        int flag = 0;
        for(int i = 0, t; i  n; ++i) {
            t = flag + an[i];
            if(t == 10) {
                flag = 1; 
                t = 0;
            } else {
                flag = 0;
            }
            an[i] = t;
        }
        if(an[(int)an.size()-1] == 0) an.erase(an.end()-1);
        reverse(an.begin(), an.end());
        return an;
    }
};
