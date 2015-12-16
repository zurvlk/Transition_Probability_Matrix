#include <stdio.h>
#define MaxCalcVal 1000

int main(){

  int i,j,k=0;
  double sum;
  double imputMatrix[4][4];
  double startValue[4] = {1,0,0,0};
  double outputValue[4];

  printf("Transition Pribability Matrix 4*4\n");
  for(i=0;i<4;i++){
    printf("please imput row No.%d\n",i+1);
    scanf("%lf %lf %lf %lf",&imputMatrix[i][0],&imputMatrix[i][1],&imputMatrix[i][2],&imputMatrix[i][3]);
    sum = imputMatrix[i][0]+imputMatrix[i][1]+imputMatrix[i][2]+imputMatrix[i][3];
  }

  printf("your imput is\n");
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      printf("%f ",imputMatrix[i][j]);
    }
    printf("\n");
  }

  for(k=0;k<MaxCalcVal;k++){
    for(i=0;i<4;i++){
      for(j=0;j<4;j++){
        outputValue[i] += startValue[j] * imputMatrix[j][i];
      }
    }

    for(i=0;(startValue[i] - outputValue[i])*1000 < 1 && i<4 ;i++){}
    if(i == 4) break;

    for(i=0;i<4;i++){
      startValue[i] = outputValue[i];
      outputValue[i] = 0;
    }

  }

  if(MaxCalcVal != k){
    printf("outputValue is {%f,%f,%f,%f}\n",outputValue[0],outputValue[1],outputValue[2],outputValue[3]);
    printf("calculation time == %d\n",k+1);
  }else{
    printf("Error Over max calculation times. Prease cheak your imput matrix or max calculation times\n");
  }
}
