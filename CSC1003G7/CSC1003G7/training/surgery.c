surgery trainSurgery(float data[ROW][COLUMN], metadata meta,
                     const int trainingStartRow, const int trainingEndRow)
{
    float noOfHaveSurgeryNormal = ALPHA, noOfNoSurgeryNormal = ALPHA,
          noOfHaveSurgeryAltered = ALPHA, noOfNoSurgeryAltered = ALPHA;

    for (int i = trainingStartRow; i < trainingEndRow; i++)
    {
        // Retrieve Surgery value from data set and store into val array
        float val = data[i][4];

        // Result (Output) : Semen Diagnosis
        float result = data[i][RESULT_COLUMN];

        // Value of 0 and 1 indicates whether user has Surgery [0 = Yes, 1 = No]
        // User has Surgery
        if (val == HAVE_SURGERY)
        {
            // User has Surgery before but is normal
            if (result == NORMAL)
                noOfHaveSurgeryNormal++;
            // User has Surgery before but is not normal
            else
                noOfHaveSurgeryAltered++;
        }
        // User does not have Surgery
        else if (val == NO_SURGERY)
        {
            // User does not have Surgery before but is normal
            if (result == NORMAL)
                noOfNoSurgeryNormal++;
            // User does not have Surgery before but is not normal
            else
                noOfNoSurgeryAltered++;
        }
    }
    // Add 2 as there are 2 different answers (yes,no) for normal and altered data
    // due to ALPHA being set to 1
    float noOfNormalDataAlpha = meta.numOfNormalData + 2;
    float noOfAlteredDataAlpha = meta.numOfAlteredData + 2;

    float haveSurgeryNormal = noOfHaveSurgeryNormal / noOfNormalDataAlpha;
    float noSurgeryNormal = noOfNoSurgeryNormal / noOfNormalDataAlpha;
    float haveSurgeryAltered = noOfHaveSurgeryAltered / noOfAlteredDataAlpha;
    float noSurgeryAltered = noOfNoSurgeryAltered / noOfAlteredDataAlpha;

    surgery result = {haveSurgeryNormal, noSurgeryNormal,
                      haveSurgeryAltered, noSurgeryAltered};
    return result;
}
