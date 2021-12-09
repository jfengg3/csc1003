/*Testing Feature 1 (Season of analysis (Winter, Spring, Summer, Fall))*/
void testSeason(float seasonValue, season probs,
                float *normalResult, float *alteredResult)
{
    /*if season is Winter, get the probability that Winter is Normal OR Altered*/
    if (seasonValue == WINTER)
    {
        *normalResult *= probs.winterNormal;
        *alteredResult *= probs.winterAltered;
    }
    /*if season is Spring, get the probability that Spring is Normal OR Altered*/
    else if (seasonValue == SPRING)
    {
        *normalResult *= probs.springNormal;
        *alteredResult *= probs.springAltered;
    }
    /*if season is Summer, get the probability that Summer is Normal OR Altered*/
    else if (seasonValue == SUMMER)
    {
        *normalResult *= probs.summerNormal;
        *alteredResult *= probs.summerAltered;
    }
    /*if season is Fall, get the probability that Fall is Normal OR Altered*/
    else if (seasonValue == FALL)
    {
        *normalResult *= probs.fallNormal;
        *alteredResult *= probs.fallAltered;
    }
}
