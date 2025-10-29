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
#include "HvSignalVar.h"
#include "HvControlVar.h"
#include "HvControlBinop.h"
#include "HvMath.h"
#include "HvSignalPhasor.h"
#include "HvControlSlice.h"
#include "HvControlIf.h"
#include "HvControlCast.h"
#include "HvControlUnop.h"

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
  static void cSlice_66sHqFgk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_52Nz8ImW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_EI3LyykQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_q3Htr5Wt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_uzCdSOAI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_Gov2pf34_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_IQe3iwZy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Dcq6cOZB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_XpNmC7WM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_B5e6vxyu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_UUyPWGVP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_3Qwfj41I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Q2A30gVK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GE13W33Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hiFB0E2c_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QULfFwBT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_TJU9d5DE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_sUN60GUp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_POqpuZsZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Ync0n4Z9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hCqE5rex_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1T59bdiM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BOefzlDZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_puB0iSYC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_P9h1IYZA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_v0cNX2VM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_BuKZ700Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_hi9ZL6ia_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_deZl0ZAZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Oypo1Tri_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_3I01IfAM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_DtOaqFK0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_ykA3Or0x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_GOhtmszl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MndSxQUm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_on4M24GN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_V3LWlsPI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_LLpFa3pz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_gBA3bHw8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_GbDyaecG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_JyCDiBJt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_xbO63Eai_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_cTeJ8XGs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_FTrqDZhX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_93Eh0LwW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_oQDixDYY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_kDXLIr6e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_divug7Z8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jl00kaiS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bS6prW85_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zv2Mzoub_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_krInV8n0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_BfOctmHc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bzMFnMCr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_i7BdjWsO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_lu9Lkgce_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5wDckaZC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7IlGBIPE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_OdOUN704_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_VleWRtgj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NEwgn3k5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XrNHH7Lc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_vUW0zHkF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_o1L4MX8J_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_nV4ZrTF6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_25gKwYEQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0cefhfw0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_OfWu3dvw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_QnO7YaMf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_N7iiZFpV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_V6N02HwZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yzNTrQuF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_1P4ZcJ1b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_rfYDlMmS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_LHiH8pq2_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_hUMXaXly;
  ControlSlice cSlice_66sHqFgk;
  ControlSlice cSlice_52Nz8ImW;
  ControlSlice cSlice_EI3LyykQ;
  ControlVar cVar_q3Htr5Wt;
  ControlIf cIf_IQe3iwZy;
  ControlBinop cBinop_Dcq6cOZB;
  ControlIf cIf_XpNmC7WM;
  ControlIf cIf_B5e6vxyu;
  ControlIf cIf_UUyPWGVP;
  ControlIf cIf_3Qwfj41I;
  ControlBinop cBinop_Q2A30gVK;
  ControlBinop cBinop_GE13W33Y;
  ControlBinop cBinop_hiFB0E2c;
  ControlBinop cBinop_Ync0n4Z9;
  ControlBinop cBinop_hCqE5rex;
  ControlBinop cBinop_1T59bdiM;
  ControlBinop cBinop_BOefzlDZ;
  ControlBinop cBinop_puB0iSYC;
  ControlVar cVar_v0cNX2VM;
  ControlIf cIf_deZl0ZAZ;
  ControlBinop cBinop_Oypo1Tri;
  ControlVar cVar_3I01IfAM;
  ControlIf cIf_GOhtmszl;
  ControlBinop cBinop_MndSxQUm;
  ControlSlice cSlice_on4M24GN;
  ControlSlice cSlice_V3LWlsPI;
  ControlSlice cSlice_LLpFa3pz;
  ControlIf cIf_gBA3bHw8;
  ControlIf cIf_GbDyaecG;
  ControlIf cIf_JyCDiBJt;
  ControlIf cIf_xbO63Eai;
  ControlIf cIf_cTeJ8XGs;
  ControlIf cIf_FTrqDZhX;
  ControlIf cIf_93Eh0LwW;
  ControlIf cIf_oQDixDYY;
  ControlIf cIf_kDXLIr6e;
  ControlVar cVar_divug7Z8;
  ControlBinop cBinop_jl00kaiS;
  ControlBinop cBinop_bS6prW85;
  ControlBinop cBinop_zv2Mzoub;
  ControlBinop cBinop_bzMFnMCr;
  ControlBinop cBinop_i7BdjWsO;
  ControlBinop cBinop_NEwgn3k5;
  ControlBinop cBinop_XrNHH7Lc;
  ControlBinop cBinop_yzNTrQuF;
  SignalVarf sVarf_lxQEULKi;
};

#endif // _HEAVY_CONTEXT_OSCILATOR_HPP_
