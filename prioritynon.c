#include<stdio.h>

void main(){

	int n, temp, arr[10][7],finala[10][10],i,j,k,t;
	printf("Enter number of Process: ");
    scanf("%d",&n);
    for(i=0; i<n; i++){
		printf("Enter Process Id, Arrival Time, Burst Time, Priority:");
		scanf("%d %d %d %d",&arr[i][0],&arr[i][1],&arr[i][2],&arr[i][3]);
	}
	for(i=0; i<n; i++){
		for(j=0; j<n-i-1; j++){
			if(arr[j][1] > arr[j+1][1]){
				for(k=0; k<5; k++){
					temp = arr[j][k];
					arr[j][k] = arr[j+1][k];
					arr[j+1][k] = temp;
				}
			}
		}
	}


	int l=1,m,exec[20][20],flag=0, p,num;
	finala[0][0]=arr[0][0];
	finala[0][1]=arr[0][2];
	j=finala[0][1];
	while(l<n){k=1;p=0;num=0;
        while(arr[k][1]<=j && k<n){
                for(m=0;m<l;m++){
                    if(arr[k][0]==finala[m][0]){
                        flag=1;p--;
                    }
                }
                if(flag==0){
                  exec[p][0]=arr[k][0];
                  exec[p][1]=arr[k][2];
                  exec[p][2]=arr[k][3];
                  num++;
                }
                k++;
                p++;flag=0;
        }

        int x,y,q;
        for(x=0; x<num; x++){
		for(y=0; y<num-x-1; y++){
			if(exec[y][2] > exec[y+1][2]){
				for(q=0; q<3; q++){
					temp = exec[y][q];
					exec[y][q] = exec[y+1][q];
					exec[y+1][q] = temp;
				}
			}
		}
	}
	finala[l][0]=exec[0][0];
	finala[l][1]=exec[0][1]+finala[l-1][1];
	j=finala[l][1];
	l++;

	}
	for( i=0; i<n; i++){
             for(j=0;j<n;j++){
                if(arr[i][0]==finala[j][0]){
                    arr[i][4]=finala[j][1];
                    break;
                }


             }
        arr[i][5]=arr[i][4]-arr[i][1];
        arr[i][6]=arr[i][5]-arr[i][2];
	}
    float totalwait=0,totalturn=0;
	printf("\n_____________________________________________________________________________________________\n");
	printf("Process ID  Arrival Time  Burst Time    Priority    Completion Time   Turnaround Time  Waiting Time\n");
	printf("_____________________________________________________________________________________________\n");
	for( i=0; i<n; i++){
		printf("\n%d \t\t%d \t\t%d \t\t%d \t\t%d\t\t%d\t\t%d\t\t\n", arr[i][0],arr[i][1],arr[i][2],arr[i][3],arr[i][4],arr[i][5],arr[i][6]);
		totalwait=totalwait+arr[i][6];
		totalturn=totalturn+arr[i][5];
	}
	printf("\n\nGhantt Chart\n\n");
	for( i=0; i<n; i++){
		printf("| P%d",finala[i][0]);
	}
	printf("|\n0 ");
	for( i=0; i<n; i++){
		printf(" %d ",finala[i][1]);
	}
	printf(" \n");
	printf("\nAverage Waiting Time: %f\n", totalwait/n);
	printf("Average Turnaround Time: %f\n\n", totalturn/n);

}
