#include <stdio.h>
#define MaxCalcCount 1000 //最大計算回数
#define StdPrecision 1000 //精度

int main(void){

  int n,i,j,k=0;
  int cheakRowsSum;
  double outputValueSum = 0;



  printf("Please input Transition-Probability-Matrix's order(n>=2): n>");
  scanf("%d",&n);

  if(n>=2){
    double imputMatrix[n][n];
    double startValue[n];
    double outputValue[n];
    double rowsSum[n];


    startValue[0] = 1;
    for(i=1;i<n;i++){
      startValue[i] = 0;
    }

    printf("Transition Probability Matrix %d*%d\n",n,n);
    for(i=0;i<n;i++){

      do{
        rowsSum[i]=0;
        printf("Please input Matrix element (%d,1)~(%d,%d) > ",i+1,i+1,n);
        for(j=0;j<n;j++){
          scanf("%lf",&imputMatrix[i][j]);
          rowsSum[i] += imputMatrix[i][j];
        }

        if(rowsSum[i] != 1){
          do{
            printf("\nWarning! Row's sum is not 1.\n");
            printf("1.Input once again\n");
            printf("2.Neglect this message\n");
            printf("Select item (1or2):");
            scanf("%d",&cheakRowsSum);
            printf("\n");
            if(k>=5){
              printf("Error! Exit this program.");
              return 1;
            }
            k++;
          }while(cheakRowsSum != 1 && cheakRowsSum != 2);
        }
      }while(rowsSum[i] != 1 && cheakRowsSum != 2);
    }

    printf("\nyour input is\n");
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
        printf("%f ",imputMatrix[i][j]);
      }
      printf("\n");
    }
    printf("\n");

    for(k=0;k<MaxCalcCount;k++){
      for(i=0;i<n;i++){
        for(j=0;j<n;j++){
          outputValue[i] += startValue[j] * imputMatrix[j][i];
        }
        outputValueSum += outputValue[i];
      }
      printf("%d times output value is {",k+1);
      for(i=0;i<n;i++){
        printf("%f",outputValue[i]);
        if(i != n-1) printf(",");
      }
      printf("}\n");

      if(outputValueSum != 1 ){
        printf("\nError %f\n",outputValueSum);
        break;
      }
      outputValueSum = 0;

      for(i=0;(startValue[i] - outputValue[i])*StdPrecision < 1 && i<n ;i++){}
      if(i == n) break;

      for(i=0;i<n;i++){
        startValue[i] = outputValue[i];
        outputValue[i] = 0;
      }
    }
    if(MaxCalcCount != k && outputValueSum <= 1){
      printf("\noutput value is {");
      for(i=0;i<n;i++){
        printf("%f",outputValue[i]);
        if(i != n-1) printf(",");
      }
      printf("}\n");

      printf("calculation time == %d\n",k+1);
      return 0;
    }else{
      printf("Error Over max calculation times. Prease cheak your input matrix\n");
      return 1;
    }
  }else{
    printf("Error! n must be 2 or more!");
    return 1;
  }
}
