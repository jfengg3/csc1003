void testAlcoholConsumption(float value, alcohol probs, float *normalResult, float *alteredResult)
{
    if (value == DRINK_SERVERAL_A_DAY)
    {
        *normalResult *= probs.drinkServeralADayNormal;
        *alteredResult *= probs.drinkServeralADayAltered;
    }
    else if (value == DRINK_EVERY_DAY)
    {
        *normalResult *= probs.drinkADayNormal;
        *alteredResult *= probs.drinkADayAltered;
    }
    else if (value == DRINK_SERVERAL_A_WEEK)
    {
        *normalResult *= probs.drinkServeralAWeekNormal;
        *alteredResult *= probs.drinkServeralAWeekAltered;
    }
    else if (value == DRINK_EVERY_WEEK)
    {
        *normalResult *= probs.drinkAWeekNormal;
        *alteredResult *= probs.drinkAWeekAltered;
    }
    else if (value == HARDLY_DRINK)
    {
        *normalResult *= probs.drinkHardlyNormal;
        *alteredResult *= probs.drinkHardlyAltered;
    }
}
