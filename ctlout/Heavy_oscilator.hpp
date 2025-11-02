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
#include "HvControlUnop.h"
#include "HvControlVar.h"
#include "HvControlSlice.h"
#include "HvControlBinop.h"
#include "HvControlIf.h"
#include "HvControlPack.h"
#include "HvControlCast.h"

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
  static void cPack_u0ngRtFn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_QcaGdRUU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_aBSjve0W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_CdED32cU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Qv38Muag_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ELGM5mTw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2W0EblFg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_aAK1nozs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_Lx96UEDE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_4RCfWBkq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_pXCKFGJa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DN6bVFo9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DKo3YyXX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6erMLpkC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zytXSzIK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qqbBGBDg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wLymI3SM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_iv0z6e6z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_cmSIv69j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_tTsxbBwu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Rv5kDSLu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_3JkO6qBB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5v7VioBq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_aJ4Bb79j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ZnkmrIma_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_nmvEbbRh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_JwvupV61_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_I6rG8Cqs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_JrUy1jHG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_r8H4XGWN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_b4tsfoNk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_9y2Hg5HY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_VLzrG9PS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_KPJgTC0l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_dbtf5AFD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_lNb4CtXo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_lS5lBuCf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_ol6lAFBk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AIg4coJ3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_5Z5gXLwa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_j2Vdze6n_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_6iokEYUL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_TVgCCwF2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_b59SOKh6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YRWmcwde_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_s73veP4M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_lUvvd4B6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_lIrqArQH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_YsDpsnpF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_yaIMPsaR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_57hpGTAJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VzgLYf46_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uVNvRpVb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_d4LQPydT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_IZ5X8eru_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_6ZhIBjYV_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  ControlPack cPack_u0ngRtFn;
  ControlVar cVar_QcaGdRUU;
  ControlVar cVar_aBSjve0W;
  ControlBinop cBinop_2W0EblFg;
  ControlBinop cBinop_aAK1nozs;
  ControlPack cPack_Lx96UEDE;
  ControlVar cVar_4RCfWBkq;
  ControlBinop cBinop_DN6bVFo9;
  ControlBinop cBinop_DKo3YyXX;
  ControlBinop cBinop_6erMLpkC;
  ControlBinop cBinop_zytXSzIK;
  ControlBinop cBinop_qqbBGBDg;
  ControlBinop cBinop_wLymI3SM;
  ControlPack cPack_cmSIv69j;
  ControlVar cVar_tTsxbBwu;
  ControlVar cVar_Rv5kDSLu;
  ControlBinop cBinop_ZnkmrIma;
  ControlBinop cBinop_nmvEbbRh;
  ControlPack cPack_JwvupV61;
  ControlVar cVar_I6rG8Cqs;
  ControlBinop cBinop_r8H4XGWN;
  ControlBinop cBinop_b4tsfoNk;
  ControlSlice cSlice_9y2Hg5HY;
  ControlSlice cSlice_VLzrG9PS;
  ControlSlice cSlice_KPJgTC0l;
  ControlVar cVar_dbtf5AFD;
  ControlIf cIf_ol6lAFBk;
  ControlBinop cBinop_AIg4coJ3;
  ControlIf cIf_5Z5gXLwa;
  ControlIf cIf_j2Vdze6n;
  ControlIf cIf_6iokEYUL;
  ControlIf cIf_TVgCCwF2;
  ControlBinop cBinop_b59SOKh6;
  ControlBinop cBinop_YRWmcwde;
  ControlBinop cBinop_s73veP4M;
  ControlBinop cBinop_57hpGTAJ;
  ControlBinop cBinop_uVNvRpVb;
};

#endif // _HEAVY_CONTEXT_OSCILATOR_HPP_
