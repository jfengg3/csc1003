typedef struct Metadata
{
    float numOfNormalData;
    float numOfAlteredData;
    float normalPriorProb;
    float alteredPriorProb;
} metadata;

typedef struct Season
{
    float winterNormal;
    float springNormal;
    float summerNormal;
    float fallNormal;
    float winterAltered;
    float springAltered;
    float summerAltered;
    float fallAltered;
} season;

typedef struct Age
{
    float normalAgeMean;
    float alteredAgeMean;
    float normalAgeVariance;
    float alteredAgeVariance;
} age;

typedef struct Disease
{
    float haveChildDiseaseNormal;
    float noChildDiseaseNormal;
    float haveChildDiseaseAltered;
    float noChildDiseaseAltered;
} disease;

typedef struct Trauma
{
    float haveTraumaNormal;
    float noTraumaNormal;
    float haveTraumaAltered;
    float noTraumaAltered;
} trauma;

typedef struct Surgery
{
    float haveSurgeryNormal;
    float noSurgeryNormal;
    float haveSurgeryAltered;
    float noSurgeryAltered;
} surgery;

typedef struct HighFever
{
    float haveFeverLess3MthsNormal;
    float haveFeverMore3MthsNormal;
    float noFeverNormal;
    float haveFeverLess3MthsAltered;
    float haveFeverMore3MthsAltered;
    float noFeverAltered;
} highFever;

typedef struct AlcoholConsumption
{
    float drinkServeralADayNormal;
    float drinkADayNormal;
    float drinkServeralAWeekNormal;
    float drinkAWeekNormal;
    float drinkHardlyNormal;
    float drinkServeralADayAltered;
    float drinkADayAltered;
    float drinkServeralAWeekAltered;
    float drinkAWeekAltered;
    float drinkHardlyAltered;
} alcohol;

typedef struct SmokingHabit
{
    float neverSmokeNormal;
    float occasionSmokeNormal;
    float dailySmokeNormal;
    float neverSmokeAltered;
    float occasionSmokeAltered;
    float dailySmokeAltered;
} smoking;

typedef struct Sitting
{
    float normalHrsMean;
    float alteredHrsMean;
    float normalHrsVariance;
    float alteredHrsVariance;
} sitting;

typedef struct TrainingResults
{
    metadata metadata;
    season season;
    age age;
    disease disease;
    trauma trauma;
    surgery surgery;
    highFever highFever;
    alcohol alcohol;
    smoking smoking;
    sitting sitting;
} trainingResults;
