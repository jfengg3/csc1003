
age trainAge(float data[ROW][COLUMN], metadata meta, const int trainingStartRow, const int trainingEndRow)
{
    // Calculate mean of normal and altered age
    float sumOfNormalAge = 0, sumOfAlteredAge = 0;
    for (int i = trainingStartRow; i < trainingEndRow; i++)
    {
        float val = data[i][1];
        float result = data[i][RESULT_COLUMN];
        if (result == NORMAL)
            sumOfNormalAge += val;
        else
            sumOfAlteredAge += val;
    }
    float normalAgeMean = sumOfNormalAge / meta.numOfNormalData;
    float alteredAgeMean = sumOfAlteredAge / meta.numOfAlteredData;

    // calculate variance of normal and altered age
    float sumOfNormalAgeVariance = 0, sumOfAlteredAgeVariance = 0;
    for (int i = trainingStartRow; i < trainingEndRow; i++)
    {
        float val = data[i][1];
        float result = data[i][RESULT_COLUMN];
        if (result == NORMAL)
            sumOfNormalAgeVariance += pow((val - normalAgeMean), 2);
        else
            sumOfAlteredAgeVariance += pow((val - alteredAgeMean), 2);
    }
    float normalAgeVariance = sumOfNormalAgeVariance / (meta.numOfNormalData - 1);
    float alteredAgeVariance = sumOfAlteredAgeVariance / (meta.numOfAlteredData - 1);
    age result = {normalAgeMean, alteredAgeMean, normalAgeVariance, alteredAgeVariance};
    return result;
}
