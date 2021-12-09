alcohol trainAlcoholConsumption(float data[ROW][COLUMN], metadata meta,
                                const int trainingStartRow, const int trainingEndRow)
{
    float noOfDrinkServeralADayNormal = ALPHA, noDrinkADayNormal = ALPHA,
          noOfDrinkServeralAWeekNormal = ALPHA, noDrinkAWeekNormal = ALPHA,
          noOfDrinkHardlyNormal = ALPHA, noOfDrinkServeralADayAltered = ALPHA,
          noDrinkADayAltered = ALPHA, noOfDrinkServeralAWeekAltered = ALPHA,
          noDrinkAWeekAltered = ALPHA, noOfDrinkHardlyAltered = ALPHA;

    for (int i = trainingStartRow; i < trainingEndRow; i++)
    {

        // Retrieve alcohol value from data set and store into val array
        float val = data[i][6];
        // Result (Output) : Semen Diagnosis
        float result = data[i][RESULT_COLUMN];

        // Value of 0.2, 0.4, 0.6, 0.8 and 1 indicates whether user drinks
        // serveral times a day, everyday, several times a week,
        // once a wk or never [0.2 = sev times a day, 0.4 = everyday,
        // 0.6 = sev times a wk, 0.8 = once a wk and 1 = never drink]
        // User had fever less than 3 months ago
        if (val == DRINK_SERVERAL_A_DAY)
        {
            // User had drink several times a day but is normal
            if (result == NORMAL)
                noOfDrinkServeralADayNormal++;
            // User had drink several times a day but is not normal
            else
                noOfDrinkServeralADayAltered++;
        }
        // User had drinks everyday
        else if (val == DRINK_EVERY_DAY)
        {
            // User had drinks everyday but is normal
            if (result == NORMAL)
                noDrinkADayNormal++;
            // User had drinks everyday but is not normal
            else
                noDrinkADayAltered++;
        }
        // User had drink several times a wk
        else if (val == DRINK_SERVERAL_A_WEEK)
        {
            // User had drink several times a wk but is normal
            if (result == NORMAL)
                noOfDrinkServeralAWeekNormal++;
            // User had drink several times a wk but is not normal
            else
                noOfDrinkServeralAWeekAltered++;
        }
        // User had drink once a wk
        else if (val == DRINK_EVERY_WEEK)
        {
            // User had drink once a wk but is normal
            if (result == NORMAL)
                noDrinkAWeekNormal++;
            // User had drink omce a wk but is not normal
            else
                noDrinkAWeekAltered++;
        }
        // User had never drink at all
        else if (val == HARDLY_DRINK)
        {
            // User had never drink at all but is normal
            if (result == NORMAL)
                noOfDrinkHardlyNormal++;
            // User had never drink at all but is not normal
            else
                noOfDrinkHardlyAltered++;
        }
    }

    // Add 5 as there are 5 different value (0.2,0.4,0.6,0.8,1) for normal
    // and altered data due to ALPHA being set to 1
    float noOfNormalDataAlpha = meta.numOfNormalData + 5;
    float noOfAlteredDataAlpha = meta.numOfAlteredData + 5;

    float drinkServeralADayNormal = noOfDrinkServeralADayNormal / noOfNormalDataAlpha;
    float drinkADayNormal = noDrinkADayNormal / noOfNormalDataAlpha;
    float drinkServeralAWeekNormal = noOfDrinkServeralAWeekNormal / noOfNormalDataAlpha;
    float drinkAWeekNormal = noDrinkAWeekNormal / noOfNormalDataAlpha;
    float drinkHardlyNormal = noOfDrinkHardlyNormal / noOfNormalDataAlpha;

    float drinkServeralADayAltered = noOfDrinkServeralADayAltered / noOfAlteredDataAlpha;
    float drinkADayAltered = noDrinkADayAltered / noOfAlteredDataAlpha;
    float drinkServeralAWeekAltered = noOfDrinkServeralAWeekAltered / noOfAlteredDataAlpha;
    float drinkAWeekAltered = noDrinkAWeekAltered / noOfAlteredDataAlpha;
    float drinkHardlyAltered = noOfDrinkHardlyAltered / noOfAlteredDataAlpha;

    alcohol result = {drinkServeralADayNormal,
                      drinkADayNormal,
                      drinkServeralAWeekNormal,
                      drinkAWeekNormal,
                      drinkHardlyNormal,
                      drinkServeralADayAltered,
                      drinkADayAltered,
                      drinkServeralAWeekAltered,
                      drinkAWeekAltered,
                      drinkHardlyAltered};
    return result;
}
