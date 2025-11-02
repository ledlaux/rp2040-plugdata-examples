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
  numBytes += cPack_init(&cPack_u0ngRtFn, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_QcaGdRUU, 10.0f);
  numBytes += cVar_init_f(&cVar_aBSjve0W, 14.0f);
  numBytes += cPack_init(&cPack_Lx96UEDE, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_4RCfWBkq, 10.0f);
  numBytes += cBinop_init(&cBinop_wLymI3SM, 1.0f); // __pow
  numBytes += cPack_init(&cPack_cmSIv69j, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_tTsxbBwu, 10.0f);
  numBytes += cVar_init_f(&cVar_Rv5kDSLu, 34.0f);
  numBytes += cPack_init(&cPack_JwvupV61, 3, 0.0f, 0.0f, 0.0f);
  numBytes += cVar_init_f(&cVar_I6rG8Cqs, 10.0f);
  numBytes += cSlice_init(&cSlice_9y2Hg5HY, 2, 1);
  numBytes += cSlice_init(&cSlice_VLzrG9PS, 1, 1);
  numBytes += cSlice_init(&cSlice_KPJgTC0l, 0, 1);
  numBytes += cVar_init_f(&cVar_dbtf5AFD, 0.0f);
  numBytes += cIf_init(&cIf_ol6lAFBk, false);
  numBytes += cIf_init(&cIf_5Z5gXLwa, false);
  numBytes += cIf_init(&cIf_j2Vdze6n, false);
  numBytes += cIf_init(&cIf_6iokEYUL, false);
  numBytes += cIf_init(&cIf_TVgCCwF2, false);
  numBytes += cBinop_init(&cBinop_s73veP4M, 0.0f); // __eq
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_oscilator::~Heavy_oscilator() {
  cPack_free(&cPack_u0ngRtFn);
  cPack_free(&cPack_Lx96UEDE);
  cPack_free(&cPack_cmSIv69j);
  cPack_free(&cPack_JwvupV61);
}

HvTable *Heavy_oscilator::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_oscilator::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_IZ5X8eru_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_6ZhIBjYV_sendMessage);
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


void Heavy_oscilator::cPack_u0ngRtFn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_CdED32cU_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cVar_QcaGdRUU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_2W0EblFg_sendMessage);
}

void Heavy_oscilator::cVar_aBSjve0W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_u0ngRtFn, 1, m, &cPack_u0ngRtFn_sendMessage);
}

void Heavy_oscilator::cSend_CdED32cU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "__hv_ctlout", 0xE5E2A040, m);
}

void Heavy_oscilator::cCast_Qv38Muag_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aBSjve0W, 0, m, &cVar_aBSjve0W_sendMessage);
}

void Heavy_oscilator::cCast_ELGM5mTw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_QcaGdRUU, 0, m, &cVar_QcaGdRUU_sendMessage);
}

void Heavy_oscilator::cBinop_2W0EblFg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_aAK1nozs_sendMessage);
}

void Heavy_oscilator::cBinop_aAK1nozs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_u0ngRtFn, 2, m, &cPack_u0ngRtFn_sendMessage);
}

void Heavy_oscilator::cPack_Lx96UEDE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_pXCKFGJa_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cVar_4RCfWBkq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_DN6bVFo9_sendMessage);
}

void Heavy_oscilator::cSend_pXCKFGJa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "__hv_noteout", 0xD1D4AC2, m);
}

void Heavy_oscilator::cBinop_DN6bVFo9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_DKo3YyXX_sendMessage);
}

void Heavy_oscilator::cBinop_DKo3YyXX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Lx96UEDE, 2, m, &cPack_Lx96UEDE_sendMessage);
}

void Heavy_oscilator::cBinop_6erMLpkC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_uVNvRpVb_sendMessage);
}

void Heavy_oscilator::cBinop_zytXSzIK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_qqbBGBDg_sendMessage);
}

void Heavy_oscilator::cBinop_qqbBGBDg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wLymI3SM, HV_BINOP_POW, 1, m, &cBinop_wLymI3SM_sendMessage);
  cMsg_iv0z6e6z_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_wLymI3SM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_6erMLpkC_sendMessage);
}

void Heavy_oscilator::cMsg_iv0z6e6z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_wLymI3SM, HV_BINOP_POW, 0, m, &cBinop_wLymI3SM_sendMessage);
}

void Heavy_oscilator::cPack_cmSIv69j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_3JkO6qBB_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cVar_tTsxbBwu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_ZnkmrIma_sendMessage);
}

void Heavy_oscilator::cVar_Rv5kDSLu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_cmSIv69j, 1, m, &cPack_cmSIv69j_sendMessage);
}

void Heavy_oscilator::cSend_3JkO6qBB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "__hv_ctlout", 0xE5E2A040, m);
}

void Heavy_oscilator::cCast_5v7VioBq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tTsxbBwu, 0, m, &cVar_tTsxbBwu_sendMessage);
}

void Heavy_oscilator::cCast_aJ4Bb79j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Rv5kDSLu, 0, m, &cVar_Rv5kDSLu_sendMessage);
}

void Heavy_oscilator::cBinop_ZnkmrIma_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_nmvEbbRh_sendMessage);
}

void Heavy_oscilator::cBinop_nmvEbbRh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_cmSIv69j, 2, m, &cPack_cmSIv69j_sendMessage);
}

void Heavy_oscilator::cPack_JwvupV61_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_JrUy1jHG_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cVar_I6rG8Cqs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 1.0f, 0, m, &cBinop_r8H4XGWN_sendMessage);
}

void Heavy_oscilator::cSend_JrUy1jHG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "__hv_noteout", 0xD1D4AC2, m);
}

void Heavy_oscilator::cBinop_r8H4XGWN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_b4tsfoNk_sendMessage);
}

void Heavy_oscilator::cBinop_b4tsfoNk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_JwvupV61, 2, m, &cPack_JwvupV61_sendMessage);
}

void Heavy_oscilator::cSlice_9y2Hg5HY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_b59SOKh6_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_VLzrG9PS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_6iokEYUL, 0, m, &cIf_6iokEYUL_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_5Z5gXLwa, 0, m, &cIf_5Z5gXLwa_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_KPJgTC0l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_TVgCCwF2, 0, m, &cIf_TVgCCwF2_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_j2Vdze6n, 0, m, &cIf_j2Vdze6n_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_dbtf5AFD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_AIg4coJ3_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_ol6lAFBk, 0, m, &cIf_ol6lAFBk_sendMessage);
}

void Heavy_oscilator::cUnop_lNb4CtXo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_YRWmcwde_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_s73veP4M, HV_BINOP_EQ, 1, m, &cBinop_s73veP4M_sendMessage);
}

void Heavy_oscilator::cUnop_lS5lBuCf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_YRWmcwde_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_s73veP4M, HV_BINOP_EQ, 1, m, &cBinop_s73veP4M_sendMessage);
}

void Heavy_oscilator::cIf_ol6lAFBk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_lS5lBuCf_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_lNb4CtXo_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cBinop_AIg4coJ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_ol6lAFBk, 1, m, &cIf_ol6lAFBk_sendMessage);
}

void Heavy_oscilator::cIf_5Z5gXLwa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_Lx96UEDE, 1, m, &cPack_Lx96UEDE_sendMessage);
      cMsg_VzgLYf46_sendMessage(_c, 0, m);
      cPack_onMessage(_c, &Context(_c)->cPack_JwvupV61, 1, m, &cPack_JwvupV61_sendMessage);
      cMsg_d4LQPydT_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_j2Vdze6n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_zytXSzIK_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_cmSIv69j, 0, m, &cPack_cmSIv69j_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_6iokEYUL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cPack_onMessage(_c, &Context(_c)->cPack_Lx96UEDE, 1, m, &cPack_Lx96UEDE_sendMessage);
      cMsg_VzgLYf46_sendMessage(_c, 0, m);
      cPack_onMessage(_c, &Context(_c)->cPack_JwvupV61, 1, m, &cPack_JwvupV61_sendMessage);
      cMsg_d4LQPydT_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_TVgCCwF2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_zytXSzIK_sendMessage);
      cPack_onMessage(_c, &Context(_c)->cPack_cmSIv69j, 0, m, &cPack_cmSIv69j_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cBinop_b59SOKh6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_s73veP4M, HV_BINOP_EQ, 0, m, &cBinop_s73veP4M_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_57hpGTAJ_sendMessage);
}

void Heavy_oscilator::cBinop_YRWmcwde_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_YsDpsnpF_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yaIMPsaR_sendMessage);
}

void Heavy_oscilator::cBinop_s73veP4M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lUvvd4B6_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lIrqArQH_sendMessage);
}

void Heavy_oscilator::cCast_lUvvd4B6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_5Z5gXLwa, 1, m, &cIf_5Z5gXLwa_sendMessage);
}

void Heavy_oscilator::cCast_lIrqArQH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_TVgCCwF2, 1, m, &cIf_TVgCCwF2_sendMessage);
}

void Heavy_oscilator::cCast_YsDpsnpF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_6iokEYUL, 1, m, &cIf_6iokEYUL_sendMessage);
}

void Heavy_oscilator::cCast_yaIMPsaR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_j2Vdze6n, 1, m, &cIf_j2Vdze6n_sendMessage);
}

void Heavy_oscilator::cBinop_57hpGTAJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_oscilator::cMsg_VzgLYf46_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 60.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_Lx96UEDE, 0, m, &cPack_Lx96UEDE_sendMessage);
}

void Heavy_oscilator::cBinop_uVNvRpVb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_u0ngRtFn, 0, m, &cPack_u0ngRtFn_sendMessage);
}

void Heavy_oscilator::cMsg_d4LQPydT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 62.0f);
  cPack_onMessage(_c, &Context(_c)->cPack_JwvupV61, 0, m, &cPack_JwvupV61_sendMessage);
}

void Heavy_oscilator::cReceive_IZ5X8eru_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ELGM5mTw_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Qv38Muag_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_4RCfWBkq, 0, m, &cVar_4RCfWBkq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5v7VioBq_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_aJ4Bb79j_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_I6rG8Cqs, 0, m, &cVar_I6rG8Cqs_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_dbtf5AFD, 0, m, &cVar_dbtf5AFD_sendMessage);
}

void Heavy_oscilator::cReceive_6ZhIBjYV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_9y2Hg5HY, 0, m, &cSlice_9y2Hg5HY_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_VLzrG9PS, 0, m, &cSlice_VLzrG9PS_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_KPJgTC0l, 0, m, &cSlice_KPJgTC0l_sendMessage);
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

  // input and output vars

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

    

    

    // process all signal functions

    // save output vars to output buffer
    // no output channels
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed

}

int Heavy_oscilator::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s)
  float **const bIn = NULL;

  // define the heavy output buffer for 0 channel(s)
  float **const bOut = NULL;

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_oscilator::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s), uninterleave
  float *const bIn = NULL;

  // define the heavy output buffer for 0 channel(s)
  float *const bOut = NULL;

  int n = processInline(bIn, bOut, n4);

  

  return n;
}
