#ifndef _PCM_H_INCLUDED
#define _PCM_H_INCLUDED

#include <Arduino.h>
#include "utility/PCMDoubleBuffer.h"

class PCMClass
{
public:
	PCMClass(int inputPin, int dmaCh);
	virtual ~PCMClass();

	int begin(int channels, long sampleRate);
	void end();

	virtual int available();
	virtual int read(void* buffer, size_t size);

	void onReceive(void(*)(void));

	void setGain(int gain);
	void setBufferSize(int bufferSize);

	// private:
	void IrqHandler();

private:
	int _inputPin;
	int _dmaCh;
	int _intno;
	volatile struct st_dmac1 *_DMACm;

	int _channels;

	PCMDoubleBuffer _doubleBuffer;

	void (*_onReceive)(void);
};

extern PCMClass PCM;

#endif
