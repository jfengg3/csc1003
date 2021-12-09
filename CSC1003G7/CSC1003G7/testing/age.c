float gaussianDistribution(float value, float variance, float mean);
void testAge(float ageValue, age probs, float *normalResult, float *alteredResult)
{
    *normalResult *= gaussianDistribution(ageValue, probs.normalAgeVariance,
                                          probs.normalAgeMean);
    *alteredResult *= gaussianDistribution(ageValue, probs.alteredAgeVariance,
                                           probs.alteredAgeMean);
}
