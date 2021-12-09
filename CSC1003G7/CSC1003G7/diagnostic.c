void diagnostic(trainingResults trainResult)
{
    printf("Enter the values for the 9 features:\n");
    float age, alcohol, disease, highFever, season,
        sitting, smoking, surgery, trauma;
    printf("1) season 2) age 3) disease 4) trauma 5) surgery ");
    printf("6) highFever 7) alcohol 8) smoking 9) sitting\n");
    scanf("%f %f %f %f %f %f %f %f %f", &season, &age, &disease, &trauma, &surgery,
          &highFever, &alcohol, &smoking, &sitting);

    float normalResult = trainResult.metadata.normalPriorProb,
          alteredResult = trainResult.metadata.alteredPriorProb;

    testSeason(season, trainResult.season, &normalResult, &alteredResult);
    testAge(age, trainResult.age, &normalResult, &alteredResult);
    testChildishDisease(disease, trainResult.disease, &normalResult, &alteredResult);
    testTrauma(trauma, trainResult.trauma, &normalResult, &alteredResult);
    testSurgery(surgery, trainResult.surgery, &normalResult, &alteredResult);
    testHighFever(highFever, trainResult.highFever, &normalResult, &alteredResult);
    testAlcoholConsumption(alcohol, trainResult.alcohol, &normalResult, &alteredResult);
    testSmokingHabit(smoking, trainResult.smoking, &normalResult, &alteredResult);
    testSitting(sitting, trainResult.sitting, &normalResult, &alteredResult);

    if (normalResult > alteredResult)
        printf("Result = Normal\n\n");
    else
        printf("Result = Altered\n\n");
}
