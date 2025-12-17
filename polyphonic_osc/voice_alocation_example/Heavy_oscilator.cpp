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
  numBytes += sPhasor_k_init(&sPhasor_XtuDQoQB, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_WAOmmqA7);
  numBytes += sPhasor_k_init(&sPhasor_BZfVAUWz, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_SyL3HYU6);
  numBytes += sPhasor_k_init(&sPhasor_mx1uxoa3, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_b4gt287u);
  numBytes += sPhasor_k_init(&sPhasor_ZEJEPzFH, 0.0f, sampleRate);
  numBytes += sLine_init(&sLine_D881Bpvt);
  numBytes += cBinop_init(&cBinop_jbsCUpDe, 1.0f); // __pow
  numBytes += cBinop_init(&cBinop_gjxC5qYg, 1.0f); // __pow
  numBytes += cSlice_init(&cSlice_IIa5NYth, 2, 1);
  numBytes += cSlice_init(&cSlice_DgzAooSE, 1, 1);
  numBytes += cSlice_init(&cSlice_O4vPlpgh, 0, 1);
  numBytes += cSlice_init(&cSlice_pM8u4mPU, 2, 1);
  numBytes += cSlice_init(&cSlice_QSKsPuuX, 1, 1);
  numBytes += cSlice_init(&cSlice_dSJpyJCQ, 0, 1);
  numBytes += cBinop_init(&cBinop_YwPC1pWg, 1.0f); // __pow
  numBytes += cSlice_init(&cSlice_T6nQn2kH, 2, 1);
  numBytes += cSlice_init(&cSlice_0VGYP0EB, 1, 1);
  numBytes += cSlice_init(&cSlice_luQJsZ7E, 0, 1);
  numBytes += cBinop_init(&cBinop_Y4fyvnIz, 1.0f); // __pow
  numBytes += cSlice_init(&cSlice_Gd8WC6sw, 2, 1);
  numBytes += cSlice_init(&cSlice_OPSY8lkQ, 1, 1);
  numBytes += cSlice_init(&cSlice_AFbBnTYv, 0, 1);
  numBytes += cPack_init(&cPack_vCu2Cusd, 2, 0.0f, 5.0f);
  numBytes += cPack_init(&cPack_Ls1wcijM, 2, 0.0f, 5.0f);
  numBytes += cPack_init(&cPack_HTZM58Y9, 2, 0.0f, 5.0f);
  numBytes += cPack_init(&cPack_glXvntLP, 2, 0.0f, 5.0f);
  
}

Heavy_oscilator::~Heavy_oscilator() {
  cPack_free(&cPack_vCu2Cusd);
  cPack_free(&cPack_Ls1wcijM);
  cPack_free(&cPack_HTZM58Y9);
  cPack_free(&cPack_glXvntLP);
}

HvTable *Heavy_oscilator::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_oscilator::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x3E185FE5: { // NOTE1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_S0fIdlZu_sendMessage);
      break;
    }
    case 0x3C682D20: { // NOTE2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_wjpK1801_sendMessage);
      break;
    }
    case 0xC430EA70: { // NOTE3
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_TJs1JUUV_sendMessage);
      break;
    }
    case 0xD3ABA527: { // NOTE4
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zx5shqUg_sendMessage);
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


void Heavy_oscilator::cBinop_cg41Gqtk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_XtuDQoQB, 0, m);
}

void Heavy_oscilator::cBinop_EY1P2A0h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_0VLYRrNB_sendMessage);
}

void Heavy_oscilator::cBinop_0VLYRrNB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_jbsCUpDe, HV_BINOP_POW, 1, m, &cBinop_jbsCUpDe_sendMessage);
  cMsg_rDmePiEP_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_jbsCUpDe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_cg41Gqtk_sendMessage);
}

void Heavy_oscilator::cMsg_rDmePiEP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_jbsCUpDe, HV_BINOP_POW, 0, m, &cBinop_jbsCUpDe_sendMessage);
}

void Heavy_oscilator::cBinop_UFTbQk4B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_BZfVAUWz, 0, m);
}

void Heavy_oscilator::cBinop_Zqp7mc1z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_uxnxImgN_sendMessage);
}

void Heavy_oscilator::cBinop_uxnxImgN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_gjxC5qYg, HV_BINOP_POW, 1, m, &cBinop_gjxC5qYg_sendMessage);
  cMsg_SpWF8eJU_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_gjxC5qYg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_UFTbQk4B_sendMessage);
}

void Heavy_oscilator::cMsg_SpWF8eJU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_gjxC5qYg, HV_BINOP_POW, 0, m, &cBinop_gjxC5qYg_sendMessage);
}

void Heavy_oscilator::cSlice_IIa5NYth_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_oscilator::cSlice_DgzAooSE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_fAbtnOoW_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_O4vPlpgh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_EY1P2A0h_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_pM8u4mPU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_oscilator::cSlice_QSKsPuuX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_qtxz2QWv_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_dSJpyJCQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_Zqp7mc1z_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cBinop_BqIeQUK6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_mx1uxoa3, 0, m);
}

void Heavy_oscilator::cBinop_xU94TP7F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_IVttf39Q_sendMessage);
}

void Heavy_oscilator::cBinop_IVttf39Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YwPC1pWg, HV_BINOP_POW, 1, m, &cBinop_YwPC1pWg_sendMessage);
  cMsg_ILAD9ncV_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_YwPC1pWg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_BqIeQUK6_sendMessage);
}

void Heavy_oscilator::cMsg_ILAD9ncV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_YwPC1pWg, HV_BINOP_POW, 0, m, &cBinop_YwPC1pWg_sendMessage);
}

void Heavy_oscilator::cSlice_T6nQn2kH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_oscilator::cSlice_0VGYP0EB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_r8vNMfwD_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_luQJsZ7E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_xU94TP7F_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cBinop_kDj9wEAm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_ZEJEPzFH, 0, m);
}

void Heavy_oscilator::cBinop_iUpPv6O6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_tHplGilX_sendMessage);
}

void Heavy_oscilator::cBinop_tHplGilX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y4fyvnIz, HV_BINOP_POW, 1, m, &cBinop_Y4fyvnIz_sendMessage);
  cMsg_gEKC9bKb_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_Y4fyvnIz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_kDj9wEAm_sendMessage);
}

void Heavy_oscilator::cMsg_gEKC9bKb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y4fyvnIz, HV_BINOP_POW, 0, m, &cBinop_Y4fyvnIz_sendMessage);
}

void Heavy_oscilator::cSlice_Gd8WC6sw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_oscilator::cSlice_OPSY8lkQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_WMG6yV4g_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_AFbBnTYv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_iUpPv6O6_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cPack_vCu2Cusd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_D881Bpvt, 0, m, NULL);
}

void Heavy_oscilator::cPack_Ls1wcijM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_b4gt287u, 0, m, NULL);
}

void Heavy_oscilator::cPack_HTZM58Y9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_SyL3HYU6, 0, m, NULL);
}

void Heavy_oscilator::cPack_glXvntLP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sLine_onMessage(_c, &Context(_c)->sLine_WAOmmqA7, 0, m, NULL);
}

void Heavy_oscilator::cBinop_WMG6yV4g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.7f, 0, m, &cBinop_yDbGEGkO_sendMessage);
}

void Heavy_oscilator::cBinop_r8vNMfwD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.7f, 0, m, &cBinop_YOQnQo5E_sendMessage);
}

void Heavy_oscilator::cBinop_qtxz2QWv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.7f, 0, m, &cBinop_bQsCFJxC_sendMessage);
}

void Heavy_oscilator::cBinop_fAbtnOoW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 0.7f, 0, m, &cBinop_buBSmkWC_sendMessage);
}

void Heavy_oscilator::cBinop_buBSmkWC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_glXvntLP, 0, m, &cPack_glXvntLP_sendMessage);
}

void Heavy_oscilator::cBinop_bQsCFJxC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_HTZM58Y9, 0, m, &cPack_HTZM58Y9_sendMessage);
}

void Heavy_oscilator::cBinop_YOQnQo5E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_Ls1wcijM, 0, m, &cPack_Ls1wcijM_sendMessage);
}

void Heavy_oscilator::cBinop_yDbGEGkO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cPack_onMessage(_c, &Context(_c)->cPack_vCu2Cusd, 0, m, &cPack_vCu2Cusd_sendMessage);
}

void Heavy_oscilator::cReceive_S0fIdlZu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_IIa5NYth, 0, m, &cSlice_IIa5NYth_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_DgzAooSE, 0, m, &cSlice_DgzAooSE_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_O4vPlpgh, 0, m, &cSlice_O4vPlpgh_sendMessage);
}

void Heavy_oscilator::cReceive_wjpK1801_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_pM8u4mPU, 0, m, &cSlice_pM8u4mPU_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_QSKsPuuX, 0, m, &cSlice_QSKsPuuX_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_dSJpyJCQ, 0, m, &cSlice_dSJpyJCQ_sendMessage);
}

void Heavy_oscilator::cReceive_TJs1JUUV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_T6nQn2kH, 0, m, &cSlice_T6nQn2kH_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_0VGYP0EB, 0, m, &cSlice_0VGYP0EB_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_luQJsZ7E, 0, m, &cSlice_luQJsZ7E_sendMessage);
}

void Heavy_oscilator::cReceive_zx5shqUg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_Gd8WC6sw, 0, m, &cSlice_Gd8WC6sw_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_OPSY8lkQ, 0, m, &cSlice_OPSY8lkQ_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_AFbBnTYv, 0, m, &cSlice_AFbBnTYv_sendMessage);
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
    __hv_phasor_k_f(&sPhasor_XtuDQoQB, VOf(Bf0));
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
    __hv_line_f(&sLine_WAOmmqA7, VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_phasor_k_f(&sPhasor_BZfVAUWz, VOf(Bf0));
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
    __hv_line_f(&sLine_SyL3HYU6, VOf(Bf5));
    __hv_mul_f(VIf(Bf4), VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf4), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_mul_f(VIf(Bf5), VIf(Bf4), VOf(Bf4));
    __hv_fma_f(VIf(Bf3), VIf(Bf1), VIf(Bf4), VOf(Bf4));
    __hv_phasor_k_f(&sPhasor_mx1uxoa3, VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_abs_f(VIf(Bf3), VOf(Bf3));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf3), VOf(Bf1));
    __hv_mul_f(VIf(Bf3), VIf(Bf1), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf6), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf5), VIf(Bf6), VIf(Bf3), VOf(Bf3));
    __hv_fma_f(VIf(Bf1), VIf(Bf0), VIf(Bf3), VOf(Bf3));
    __hv_line_f(&sLine_b4gt287u, VOf(Bf0));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_phasor_k_f(&sPhasor_ZEJEPzFH, VOf(Bf1));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf6), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf1));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf7), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf5), VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf1), VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_line_f(&sLine_D881Bpvt, VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf0), VIf(Bf3), VIf(Bf6), VOf(Bf6));
    __hv_add_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf4), 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f, 0.6f);
    __hv_mul_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_min_f(VIf(Bf4), VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf4), -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f, -0.5f);
    __hv_max_f(VIf(Bf6), VIf(Bf4), VOf(Bf4));
    __hv_add_f(VIf(Bf4), VIf(O0), VOf(O0));
    __hv_add_f(VIf(Bf4), VIf(O1), VOf(O1));

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
