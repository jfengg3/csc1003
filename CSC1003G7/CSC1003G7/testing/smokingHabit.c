void testSmokingHabit(float value, smoking probs, float *normalResult, float *alteredResult)
{
    if (value == NEVER_SMOKE)
    {
        *normalResult *= probs.neverSmokeNormal;
        *alteredResult *= probs.neverSmokeAltered;
    }
    else if (value == OCCASIONAL_SMOKE)
    {
        *normalResult *= probs.occasionSmokeNormal;
        *alteredResult *= probs.occasionSmokeAltered;
    }
    else if (value == DAILY_SMOKE)
    {
        *normalResult *= probs.dailySmokeNormal;
        *alteredResult *= probs.dailySmokeAltered;
    }
}
