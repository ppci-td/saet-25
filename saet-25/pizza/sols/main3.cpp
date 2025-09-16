// long long double

#include <bits/stdc++.h>

#define EPS 1e-7 // so usado para testar = 0

using namespace std;

inline int cmpf(long double a, long double b) {
    if (fabs(a-b) < EPS) return 0;
    return a < b ? -1 : 1;
}

struct pvec {
    long double x, y;
    pvec(long double x=0, long double y=0) :x(x), y(y) {}
    pvec operator+(pvec p) { return pvec(x+p.x,y+p.y); }
    pvec operator-(pvec p) { return pvec(x-p.x,y-p.y); }
    pvec operator*(long double a) { return pvec(a*x,a*y); }
    long double dot(pvec p) { return x*p.x + y*p.y; }
    long double cross(pvec p) { return x*p.y - y*p.x; }
    long double abs() { return sqrt(x*x + y*y); }
    long double angulo(pvec p) { // angulo entre vetores
                   //[---cos do angulo----]
        return acos( dot(p)/(abs()*p.abs()) );
    }
};

struct reta {
    pvec P, vd;
    reta(pvec A, pvec B) :P(A), vd(B-A) {} // Definir reta dados dois pontos!!
    pvec intersec(reta s) {
       if (cmpf(vd.x,0.0)==0) return s.P + s.vd*( (P.x - s.P.x)/s.vd.x );
       return s.P + s.vd*( (P.y - s.P.y + (s.P.x - P.x)*vd.y/vd.x)/
                           (s.vd.y - vd.y*s.vd.x/vd.x ) );
    }
};

long double area_tri(pvec p1, pvec p2, pvec p3) {
    return fabs( (p2-p1).cross(p3-p1) )/2.0;
}

long double r, x, y;
long double a[4];
pvec P;

long double calc1() {
    pvec A = pvec(-sqrt(r*r-y*y),y);
    pvec B = pvec(x,-sqrt(r*r-x*x));
    long double aLfa = A.angulo(B);
    long double circ = aLfa*r*r/2.0;
    long double t1 = y*fabs(A.x)/2.0;
    long double t2 = x*fabs(B.y)/2.0;
    long double ret = x*y;
    return circ+t1+t2+ret;
}

long double calc2() {
    pvec A = pvec(x,-sqrt(r*r-x*x));
    pvec B = pvec(+sqrt(r*r-y*y),y);
    long double aLfa = A.angulo(B);
    long double circ = aLfa*r*r/2.0;
    pvec C = reta(pvec(0,0),B).intersec(reta(P, pvec(x,r)));
    long double t1 = (P-C).abs()*(B-P).x/2.0;
    long double t2 = area_tri(pvec(0,0),A,C);
    return circ+t1-t2;
}

long double calc3() {
    pvec A = pvec(+sqrt(r*r-y*y),y);
    pvec B = pvec(x,+sqrt(r*r-x*x));
    long double aLfa = A.angulo(B);
    long double circ = aLfa*r*r/2.0;
    long double t1 = area_tri(pvec(0,0), A, P);
    long double t2 = area_tri(pvec(0,0), B, P);
    return circ-t1-t2;
}

int main() {

    scanf("%Lf %Lf %Lf", &r, &x, &y);
    x = fabs(x);
    y = fabs(y);

    P = pvec(x,y);
    a[0] = calc1();
    a[1] = calc2();
    a[2] = calc3();
    a[3] = M_PIl*r*r - a[0] - a[1] - a[2];

    sort(a,a+4);
    for (int i=0;i<4;i++) {
        if (i) printf(" ");
        printf("%.3Lf",a[i]);
    }
    printf("\n");

    // debug
/*    long double soma = a[0]+a[1]+a[2]+a[3];
    long double tudo = M_PI*r*r;
    printf("%.15Lf\n%.15Lf\n",soma,tudo);*/

    return 0;
}
