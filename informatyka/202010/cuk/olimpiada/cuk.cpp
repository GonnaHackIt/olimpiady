#include <iostream>
#include <vector>
using namespace std;

int minIndex[3][1];
int abc = 0;
bool isD, isP, isR;
bool isD2, isP2, isR2;

struct gablota {
    int d;
    int p;
    int r;
};


void checkMains(vector<gablota>& vGablota, vector<int[3]>& main, long long int& moves) {
    
    if (!isD && isD2) {
        int i = minIndex[0][0];

        gablota x = vGablota[i];
        int a = x.d;
        int b = x.p;
        int c = x.r;


        if (main[i][1] == 1) {
            moves = moves - a - c;
            moves = moves + b + c;
        }
        else if (main[i][2] == 1) {
            moves = moves - a - b;
            moves = moves + b + c;
        }
        isD = true;
    }

    else if (!isP && isP2) {
        int i = minIndex[1][0];

        gablota x = vGablota[i];
        int a = x.d;
        int b = x.p;
        int c = x.r;

        if (main[i][0] == 1) {
            moves = moves - b - c;
            moves = moves + a + c;
        }
        else if (main[i][2] == 1) {
            moves = moves - a - b;
            moves = moves + a + c;
        }
        isP = true;
    }

    else if (!isR && isR2) {
        int i = minIndex[2][0];

        gablota x = vGablota[i];
        int a = x.d;
        int b = x.p;
        int c = x.r;

        if (main[i][0] == 1) {
            moves = moves - b - c;
            moves = moves + b + a;
        }
        else if (main[i][1] == 1) {
            moves = moves - a - c;
            moves = moves + b + a;
        }
        isR = true;
    }

}


void minMoves(vector<gablota>& vGablota, int i) {

    int min1, min2, min3;
    gablota x = vGablota[i];
    min1 = x.p + x.r;
    min2 = x.d + x.r;
    min3 = x.d + x.p;


    if (abc==0) {
        minIndex[0][0] = i;
        minIndex[0][1] = min1;
        minIndex[1][0] = i;
        minIndex[1][1] = min2;
        minIndex[2][0] = i;
        minIndex[2][1] = min3;
        abc++;
    }
    
    else {
        if (min1 < minIndex[0][1]) {
            minIndex[0][1] = min1;
            minIndex[0][0] = i;
        }
        if (min2 < minIndex[1][1]) {
            minIndex[1][1] = min1;
            minIndex[1][0] = i;
        }
        if (min3 < minIndex[2][1]) {
            minIndex[2][1] = min1;
            minIndex[2][0] = i;
        }
    }
    

}



void movesAdd(vector<gablota>& vGablota, vector<int[3]>& main, long long int& moves, int i) {


    gablota x = vGablota[i];
    if (main[i][0] == 1) {
        moves += (long long int)x.p + (long long int)x.r;
        
    }
    else if (main[i][1] == 1) {
        moves += (long long int)x.d + (long long int)x.r;
        
    }
    else if (main[i][2] == 1) {
        moves += (long long int)x.d + (long long int)x.p;
        
    }
    minMoves(vGablota, i);

}


void mainObj(vector<gablota>& vGablota, vector<int[3]> &main, int i) {

    gablota x = vGablota[i];
    int d = x.d;
    int p = x.p;
    int r = x.r;

    if (d >= p && d >= r) {
        if (d == p && isD) {
            main[i][1] = 1;
            isP = true;
        }
        else if (d == r && isD) {
            main[i][2] = 1;
            isR = true;
        }
        else {
            main[i][0] = 1;
            isD = true;
        }
    }
    else if (p >= d && p >= r) {
        if (d == p && isP) {
            main[i][0] = 1;
            isD = true;
        }
        else if (p == r && isP) {
            main[i][2] = 1;
            isR = true;
        }
        else {
            main[i][1] = 1;
            isP = true;
        }

    }
    else if (r >= d && r >= p) {
        if (r == d && isR) {
            main[i][0] = 1;
            isD = true;
        }
        else if (r == p && isR) {
            main[i][1] = 1;
            isP = true;
        }
        else {
            main[i][2] = 1;
            isR = true;
        }
    }
}



int main()
{
   
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long int moves = 0;
    vector<gablota> gabloty;
    vector<int[3]> main (300000);
 
    isD, isP, isR = false;
    isD2, isP2, isR2 = false;
    int i;
    cin >> i;

    for (int j = 0; j < i; j++) {

        int a, b, c;
        cin >> a >> b >> c;
        gablota gablota;
        gablota.d = a;
        gablota.p = b;
        gablota.r = c;
        if (a != 0) {
            isD2 = true;
        }
        if (b != 0) {
            isP2 = true;
        }
        if (c != 0) {
            isR2 = true;
        }
        gabloty.push_back(gablota);

        mainObj(gabloty, main, j);
        movesAdd(gabloty, main, moves, j);

    }

    for (int k = 0; k < 2; k++) {
        checkMains(gabloty, main, moves);
    }
   
    cout << moves << endl;

    return 0;
}



