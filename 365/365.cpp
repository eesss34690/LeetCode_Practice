class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (x+ y< z) return false;
        if (!z) return true;
        if (z% __gcd(x, y)) return false;
        return true;
    }
};