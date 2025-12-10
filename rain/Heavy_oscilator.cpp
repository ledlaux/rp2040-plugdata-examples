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
  numBytes += sLine_init(&sLine_wCieg1Ax);
  numBytes += sLine_init(&sLine_EQow6klP);
  numBytes += sLine_init(&sLine_Y0V7d2iX);
  numBytes += sBiquad_k_init(&sBiquad_k_XRAOuAFX, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sRPole_init(&sRPole_5HUoRBvn);
  numBytes += sRPole_init(&sRPole_TAIk2z3J);
  numBytes += sBiquad_k_init(&sBiquad_k_s2efIq3b, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sRPole_init(&sRPole_vwhq28qR);
  numBytes += sRPole_init(&sRPole_lwVKV3ly);
  numBytes += sRPole_init(&sRPole_Dc0nT1PE);
  numBytes += sDel1_init(&sDel1_cyKQpS63);
  numBytes += sRPole_init(&sRPole_17Lle2VY);
  numBytes += sDel1_init(&sDel1_6y8cj2fu);
  numBytes += sRPole_init(&sRPole_jaJFMRGf);
  numBytes += sDel1_init(&sDel1_DaZxmg4J);
  numBytes += sRPole_init(&sRPole_sBJQMQRA);
  numBytes += sDel1_init(&sDel1_ZOlLlFca);
  numBytes += cRandom_init(&cRandom_pSx81fIF, -1143481732);
  numBytes += cSlice_init(&cSlice_acOgP3GP, 1, 1);
  numBytes += sVari_init(&sVari_S59PosZD, 0, 0, false);
  numBytes += cVar_init_f(&cVar_QZ0BkUE3, 4000.0f);
  numBytes += cVar_init_f(&cVar_6NmxUAak, 10.0f);
  numBytes += cBinop_init(&cBinop_Xj3fH6T3, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_xvHSuBdo, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_zAoXzo4f, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Mh1m2zgQ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_hDtblQgX, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_DNsmcuZr, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_hkQUPKth, 500.0f);
  numBytes += cBinop_init(&cBinop_AvLtiuqt, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_GMJS16ZI, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_aejQccwH, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_iW1w4dEm, 500.0f);
  numBytes += cBinop_init(&cBinop_UA1E7qA6, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_Q9Z7C158, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_WOlLLjn2, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Srq3XaVH, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_wmbxDrp2, 0.0f);
  numBytes += cBinop_init(&cBinop_AdYQBNGM, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_LYYNs6g4, 0.0f, 0.0f, false);
  numBytes += cRandom_init(&cRandom_kTy7EKXx, -1121896194);
  numBytes += cSlice_init(&cSlice_lriMrn0I, 1, 1);
  numBytes += sVari_init(&sVari_36WuY7Hv, 0, 0, false);
  numBytes += cVar_init_f(&cVar_PHLL2CLM, 4000.0f);
  numBytes += cVar_init_f(&cVar_YwUjmQRp, 10.0f);
  numBytes += cBinop_init(&cBinop_9pZ4AJTs, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_2wehNVen, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_P81CbORz, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_D15DLOIs, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_JxkXJcnT, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_QacMDV1H, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_lwGtO5KD, 500.0f);
  numBytes += cBinop_init(&cBinop_JHbJp02C, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_v9aMS89y, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_NxnKugmj, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_EsDVgNUg, 500.0f);
  numBytes += cBinop_init(&cBinop_drz10Vbc, 0.0f); // __mul
  numBytes += sVarf_init(&sVarf_xheJQvZd, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_57SS1SN7, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_J3eMaYyI, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_KTt3dF38, 0.0f);
  numBytes += cBinop_init(&cBinop_kA92kZus, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_0gHdZJY9, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_eYuy1EF0, 0.0f);
  numBytes += cVar_init_f(&cVar_IdOhdnFj, 0.0f);
  numBytes += cVar_init_f(&cVar_1adPNYLl, 0.0f);
  numBytes += cVar_init_f(&cVar_KM6ZNbOv, 0.0f);
  numBytes += cVar_init_f(&cVar_DZrKzlzU, 0.0f);
  numBytes += cVar_init_f(&cVar_UILOwbUA, 0.0f);
  numBytes += cVar_init_f(&cVar_pW8mTZ8R, 0.0f);
  numBytes += cVar_init_f(&cVar_VDNBZnC9, 0.0f);
  numBytes += sVarf_init(&sVarf_vwxala6I, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_fzwtMBXq, 3.0f);
  numBytes += cBinop_init(&cBinop_vu28iXTf, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_h4AvpEel, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_sVAHYHjp, 0.0f, 0.0f, false);
  numBytes += cVar_init_f(&cVar_styvMVdb, 3.0f);
  numBytes += cBinop_init(&cBinop_A7CfznwS, 0.0f); // __div
  numBytes += sVarf_init(&sVarf_gqKDCcSz, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_NBo0uCOz, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_h7LowYJC, 0.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_9UX9VceC, 0.0f, 0.0f, false);
  numBytes += cBinop_init(&cBinop_BSqjZoHM, 6.0f); // __mul
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_oscilator::~Heavy_oscilator() {
  // nothing to free
}

HvTable *Heavy_oscilator::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_oscilator::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_bYdOyYgs_sendMessage);
      break;
    }
    case 0x7924B13C: { // cracles
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_UkRjy56L_sendMessage);
      break;
    }
    case 0x86883492: { // dropamount
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_BnLswJ9N_sendMessage);
      break;
    }
    case 0xE480BBEA: { // dropgain
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Zix1ipZH_sendMessage);
      break;
    }
    case 0x3EC7528A: { // dropsize
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_KzBWnpRq_sendMessage);
      break;
    }
    case 0x21FB2849: { // drp-amt
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_dwHMvZ2y_sendMessage);
      break;
    }
    case 0xDF89A8D2: { // drp-sze
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jp58OVra_sendMessage);
      break;
    }
    case 0x474D7361: { // hip
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_exKCFX9a_sendMessage);
      break;
    }
    case 0xF8569716: { // hipass
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_mF9ooz26_sendMessage);
      break;
    }
    case 0xDA41E7A3: { // int
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_o7Sr4AAd_sendMessage);
      break;
    }
    case 0x3D836879: { // intensity
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_7IfN2eDV_sendMessage);
      break;
    }
    case 0x4AD2D14C: { // size
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Gb5xzF9G_sendMessage);
      break;
    }
    case 0xAC6ABCD2: { // sze
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_PrunwJiS_sendMessage);
      break;
    }
    case 0xAE05860F: { // wind
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_MtAQsm7E_sendMessage);
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


void Heavy_oscilator::cSwitchcase_FhgN4NxL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_acOgP3GP, 0, m, &cSlice_acOgP3GP_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_pSx81fIF, 0, m, &cRandom_pSx81fIF_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cBinop_ov2nYH8F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_m08mg4rP_sendMessage);
}

void Heavy_oscilator::cUnop_m08mg4rP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_l4F44jR9_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cRandom_pSx81fIF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_ov2nYH8F_sendMessage);
}

void Heavy_oscilator::cSlice_acOgP3GP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_pSx81fIF, 1, m, &cRandom_pSx81fIF_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cMsg_l4F44jR9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_S59PosZD, m);
}

void Heavy_oscilator::cMsg_ZS4JMQ9R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8Zk20blT_sendMessage);
}

void Heavy_oscilator::cSystem_8Zk20blT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xj3fH6T3, HV_BINOP_DIVIDE, 1, m, &cBinop_Xj3fH6T3_sendMessage);
}

void Heavy_oscilator::cVar_QZ0BkUE3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_rp8Q9Ksl_sendMessage);
}

void Heavy_oscilator::cVar_6NmxUAak_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_hKbAMdp9_sendMessage);
}

void Heavy_oscilator::cUnop_DfSCjz8k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_bxR7EyAm_sendMessage);
}

void Heavy_oscilator::cBinop_Xj3fH6T3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Mh1m2zgQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_Mh1m2zgQ_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_DfSCjz8k_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_xvHSuBdo, HV_BINOP_DIVIDE, 0, m, &cBinop_xvHSuBdo_sendMessage);
}

void Heavy_oscilator::cBinop_rp8Q9Ksl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Xj3fH6T3, HV_BINOP_DIVIDE, 0, m, &cBinop_Xj3fH6T3_sendMessage);
}

void Heavy_oscilator::cBinop_xvHSuBdo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_TnLiuki4_sendMessage);
}

void Heavy_oscilator::cBinop_FyVQ7Zuk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_27DjrAiX_sendMessage);
}

void Heavy_oscilator::cBinop_27DjrAiX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_XysbqxKt_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zAoXzo4f, HV_BINOP_MULTIPLY, 0, m, &cBinop_zAoXzo4f_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Mh1m2zgQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_Mh1m2zgQ_sendMessage);
}

void Heavy_oscilator::cBinop_bxR7EyAm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zAoXzo4f, HV_BINOP_MULTIPLY, 1, m, &cBinop_zAoXzo4f_sendMessage);
}

void Heavy_oscilator::cBinop_zAoXzo4f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_qHCfgCUC_sendMessage);
}

void Heavy_oscilator::cCast_ghe8aUUl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QZ0BkUE3, 0, m, &cVar_QZ0BkUE3_sendMessage);
}

void Heavy_oscilator::cBinop_o6STFMWH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_mimBSeTW_sendMessage);
}

void Heavy_oscilator::cBinop_mimBSeTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_XRAOuAFX, 5, m);
}

void Heavy_oscilator::cBinop_qHCfgCUC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_XRAOuAFX, 4, m);
}

void Heavy_oscilator::cBinop_lahS6OeI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DNsmcuZr, HV_BINOP_MULTIPLY, 0, m, &cBinop_DNsmcuZr_sendMessage);
}

void Heavy_oscilator::cBinop_Mh1m2zgQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hDtblQgX, HV_BINOP_ADD, 1, m, &cBinop_hDtblQgX_sendMessage);
}

void Heavy_oscilator::cBinop_XysbqxKt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_o6STFMWH_sendMessage);
}

void Heavy_oscilator::cBinop_hDtblQgX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DNsmcuZr, HV_BINOP_MULTIPLY, 1, m, &cBinop_DNsmcuZr_sendMessage);
}

void Heavy_oscilator::cBinop_DNsmcuZr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_XRAOuAFX, 1, m);
}

void Heavy_oscilator::cBinop_hKbAMdp9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_xvHSuBdo, HV_BINOP_DIVIDE, 1, m, &cBinop_xvHSuBdo_sendMessage);
}

void Heavy_oscilator::cBinop_TnLiuki4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_FyVQ7Zuk_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hDtblQgX, HV_BINOP_ADD, 0, m, &cBinop_hDtblQgX_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_lahS6OeI_sendMessage);
}

void Heavy_oscilator::cVar_hkQUPKth_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AvLtiuqt, HV_BINOP_MULTIPLY, 0, m, &cBinop_AvLtiuqt_sendMessage);
}

void Heavy_oscilator::cMsg_VDCYvuOe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GQBnWOdJ_sendMessage);
}

void Heavy_oscilator::cSystem_GQBnWOdJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kOerC2NE_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_AvLtiuqt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_m7PNMZEJ_sendMessage);
}

void Heavy_oscilator::cBinop_NLAMBht3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AvLtiuqt, HV_BINOP_MULTIPLY, 1, m, &cBinop_AvLtiuqt_sendMessage);
}

void Heavy_oscilator::cMsg_kOerC2NE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_NLAMBht3_sendMessage);
}

void Heavy_oscilator::cBinop_m7PNMZEJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_peZ811oC_sendMessage);
}

void Heavy_oscilator::cBinop_peZ811oC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_Jpqa8Aiy_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_aejQccwH, m);
}

void Heavy_oscilator::cBinop_Jpqa8Aiy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_GMJS16ZI, m);
}

void Heavy_oscilator::cVar_iW1w4dEm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UA1E7qA6, HV_BINOP_MULTIPLY, 0, m, &cBinop_UA1E7qA6_sendMessage);
}

void Heavy_oscilator::cMsg_FLQV2kQD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_3zsBjvgX_sendMessage);
}

void Heavy_oscilator::cSystem_3zsBjvgX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_sSICcPs3_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_UA1E7qA6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_skoIeMg5_sendMessage);
}

void Heavy_oscilator::cBinop_jibWlvuR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UA1E7qA6, HV_BINOP_MULTIPLY, 1, m, &cBinop_UA1E7qA6_sendMessage);
}

void Heavy_oscilator::cMsg_sSICcPs3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_jibWlvuR_sendMessage);
}

void Heavy_oscilator::cBinop_skoIeMg5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_kCwsRjQS_sendMessage);
}

void Heavy_oscilator::cBinop_kCwsRjQS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_1L7oTdrc_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_WOlLLjn2, m);
}

void Heavy_oscilator::cBinop_1L7oTdrc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Q9Z7C158, m);
}

void Heavy_oscilator::cBinop_AQVhiK5q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_MxE7alXN_sendMessage);
}

void Heavy_oscilator::cBinop_MxE7alXN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_HUFMqKJA_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_X0ivxRpo_sendMessage);
}

void Heavy_oscilator::cVar_wmbxDrp2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_AwQCRK5X_sendMessage);
}

void Heavy_oscilator::cMsg_1tsDFKPY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_oR8HZsZn_sendMessage);
}

void Heavy_oscilator::cSystem_oR8HZsZn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AdYQBNGM, HV_BINOP_DIVIDE, 1, m, &cBinop_AdYQBNGM_sendMessage);
}

void Heavy_oscilator::cBinop_HUFMqKJA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_98mzf2ze_sendMessage);
}

void Heavy_oscilator::cBinop_98mzf2ze_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_LYYNs6g4, m);
}

void Heavy_oscilator::cMsg_LPQ1LUzi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_e9Wmdo0J_sendMessage);
}

void Heavy_oscilator::cBinop_e9Wmdo0J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_AQVhiK5q_sendMessage);
}

void Heavy_oscilator::cBinop_X0ivxRpo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Srq3XaVH, m);
}

void Heavy_oscilator::cBinop_AwQCRK5X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_GPqSZOIx_sendMessage);
}

void Heavy_oscilator::cBinop_GPqSZOIx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_AdYQBNGM, HV_BINOP_DIVIDE, 0, m, &cBinop_AdYQBNGM_sendMessage);
}

void Heavy_oscilator::cBinop_AdYQBNGM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LPQ1LUzi_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cSwitchcase_bHkEZxmW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  int msgIndex = 0;
  switch (msg_getHash(m, msgIndex)) {
    case 0x6D60E6E: { // "symbol"
      msgIndex = 1;
      break;
    }
  }
  switch (msg_getHash(m, msgIndex)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_lriMrn0I, 0, m, &cSlice_lriMrn0I_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_kTy7EKXx, 0, m, &cRandom_kTy7EKXx_sendMessage);
      break;
    }
  }
}

void Heavy_oscilator::cBinop_RD033ZyO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_GcFmMgzy_sendMessage);
}

void Heavy_oscilator::cUnop_GcFmMgzy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yMnDcoCR_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cRandom_kTy7EKXx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_RD033ZyO_sendMessage);
}

void Heavy_oscilator::cSlice_lriMrn0I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_kTy7EKXx, 1, m, &cRandom_kTy7EKXx_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cMsg_yMnDcoCR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_36WuY7Hv, m);
}

void Heavy_oscilator::cMsg_Rc02LkeD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_7GWlY9P1_sendMessage);
}

void Heavy_oscilator::cSystem_7GWlY9P1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9pZ4AJTs, HV_BINOP_DIVIDE, 1, m, &cBinop_9pZ4AJTs_sendMessage);
}

void Heavy_oscilator::cVar_PHLL2CLM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_siFiPbMn_sendMessage);
}

void Heavy_oscilator::cVar_YwUjmQRp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_GW9QhCWu_sendMessage);
}

void Heavy_oscilator::cUnop_xrpNi7A1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_PXcEy4MU_sendMessage);
}

void Heavy_oscilator::cBinop_9pZ4AJTs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_D15DLOIs, HV_BINOP_MULTIPLY, 1, m, &cBinop_D15DLOIs_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_xrpNi7A1_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_2wehNVen, HV_BINOP_DIVIDE, 0, m, &cBinop_2wehNVen_sendMessage);
}

void Heavy_oscilator::cBinop_siFiPbMn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9pZ4AJTs, HV_BINOP_DIVIDE, 0, m, &cBinop_9pZ4AJTs_sendMessage);
}

void Heavy_oscilator::cBinop_2wehNVen_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_2P2kKXWe_sendMessage);
}

void Heavy_oscilator::cBinop_MG51sjIY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_B31QZepo_sendMessage);
}

void Heavy_oscilator::cBinop_B31QZepo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_ImpnIOGr_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_P81CbORz, HV_BINOP_MULTIPLY, 0, m, &cBinop_P81CbORz_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_D15DLOIs, HV_BINOP_MULTIPLY, 0, m, &cBinop_D15DLOIs_sendMessage);
}

void Heavy_oscilator::cBinop_PXcEy4MU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_P81CbORz, HV_BINOP_MULTIPLY, 1, m, &cBinop_P81CbORz_sendMessage);
}

void Heavy_oscilator::cBinop_P81CbORz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_cgHFPrxE_sendMessage);
}

void Heavy_oscilator::cCast_PgHOiUx4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PHLL2CLM, 0, m, &cVar_PHLL2CLM_sendMessage);
}

void Heavy_oscilator::cBinop_P2u9NvUN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_Z3GdE8i7_sendMessage);
}

void Heavy_oscilator::cBinop_Z3GdE8i7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_s2efIq3b, 5, m);
}

void Heavy_oscilator::cBinop_cgHFPrxE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_s2efIq3b, 4, m);
}

void Heavy_oscilator::cBinop_kgkwtweE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QacMDV1H, HV_BINOP_MULTIPLY, 0, m, &cBinop_QacMDV1H_sendMessage);
}

void Heavy_oscilator::cBinop_D15DLOIs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JxkXJcnT, HV_BINOP_ADD, 1, m, &cBinop_JxkXJcnT_sendMessage);
}

void Heavy_oscilator::cBinop_ImpnIOGr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_P2u9NvUN_sendMessage);
}

void Heavy_oscilator::cBinop_JxkXJcnT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QacMDV1H, HV_BINOP_MULTIPLY, 1, m, &cBinop_QacMDV1H_sendMessage);
}

void Heavy_oscilator::cBinop_QacMDV1H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_s2efIq3b, 1, m);
}

void Heavy_oscilator::cBinop_GW9QhCWu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2wehNVen, HV_BINOP_DIVIDE, 1, m, &cBinop_2wehNVen_sendMessage);
}

void Heavy_oscilator::cBinop_2P2kKXWe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_MG51sjIY_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JxkXJcnT, HV_BINOP_ADD, 0, m, &cBinop_JxkXJcnT_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_kgkwtweE_sendMessage);
}

void Heavy_oscilator::cVar_lwGtO5KD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JHbJp02C, HV_BINOP_MULTIPLY, 0, m, &cBinop_JHbJp02C_sendMessage);
}

void Heavy_oscilator::cMsg_WKAdOun3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FcPJjp8y_sendMessage);
}

void Heavy_oscilator::cSystem_FcPJjp8y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_bIexzAJD_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_JHbJp02C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_1xOhMkYe_sendMessage);
}

void Heavy_oscilator::cBinop_ontYPAgV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JHbJp02C, HV_BINOP_MULTIPLY, 1, m, &cBinop_JHbJp02C_sendMessage);
}

void Heavy_oscilator::cMsg_bIexzAJD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_ontYPAgV_sendMessage);
}

void Heavy_oscilator::cBinop_1xOhMkYe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_VR33yC6s_sendMessage);
}

void Heavy_oscilator::cBinop_VR33yC6s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_vMM9yGxC_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_NxnKugmj, m);
}

void Heavy_oscilator::cBinop_vMM9yGxC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_v9aMS89y, m);
}

void Heavy_oscilator::cVar_EsDVgNUg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_drz10Vbc, HV_BINOP_MULTIPLY, 0, m, &cBinop_drz10Vbc_sendMessage);
}

void Heavy_oscilator::cMsg_UEh4knts_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fDf4V5fT_sendMessage);
}

void Heavy_oscilator::cSystem_fDf4V5fT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ip9m4Asd_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_drz10Vbc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_z7WGV6ww_sendMessage);
}

void Heavy_oscilator::cBinop_pAEx3lFo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_drz10Vbc, HV_BINOP_MULTIPLY, 1, m, &cBinop_drz10Vbc_sendMessage);
}

void Heavy_oscilator::cMsg_ip9m4Asd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 6.28319f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 0.0f, 0, m, &cBinop_pAEx3lFo_sendMessage);
}

void Heavy_oscilator::cBinop_z7WGV6ww_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_5cfDobne_sendMessage);
}

void Heavy_oscilator::cBinop_5cfDobne_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_dxQiKY9P_sendMessage);
  sVarf_onMessage(_c, &Context(_c)->sVarf_57SS1SN7, m);
}

void Heavy_oscilator::cBinop_dxQiKY9P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_xheJQvZd, m);
}

void Heavy_oscilator::cBinop_DkKCz6i3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_9HdKxzMQ_sendMessage);
}

void Heavy_oscilator::cBinop_9HdKxzMQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_wcS580O3_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_QolFXuNn_sendMessage);
}

void Heavy_oscilator::cVar_KTt3dF38_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_T9zJ0cQS_sendMessage);
}

void Heavy_oscilator::cMsg_OIzXGALD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_FdwFEq9g_sendMessage);
}

void Heavy_oscilator::cSystem_FdwFEq9g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kA92kZus, HV_BINOP_DIVIDE, 1, m, &cBinop_kA92kZus_sendMessage);
}

void Heavy_oscilator::cBinop_wcS580O3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_kChTQRgv_sendMessage);
}

void Heavy_oscilator::cBinop_kChTQRgv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_0gHdZJY9, m);
}

void Heavy_oscilator::cMsg_Bj9XWomg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_Swm11T17_sendMessage);
}

void Heavy_oscilator::cBinop_Swm11T17_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_DkKCz6i3_sendMessage);
}

void Heavy_oscilator::cBinop_QolFXuNn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_J3eMaYyI, m);
}

void Heavy_oscilator::cBinop_T9zJ0cQS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_CmgSHPGB_sendMessage);
}

void Heavy_oscilator::cBinop_CmgSHPGB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kA92kZus, HV_BINOP_DIVIDE, 0, m, &cBinop_kA92kZus_sendMessage);
}

void Heavy_oscilator::cBinop_kA92kZus_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Bj9XWomg_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cVar_eYuy1EF0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AzJQmpLV_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cVar_IdOhdnFj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Pr5xdVQv_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cVar_1adPNYLl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AF3SIm0f_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cVar_KM6ZNbOv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IRULhrJB_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cVar_DZrKzlzU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_MC4XRr1I_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cVar_UILOwbUA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_pqCCseVC_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cVar_pW8mTZ8R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_dRLtw7cY_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cVar_VDNBZnC9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_zGGKAEgV_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_APoQxbMf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_xvuR8Tqc_sendMessage);
}

void Heavy_oscilator::cBinop_xvuR8Tqc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Ivah2bwC_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_cOTZtaVc_sendMessage);
}

void Heavy_oscilator::cVar_fzwtMBXq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_dqtwBth2_sendMessage);
}

void Heavy_oscilator::cMsg_2r4HKoVS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MnQtnIAP_sendMessage);
}

void Heavy_oscilator::cSystem_MnQtnIAP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vu28iXTf, HV_BINOP_DIVIDE, 1, m, &cBinop_vu28iXTf_sendMessage);
}

void Heavy_oscilator::cBinop_Ivah2bwC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_g2DDTeUQ_sendMessage);
}

void Heavy_oscilator::cBinop_g2DDTeUQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_h4AvpEel, m);
}

void Heavy_oscilator::cMsg_GEUECMTe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_CfZCxG2G_sendMessage);
}

void Heavy_oscilator::cBinop_CfZCxG2G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_APoQxbMf_sendMessage);
}

void Heavy_oscilator::cBinop_cOTZtaVc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_vwxala6I, m);
}

void Heavy_oscilator::cBinop_dqtwBth2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_sryIS9V1_sendMessage);
}

void Heavy_oscilator::cBinop_sryIS9V1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vu28iXTf, HV_BINOP_DIVIDE, 0, m, &cBinop_vu28iXTf_sendMessage);
}

void Heavy_oscilator::cBinop_vu28iXTf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GEUECMTe_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_TtgOhFjz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_bzWifuLy_sendMessage);
}

void Heavy_oscilator::cBinop_bzWifuLy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_83MIeR2s_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_kRSENVeW_sendMessage);
}

void Heavy_oscilator::cVar_styvMVdb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_JKZFgdQ4_sendMessage);
}

void Heavy_oscilator::cMsg_qE0CCRtT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_17v21Dk4_sendMessage);
}

void Heavy_oscilator::cSystem_17v21Dk4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A7CfznwS, HV_BINOP_DIVIDE, 1, m, &cBinop_A7CfznwS_sendMessage);
}

void Heavy_oscilator::cBinop_83MIeR2s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.5f, 0, m, &cBinop_4HcGycn9_sendMessage);
}

void Heavy_oscilator::cBinop_4HcGycn9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_gqKDCcSz, m);
}

void Heavy_oscilator::cMsg_xFewYxLT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_iuJgYpUu_sendMessage);
}

void Heavy_oscilator::cBinop_iuJgYpUu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_TtgOhFjz_sendMessage);
}

void Heavy_oscilator::cBinop_kRSENVeW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_sVAHYHjp, m);
}

void Heavy_oscilator::cBinop_JKZFgdQ4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_Hjcse34s_sendMessage);
}

void Heavy_oscilator::cBinop_Hjcse34s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_A7CfznwS, HV_BINOP_DIVIDE, 0, m, &cBinop_A7CfznwS_sendMessage);
}

void Heavy_oscilator::cBinop_A7CfznwS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xFewYxLT_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_5vnVF0gA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eYuy1EF0, 0, m, &cVar_eYuy1EF0_sendMessage);
}

void Heavy_oscilator::cMsg_AzJQmpLV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Y0V7d2iX, 0, m, NULL);
}

void Heavy_oscilator::cBinop_sYYVgJ3D_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 14.0f, 0, m, &cBinop_OzoqjoYF_sendMessage);
}

void Heavy_oscilator::cMsg_MHyk0gvq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 0.0f, 0, m, &cBinop_SKqxXKtX_sendMessage);
}

void Heavy_oscilator::cBinop_SKqxXKtX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IdOhdnFj, 0, m, &cVar_IdOhdnFj_sendMessage);
}

void Heavy_oscilator::cBinop_OzoqjoYF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MHyk0gvq_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cSend_Pr5xdVQv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_exKCFX9a_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_EoIpSoP2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 4.0f, 0, m, &cBinop_mjn4A4Ek_sendMessage);
}

void Heavy_oscilator::cMsg_AF3SIm0f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_EQow6klP, 0, m, NULL);
}

void Heavy_oscilator::cBinop_MC88R0BS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_KM6ZNbOv, 0, m, &cVar_KM6ZNbOv_sendMessage);
}

void Heavy_oscilator::cMsg_IRULhrJB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_wCieg1Ax, 0, m, NULL);
}

void Heavy_oscilator::cBinop_krjgFZ1h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BSqjZoHM, HV_BINOP_MULTIPLY, 0, m, &cBinop_BSqjZoHM_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BSqjZoHM, HV_BINOP_MULTIPLY, 1, m, &cBinop_BSqjZoHM_sendMessage);
}

void Heavy_oscilator::cBinop_4B1j5e6d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.0f, 0, m, &cBinop_QkJ831iz_sendMessage);
}

void Heavy_oscilator::cMsg_wTF4yiES_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 0.0f, 0, m, &cBinop_l18dUWfP_sendMessage);
}

void Heavy_oscilator::cBinop_l18dUWfP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 250.0f, 0, m, &cBinop_1o006dG3_sendMessage);
}

void Heavy_oscilator::cBinop_YfHXMrak_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.0f, 0, m, &cBinop_SBZSlPS0_sendMessage);
}

void Heavy_oscilator::cMsg_zdfwBkCN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 0.0f, 0, m, &cBinop_kggWLTWd_sendMessage);
}

void Heavy_oscilator::cBinop_kggWLTWd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 250.0f, 0, m, &cBinop_hHgG7jRK_sendMessage);
}

void Heavy_oscilator::cMsg_xom41Bsp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 0.0f, 0, m, &cBinop_bHGzmT9Y_sendMessage);
}

void Heavy_oscilator::cBinop_bHGzmT9Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.7f, 0, m, &cBinop_UvX2Gnj3_sendMessage);
}

void Heavy_oscilator::cBinop_UvX2Gnj3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DZrKzlzU, 0, m, &cVar_DZrKzlzU_sendMessage);
}

void Heavy_oscilator::cSend_MC4XRr1I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_o7Sr4AAd_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_edDto8QF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xom41Bsp_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cMsg_817lCv6y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 0.0f, 0, m, &cBinop_UNQXJDkq_sendMessage);
}

void Heavy_oscilator::cBinop_UNQXJDkq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5.0f, 0, m, &cBinop_edDto8QF_sendMessage);
}

void Heavy_oscilator::cBinop_1o006dG3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_UILOwbUA, 0, m, &cVar_UILOwbUA_sendMessage);
}

void Heavy_oscilator::cBinop_hHgG7jRK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_pW8mTZ8R, 0, m, &cVar_pW8mTZ8R_sendMessage);
}

void Heavy_oscilator::cBinop_QkJ831iz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wTF4yiES_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cSend_pqCCseVC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_jp58OVra_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_SBZSlPS0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zdfwBkCN_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cSend_dRLtw7cY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_PrunwJiS_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cMsg_pfWOsWHx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  msg_setElementToFrom(m, 1, n, 0);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 0.0f, 0, m, &cBinop_x64my1nh_sendMessage);
}

void Heavy_oscilator::cBinop_x64my1nh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 250.0f, 0, m, &cBinop_8AehJCoX_sendMessage);
}

void Heavy_oscilator::cBinop_8AehJCoX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_VDNBZnC9, 0, m, &cVar_VDNBZnC9_sendMessage);
}

void Heavy_oscilator::cBinop_BSqjZoHM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pfWOsWHx_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cSend_zGGKAEgV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cReceive_dwHMvZ2y_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_mjn4A4Ek_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1adPNYLl, 0, m, &cVar_1adPNYLl_sendMessage);
}

void Heavy_oscilator::cReceive_bYdOyYgs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_FhgN4NxL_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_6NmxUAak, 0, m, &cVar_6NmxUAak_sendMessage);
  cMsg_ZS4JMQ9R_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_QZ0BkUE3, 0, m, &cVar_QZ0BkUE3_sendMessage);
  cMsg_VDCYvuOe_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_hkQUPKth, 0, m, &cVar_hkQUPKth_sendMessage);
  cMsg_FLQV2kQD_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_iW1w4dEm, 0, m, &cVar_iW1w4dEm_sendMessage);
  cMsg_1tsDFKPY_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_wmbxDrp2, 0, m, &cVar_wmbxDrp2_sendMessage);
  cSwitchcase_bHkEZxmW_onMessage(_c, NULL, 0, m, NULL);
  cVar_onMessage(_c, &Context(_c)->cVar_YwUjmQRp, 0, m, &cVar_YwUjmQRp_sendMessage);
  cMsg_Rc02LkeD_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_PHLL2CLM, 0, m, &cVar_PHLL2CLM_sendMessage);
  cMsg_WKAdOun3_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_lwGtO5KD, 0, m, &cVar_lwGtO5KD_sendMessage);
  cMsg_UEh4knts_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_EsDVgNUg, 0, m, &cVar_EsDVgNUg_sendMessage);
  cMsg_OIzXGALD_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_KTt3dF38, 0, m, &cVar_KTt3dF38_sendMessage);
  cMsg_2r4HKoVS_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_fzwtMBXq, 0, m, &cVar_fzwtMBXq_sendMessage);
  cMsg_qE0CCRtT_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_styvMVdb, 0, m, &cVar_styvMVdb_sendMessage);
}

void Heavy_oscilator::cReceive_exKCFX9a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wmbxDrp2, 0, m, &cVar_wmbxDrp2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_KTt3dF38, 0, m, &cVar_KTt3dF38_sendMessage);
}

void Heavy_oscilator::cReceive_dwHMvZ2y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hkQUPKth, 0, m, &cVar_hkQUPKth_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lwGtO5KD, 0, m, &cVar_lwGtO5KD_sendMessage);
}

void Heavy_oscilator::cReceive_jp58OVra_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_iW1w4dEm, 0, m, &cVar_iW1w4dEm_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_EsDVgNUg, 0, m, &cVar_EsDVgNUg_sendMessage);
}

void Heavy_oscilator::cReceive_PrunwJiS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QZ0BkUE3, 0, m, &cVar_QZ0BkUE3_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_PHLL2CLM, 0, m, &cVar_PHLL2CLM_sendMessage);
}

void Heavy_oscilator::cReceive_o7Sr4AAd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_6NmxUAak, 0, m, &cVar_6NmxUAak_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ghe8aUUl_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_YwUjmQRp, 0, m, &cVar_YwUjmQRp_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PgHOiUx4_sendMessage);
}

void Heavy_oscilator::cReceive_UkRjy56L_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_5vnVF0gA_sendMessage);
}

void Heavy_oscilator::cReceive_mF9ooz26_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_sYYVgJ3D_sendMessage);
}

void Heavy_oscilator::cReceive_BnLswJ9N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_krjgFZ1h_sendMessage);
}

void Heavy_oscilator::cReceive_7IfN2eDV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_817lCv6y_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cReceive_MtAQsm7E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_EoIpSoP2_sendMessage);
}

void Heavy_oscilator::cReceive_Zix1ipZH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_MC88R0BS_sendMessage);
}

void Heavy_oscilator::cReceive_KzBWnpRq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_4B1j5e6d_sendMessage);
}

void Heavy_oscilator::cReceive_Gb5xzF9G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_YfHXMrak_sendMessage);
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
  hv_bufferi_t Bi0, Bi1;

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
    __hv_line_f(&sLine_wCieg1Ax, VOf(Bf0));
    __hv_varwrite_f(&sVarf_NBo0uCOz, VIf(Bf0));
    __hv_varread_f(&sVarf_NBo0uCOz, VOf(Bf0));
    __hv_varread_f(&sVarf_NBo0uCOz, VOf(Bf0));
    __hv_line_f(&sLine_EQow6klP, VOf(Bf0));
    __hv_varwrite_f(&sVarf_h7LowYJC, VIf(Bf0));
    __hv_line_f(&sLine_Y0V7d2iX, VOf(Bf0));
    __hv_varwrite_f(&sVarf_9UX9VceC, VIf(Bf0));
    __hv_varread_i(&sVari_S59PosZD, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_i(&sVari_S59PosZD, VIi(Bi1));
    __hv_varread_f(&sVarf_9UX9VceC, VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_biquad_k_f(&sBiquad_k_XRAOuAFX, VIf(Bf1), VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf1));
    __hv_varread_f(&sVarf_aejQccwH, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_GMJS16ZI, VOf(Bf3));
    __hv_rpole_f(&sRPole_5HUoRBvn, VIf(Bf2), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_varread_f(&sVarf_WOlLLjn2, VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_Q9Z7C158, VOf(Bf3));
    __hv_rpole_f(&sRPole_TAIk2z3J, VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_varread_i(&sVari_36WuY7Hv, VOi(Bi1));
    __hv_var_k_i(VOi(Bi0), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi1), VIi(Bi0), VOi(Bi0));
    __hv_cast_if(VIi(Bi0), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_varwrite_i(&sVari_36WuY7Hv, VIi(Bi0));
    __hv_biquad_k_f(&sBiquad_k_s2efIq3b, VIf(Bf4), VOf(Bf2));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf5));
    __hv_varread_f(&sVarf_NxnKugmj, VOf(Bf6));
    __hv_mul_f(VIf(Bf5), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_v9aMS89y, VOf(Bf7));
    __hv_rpole_f(&sRPole_vwhq28qR, VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_mul_f(VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_57SS1SN7, VOf(Bf5));
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_xheJQvZd, VOf(Bf7));
    __hv_rpole_f(&sRPole_lwVKV3ly, VIf(Bf5), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_9UX9VceC, VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_J3eMaYyI, VOf(Bf5));
    __hv_rpole_f(&sRPole_Dc0nT1PE, VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_cyKQpS63, VIf(Bf5), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_sub_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_0gHdZJY9, VOf(Bf5));
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_add_f(VIf(Bf7), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_h7LowYJC, VOf(Bf7));
    __hv_var_k_f(VOf(Bf2), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_min_f(VIf(ZERO), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf4), -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f);
    __hv_max_f(VIf(Bf2), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf5), VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_sVAHYHjp, VOf(Bf7));
    __hv_rpole_f(&sRPole_17Lle2VY, VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_6y8cj2fu, VIf(Bf7), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_gqKDCcSz, VOf(Bf7));
    __hv_mul_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf4), 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f);
    __hv_mul_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf7), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_min_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf4), -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f);
    __hv_max_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf7), 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f);
    __hv_mul_f(VIf(Bf4), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf7), VIf(O1), VOf(O1));
    __hv_varread_f(&sVarf_Srq3XaVH, VOf(Bf7));
    __hv_rpole_f(&sRPole_jaJFMRGf, VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_DaZxmg4J, VIf(Bf7), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf0), VOf(Bf0));
    __hv_sub_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_varread_f(&sVarf_LYYNs6g4, VOf(Bf7));
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_h7LowYJC, VOf(Bf3));
    __hv_var_k_f(VOf(Bf0), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_min_f(VIf(ZERO), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf4), -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f);
    __hv_max_f(VIf(Bf0), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf7), VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_vwxala6I, VOf(Bf3));
    __hv_rpole_f(&sRPole_sBJQMQRA, VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_del1_f(&sDel1_ZOlLlFca, VIf(Bf3), VOf(Bf7));
    __hv_mul_f(VIf(Bf7), VIf(Bf4), VOf(Bf4));
    __hv_sub_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_varread_f(&sVarf_h4AvpEel, VOf(Bf3));
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f);
    __hv_mul_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f);
    __hv_min_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf4), -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f, -1.0f);
    __hv_max_f(VIf(Bf3), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf3), 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f, 0.7f);
    __hv_mul_f(VIf(Bf4), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O0), VOf(O0));

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
