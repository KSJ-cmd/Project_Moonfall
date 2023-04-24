// Fill out your copyright notice in the Description page of Project Settings.


#include "System/Combat/CombatSystemLibrary.h"

float UCombatSystemLibrary::CalculateProbability_Bernoulli(int NumSuccesses, int NumTrials, float SuccessRate)
{
	// �������� �������� ������ Ȯ�� ���
	float P = SuccessRate;

	// ������ ������ �̿��Ͽ� ���� Ȯ�� ���
	float Posterior = (float)NumSuccesses / (float)NumTrials;
	float Likelihood = powf(P, NumSuccesses) * powf(1 - P, NumTrials - NumSuccesses);
	float Evidence = Likelihood + (1 - Posterior) * powf(1 - P, NumTrials - NumSuccesses);
	return Likelihood / Evidence;
}

float UCombatSystemLibrary::CalculateProbability_EWMA(float Weight, float SuccessRate)
{
	SuccessRate = (1 - Weight) * SuccessRate + Weight * 1.0f; // EWMA ����


	SuccessRate = FMath::Clamp(SuccessRate, 0.0f, SuccessRate * 2.0f); // ���� ����

	return SuccessRate;
}

float UCombatSystemLibrary::CalculateProbability_BinomialDistribution(int32 NumTrials, float Probability, int32 NumSuccesses)
{
    float q = 1.f - Probability;
    float p = Probability;
    float k = (float)NumSuccesses;
    float n = (float)NumTrials;
    float choose = 1.f;
    float sum = 0.f;

    for (int32 i = 0; i <= k; i++)
    {
        sum += choose * powf(p, i) * powf(q, n - i);
        choose *= ((n - i) / (i + 1));
    }

    return sum;
}