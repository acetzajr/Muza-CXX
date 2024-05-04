#include <stdio.h>

#include "acetza/assert.h"
#include "acetza/muza/wave.h"
#include "acetza/muza/wavers/basic.h"
int main() {
  AzBasic basic;
  AzBasicDefault(&basic);
  AzWave wave;
  AzBasicWave(&basic, &wave);
  AzWaveSave(&wave, "tmp/wave.wav");
  AzWavePrint(&wave, "tmp/wave.txt");
  AzWave load;
  AzWaveLoad(&load, "tmp/wave.wav");
  AzWaveSave(&load, "tmp/load.wav");
  AzWavePrint(&load, "tmp/load.txt");
  //*AzWaveSample (&load, 0, 0) = 1.0;
  printf("Equal waves: %s\n", AzWaveEqual(&wave, &load) ? "true" : "false");
  AzWaveFree(&wave);
  AzWaveFree(&load);
}
int main0x0() {
  AzBasic basic;
  AzBasicDefault(&basic);
  AzWave wave;
  AzBasicWave(&basic, &wave);
  AzWaveSave(&wave, "tmp/wave.wav");
  AzWaveFree(&wave);
}
