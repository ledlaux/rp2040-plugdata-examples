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

#include "Heavy_oscilator.hpp"

#include <new>

#define Context(_c) static_cast<Heavy_oscilator *>(_c)


/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_oscilator_new(double sampleRate) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_oscilator));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_oscilator(sampleRate);
    return Context(ptr);
  }

  HV_EXPORT HeavyContextInterface *hv_oscilator_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    // allocate aligned memory
    void *ptr = hv_malloc(sizeof(Heavy_oscilator));
    // ensure non-null
    if (!ptr) return nullptr;
    // call constructor
    new(ptr) Heavy_oscilator(sampleRate, poolKb, inQueueKb, outQueueKb);
    return Context(ptr);
  }

  HV_EXPORT void hv_oscilator_free(HeavyContextInterface *instance) {
    // call destructor
    Context(instance)->~Heavy_oscilator();
    // free memory
    hv_free(instance);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_oscilator::Heavy_oscilator(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_9TTFfL4P, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_bwoGldBa, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_lSzH15v1, 0.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_f16rvLdx, 0.0f, sampleRate);
  numBytes += cSlice_init(&cSlice_OyfiExI1, 2, 1);
  numBytes += cSlice_init(&cSlice_szdZLL1Q, 1, 1);
  numBytes += cSlice_init(&cSlice_fx77tlyX, 0, 1);
  numBytes += cVar_init_f(&cVar_pDP65RWI, 0.0f);
  numBytes += cIf_init(&cIf_UkJMxis6, false);
  numBytes += cIf_init(&cIf_Eql4vg2i, false);
  numBytes += cIf_init(&cIf_oHMxIaWN, false);
  numBytes += cIf_init(&cIf_0dJqR9nb, false);
  numBytes += cIf_init(&cIf_U6BnyBY3, false);
  numBytes += cBinop_init(&cBinop_QybsPrIu, 0.0f); // __eq
  numBytes += cPack_init(&cPack_P2sq9gCp, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_KisjK5Mh, 1.0f); // __pow
  numBytes += cBinop_init(&cBinop_tFZtpwf2, 1.0f); // __pow
  numBytes += cBinop_init(&cBinop_RpEMnkx6, 1.0f); // __pow
  numBytes += cSlice_init(&cSlice_AmbvDKQi, 1, 1);
  numBytes += cSlice_init(&cSlice_BiG3Pxde, 0, 1);
  numBytes += cSlice_init(&cSlice_NgHJ2lSY, 1, 1);
  numBytes += cSlice_init(&cSlice_H14iFE9o, 0, 1);
  numBytes += cSlice_init(&cSlice_LpDW15Do, 1, 1);
  numBytes += cSlice_init(&cSlice_fap0RoWs, 0, 1);
  numBytes += cBinop_init(&cBinop_7sPjqjg6, 1.0f); // __pow
  numBytes += cSlice_init(&cSlice_DSUtjKHH, 1, 1);
  numBytes += cSlice_init(&cSlice_72SMDez8, 0, 1);
  numBytes += cSlice_init(&cSlice_pXSrLX7D, 1, -1);
  numBytes += cSlice_init(&cSlice_hX5norEq, 1, -1);
  numBytes += cSlice_init(&cSlice_A7j5aF6y, 1, -1);
  numBytes += cVar_init_f(&cVar_I34S85zw, 0.0f);
  numBytes += cVar_init_f(&cVar_XZsPoPQe, 0.0f);
  numBytes += cSlice_init(&cSlice_BcDu7exk, 1, -1);
  numBytes += cSlice_init(&cSlice_MS0zZzlj, 1, -1);
  numBytes += cSlice_init(&cSlice_5Ki9XshM, 1, 1);
  numBytes += cSlice_init(&cSlice_5A3t5pqC, 0, 1);
  numBytes += cVar_init_f(&cVar_NljSjr94, 0.0f);
  numBytes += cIf_init(&cIf_ssJNiM7O, false);
  numBytes += cIf_init(&cIf_ZCK6a8Rg, false);
  numBytes += cIf_init(&cIf_2BsmnRUF, false);
  numBytes += cVar_init_f(&cVar_PQkhxaMq, 0.0f);
  numBytes += cIf_init(&cIf_7XA9ayjP, false);
  numBytes += cVar_init_f(&cVar_jFhymAUO, 0.0f);
  numBytes += cIf_init(&cIf_Jf4B0dWi, false);
  numBytes += cBinop_init(&cBinop_8IGBpzgz, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_BfjVatE4, 4.0f);
  numBytes += cTabread_init(&cTabread_1F4O0Crx, &hTable_gkOAMu6H); // 1023-used
  numBytes += cSlice_init(&cSlice_KsGDNLp3, 1, -1);
  numBytes += cVar_init_s(&cVar_E8yCVlz3, "1023-used");
  numBytes += cBinop_init(&cBinop_ZXczc35f, 0.0f); // __min
  numBytes += cTabread_init(&cTabread_uUCSsrPO, &hTable_7bRFnRfg); // 1023-ids
  numBytes += cSlice_init(&cSlice_MYVY0uaS, 1, -1);
  numBytes += cVar_init_s(&cVar_NWVjdYee, "1023-ids");
  numBytes += cBinop_init(&cBinop_PIKDUfqr, 0.0f); // __min
  numBytes += cVar_init_f(&cVar_InuI8nn2, 0.0f);
  numBytes += cSlice_init(&cSlice_mx0WBXj2, 1, 1);
  numBytes += cSlice_init(&cSlice_D63eNkaF, 0, 1);
  numBytes += cTabread_init(&cTabread_JHAepwtR, &hTable_C5CCH3SW); // 1023-pitches
  numBytes += cSlice_init(&cSlice_iZgIppIm, 1, -1);
  numBytes += cVar_init_s(&cVar_0vrPvhiN, "1023-pitches");
  numBytes += cBinop_init(&cBinop_KQAlnVYW, 0.0f); // __min
  numBytes += cVar_init_f(&cVar_g3f6IyrN, 0.0f);
  numBytes += cVar_init_f(&cVar_T71Haxt3, 0.0f);
  numBytes += cIf_init(&cIf_2twmAS6m, false);
  numBytes += cTabwrite_init(&cTabwrite_bOYjNtUk, &hTable_gkOAMu6H); // 1023-used
  numBytes += cSlice_init(&cSlice_h1XNnaaV, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_EfTFlvgZ, &hTable_7bRFnRfg); // 1023-ids
  numBytes += cSlice_init(&cSlice_dadA4V39, 1, -1);
  numBytes += cVar_init_f(&cVar_yKk52p00, 0.0f);
  numBytes += cVar_init_f(&cVar_Bv0dE2T5, 0.0f);
  numBytes += cSlice_init(&cSlice_lG0gjg37, 1, 1);
  numBytes += cSlice_init(&cSlice_a6R0UN06, 0, 1);
  numBytes += cPack_init(&cPack_mkTzUvTf, 2, 0.0f, 0.0f);
  numBytes += cBinop_init(&cBinop_iENjzuNU, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_JekiFyXB, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_rmse6Y2W, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_unbs5F5s, 0.0f); // __lt
  numBytes += cIf_init(&cIf_OaM6yKRK, false);
  numBytes += cVar_init_f(&cVar_nGW5GgAN, 0.0f);
  numBytes += cIf_init(&cIf_NesYM2UD, false);
  numBytes += cVar_init_f(&cVar_yKH4wAEX, 0.0f);
  numBytes += cIf_init(&cIf_IGJZrmMN, false);
  numBytes += cBinop_init(&cBinop_fdYJ1Drq, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_JY6KGwun, 4.0f);
  numBytes += cTabwrite_init(&cTabwrite_Ca4iZ5bZ, &hTable_gkOAMu6H); // 1023-used
  numBytes += cSlice_init(&cSlice_n8TXjSsV, 1, -1);
  numBytes += cTabread_init(&cTabread_GIUQMtx7, &hTable_gkOAMu6H); // 1023-used
  numBytes += cSlice_init(&cSlice_N32EUb1L, 1, -1);
  numBytes += cVar_init_s(&cVar_8XW6ImNE, "1023-used");
  numBytes += cBinop_init(&cBinop_hbwvm8yL, 0.0f); // __min
  numBytes += cIf_init(&cIf_0uJrJMyI, false);
  numBytes += cTabread_init(&cTabread_g45EiKfI, &hTable_C5CCH3SW); // 1023-pitches
  numBytes += cSlice_init(&cSlice_fUHh0SI0, 1, -1);
  numBytes += cVar_init_s(&cVar_WkZWX2qM, "1023-pitches");
  numBytes += cBinop_init(&cBinop_JgWYKx4t, 0.0f); // __min
  numBytes += cIf_init(&cIf_2Ux4X0D2, false);
  numBytes += cVar_init_f(&cVar_m5Hb3jIa, 0.0f);
  numBytes += cIf_init(&cIf_rLZI7WcJ, false);
  numBytes += cVar_init_f(&cVar_LvTUQrRF, 0.0f);
  numBytes += cIf_init(&cIf_dcvO8hSv, false);
  numBytes += cBinop_init(&cBinop_nMIysJ1I, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_8xF6BMLk, 4.0f);
  numBytes += cTabwrite_init(&cTabwrite_cnd5aQUU, &hTable_gkOAMu6H); // 1023-used
  numBytes += cSlice_init(&cSlice_pWNAW4I2, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_SwYOBoxm, &hTable_7bRFnRfg); // 1023-ids
  numBytes += cSlice_init(&cSlice_oZ0UBQG6, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_sHWRGFWe, &hTable_C5CCH3SW); // 1023-pitches
  numBytes += cSlice_init(&cSlice_e29IinWm, 1, -1);
  numBytes += cIf_init(&cIf_Q6CS4vbD, false);
  numBytes += cVar_init_f(&cVar_q2JS4jXN, 0.0f);
  numBytes += cIf_init(&cIf_syIpIb9N, false);
  numBytes += cVar_init_f(&cVar_IMlMRQyp, 0.0f);
  numBytes += cIf_init(&cIf_oDbc4aMo, false);
  numBytes += cBinop_init(&cBinop_4Nplzael, 0.0f); // __lt
  numBytes += cVar_init_f(&cVar_oCvcxc2c, 4.0f);
  numBytes += cVar_init_f(&cVar_bdxEN2LO, 0.0f);
  numBytes += cIf_init(&cIf_21taUPIV, false);
  numBytes += cVar_init_f(&cVar_dSrn7Mhx, 0.0f);
  numBytes += cVar_init_f(&cVar_YnhVUcLw, 0.0f);
  numBytes += cVar_init_f(&cVar_d1TlPfTP, 0.0f);
  numBytes += cIf_init(&cIf_wjZ51R2q, false);
  numBytes += cIf_init(&cIf_AZVhY21F, false);
  numBytes += cPack_init(&cPack_i2GEUUPy, 2, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_sTIzApk2, 0.0f);
  numBytes += cSlice_init(&cSlice_Essvpzzl, 1, 1);
  numBytes += cSlice_init(&cSlice_3xHzL2kM, 0, 1);
  numBytes += cVar_init_f(&cVar_dTdWEODM, 0.0f);
  numBytes += cIf_init(&cIf_VnIksJEB, false);
  numBytes += cVar_init_f(&cVar_hSRepmzI, 0.0f);
  numBytes += cVar_init_f(&cVar_ogRxM92i, 0.0f);
  numBytes += cTabread_init(&cTabread_7789y7SF, &hTable_gkOAMu6H); // 1023-used
  numBytes += cSlice_init(&cSlice_TQJ0Ylwn, 1, -1);
  numBytes += cVar_init_s(&cVar_ky7fTBNm, "1023-used");
  numBytes += cBinop_init(&cBinop_NE2wHN7w, 0.0f); // __min
  numBytes += cTabread_init(&cTabread_yrDUVyM3, &hTable_7bRFnRfg); // 1023-ids
  numBytes += cSlice_init(&cSlice_ZBkHeBmw, 1, -1);
  numBytes += cVar_init_s(&cVar_rW8oWBb4, "1023-ids");
  numBytes += cBinop_init(&cBinop_QXzaP0aw, 0.0f); // __min
  numBytes += cTabwrite_init(&cTabwrite_HeX9YxwM, &hTable_C5CCH3SW); // 1023-pitches
  numBytes += cSlice_init(&cSlice_AWahCSRN, 1, -1);
  numBytes += cTabread_init(&cTabread_SMbAMKZh, &hTable_C5CCH3SW); // 1023-pitches
  numBytes += cSlice_init(&cSlice_2YMOXPvV, 1, -1);
  numBytes += cVar_init_s(&cVar_Oewi7VnM, "1023-pitches");
  numBytes += cBinop_init(&cBinop_b3KupEMg, 0.0f); // __min
  numBytes += cTabwrite_init(&cTabwrite_7tYryxHt, &hTable_C5CCH3SW); // 1023-pitches
  numBytes += cSlice_init(&cSlice_rnnTIWo4, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_cASfqTdh, &hTable_gkOAMu6H); // 1023-used
  numBytes += cSlice_init(&cSlice_amtOhOO0, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_xoMQG02i, &hTable_7bRFnRfg); // 1023-ids
  numBytes += cSlice_init(&cSlice_A1YbJdow, 1, -1);
  numBytes += cTabwrite_init(&cTabwrite_bq46fd6M, &hTable_7bRFnRfg); // 1023-ids
  numBytes += cSlice_init(&cSlice_b82yW8Sz, 1, -1);
  numBytes += cVar_init_f(&cVar_ZIm1hLKm, 0.0f);
  numBytes += cTabwrite_init(&cTabwrite_gsnF3ELF, &hTable_gkOAMu6H); // 1023-used
  numBytes += cSlice_init(&cSlice_YRSXVseO, 1, -1);
  numBytes += cVar_init_f(&cVar_G4sfpKej, 0.0f);
  numBytes += cSlice_init(&cSlice_8NSfZI7Y, 1, 1);
  numBytes += cSlice_init(&cSlice_2csz914V, 0, 1);
  numBytes += cVar_init_f(&cVar_9eUFWCxd, 0.0f);
  numBytes += cBinop_init(&cBinop_P7Uv29Fm, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_Jw8KnCTD, 0.0f); // __lt
  numBytes += cBinop_init(&cBinop_mgeB0GQT, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_9TjiUpzZ, 0.0f); // __lt
  numBytes += cBinop_init(&cBinop_K9L9KRB2, 0.0f); // __logand
  numBytes += cBinop_init(&cBinop_D85EKmZ1, 65535.0f); // __unimod
  numBytes += hTable_init(&hTable_C5CCH3SW, 4);
  numBytes += hTable_init(&hTable_gkOAMu6H, 4);
  numBytes += hTable_init(&hTable_7bRFnRfg, 4);
  numBytes += sVarf_init(&sVarf_MSnmIugP, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Qtb2pfjZ, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_sLxWwvVg, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_rQyx0UPr, 0.0f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_oscilator::~Heavy_oscilator() {
  cPack_free(&cPack_P2sq9gCp);
  cPack_free(&cPack_mkTzUvTf);
  cPack_free(&cPack_i2GEUUPy);
  hTable_free(&hTable_C5CCH3SW);
  hTable_free(&hTable_gkOAMu6H);
  hTable_free(&hTable_7bRFnRfg);
}

HvTable *Heavy_oscilator::getTableForHash(hv_uint32_t tableHash) {switch (tableHash) {
    case 0x62D84860: return &hTable_C5CCH3SW; // 1023-pitches
    case 0x352F3ABD: return &hTable_gkOAMu6H; // 1023-used
    case 0x8E3D88CB: return &hTable_7bRFnRfg; // 1023-ids
    default: return nullptr;
  }
}

void Heavy_oscilator::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCDF32FF6: { // 1023-currentVoiceId
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_3BIg37j0_sendMessage);
      break;
    }
    case 0x3C8AE98D: { // 1023-indexOff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_vJjS1xQ6_sendMessage);
      break;
    }
    case 0x4FAD54EC: { // 1023-indexOn
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Q3VXyAPn_sendMessage);
      break;
    }
    case 0xD06AA72: { // 1023-isFirstOff
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_aJr8kjZf_sendMessage);
      break;
    }
    case 0xC2D593E2: { // 1023-isFirstOn
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_0CnywkIA_sendMessage);
      break;
    }
    case 0x7598FECD: { // 1023-maxVoiceId
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jeNHm6M2_sendMessage);
      break;
    }
    case 0x9A66BF9F: { // 1023-shouldSteal
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_LnqE8L6a_sendMessage);
      break;
    }
    case 0x846C1935: { // 1023-voiceId++
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_p9frMpch_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_bhH65O66_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_HMcP7h6w_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_oscilator::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 0;
}



/*
 * Send Function Implementations
 */


void Heavy_oscilator::cSlice_OyfiExI1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_UEpsfZSn_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_szdZLL1Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_0dJqR9nb, 0, m, &cIf_0dJqR9nb_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_Eql4vg2i, 0, m, &cIf_Eql4vg2i_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_fx77tlyX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_U6BnyBY3, 0, m, &cIf_U6BnyBY3_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_oHMxIaWN, 0, m, &cIf_oHMxIaWN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_pDP65RWI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_lX8T1dLS_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_UkJMxis6, 0, m, &cIf_UkJMxis6_sendMessage);
}

void Heavy_oscilator::cUnop_FyKxDMvI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_pzDGgWnI_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_QybsPrIu, HV_BINOP_EQ, 1, m, &cBinop_QybsPrIu_sendMessage);
}

void Heavy_oscilator::cUnop_SMtGdEda_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_pzDGgWnI_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_QybsPrIu, HV_BINOP_EQ, 1, m, &cBinop_QybsPrIu_sendMessage);
}

void Heavy_oscilator::cIf_UkJMxis6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_SMtGdEda_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_FyKxDMvI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cBinop_lX8T1dLS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_UkJMxis6, 1, m, &cIf_UkJMxis6_sendMessage);
}

void Heavy_oscilator::cIf_Eql4vg2i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_NljSjr94, 0, m, &cVar_NljSjr94_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_oHMxIaWN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_WcKbochI_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_0dJqR9nb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cVar_onMessage(_c, &Context(_c)->cVar_NljSjr94, 0, m, &cVar_NljSjr94_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_U6BnyBY3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_WcKbochI_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cBinop_UEpsfZSn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QybsPrIu, HV_BINOP_EQ, 0, m, &cBinop_QybsPrIu_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_oCUqkHA0_sendMessage);
}

void Heavy_oscilator::cBinop_pzDGgWnI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8BXjYzAS_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5SZxbr3z_sendMessage);
}

void Heavy_oscilator::cBinop_QybsPrIu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vrfDbPuz_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SiT30gZG_sendMessage);
}

void Heavy_oscilator::cCast_SiT30gZG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_U6BnyBY3, 1, m, &cIf_U6BnyBY3_sendMessage);
}

void Heavy_oscilator::cCast_vrfDbPuz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Eql4vg2i, 1, m, &cIf_Eql4vg2i_sendMessage);
}

void Heavy_oscilator::cCast_5SZxbr3z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_oHMxIaWN, 1, m, &cIf_oHMxIaWN_sendMessage);
}

void Heavy_oscilator::cCast_8BXjYzAS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_0dJqR9nb, 1, m, &cIf_0dJqR9nb_sendMessage);
}

void Heavy_oscilator::cBinop_oCUqkHA0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_oscilator::cPack_P2sq9gCp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_OMXQXJUf_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cBinop_65UPFxM8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_bwoGldBa, 0, m);
}

void Heavy_oscilator::cBinop_MnLvXxRx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_VhGTqfn9_sendMessage);
}

void Heavy_oscilator::cBinop_VhGTqfn9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KisjK5Mh, HV_BINOP_POW, 1, m, &cBinop_KisjK5Mh_sendMessage);
  cMsg_HtHyA7Ag_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_KisjK5Mh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_65UPFxM8_sendMessage);
}

void Heavy_oscilator::cMsg_HtHyA7Ag_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_KisjK5Mh, HV_BINOP_POW, 0, m, &cBinop_KisjK5Mh_sendMessage);
}

void Heavy_oscilator::cBinop_3edP2gyt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_9TTFfL4P, 0, m);
}

void Heavy_oscilator::cBinop_YqTc5LAw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_MEtdNxkP_sendMessage);
}

void Heavy_oscilator::cBinop_MEtdNxkP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_tFZtpwf2, HV_BINOP_POW, 1, m, &cBinop_tFZtpwf2_sendMessage);
  cMsg_hXMdEyKK_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_tFZtpwf2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_3edP2gyt_sendMessage);
}

void Heavy_oscilator::cMsg_hXMdEyKK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_tFZtpwf2, HV_BINOP_POW, 0, m, &cBinop_tFZtpwf2_sendMessage);
}

void Heavy_oscilator::cBinop_ekixPhgb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_lSzH15v1, 0, m);
}

void Heavy_oscilator::cBinop_mxVRkbea_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_sshzWggy_sendMessage);
}

void Heavy_oscilator::cBinop_sshzWggy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_RpEMnkx6, HV_BINOP_POW, 1, m, &cBinop_RpEMnkx6_sendMessage);
  cMsg_s5LvwO2X_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_RpEMnkx6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_ekixPhgb_sendMessage);
}

void Heavy_oscilator::cMsg_s5LvwO2X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_RpEMnkx6, HV_BINOP_POW, 0, m, &cBinop_RpEMnkx6_sendMessage);
}

void Heavy_oscilator::cSlice_AmbvDKQi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_Vq8sL6FN_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_BiG3Pxde_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_mxVRkbea_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_NgHJ2lSY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_xFuFg9PO_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_H14iFE9o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_YqTc5LAw_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_LpDW15Do_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_dIi5ckR3_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_fap0RoWs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_MnLvXxRx_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cBinop_kYO98sTH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_f16rvLdx, 0, m);
}

void Heavy_oscilator::cBinop_hJiKir4I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_BImEtsoA_sendMessage);
}

void Heavy_oscilator::cBinop_BImEtsoA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7sPjqjg6, HV_BINOP_POW, 1, m, &cBinop_7sPjqjg6_sendMessage);
  cMsg_C3RDZy0D_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_7sPjqjg6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_kYO98sTH_sendMessage);
}

void Heavy_oscilator::cMsg_C3RDZy0D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_7sPjqjg6, HV_BINOP_POW, 0, m, &cBinop_7sPjqjg6_sendMessage);
}

void Heavy_oscilator::cSlice_DSUtjKHH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_ODnedi2o_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_72SMDez8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_hJiKir4I_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSwitchcase_OMXQXJUf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_pXSrLX7D, 0, m, &cSlice_pXSrLX7D_sendMessage);
      break;
    }
    case 0x40000000: { // "2.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_hX5norEq, 0, m, &cSlice_hX5norEq_sendMessage);
      break;
    }
    case 0x40400000: { // "3.0"
      cSlice_onMessage(_c, &Context(_c)->cSlice_A7j5aF6y, 0, m, &cSlice_A7j5aF6y_sendMessage);
      break;
    }
    default: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_DSUtjKHH, 0, m, &cSlice_DSUtjKHH_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_72SMDez8, 0, m, &cSlice_72SMDez8_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cSlice_pXSrLX7D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_NgHJ2lSY, 0, m, &cSlice_NgHJ2lSY_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_H14iFE9o, 0, m, &cSlice_H14iFE9o_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_NgHJ2lSY, 0, m, &cSlice_NgHJ2lSY_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_H14iFE9o, 0, m, &cSlice_H14iFE9o_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_hX5norEq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_LpDW15Do, 0, m, &cSlice_LpDW15Do_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_fap0RoWs, 0, m, &cSlice_fap0RoWs_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_LpDW15Do, 0, m, &cSlice_LpDW15Do_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_fap0RoWs, 0, m, &cSlice_fap0RoWs_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_A7j5aF6y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_AmbvDKQi, 0, m, &cSlice_AmbvDKQi_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_BiG3Pxde, 0, m, &cSlice_BiG3Pxde_sendMessage);
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_AmbvDKQi, 0, m, &cSlice_AmbvDKQi_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_BiG3Pxde, 0, m, &cSlice_BiG3Pxde_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_I34S85zw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_H5ywhhGO_sendMessage);
}

void Heavy_oscilator::cVar_XZsPoPQe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D85EKmZ1, HV_BINOP_MOD_UNIPOLAR, 0, m, &cBinop_D85EKmZ1_sendMessage);
}

void Heavy_oscilator::cSwitchcase_WcKbochI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_BcDu7exk, 0, m, &cSlice_BcDu7exk_sendMessage);
      break;
    }
    case 0x47BE8354: { // "clear"
      cSlice_onMessage(_c, &Context(_c)->cSlice_MS0zZzlj, 0, m, &cSlice_MS0zZzlj_sendMessage);
      break;
    }
    default: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_5Ki9XshM, 0, m, &cSlice_5Ki9XshM_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_5A3t5pqC, 0, m, &cSlice_5A3t5pqC_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cSlice_BcDu7exk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NxB3aSCv_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nPIbCjpY_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NxB3aSCv_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_nPIbCjpY_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_MS0zZzlj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UA6ocTyI_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fhvRVDgF_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UA6ocTyI_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_fhvRVDgF_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_5Ki9XshM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cVar_onMessage(_c, &Context(_c)->cVar_NljSjr94, 0, m, &cVar_NljSjr94_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_5A3t5pqC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_ssJNiM7O, 0, m, &cIf_ssJNiM7O_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_ZCK6a8Rg, 0, m, &cIf_ZCK6a8Rg_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_NljSjr94_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_i2GEUUPy, 1, m, &cPack_i2GEUUPy_sendMessage);
  cPack_onMessage(_c, &Context(_c)->cPack_mkTzUvTf, 1, m, &cPack_mkTzUvTf_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_TjgTlTXq_sendMessage);
}

void Heavy_oscilator::cIf_ssJNiM7O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_s1VjRz8u_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2zNpbtAs_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QqIQbd99_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_i2GEUUPy, 0, m, &cPack_i2GEUUPy_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_ZCK6a8Rg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_mkTzUvTf, 0, m, &cPack_mkTzUvTf_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_2BsmnRUF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_07licPn4_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WnRqXp0R_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_PQkhxaMq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rm3spKPH_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IpIB6VcW_sendMessage);
}

void Heavy_oscilator::cIf_7XA9ayjP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_WcPQHF84_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SyJt0ET8_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cBinop_4HBVA6E3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_7XA9ayjP, 1, m, &cIf_7XA9ayjP_sendMessage);
}

void Heavy_oscilator::cVar_jFhymAUO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_gtQbdZuB_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_Jf4B0dWi, 0, m, &cIf_Jf4B0dWi_sendMessage);
}

void Heavy_oscilator::cUnop_UouaRA7q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_4HBVA6E3_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_7XA9ayjP, 0, m, &cIf_7XA9ayjP_sendMessage);
}

void Heavy_oscilator::cUnop_TPEajMjI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_4HBVA6E3_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_7XA9ayjP, 0, m, &cIf_7XA9ayjP_sendMessage);
}

void Heavy_oscilator::cIf_Jf4B0dWi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_TPEajMjI_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_UouaRA7q_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cBinop_gtQbdZuB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Jf4B0dWi, 1, m, &cIf_Jf4B0dWi_sendMessage);
}

void Heavy_oscilator::cCast_IpIB6VcW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_2BsmnRUF, 0, m, &cIf_2BsmnRUF_sendMessage);
}

void Heavy_oscilator::cCast_rm3spKPH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8IGBpzgz, HV_BINOP_LESS_THAN, 0, m, &cBinop_8IGBpzgz_sendMessage);
}

void Heavy_oscilator::cBinop_8IGBpzgz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_2BsmnRUF, 1, m, &cIf_2BsmnRUF_sendMessage);
}

void Heavy_oscilator::cCast_WcPQHF84_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8IGBpzgz, HV_BINOP_LESS_THAN, 1, m, &cBinop_8IGBpzgz_sendMessage);
}

void Heavy_oscilator::cCast_SyJt0ET8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_D9kZAAL1_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_kYBuFrJm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PQkhxaMq, 0, m, &cVar_PQkhxaMq_sendMessage);
}

void Heavy_oscilator::cMsg_D9kZAAL1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_PQkhxaMq, 0, m, &cVar_PQkhxaMq_sendMessage);
}

void Heavy_oscilator::cCast_WnRqXp0R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_kYBuFrJm_sendMessage);
}

void Heavy_oscilator::cCast_07licPn4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4xlaLx39_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_U48a95fq_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_y4ThukRr_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2j9fjdyO_sendMessage);
}

void Heavy_oscilator::cVar_BfjVatE4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jFhymAUO, 0, m, &cVar_jFhymAUO_sendMessage);
}

void Heavy_oscilator::cTabread_1F4O0Crx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rmse6Y2W, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_rmse6Y2W_sendMessage);
}

void Heavy_oscilator::cSwitchcase_nwkcIfhK_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_KsGDNLp3, 0, m, &cSlice_KsGDNLp3_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XAMaSQaW_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_7glnYAQd_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cSlice_KsGDNLp3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_1F4O0Crx, 1, m, &cTabread_1F4O0Crx_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_1F4O0Crx, 1, m, &cTabread_1F4O0Crx_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_E8yCVlz3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_W0H6ffef_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cSystem_rbyXws4R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Ewl7GwMl_sendMessage);
}

void Heavy_oscilator::cBinop_SUDj2EZc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZXczc35f, HV_BINOP_MIN, 0, m, &cBinop_ZXczc35f_sendMessage);
}

void Heavy_oscilator::cCast_7glnYAQd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_SUDj2EZc_sendMessage);
}

void Heavy_oscilator::cCast_XAMaSQaW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_E8yCVlz3, 0, m, &cVar_E8yCVlz3_sendMessage);
}

void Heavy_oscilator::cBinop_ZXczc35f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_1F4O0Crx, 0, m, &cTabread_1F4O0Crx_sendMessage);
}

void Heavy_oscilator::cMsg_W0H6ffef_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rbyXws4R_sendMessage);
}

void Heavy_oscilator::cBinop_Ewl7GwMl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZXczc35f, HV_BINOP_MIN, 1, m, &cBinop_ZXczc35f_sendMessage);
}

void Heavy_oscilator::cTabread_uUCSsrPO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_egsrMdaf_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2Iu8p8rn_sendMessage);
}

void Heavy_oscilator::cSwitchcase_2VCgBNXp_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_MYVY0uaS, 0, m, &cSlice_MYVY0uaS_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_74OYjbcg_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xnQStXq1_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cSlice_MYVY0uaS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_uUCSsrPO, 1, m, &cTabread_uUCSsrPO_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_uUCSsrPO, 1, m, &cTabread_uUCSsrPO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_NWVjdYee_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_oFETsmoF_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cSystem_YErsLsfo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_X0llOVnR_sendMessage);
}

void Heavy_oscilator::cBinop_OFG6jmj8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PIKDUfqr, HV_BINOP_MIN, 0, m, &cBinop_PIKDUfqr_sendMessage);
}

void Heavy_oscilator::cCast_74OYjbcg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NWVjdYee, 0, m, &cVar_NWVjdYee_sendMessage);
}

void Heavy_oscilator::cCast_xnQStXq1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_OFG6jmj8_sendMessage);
}

void Heavy_oscilator::cBinop_PIKDUfqr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_uUCSsrPO, 0, m, &cTabread_uUCSsrPO_sendMessage);
}

void Heavy_oscilator::cMsg_oFETsmoF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_YErsLsfo_sendMessage);
}

void Heavy_oscilator::cBinop_X0llOVnR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PIKDUfqr, HV_BINOP_MIN, 1, m, &cBinop_PIKDUfqr_sendMessage);
}

void Heavy_oscilator::cVar_InuI8nn2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_bOYjNtUk, 1, m, &cTabwrite_bOYjNtUk_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_EfTFlvgZ, 1, m, &cTabwrite_EfTFlvgZ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Bv0dE2T5, 1, m, &cVar_Bv0dE2T5_sendMessage);
}

void Heavy_oscilator::cSlice_mx0WBXj2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_D63eNkaF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jdi44un2_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_m3liIgP4_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cTabread_JHAepwtR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iENjzuNU, HV_BINOP_EQ, 0, m, &cBinop_iENjzuNU_sendMessage);
}

void Heavy_oscilator::cSwitchcase_IdvbLvym_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_iZgIppIm, 0, m, &cSlice_iZgIppIm_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3DdnwVDD_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fyTGutzV_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cSlice_iZgIppIm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_JHAepwtR, 1, m, &cTabread_JHAepwtR_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_JHAepwtR, 1, m, &cTabread_JHAepwtR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_0vrPvhiN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GmtwbPp9_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cSystem_hJJsoKFQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_kxKAm3PD_sendMessage);
}

void Heavy_oscilator::cBinop_fExriG3z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KQAlnVYW, HV_BINOP_MIN, 0, m, &cBinop_KQAlnVYW_sendMessage);
}

void Heavy_oscilator::cCast_fyTGutzV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_fExriG3z_sendMessage);
}

void Heavy_oscilator::cCast_3DdnwVDD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_0vrPvhiN, 0, m, &cVar_0vrPvhiN_sendMessage);
}

void Heavy_oscilator::cBinop_KQAlnVYW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_JHAepwtR, 0, m, &cTabread_JHAepwtR_sendMessage);
}

void Heavy_oscilator::cMsg_GmtwbPp9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hJJsoKFQ_sendMessage);
}

void Heavy_oscilator::cBinop_kxKAm3PD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_KQAlnVYW, HV_BINOP_MIN, 1, m, &cBinop_KQAlnVYW_sendMessage);
}

void Heavy_oscilator::cVar_g3f6IyrN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_unbs5F5s, HV_BINOP_LESS_THAN, 1, m, &cBinop_unbs5F5s_sendMessage);
}

void Heavy_oscilator::cSwitchcase_VjKa5FIL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Cyjd9Q6U_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_oscilator::cCast_Cyjd9Q6U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mmbKq7uy_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rBb34ZiU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Clo32KFB_sendMessage);
}

void Heavy_oscilator::cVar_T71Haxt3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_unbs5F5s, HV_BINOP_LESS_THAN, 1, m, &cBinop_unbs5F5s_sendMessage);
}

void Heavy_oscilator::cIf_2twmAS6m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8nHZcS97_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Xv6nWp30_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sHVoS7FY_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_lG0gjg37, 0, m, &cSlice_lG0gjg37_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_a6R0UN06, 0, m, &cSlice_a6R0UN06_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AGzuxDwb_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cTabwrite_bOYjNtUk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_oscilator::cSwitchcase_og1bMfUQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_h1XNnaaV, 0, m, &cSlice_h1XNnaaV_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_bOYjNtUk, 0, m, &cTabwrite_bOYjNtUk_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cSlice_h1XNnaaV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_bOYjNtUk, 2, m, &cTabwrite_bOYjNtUk_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_bOYjNtUk, 2, m, &cTabwrite_bOYjNtUk_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cTabwrite_EfTFlvgZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_oscilator::cSwitchcase_hyOcfGaJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_dadA4V39, 0, m, &cSlice_dadA4V39_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_EfTFlvgZ, 0, m, &cTabwrite_EfTFlvgZ_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cSlice_dadA4V39_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_EfTFlvgZ, 2, m, &cTabwrite_EfTFlvgZ_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_EfTFlvgZ, 2, m, &cTabwrite_EfTFlvgZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_yKk52p00_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_hyOcfGaJ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cVar_Bv0dE2T5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_OWoZL6HW_sendMessage);
}

void Heavy_oscilator::cSlice_lG0gjg37_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_a6R0UN06_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_P2sq9gCp, 1, m, &cPack_P2sq9gCp_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cPack_mkTzUvTf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xElUjrcd_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PtPPbFGp_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_mx0WBXj2, 0, m, &cSlice_mx0WBXj2_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_D63eNkaF, 0, m, &cSlice_D63eNkaF_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_2twmAS6m, 0, m, &cIf_2twmAS6m_sendMessage);
}

void Heavy_oscilator::cCast_y4ThukRr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_nwkcIfhK_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cCast_U48a95fq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_2VCgBNXp_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cCast_4xlaLx39_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_InuI8nn2, 1, m, &cVar_InuI8nn2_sendMessage);
}

void Heavy_oscilator::cCast_2j9fjdyO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_IdvbLvym_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cMsg_pGQXoXbN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_2twmAS6m, 1, m, &cIf_2twmAS6m_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_InuI8nn2, 0, m, &cVar_InuI8nn2_sendMessage);
}

void Heavy_oscilator::cMsg_vCDQIel2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cIf_onMessage(_c, &Context(_c)->cIf_2twmAS6m, 1, m, &cIf_2twmAS6m_sendMessage);
}

void Heavy_oscilator::cCast_xElUjrcd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_g3f6IyrN, 0, m, &cVar_g3f6IyrN_sendMessage);
}

void Heavy_oscilator::cCast_PtPPbFGp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pGQXoXbN_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_jdi44un2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_iENjzuNU, HV_BINOP_EQ, 1, m, &cBinop_iENjzuNU_sendMessage);
}

void Heavy_oscilator::cCast_m3liIgP4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BfjVatE4, 0, m, &cVar_BfjVatE4_sendMessage);
}

void Heavy_oscilator::cBinop_iENjzuNU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JekiFyXB, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_JekiFyXB_sendMessage);
}

void Heavy_oscilator::cBinop_JekiFyXB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_VjKa5FIL_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cBinop_rmse6Y2W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JekiFyXB, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_JekiFyXB_sendMessage);
}

void Heavy_oscilator::cBinop_unbs5F5s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rmse6Y2W, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_rmse6Y2W_sendMessage);
}

void Heavy_oscilator::cCast_mmbKq7uy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_T71Haxt3, 0, m, &cVar_T71Haxt3_sendMessage);
}

void Heavy_oscilator::cCast_Clo32KFB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_InuI8nn2, 0, m, &cVar_InuI8nn2_sendMessage);
}

void Heavy_oscilator::cCast_rBb34ZiU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vCDQIel2_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_egsrMdaf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_T71Haxt3, 1, m, &cVar_T71Haxt3_sendMessage);
}

void Heavy_oscilator::cCast_2Iu8p8rn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_unbs5F5s, HV_BINOP_LESS_THAN, 0, m, &cBinop_unbs5F5s_sendMessage);
}

void Heavy_oscilator::cCast_IA9blfH0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_N0miDQP2_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_2OlFPK6f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yKk52p00, 0, m, &cVar_yKk52p00_sendMessage);
}

void Heavy_oscilator::cSend_N0miDQP2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_p9frMpch_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_Xv6nWp30_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IA9blfH0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2OlFPK6f_sendMessage);
}

void Heavy_oscilator::cCast_8nHZcS97_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QryR0BfX_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cMsg_QryR0BfX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_og1bMfUQ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cCast_sHVoS7FY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rSi8Phkc_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_AGzuxDwb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Bv0dE2T5, 0, m, &cVar_Bv0dE2T5_sendMessage);
}

void Heavy_oscilator::cMsg_rSi8Phkc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_P2sq9gCp, 2, m, &cPack_P2sq9gCp_sendMessage);
}

void Heavy_oscilator::cIf_OaM6yKRK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2vQgr0yv_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DOQIW6Dc_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_nGW5GgAN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HjFrCPUr_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_B5tu9xWI_sendMessage);
}

void Heavy_oscilator::cIf_NesYM2UD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4GV9RdDB_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_wbzBDMPb_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cBinop_m3FVgQIW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_NesYM2UD, 1, m, &cIf_NesYM2UD_sendMessage);
}

void Heavy_oscilator::cVar_yKH4wAEX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_mj62WLDO_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_IGJZrmMN, 0, m, &cIf_IGJZrmMN_sendMessage);
}

void Heavy_oscilator::cUnop_ZnuyUKZf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_m3FVgQIW_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_NesYM2UD, 0, m, &cIf_NesYM2UD_sendMessage);
}

void Heavy_oscilator::cUnop_Xahiqdon_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_m3FVgQIW_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_NesYM2UD, 0, m, &cIf_NesYM2UD_sendMessage);
}

void Heavy_oscilator::cIf_IGJZrmMN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_Xahiqdon_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_ZnuyUKZf_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cBinop_mj62WLDO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_IGJZrmMN, 1, m, &cIf_IGJZrmMN_sendMessage);
}

void Heavy_oscilator::cCast_B5tu9xWI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_OaM6yKRK, 0, m, &cIf_OaM6yKRK_sendMessage);
}

void Heavy_oscilator::cCast_HjFrCPUr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fdYJ1Drq, HV_BINOP_LESS_THAN, 0, m, &cBinop_fdYJ1Drq_sendMessage);
}

void Heavy_oscilator::cBinop_fdYJ1Drq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_OaM6yKRK, 1, m, &cIf_OaM6yKRK_sendMessage);
}

void Heavy_oscilator::cCast_4GV9RdDB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_fdYJ1Drq, HV_BINOP_LESS_THAN, 1, m, &cBinop_fdYJ1Drq_sendMessage);
}

void Heavy_oscilator::cCast_wbzBDMPb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LSgeepVS_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_ncUkekMW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_nGW5GgAN, 0, m, &cVar_nGW5GgAN_sendMessage);
}

void Heavy_oscilator::cMsg_LSgeepVS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_nGW5GgAN, 0, m, &cVar_nGW5GgAN_sendMessage);
}

void Heavy_oscilator::cCast_2vQgr0yv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iOmysfcN_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_t5Pj7Dco_sendMessage);
}

void Heavy_oscilator::cCast_DOQIW6Dc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_ncUkekMW_sendMessage);
}

void Heavy_oscilator::cVar_JY6KGwun_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yKH4wAEX, 0, m, &cVar_yKH4wAEX_sendMessage);
}

void Heavy_oscilator::cTabwrite_Ca4iZ5bZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_oscilator::cSwitchcase_yfDZkcBj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_n8TXjSsV, 0, m, &cSlice_n8TXjSsV_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_Ca4iZ5bZ, 0, m, &cTabwrite_Ca4iZ5bZ_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cSlice_n8TXjSsV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_Ca4iZ5bZ, 2, m, &cTabwrite_Ca4iZ5bZ_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_Ca4iZ5bZ, 2, m, &cTabwrite_Ca4iZ5bZ_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cTabread_GIUQMtx7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_T8klCp0F_sendMessage);
}

void Heavy_oscilator::cSwitchcase_RYFGzm5L_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_N32EUb1L, 0, m, &cSlice_N32EUb1L_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zTWxpbJU_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gpqNAtJ8_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cSlice_N32EUb1L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_GIUQMtx7, 1, m, &cTabread_GIUQMtx7_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_GIUQMtx7, 1, m, &cTabread_GIUQMtx7_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_8XW6ImNE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_SgljQv9F_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cSystem_6XTKjR7Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_BQ0jypiW_sendMessage);
}

void Heavy_oscilator::cBinop_O2GaGqCc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hbwvm8yL, HV_BINOP_MIN, 0, m, &cBinop_hbwvm8yL_sendMessage);
}

void Heavy_oscilator::cCast_gpqNAtJ8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_O2GaGqCc_sendMessage);
}

void Heavy_oscilator::cCast_zTWxpbJU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8XW6ImNE, 0, m, &cVar_8XW6ImNE_sendMessage);
}

void Heavy_oscilator::cBinop_hbwvm8yL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_GIUQMtx7, 0, m, &cTabread_GIUQMtx7_sendMessage);
}

void Heavy_oscilator::cMsg_SgljQv9F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6XTKjR7Y_sendMessage);
}

void Heavy_oscilator::cBinop_BQ0jypiW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hbwvm8yL, HV_BINOP_MIN, 1, m, &cBinop_hbwvm8yL_sendMessage);
}

void Heavy_oscilator::cIf_0uJrJMyI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZA7hY5x6_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_w3VFMaVy_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_50R076tR_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Wy5szmlT_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jA0Qer8t_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cTabread_g45EiKfI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_P2sq9gCp, 1, m, &cPack_P2sq9gCp_sendMessage);
}

void Heavy_oscilator::cSwitchcase_DPl16UAt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_fUHh0SI0, 0, m, &cSlice_fUHh0SI0_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SyO1zDEc_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ioEUSX06_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cSlice_fUHh0SI0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_g45EiKfI, 1, m, &cTabread_g45EiKfI_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_g45EiKfI, 1, m, &cTabread_g45EiKfI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_WkZWX2qM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GyHLgKGj_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cSystem_GiIgdNkN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_12O1k1IQ_sendMessage);
}

void Heavy_oscilator::cBinop_BwlhS9Uj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JgWYKx4t, HV_BINOP_MIN, 0, m, &cBinop_JgWYKx4t_sendMessage);
}

void Heavy_oscilator::cCast_ioEUSX06_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_BwlhS9Uj_sendMessage);
}

void Heavy_oscilator::cCast_SyO1zDEc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_WkZWX2qM, 0, m, &cVar_WkZWX2qM_sendMessage);
}

void Heavy_oscilator::cBinop_JgWYKx4t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_g45EiKfI, 0, m, &cTabread_g45EiKfI_sendMessage);
}

void Heavy_oscilator::cMsg_GyHLgKGj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GiIgdNkN_sendMessage);
}

void Heavy_oscilator::cBinop_12O1k1IQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JgWYKx4t, HV_BINOP_MIN, 1, m, &cBinop_JgWYKx4t_sendMessage);
}

void Heavy_oscilator::cCast_nPIbCjpY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JY6KGwun, 0, m, &cVar_JY6KGwun_sendMessage);
}

void Heavy_oscilator::cCast_NxB3aSCv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YhAwsQZH_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cMsg_YhAwsQZH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_dUkgRhec_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cSend_dUkgRhec_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_p9frMpch_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_T8klCp0F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_0uJrJMyI, 1, m, &cIf_0uJrJMyI_sendMessage);
}

void Heavy_oscilator::cCast_iOmysfcN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_RYFGzm5L_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cCast_t5Pj7Dco_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_0uJrJMyI, 0, m, &cIf_0uJrJMyI_sendMessage);
}

void Heavy_oscilator::cMsg_vHBxaSSc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_P2sq9gCp, 2, m, &cPack_P2sq9gCp_sendMessage);
}

void Heavy_oscilator::cCast_jA0Qer8t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_7Q4s9u69_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_Wy5szmlT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Oem8QGPY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5Dw3UV29_sendMessage);
}

void Heavy_oscilator::cCast_50R076tR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_OWoZL6HW_sendMessage);
}

void Heavy_oscilator::cCast_w3VFMaVy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_DPl16UAt_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cCast_ZA7hY5x6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_vHBxaSSc_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_5Dw3UV29_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Uncojobu_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_Oem8QGPY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_Ca4iZ5bZ, 1, m, &cTabwrite_Ca4iZ5bZ_sendMessage);
}

void Heavy_oscilator::cMsg_Uncojobu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_yfDZkcBj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cSend_7Q4s9u69_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_p9frMpch_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cIf_2Ux4X0D2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_peqvBbMl_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SPIzLO1d_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_m5Hb3jIa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YfNkixzB_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mlZD7tTQ_sendMessage);
}

void Heavy_oscilator::cIf_rLZI7WcJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nCl77CA4_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8H30MvuW_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cBinop_FO7GcR8A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_rLZI7WcJ, 1, m, &cIf_rLZI7WcJ_sendMessage);
}

void Heavy_oscilator::cVar_LvTUQrRF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_i0rK84VC_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_dcvO8hSv, 0, m, &cIf_dcvO8hSv_sendMessage);
}

void Heavy_oscilator::cUnop_VUc0E8cu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_FO7GcR8A_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_rLZI7WcJ, 0, m, &cIf_rLZI7WcJ_sendMessage);
}

void Heavy_oscilator::cUnop_SVMJYFdH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_FO7GcR8A_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_rLZI7WcJ, 0, m, &cIf_rLZI7WcJ_sendMessage);
}

void Heavy_oscilator::cIf_dcvO8hSv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_SVMJYFdH_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_VUc0E8cu_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cBinop_i0rK84VC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_dcvO8hSv, 1, m, &cIf_dcvO8hSv_sendMessage);
}

void Heavy_oscilator::cCast_YfNkixzB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nMIysJ1I, HV_BINOP_LESS_THAN, 0, m, &cBinop_nMIysJ1I_sendMessage);
}

void Heavy_oscilator::cCast_mlZD7tTQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_2Ux4X0D2, 0, m, &cIf_2Ux4X0D2_sendMessage);
}

void Heavy_oscilator::cBinop_nMIysJ1I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_2Ux4X0D2, 1, m, &cIf_2Ux4X0D2_sendMessage);
}

void Heavy_oscilator::cCast_nCl77CA4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_nMIysJ1I, HV_BINOP_LESS_THAN, 1, m, &cBinop_nMIysJ1I_sendMessage);
}

void Heavy_oscilator::cCast_8H30MvuW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WooSVJqu_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_evun0Si8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_m5Hb3jIa, 0, m, &cVar_m5Hb3jIa_sendMessage);
}

void Heavy_oscilator::cMsg_WooSVJqu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_m5Hb3jIa, 0, m, &cVar_m5Hb3jIa_sendMessage);
}

void Heavy_oscilator::cCast_SPIzLO1d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_evun0Si8_sendMessage);
}

void Heavy_oscilator::cCast_peqvBbMl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_sHWRGFWe, 1, m, &cTabwrite_sHWRGFWe_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_SwYOBoxm, 1, m, &cTabwrite_SwYOBoxm_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_cnd5aQUU, 1, m, &cTabwrite_cnd5aQUU_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mjHYeRPp_sendMessage);
}

void Heavy_oscilator::cVar_8xF6BMLk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LvTUQrRF, 0, m, &cVar_LvTUQrRF_sendMessage);
}

void Heavy_oscilator::cTabwrite_cnd5aQUU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_oscilator::cSwitchcase_KS0ralml_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_pWNAW4I2, 0, m, &cSlice_pWNAW4I2_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_cnd5aQUU, 0, m, &cTabwrite_cnd5aQUU_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cSlice_pWNAW4I2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_cnd5aQUU, 2, m, &cTabwrite_cnd5aQUU_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_cnd5aQUU, 2, m, &cTabwrite_cnd5aQUU_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cTabwrite_SwYOBoxm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_oscilator::cSwitchcase_yoLSqNZN_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_oZ0UBQG6, 0, m, &cSlice_oZ0UBQG6_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_SwYOBoxm, 0, m, &cTabwrite_SwYOBoxm_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cSlice_oZ0UBQG6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_SwYOBoxm, 2, m, &cTabwrite_SwYOBoxm_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_SwYOBoxm, 2, m, &cTabwrite_SwYOBoxm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cTabwrite_sHWRGFWe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_oscilator::cSwitchcase_BHaRu3kk_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_e29IinWm, 0, m, &cSlice_e29IinWm_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_sHWRGFWe, 0, m, &cTabwrite_sHWRGFWe_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cSlice_e29IinWm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_sHWRGFWe, 2, m, &cTabwrite_sHWRGFWe_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_sHWRGFWe, 2, m, &cTabwrite_sHWRGFWe_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cMsg_NfOPdQWK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_BHaRu3kk_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_yoLSqNZN_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_KS0ralml_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cCast_UA6ocTyI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_6mwu74ue_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_fhvRVDgF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8xF6BMLk, 0, m, &cVar_8xF6BMLk_sendMessage);
}

void Heavy_oscilator::cMsg_6mwu74ue_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_4SnLpIGM_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cSend_4SnLpIGM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_p9frMpch_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_mjHYeRPp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NfOPdQWK_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cIf_Q6CS4vbD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Eid6JHaY_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_l6itORnO_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_q2JS4jXN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_rrxaWU5n_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_mlnZPCFQ_sendMessage);
}

void Heavy_oscilator::cIf_syIpIb9N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5t9tpNAr_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_roA5WKeR_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cBinop_gITDYzFv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_syIpIb9N, 1, m, &cIf_syIpIb9N_sendMessage);
}

void Heavy_oscilator::cVar_IMlMRQyp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_9oU5swTU_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_oDbc4aMo, 0, m, &cIf_oDbc4aMo_sendMessage);
}

void Heavy_oscilator::cUnop_UGdynH5u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_gITDYzFv_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_syIpIb9N, 0, m, &cIf_syIpIb9N_sendMessage);
}

void Heavy_oscilator::cUnop_VhRfAsIW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN_EQL, 1.0f, 0, m, &cBinop_gITDYzFv_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_syIpIb9N, 0, m, &cIf_syIpIb9N_sendMessage);
}

void Heavy_oscilator::cIf_oDbc4aMo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_VhRfAsIW_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_UGdynH5u_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cBinop_9oU5swTU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_oDbc4aMo, 1, m, &cIf_oDbc4aMo_sendMessage);
}

void Heavy_oscilator::cCast_mlnZPCFQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Q6CS4vbD, 0, m, &cIf_Q6CS4vbD_sendMessage);
}

void Heavy_oscilator::cCast_rrxaWU5n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4Nplzael, HV_BINOP_LESS_THAN, 0, m, &cBinop_4Nplzael_sendMessage);
}

void Heavy_oscilator::cBinop_4Nplzael_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_Q6CS4vbD, 1, m, &cIf_Q6CS4vbD_sendMessage);
}

void Heavy_oscilator::cCast_5t9tpNAr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4Nplzael, HV_BINOP_LESS_THAN, 1, m, &cBinop_4Nplzael_sendMessage);
}

void Heavy_oscilator::cCast_roA5WKeR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fXji3ZRT_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_CDoWbJPA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_q2JS4jXN, 0, m, &cVar_q2JS4jXN_sendMessage);
}

void Heavy_oscilator::cMsg_fXji3ZRT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_q2JS4jXN, 0, m, &cVar_q2JS4jXN_sendMessage);
}

void Heavy_oscilator::cCast_Eid6JHaY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_oe7Fev5H_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IOoWn9UY_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TdNLXSOi_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_zK3OarlH_sendMessage);
}

void Heavy_oscilator::cCast_l6itORnO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_CDoWbJPA_sendMessage);
}

void Heavy_oscilator::cVar_oCvcxc2c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IMlMRQyp, 0, m, &cVar_IMlMRQyp_sendMessage);
}

void Heavy_oscilator::cSwitchcase_huGNcOWF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_1gNtZtwi_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_oscilator::cCast_1gNtZtwi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JlfRMsVX_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vfmqlIEl_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_NwSzSGkl_sendMessage);
}

void Heavy_oscilator::cVar_bdxEN2LO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_0qzf5dlr_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cIf_21taUPIV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSwitchcase_S3g6vAoR_onMessage(_c, NULL, 0, m, NULL);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_dSrn7Mhx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_it1XHgiu_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cSwitchcase_S3g6vAoR_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Z2ZNQ1kL_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_oscilator::cCast_Z2ZNQ1kL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SGLisBZt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_e82tjvpC_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vjD740E9_sendMessage);
}

void Heavy_oscilator::cVar_YnhVUcLw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Jw8KnCTD, HV_BINOP_LESS_THAN, 1, m, &cBinop_Jw8KnCTD_sendMessage);
}

void Heavy_oscilator::cVar_d1TlPfTP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9TjiUpzZ, HV_BINOP_LESS_THAN, 1, m, &cBinop_9TjiUpzZ_sendMessage);
}

void Heavy_oscilator::cIf_wjZ51R2q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cSlice_onMessage(_c, &Context(_c)->cSlice_Essvpzzl, 0, m, &cSlice_Essvpzzl_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_3xHzL2kM, 0, m, &cSlice_3xHzL2kM_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6Q08VtIU_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ClQghk4o_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VDmdHjlf_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_AZVhY21F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dbH4GkFb_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_8NSfZI7Y, 0, m, &cSlice_8NSfZI7Y_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_2csz914V, 0, m, &cSlice_2csz914V_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_cj5xEPUr_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kbSmsluP_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dHeNZosh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cPack_i2GEUUPy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_AZVhY21F, 0, m, &cIf_AZVhY21F_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_wjZ51R2q, 0, m, &cIf_wjZ51R2q_sendMessage);
}

void Heavy_oscilator::cVar_sTIzApk2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_OWoZL6HW_sendMessage);
}

void Heavy_oscilator::cSlice_Essvpzzl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_P2sq9gCp, 2, m, &cPack_P2sq9gCp_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_3xHzL2kM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_YvkyJicu_onMessage(_c, NULL, 0, m, NULL);
      cPack_onMessage(_c, &Context(_c)->cPack_P2sq9gCp, 1, m, &cPack_P2sq9gCp_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_dTdWEODM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_OWoZL6HW_sendMessage);
}

void Heavy_oscilator::cIf_VnIksJEB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_AZVhY21F, 1, m, &cIf_AZVhY21F_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_hSRepmzI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_JaWKmLnt_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cVar_ogRxM92i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_jASrCI1F_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cTabread_7789y7SF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_6gOcSMJU_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_DyZakPJe_sendMessage);
}

void Heavy_oscilator::cSwitchcase_CBOUwBSj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_TQJ0Ylwn, 0, m, &cSlice_TQJ0Ylwn_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dfW1FZ8M_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_CQVklQ3m_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cSlice_TQJ0Ylwn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_7789y7SF, 1, m, &cTabread_7789y7SF_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_7789y7SF, 1, m, &cTabread_7789y7SF_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_ky7fTBNm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5r6X3yjF_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cSystem_KpLtstrt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_XYZrw796_sendMessage);
}

void Heavy_oscilator::cBinop_GzsSS4Y8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NE2wHN7w, HV_BINOP_MIN, 0, m, &cBinop_NE2wHN7w_sendMessage);
}

void Heavy_oscilator::cCast_CQVklQ3m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_GzsSS4Y8_sendMessage);
}

void Heavy_oscilator::cCast_dfW1FZ8M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ky7fTBNm, 0, m, &cVar_ky7fTBNm_sendMessage);
}

void Heavy_oscilator::cBinop_NE2wHN7w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_7789y7SF, 0, m, &cTabread_7789y7SF_sendMessage);
}

void Heavy_oscilator::cMsg_5r6X3yjF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_KpLtstrt_sendMessage);
}

void Heavy_oscilator::cBinop_XYZrw796_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NE2wHN7w, HV_BINOP_MIN, 1, m, &cBinop_NE2wHN7w_sendMessage);
}

void Heavy_oscilator::cTabread_yrDUVyM3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_qVNQSjhc_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_eIB4UPDb_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_HzRXn63s_sendMessage);
}

void Heavy_oscilator::cSwitchcase_zVgRGAg6_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ZBkHeBmw, 0, m, &cSlice_ZBkHeBmw_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JzuXM5Aw_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5UZ4a2J5_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cSlice_ZBkHeBmw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_yrDUVyM3, 1, m, &cTabread_yrDUVyM3_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_yrDUVyM3, 1, m, &cTabread_yrDUVyM3_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_rW8oWBb4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_b2Ipm47a_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cSystem_OMpbAFru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_CutoHqjd_sendMessage);
}

void Heavy_oscilator::cBinop_u6TBdN9B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QXzaP0aw, HV_BINOP_MIN, 0, m, &cBinop_QXzaP0aw_sendMessage);
}

void Heavy_oscilator::cCast_5UZ4a2J5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_u6TBdN9B_sendMessage);
}

void Heavy_oscilator::cCast_JzuXM5Aw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rW8oWBb4, 0, m, &cVar_rW8oWBb4_sendMessage);
}

void Heavy_oscilator::cBinop_QXzaP0aw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_yrDUVyM3, 0, m, &cTabread_yrDUVyM3_sendMessage);
}

void Heavy_oscilator::cMsg_b2Ipm47a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OMpbAFru_sendMessage);
}

void Heavy_oscilator::cBinop_CutoHqjd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QXzaP0aw, HV_BINOP_MIN, 1, m, &cBinop_QXzaP0aw_sendMessage);
}

void Heavy_oscilator::cTabwrite_HeX9YxwM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_oscilator::cSwitchcase_yYl6M65p_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_AWahCSRN, 0, m, &cSlice_AWahCSRN_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_HeX9YxwM, 0, m, &cTabwrite_HeX9YxwM_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cSlice_AWahCSRN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_HeX9YxwM, 2, m, &cTabwrite_HeX9YxwM_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_HeX9YxwM, 2, m, &cTabwrite_HeX9YxwM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cTabread_SMbAMKZh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_P2sq9gCp, 1, m, &cPack_P2sq9gCp_sendMessage);
}

void Heavy_oscilator::cSwitchcase_JaWKmLnt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_2YMOXPvV, 0, m, &cSlice_2YMOXPvV_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rVjiOOpM_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_75tIlUlB_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cSlice_2YMOXPvV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_SMbAMKZh, 1, m, &cTabread_SMbAMKZh_sendMessage);
      break;
    }
    case 1: {
      cTabread_onMessage(_c, &Context(_c)->cTabread_SMbAMKZh, 1, m, &cTabread_SMbAMKZh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_Oewi7VnM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rMhr5Sq0_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cSystem_NiIKkvll_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_QLPPwCzc_sendMessage);
}

void Heavy_oscilator::cBinop_O0aHfqBw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_b3KupEMg, HV_BINOP_MIN, 0, m, &cBinop_b3KupEMg_sendMessage);
}

void Heavy_oscilator::cCast_75tIlUlB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_O0aHfqBw_sendMessage);
}

void Heavy_oscilator::cCast_rVjiOOpM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Oewi7VnM, 0, m, &cVar_Oewi7VnM_sendMessage);
}

void Heavy_oscilator::cBinop_b3KupEMg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabread_onMessage(_c, &Context(_c)->cTabread_SMbAMKZh, 0, m, &cTabread_SMbAMKZh_sendMessage);
}

void Heavy_oscilator::cMsg_rMhr5Sq0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(3);
  msg_init(m, 3, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "table");
  msg_setElementToFrom(m, 1, n, 0);
  msg_setSymbol(m, 2, "length");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_NiIKkvll_sendMessage);
}

void Heavy_oscilator::cBinop_QLPPwCzc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_b3KupEMg, HV_BINOP_MIN, 1, m, &cBinop_b3KupEMg_sendMessage);
}

void Heavy_oscilator::cTabwrite_7tYryxHt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_oscilator::cSwitchcase_YvkyJicu_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_rnnTIWo4, 0, m, &cSlice_rnnTIWo4_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_7tYryxHt, 0, m, &cTabwrite_7tYryxHt_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cSlice_rnnTIWo4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_7tYryxHt, 2, m, &cTabwrite_7tYryxHt_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_7tYryxHt, 2, m, &cTabwrite_7tYryxHt_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cTabwrite_cASfqTdh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_oscilator::cSwitchcase_PPi3tc4A_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_amtOhOO0, 0, m, &cSlice_amtOhOO0_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_cASfqTdh, 0, m, &cTabwrite_cASfqTdh_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cSlice_amtOhOO0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_cASfqTdh, 2, m, &cTabwrite_cASfqTdh_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_cASfqTdh, 2, m, &cTabwrite_cASfqTdh_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cTabwrite_xoMQG02i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_oscilator::cSwitchcase_jASrCI1F_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_A1YbJdow, 0, m, &cSlice_A1YbJdow_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_xoMQG02i, 0, m, &cTabwrite_xoMQG02i_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cSlice_A1YbJdow_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_xoMQG02i, 2, m, &cTabwrite_xoMQG02i_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_xoMQG02i, 2, m, &cTabwrite_xoMQG02i_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cTabwrite_bq46fd6M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_oscilator::cSwitchcase_wG9pWkJE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_b82yW8Sz, 0, m, &cSlice_b82yW8Sz_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_bq46fd6M, 0, m, &cTabwrite_bq46fd6M_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cSlice_b82yW8Sz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_bq46fd6M, 2, m, &cTabwrite_bq46fd6M_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_bq46fd6M, 2, m, &cTabwrite_bq46fd6M_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_ZIm1hLKm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_wG9pWkJE_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cTabwrite_gsnF3ELF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_oscilator::cSwitchcase_2PdV9jxy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_YRSXVseO, 0, m, &cSlice_YRSXVseO_sendMessage);
      break;
    }
    default: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_gsnF3ELF, 0, m, &cTabwrite_gsnF3ELF_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cSlice_YRSXVseO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_gsnF3ELF, 2, m, &cTabwrite_gsnF3ELF_sendMessage);
      break;
    }
    case 1: {
      cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_gsnF3ELF, 2, m, &cTabwrite_gsnF3ELF_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_G4sfpKej_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_NgPqu7mN_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_GZn7kUNG_sendMessage);
}

void Heavy_oscilator::cSlice_8NSfZI7Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cPack_onMessage(_c, &Context(_c)->cPack_P2sq9gCp, 2, m, &cPack_P2sq9gCp_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_2csz914V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cSwitchcase_yYl6M65p_onMessage(_c, NULL, 0, m, NULL);
      cPack_onMessage(_c, &Context(_c)->cPack_P2sq9gCp, 1, m, &cPack_P2sq9gCp_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_9eUFWCxd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_K9L9KRB2, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_K9L9KRB2_sendMessage);
}

void Heavy_oscilator::cBinop_P7Uv29Fm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_kEUhDlZs_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xwmCMtGS_sendMessage);
}

void Heavy_oscilator::cBinop_Jw8KnCTD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mgeB0GQT, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_mgeB0GQT_sendMessage);
}

void Heavy_oscilator::cCast_zK3OarlH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_oscilator::cCast_TdNLXSOi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_CBOUwBSj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cCast_IOoWn9UY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_zVgRGAg6_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cCast_oe7Fev5H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bdxEN2LO, 1, m, &cVar_bdxEN2LO_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_dSrn7Mhx, 1, m, &cVar_dSrn7Mhx_sendMessage);
}

void Heavy_oscilator::cSend_0qzf5dlr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Q3VXyAPn_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_DyZakPJe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_4WifP3dN_sendMessage);
}

void Heavy_oscilator::cCast_6gOcSMJU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_P7Uv29Fm, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_P7Uv29Fm_sendMessage);
}

void Heavy_oscilator::cBinop_mgeB0GQT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_21taUPIV, 0, m, &cIf_21taUPIV_sendMessage);
}

void Heavy_oscilator::cBinop_4WifP3dN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mgeB0GQT, HV_BINOP_LOGICAL_AND, 0, m, &cBinop_mgeB0GQT_sendMessage);
}

void Heavy_oscilator::cCast_kEUhDlZs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_huGNcOWF_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cCast_xwmCMtGS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_BvgZegx1_sendMessage);
}

void Heavy_oscilator::cBinop_BvgZegx1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_21taUPIV, 1, m, &cIf_21taUPIV_sendMessage);
}

void Heavy_oscilator::cSend_it1XHgiu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_vJjS1xQ6_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cSend_0MP7Gslu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_Q3VXyAPn_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cSend_3uSzsZaD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_vJjS1xQ6_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_s1VjRz8u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ap8akXDk_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_QqIQbd99_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_oCvcxc2c, 0, m, &cVar_oCvcxc2c_sendMessage);
}

void Heavy_oscilator::cCast_2zNpbtAs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_G4sfpKej, 0, m, &cVar_G4sfpKej_sendMessage);
}

void Heavy_oscilator::cBinop_9TjiUpzZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_P7Uv29Fm, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_P7Uv29Fm_sendMessage);
}

void Heavy_oscilator::cCast_eIB4UPDb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9TjiUpzZ, HV_BINOP_LESS_THAN, 0, m, &cBinop_9TjiUpzZ_sendMessage);
}

void Heavy_oscilator::cCast_qVNQSjhc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YnhVUcLw, 1, m, &cVar_YnhVUcLw_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_d1TlPfTP, 1, m, &cVar_d1TlPfTP_sendMessage);
}

void Heavy_oscilator::cCast_HzRXn63s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Jw8KnCTD, HV_BINOP_LESS_THAN, 0, m, &cBinop_Jw8KnCTD_sendMessage);
}

void Heavy_oscilator::cCast_NgPqu7mN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_d1TlPfTP, 0, m, &cVar_d1TlPfTP_sendMessage);
}

void Heavy_oscilator::cCast_GZn7kUNG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YnhVUcLw, 0, m, &cVar_YnhVUcLw_sendMessage);
}

void Heavy_oscilator::cSend_w7hzeh3f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_aJr8kjZf_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_SGLisBZt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YnhVUcLw, 0, m, &cVar_YnhVUcLw_sendMessage);
}

void Heavy_oscilator::cCast_e82tjvpC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xrVNivPJ_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_vjD740E9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dSrn7Mhx, 0, m, &cVar_dSrn7Mhx_sendMessage);
}

void Heavy_oscilator::cMsg_xrVNivPJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_w7hzeh3f_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cMsg_fTaxcZaz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSend_GMnYWxi1_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cSend_GMnYWxi1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_0CnywkIA_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_JlfRMsVX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_d1TlPfTP, 0, m, &cVar_d1TlPfTP_sendMessage);
}

void Heavy_oscilator::cCast_NwSzSGkl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bdxEN2LO, 0, m, &cVar_bdxEN2LO_sendMessage);
}

void Heavy_oscilator::cCast_vfmqlIEl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_fTaxcZaz_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cMsg_ap8akXDk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSend_3uSzsZaD_sendMessage(_c, 0, m);
  cSend_0MP7Gslu_sendMessage(_c, 0, m);
  cSend_eQm3zzel_sendMessage(_c, 0, m);
  cSend_jJCzioWa_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cSend_eQm3zzel_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_0CnywkIA_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cSend_jJCzioWa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_aJr8kjZf_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_2RGN912O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_wjZ51R2q, 1, m, &cIf_wjZ51R2q_sendMessage);
}

void Heavy_oscilator::cCast_hrCexxA1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_6Hh75fqW_sendMessage);
}

void Heavy_oscilator::cBinop_K9L9KRB2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_VnIksJEB, 0, m, &cIf_VnIksJEB_sendMessage);
}

void Heavy_oscilator::cBinop_6Hh75fqW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9eUFWCxd, 0, m, &cVar_9eUFWCxd_sendMessage);
}

void Heavy_oscilator::cMsg_u6f6Q1YO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_PPi3tc4A_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cMsg_PIcePpoC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_2PdV9jxy_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_oscilator::cCast_9c1SUyb0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hSRepmzI, 0, m, &cVar_hSRepmzI_sendMessage);
}

void Heavy_oscilator::cCast_pUTZBd9F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dTdWEODM, 0, m, &cVar_dTdWEODM_sendMessage);
}

void Heavy_oscilator::cCast_wbkTu0AK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_e3thID7G_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cMsg_e3thID7G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_P2sq9gCp, 2, m, &cPack_P2sq9gCp_sendMessage);
}

void Heavy_oscilator::cCast_VDmdHjlf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3wuTdbRQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ydcySUE1_sendMessage);
}

void Heavy_oscilator::cCast_6Q08VtIU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sTIzApk2, 0, m, &cVar_sTIzApk2_sendMessage);
}

void Heavy_oscilator::cCast_ClQghk4o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_u6f6Q1YO_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_ydcySUE1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ogRxM92i, 0, m, &cVar_ogRxM92i_sendMessage);
}

void Heavy_oscilator::cCast_3wuTdbRQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_g3NMNw2t_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cSend_g3NMNw2t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_p9frMpch_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_qwMl7tsn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZIm1hLKm, 0, m, &cVar_ZIm1hLKm_sendMessage);
}

void Heavy_oscilator::cCast_AkISaG3l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_9ofpcyLW_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cSend_9ofpcyLW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_p9frMpch_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_dbH4GkFb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wbkTu0AK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9c1SUyb0_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_pUTZBd9F_sendMessage);
}

void Heavy_oscilator::cCast_cj5xEPUr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_dTdWEODM, 0, m, &cVar_dTdWEODM_sendMessage);
}

void Heavy_oscilator::cCast_dHeNZosh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AkISaG3l_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qwMl7tsn_sendMessage);
}

void Heavy_oscilator::cCast_kbSmsluP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PIcePpoC_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_8NJR096l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_K9L9KRB2, HV_BINOP_LOGICAL_AND, 1, m, &cBinop_K9L9KRB2_sendMessage);
}

void Heavy_oscilator::cCast_qaFxXUWO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9eUFWCxd, 0, m, &cVar_9eUFWCxd_sendMessage);
}

void Heavy_oscilator::cSend_cTJ90Sqi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_LnqE8L6a_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_mGTu0Vde_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XZsPoPQe, 1, m, &cVar_XZsPoPQe_sendMessage);
}

void Heavy_oscilator::cSend_yaUrHtmj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_3BIg37j0_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_OWoZL6HW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_P2sq9gCp, 0, m, &cPack_P2sq9gCp_sendMessage);
}

void Heavy_oscilator::cBinop_D85EKmZ1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_mGTu0Vde_sendMessage);
  cSend_yaUrHtmj_sendMessage(_c, 0, m);
}

void Heavy_oscilator::hTable_C5CCH3SW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_oscilator::hTable_gkOAMu6H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_oscilator::hTable_7bRFnRfg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_oscilator::cCast_VWcL3YFh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AFnPrKGk_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cCast_WZcmxr1Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_I34S85zw, 0, m, &cVar_I34S85zw_sendMessage);
}

void Heavy_oscilator::cSend_a31TwwhE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jeNHm6M2_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cMsg_AFnPrKGk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 65535.0f);
  cSend_a31TwwhE_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_TjgTlTXq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ssJNiM7O, 1, m, &cIf_ssJNiM7O_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_pEmJyJ5J_sendMessage);
}

void Heavy_oscilator::cBinop_pEmJyJ5J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ZCK6a8Rg, 1, m, &cIf_ZCK6a8Rg_sendMessage);
}

void Heavy_oscilator::cBinop_H5ywhhGO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_cTJ90Sqi_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_Vq8sL6FN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Qtb2pfjZ, m);
}

void Heavy_oscilator::cBinop_xFuFg9PO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_MSnmIugP, m);
}

void Heavy_oscilator::cBinop_dIi5ckR3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_sLxWwvVg, m);
}

void Heavy_oscilator::cBinop_ODnedi2o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_rQyx0UPr, m);
}

void Heavy_oscilator::cReceive_bhH65O66_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pDP65RWI, 0, m, &cVar_pDP65RWI_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_VWcL3YFh_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_WZcmxr1Y_sendMessage);
}

void Heavy_oscilator::cReceive_HMcP7h6w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_OyfiExI1, 0, m, &cSlice_OyfiExI1_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_szdZLL1Q, 0, m, &cSlice_szdZLL1Q_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_fx77tlyX, 0, m, &cSlice_fx77tlyX_sendMessage);
}

void Heavy_oscilator::cReceive_LnqE8L6a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_VnIksJEB, 1, m, &cIf_VnIksJEB_sendMessage);
}

void Heavy_oscilator::cReceive_3BIg37j0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yKk52p00, 1, m, &cVar_yKk52p00_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ogRxM92i, 1, m, &cVar_ogRxM92i_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ZIm1hLKm, 1, m, &cVar_ZIm1hLKm_sendMessage);
}

void Heavy_oscilator::cReceive_p9frMpch_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XZsPoPQe, 0, m, &cVar_XZsPoPQe_sendMessage);
}

void Heavy_oscilator::cReceive_jeNHm6M2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_g3f6IyrN, 1, m, &cVar_g3f6IyrN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_G4sfpKej, 1, m, &cVar_G4sfpKej_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_D85EKmZ1, HV_BINOP_MOD_UNIPOLAR, 1, m, &cBinop_D85EKmZ1_sendMessage);
}

void Heavy_oscilator::cReceive_Q3VXyAPn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_HeX9YxwM, 1, m, &cTabwrite_HeX9YxwM_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_gsnF3ELF, 1, m, &cTabwrite_gsnF3ELF_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_bq46fd6M, 1, m, &cTabwrite_bq46fd6M_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_dTdWEODM, 1, m, &cVar_dTdWEODM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_hSRepmzI, 1, m, &cVar_hSRepmzI_sendMessage);
}

void Heavy_oscilator::cReceive_vJjS1xQ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_sTIzApk2, 1, m, &cVar_sTIzApk2_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_xoMQG02i, 1, m, &cTabwrite_xoMQG02i_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_7tYryxHt, 1, m, &cTabwrite_7tYryxHt_sendMessage);
  cTabwrite_onMessage(_c, &Context(_c)->cTabwrite_cASfqTdh, 1, m, &cTabwrite_cASfqTdh_sendMessage);
}

void Heavy_oscilator::cReceive_aJr8kjZf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_hrCexxA1_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_2RGN912O_sendMessage);
}

void Heavy_oscilator::cReceive_0CnywkIA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_8NJR096l_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qaFxXUWO_sendMessage);
}




/*
 * Context Process Implementation
 */

int Heavy_oscilator::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }

  sendBangToReceiver(0xDD21C0EB); // send to __hv_bang~ on next cycle
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7;

  // input and output vars
  hv_bufferf_t O0, O1;

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_phasor_k_f(&sPhasor_9TTFfL4P, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf4), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf2), VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf0), VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_MSnmIugP, VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_bwoGldBa, VOf(Bf0));
    __hv_var_k_f(VOf(Bf4), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_abs_f(VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf4), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf4), VOf(Bf0));
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf5), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf6), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf2), VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf0), VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_sLxWwvVg, VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf1), VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_phasor_k_f(&sPhasor_lSzH15v1, VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf6), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf3), VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_Qtb2pfjZ, VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_f16rvLdx, VOf(Bf3));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf6), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf3));
    __hv_mul_f(VIf(Bf6), VIf(Bf3), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf2), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf7), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf3), VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_rQyx0UPr, VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf1), VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf5), VIf(O1), VOf(O1));
    __hv_add_f(VIf(Bf5), VIf(O0), VOf(O0));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed

}

int Heavy_oscilator::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s)
  float **const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_oscilator::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s), uninterleave
  float *const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float *const bOut = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));

  int n = processInline(bIn, bOut, n4);

  // interleave the heavy output into the output buffer
  #if HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 8, i += 16) {
    __m256 x = _mm256_load_ps(bOut+j);    // LLLLLLLL
    __m256 y = _mm256_load_ps(bOut+n4+j); // RRRRRRRR
    __m256 a = _mm256_unpacklo_ps(x, y);  // LRLRLRLR
    __m256 b = _mm256_unpackhi_ps(x, y);  // LRLRLRLR
    _mm256_store_ps(outputBuffers+i, a);
    _mm256_store_ps(outputBuffers+8+i, b);
  }
  #elif HV_SIMD_SSE
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 x = _mm_load_ps(bOut+j);    // LLLL
    __m128 y = _mm_load_ps(bOut+n4+j); // RRRR
    __m128 a = _mm_unpacklo_ps(x, y);  // LRLR
    __m128 b = _mm_unpackhi_ps(x, y);  // LRLR
    _mm_store_ps(outputBuffers+i, a);
    _mm_store_ps(outputBuffers+4+i, b);
  }
  #elif HV_SIMD_NEON
  // https://community.arm.com/groups/processors/blog/2012/03/13/coding-for-neon--part-5-rearranging-vectors
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4_t x = vld1q_f32(bOut+j);
    float32x4_t y = vld1q_f32(bOut+n4+j);
    float32x4x2_t z = {x, y};
    vst2q_f32(outputBuffers+i, z); // interleave and store
  }
  #else // HV_SIMD_NONE
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n4; ++j) {
      outputBuffers[i+2*j] = bOut[i*n4+j];
    }
  }
  #endif

  return n;
}
