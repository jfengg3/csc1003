#include "testing/season.c"
#include "testing/age.c"
#include "testing/childishDisease.c"
#include "testing/trauma.c"
#include "testing/surgery.c"
#include "testing/highFever.c"
#include "testing/alcoholConsumption.c"
#include "testing/smokingHabit.c"
#include "testing/sitting.c"

float testing(float data[ROW][COLUMN], trainingResults trainResult,
              const int testingStartRow, const int testingEndRow)
{
    float totalNumOfErrors = 0, totalNumOfTests = testingEndRow - testingStartRow,
          falseNegative = 0, falsePositive = 0,
          trueNegative = 0, truePositive = 0;

    for (int i = testingStartRow; i < testingEndRow; i++)
    {
        // Result for normal and altered altered posterior probability
        float normalResult = trainResult.metadata.normalPriorProb,
              alteredResult = trainResult.metadata.alteredPriorProb;

        float seasonValue = data[i][0], ageValue = data[i][1], childDisease = data[i][2],
              traumaValue = data[i][3], surgeryValue = data[i][4], feverValue = data[i][5],
              alcohol = data[i][6], smoking = data[i][7], sitHrs = data[i][8],
              result = data[i][RESULT_COLUMN];

        // Calculate probability of Y = Normal OR Y = Altered
        // with 9 different features
        testSeason(seasonValue, trainResult.season, &normalResult, &alteredResult);
        testAge(ageValue, trainResult.age, &normalResult, &alteredResult);
        testChildishDisease(childDisease, trainResult.disease, &normalResult, &alteredResult);
        testTrauma(traumaValue, trainResult.trauma, &normalResult, &alteredResult);
        testSurgery(surgeryValue, trainResult.surgery, &normalResult, &alteredResult);
        testHighFever(feverValue, trainResult.highFever, &normalResult, &alteredResult);
        testAlcoholConsumption(alcohol, trainResult.alcohol, &normalResult, &alteredResult);
        testSmokingHabit(smoking, trainResult.smoking, &normalResult, &alteredResult);
        testSitting(sitHrs, trainResult.sitting, &normalResult, &alteredResult);

        // Y = Normal
        if (normalResult > alteredResult)
        {
            if (result == NORMAL)
                truePositive++;
            else
            {
                falsePositive++;
                totalNumOfErrors++;
            }
        }
        // Y = Altered
        else
        {
            if (result == NORMAL)
            {
                falseNegative++;
                totalNumOfErrors++;
            }
            else
            {
                trueNegative++;
            }
        }
    }

    // Check how accurate the classifier is, how many values we predicted correctly
    float accuracy = (truePositive + trueNegative) / totalNumOfTests;

    // Misclassification Rate / Error Rate : how often the prediction is wrong?
    // alternative solution -> float errorRate = 1 - accuracy;
    float probOfError = totalNumOfErrors / totalNumOfTests;

    // Precision : calculates how many times a prediciton is correct out of total prediction
    float precisionPositive = truePositive / (truePositive + falsePositive);
    float precisionNegative = trueNegative / (trueNegative + falseNegative);

    printf("Total predictions by the classifier: %.0f\n", totalNumOfTests);
    printf("Accuracy of the classifier: %.2f\n", accuracy);
    printf("Probability of error = %.2f\n", probOfError);
    printf("Positive precision of the classifier: %.2f\n", isnan(precisionPositive) ? 0 : precisionPositive);
    printf("Negative precision of the classifier: %.2f\n", isnan(precisionNegative) ? 0 : precisionNegative);

    printf("Confusion Matrix table values: \n");
    printf("True Positive = %.0f\nTrue Negative = %.0f\n", truePositive, trueNegative);
    printf("False Positive = %.0f\nFalse Negative = %.0f\n", falsePositive, falseNegative);

    return probOfError;
}

// Gaussain distribution using variance formula
float gaussianDistribution(float value, float variance, float mean)
{
    float fx = 1 / sqrt(2 * M_PI) * exp(-0.5 * pow(((value - mean) / variance), 2));
    return fx;
}
