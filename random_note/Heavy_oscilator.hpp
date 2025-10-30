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
#include "HvControlCast.h"
#include "HvControlBinop.h"
#include "HvControlDelay.h"
#include "HvControlRandom.h"
#include "HvControlSlice.h"
#include "HvControlIf.h"
#include "HvControlSystem.h"
#include "HvControlPack.h"
#include "HvControlUnop.h"
#include "HvControlVar.h"

class Heavy_oscilator : public HeavyContext {

 public:
  Heavy_oscilator(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_oscilator();

  const char *getName() override { return "oscilator"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 0; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cSwitchcase_u48BcOa1_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_qVI2qLFw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_zxWlnbzx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_vOXr3lvm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_XuDizEkF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_5akChfHt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_thb5hv9c_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_pWksGkvP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FhMFlfDh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BNbbwbkD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_Hpu9lGgO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_6HwCaFgb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_XpvOLeDM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1NVR8n6u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_L5azJCpV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_wGhiJtjk_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_ZU3MBtE6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_Q8XtEwAP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_fghBiXcE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_a1zWVM4l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_6UWDLNAc_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_jZmSVXQE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_g8pNLTE5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_VCPStqxY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_bFSJfQyu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_0t2Wjfp5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cDelay_8hpiedtM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_F13i6cdG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_FEoOEkJ1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_In7f1UFC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_pGfO4CcK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4PyDYNNm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fW5MmYWM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_SgypNNMO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_m4Copabz_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_hz6iaous_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_dl90YWPZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_wEthnp8j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Uwqo7FPO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Yd8lLG6a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_gxmuX8pR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_XWHrq8uK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ONRGvt8O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_eWbuJ1hW_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  ControlDelay cDelay_qVI2qLFw;
  ControlVar cVar_5akChfHt;
  ControlBinop cBinop_pWksGkvP;
  ControlBinop cBinop_FhMFlfDh;
  ControlBinop cBinop_BNbbwbkD;
  ControlPack cPack_Hpu9lGgO;
  ControlVar cVar_6HwCaFgb;
  ControlBinop cBinop_1NVR8n6u;
  ControlBinop cBinop_L5azJCpV;
  ControlBinop cBinop_ZU3MBtE6;
  ControlRandom cRandom_fghBiXcE;
  ControlSlice cSlice_a1zWVM4l;
  ControlBinop cBinop_jZmSVXQE;
  ControlRandom cRandom_VCPStqxY;
  ControlSlice cSlice_bFSJfQyu;
  ControlVar cVar_0t2Wjfp5;
  ControlDelay cDelay_8hpiedtM;
  ControlIf cIf_F13i6cdG;
  ControlVar cVar_FEoOEkJ1;
  ControlVar cVar_In7f1UFC;
  ControlBinop cBinop_4PyDYNNm;
  ControlBinop cBinop_hz6iaous;
  ControlRandom cRandom_wEthnp8j;
  ControlSlice cSlice_Uwqo7FPO;
  ControlBinop cBinop_ONRGvt8O;
};

#endif // _HEAVY_CONTEXT_OSCILATOR_HPP_
