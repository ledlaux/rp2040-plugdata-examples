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
  numBytes += sPhasor_k_init(&sPhasor_hUMXaXly, 0.0f, sampleRate);
  numBytes += cSlice_init(&cSlice_66sHqFgk, 2, 1);
  numBytes += cSlice_init(&cSlice_52Nz8ImW, 1, 1);
  numBytes += cSlice_init(&cSlice_EI3LyykQ, 0, 1);
  numBytes += cVar_init_f(&cVar_q3Htr5Wt, 0.0f);
  numBytes += cIf_init(&cIf_IQe3iwZy, false);
  numBytes += cIf_init(&cIf_XpNmC7WM, false);
  numBytes += cIf_init(&cIf_B5e6vxyu, false);
  numBytes += cIf_init(&cIf_UUyPWGVP, false);
  numBytes += cIf_init(&cIf_3Qwfj41I, false);
  numBytes += cBinop_init(&cBinop_hiFB0E2c, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_puB0iSYC, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_v0cNX2VM, 7.0f);
  numBytes += cIf_init(&cIf_deZl0ZAZ, true);
  numBytes += cVar_init_f(&cVar_3I01IfAM, 0.0f);
  numBytes += cIf_init(&cIf_GOhtmszl, false);
  numBytes += cSlice_init(&cSlice_on4M24GN, 2, 1);
  numBytes += cSlice_init(&cSlice_V3LWlsPI, 1, 1);
  numBytes += cSlice_init(&cSlice_LLpFa3pz, 0, 1);
  numBytes += cIf_init(&cIf_gBA3bHw8, false);
  numBytes += cIf_init(&cIf_GbDyaecG, false);
  numBytes += cIf_init(&cIf_JyCDiBJt, false);
  numBytes += cIf_init(&cIf_xbO63Eai, true);
  numBytes += cIf_init(&cIf_cTeJ8XGs, true);
  numBytes += cIf_init(&cIf_FTrqDZhX, true);
  numBytes += cIf_init(&cIf_93Eh0LwW, true);
  numBytes += cIf_init(&cIf_oQDixDYY, false);
  numBytes += cIf_init(&cIf_kDXLIr6e, false);
  numBytes += cVar_init_f(&cVar_divug7Z8, 0.0f);
  numBytes += cBinop_init(&cBinop_zv2Mzoub, 0.0f); // __eq
  numBytes += cBinop_init(&cBinop_XrNHH7Lc, 0.0f); // __eq
  numBytes += sVarf_init(&sVarf_lxQEULKi, 0.0f, 0.0f, false);
  
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
    case 0x41BE0F9C: { // __hv_ctlin
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_LHiH8pq2_sendMessage);
      break;
    }
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_1P4ZcJ1b_sendMessage);
      break;
    }
    case 0x67E37CA3: { // __hv_notein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_rfYDlMmS_sendMessage);
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


void Heavy_oscilator::cSlice_66sHqFgk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Q2A30gVK_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_52Nz8ImW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_UUyPWGVP, 0, m, &cIf_UUyPWGVP_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_XpNmC7WM, 0, m, &cIf_XpNmC7WM_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_EI3LyykQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_3Qwfj41I, 0, m, &cIf_3Qwfj41I_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_B5e6vxyu, 0, m, &cIf_B5e6vxyu_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cVar_q3Htr5Wt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Dcq6cOZB_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_IQe3iwZy, 0, m, &cIf_IQe3iwZy_sendMessage);
}

void Heavy_oscilator::cUnop_uzCdSOAI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_GE13W33Y_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hiFB0E2c, HV_BINOP_EQ, 1, m, &cBinop_hiFB0E2c_sendMessage);
}

void Heavy_oscilator::cUnop_Gov2pf34_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_GE13W33Y_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hiFB0E2c, HV_BINOP_EQ, 1, m, &cBinop_hiFB0E2c_sendMessage);
}

void Heavy_oscilator::cIf_IQe3iwZy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_Gov2pf34_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_uzCdSOAI_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cBinop_Dcq6cOZB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_IQe3iwZy, 1, m, &cIf_IQe3iwZy_sendMessage);
}

void Heavy_oscilator::cIf_XpNmC7WM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_oscilator::cIf_B5e6vxyu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_1T59bdiM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_UUyPWGVP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_oscilator::cIf_3Qwfj41I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_1T59bdiM_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cBinop_Q2A30gVK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hiFB0E2c, HV_BINOP_EQ, 0, m, &cBinop_hiFB0E2c_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_Ync0n4Z9_sendMessage);
}

void Heavy_oscilator::cBinop_GE13W33Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_POqpuZsZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_sUN60GUp_sendMessage);
}

void Heavy_oscilator::cBinop_hiFB0E2c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QULfFwBT_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_TJU9d5DE_sendMessage);
}

void Heavy_oscilator::cCast_QULfFwBT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_XpNmC7WM, 1, m, &cIf_XpNmC7WM_sendMessage);
}

void Heavy_oscilator::cCast_TJU9d5DE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_3Qwfj41I, 1, m, &cIf_3Qwfj41I_sendMessage);
}

void Heavy_oscilator::cCast_sUN60GUp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_B5e6vxyu, 1, m, &cIf_B5e6vxyu_sendMessage);
}

void Heavy_oscilator::cCast_POqpuZsZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_UUyPWGVP, 1, m, &cIf_UUyPWGVP_sendMessage);
}

void Heavy_oscilator::cBinop_Ync0n4Z9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_oscilator::cBinop_hCqE5rex_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_hUMXaXly, 0, m);
}

void Heavy_oscilator::cBinop_1T59bdiM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_BOefzlDZ_sendMessage);
}

void Heavy_oscilator::cBinop_BOefzlDZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_puB0iSYC, HV_BINOP_POW, 1, m, &cBinop_puB0iSYC_sendMessage);
  cMsg_P9h1IYZA_sendMessage(_c, 0, m);
}

void Heavy_oscilator::cBinop_puB0iSYC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_hCqE5rex_sendMessage);
}

void Heavy_oscilator::cMsg_P9h1IYZA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_puB0iSYC, HV_BINOP_POW, 0, m, &cBinop_puB0iSYC_sendMessage);
}

void Heavy_oscilator::cVar_v0cNX2VM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_Oypo1Tri_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_deZl0ZAZ, 0, m, &cIf_deZl0ZAZ_sendMessage);
}

void Heavy_oscilator::cUnop_BuKZ700Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BfOctmHc_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_krInV8n0_sendMessage);
}

void Heavy_oscilator::cUnop_hi9ZL6ia_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_BfOctmHc_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_krInV8n0_sendMessage);
}

void Heavy_oscilator::cIf_deZl0ZAZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_hi9ZL6ia_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_BuKZ700Y_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cBinop_Oypo1Tri_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_deZl0ZAZ, 1, m, &cIf_deZl0ZAZ_sendMessage);
}

void Heavy_oscilator::cVar_3I01IfAM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_MndSxQUm_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_GOhtmszl, 0, m, &cIf_GOhtmszl_sendMessage);
}

void Heavy_oscilator::cUnop_DtOaqFK0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lu9Lkgce_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5wDckaZC_sendMessage);
}

void Heavy_oscilator::cUnop_ykA3Or0x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_lu9Lkgce_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5wDckaZC_sendMessage);
}

void Heavy_oscilator::cIf_GOhtmszl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_ykA3Or0x_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_DtOaqFK0_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cBinop_MndSxQUm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_GOhtmszl, 1, m, &cIf_GOhtmszl_sendMessage);
}

void Heavy_oscilator::cSlice_on4M24GN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_jl00kaiS_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_V3LWlsPI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_GbDyaecG, 0, m, &cIf_GbDyaecG_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_zv2Mzoub, HV_BINOP_EQ, 0, m, &cBinop_zv2Mzoub_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cSlice_LLpFa3pz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cIf_onMessage(_c, &Context(_c)->cIf_gBA3bHw8, 0, m, &cIf_gBA3bHw8_sendMessage);
      cIf_onMessage(_c, &Context(_c)->cIf_JyCDiBJt, 0, m, &cIf_JyCDiBJt_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_gBA3bHw8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_yzNTrQuF_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_GbDyaecG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_oscilator::cIf_JyCDiBJt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_cTeJ8XGs, 0, m, &cIf_cTeJ8XGs_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_xbO63Eai_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_93Eh0LwW, 0, m, &cIf_93Eh0LwW_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_cTeJ8XGs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cIf_onMessage(_c, &Context(_c)->cIf_FTrqDZhX, 0, m, &cIf_FTrqDZhX_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_FTrqDZhX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 127.0f, 0, m, &cBinop_yzNTrQuF_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_93Eh0LwW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_oscilator::cIf_oQDixDYY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      break;
    }
    case 1: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_XrNHH7Lc, HV_BINOP_EQ, 0, m, &cBinop_XrNHH7Lc_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_oscilator::cIf_kDXLIr6e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
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

void Heavy_oscilator::cVar_divug7Z8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_xbO63Eai, 0, m, &cIf_xbO63Eai_sendMessage);
}

void Heavy_oscilator::cBinop_jl00kaiS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_bS6prW85_sendMessage);
}

void Heavy_oscilator::cBinop_bS6prW85_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_VleWRtgj_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OdOUN704_sendMessage);
}

void Heavy_oscilator::cBinop_zv2Mzoub_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_nV4ZrTF6_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_25gKwYEQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0cefhfw0_sendMessage);
}

void Heavy_oscilator::cCast_krInV8n0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_bzMFnMCr_sendMessage);
}

void Heavy_oscilator::cCast_BfOctmHc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zv2Mzoub, HV_BINOP_EQ, 1, m, &cBinop_zv2Mzoub_sendMessage);
}

void Heavy_oscilator::cBinop_bzMFnMCr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QnO7YaMf_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_V6N02HwZ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_OfWu3dvw_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_N7iiZFpV_sendMessage);
}

void Heavy_oscilator::cBinop_i7BdjWsO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_cTeJ8XGs, 1, m, &cIf_cTeJ8XGs_sendMessage);
}

void Heavy_oscilator::cCast_lu9Lkgce_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_NEQ, 0.0f, 0, m, &cBinop_7IlGBIPE_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_NEwgn3k5_sendMessage);
}

void Heavy_oscilator::cCast_5wDckaZC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XrNHH7Lc, HV_BINOP_EQ, 1, m, &cBinop_XrNHH7Lc_sendMessage);
}

void Heavy_oscilator::cBinop_7IlGBIPE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_oQDixDYY, 1, m, &cIf_oQDixDYY_sendMessage);
}

void Heavy_oscilator::cCast_OdOUN704_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_vUW0zHkF_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_o1L4MX8J_sendMessage);
}

void Heavy_oscilator::cCast_VleWRtgj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_oQDixDYY, 0, m, &cIf_oQDixDYY_sendMessage);
}

void Heavy_oscilator::cBinop_NEwgn3k5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_93Eh0LwW, 1, m, &cIf_93Eh0LwW_sendMessage);
}

void Heavy_oscilator::cBinop_XrNHH7Lc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_FTrqDZhX, 1, m, &cIf_FTrqDZhX_sendMessage);
}

void Heavy_oscilator::cCast_vUW0zHkF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_kDXLIr6e, 0, m, &cIf_kDXLIr6e_sendMessage);
}

void Heavy_oscilator::cCast_o1L4MX8J_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_divug7Z8, 1, m, &cVar_divug7Z8_sendMessage);
}

void Heavy_oscilator::cCast_nV4ZrTF6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_xbO63Eai, 1, m, &cIf_xbO63Eai_sendMessage);
}

void Heavy_oscilator::cCast_25gKwYEQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_divug7Z8, 0, m, &cVar_divug7Z8_sendMessage);
}

void Heavy_oscilator::cCast_0cefhfw0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_JyCDiBJt, 1, m, &cIf_JyCDiBJt_sendMessage);
}

void Heavy_oscilator::cCast_OfWu3dvw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_gBA3bHw8, 1, m, &cIf_gBA3bHw8_sendMessage);
}

void Heavy_oscilator::cCast_QnO7YaMf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_kDXLIr6e, 1, m, &cIf_kDXLIr6e_sendMessage);
}

void Heavy_oscilator::cCast_N7iiZFpV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_i7BdjWsO_sendMessage);
}

void Heavy_oscilator::cCast_V6N02HwZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_GbDyaecG, 1, m, &cIf_GbDyaecG_sendMessage);
}

void Heavy_oscilator::cBinop_yzNTrQuF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_lxQEULKi, m);
}

void Heavy_oscilator::cReceive_1P4ZcJ1b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_q3Htr5Wt, 0, m, &cVar_q3Htr5Wt_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_3I01IfAM, 0, m, &cVar_3I01IfAM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_v0cNX2VM, 0, m, &cVar_v0cNX2VM_sendMessage);
}

void Heavy_oscilator::cReceive_rfYDlMmS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_66sHqFgk, 0, m, &cSlice_66sHqFgk_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_52Nz8ImW, 0, m, &cSlice_52Nz8ImW_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_EI3LyykQ, 0, m, &cSlice_EI3LyykQ_sendMessage);
}

void Heavy_oscilator::cReceive_LHiH8pq2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSlice_onMessage(_c, &Context(_c)->cSlice_on4M24GN, 0, m, &cSlice_on4M24GN_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_V3LWlsPI, 0, m, &cSlice_V3LWlsPI_sendMessage);
  cSlice_onMessage(_c, &Context(_c)->cSlice_LLpFa3pz, 0, m, &cSlice_LLpFa3pz_sendMessage);
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
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4;

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
    __hv_phasor_k_f(&sPhasor_hUMXaXly, VOf(Bf0));
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
    __hv_varread_f(&sVarf_lxQEULKi, VOf(Bf3));
    __hv_mul_f(VIf(Bf1), VIf(Bf3), VOf(Bf3));
    __hv_add_f(VIf(Bf3), VIf(O0), VOf(O0));
    __hv_add_f(VIf(Bf3), VIf(O1), VOf(O1));

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
