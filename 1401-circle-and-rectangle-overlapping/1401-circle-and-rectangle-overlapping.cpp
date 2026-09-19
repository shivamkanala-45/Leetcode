class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        int x, y;
        if (xc <= x1)
            x = x1;
        else if (xc >= x2)
            x = x2;
        else
            x = xc;
        if (yc <= y1)
            y = y1;
        else if (yc >= y2)
            y = y2;
        else
            y = yc;
        int d = (x - xc) * (x - xc) + (y - yc) * (y - yc);
        if (d <= r * r)
            return 1;

        return 0;
    }
};