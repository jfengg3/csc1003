#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>
#include "constant.h" // Defined constant
#include "type.h"     // Feature type definitions
#include "training.c"
#include "testing.c"
#include "diagnostic.c"

void readFile(float data[ROW][COLUMN]);
int main()
{
    // Time the program
    clock_t timer;
    timer = clock();

    // Read data file
    float data[ROW][COLUMN];
    readFile(data);

    printf("\n\n1) Training Set (First 90), Testing Set (Last 10)\n");
    const int trainingStartRow1 = 0, trainingEndRow1 = TRAINING_SIZE_1,
              testingStartRow1 = TRAINING_SIZE_1, testingEndRow1 = ROW;
    trainingResults result1 = training(data, trainingStartRow1, trainingEndRow1);
    float error1 = testing(data, result1, testingStartRow1, testingEndRow1);

    printf("\n\n2) Training Set (First 80), Testing Set (Last 20)\n");
    const int trainingStartRow2 = 0, trainingEndRow2 = TRAINING_SIZE_2,
              testingStartRow2 = TRAINING_SIZE_2, testingEndRow2 = ROW;
    trainingResults result2 = training(data, trainingStartRow2, trainingEndRow2);
    float error2 = testing(data, result2, testingStartRow2, testingEndRow2);

    printf("\n\n3) Training Set (First 50), Testing Set (Last 50)\n");
    const int trainingStartRow3 = 0, trainingEndRow3 = TRAINING_SIZE_3,
              testingStartRow3 = TRAINING_SIZE_3, testingEndRow3 = ROW;
    trainingResults result3 = training(data, trainingStartRow3, trainingEndRow3);
    float error3 = testing(data, result3, testingStartRow3, testingEndRow3);

    printf("\n\n3) Training Set (First 30), Testing Set (Last 70)\n");
    const int trainingStartRow4 = 0, trainingEndRow4 = TRAINING_SIZE_4,
              testingStartRow4 = TRAINING_SIZE_4, testingEndRow4 = ROW;
    trainingResults result4 = training(data, trainingStartRow4, trainingEndRow4);
    float error4 = testing(data, result4, testingStartRow4, testingEndRow4);

    // Calculate time taken and print it
    timer = clock() - timer;
    double timerTimeTaken = ((double)timer) / CLOCKS_PER_SEC;
    printf("\nTime taken to complete entire program = %.1f milliseconds\n\n", timerTimeTaken * 1000);

    // Probability of error graph using gnuplot
    int plotX[] = {TRAINING_SIZE_1, TRAINING_SIZE_2, TRAINING_SIZE_3, TRAINING_SIZE_4};
    float plotY[] = {error1, error2, error3, error4};
    FILE *gnuplot = popen("gnuplot -p", "w");
    if (!gnuplot)
    {
        perror("popen");
        exit(EXIT_FAILURE);
    }
    fputs("set xlabel 'Training Size' \n", gnuplot);
    fputs("set ylabel 'Error Rate' \n", gnuplot);
    fputs("set title 'Probability Of Errors' \n", gnuplot);
    fprintf(gnuplot, "plot '-' t 'Error' w lp pt 5\n");
    for (int numOfSet = 0; numOfSet < NUM_OF_SETS; numOfSet++)
        fprintf(gnuplot, "%d %f\n", plotX[numOfSet], plotY[numOfSet]);
    fprintf(gnuplot, "e\n");
    pclose(gnuplot);

    // Diagnostic program
    int diagnosticNum = 1;
    printf("Running diagnostic program...\n");
    while (diagnosticNum >= 1)
    {
        printf("Select diganostic training result set \n");
        printf("1) (90/10) \n2) (80/20) \n3) (50/50).\n4) (30/70)\n");
        printf("Enter number <= 0 to stop this program.\n");
        scanf("%d", &diagnosticNum);
        if (diagnosticNum < 1)
            break;
        if (diagnosticNum == 1)
            diagnostic(result1);
        else if (diagnosticNum == 2)
            diagnostic(result2);
        else if (diagnosticNum == 3)
            diagnostic(result3);
        else
            diagnostic(result4);
    }
    return 0;
}

/*Function used to open the dataset file & extract the features*/
void readFile(float data[ROW][COLUMN])
{
    /*pointer variable of fp (file pointer) pointing to FILE structure*/
    FILE *fp;

    /*opening the file with read privileges*/
    fp = fopen("data.txt", "r");

    /*if file poniter doesn't exists, exit and print message file could not be opened*/
    if (fp == NULL)
    {
        printf("File could not be opened \n");
        exit(1);
    }

    /*ROW is defined as 100 under constant.h*/
    for (int i = 0; i <= ROW; i++)
    {
        /*file is scanned into array for each feature, the count of rows will stop when it reaches 100*/
        fscanf(fp, "%f, %f, %f ,%f, %f, %f, %f ,%f, %f, %f", &data[i][0], &data[i][1], &data[i][2],
               &data[i][3], &data[i][4], &data[i][5], &data[i][6], &data[i][7], &data[i][8], &data[i][9]);
    }
    fclose(fp);
}
