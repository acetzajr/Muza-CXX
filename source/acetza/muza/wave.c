#include "acetza/muza/wave.h"
#include <stdlib.h>
int
AzTimeToFrame (double time, int sampleRate)
{
  return time * sampleRate;
}
double
AzFrameToTime (int frame, int sampleRate)
{
  return (double)frame / sampleRate;
}
void
AzWaveNew (AzWave *wave, double *samples, int frames, int channels,
           int sampleRate)
{
  wave->samples = samples;
  wave->frames = frames;
  wave->channels = channels;
  wave->sampleRate = sampleRate;
}
void
AzWaveDuration (AzWave *wave, double duration, int channels, int sampleRate)
{
  wave->frames = AzTimeToFrame (duration, sampleRate);
  wave->channels = channels;
  wave->sampleRate = sampleRate;
  wave->samples = malloc (sizeof (double) * wave->frames * channels);
}
void
AzWaveFree (AzWave *wave)
{
  free (wave->samples);
}
