#include <sndfile.h>
#include <stdio.h>

#include "acetza/assert.h"
#include "acetza/muza/wave.h"
void AzWavePrint(AzWave *wave, const char *path) {
  FILE *file = fopen(path, "w");
  AzAssert(file != NULL, 1, "the file %s could not be opened", path);
  for (int frame = 0; frame < wave->frames; frame++) {
    for (int channel = 0; channel < wave->channels; channel++) {
      fprintf(file, "[%.3lf]", *AzWaveSample(wave, frame, channel));
    }
    fprintf(file, "\n");
  }
  fclose(file);
}
void AzWaveSave(AzWave *wave, const char *path) {
  SF_INFO info;
  info.samplerate = wave->sampleRate;
  info.channels = wave->channels;
  info.format = SF_FORMAT_WAV | SF_FORMAT_DOUBLE;
  SNDFILE *file = sf_open(path, SFM_WRITE, &info);
  AzAssert(file != NULL, 1, "the file %s could not be opened", path);
  sf_writef_double(file, wave->samples, wave->frames);
  sf_close(file);
}
void AzWaveLoad(AzWave *wave, const char *path) {
  SF_INFO info;
  info.format = 0;
  SNDFILE *file = sf_open(path, SFM_READ, &info);
  AzAssert(file != NULL, 1, "the file %s could not be opened", path);
  AzWaveWithFrames(wave, info.frames, info.channels, info.samplerate);
  sf_readf_double(file, wave->samples, wave->frames);
  sf_close(file);
}
