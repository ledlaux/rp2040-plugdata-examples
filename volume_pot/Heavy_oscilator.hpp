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
#include "HvSignalPhasor.h"
#include "HvControlSlice.h"
#include "HvSignalVar.h"
#include "HvControlIf.h"
#include "HvControlCast.h"
#include "HvControlUnop.h"
#include "HvMath.h"
#include "HvControlVar.h"
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
  static void cSlice_lKfCvRQo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_fiXu299V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_mzXJPz5u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_WHojksvG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_aqFYB0ZZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_p0ODwrde_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_tr6T9tUR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2rGbN3bF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_MGUx0kTR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_bcI6fNO1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_fH7zvLQ2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_U3lTin03_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_N8L9YBuZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7p2LU1VD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_70haeRay_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_G6WIiaCk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_YAmo2qNy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_lhw6vyzC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_alszoWbi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5v5zKz0I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FL8JRTjH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_evCLvpb7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qd9igj9c_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UnxyonXJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9O86WZ49_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_fbNAxIIl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_vhWg6DoI_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_Yu97DIt0;
  ControlSlice cSlice_lKfCvRQo;
  ControlSlice cSlice_fiXu299V;
  ControlSlice cSlice_mzXJPz5u;
  ControlVar cVar_WHojksvG;
  ControlIf cIf_tr6T9tUR;
  ControlBinop cBinop_2rGbN3bF;
  ControlIf cIf_MGUx0kTR;
  ControlIf cIf_bcI6fNO1;
  ControlIf cIf_fH7zvLQ2;
  ControlIf cIf_U3lTin03;
  ControlBinop cBinop_N8L9YBuZ;
  ControlBinop cBinop_7p2LU1VD;
  ControlBinop cBinop_70haeRay;
  ControlBinop cBinop_5v5zKz0I;
  ControlBinop cBinop_FL8JRTjH;
  ControlBinop cBinop_evCLvpb7;
  ControlBinop cBinop_qd9igj9c;
  ControlBinop cBinop_UnxyonXJ;
};

#endif // _HEAVY_CONTEXT_OSCILATOR_HPP_
