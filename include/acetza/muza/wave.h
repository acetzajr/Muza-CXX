#pragma once
typedef struct AzWave
{
  double *samples;
  int sampleRate;
  int channels;
  int frames;
} AzWave;
int AzTimeToFrame (double time, int sampleRate);
double AzFrameToTime (int frame, int sampleRate);
void AzWaveNew (AzWave *wave, double *samples, int frames, int channels,
                int sampleRate);
void AzWaveDuration (AzWave *wave, double duration, int channels,
                     int sampleRate);
void AzWaveFree (AzWave *wave);
