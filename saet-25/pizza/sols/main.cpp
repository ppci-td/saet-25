#include <bits/stdc++.h>

#define EPS 1e-7 // so usado para testar = 0

using namespace std;

inline int cmpf(double a, double b) {
    if (fabs(a-b) < EPS) return 0;
    return a < b ? -1 : 1;
}

struct pvec {
    double x, y;
    pvec(double x=0, double y=0) :x(x), y(y) {}
    pvec operator+(pvec p) { return pvec(x+p.x,y+p.y); }
    pvec operator-(pvec p) { return pvec(x-p.x,y-p.y); }
    pvec operator*(double a) { return pvec(a*x,a*y); }
    double dot(pvec p) { return x*p.x + y*p.y; }
    double cross(pvec p) { return x*p.y - y*p.x; }
    double abs() { return sqrt(x*x + y*y); }
    double angulo(pvec p) { // angulo entre vetores
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

double area_tri(pvec p1, pvec p2, pvec p3) {
    return fabs( (p2-p1).cross(p3-p1) )/2.0;
}

double r, x, y;
double a[4];
pvec P;

double calc1() {
    pvec A = pvec(-sqrt(r*r-y*y),y);
    pvec B = pvec(x,-sqrt(r*r-x*x));
    double alfa = A.angulo(B);
    double circ = alfa*r*r/2.0;
    double t1 = y*fabs(A.x)/2.0;
    double t2 = x*fabs(B.y)/2.0;
    double ret = x*y;
    return circ+t1+t2+ret;
}

double calc2() {
    pvec A = pvec(x,-sqrt(r*r-x*x));
    pvec B = pvec(+sqrt(r*r-y*y),y);
    double alfa = A.angulo(B);
    double circ = alfa*r*r/2.0;
    pvec C = reta(pvec(0,0),B).intersec(reta(P, pvec(x,r)));
    double t1 = (P-C).abs()*(B-P).x/2.0;
    double t2 = area_tri(pvec(0,0),A,C);
    return circ+t1-t2;
}

double calc3() {
    pvec A = pvec(+sqrt(r*r-y*y),y);
    pvec B = pvec(x,+sqrt(r*r-x*x));
    double alfa = A.angulo(B);
    double circ = alfa*r*r/2.0;
    double t1 = area_tri(pvec(0,0), A, P);
    double t2 = area_tri(pvec(0,0), B, P);
    return circ-t1-t2;
}

double calc4() {
    pvec A = pvec(-sqrt(r*r-y*y),y);
    pvec B = pvec(x,+sqrt(r*r-x*x));
    double alfa = A.angulo(B);
    double circ = alfa*r*r/2.0;
    pvec C = reta(pvec(0,0),B).intersec(reta(P,pvec(r,y)));
    double t1 = area_tri(C,P,B);
    double t2 = area_tri(C,A,pvec(0,0));
    return circ+t1-t2;
}

int main() {

    scanf("%lf %lf %lf", &r, &x, &y);
    x = fabs(x);
    y = fabs(y);

    P = pvec(x,y);
    a[0] = calc1();
    a[1] = calc2();
    a[2] = calc3();
    a[3] = calc4();

    sort(a,a+4);
    for (int i=0;i<4;i++) {
        if (i) printf(" ");
        printf("%.3lf",a[i]);
    }
    printf("\n");

    // debug
/*    double soma = a[0]+a[1]+a[2]+a[3];
    double tudo = M_PI*r*r;
    printf("%.15lf\n%.15lf\n",soma,tudo);*/

    return 0;
}
