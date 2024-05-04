#include "acetza/muza/wavers/basic.h"

#include <math.h>
#include <stdio.h>
const AzBasic AzBasicDefaults = {.primitive = AzSin,
                                 .duration = 1.0,
                                 .frequency = 360.0,
                                 .amplitude = 1.0,
                                 .channels = 2,
                                 .sampleRate = 44100};
void AzBasicNew(AzBasic *basic, AzPrimitive primitive, double duration,
                double frequency, double amplitude, int channels,
                int sampleRate) {
  basic->primitive = primitive;
  basic->duration = duration;
  basic->frequency = frequency;
  basic->amplitude = amplitude;
  basic->channels = channels;
  basic->sampleRate = sampleRate;
}
void AzBasicDefault(AzBasic *basic) {
  AzBasicNew(basic, AzBasicDefaults.primitive, AzBasicDefaults.duration,
             AzBasicDefaults.frequency, AzBasicDefaults.amplitude,
             AzBasicDefaults.channels, AzBasicDefaults.sampleRate);
}
void AzBasicWave(AzBasic *basic, AzWave *wave) {
  AzWaveWithDuration(wave, basic->duration, basic->channels, basic->sampleRate);
  for (int frame = 0; frame < wave->frames; frame++) {
    double time = AzFrameToTime(frame, wave->sampleRate);
    double x = fmod(time * basic->frequency, 1.0);
    double sample = basic->primitive(x) * basic->amplitude;
    // printf ("%lf, %lf, %lf\n", time, x, sample);
    for (int channel = 0; channel < wave->channels; channel++) {
      double *ptr = AzWaveSample(wave, frame, channel);
      *ptr = sample;
    }
  }
}
