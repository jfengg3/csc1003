float gaussianDistribution(float value, float variance, float mean);
void testSitting(float sitHrs, sitting probs, float *normalResult, float *alteredResult)
{
    *normalResult *= gaussianDistribution(sitHrs, probs.normalHrsVariance,
                                          probs.normalHrsMean);
    *alteredResult *= gaussianDistribution(sitHrs, probs.alteredHrsVariance,
                                           probs.alteredHrsMean);
}
