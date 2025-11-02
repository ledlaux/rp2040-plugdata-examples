/**
 * Copyright (c) 2025 Enzien Audio, Ltd.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the phrase "powered by heavy",
 *    the heavy logo, and a hyperlink to https://enzienaudio.com, all in a visible
 *    form.
 * 
 *   2.1 If the Application is distributed in a store system (for example,
 *       the Apple "App Store" or "Google Play"), the phrase "powered by heavy"
 *       shall be included in the app description or the copyright text as well as
 *       the in the app itself. The heavy logo will shall be visible in the app
 *       itself as well.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef _HEAVY_CONTEXT_OSCILATOR_HPP_
#define _HEAVY_CONTEXT_OSCILATOR_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvMath.h"
#include "HvSignalPhasor.h"
#include "HvSignalVar.h"
#include "HvControlBinop.h"

class Heavy_oscilator : public HeavyContext {

 public:
  Heavy_oscilator(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_oscilator();

  const char *getName() override { return "oscilator"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cBinop_QAYVEJsV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Ak6aEjiJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lyrnYxet_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ahrstHwT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_SYQ0nYxq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_bprOUkM6_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_UlquGfvh;
  ControlBinop cBinop_QAYVEJsV;
  ControlBinop cBinop_Ak6aEjiJ;
  ControlBinop cBinop_lyrnYxet;
  ControlBinop cBinop_ahrstHwT;
};

#endif // _HEAVY_CONTEXT_OSCILATOR_HPP_
