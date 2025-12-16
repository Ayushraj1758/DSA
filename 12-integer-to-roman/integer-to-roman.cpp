class Solution {
public:
    string intToRoman(int num) {
        int I,V,X,L,C,D,M,cm,cd,xc,xl,ix,iv;

        M = num / 1000; num %= 1000;
        cm = num / 900; num %= 900;
        D = num / 500; num %= 500;
        cd = num / 400; num %= 400;
        C = num / 100; num %= 100;
        xc = num / 90; num %= 90;
        L = num / 50; num %= 50;
        xl = num / 40; num %= 40;
        X = num / 10; num %= 10;
        ix = num / 9; num %= 9;
        V = num / 5; num %= 5;
        iv = num / 4; num %= 4;
        I = num;

        string res = "";

        res += string(M, 'M');
        while (cm--) res += "CM";
        res += string(D, 'D');
        while (cd--) res += "CD";
        res += string(C, 'C');
        while (xc--) res += "XC";
        res += string(L, 'L');
        while (xl--) res += "XL";
        res += string(X, 'X');
        while (ix--) res += "IX";
        res += string(V, 'V');
        while (iv--) res += "IV";
        res += string(I, 'I');

        return res;
    }
};
