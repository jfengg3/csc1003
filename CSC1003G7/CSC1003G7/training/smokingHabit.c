smoking trainSmokingHabit(float data[ROW][COLUMN], metadata meta,
                          const int trainingStartRow, const int trainingEndRow)
{
    float sumOfNeverSmokeNormal = ALPHA, sumOfOccasionSmokeNormal = ALPHA,
          sumOfDailySmokeNormal = ALPHA, sumOfNeverSmokeAltered = ALPHA,
          sumOfOccasionSmokeAltered = ALPHA, sumOfDailySmokeAltered = ALPHA;

    for (int i = trainingStartRow; i < trainingEndRow; i++)
    {

        // Retrieve smoking value from data set and store into val array
        float val = data[i][7];
        // Result (Output) : Semen Diagnosis
        float result = data[i][RESULT_COLUMN];

        // Value of -1, 0 and 1 indicates whether user has never smoke,
        // occasionally smoke or smoke daily [-1 = nvr smoke, 0 =
        //  occasionally smoke, 1 = smoke daily]
        // User had fever less than 3 months ago
        if (val == NEVER_SMOKE)
        {
            // User had never smoke but is normal
            if (result == NORMAL)
                sumOfNeverSmokeNormal++;
            // User had never smoke but is not normal
            else
                sumOfNeverSmokeAltered++;
        }
        // User had smoke occasionally
        else if (val == OCCASIONAL_SMOKE)
        {
            // User had smoke occasionally but is normal
            if (result == NORMAL)
                sumOfOccasionSmokeNormal++;
            // User had smoke occasionally but is not normal
            else
                sumOfOccasionSmokeAltered++;
        }
        // User had smoke daily
        else if (val == DAILY_SMOKE)
        {
            // User had smoke daily but is normal
            if (result == NORMAL)
                sumOfDailySmokeNormal++;
            // User had smoke daily but is not normal
            else
                sumOfDailySmokeAltered++;
        }
    }

    // Add 3 as there are 3 different value (-1,0,1) for normal
    // and altered data due to ALPHA being set to 1
    float noOfNormalDataAlpha = meta.numOfNormalData + 3;
    float noOfAlteredDataAlpha = meta.numOfAlteredData + 3;

    float neverSmokeNormal = sumOfNeverSmokeNormal / noOfNormalDataAlpha;
    float occasionSmokeNormal = sumOfOccasionSmokeNormal / noOfNormalDataAlpha;
    float dailySmokeNormal = sumOfDailySmokeNormal / noOfNormalDataAlpha;

    float neverSmokeAltered = sumOfNeverSmokeAltered / noOfAlteredDataAlpha;
    float occasionSmokeAltered = sumOfOccasionSmokeAltered / noOfAlteredDataAlpha;
    float dailySmokeAltered = sumOfDailySmokeAltered / noOfAlteredDataAlpha;

    smoking result = {neverSmokeNormal,
                      occasionSmokeNormal,
                      dailySmokeNormal,
                      neverSmokeAltered,
                      occasionSmokeAltered,
                      dailySmokeAltered};
    return result;
}
