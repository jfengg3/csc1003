
season trainSeason(float data[ROW][COLUMN], metadata meta, const int start, const int end)
{
    // number of rows that are NORMAL(N) or altered(A) by season
    float winterNormal = ALPHA, springNormal = ALPHA, summerNormal = ALPHA,
          fallNormal = ALPHA, winterAltered = ALPHA, springAltered = ALPHA,
          summerAltered = ALPHA, fallAltered = ALPHA;

    for (int i = start; i < end; i++)
    {
        float val = data[i][0];                /*val is retrieved from feature 1 under column 0*/
        float result = data[i][RESULT_COLUMN]; /*result is retrieved from feature 10 under column 9/result column*/

        /*Given that column 0 is Winter, and if result is Normal, existence of Winter is normal will be increment by 1*/
        /*Otherwise if column 0 is Winter, and result is Altered, existence of Winter is altered will be increment by 1*/
        if (val == WINTER)
        {
            if (result == NORMAL)
            {
                winterNormal++;
            }
            else
            {
                winterAltered++;
            }
        }
        /*Given that column 0 is Spring, and if result is Normal, existence of Spring is normal will be increment by 1*/
        /*Otherwise if column 0 is Spring, and result is Altered, existence of Spring is altered will be increment by 1*/
        else if (val == SPRING)
        {
            if (result == NORMAL)
            {
                springNormal++;
            }
            else
            {
                springAltered++;
            }
        }
        /*Given that column 0 is Summer, and if result is Normal, existence of Summer is normal will be increment by 1*/
        /*Otherwise if column 0 is Summer, and result is Altered, existence of Summer is altered will be increment by 1*/
        else if (val == SUMMER)
        {
            if (result == NORMAL)
            {
                summerNormal++;
            }
            else
            {
                summerAltered++;
            }
        }
        /*Given that column 0 is Fall, and if result is Normal, existence of Fall is normal will be increment by 1*/
        /*Otherwise if column 0 is Fall, and result is Altered, existence of Fall is altered will be increment by 1*/
        else if (val == FALL)
        {
            if (result == NORMAL)
            {
                fallNormal++;
            }
            else
            {
                fallAltered++;
            }
        }
    }

    /*Once all rows have been checked for feature 1 (column 0) output the number of normal & altered data using the 4 values*/
    float numOfNormalData = meta.numOfNormalData + 4;
    float numOfAlteredData = meta.numOfAlteredData + 4;

    /*To get the individual values:
       1) Winter & Normal OR  Winter & Altered semen diagnosis
       2) Spring & Normal OR  Spring & Altered semen diagnosis
       3) Summer & Normal OR  Summer & Altered semen diagnosis
       4) Fall & Normal OR  Fall & Altered semen diagnosis*/
    winterNormal /= numOfNormalData;   /*To find out the how many winter data is normal by dividing by the total number of normal data*/
    winterAltered /= numOfAlteredData; /*To find out the how many winter data is altered by dividing by the total number of altered data*/
    springNormal /= numOfNormalData;   /*To find out the how many spring data is normal by dividing by the total number of normal data*/
    springAltered /= numOfAlteredData; /*To find out the how many spring data is altered by dividing by the total number of altered data*/
    summerNormal /= numOfNormalData;   /*To find out the how many summer data is normal by dividing by the total number of normal data*/
    summerAltered /= numOfAlteredData; /*To find out the how many summer data is altered by dividing by the total number of altered data*/
    fallNormal /= numOfNormalData;     /*To find out the how many fall data is normal by dividing by the total number of normal data*/
    fallAltered /= numOfAlteredData;   /*To find out the how many fall data is altered by dividing by the total number of altered data*/

    /*to return the result for each season if normal or altered semen diagnosis*/
    season result = {winterNormal, springNormal, summerNormal, fallNormal,
                     winterAltered, springAltered, summerAltered, fallAltered};
    return result;
}
