disease trainChildishDisease(float data[ROW][COLUMN], metadata meta,
                             const int trainingStartRow, const int trainingEndRow)
{
    float haveChildDiseaseNormal = ALPHA, noChildDiseaseNormal = ALPHA,
          haveChildDiseaseAltered = ALPHA, noChildDiseaseAltered = ALPHA;
    for (int i = trainingStartRow; i < trainingEndRow; i++)
    {
        float val = data[i][2];                /*val is retrieved from feature 3 under column 2*/
        float result = data[i][RESULT_COLUMN]; /*result is retrieved from feature 10 under column 9/result column*/

        /*Given that column 2 is have child disease, and if result is Normal, existence of have child disease is normal will be increment by 1*/
        /*Otherwise if column 2 is have child disease, and result is Altered, existence of have child disease is altered will be increment by 1*/
        if (val == HAVE_CHILD_DISEASE)
        {
            if (result == NORMAL)
            {
                haveChildDiseaseNormal++;
            }
            else
            {
                haveChildDiseaseAltered++;
            }
        }
        /*Given that column 2 is no child disease, and if result is Normal, existence of no child disease is normal will be increment by 1*/
        /*Otherwise if column 2 is no child disease, and result is Altered, existence of no child disease is altered will be increment by 1*/
        else if (val == NO_CHILD_DISEASE)
        {
            if (result == NORMAL)
            {
                noChildDiseaseNormal++;
            }
            else
            {
                noChildDiseaseAltered++;
            }
        }
    }

    /*Once all rows have been checked for feature 3 (column 2) output the number of normal & altered data using the 2 values*/
    float numOfNormalData = meta.numOfNormalData + 2;
    float numOfAlteredData = meta.numOfAlteredData + 2;

    /*To get the individual values:
       1) have child disease & Normal semen diagnosis
       2) have child disease & Altered semen diagnosis
       3) no child disease & Normal semen diagnosis
       4) no child disease & Altered semen diagnosis*/
    haveChildDiseaseNormal /= numOfNormalData;   /*To find out the how many have child disease is normal by dividing by the total number of normal data*/
    haveChildDiseaseAltered /= numOfAlteredData; /*To find out the how many have child disease is altered by dividing by the total number of altered data*/
    noChildDiseaseNormal /= numOfNormalData;     /*To find out the how many do not have child disease is normal by dividing by the total number of normal data*/
    noChildDiseaseAltered /= numOfNormalData;    /*To find out the how many do not have child disease is altered by dividing by the total number of altered data*/

    /*to return the result for "have child disease" or "no child disease" if normal or altered semen diagnosis*/

    disease result = {haveChildDiseaseNormal,
                      noChildDiseaseNormal,
                      haveChildDiseaseAltered,
                      noChildDiseaseAltered};
    return result;
}
