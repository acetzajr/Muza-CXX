#pragma once
#include "acetza/muza/primitives.h"
#include "acetza/muza/wave.h"
typedef struct AzBasic {
  AzPrimitive primitive;
  double duration;
  double frequency;
  double amplitude;
  int channels;
  int sampleRate;
} AzBasic;
extern const AzBasic AzBasicDefaults;
void AzBasicNew(AzBasic *basic, AzPrimitive primitive, double duration,
                double frequency, double amplitude, int channels,
                int sampleRate);
void AzBasicDefault(AzBasic *basic);
void AzBasicWave(AzBasic *basic, AzWave *wave);
