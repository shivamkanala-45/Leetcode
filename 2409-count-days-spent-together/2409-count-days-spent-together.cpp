class Solution {
public:
    int countDaysTogether(string aa, string la, string ab, string lb) {
        int v[14] = {0,   0,   31,  59,  90,  120, 151,
                     181, 212, 243, 273, 304, 334, 365};
        int a = v[(aa[0] - '0') * 10 + (aa[1] - '0')] + (aa[3] - '0') * 10 +
                (aa[4] - '0');
        int b = v[(ab[0] - '0') * 10 + (ab[1] - '0')] + (ab[3] - '0') * 10 +
                (ab[4] - '0');
        int c = v[(la[0] - '0') * 10 + (la[1] - '0')] + (la[3] - '0') * 10 +
                (la[4] - '0');
        int d = v[(lb[0] - '0') * 10 + (lb[1] - '0')] + (lb[3] - '0') * 10 +
                (lb[4] - '0');
        cout << a << " " << b << " " << c << " " << d << endl;
        int e = max(a, b);
        int f = min(c, d);
        if (f - e < 0)
            return 0;
        return f - e + 1;
    }
};