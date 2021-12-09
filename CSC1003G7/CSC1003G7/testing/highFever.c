void testHighFever(float feverValue, highFever probs, float *normalResult, float *alteredResult)
{
    if (feverValue == FEVER_LESS_3_MTHS)
    {
        *normalResult *= probs.haveFeverLess3MthsNormal;
        *alteredResult *= probs.haveFeverLess3MthsAltered;
    }
    else if (feverValue == FEVER_MORE_3_MTHS)
    {
        *normalResult *= probs.haveFeverMore3MthsNormal;
        *alteredResult *= probs.haveFeverMore3MthsAltered;
    }
    else if (feverValue == NO_FEVER)
    {
        *normalResult *= probs.noFeverNormal;
        *alteredResult *= probs.noFeverAltered;
    }
}
