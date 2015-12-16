#include <stdio.h>

int main(){
  int i,j,k,l=0;
  double imputMatrix[4][4];
  double startValue[4] = {1,0,0,0};
  double outputValue[4];

  printf("Please imput 4*4 transition probability matrix\n");
  
  for(i=0;i<4;i++){
    printf("please imput row No.%d\n",i+1);
    scanf("%lf %lf %lf %lf",&imputMatrix[i][0],&imputMatrix[i][1],&imputMatrix[i][2],&imputMatrix[i][3]);
  }
  printf("max calculation times >");
  scanf("%d",&k);

  printf("your imput is\n");
  for(i=0;i<4;i++){
    printf("%f %f %f %f\n",imputMatrix[i][0],imputMatrix[i][1],imputMatrix[i][2],imputMatrix[i][3]);
  }


  while(1){
    for(i=0;i<4;i++){
      for(j=0;j<4;j++){
        outputValue[i] += startValue[j] * imputMatrix[j][i];
      }
    }

    if((startValue[0] - outputValue[0])*1000 < 1){
      if((startValue[1] - outputValue[1])*1000 < 1){
        if((startValue[2] - outputValue[2])*1000 < 1){
          if((startValue[3] - outputValue[3])*1000 < 1){
            break;
          }
        }
      }
    }

    for(i=0;i<4;i++){
      startValue[i] = outputValue[i];
      outputValue[i] = 0;
    }


    l++;
    if(l == k) break;

  }

  if(l != k){
    printf("outputValue is {%f,%f,%f,%f}\n",outputValue[0],outputValue[1],outputValue[2],outputValue[3]);
    printf("calculation time == %d\n",l);
  }else{
    printf("Error Over max calculation times. Prease cheak your imput matrix or max calculation times\n");
  }
}
