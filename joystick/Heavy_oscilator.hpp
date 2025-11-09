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
#include "HvControlBinop.h"
#include "HvControlPack.h"
#include "HvControlDelay.h"
#include "HvControlSystem.h"
#include "HvControlSlice.h"
#include "HvControlVar.h"
#include "HvControlUnop.h"
#include "HvControlCast.h"
#include "HvControlIf.h"

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
  static void cCast_Pppyj9Wp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_cwvtHNJr_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_ADRIYkcU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_HiIW3WC1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_bcwu65pR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_fxjqNf9g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_15wzJrQr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_zZr3pfAa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_bEYxWuke_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_51mJV9Ur_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_OCSIdUQD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_V1uBgHWe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_pmOWo0AL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_KkNp7KBT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_CROMJxG4_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_xgv2mT3T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UFghpRqI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_v6WwEou0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_K7QXO20W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_rKxWZwrv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_hDAVU9lz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jx7qfSBX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Kf73bCOG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sxqOg1kO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_EFsPvjLy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_oAy4xkFv_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_wla2z7Gx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_TSPvr6Gm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_l0OVPyx3_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_956kD1M7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Lf2M2Axe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_QFwGKWTx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_CxS8E1rz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_W9zEw6um_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_INsfWBqn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_e2QzofsH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_8kq40XDs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_e7voqfOh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_6I7PofHa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_MknGRLfX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_C8CcNc4y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GjJfKUWN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wiyLKsdc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uUL0dK7a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tEPXppmK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_6969VZ7c_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qFXUe27u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bGYSRqtR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bz3TXvws_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wJpTfBOK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CGvoqtIB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ZyuzZ09t_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7mUp2Vkv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_OqKXIvHA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Xvj7mAoU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_cNX8Qh5X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Jfr73jZP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_C9VKzEv2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DBIFlaz3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xLQajHPz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qtKhezmj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_g0ALrrVJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_TPSHxpHu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_uuWlXGq1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KcWBiXKf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qeWubkxd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_J7fTj8xz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_IwOySgoB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lcrlcfaD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2zr8hsDT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_NM1txbBc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_gFnS1MLM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cPack_st09lugV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_z414T7Bz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mTxXNMN7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_PT6v4N35_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_xYsx3bwX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ZGHQQS02_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6fVgXta9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zxUTBVGm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_hZpoTEBK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_R698B7d3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_Dq48wTqZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_46VRmpyo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_oJbHfnVu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_dJiytzPh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_ohkOfrtD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_9qU6Ln7n_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_O7YgepM2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8dFPSoPz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_eTRYqz8h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_IFkQln4R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_Fjg2Hmd1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_70gCMtEC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_Ly1udjZ0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_J4EbceIN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_EhdYlMg1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_wevA2Ty0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_9jBOA7gp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_cjBMuI5L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_zLe9mwQM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_7SdfT2wa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_J0ccA27A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_D7sqgxyN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Xs5zlmbV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_plJFnUXg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_qSY9tPfq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_MbzAxncz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_oGw3bWeJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vsLZWSFf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_0w6byLTl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_a07kVl0h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rF1U4crY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_IFRcUTwD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_lkJUCp9Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VhotNQMP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rh1e2meB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_rlZDIN2p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_8dZ9cZHf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ZS6uVSk8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_TfJv0Boc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_8pI5zDVk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_RcCdhYHe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_FXqItFNM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Wc3Uc2Iw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ur5CKBc3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hhKOlndm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_w6iS2pft_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ksPi80zr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cam4J9fF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZHSDgp1T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_BAlgXfHK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_DMSVNCoZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_KK0VG5yu_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  ControlDelay cDelay_ADRIYkcU;
  ControlVar cVar_fxjqNf9g;
  ControlBinop cBinop_15wzJrQr;
  ControlVar cVar_zZr3pfAa;
  ControlIf cIf_OCSIdUQD;
  ControlBinop cBinop_V1uBgHWe;
  ControlDelay cDelay_xgv2mT3T;
  ControlVar cVar_rKxWZwrv;
  ControlBinop cBinop_jx7qfSBX;
  ControlBinop cBinop_Kf73bCOG;
  ControlBinop cBinop_sxqOg1kO;
  ControlVar cVar_EFsPvjLy;
  ControlSlice cSlice_956kD1M7;
  ControlSlice cSlice_Lf2M2Axe;
  ControlVar cVar_QFwGKWTx;
  ControlVar cVar_CxS8E1rz;
  ControlVar cVar_e2QzofsH;
  ControlVar cVar_8kq40XDs;
  ControlVar cVar_e7voqfOh;
  ControlSlice cSlice_6I7PofHa;
  ControlSlice cSlice_MknGRLfX;
  ControlBinop cBinop_C8CcNc4y;
  ControlBinop cBinop_GjJfKUWN;
  ControlBinop cBinop_wiyLKsdc;
  ControlBinop cBinop_uUL0dK7a;
  ControlBinop cBinop_tEPXppmK;
  ControlBinop cBinop_bGYSRqtR;
  ControlBinop cBinop_bz3TXvws;
  ControlBinop cBinop_wJpTfBOK;
  ControlBinop cBinop_CGvoqtIB;
  ControlBinop cBinop_C9VKzEv2;
  ControlBinop cBinop_uuWlXGq1;
  ControlBinop cBinop_lcrlcfaD;
  ControlBinop cBinop_2zr8hsDT;
  ControlVar cVar_NM1txbBc;
  ControlBinop cBinop_gFnS1MLM;
  ControlPack cPack_st09lugV;
  ControlVar cVar_z414T7Bz;
  ControlVar cVar_mTxXNMN7;
  ControlBinop cBinop_6fVgXta9;
  ControlBinop cBinop_zxUTBVGm;
  ControlVar cVar_hZpoTEBK;
  ControlIf cIf_46VRmpyo;
  ControlBinop cBinop_oJbHfnVu;
  ControlVar cVar_dJiytzPh;
  ControlIf cIf_O7YgepM2;
  ControlBinop cBinop_8dFPSoPz;
  ControlSlice cSlice_eTRYqz8h;
  ControlSlice cSlice_IFkQln4R;
  ControlSlice cSlice_Fjg2Hmd1;
  ControlIf cIf_70gCMtEC;
  ControlIf cIf_Ly1udjZ0;
  ControlIf cIf_J4EbceIN;
  ControlIf cIf_EhdYlMg1;
  ControlIf cIf_wevA2Ty0;
  ControlIf cIf_9jBOA7gp;
  ControlIf cIf_cjBMuI5L;
  ControlIf cIf_zLe9mwQM;
  ControlIf cIf_7SdfT2wa;
  ControlVar cVar_J0ccA27A;
  ControlBinop cBinop_D7sqgxyN;
  ControlBinop cBinop_Xs5zlmbV;
  ControlBinop cBinop_plJFnUXg;
  ControlBinop cBinop_oGw3bWeJ;
  ControlBinop cBinop_vsLZWSFf;
  ControlBinop cBinop_VhotNQMP;
  ControlBinop cBinop_rh1e2meB;
  ControlBinop cBinop_hhKOlndm;
  ControlBinop cBinop_w6iS2pft;
  ControlBinop cBinop_ksPi80zr;
  ControlBinop cBinop_cam4J9fF;
};

#endif // _HEAVY_CONTEXT_OSCILATOR_HPP_
