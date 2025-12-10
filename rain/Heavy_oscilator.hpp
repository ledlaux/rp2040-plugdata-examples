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
#include "HvControlSystem.h"
#include "HvMath.h"
#include "HvSignalBiquad.h"
#include "HvControlCast.h"
#include "HvSignalRPole.h"
#include "HvControlUnop.h"
#include "HvSignalLine.h"
#include "HvControlSlice.h"
#include "HvSignalDel1.h"
#include "HvControlVar.h"
#include "HvSignalVar.h"
#include "HvControlBinop.h"
#include "HvControlRandom.h"

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
  static void cSwitchcase_FhgN4NxL_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_ov2nYH8F_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_m08mg4rP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_pSx81fIF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_acOgP3GP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_l4F44jR9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZS4JMQ9R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_8Zk20blT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_QZ0BkUE3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_6NmxUAak_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_DfSCjz8k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Xj3fH6T3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rp8Q9Ksl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xvHSuBdo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FyVQ7Zuk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_27DjrAiX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bxR7EyAm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zAoXzo4f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ghe8aUUl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_o6STFMWH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mimBSeTW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qHCfgCUC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lahS6OeI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Mh1m2zgQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_XysbqxKt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hDtblQgX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DNsmcuZr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hKbAMdp9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TnLiuki4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_hkQUPKth_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VDCYvuOe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_GQBnWOdJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AvLtiuqt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NLAMBht3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_kOerC2NE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_m7PNMZEJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_peZ811oC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Jpqa8Aiy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_iW1w4dEm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FLQV2kQD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_3zsBjvgX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UA1E7qA6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jibWlvuR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_sSICcPs3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_skoIeMg5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kCwsRjQS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1L7oTdrc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AQVhiK5q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MxE7alXN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_wmbxDrp2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_1tsDFKPY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_oR8HZsZn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_HUFMqKJA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_98mzf2ze_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_LPQ1LUzi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_e9Wmdo0J_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_X0ivxRpo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AwQCRK5X_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GPqSZOIx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_AdYQBNGM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_bHkEZxmW_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_RD033ZyO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_GcFmMgzy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_kTy7EKXx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_lriMrn0I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_yMnDcoCR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Rc02LkeD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_7GWlY9P1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_PHLL2CLM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_YwUjmQRp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_xrpNi7A1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9pZ4AJTs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_siFiPbMn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2wehNVen_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MG51sjIY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_B31QZepo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PXcEy4MU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_P81CbORz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_PgHOiUx4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_P2u9NvUN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Z3GdE8i7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cgHFPrxE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kgkwtweE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_D15DLOIs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ImpnIOGr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JxkXJcnT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QacMDV1H_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GW9QhCWu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2P2kKXWe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_lwGtO5KD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_WKAdOun3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_FcPJjp8y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JHbJp02C_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ontYPAgV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_bIexzAJD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1xOhMkYe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VR33yC6s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vMM9yGxC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_EsDVgNUg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_UEh4knts_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_fDf4V5fT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_drz10Vbc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_pAEx3lFo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ip9m4Asd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_z7WGV6ww_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5cfDobne_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dxQiKY9P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DkKCz6i3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9HdKxzMQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_KTt3dF38_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_OIzXGALD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_FdwFEq9g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wcS580O3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kChTQRgv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Bj9XWomg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Swm11T17_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QolFXuNn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_T9zJ0cQS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CmgSHPGB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kA92kZus_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_eYuy1EF0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_IdOhdnFj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_1adPNYLl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_KM6ZNbOv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_DZrKzlzU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_UILOwbUA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_pW8mTZ8R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_VDNBZnC9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_APoQxbMf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xvuR8Tqc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_fzwtMBXq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2r4HKoVS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_MnQtnIAP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Ivah2bwC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_g2DDTeUQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_GEUECMTe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_CfZCxG2G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cOTZtaVc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dqtwBth2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sryIS9V1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vu28iXTf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TtgOhFjz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bzWifuLy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_styvMVdb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_qE0CCRtT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_17v21Dk4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_83MIeR2s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4HcGycn9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xFewYxLT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_iuJgYpUu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kRSENVeW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JKZFgdQ4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Hjcse34s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_A7CfznwS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5vnVF0gA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_AzJQmpLV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sYYVgJ3D_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_MHyk0gvq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SKqxXKtX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OzoqjoYF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_Pr5xdVQv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EoIpSoP2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_AF3SIm0f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MC88R0BS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_IRULhrJB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_krjgFZ1h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4B1j5e6d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wTF4yiES_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_l18dUWfP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YfHXMrak_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_zdfwBkCN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_kggWLTWd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xom41Bsp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bHGzmT9Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UvX2Gnj3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_MC4XRr1I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_edDto8QF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_817lCv6y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_UNQXJDkq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1o006dG3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_hHgG7jRK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QkJ831iz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_pqCCseVC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SBZSlPS0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_dRLtw7cY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_pfWOsWHx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_x64my1nh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8AehJCoX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BSqjZoHM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_zGGKAEgV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mjn4A4Ek_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_bYdOyYgs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_exKCFX9a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_dwHMvZ2y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_jp58OVra_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_PrunwJiS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_o7Sr4AAd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_UkRjy56L_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_mF9ooz26_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_BnLswJ9N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_7IfN2eDV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_MtAQsm7E_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Zix1ipZH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_KzBWnpRq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Gb5xzF9G_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalLine sLine_wCieg1Ax;
  SignalLine sLine_EQow6klP;
  SignalLine sLine_Y0V7d2iX;
  SignalBiquad_k sBiquad_k_XRAOuAFX;
  SignalRPole sRPole_5HUoRBvn;
  SignalRPole sRPole_TAIk2z3J;
  SignalBiquad_k sBiquad_k_s2efIq3b;
  SignalRPole sRPole_vwhq28qR;
  SignalRPole sRPole_lwVKV3ly;
  SignalRPole sRPole_Dc0nT1PE;
  SignalDel1 sDel1_cyKQpS63;
  SignalRPole sRPole_17Lle2VY;
  SignalDel1 sDel1_6y8cj2fu;
  SignalRPole sRPole_jaJFMRGf;
  SignalDel1 sDel1_DaZxmg4J;
  SignalRPole sRPole_sBJQMQRA;
  SignalDel1 sDel1_ZOlLlFca;
  ControlBinop cBinop_ov2nYH8F;
  ControlRandom cRandom_pSx81fIF;
  ControlSlice cSlice_acOgP3GP;
  SignalVari sVari_S59PosZD;
  ControlVar cVar_QZ0BkUE3;
  ControlVar cVar_6NmxUAak;
  ControlBinop cBinop_Xj3fH6T3;
  ControlBinop cBinop_rp8Q9Ksl;
  ControlBinop cBinop_xvHSuBdo;
  ControlBinop cBinop_FyVQ7Zuk;
  ControlBinop cBinop_27DjrAiX;
  ControlBinop cBinop_bxR7EyAm;
  ControlBinop cBinop_zAoXzo4f;
  ControlBinop cBinop_o6STFMWH;
  ControlBinop cBinop_mimBSeTW;
  ControlBinop cBinop_qHCfgCUC;
  ControlBinop cBinop_lahS6OeI;
  ControlBinop cBinop_Mh1m2zgQ;
  ControlBinop cBinop_XysbqxKt;
  ControlBinop cBinop_hDtblQgX;
  ControlBinop cBinop_DNsmcuZr;
  ControlBinop cBinop_hKbAMdp9;
  ControlBinop cBinop_TnLiuki4;
  ControlVar cVar_hkQUPKth;
  ControlBinop cBinop_AvLtiuqt;
  ControlBinop cBinop_NLAMBht3;
  SignalVarf sVarf_GMJS16ZI;
  ControlBinop cBinop_m7PNMZEJ;
  ControlBinop cBinop_peZ811oC;
  ControlBinop cBinop_Jpqa8Aiy;
  SignalVarf sVarf_aejQccwH;
  ControlVar cVar_iW1w4dEm;
  ControlBinop cBinop_UA1E7qA6;
  ControlBinop cBinop_jibWlvuR;
  SignalVarf sVarf_Q9Z7C158;
  ControlBinop cBinop_skoIeMg5;
  ControlBinop cBinop_kCwsRjQS;
  ControlBinop cBinop_1L7oTdrc;
  SignalVarf sVarf_WOlLLjn2;
  ControlBinop cBinop_AQVhiK5q;
  ControlBinop cBinop_MxE7alXN;
  SignalVarf sVarf_Srq3XaVH;
  ControlVar cVar_wmbxDrp2;
  ControlBinop cBinop_HUFMqKJA;
  ControlBinop cBinop_98mzf2ze;
  ControlBinop cBinop_e9Wmdo0J;
  ControlBinop cBinop_X0ivxRpo;
  ControlBinop cBinop_AwQCRK5X;
  ControlBinop cBinop_GPqSZOIx;
  ControlBinop cBinop_AdYQBNGM;
  SignalVarf sVarf_LYYNs6g4;
  ControlBinop cBinop_RD033ZyO;
  ControlRandom cRandom_kTy7EKXx;
  ControlSlice cSlice_lriMrn0I;
  SignalVari sVari_36WuY7Hv;
  ControlVar cVar_PHLL2CLM;
  ControlVar cVar_YwUjmQRp;
  ControlBinop cBinop_9pZ4AJTs;
  ControlBinop cBinop_siFiPbMn;
  ControlBinop cBinop_2wehNVen;
  ControlBinop cBinop_MG51sjIY;
  ControlBinop cBinop_B31QZepo;
  ControlBinop cBinop_PXcEy4MU;
  ControlBinop cBinop_P81CbORz;
  ControlBinop cBinop_P2u9NvUN;
  ControlBinop cBinop_Z3GdE8i7;
  ControlBinop cBinop_cgHFPrxE;
  ControlBinop cBinop_kgkwtweE;
  ControlBinop cBinop_D15DLOIs;
  ControlBinop cBinop_ImpnIOGr;
  ControlBinop cBinop_JxkXJcnT;
  ControlBinop cBinop_QacMDV1H;
  ControlBinop cBinop_GW9QhCWu;
  ControlBinop cBinop_2P2kKXWe;
  ControlVar cVar_lwGtO5KD;
  ControlBinop cBinop_JHbJp02C;
  ControlBinop cBinop_ontYPAgV;
  SignalVarf sVarf_v9aMS89y;
  ControlBinop cBinop_1xOhMkYe;
  ControlBinop cBinop_VR33yC6s;
  ControlBinop cBinop_vMM9yGxC;
  SignalVarf sVarf_NxnKugmj;
  ControlVar cVar_EsDVgNUg;
  ControlBinop cBinop_drz10Vbc;
  ControlBinop cBinop_pAEx3lFo;
  SignalVarf sVarf_xheJQvZd;
  ControlBinop cBinop_z7WGV6ww;
  ControlBinop cBinop_5cfDobne;
  ControlBinop cBinop_dxQiKY9P;
  SignalVarf sVarf_57SS1SN7;
  ControlBinop cBinop_DkKCz6i3;
  ControlBinop cBinop_9HdKxzMQ;
  SignalVarf sVarf_J3eMaYyI;
  ControlVar cVar_KTt3dF38;
  ControlBinop cBinop_wcS580O3;
  ControlBinop cBinop_kChTQRgv;
  ControlBinop cBinop_Swm11T17;
  ControlBinop cBinop_QolFXuNn;
  ControlBinop cBinop_T9zJ0cQS;
  ControlBinop cBinop_CmgSHPGB;
  ControlBinop cBinop_kA92kZus;
  SignalVarf sVarf_0gHdZJY9;
  ControlVar cVar_eYuy1EF0;
  ControlVar cVar_IdOhdnFj;
  ControlVar cVar_1adPNYLl;
  ControlVar cVar_KM6ZNbOv;
  ControlVar cVar_DZrKzlzU;
  ControlVar cVar_UILOwbUA;
  ControlVar cVar_pW8mTZ8R;
  ControlVar cVar_VDNBZnC9;
  ControlBinop cBinop_APoQxbMf;
  ControlBinop cBinop_xvuR8Tqc;
  SignalVarf sVarf_vwxala6I;
  ControlVar cVar_fzwtMBXq;
  ControlBinop cBinop_Ivah2bwC;
  ControlBinop cBinop_g2DDTeUQ;
  ControlBinop cBinop_CfZCxG2G;
  ControlBinop cBinop_cOTZtaVc;
  ControlBinop cBinop_dqtwBth2;
  ControlBinop cBinop_sryIS9V1;
  ControlBinop cBinop_vu28iXTf;
  SignalVarf sVarf_h4AvpEel;
  ControlBinop cBinop_TtgOhFjz;
  ControlBinop cBinop_bzWifuLy;
  SignalVarf sVarf_sVAHYHjp;
  ControlVar cVar_styvMVdb;
  ControlBinop cBinop_83MIeR2s;
  ControlBinop cBinop_4HcGycn9;
  ControlBinop cBinop_iuJgYpUu;
  ControlBinop cBinop_kRSENVeW;
  ControlBinop cBinop_JKZFgdQ4;
  ControlBinop cBinop_Hjcse34s;
  ControlBinop cBinop_A7CfznwS;
  SignalVarf sVarf_gqKDCcSz;
  SignalVarf sVarf_NBo0uCOz;
  SignalVarf sVarf_h7LowYJC;
  SignalVarf sVarf_9UX9VceC;
  ControlBinop cBinop_5vnVF0gA;
  ControlBinop cBinop_sYYVgJ3D;
  ControlBinop cBinop_SKqxXKtX;
  ControlBinop cBinop_OzoqjoYF;
  ControlBinop cBinop_EoIpSoP2;
  ControlBinop cBinop_MC88R0BS;
  ControlBinop cBinop_krjgFZ1h;
  ControlBinop cBinop_4B1j5e6d;
  ControlBinop cBinop_l18dUWfP;
  ControlBinop cBinop_YfHXMrak;
  ControlBinop cBinop_kggWLTWd;
  ControlBinop cBinop_bHGzmT9Y;
  ControlBinop cBinop_UvX2Gnj3;
  ControlBinop cBinop_edDto8QF;
  ControlBinop cBinop_UNQXJDkq;
  ControlBinop cBinop_1o006dG3;
  ControlBinop cBinop_hHgG7jRK;
  ControlBinop cBinop_QkJ831iz;
  ControlBinop cBinop_SBZSlPS0;
  ControlBinop cBinop_x64my1nh;
  ControlBinop cBinop_8AehJCoX;
  ControlBinop cBinop_BSqjZoHM;
  ControlBinop cBinop_mjn4A4Ek;
};

#endif // _HEAVY_CONTEXT_OSCILATOR_HPP_
