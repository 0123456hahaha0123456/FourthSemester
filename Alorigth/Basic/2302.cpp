#include <iostream>
#include <string>
#include <algorithm>
#define MAXSETSIZE 210
#define DIGIT 0
#define COMMA 2
#define DEFIS 3
#define BLANK 4
#define OTHER 5

using namespace std;

struct SETINARRAY {
	int m[MAXSETSIZE];
	int n;
};
void Union(SETINARRAY &A, SETINARRAY &B, SETINARRAY &Res);
void Cross(SETINARRAY &A, SETINARRAY &B, SETINARRAY &Res);
void Difference(SETINARRAY &A, SETINARRAY &B, SETINARRAY &Res);
short SymClass(char z);
int StringToIntArray(string &p, int *r);
string ArrayToString(int *p, int np);

int main() {
	SETINARRAY X, Y, Z;
	string s;
	cin >> s;
	X.n = StringToIntArray(s, X.m);
	cin >> s;
	Y.n = StringToIntArray(s, Y.m);

	Union(X, Y, Z);
	cout << ArrayToString(Z.m, Z.n);
	Cross(X, Y, Z);
	cout << "\n" + ArrayToString(Z.m, Z.n);
	Difference(X, Y, Z);
	cout << "\n" + ArrayToString(Z.m, Z.n);
	return 0;
}

void Union(SETINARRAY &A, SETINARRAY &B, SETINARRAY &Res) {
    Res.n = 0;
    for(int i=0;i<A.n;i++){
        Res.m[Res.n] = A.m[i];
        Res.n++;
    }
    for(int i=0;i<B.n;i++){
        bool ok = true;
        for(int j=0;j<A.n;j++) 
			if (A.m[j] == B.m[i]) {
				ok = false;
				break;
			}
        if (ok) {
            Res.m[Res.n] = B.m[i];
            Res.n ++;
        }
    }
    if (Res.n>0) sort(Res.m,Res.m+Res.n);
}
void Cross(SETINARRAY &A, SETINARRAY &B, SETINARRAY &Res) {
    Res.n = 0;
    for(int i=0;i<A.n;i++){
        for(int j=0;j<B.n;j++) 
			if(A.m[i] == B.m[j]) {
				Res.m[Res.n] = A.m[i];
				Res.n++;
				break;
			}
    }
    if (Res.n>0) sort(Res.m,Res.m+Res.n);
}

void Difference(SETINARRAY &A, SETINARRAY &B, SETINARRAY &Res) {
    Res.n = 0;
    for(int i=0;i<A.n;i++){
        bool ok= true;
        for(int j=0;j<B.n;j++) if (A.m[i] == B.m[j]) {
            ok = false;
            break;
        }
        if(ok) {
            Res.m[Res.n] = A.m[i];
            Res.n++;
        }
    }

    for(int i=0;i<B.n;i++){
        bool ok = true;
        for(int j=0;j<A.n;j++) if (A.m[j] == B.m[i]) {
            ok = false;
            break;
        }
        if(ok) {
            Res.m[Res.n] = B.m[i];
            Res.n++;
        }
    }
    if (Res.n>0) sort(Res.m,Res.m+Res.n);
}

short SymClass(char z) {
	if (z >= '0' && z <= '9') {
		return DIGIT;
	}
	if (z == ',') {
		return COMMA;
	}
	if (z == '-') {
		return DEFIS;
	}
	if (z == ' ') {
		return BLANK;
	}
	return OTHER;
}

int StringToIntArray(string &p, int *r) {
	int k, p1 = -1, p2 = -1;
	char buf[20];
	short sClass;
	int i = 0;
	int n = 0;
	int LastPunkt = -1;

	if (!p.size()) {
		return 0;
	}
	for (int j = 0; j < p.size(); j++) {
		sClass = SymClass(p[j]);
		switch (sClass) {
		case DIGIT:
			buf[i++] = p[j];
			break;
		case COMMA:
			buf[i] = '\0';
			if (LastPunkt == -1 || LastPunkt == COMMA) {
				p1 = atoi(buf);
				r[n++] = p1;
			}
			if (LastPunkt == DEFIS) {
				p2 = atoi(buf);
				if (p1 == -1 || p2 == -1) {
					return -1;
				}
				if (p2<p1) {
					return -1;
				}
				for (k = p1; k <= p2; k++) {
					r[n++] = k;
				}
				p1 = p2 = -1;
			}
			i = 0;
			LastPunkt = COMMA;
			break;
		case DEFIS:
			buf[i] = '\0';
			p1 = atoi(buf);
			p2 = -1;
			LastPunkt = DEFIS;
			i = 0;
			break;
		case BLANK:
			break;
		default:
			return -1;
		} // switch
	}
	buf[i] = '\0';
	if (LastPunkt == -1 || LastPunkt == COMMA) {
		p1 = atoi(buf);
		r[n++] = p1;
	}
	if (LastPunkt == DEFIS) {
		p2 = atoi(buf);
		if (p1 == -1 || p2 == -1) {
			return -1;
		}
		for (k = p1; k <= p2; k++) {
			r[n++] = k;
		}
	}

	bool b = true;
	int t;
	while (b) {
		b = false;
		for (i = 0; i<n - 1; i++) {
			if (r[i]>r[i + 1]) {
				t = r[i];
				r[i] = r[i + 1];
				r[i + 1] = t;
				b = true;
			}
		}
	}
	return n;
}

string ArrayToString(int *p, int np) {
	if (!np) {
		return "Empty";
	}
	int i, cnt = 0;
	string s = to_string(p[0]);
	bool DiffOne, SerStart = false, fOne = false;
	for (i = 1; i < np; i++) {
		DiffOne = (p[i] - p[i - 1] == 1);
		if (!SerStart && DiffOne) {
			SerStart = true;
		}
		if (DiffOne) {
			cnt++;
			if (i == np - 1) {
				if (cnt > 1) {
					s += "-";
				}
				else {
					s += ",";
				}
				s += to_string(p[i]);
			}
			else if (((p[i + 1] - p[i]) != 1) && cnt==1) {
				s += "," + to_string(p[i]);
			}
		}
		else {
			if (cnt <= 1) {
				s += ",";
				s += to_string(p[i]);
			}
			else {
				fOne = false;
				s += "-";
				s += to_string(p[i - 1]);
				s += ",";
				s += to_string(p[i]);
				cnt = 0;
			}
		}
	}
	return s;
}
