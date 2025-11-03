#include <stdio.h>
int main()
{
int n,i;
int arr[100];
printf("enter mumber of element");
scanf("%d",&n);
printf("enter %d number:" ,n);
for(int i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("you entered:");
for(int i=0;i<n;i++)
{
printf("%d",arr[i]);
}
}
