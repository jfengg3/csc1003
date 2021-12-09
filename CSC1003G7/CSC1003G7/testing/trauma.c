void testTrauma(float traumaValue, trauma probs, float *normalResult, float *alteredResult)
{
    if (traumaValue == HAVE_TRAUMA)
    {
        *normalResult *= probs.haveTraumaNormal;
        *alteredResult *= probs.haveTraumaAltered;
    }
    else if (traumaValue == NO_TRAUMA)
    {
        *normalResult *= probs.noTraumaNormal;
        *alteredResult *= probs.noTraumaAltered;
    }
}
