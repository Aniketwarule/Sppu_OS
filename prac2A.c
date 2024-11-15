#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

void printarr(int arr[],int n)
{
  for(int i=0;i<n;i++) printf("%d\t",arr[i]);
}

void sortasc(int arr[], int n)
{
  for(int i=0;i<n-1;i++) {
    for(int j=i+1;j<n;j++) {
      if(arr[i]>arr[j]) {
        int temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
      }
    }
  }
}

void sortdsc(int arr[], int n)
{
  for(int i=0;i<n-1;i++) {
    for(int j=i+1;j<n;j++) {
      if(arr[i]<arr[j]) {
        int temp = arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
      }
    }
  }
}

int main()
{
  int n;	
  printf("Enter Size of Array : ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter %d Elements : \n",n);
  for(int i=0;i<n;i++) scanf("%d",&arr[i]);
  int pid = fork();
  
  if(pid<0) printf("Unable to create child\n");
  else if(pid==0)
  {
    printf("\n----------  We are in the Child Process  ----------\n");
    printf("Child process ID : %d\n",getpid());
    printf("Parent process ID : %d\n",getppid());
    printf("Sort in Ascending order : ");
    sortasc(arr,n);
    printarr(arr,n);
  }
  else 
  {
    int status;
    wait(&status);
    printf("\n\n----------  We are in the Parent Process  ----------\n");
    printf("Parent process ID : %d\n",getpid());
    printf("Sort in Descending order : ");
    sortdsc(arr,n);
    printarr(arr,n);
  }
  return 0;
}
