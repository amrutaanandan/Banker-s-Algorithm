#include <stdio.h>

void read(int a[5][5], int rows, int cols);
void safety();
void request_a();
int n,m,i = 0,j = 0,k = 0,ind = 0, flag = 1, flag1, alloc[5][5], max[5][5], finish[10], need[5][5],
work[10],process[10];
int req[10], avail[10], pid, op,flag2 = 0;
void main(){
printf("\nEnter number of resources: ");
scanf("%d", &n);
printf("\nEnter number of processes: ");
scanf("%d", &m);
printf("\nEnter the allocation matrix:\n");
read(alloc, m, n);
printf("\nEnter the MAX matrix:\n");
read(max, m, n);
printf("\nEnter available resources:\n");
for(i = 0; i<n; i++){
scanf("%d", &work[i]);
avail[i] = work[i];
}
for(i = 0; i<m; i++){
for(j = 0; j<n; j++){
need[i][j] = max[i][j] - alloc[i][j];
}
}
for(i = 0; i<m; i++){
finish[i] = 0; //false
}
safety();
if(flag == 1){
do{
printf("\n1-Enter request\n2-Exit\n\n");
scanf("%d", &op);
switch(op){
case 1:{
printf("\n\nEnter request: ");
for(i = 0; i<n; i++)
scanf("%d", &req[i]);

printf("\nEnter pid of requesting process: ");
scanf("%d", &pid);
request_a();
break;
}
case 2:{
printf("\nExited successfully...\n");
break;
}
default:{
printf("\nInvalid input!\n");
break;
}
}
}while(op != 2);
}
}
void read(int a[5][5], int rows, int cols){
for(i = 0; i<rows; i++){
for(j = 0; j<cols; j++){
scanf("%d", &a[i][j]);
}
}
}
void safety(){
flag = 1;
for(i = 0; i<m; i++)
finish[i] = 0;
for(i = 0; i<m; i++){
for(j = 0; j<m; j++){
if(finish[j] == 0){
flag1 = 0;
for(k = 0; k<n; k++){
if(need[j][k] <= work[k]){
flag1 = 1;
}
else{
flag1= 0;
break;
}
}
if(flag1 == 1){
for(k = 0; k<n; k++){
work[k] += alloc[j][k];
}
finish[j] = 1;
process[ind++] = j;
}

}
}
}

for(i = 0; i<m; i++){
if(finish[i] == 0){
flag = 0;
}
}
if(flag == 0){
printf("\nCannot form a safe sequence!\n");
}
else{
printf("\n");
printf("\nThe safe sequence is\n");
for(i = 0; i<m; i++){
if(i == m-1){
printf("P%d ", process[i]);
}
else{
printf("P%d --> ", process[i]);
}
}
printf("\n");
}
}
void request_a(){
flag1 = 0;
for(i = 0; i<n; i++){
if(req[i] <= need[pid][i]){
flag1 = 1;
}
else{
flag1 = 0;
break;
}
}
if(flag1 == 1){
for(i = 0; i<n; i++){
avail[i] = avail[i] - req[i];
alloc[pid][i] = alloc[pid][i] + req[i];
need[pid][i] = need[pid][i] - req[i];
work[i] = avail[i];
}

safety();
}
else{
printf("\nCannot form safe sequence!\n");
}
}
