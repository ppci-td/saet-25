// metodo de monte carlo. Com coordenadas polares. Deve dar WA por 'poucas'
// iteracoes e tambem por precisao ruim

#define ITERACOES 1000000

#include <bits/stdc++.h>

using namespace std;

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

pvec gira(pvec p, double a) {
    return pvec(p.x*cos(a) - p.y*sin(a), p.x*sin(a) + p.y*cos(a));
}

double r, x, y;
double a[4];
int qnts[4];

int main() {

    srand(time(NULL) + clock());
    scanf("%lf %lf %lf", &r, &x, &y);
    memset(qnts,0,sizeof(qnts));
    for (int tt=0;tt<ITERACOES;tt++) {
        double p = (double)rand()/(double)RAND_MAX;
        pvec pt = pvec(r*p,0);
        double g = (double)rand()/(double)RAND_MAX;
        pt = gira(pt, g*2.0*M_PI);
//        printf("%.3lf %.3lf dist %.3lf\n", pt.x, pt.y, pt.abs());
        if (pt.x <= x and pt.y <= y) qnts[0]++;
        else if (pt.x >= x and pt.y <= y) qnts[1]++;
        else if (pt.x >= x and pt.y >= y) qnts[2]++;
        else if (pt.x <= x and pt.y >= y) qnts[3]++;
    }

    for (int i=0;i<4;i++)
        a[i] = (double)qnts[i]/(double)ITERACOES * M_PI*r*r;

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
