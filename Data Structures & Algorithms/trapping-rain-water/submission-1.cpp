#include <iostream>
#include <vector>
using namespace std;

void printVector(const vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> l = {};
        vector<int> r(height.size());
        int maxL = 0;
        int maxR = 0;
        int result = 0;
        for(int i = 0; i < height.size(); i++){
            if(i == 0){
                l.push_back(0);
                if(height[i] > maxL) maxL = height[i];
                continue;
            }
            l.push_back(maxL);
            if(height[i] > maxL) maxL = height[i];
        }
        for(int i = height.size() - 1; i >= 0; i--){
            if(i == height.size() - 1){
                r[i] = 0;
                if(height[i] > maxR) maxR = height[i];
                continue;
            }
            r[i] = maxR;
            if(height[i] > maxR) maxR = height[i];
        }
        printVector(l);
        printVector(r);

        for(int i = 0; i < height.size(); i++){
            const int minHeight = min(l[i], r[i]);
            if( minHeight - height[i] <= 0 ) continue;
            result += minHeight - height[i];
        }
        return result;
    }
};
