class SmallestInfiniteSet {
public:
    vector<bool> out;
    SmallestInfiniteSet() {
        out.resize(1001, true);
    }

    int popSmallest() {
        for (int i = 1; i <= 1000; i++)
        {
            if (out[i])
            {
                out[i] = false;
                return i;
            }
        }
        return NULL;
    }

    void addBack(int num) {
        out[num] = true;
    }
};
