
#include "training/season.c"
#include "training/age.c"
#include "training/childishDisease.c"
#include "training/trauma.c"
#include "training/surgery.c"
#include "training/highFever.c"
#include "training/alcoholConsumption.c"
#include "training/smokingHabit.c"
#include "training/sitting.c"

trainingResults training(float data[ROW][COLUMN], const int start, const int end)
{
    // Reset and calculate the number of normal and altered data
    float numOfNormalData = 0, numOfAlteredData = 0;
    for (int i = start; i < end; i++)
    {
        if (data[i][RESULT_COLUMN] == NORMAL)
            numOfNormalData++;
        else
            numOfAlteredData++;
    }
    // Caculate normal and altered prior probability
    int totalNumOfData = end - start;
    float normalPriorProb = numOfNormalData / totalNumOfData;
    float alteredPriorProb = numOfAlteredData / totalNumOfData;

    metadata meta = {numOfNormalData, numOfAlteredData,
                     normalPriorProb, alteredPriorProb};

    // Train with 9 different features
    season seasonProbs = trainSeason(data, meta, start, end);
    age ageProbs = trainAge(data, meta, start, end);
    disease diseaseProbs = trainChildishDisease(data, meta, start, end);
    trauma traumaProbs = trainTrauma(data, meta, start, end);
    surgery surgeryProbs = trainSurgery(data, meta, start, end);
    highFever highFeverProbs = trainHighFever(data, meta, start, end);
    alcohol alcoholProbs = trainAlcoholConsumption(data, meta, start, end);
    smoking smokingProbs = trainSmokingHabit(data, meta, start, end);
    sitting sittingProbs = trainSitting(data, meta, start, end);

    trainingResults result = {
        meta, seasonProbs, ageProbs, diseaseProbs,
        traumaProbs, surgeryProbs, highFeverProbs, alcoholProbs,
        smokingProbs, sittingProbs};

    return result;
}
