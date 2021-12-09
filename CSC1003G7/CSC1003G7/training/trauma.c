trauma trainTrauma(float data[ROW][COLUMN], metadata meta,
                   const int trainingStartRow, const int trainingEndRow)
{
    float sumOfHaveTraumaNormal = ALPHA, sumOfNoTraumaNormal = ALPHA,
          sumOfHaveTraumaAltered = ALPHA, sumOfNoTraumaAltered = ALPHA;
    for (int i = trainingStartRow; i < trainingEndRow; i++)
    {
        // Retrieve trauma value from data set and store into val array
        float val = data[i][3];

        // Result (Output) : Semen Diagnosis
        float result = data[i][RESULT_COLUMN];

        // Value of 0 and 1 indicates whether user has Trauma [0 = Yes, 1 = No]
        // User has trauma
        if (val == HAVE_TRAUMA)
        {
            // User has trauma before but is normal
            if (result == NORMAL)
                sumOfHaveTraumaNormal++;
            // User has trauma before but is not normal
            else
                sumOfHaveTraumaAltered++;
        }
        // User does not have trauma
        else if (val == NO_TRAUMA)
        {
            // User does not have trauma before but is normal
            if (result == NORMAL)
                sumOfNoTraumaNormal++;
            // User does not have trauma before but is not normal
            else
                sumOfNoTraumaAltered++;
        }
    }
    // Add 2 as there are 2 different answers (yes,no) for normal and altered data
    // due to ALPHA being set to 1
    float numOfNormalData = meta.numOfNormalData + 2;
    float numOfAlteredData = meta.numOfAlteredData + 2;

    float haveTraumaNormal = sumOfHaveTraumaNormal / numOfNormalData;
    float noTraumaNormal = sumOfNoTraumaNormal / numOfNormalData;
    float haveTraumaAltered = sumOfHaveTraumaAltered / numOfAlteredData;
    float noTraumaAltered = sumOfNoTraumaAltered / numOfAlteredData;

    trauma result = {haveTraumaNormal,
                     noTraumaNormal,
                     haveTraumaAltered,
                     noTraumaAltered};
    return result;
}
