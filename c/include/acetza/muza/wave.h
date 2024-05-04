#pragma once
#include <stdbool.h>
typedef struct AzWave {
  double *samples;
  int sampleRate;
  int channels;
  int frames;
} AzWave;
int AzTimeToFrame(double time, int sampleRate);
double AzFrameToTime(int frame, int sampleRate);
void AzWaveNew(AzWave *wave, double *samples, int frames, int channels,
               int sampleRate);
void AzWaveWithDuration(AzWave *wave, double duration, int channels,
                        int sampleRate);
void AzWaveWithFrames(AzWave *wave, int frames, int channels, int sampleRate);
void AzWaveFree(AzWave *wave);
int AzWaveIndex(AzWave *wave, int frame, int channel);
double *AzWaveSample(AzWave *wave, int frame, int channel);
void AzWaveSave(AzWave *wave, const char *path);
void AzWaveLoad(AzWave *wave, const char *path);
void AzWavePrint(AzWave *wave, const char *path);
bool AzWaveEqual(AzWave *wave, AzWave *other);
