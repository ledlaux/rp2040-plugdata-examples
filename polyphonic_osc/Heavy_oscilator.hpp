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
#include "HvControlSlice.h"
#include "HvSignalLine.h"
#include "HvMath.h"
#include "HvControlBinop.h"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"

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
  static void cBinop_2SxooV7V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7IatJ2cB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DP5Slg7j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ImD3nwLV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9q2Gzw2y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gFlNwdX2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MBRMDaMz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Nnoz2Wr4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0R4I2gAi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9lJPLzCD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_RaULzn1U_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_IGbzbdgK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_jBoSt8sj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_JhHevq0l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_3hchOCAD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_h50pdnWK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_i1AF1HBG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_pTmAXeFk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_eR4xofXC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5obX8cHH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_cQLxlyXb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_BWdFrapj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_0XS1VV9t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_6DygiP1l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8tIs6Y0U_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0Cocl6Oq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Z88NIL7E_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Bagliqh7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_tZfuQnZ0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_bxTgN16F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_i5MgmqCH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_YnnGCAAZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QjFq5JT3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AC6Zufch_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_oBd0Xq0L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TQxCjrv0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_iftuMLPX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_jAFPjyNE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_2YIUVkkb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_YO4AerPW_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_tA2PhNXp;
  SignalLine sLine_xsEGYvCy;
  SignalPhasor sPhasor_2eC7Loko;
  SignalLine sLine_tBLTdZBx;
  SignalPhasor sPhasor_Bkaj6EZn;
  SignalLine sLine_79ktEobt;
  SignalPhasor sPhasor_nqdGc7ov;
  SignalLine sLine_Jy5z5trx;
  ControlBinop cBinop_2SxooV7V;
  ControlBinop cBinop_7IatJ2cB;
  ControlBinop cBinop_DP5Slg7j;
  ControlBinop cBinop_ImD3nwLV;
  ControlBinop cBinop_gFlNwdX2;
  ControlBinop cBinop_MBRMDaMz;
  ControlBinop cBinop_Nnoz2Wr4;
  ControlBinop cBinop_0R4I2gAi;
  ControlSlice cSlice_RaULzn1U;
  ControlSlice cSlice_IGbzbdgK;
  ControlSlice cSlice_jBoSt8sj;
  ControlSlice cSlice_JhHevq0l;
  ControlSlice cSlice_3hchOCAD;
  ControlSlice cSlice_h50pdnWK;
  ControlBinop cBinop_i1AF1HBG;
  ControlBinop cBinop_pTmAXeFk;
  ControlBinop cBinop_eR4xofXC;
  ControlBinop cBinop_5obX8cHH;
  ControlSlice cSlice_BWdFrapj;
  ControlSlice cSlice_0XS1VV9t;
  ControlSlice cSlice_6DygiP1l;
  ControlBinop cBinop_8tIs6Y0U;
  ControlBinop cBinop_0Cocl6Oq;
  ControlBinop cBinop_Z88NIL7E;
  ControlBinop cBinop_Bagliqh7;
  ControlSlice cSlice_bxTgN16F;
  ControlSlice cSlice_i5MgmqCH;
  ControlSlice cSlice_YnnGCAAZ;
  ControlBinop cBinop_QjFq5JT3;
  ControlBinop cBinop_AC6Zufch;
  ControlBinop cBinop_oBd0Xq0L;
  ControlBinop cBinop_TQxCjrv0;
};

#endif // _HEAVY_CONTEXT_OSCILATOR_HPP_
