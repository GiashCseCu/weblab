#include<bits/stdc++.h>

void knap(int item, float cost[], float wig[], float cap)
{
  int u,i;
  float x[100],prof = 0.0;
  for(i=0;i<item; i++)
    x[i] = 0.0;

    for(i=0; i<item; i++)
    {
        if(wig[i]>u)
            break;
        else
        {
            x[i] = 1.0;
            prof = prof+cost[i];
            u = u-wig[i];
        }
    }
    if(i<item)
        x[i] = u/wig[i];
    prof = prof+(x[i]*cost[i]);

    printf(".2%f\n", prof);
}
//void knap(int item,float wig[],float cost,int cap);

int main()
{
    int item,i,j;
    float cost[100],wig[100],frac[100],temp,cap;

    scanf("%d %f", &item, &cap);
    for(int i=0; i<item; i++)
    {
        scanf("%f %f", &wig[i], &cost[i]);
    }
    for(i=0; i<item; i++)
    {
        frac[i] = cost[i]/wig[i];
        printf("%f\n", frac[i]);
    }

    for(i=0; i<item; i++)
    {
        for(j=i+1; j<item-1; j++)
        {
            if(frac[i]<frac[j])
            {
              temp = frac[j];
            frac[j] = frac[i];
            frac[i] = temp;

            temp = wig[j];
            wig[j] = wig[i];
            wig[i] = temp;

            temp = cost[j];
            cost[j] = cost[i];
            cost[i] = temp;
            }
        }
    }
    knap(item, wig, cost,cap);

  return 0;
}




