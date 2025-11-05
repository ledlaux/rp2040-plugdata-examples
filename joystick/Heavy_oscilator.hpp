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
#include "HvControlIf.h"
#include "HvControlPack.h"
#include "HvControlVar.h"
#include "HvControlCast.h"
#include "HvControlDelay.h"
#include "HvControlSystem.h"
#include "HvControlUnop.h"
#include "HvControlBinop.h"

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
  static void cCast_3HC5szNx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_wbSKx9ZS_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_6cIMZZ5c_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ueDKGkJ4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7TdoLQ7A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_bUo8Q6QH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sT96zeuw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_YxaBwyvH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_eI0Ykmen_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_zJypmdxN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_lXOJ5ZUO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mdByKKRN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_a02DMVPr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_jGw6VDkp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_hwKAbXgU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_52M7NFGt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_AdSzTRhI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_TCYXGYRk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fwV6ds5O_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_F0cQE6MN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_CX6VZlEs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_F3y1nbfk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_4J7hujSU_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_4HIsnHVk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_WE2bvR61_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ImcBbEQb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_0xeoKUvP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_3wExzgq0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_0s2rY33x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MfZWY3tB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9kzv8zlw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qWUGInOO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_gmoMKC4V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_3J10EMpg_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_MVkbGniV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_DrswzZRK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_xlPRIqnr_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_EVadOW7z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_LjELob1Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_x9tu2yin_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_NiEls56W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_PCRw88Z1_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_OJGQ8E0a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_qPdSy9Kp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_nkRb1GIH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_bNitOecK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_NYHvxHMT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_xC4L0naM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KtnLutqa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JEWaGsW2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RGtLDEyO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fGvjlESN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HbKRtZKT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_A2PZYQOp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xMUEwIQd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_oT2Z9CKx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jaTeGc6l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LSVBZjVK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_euxzMNWi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ApnhOF1D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_fS0M8U2y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Jkoe4rwa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_pWjh1qzs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_V9DV19lR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_CQVZZtWh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hvzhr2Ya_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_u1mr3NYY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_BiZSf1X4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_CG6BxZvf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_el1tPONC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_EkVRLv8a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_07d5AF2e_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_PCgb7WDU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_yVsmMBXk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_PuqT9zas_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UNRufOQl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wT04srut_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mKBqOAmR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_pn4pioqt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xztpUmWv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_0e2qYnMo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_TIi8wsC5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_3vuJD6JQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_RDkVCSvN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JlzizZlh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_1DcVJc5T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_x2fHMBod_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_txE4Clkj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_vNrEELkt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fvL9K3rr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_gbkM7qkt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_g4WnD2jY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_yVZ4Za9F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_UMQ8otJM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_kODPIagP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_7aqpr9GZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_4za479rs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_kxpQNChW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_RZMGPphJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_gzuwevOs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_HgZKMSFL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_BFH0Tyln_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_CwRNl4gv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Yjc58CMa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Aybv68As_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8lUuwXwK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Fvbmv02M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_FfgNerlg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6KYfv0uy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_3G1g5Uh3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_jilUrcfU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_NGelARx1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4vJgNSOu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_SuKAWnsB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0BeH90bh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_KIVxUVat_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JYfB4Hoj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_haweYlc0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_W55j5CUz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_38JtXbxA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_tOGJyI0c_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Yjw1DRW5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_NNoArHGG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_8qCinMwh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_sOloAWjV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_JpwRs5yB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_A1cVKMvm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_C4gvBpPn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RmTkbZLY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_oyqd7S6K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DDLytDSj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Q57uYtzD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_WVlCvUEd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_pInKoDpQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  ControlDelay cDelay_6cIMZZ5c;
  ControlVar cVar_bUo8Q6QH;
  ControlBinop cBinop_sT96zeuw;
  ControlVar cVar_YxaBwyvH;
  ControlIf cIf_lXOJ5ZUO;
  ControlBinop cBinop_mdByKKRN;
  ControlPack cPack_a02DMVPr;
  ControlVar cVar_jGw6VDkp;
  ControlVar cVar_hwKAbXgU;
  ControlBinop cBinop_fwV6ds5O;
  ControlBinop cBinop_F0cQE6MN;
  ControlDelay cDelay_4HIsnHVk;
  ControlVar cVar_3wExzgq0;
  ControlBinop cBinop_MfZWY3tB;
  ControlBinop cBinop_9kzv8zlw;
  ControlBinop cBinop_qWUGInOO;
  ControlVar cVar_gmoMKC4V;
  ControlSlice cSlice_EVadOW7z;
  ControlSlice cSlice_LjELob1Q;
  ControlVar cVar_x9tu2yin;
  ControlVar cVar_NiEls56W;
  ControlVar cVar_qPdSy9Kp;
  ControlVar cVar_nkRb1GIH;
  ControlVar cVar_bNitOecK;
  ControlSlice cSlice_NYHvxHMT;
  ControlSlice cSlice_xC4L0naM;
  ControlBinop cBinop_KtnLutqa;
  ControlBinop cBinop_JEWaGsW2;
  ControlBinop cBinop_RGtLDEyO;
  ControlBinop cBinop_fGvjlESN;
  ControlBinop cBinop_HbKRtZKT;
  ControlBinop cBinop_oT2Z9CKx;
  ControlBinop cBinop_jaTeGc6l;
  ControlBinop cBinop_LSVBZjVK;
  ControlBinop cBinop_euxzMNWi;
  ControlBinop cBinop_hvzhr2Ya;
  ControlBinop cBinop_07d5AF2e;
  ControlBinop cBinop_wT04srut;
  ControlBinop cBinop_mKBqOAmR;
  ControlVar cVar_pn4pioqt;
  ControlBinop cBinop_xztpUmWv;
  ControlVar cVar_0e2qYnMo;
  ControlIf cIf_RDkVCSvN;
  ControlBinop cBinop_JlzizZlh;
  ControlVar cVar_1DcVJc5T;
  ControlIf cIf_vNrEELkt;
  ControlBinop cBinop_fvL9K3rr;
  ControlSlice cSlice_gbkM7qkt;
  ControlSlice cSlice_g4WnD2jY;
  ControlSlice cSlice_yVZ4Za9F;
  ControlIf cIf_UMQ8otJM;
  ControlIf cIf_kODPIagP;
  ControlIf cIf_7aqpr9GZ;
  ControlIf cIf_4za479rs;
  ControlIf cIf_kxpQNChW;
  ControlIf cIf_RZMGPphJ;
  ControlIf cIf_gzuwevOs;
  ControlIf cIf_HgZKMSFL;
  ControlIf cIf_BFH0Tyln;
  ControlVar cVar_CwRNl4gv;
  ControlBinop cBinop_Yjc58CMa;
  ControlBinop cBinop_Aybv68As;
  ControlBinop cBinop_8lUuwXwK;
  ControlBinop cBinop_6KYfv0uy;
  ControlBinop cBinop_3G1g5Uh3;
  ControlBinop cBinop_KIVxUVat;
  ControlBinop cBinop_JYfB4Hoj;
  ControlBinop cBinop_A1cVKMvm;
  ControlBinop cBinop_C4gvBpPn;
  ControlBinop cBinop_RmTkbZLY;
  ControlBinop cBinop_oyqd7S6K;
};

#endif // _HEAVY_CONTEXT_OSCILATOR_HPP_
