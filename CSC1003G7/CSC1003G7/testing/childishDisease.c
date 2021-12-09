/*Testing Feature 3 (Childish Disease (Chicken pox, measles, mumps, polio)*/
void testChildishDisease(float childDisease, disease probs, float *normalResult, float *alteredResult)
{
    /*if child disease is present, get the probability that child disease is Normal OR Altered*/
    if (childDisease == HAVE_CHILD_DISEASE)
    {
        *normalResult *= probs.haveChildDiseaseNormal;
        *alteredResult *= probs.haveChildDiseaseAltered;
    }
    /*if child disease is not present, get the probability that no child disease is Normal OR Altered*/
    else if (childDisease == NO_CHILD_DISEASE)
    {
        *normalResult *= probs.noChildDiseaseNormal;
        *alteredResult *= probs.noChildDiseaseAltered;
    }
}
