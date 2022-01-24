#pragma once
#include "TFCore.h"


class Detection : public TFCore
{
public:
	Detection();
	~Detection();
	std::vector<std::vector<DetectionResult>> GetDetectionResults(float iouThresh = 0.5, float scoreThresh = 0.25);
	bool GetDetectionResults(DetectionResult** detectionResultArr, int* boxNumArr, float iouThresh = 0.5, float scoreThresh = 0.25);
	bool GetWholeImageDetectionResultsSingleOutput(DetectionResult* arrDetRes, int&, float fIOUThres = 0.5, float fScoreThres = 0.25);
	bool GetWholeImageDetectionResultsDoubleOutput(DetectionResult* arrDetRes, int&, float fIOUThres = 0.5, float fScoreThres = 0.25);

private:
	float CalculateIOU(DetectionResult, DetectionResult);
	void DoNMS(std::vector<DetectionResult>&, float, float, int);
	void ApplyScoreThreshold(std::vector<DetectionResult>&, float);
};