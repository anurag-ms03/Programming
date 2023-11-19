#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;
double heron_area(int a, int b, int c) {
    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
void sort_by_area(triangle* tr, int n) {
	double a[n];
    for(int i=0;i<n;i++){
        a[i]=heron_area(tr[i].a,tr[i].b,tr[i].c);
    }
      int i, j;  
  for (i = 0; i < n - 1; i++) {  
    for (j = 0; j < n - i - 1; j++) {  
      if (a[j] > a[j + 1]) {  
        double temp = a[j];  
        a[j] = a[j + 1];  
        a[j + 1] = temp;  
        triangle temp2=tr[j];
        tr[j]=tr[j+1];
        tr[j+1]=temp2;
      }  
    }  
  }  
}
int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}