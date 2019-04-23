#include<stdio.h>
int main()
{
    int x,p,q,m,tp;
    int y[10]={1,2,3,4,5,6,7,8,9,0};
    int bt_x[10],at_x[10],wt_x[10],tat_x[10],tt=0,s=0,z=1,bt=0;
    float wt_a=0, tat_a=0,tat_s=0,wt_s=0;
    printf("************/|\ Shortest JOb First /|\*************\n\n");
    printf("\n Enter No of Process:- ");
    scanf("%d", &x);

    for(p=0;p<x;p++)
    {
        printf("\t burst time p%d:- ",p+1);
        scanf("%d",&bt_x[p]);

    }
    primal:
    for(p=0; p<x; p++)
    {
        printf("\t arrival time p%d:- ", p+1);
        scanf("\t%d",&at_x[p]);
        if(at_x[p]==0)
        {
            printf("invalid arrival time");
            goto primal;
        }
    }



    for(p=0; p<x; p++)
    {
        for (q=0; q<x; q++)
        {
            if(at_x[p]<at_x[q])
            {
                tp=y[q];
                y[q]=y[p];
                y[q]=tp;
                tp=at_x[q];
                at_x[q]=at_x[p];
                at_x[p]=tp;
                tp=bt_x[q];
                bt_x[q]=bt_x[p];
                bt_x[p]=tp;
            }
        }
    }

   for(q=0;q<x;q++)
   {
       bt=bt+bt_x[q];
       m=bt_x[z];
       for(p=z ; p<x; p++)
       {
           if(bt>=at_x[p] && bt_x[p]<m)
           {
               tp=y[z];
               y[z]=y[p];
               y[p]=tp;
               tp=at_x[z];
               at_x[z]=at_x[p];
               at_x[p]=tp;
               tp=bt_x[z];
               bt_x[z]=bt_x[p];
               bt_x[p]=tp;
           }
       }
       z++;
   }
   wt_x[0]=0;
   for(p=1; p<x; p++)
   {
       s=s+bt_x[p-1];
       wt_x[p]=s-at_x[p];
       wt_s=wt_s+wt_x[p];
   }

   wt_a=(wt_s/x);
   for(p=0;p<x;p++)
   {
       tt=tt+bt_x[p];
       tat_x[p]=tt-at_x[p];
       tat_s=tat_s+tat_x[p];
   }
   tat_a=(tat_s/x);
   printf("\n OUTPUT: ");
   printf("\nprocess\t AT\t BT\t TAT\t WT" );
   for(p=0; p<x; p++)
   {
       printf("\n p%d\t %d\t\t %d\t %d\t\t%d",y[p],at_x[p],bt_x[p],tat_x[p],wt_x[p]);
   }
      printf("\n average of tat: %f",tat_a);
      printf("\n\n average of wt: %f",wt_a);
}
