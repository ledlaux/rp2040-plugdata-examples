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
#include "HvSignalVar.h"
#include "HvSignalLine.h"
#include "HvSignalPhasor.h"
#include "HvControlBinop.h"
#include "HvControlPack.h"
#include "HvMath.h"

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
  static void cBinop_cg41Gqtk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EY1P2A0h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0VLYRrNB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jbsCUpDe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_rDmePiEP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UFTbQk4B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Zqp7mc1z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uxnxImgN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gjxC5qYg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_SpWF8eJU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_IIa5NYth_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_DgzAooSE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_O4vPlpgh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_pM8u4mPU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_QSKsPuuX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_dSJpyJCQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BqIeQUK6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xU94TP7F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_IVttf39Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YwPC1pWg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ILAD9ncV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_T6nQn2kH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_0VGYP0EB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_luQJsZ7E_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kDj9wEAm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iUpPv6O6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tHplGilX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Y4fyvnIz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_gEKC9bKb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Gd8WC6sw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_OPSY8lkQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_AFbBnTYv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_vCu2Cusd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_Ls1wcijM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_HTZM58Y9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_glXvntLP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_WMG6yV4g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_r8vNMfwD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qtxz2QWv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fAbtnOoW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_buBSmkWC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bQsCFJxC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YOQnQo5E_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yDbGEGkO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_S0fIdlZu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_wjpK1801_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_TJs1JUUV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_zx5shqUg_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_XtuDQoQB;
  SignalLine sLine_WAOmmqA7;
  SignalPhasor sPhasor_BZfVAUWz;
  SignalLine sLine_SyL3HYU6;
  SignalPhasor sPhasor_mx1uxoa3;
  SignalLine sLine_b4gt287u;
  SignalPhasor sPhasor_ZEJEPzFH;
  SignalLine sLine_D881Bpvt;
  ControlBinop cBinop_cg41Gqtk;
  ControlBinop cBinop_EY1P2A0h;
  ControlBinop cBinop_0VLYRrNB;
  ControlBinop cBinop_jbsCUpDe;
  ControlBinop cBinop_UFTbQk4B;
  ControlBinop cBinop_Zqp7mc1z;
  ControlBinop cBinop_uxnxImgN;
  ControlBinop cBinop_gjxC5qYg;
  ControlSlice cSlice_IIa5NYth;
  ControlSlice cSlice_DgzAooSE;
  ControlSlice cSlice_O4vPlpgh;
  ControlSlice cSlice_pM8u4mPU;
  ControlSlice cSlice_QSKsPuuX;
  ControlSlice cSlice_dSJpyJCQ;
  ControlBinop cBinop_BqIeQUK6;
  ControlBinop cBinop_xU94TP7F;
  ControlBinop cBinop_IVttf39Q;
  ControlBinop cBinop_YwPC1pWg;
  ControlSlice cSlice_T6nQn2kH;
  ControlSlice cSlice_0VGYP0EB;
  ControlSlice cSlice_luQJsZ7E;
  ControlBinop cBinop_kDj9wEAm;
  ControlBinop cBinop_iUpPv6O6;
  ControlBinop cBinop_tHplGilX;
  ControlBinop cBinop_Y4fyvnIz;
  ControlSlice cSlice_Gd8WC6sw;
  ControlSlice cSlice_OPSY8lkQ;
  ControlSlice cSlice_AFbBnTYv;
  ControlPack cPack_vCu2Cusd;
  ControlPack cPack_Ls1wcijM;
  ControlPack cPack_HTZM58Y9;
  ControlPack cPack_glXvntLP;
  ControlBinop cBinop_WMG6yV4g;
  ControlBinop cBinop_r8vNMfwD;
  ControlBinop cBinop_qtxz2QWv;
  ControlBinop cBinop_fAbtnOoW;
  ControlBinop cBinop_buBSmkWC;
  ControlBinop cBinop_bQsCFJxC;
  ControlBinop cBinop_YOQnQo5E;
  ControlBinop cBinop_yDbGEGkO;
};

#endif // _HEAVY_CONTEXT_OSCILATOR_HPP_
