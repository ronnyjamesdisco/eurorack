#ifndef __VOCALIST_H__
#define __VOCALIST_H__

#include "wordlist.h"

#define NUM_VOCALIST_PATCHES NUM_BANKS

#include "sam.h"

#define MODE_NORMAL 0
#define MODE_CRAZY 1
#define MODE_REALLY_CRAZY 2

typedef unsigned short uint16_t;

class Vocalist {
public:
  Vocalist() {

  }

  ~Vocalist() { }

  void init(int sampleRate, int samplesPerBlock);
  void set_shape(int shape);

  void Render(const uint8_t* sync_buffer, int16_t *output, int len);
  void set_gatestate(bool gs);
  void Strike() { }
  // void SetBank(unsigned char b);
  void SetWord(unsigned char b);

  void SetMode(int m) { mode = m; }
  void set_pitch(uint16_t braids_pitch);

  void set_parameters(uint16_t parameter1, uint16_t parameter2);
  
private:
  void Load();

  SAM sam;
  unsigned char mode;
  uint16_t offset;
  unsigned char bank;
  unsigned char word;
  bool gatestate;
  bool risingEdge;
  bool playing;
  const unsigned char *validOffset_;
  unsigned char validOffsetLen_;
};

#endif