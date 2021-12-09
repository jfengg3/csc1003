void testSurgery(float surgeryValue, surgery probs, float *normalResult, float *alteredResult)
{
    if (surgeryValue == HAVE_SURGERY)
    {
        *normalResult *= probs.haveSurgeryNormal;
        *alteredResult *= probs.haveSurgeryAltered;
    }
    else if (surgeryValue == NO_SURGERY)
    {
        *normalResult *= probs.noSurgeryNormal;
        *alteredResult *= probs.noSurgeryAltered;
    }
}
