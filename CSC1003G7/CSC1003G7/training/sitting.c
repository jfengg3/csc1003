sitting trainSitting(float data[ROW][COLUMN], metadata meta,
                     const int trainingStartRow, const int trainingEndRow)
{
    float sumOfNormalHrs = 0, sumOfAlteredHrs = 0;
    for (int i = trainingStartRow; i < trainingEndRow; i++)
    {
        float val = data[i][8];
        float result = data[i][RESULT_COLUMN];
        if (result == NORMAL)
            sumOfNormalHrs += val;
        else
            sumOfAlteredHrs += val;
    }
    float normalHrsMean = sumOfNormalHrs / meta.numOfNormalData;
    float alteredHrsMean = sumOfAlteredHrs / meta.numOfAlteredData;

    // calculate variance of normal and altered hours
    float sumOfNormalHrsVariance = 0, sumOfAlteredHrsVariance = 0;
    for (int i = trainingStartRow; i < trainingEndRow; i++)
    {
        float val = data[i][1];
        float result = data[i][RESULT_COLUMN];
        if (result == NORMAL)
            sumOfNormalHrsVariance += pow((val - normalHrsMean), 2);
        else
            sumOfAlteredHrsVariance += pow((val - alteredHrsMean), 2);
    }
    float normalHrsVariance = sumOfNormalHrsVariance / (meta.numOfNormalData - 1);
    float alteredHrsVariance = sumOfAlteredHrsVariance / (meta.numOfAlteredData - 1);

    sitting result = {normalHrsMean, alteredHrsMean,
                      normalHrsVariance, alteredHrsVariance};
    return result;
}
