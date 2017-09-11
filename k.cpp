#include<bits/stdc++.h>
using namespace std;

void knap(int n, float w[], float p[], float cap) {
   float x[20], prof = 0;
   int i, j, u;
   u = cap;

   for (i = 0; i < n; i++)
      x[i] = 0.0;

   for (i = 0; i < n; i++) {
      if (w[i] > u)
         break;
      else {
         x[i] = 1.0;
         prof = prof + p[i];
         u = u - w[i];
      }
   }

   if (i < n)
      x[i] = u / w[i];

   prof = prof + (x[i] * p[i]);

   printf("%.2f\n", prof);

}

int main() {
   float w[20], p[20], cap;
   int item, i, j;
   float r[20], temp;


   scanf("%d %f", &item, &cap);
   for (i = 0; i < item; i++) {
      scanf("%f %f", &w[i], &p[i]);
   }

   for (i = 0; i < item; i++) {
      r[i] = p[i] / w[i];
   }

   for (i = 0; i < item; i++) {
      for (j = i + 1; j < item; j++) {
         if (r[i] < r[j]) {
            temp = r[j];
            r[j] = r[i];
            r[i] = temp;

            temp = w[j];
            w[j] = w[i];
            w[i] = temp;

            temp = p[j];
            p[j] = p[i];
            p[i] = temp;
         }
      }
   }

   knap(item, w, p, cap);


   return 0;
}

