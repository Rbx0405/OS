#include<stdio.h>
struct process {
int pid;
int burst;
};
void sort(struct process p[],int n){
for(int i=0;i<n-1;i++){
for(int j=i+1;j<n;j++){
if(p[i].burst>p[j].burst){
struct process temp = p[i];
p[i]=p[j];
p[j]=temp;
}
}
}
}
void sjf(struct process p[],int n){
int wt=0,tat=0;
float avg_wt,avg_tat;
sort(p,n);
printf("pid\t\bt\twt\ttat\n");
for(int i=0;i<n;i++){
printf("%d\t%d\t%d\t%d\n",p[i].pid,p[i].burst,wt,wt+p[i].burst);
avg_wt += wt;
wt += p[i].burst;
avg_tat += wt;
}
printf("Average wt=%f",(float)avg_wt/n);
printf("Average tat=%f",(float)avg_tat/n);
}
int main(){
int n;
printf("enter the number of process");
scanf("%d",&n);
struct process p[n];
for(int i=0;i<n;i++){
printf("burst time:");
scanf("%d",&p[i].burst);
p[i].pid=i+1;
}
sjf(p,n);
return 0;
}
