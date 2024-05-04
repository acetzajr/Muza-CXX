#include "acetza/muza/wave.h"

#include <stdlib.h>
int AzTimeToFrame(double time, int sampleRate) { return time * sampleRate; }
double AzFrameToTime(int frame, int sampleRate) {
  return (double)frame / sampleRate;
}
void AzWaveNew(AzWave *wave, double *samples, int frames, int channels,
               int sampleRate) {
  wave->samples = samples;
  wave->frames = frames;
  wave->channels = channels;
  wave->sampleRate = sampleRate;
}
void AzWaveWithDuration(AzWave *wave, double duration, int channels,
                        int sampleRate) {
  wave->frames = AzTimeToFrame(duration, sampleRate);
  wave->channels = channels;
  wave->sampleRate = sampleRate;
  wave->samples = malloc(sizeof(double) * wave->frames * channels);
}
void AzWaveWithFrames(AzWave *wave, int frames, int channels, int sampleRate) {
  wave->frames = frames;
  wave->channels = channels;
  wave->sampleRate = sampleRate;
  wave->samples = malloc(sizeof(double) * frames * channels);
}
void AzWaveFree(AzWave *wave) { free(wave->samples); }
int AzWaveIndex(AzWave *wave, int frame, int channel) {
  return frame * wave->channels + channel;
}
double *AzWaveSample(AzWave *wave, int frame, int channel) {
  return &wave->samples[AzWaveIndex(wave, frame, channel)];
}
bool AzWaveEqual(AzWave *wave, AzWave *other) {
  if (wave->sampleRate != other->sampleRate) return false;
  if (wave->channels != other->channels) return false;
  if (wave->frames != other->frames) return false;
  for (int frame = 0; frame < wave->frames; frame++) {
    for (int channel = 0; channel < wave->channels; channel++) {
      double a = *AzWaveSample(wave, frame, channel);
      double b = *AzWaveSample(other, frame, channel);
      if (a != b) return false;
    }
  }
  return true;
}
