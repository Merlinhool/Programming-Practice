/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
bool operator ==(const Point&a, const Point&b) {
        return (1ll * a.x * b.y - 1ll * a.y * b.x) == 0;
}
bool operator < (const Point&a, const Point&b) {
        return (1ll * a.x * b.y - 1ll * a.y * b.x) < 0;
}
Point operator - (const Point&a, const Point&b) {
        return Point(a.x-b.x, a.y-b.y);
}
bool equ(Point a, Point b) {
        return a.x == b.x && a.y == b.y;
}
bool cmp(Point a, Point b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
}
class Solution {
public:
        int maxPoints(vector<Point>& pnt) {
                int n = pnt.size();
                sort(pnt.begin(), pnt.end(), cmp);

                vector<pair<Point, int> > vec;
                for(int i = 0; i < n; ++i) {
                        if(!i || !equ(pnt[i], vec.back().first)) vec.push_back(make_pair(pnt[i], 1));
                        else ++(vec.back().second);
                }

                int ans = 0;
                map<Point, int> has;
                for(int i = 0; i < (int)vec.size(); ++i) {
                        has.clear();
                        for(int j = i + 1; j < (int)vec.size(); ++j) {
                                has[vec[i].first-vec[j].first] += vec[j].second;
                        }
                        int mx = 0;
                        for(map<Point, int>::iterator it = has.begin(); it != has.end(); ++it) {
                                mx = std::max(mx, it->second);
                        }
                        ans = std::max(ans, mx + vec[i].second);
                }
                return ans;
        }
};
