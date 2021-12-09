highFever trainHighFever(float data[ROW][COLUMN], metadata meta,
                         const int trainingStartRow, const int trainingEndRow)
{
    float sumOfHaveFeverLess3MthsNormal = ALPHA, sumOfHaveFeverMore3MthsNormal = ALPHA,
          sumOfNoFeverNormal = ALPHA, sumOfHaveFeverLess3MthsAltered = ALPHA,
          sumOfHaveFeverMore3MthsAltered = ALPHA, sumOfNoFeverAltered = ALPHA;

    for (int i = trainingStartRow; i < trainingEndRow; i++)
    {
        // Retrieve Fever value from data set and store into val array
        float val = data[i][5];
        // Result (Output) : Semen Diagnosis
        float result = data[i][RESULT_COLUMN];

        // Value of -1, 0 and 1 indicates whether user has Fever less or more than three months ago, or no fever at all [-1 = < 3 mths, 0 = > 3 mths, 1 = no fever]
        // User had fever less than 3 months ago
        if (val == FEVER_LESS_3_MTHS)
        {
            // User had fever less than 3 months ago but is normal
            if (result == NORMAL)
                sumOfHaveFeverLess3MthsNormal++;
            // User had fever less than 3 months ago but is not normal
            else
                sumOfHaveFeverLess3MthsAltered++;
        }
        // User had fever more than 3 months ago
        else if (val == FEVER_MORE_3_MTHS)
        {
            // User had fever more than 3 months ago but is normal
            if (result == NORMAL)
                sumOfHaveFeverMore3MthsNormal++;
            // User had fever more than 3 months ago but is not normal
            else
                sumOfHaveFeverMore3MthsAltered++;
        }
        // User had no fever the past 3 months
        else if (val == NO_FEVER)
        {
            // User had no fever but is normal
            if (result == NORMAL)
                sumOfNoFeverNormal++;
            // User had no fever but is not normal
            else
                sumOfNoFeverAltered++;
        }
    }

    // Add 3 as there are 3 different value (-1,0,1) for normal and altered data
    // due to ALPHA being set to 1
    float noOfNormalDataAlpha = meta.numOfNormalData + 3;
    float noOfAlteredDataAlpha = meta.numOfAlteredData + 3;

    float haveFeverLess3MthsNormal = sumOfHaveFeverLess3MthsNormal / noOfNormalDataAlpha;
    float haveFeverMore3MthsNormal = sumOfHaveFeverMore3MthsNormal / noOfNormalDataAlpha;
    float noFeverNormal = sumOfNoFeverNormal / noOfNormalDataAlpha;
    float haveFeverLess3MthsAltered = sumOfHaveFeverLess3MthsAltered / noOfAlteredDataAlpha;
    float haveFeverMore3MthsAltered = sumOfHaveFeverMore3MthsAltered / noOfAlteredDataAlpha;
    float noFeverAltered = sumOfNoFeverAltered / noOfAlteredDataAlpha;

    highFever result = {haveFeverLess3MthsNormal, haveFeverMore3MthsNormal,
                        noFeverNormal, haveFeverLess3MthsAltered,
                        haveFeverMore3MthsAltered, noFeverAltered};
    return result;
}
